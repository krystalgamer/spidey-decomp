#include "spool.h"
#include "utils.h"
#include "validate.h"
#include "utils.h"
#include "panel.h"
#include "PCTex.h"
#include "DXinit.h"
#include "dcfileio.h"
#include "crate.h"

#include <cstring>

EXPORT i32 gSpoolRegionRelatedOne;
EXPORT i32 gSpoolRegionRelatedTwo;
EXPORT i32 GrenadeExplosionRegion = -1;
EXPORT i32 SymBurnRegion = -1;
EXPORT i32 FireDomeRegion = -1;
EXPORT i32 FireRingRegion = -1;


EXPORT i32 gSpoolCurrentOpenSpot;
EXPORT i32 gSpoolAnimPacketRelated;
EXPORT i32 gSpoolInitOne;
EXPORT i32 gSpoolInitTwo;
EXPORT i32 gSpoolColijEnvIndex;
EXPORT i32 gSpoolInitRelatedUnk;

EXPORT i32 EnvRegions[2] = { -1, -1 };

EXPORT Texture* gSpoolTexturesRelated;
EXPORT Texture gSpoolInitRelated[512];

EXPORT SAccess* gAccessRelated[MAXPSX];

const i32 MAXITEMSPERCHECKSUM = 5;
EXPORT i16 gEnvModelHashTable[256][MAXITEMSPERCHECKSUM];

SPSXRegion PSXRegion[MAXPSX];

#define TEXTURE_CHECKSUM_TABLE_SIZE (512)
EXPORT Texture* TextureChecksumHashTable[TEXTURE_CHECKSUM_TABLE_SIZE];

EXPORT i32 lowGraphics;
EXPORT i32 CurrentSuit;

EXPORT u8 gGiveDefaultTexture;
EXPORT i32** gUnknownRelatedToFind;

EXPORT TextureEntry gTextureEntries[256];

EXPORT i32 HashIndex;
EXPORT Texture* pCurrentTex;

EXPORT char SuitNames[11][32] = 
{
	"Dummy",
	"spidey",
	"sp2099",
	"spSymbi",
	"spUniv",
	"spUnlim",
	"spBagMan",
	"spScar",
	"spReilly",
	"spQuick",
	"spPark",

};

// @Ok
// @Validate
i32 Spool_PSX(
		const char* Filename,
		i32 IsEnviro)
{
	char v22[32];
	print_if_false(Filename != 0, "No FileName sent to Spool_PSX.");
	Utils_CopyString(Filename, v22, sizeof(v22));

	if ( !gLowGraphics && Utils_CompareStrings(v22, "spidey") )
		Utils_CopyString(SuitNames[CurrentSuit], v22, sizeof(v22));

	for (i32 i = 0; i < MAXPSX; i++)
	{
		if (PSXRegion[i].Filename[0] && Utils_CompareStrings(v22, PSXRegion[i].Filename))
		{
			return i;
		}
	}

	i32 openSpot = -1;
	for (i32 k = 0; k < MAXPSX; k++)
	{
		if (PSXRegion[k].Filename[0] == '\0')
		{
			openSpot = k;
			break;
		}
	}

	print_if_false(openSpot == -1, "Too many PSX files loaded, increase MAXPSXS in spool.h");
	if (IsEnviro)
	{
		print_if_false(EnvRegions[0] == -1, "Old environment still loaded");
		EnvRegions[0] = openSpot;
	}

	Utils_CopyString(v22, PSXRegion[openSpot].Filename, 9);
	gSpoolCurrentOpenSpot = openSpot;


	i32 v8;
	char v23[64];
	if ( gLowGraphics && (sprintf(v23, "lowres\\%s.psx", v22), (v8 = FileIO_Open(v23)) != 0) )
	{
		print_if_false((unsigned __int8)"Loading LowRes Model: %s\r\n", v23);
		PSXRegion[openSpot].LowRes = 1;
	}
	else
	{
		sprintf(v23, "%s.psx", v22);
		v8 = FileIO_Open(v23);
	}

	void* v9 = DCMem_New(v8, 1, 1, 0, 1);
	PSXRegion[openSpot].pPSX = static_cast<u32*>(v9);

	FileIO_Load(v9);
	FileIO_Sync();
	ProcessNewPSX(openSpot);

	if (IsEnviro)
	{
		print_if_false(EnviroList == 0, "EnviroList not NULL");
		EnviroList = PSXRegion[openSpot].field_10;
		gSpoolRegionRelatedOne = gSpoolRegionRelatedTwo;

		gCommandPointRelated[0] = Spool_SkipPackets(PSXRegion[openSpot].pPSX);
		Spool_AddEnvModelsToHashTable();
	}

	if ( Utils_CompareStrings(v22, "expgrnd") )
	{
		print_if_false(GrenadeExplosionRegion == -1, "GrenadeExplosionRegion already set?");
		GrenadeExplosionRegion = openSpot;
	}

	if ( Utils_CompareStrings(v22, "fire") )
	{
		print_if_false(SymBurnRegion == -1, "SymBurnRegion already set?");
		Spool_MaskFaceFlags(openSpot, 512, -1);
		SymBurnRegion = openSpot;
	}

	if ( Utils_CompareStrings(v22, "firedome") )
	{
		print_if_false(FireDomeRegion == -1, "FireDomeRegion already set?");
		FireDomeRegion = openSpot;
	}

	if ( Utils_CompareStrings(v22, "firering") )
	{
		print_if_false(FireRingRegion == -1, "FireRingRegion already set?");
		FireRingRegion = openSpot;
	}

	return openSpot;
}

// @SMALLTODO
void DecrementTextureUsage(i32)
{
    printf("DecrementTextureUsage(i32)");
}

// @Ok
char* GetNextLine(char * a1)
{
	char * res = strchr(a1, '\r');
	if (res)
	{
		res++;
		if (*res == '\n')
			res++;
	}

	return res;
}

// @Ok
void GotoStartOfTextureList(void)
{
	HashIndex = 0;
	pCurrentTex = TextureChecksumHashTable[0];
}

// @SMALLTODO
void NewTextureEntry(u32 checksum)
{
    printf("NewTextureEntry(u32)");
}

// @NotOk
// review when removed unused textures is done
INLINE Texture* NextTexture(void)
{
	Texture* res = 0;

	if (HashIndex < TEXTURE_CHECKSUM_TABLE_SIZE)
	{
		while (pCurrentTex == 0)
		{
			HashIndex++;
			pCurrentTex = TextureChecksumHashTable[HashIndex];

			if (TEXTURE_CHECKSUM_TABLE_SIZE <= HashIndex)
				return 0;
		}

		res = pCurrentTex;
		pCurrentTex = pCurrentTex->pNext;
	}


	return res;
}

// @SMALLTODO
void PreProcessAnimPacket(u32 *,u32 *)
{
    printf("PreProcessAnimPacket(u32 *,u32 *)");
}

// @MEDIUMTODO
void ProcessNewPSX(i32)
{
    printf("ProcessNewPSX(i32)");
}

// @SMALLTODO
void RemoveAnimPacket(u32 *)
{
    printf("RemoveAnimPacket(u32 *)");
}

// @Ok
// @Validate
INLINE void RemoveTextureEntry(Texture* pTexture)
{
	if (pTexture->pNext)
		pTexture->pNext->pPrevious = pTexture->pPrevious;

	if (pTexture->pPrevious)
		pTexture->pPrevious->pNext = pTexture->pNext;

	u32 checksum = pTexture->Checksum % TEXTURE_CHECKSUM_TABLE_SIZE;
	if (pTexture == TextureChecksumHashTable[checksum])
		TextureChecksumHashTable[checksum] = pTexture->pNext;

	Texture** pFreeList = reinterpret_cast<Texture**>(&gSpoolInitRelated);
	pTexture->pNext = *pFreeList;
	*pFreeList = pTexture;
}

// @Ok
// @Validate
INLINE void Spool_AddEnvModelsToHashTable(void)
{
	print_if_false(EnviroList != 0, "NULL EnviroList?");
	u32* pModelChecksums = PSXRegion[EnviroList->mRegion].pModelChecksums;
	print_if_false(pModelChecksums != 0, "NULL pChecksums?");

	u32 v16 = reinterpret_cast<u32>(PSXRegion[EnviroList->mRegion].ppModels[-1]);
	for (u32 v15 = 0; v15 < v16; v15++)
	{
		u32 checksumIndex = pModelChecksums[v15] % 256;

		i32 k;
		for (k = 0; gEnvModelHashTable[checksumIndex][k] >= 0; k++)
		{
			print_if_false(
				k < MAXITEMSPERCHECKSUM,
				"Too many items have the same checksum mod 256\n Need to increase MAXITEMSPERCHECKSUM in spool.cpp");
		}

		gEnvModelHashTable[checksumIndex][k] = v15;
	}
}

// @MEDIUMTODO
void Spool_AnimAccess(char *,SAnimFrame **)
{
    printf("Spool_AnimAccess(char *,SAnimFrame **)");
}

// @Ok
// @Matching
void Spool_ClearEnvironmentRegions(void)
{
	ClearRegion(EnvRegions[0], 1);
}

// @SMALLTODO
void Spool_FindAnim(char *,i32)
{
    printf("Spool_FindAnim(char *,i32)");
}

// @Ok
// @Matching
i32 Spool_GetEnvIndex(i32 a1)
{
	return (a1 != EnvRegions[0]) ? -1 : 0;
}

// @SMALLTODO
void Spool_GetPalette(u32,i32)
{
    printf("Spool_GetPalette(u32,i32)");
}

// @Ok
// @Matching
void Spool_Init(void)
{
	print_if_false(1u, "MAXPSXS is too big");
	PCTex_ReleaseAllTextures();
	PCTex_InitSystemTextures();

	for (i32 i = 0; i < MAXPSX; i++)
	{
		PSXRegion[i].Filename[0] = 0;
		PSXRegion[i].Protected = 0;
		PSXRegion[i].Usable = 0;
		PSXRegion[i].ppModels = 0;

		delete[] PSXRegion[i].field_10;

		PSXRegion[i].field_10 = 0;
		PSXRegion[i].pPSX = 0;
		PSXRegion[i].pAnimFile = 0;
		PSXRegion[i].pHierarchy = 0;
		PSXRegion[i].pColourPulseData = 0;
		PSXRegion[i].pTexWibData = 0;
		PSXRegion[i].pHooks = 0;

		while(gAccessRelated[i])
		{
			SAccess* pCur = gAccessRelated[i];
			SAccess* next = pCur->pNext;
			gAccessRelated[i] = next;

			pCur->pPrev->pNext = 0;
			delete pCur;
		}
	}

	gSpoolTexturesRelated = &gSpoolInitRelated[0];
	for (i32 j = 0; j < TEXTURE_CHECKSUM_TABLE_SIZE; j++)
		TextureChecksumHashTable[j] = 0;

	for (i32 k = 0; k < 511; k++)
	{
		gSpoolInitRelated[k].pNext = &gSpoolInitRelated[k+1];
	}

	gSpoolInitRelated[511].pNext = 0;
	Spool_InitialiseEnvModelHashTable();

	gSpoolAnimPacketRelated = 0;
	gSpoolInitOne = 0;
	gSpoolInitTwo = 0;
	EnviroList = 0;
	gSpoolColijEnvIndex = 0;
	gSpoolInitRelatedUnk = 0;

	EnvRegions[0] = -1;
	EnvRegions[1] = -1;

}

// @Ok
INLINE void Spool_InitialiseEnvModelHashTable(void)
{
	for (i32 i = 0; i < 256; i++)
	{
		for (i32 j = 0; j < MAXITEMSPERCHECKSUM; j++)
		{
			gEnvModelHashTable[i][j] = -1;
		}
	}
}

// @SMALLTODO
void Spool_MaskFaceFlags(i32,u32,u32)
{
    printf("Spool_MaskFaceFlags(i32,u32,u32)");
}

// @SMALLTODO
void Spool_ReloadAll(void)
{
    printf("Spool_ReloadAll(void)");
}

// @SMALLTODO
void Spool_RemoveAccess(void **,i32)
{
    printf("Spool_RemoveAccess(void **,i32)");
}

// @Ok
void Spool_Sync(void)
{
}

// @SMALLTODO
void Spool_TextureAccess(u32,Texture **)
{
    printf("Spool_TextureAccess(u32,Texture **)");
}

// @MEDIUMTODO
void SwapPSXFile(u32 *)
{
    printf("SwapPSXFile(u32 *)");
}

// @MEDIUMTODO
void SwapPSXPacketData(u32 *)
{
    printf("SwapPSXPacketData(u32 *)");
}

// @SMALLTODO
void SwapPSXTextureData(u32 *,Texture **,u32 *)
{
    printf("SwapPSXTextureData(u32 *,Texture **,u32 *)");
}

// @SMALLTODO
void accessLog(char *,...)
{
    printf("accessLog(char *,...)");
}

// @SMALLTODO
void addAccess(void **,u32,u32,i32)
{
    printf("addAccess(void **,u32,u32,i32)");
}

// @SMALLTODO
void restoreRegionAccess(i32)
{
    printf("restoreRegionAccess(i32)");
}

// @SMALLTODO
void texClearChecksums(char *)
{
    printf("texClearChecksums(char *)");
}

// @SMALLTODO
void texLoadChecksums(char *)
{
    printf("texLoadChecksums(char *)");
}


// @Ok
u32 Spool_GetModelChecksum(CItem *pItem)
{
	return PSXRegion[pItem->mRegion].pModelChecksums[pItem->mModel];
}

// @Ok
// @Matching
CItem* Spool_FindEnviroItem(u32 Checksum)
{
	CItem* pList = EnviroList;
	if (pList)
	{
		u32* pModelChecksums = PSXRegion[EnviroList->mRegion].pModelChecksums;
		print_if_false(pModelChecksums != 0, "NULL pChecksums?");

		i16* pHashes = gEnvModelHashTable[Checksum % 256];

		for (i32 i = 0, curHash = pHashes[i]; curHash >= 0; curHash = pHashes[i])
		{
			if (Checksum == pModelChecksums[curHash])
			{
				return
					reinterpret_cast<CItem*>(&reinterpret_cast<char*>(pList)[0x40 * curHash]);
			}
			
			if (++i >= 5)
				break;
		}
	}

	return 0;
}

// @Ok
// @Matching
int Spool_FindRegion(const char *a1)
{
	char fileName[0x20];
	print_if_false(a1 != 0, "No FileName sent to Spool_PSX.");
	Utils_CopyString(a1, fileName, sizeof(fileName));


	if (!lowGraphics)
	{
		if (Utils_CompareStrings(fileName, "spidey"))
			Utils_CopyString(SuitNames[CurrentSuit], fileName, sizeof(fileName));
	}

	for (i32 i = 0; i < MAXPSX; i++)
	{
		if (Utils_CompareStrings(fileName, PSXRegion[i].Filename))
		{
			return i;
		}
	}

	return -1;
}

// @MEDIUMTODO
unsigned int Spool_GetModel(unsigned int Checksum, int Region)
{
	return 0x26052024;
}

// @NotOk
// understand this piece of shit
INLINE u32 *Spool_SkipPackets(u32 *pPSX)
{
	unsigned int *i; // r4
	for ( i = (unsigned int *)((char *)pPSX + pPSX[1]); *i != -1; i = (unsigned int *)((char *)i + i[1] + 8) );

	return i + 1;
}

// @BIGTODO
void ClearRegion(int, int)
{
	printf("void ClearRegion(int, int)");
}

// @BIGTODO
void Spool_RemoveUnusedTextures(void)
{}

// @Ok
void Spool_ClearPSX(const char* Filename)
{

	char v3[32]; // [esp+8h] [ebp-40h] BYREF
	char v4[32]; // [esp+28h] [ebp-20h] BYREF

	print_if_false(Filename != 0, "No FileName sent to Spool_PSX.");
	Utils_CopyString(Filename, v3, 32);

	if ( !lowGraphics && Utils_CompareStrings(v3, "spidey") )
		Utils_CopyString(SuitNames[CurrentSuit], v3, 32);

	print_if_false(v3 != 0, "No FileName sent to Spool_PSX.");
	Utils_CopyString(v3, v4, 32);

	if ( !lowGraphics && Utils_CompareStrings(v4, "spidey") )
		Utils_CopyString(SuitNames[CurrentSuit], v4, 32);

	i32 index = 0;

	while (1)
	{
		if (Utils_CompareStrings(v4, PSXRegion[index].Filename))
			break;

		index++;
		if (index > MAXPSX)
		{
			index = -1;
			break;
		}
	}

	ClearRegion(index, 1);
}

// @Ok
void Spool_ClearAllPSXs(void)
{
	for (i32 i = 0; i < MAXPSX; i++)
	{
		if (!PSXRegion[i].Protected)
			ClearRegion(i, 1);
	}

	Spool_RemoveUnusedTextures();
}

// @NotOk
// understand the unknown variable
Texture *Spool_FindTextureEntry(u32 checksum)
{
	Texture *pSearch;
	for (pSearch = TextureChecksumHashTable[checksum & 511];
			pSearch;
			pSearch = pSearch->pNext)
	{
		if (pSearch->Checksum == checksum)
			break;
	}

	if (!pSearch)
	{
		if (!gGiveDefaultTexture)
		{
			print_if_false(0, "Can't find texture from checksum %ld", checksum);
			return reinterpret_cast<Texture*>(gUnknownRelatedToFind[1]);
		}
	}

	return pSearch;
}

#ifndef _WIN32
void strlwr(char* inp)
{
	// @TODO later date
}
#endif

// @NotOk
// understand th ereturn for index >= 256
Texture *Spool_FindTextureEntry(char *name)
{
	char localName[256];
	strcpy(localName, name);
	strlwr(localName);

	i32 index;
	for (index = 0; index < 256; index++)
	{
		TextureEntry *currentEntry = &gTextureEntries[index];
		if (!strcmp(currentEntry->Name, localName) && currentEntry->Active)
			break;
	}

	if (index >= 256)
		return reinterpret_cast<Texture*>(gUnknownRelatedToFind[1]);

	return Spool_FindTextureEntry(gTextureEntries[index].Checksum);
}

// @Ok
u32 Spool_FindTextureChecksum(char *name)
{
	char localName[256];
	strcpy(localName, name);
	strlwr(localName);

	i32 index;
	for (index = 0; index < 256; index++)
	{
		TextureEntry *currentEntry = &gTextureEntries[index];
		if (!strcmp(currentEntry->Name, localName) && currentEntry->Active)
			break;
	}

	if (index < 256)
		return gTextureEntries[index].Checksum;

	return 0;
}

void validate_SPSXRegion(void)
{
	VALIDATE_SIZE(SPSXRegion, 0x44);

	VALIDATE(SPSXRegion, Filename, 0x0);
	VALIDATE(SPSXRegion, Usable, 0xA);
	VALIDATE(SPSXRegion, Protected, 0xB);
	VALIDATE(SPSXRegion, pModelChecksums, 0xC);
	VALIDATE(SPSXRegion, field_10, 0x10);
	VALIDATE(SPSXRegion, ppModels, 0x14);
	VALIDATE(SPSXRegion, pPSX, 0x18);
	VALIDATE(SPSXRegion, pAnimFile, 0x1C);
	VALIDATE(SPSXRegion, pHierarchy, 0x20);
	VALIDATE(SPSXRegion, pHooks, 0x24);
	VALIDATE(SPSXRegion, pColourTable, 0x28);
	VALIDATE(SPSXRegion, pTexWibData, 0x2C);
	VALIDATE(SPSXRegion, pColourPulseData, 0x30);
	VALIDATE(SPSXRegion, LowRes, 0x3B);
}

void validate_TextureEntry(void)
{
	VALIDATE_SIZE(TextureEntry, 0x28);

	VALIDATE(TextureEntry, Active, 0x0);
	VALIDATE(TextureEntry, Name, 0x1);
	VALIDATE(TextureEntry, Checksum, 0x24);
}

void validate_SAccess(void)
{
	VALIDATE_SIZE(SAccess, 0x14);

	VALIDATE(SAccess, pNext, 0x0);
	VALIDATE(SAccess, pPrev, 0x4);
	VALIDATE(SAccess, mType, 0x8);
	VALIDATE(SAccess, mName, 0xC);
}
