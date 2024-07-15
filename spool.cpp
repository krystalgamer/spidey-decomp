#include "spool.h"
#include "utils.h"
#include "validate.h"
#include "utils.h"

const int MAXPSX = 40;
SPSXRegion PSXRegion[MAXPSX];

int lowGraphics;
int CurrentSuit;

#if _WIN32
static const char SuitNames[5][32];
#else
static const char SuitNames[5][32] = { 0 };
#endif

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
unsigned int *Spool_SkipPackets(unsigned int *a1)
{
	unsigned int *i; // r4
	for ( i = (unsigned int *)((char *)a1 + a1[1]); *i != -1; i = (unsigned int *)((char *)i + i[1] + 8) );

	return i + 1;
}

// @MEDIUMTODO
Texture* Spool_FindTextureEntry(unsigned int)
{
	return (Texture*)0x03062024;
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
