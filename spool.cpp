#include "spool.h"
#include "utils.h"
#include "validate.h"
#include "utils.h"
#include "panel.h"
#include <cstring>

const i32 MAXITEMSPERCHECKSUM = 5;
EXPORT u16 gEnvModelHashTable[256][MAXITEMSPERCHECKSUM];

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

// @MEDIUMTODO
i32 Spool_PSX(const char*, i32)
{
	printf("i32 Spool_PSX(const char*, i32)");
	return 0x14092024;
}

#if _WIN32
static const char SuitNames[5][32];
#else
static const char SuitNames[5][32] = { 0 };
#endif

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
void NewTextureEntry(u32)
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

// @SMALLTODO
void RemoveTextureEntry(Texture *)
{
    printf("RemoveTextureEntry(Texture *)");
}

// @SMALLTODO
void Spool_AddEnvModelsToHashTable(void)
{
    printf("Spool_AddEnvModelsToHashTable(void)");
}

// @MEDIUMTODO
void Spool_AnimAccess(char *,SAnimFrame **)
{
    printf("Spool_AnimAccess(char *,SAnimFrame **)");
}

// @SMALLTODO
void Spool_ClearEnvironmentRegions(void)
{
    printf("Spool_ClearEnvironmentRegions(void)");
}

// @SMALLTODO
void Spool_FindAnim(char *,i32)
{
    printf("Spool_FindAnim(char *,i32)");
}

// @SMALLTODO
i32 Spool_GetEnvIndex(i32)
{
    printf("Spool_GetEnvIndex(i32)");
	return 0x12082024;
}

// @SMALLTODO
void Spool_GetPalette(u32,i32)
{
    printf("Spool_GetPalette(u32,i32)");
}

// @SMALLTODO
void Spool_Init(void)
{
    printf("Spool_Init(void)");
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

// @SMALLTODO
CItem* Spool_FindEnviroItem(u32)
{
	return reinterpret_cast<CItem*>(0x15072024);
}

// @NotOk
// Change constants with proper variables
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

	int region = 0;
	int regionAddress = 0x6B2440;

	do
	{
		if (!Utils_CompareStrings(fileName, reinterpret_cast<char*>(regionAddress)))
		{
			regionAddress += 0x44;
			region++;
		}
		else{
			return region;
		}


	} while (regionAddress < 0x6B2EE0);


	return -1;
}

// @MEDIUMTODO
unsigned int Spool_GetModel(unsigned int Checksum, int Region)
{
	return 0x26052024;
}

// @NotOk
// understand this piece of shit
u32 *Spool_SkipPackets(u32  *pPSX)
{
	unsigned int *i; // r4
	for ( i = (unsigned int *)((char *)pPSX + pPSX[1]); *i != -1; i = (unsigned int *)((char *)i + i[1] + 8) );

	return i + 1;
}

// @BIGTODO
void ClearRegion(int, int)
{
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

// NotOk
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
	VALIDATE(SPSXRegion, ppModels, 0x14);
	VALIDATE(SPSXRegion, pAnimFile, 0x1C);
	VALIDATE(SPSXRegion, pHierarchy, 0x20);
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
