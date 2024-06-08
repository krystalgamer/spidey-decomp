#include "spool.h"
#include "utils.h"
#include "validate.h"

const int NUM_REGIONS = 40;
SPSXRegion PSXRegion[NUM_REGIONS];

int lowGraphics;
int CurrentSuit;

#if _WIN32
static const char SuitNames[5][32];
#else
static const char SuitNames[5][32] = { 0 };
#endif

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

// @TODO
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

// @TODO
Texture* Spool_FindTextureEntry(unsigned int)
{
	return (Texture*)0x03062024;
}

// @TODO
void ClearRegion(int, int)
{
}

// @TODO
void Spool_RemoveUnusedTextures(void)
{}

// @Ok
void Spool_ClearAllPSXs(void)
{
	for (i32 i = 0; i < NUM_REGIONS; i++)
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
	VALIDATE(SPSXRegion, Protected, 0xB);
}
