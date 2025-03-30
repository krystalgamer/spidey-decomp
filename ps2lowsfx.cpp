#include "ps2lowsfx.h"
#include "DXsound.h"
#include "ps2redbook.h"
#include "my_assert.h"
#include "PCGfx.h"
#include "pcdcMem.h"
#include "stubs.h"
#include "utils.h"
#include "tweak.h"
#include "spidey.h"
#include "dcfileio.h"

#include <cmath>

#include "validate.h"

//#define VALIDATE_PARSESFX


// @Ok
EXPORT u32 gSfxPlayRelated;

// @Ok
EXPORT i32 gSfxGlobal;

// @Ok
u32 SFXFalloffArray[32];

// @Ok
u32 SFXLevelSpecificArray[192];
// @Ok
u16 SFXLevelSpecificAliasArray[64];

// @Ok
EXPORT bool gBootRomSoundMode;

// @Ok
EXPORT u8 gSfxVolArr[256] =
{

  0xFF, 0xFB, 0xF7, 0xF3, 0xEF, 0xEB, 0xE7, 0xE3, 0xDF, 0xDB, 
  0xD7, 0xD1, 0xCB, 0xC5, 0xC1, 0xBB, 0xB7, 0xB3, 0xB1, 0xAD, 
  0xA9, 0xA5, 0xA3, 0x9F, 0x9D, 0x99, 0x97, 0x95, 0x93, 0x91, 
  0x8F, 0x8D, 0x8B, 0x89, 0x87, 0x85, 0x83, 0x81, 0x7F, 0x7D, 
  0x7B, 0x7A, 0x79, 0x77, 0x75, 0x74, 0x73, 0x71, 0x6F, 0x6E, 
  0x6D, 0x6C, 0x6B, 0x69, 0x67, 0x66, 0x65, 0x64, 0x63, 0x62, 
  0x61, 0x60, 0x5F, 0x5E, 0x5D, 0x5C, 0x5B, 0x5A, 0x59, 0x58, 
  0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x51, 0x50, 0x4F, 0x4E, 
  0x4D, 0x4D, 0x4C, 0x4C, 0x4B, 0x4A, 0x49, 0x48, 0x47, 0x47, 
  0x46, 0x46, 0x45, 0x44, 0x43, 0x42, 0x41, 0x41, 0x40, 0x40, 
  0x3F, 0x3E, 0x3D, 0x3D, 0x3C, 0x3C, 0x3B, 0x3B, 0x3A, 0x3A, 
  0x39, 0x38, 0x37, 0x37, 0x36, 0x36, 0x35, 0x35, 0x34, 0x34, 
  0x33, 0x33, 0x32, 0x32, 0x31, 0x31, 0x30, 0x30, 0x2F, 0x2F, 
  0x2E, 0x2E, 0x2D, 0x2D, 0x2C, 0x2C, 0x2B, 0x2B, 0x2A, 0x2A, 

  0x29, 0x29, 0x28, 0x28, 0x27, 0x27, 0x26, 0x26, 0x25, 0x25, 
  0x24, 0x24, 0x23, 0x23, 0x23, 0x22, 0x22, 0x22, 0x21, 0x21, 
  0x20, 0x20, 0x1F, 0x1F, 0x1E, 0x1E, 0x1D, 0x1D, 0x1D, 0x1C, 
  0x1C, 0x1C, 0x1B, 0x1B, 0x1B, 0x1A, 0x1A, 0x1A, 0x19, 0x19, 
  0x18, 0x18, 0x17, 0x17, 0x17, 0x16, 0x16, 0x16, 0x15, 0x15, 
  0x15, 0x14, 0x14, 0x14, 0x13, 0x13, 0x13, 0x12, 0x12, 0x12, 
  0x11, 0x11, 0x11, 0x10, 0x10, 0x10, 0x0F, 0x0F, 0x0F, 0x0E, 
  0x0E, 0x0E, 0x0D, 0x0D, 0x0D, 0x0D, 0x0C, 0x0C, 0x0C, 0x0C, 
  0x0B, 0x0B, 0x0B, 0x0A, 0x0A, 0x0A, 0x09, 0x09, 0x09, 0x08, 
  0x08, 0x08, 0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 
  0x05, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04, 0x03, 0x03, 
  0x02, 0x02, 0x01, 0x01, 0x00, 0x00
};

// @Ok
EXPORT u8 gReverbType;

// @Ok
EXPORT u8 gSfxInited;

// @Ok
EXPORT i32 gVoiceIndex = 1;

// @Ok
EXPORT SSfxRelated gSfxSomething;

// @Ok
EXPORT i32 gNumVoices;

EXPORT u8 SFXPaused;
#define LEN_SFX_ENTRIES 32
EXPORT SSfxEntry gSfxEntries[LEN_SFX_ENTRIES];

// @Ok
EXPORT SSFXBank gSoundBank;

// @Ok
EXPORT SSFXBank gSfxRelatedOutLevel;


// @Ok
EXPORT u32 gSfxArrayOne[192] =
{
  1u,
  234881084u,
  8192u,
  2u,
  234881084u,
  8192u,
  4u,
  234881084u,
  8192u,
  8u,
  234881084u,
  8192u,

  16u,
  201326652u,
  8192u,
  32u,
  201326652u,
  8192u,

  64u,
  201326652u,
  8192u,
  128u,
  201326655u,
  8192u,
  256u,
  201326652u,
  8192u,
  512u,

  201326652u,

  8192u,
  1024u,
  201326652u,
  8192u,
  2048u,
  201326652u,
  8192u,
  4096u,
  201326652u,
  8192u,
  8192u,

  201326652u,

  8192u,
  16384u,
  201326652u,
  8192u,
  32768u,
  201326652u,
  8192u,
  65537u,
  201326652u,
  8192u,

  65538u,
  201326652u,
  8192u,
  65540u,
  201326652u,
  8192u,
  65544u,
  201326652u,
  8192u,
  65552u,
  201326652u,
  8192u,
  65568u,
  201326652u,

  8192u,
  65600u,
  201326652u,
  8192u,
  65664u,
  201326652u,
  8192u,
  65792u,
  201326652u,
  8192u,

  2147549696u,
  201326652u,
  8192u,
  66560u,

  201326652u,

  8192u,
  67584u,
  201326652u,
  8192u,
  69632u,
  201326652u,
  8192u,
  73728u,
  201326652u,
  8192u,

  81920u,
  268435516u,
  8192u,
  98304u,
  201326652u,
  8192u,
  2147614721u,
  201326652u,
  8192u,
  131074u,
  201326652u,
  8192u,
  131076u,
  201326652u,
  8192u,
  131080u,
  201326652u,
  8192u,
  131088u,
  201326652u,
  8192u,
  131104u,
  201326652u,
  8192u,
  131136u,
  201326652u,
  8192u,
  131200u,
  201326652u,
  8192u,
  131328u,
  234881084u,
  8192u,
  131584u,
  234881084u,
  8192u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u,
  0u
};


// @Ok
EXPORT u16 gSfxArraAliasyOne[64];

// @IGNOREME
// @Note: exists purely for matching purposes
static void nullsub_3(void)
{
}

// @IGNOREME
// @Note: exists purely for matching purposes
static void nullsub_one_arg(i32)
{
}

// @Ok
INLINE void CopyFilenameDefaultExtension(
		char* dst,
		i32 len,
		const char* pFileName,
		const char* pExtension)
{
	strncpy(dst, pFileName, len);

	char *dot = strrchr(dst, '.');
	if (dot)
		*dot = 0;
	strcat(dst, pExtension);
}

// @Ok
// @Matching
INLINE i32 DCSFX_AdjustVol(i32 a1)
{
	DoAssert((a1 >= 0 || (a1 = -a1, a1 >= 0)) && a1 < 0x4000, "DCSFX_AdjustVol: bad volume");

	a1 >>= 5;
	if (a1 > 255)
		a1 = 255;

	return 255 - gSfxVolArr[a1];
}

// @Ok
// @Matching
void DCSetBootROMSoundMode(bool a1)
{
	if (a1 != gBootRomSoundMode)
	{
		gBootRomSoundMode = a1;
		void *v1 = syMalloc(0x4000u);

		i32 v2 = syCfgInit(v1);
		DoAssert(v2 == 0, "Problem with configuration init.");

		i32 v3 = syCfgSetSoundMode(a1 != false);
		DoAssert(v3 == 0, "Problem with syCfgGetSoundMode");


		i32 v4 = syCfgExit();
		DoAssert(v4 == 0, "Problem with syCfgExit");

		syFree(v1);
	}
}

// @Ok
// @AlmostMatching: after the log function there's an extra spill in memory that I cannot match
// don't know if it's due to float consistency thingy, but can't repro this shit for some reason
INLINE i32 PSXPitchToDCPitch(i32 a1)
{
	if (a1 <= 0)
		return 0;

	f32 v16 = 1.442695f * logf(a1);
	f32 v17 = (v16 - 10.0f) * 1200.0f;

	return v17;
}

// @NotOk
// @Validate: when inlined
INLINE i32 SFX_AllocVoice(i32 a1, bool a2)
{
	i32 v8 = gVoiceIndex;
	i32 v9 = 0;
	for (i32 i = gVoiceIndex; i < 32; i++)
	{

		if (!DXSOUND_IsPlaying(i))
		{
			SFX_KillVoice(i);
			gVoiceIndex = i + 1;
			if (i == 31)
				gVoiceIndex = 1;
			v9 = 1;
			break;
		}
	}

	if (!v9)
	{
		for (i32 j = 1; j < v8; j++)
		{
			if (!DXSOUND_IsPlaying(j))
			{
				SFX_KillVoice(j);
				gVoiceIndex = j + 1;
				if (j == 31)
					gVoiceIndex = 1;
				break;
			}
		}
	}

	i32 k;
	for (k = 1; k < 32; ++k)
	{
		if (!gSfxEntries[k].field_1A && !gSfxEntries[k].field_1B )
			break;
	}

	if (k < 32)
	{
		gSfxEntries[k].field_0 = a1;
		gSfxEntries[k].field_1A = 1;
		gSfxEntries[k].field_1B = a2;
		gSfxEntries[k].field_4 = 0;
		gSfxEntries[k].field_8 = 0;
		gSfxEntries[k].field_C = 0;
		gSfxEntries[k].field_10 = 0;
		gSfxEntries[k].field_1C = 0;

		DoAssert(gNumVoices++ <= 32, "voice allocation error"); 
		return k;
	}

	error("SFX out of voices.");
    nullsub_3();
	return -1;
}

// @Ok
// @AlmostmAtching: something about amheapFree is making it not match
// it dumps the result into the stack before pushing
INLINE void SFX_CloseBank(SSFXBank *pBank)
{
	SFX_StopAll();

	if (pBank->field_4)
	{
		DXSOUND_Unload(pBank->field_8, 0);
		
		if (pBank == &gSoundBank && gSfxRelatedOutLevel.field_4)
			SFX_CloseBank(&gSfxRelatedOutLevel);

		DebugPrintfX("unloading sound bank %s.", pBank->field_8);

		i32 res = amHeapFree(pBank->field_4);
		DoAssert(!!res, "amHeapFree failed");
		pBank->field_4 = 0;
		pBank->mNumAssets = 0;

		if (gSfxSomething.field_0)
			Mem_AlignedDelete(gSfxSomething.field_0);

		memset(&gSfxSomething, 0, sizeof(gSfxSomething));
	}
}

// @Ok
// @Matching
INLINE void SFX_FreeVoice(i32 a1)
{
	nullsub_3();
	SSfxEntry *pEntry = &gSfxEntries[a1];

	pEntry->field_1A = 0;
	pEntry->field_1B = 0;
	pEntry->field_10 = 0;
	pEntry->field_1C = 0;
	pEntry->field_24 = 0;

	DoAssert(--gNumVoices >= 0, "voice deallocation error");
	nullsub_3();
}

// @Ok
void SFX_Init(char* pSfxBankName)
{
	char buf[56];
	DoAssert(pSfxBankName && *pSfxBankName, "bad sfx bank filename");

	CopyFilenameDefaultExtension(buf, sizeof(buf), pSfxBankName, ".kat");
	SFX_LoadBank(buf, &gSoundBank);
	CopyFilenameDefaultExtension(buf, sizeof(buf), pSfxBankName, ".sfx");

	SFX_ParseSFXFile(buf, gSfxArrayOne, gSfxArraAliasyOne, 64, 0);
}

// @NotOk
// @Note: this is fine, it's missing a bunch of stubbed calls that after spending too much time
// looking into the DreamCast version I opted not to pursue further. If someone wants a challenge, enjoy.
void SFX_InitAtStart(void)
{
	if (!gSfxInited)
	{
		memset(gSfxEntries, 0, sizeof(gSfxEntries));
		memset(&gSfxSomething, 0, sizeof(gSfxSomething));
		gSfxInited = 1;
		gNumVoices = 0;
	}
}

// @Ok
INLINE void SFX_KillVoice(u32 a1)
{
	if (gSfxEntries[a1].field_1A)
	{
		DXSOUND_Stop(a1);
		DXSOUND_Close(a1);
		SFX_FreeVoice(a1);
	}
}

// @Ok
// @AlmostMatching: KillVoice is not inlined here for some reason, tiny reg allocation diff
// diffs come also from fileSize update but that's not used so idgaf
void SFX_LoadBank(
		const char *pName,
		SSFXBank *pBank)
{
	if (pBank->field_4 && !strcmp(pBank->field_8, pName))
		return;

	SFX_CloseBank(pBank);

	if (!FileIO_FileExists(pName))
	{
		DebugPrintfX("could not find sound bank %s...", pName);
		return;
	}

	DebugPrintfX("loading sound bank %s...", pName);
	i32 fileSize = FileIO_Open(pName);
	DoAssert(fileSize != 0, "couldn't find bank file");

	void *fileBuf = DCMem_New(fileSize, 0, 1, 0, 1);
	FileIO_Load(fileBuf);
	FileIO_Sync();

	pBank->mNumAssets = static_cast<i32*>(fileBuf)[0];
	DoAssert(pBank->mNumAssets < NUM_ASSETS_PER_BANK, "Too many assets in bank.");

	u8 v17 = 0;
	memcpy(
			pBank->mAssets,
			&static_cast<i32*>(fileBuf)[1],
			sizeof(SSfxAsset) * pBank->mNumAssets);

	i32 mNumAssets = pBank->mNumAssets;
	SSfxAsset *pAsset = &pBank->mAssets[pBank->mNumAssets];

	while (--pAsset >= pBank->mAssets)
	{

		DoAssert(--mNumAssets >= 0, "too many streams in the bank");

		DoAssert(
				pAsset->field_C >= 0x63 && pAsset->field_C <= 0xF423F,
				"bogus sample rate");

		DoAssert(
				pAsset->field_14 == 4 || pAsset->field_14 == 8 || pAsset->field_14 == 16,
				"bogus bit depth");
		if (pAsset->field_8 >= 0x20000 && pBank != &gSoundBank)
		{
			DoAssert(1, "all streaming samples must be at end of bank");

			gSfxSomething.field_4 = pAsset->field_8;
			gSfxSomething.field_4 &= 0xFFFFFFFC;
			gSfxSomething.field_4 = pAsset->field_8;

			i32 v13 = 4 - (pAsset->field_4 & 3);
			gSfxSomething.field_C += 13;

			if (!gSfxSomething.field_0)
			{
				gSfxSomething.field_0 = DCMem_New(gSfxSomething.field_4, 0, 1, 0, 1);
				DoAssert(
						!!gSfxSomething.field_0,
						"could not allocate main mem stream buffer");
				memcpy(
						gSfxSomething.field_0,
						&reinterpret_cast<u8*>(fileBuf)[gSfxSomething.field_C],
						gSfxSomething.field_4);
			}

			gSfxSomething.field_10 = 0xC000;

			switch (pAsset->field_14)
			{
				case 4:
					gSfxSomething.field_14 = gSfxSomething.field_10;
					break;
				case 8:
					gSfxSomething.field_14 = gSfxSomething.field_10 >> 1;
					break;
				case 16:
					gSfxSomething.field_14 = gSfxSomething.field_10 >> 2;
					break;
				default:
					DoAssert(0, "?");
				break;
			}

			v17 = 1;
			pAsset->field_8 = gSfxSomething.field_10 + v13;

			fileSize += pAsset->field_8 - gSfxSomething.field_4;
			fileSize += 3;
			fileSize &= 0xFFFFFFFC;
		}
	}

	u32 *v20;
	if (!amHeapAlloc(&v20, fileSize, 32, 2, 0))
		error("unable to allocate %d bytes of sound memory for %s", fileSize, pName);


	i32 acRes = acG2Write(v20, fileBuf, fileSize);
	DoAssert(!!acRes, "acG2Write failed");

	if (v17)
		gSfxSomething.field_C += reinterpret_cast<i32>(v20);

	Mem_AlignedDelete(fileBuf);
	pBank->field_4 = reinterpret_cast<i32>(v20);
	strncpy(pBank->field_8, pName, 56);

	DXSOUND_Load(pBank->field_8);
}

// @Ok
// @AlmostMatching: inline of PSXPitchToDCPitch not matching
void SFX_ModifyPos(
		u32 voice_id,
		const CVector *pos,
		i32 delta_dist)
{
	if (voice_id)
	{
		for (i32 i = 0; i < 32; i++)
		{
			if (voice_id & (1<<i))
			{
				u32 v11 = Utils_CalculateSpatialAttenuation(
						pos,
						(SFXFalloffArray[i] >> 2) & 0x3FFF,
						(SFXFalloffArray[i] & 0xFFFF) << 1);

				i32 v13 = v11 & 0xFFF;
				v13 <<= 2;
				v13 *= gGameState[12];
				v13 >>= 14;

				i32 v14 = (v11 >> 16) & 0xFFF;
				v14 <<= 2;
				v14 *= gGameState[12];
				v14 >>= 14;

				if (gBootRomSoundMode)
				{
					v14 = (v13 + v14) / 2;
					v13 = v14;
				}

				SFX_ModifyVol(1 << i, v13, v14);
				

				if (delta_dist)
				{
					i32 v16 = gSfxEntries[i].field_14;
					i32 v17 = v16 * delta_dist / 0x2000;
					i32 v18 = v16 - v17;
					if (v18 > v16 && v18 - v16 > v16 + (v16 >> 1))
						v18 = v16 + (v16 >> 1);

					gSfxEntries[i].field_20 = PSXPitchToDCPitch(v18);
					DXSOUND_SetPitch(i, gSfxEntries[i].field_20);
				}
			}
		}
	}
}

// @Ok
// @Matching
void SFX_ModifyVol(
		u32 voice_id,
		i32 vl,
		i32 vr)
{
	i32 v10 = 0;
	while (voice_id)
	{
		if (voice_id & 1)
		{
			if (gSfxEntries[v10].field_1A)
			{
				if (vl > 0x3FFF)
				{
					vl = 0x3FFF;
				}
				else if (vl < -16383)
				{
					vl = -16383;
				}

				if (vr > 0x3FFF)
				{
					vr = 0x3FFF;
				}
				else if (vr < -16383)
				{
					vr = -16383;
				}

				i32 v6 = (vr + vl) >> 1;
				i32 v7;
				if (vl == vr)
					v7 = 15;
				else
					v7 = 31 * vl / (vr + vl);

				DoAssert(1u, "pan out of range");

				DXSOUND_SetPan(v10, v7);
				gSfxEntries[v10].field_16 = v6;

				if (v6 > 0x3FFF)
				{
					v6 = 0x3FFF;
				}
				else if (v6 < -16383)
				{
					v6 = -16383;
				}

				i32 vol = DCSFX_AdjustVol(v6);
				DXSOUND_SetVolume(v10, vol);
			}
		}

		voice_id >>= 1;
		v10++;
	}
}

EXPORT u8 volatile gStubSfx;

// @Ok
// @Matching
void SFX_Off(void)
{
	if (!gStubSfx)
		stubbed_printf("Stubbed: SFX_Off( void )\n");
}

u8 testBuf[0x800];

// @Ok
// @Validated
void SFX_ParseSFXFile(
		char *p_name,
		u32 *array,
		u16 *aliasArray,
		i32 maxEntries,
		i32 mask)
{
	char v20[20];

	DoAssert(p_name != 0, "Invalid SFX filename");
	DoAssert(array != 0, "No sfx array to fill");
	DoAssert(aliasArray != 0, "No sfx alias array to fill");

	sprintf(v20, p_name);

#ifndef VALIDATE_PARSESFX
	u32 *pSfxFile = static_cast<u32*>(DCMem_New(0x800u, 0, 1, 0, 1));
	i32 fileSize = FileIO_Open(v20);
	DoAssert(fileSize <= 2048, "Bad size for .SFX file");


	FileIO_Load(pSfxFile);
	FileIO_Sync();
#else
	u32 *pSfxFile = reinterpret_cast<u32*>(testBuf);
#endif

	u32 curVal = *pSfxFile;
	i32 arrayIndex = 0;
	i32 aliasIndex = 0;

	while (curVal != 0xFFFFFFFF)
	{
		if (arrayIndex >= 192)
			break;

		if ((curVal & 0xFF) == 0xFE)
			array[arrayIndex] = mask | 0x80000000;
		else 
			array[arrayIndex] = mask;

		array[arrayIndex] |= (curVal & 0x0000FF00) << 8;
		array[arrayIndex] |= 1 << ((curVal >> 0x10) & 0xFF);

		u32 nextVal = pSfxFile[1];

		array[arrayIndex+1] = curVal >> 0x18 | nextVal & 0xFFFF0000;
		array[arrayIndex+2] = nextVal & 0xFFFF;

		aliasArray[aliasIndex] = pSfxFile[2];

		arrayIndex += 3;
		aliasIndex++;

		pSfxFile += 4;
		curVal = *pSfxFile;
	}

	if (aliasIndex < maxEntries)
		aliasArray[aliasIndex] = -1;

#ifndef VALIDATE_PARSESFX
	Mem_Delete(pSfxFile);
#endif
}

// @Ok
// @Matching
void SFX_Pause(void)
{
	if (!SFXPaused)
	{
		SFXPaused = 1;

		for (i32 i = 0; i < LEN_SFX_ENTRIES; i++)
		{
			if (gSfxEntries[i].field_1A)
				DXSOUND_SetVolume(i, 0);
		}

		Redbook_XAPause(true);
	}
}

// @Ok
// @Matching
void SFX_SetVoiceVolume(u32 a1, i16 a2)
{
	if (a1)
	{
		for (i32 i = 0; i < 32; i++)
		{
			if (a1 & (1<< i))
			{
				gSfxEntries[i].field_16 = a2;

				SFX_ModifyVol(
						1 << i,
						gSfxEntries[i].field_16,
						gSfxEntries[i].field_16);
				break;
			}
		}
	}
}

// @Ok
// @NotMatching: the null subs are weird are probably fucked the inlining
void SFX_ShutDown(void)
{
	if (gSfxInited)
	{
		SFX_CloseBank(&gSfxRelatedOutLevel);
		SFX_CloseBank(&gSoundBank);

		nullsub_3();
		nullsub_3();

		gSfxInited = 0;
	}
}

// @Ok
// @AlmostMatching: SFX_CloseBank in the original doesn't inline SFX_Stop for some reason
void SFX_SpoolInLevelSFX(const char *p_name)
{
	DoAssert(p_name && *p_name, "bad level sfx bank filename");

	SFX_CloseBank(&gSfxRelatedOutLevel);

	char v5[56];
	CopyFilenameDefaultExtension(v5, sizeof(v5), p_name, ".kat");
	SFX_LoadBank(v5, &gSfxRelatedOutLevel);

	CopyFilenameDefaultExtension(v5, sizeof(v5), p_name, ".sfx");
	SFX_ParseSFXFile(v5, SFXLevelSpecificArray, SFXLevelSpecificAliasArray, 64, 0x40000000);
}

// @Ok
// @AlmostMatching: inlining diffs by 4 bytes due to 2 inlined functions diffing 2 bytes
void SFX_SpoolOutLevelSFX(void)
{
	SFX_CloseBank(&gSfxRelatedOutLevel);
}

// @Ok
// @AlmostMatching: same size and reg allocation, just shifted pointer diff offsets for gSfxEntries
void SFX_Unpause(void)
{
	if (SFXPaused)
	{
		SFXPaused = 0;
		for (i32 i = 0; i < 32; i++)
		{
			if (gSfxEntries[i].field_1B)
			{
				u8 v5;
				if (!(gSfxEntries[i].field_24 & 0x4000) && gReverbType)
					v5 = 0;
				else
					v5 = 1;


				i32 v6 = (gGameState[12] * ((gSfxEntries[i].field_18 * gSfxEntries[i].field_16) >> 12)) >> 14;
				if (v6 > 0x3FF)
				{
					v6 = 0x3FFF;
				}
				else if (v6 < -16383)
				{
					v6 = -16383;
				}

				i32 v7 = DCSFX_AdjustVol(v6);
				if (v5 == 0)
					acDspSetMixerChannel(i, 0, 15, 10);

				DXSOUND_SetVolume(i, v7);
				DXSOUND_SetPan(i, 15);
				DXSOUND_SetPitch(i, gSfxEntries[i].field_20);
				DXSOUND_Play(i, 1);
			}
		}

		gSfxGlobal = 6666;
		MechList->field_530 = 6666;
		Redbook_XAPause(0);
		nullsub_one_arg(2);
	}
}

// @MEDIUMTODO
u32 playSFX(u32,u8,i16,i16,i32,u16)
{
    printf("playSFX(u32,u8,i16,i16,i32,u16)");
	return 0x30032025;
}

// @NotOk
// @Validate: when inlined
INLINE u32 translateLevelSpecificAliasToIndex(u32 alias)
{
	for (i32 i = 0; i < 64; i++)
	{

		if (SFXLevelSpecificAliasArray[i] == 0xFFFF)
			return 0xFFFFFFFF;

		if (alias == SFXLevelSpecificAliasArray[i])
			return i;
	}

	return 0xFFFFFFFF;
}

// @Ok
// @Matching
INLINE void SFX_StopAll(void)
{
	for (i32 i = 0; i < 24; i++)
	{
		SFX_Stop(1 << i);
	}
}

// @Ok
// @AlmostMatching: the v10 assingment was originally optimized but i managed to make it a little better
// also the last call to playSFX is not perfect matching but fine
// @Validate
u32 SFX_PlayPos(
		u32 sound,
		CVector *pos,
		i32 pitch_offset)
{
	if (!sound)
		return 0;

	u8 v4 = (sound >> 15) & 1;
	u8 v5 = (sound >> 14) & 1;
	u32 sfxIndex = sound & 0xFFFF3FFF;

	u32 v9;
	if (v4)
	{
		v9 = translateLevelSpecificAliasToIndex(sfxIndex);
		if (v9 == 0xFFFFFFFF)
			return 0;
	}
	else
	{
		DoAssert(sfxIndex < 0x40, "SFX index out of bounds");
		v9 = sfxIndex - 1;
	}

	u32 *v10 = &SFXLevelSpecificArray[3 * v9];
	if (!v4)
		v10 = &gSfxArrayOne[3 * v9];

	u32 soundTwo = v10[2];
	u32 v11 = Utils_CalculateSpatialAttenuation(
			pos,
			soundTwo >> 2,
			2 * soundTwo);

	u32 v12 = v10[1];
	u32 v13 = v12 >> 0x10;

	i32 v14 = v11 & 0xFFF;
	v14 <<= 2;
	v14 *= gGameState[12];
	v14 >>= 14;

	i32 v15 = (v11 >> 16) & 0xFFF;
	v15 <<= 2;
	v15 *= gGameState[12];
	v15 >>= 14;

	if (gBootRomSoundMode)
	{
		v15 = (v14 + v15) / 2;
		v14 = v15;
	}

	gSfxPlayRelated = (100 * v13) >> 12;

	u32 result = playSFX(
			v10[0] | (v5 ? 0x4000 : 0),
			v12,
			v14,
			v15,
			pitch_offset,
			v13 & 0xFFFF);

	for (i32 i = 0; i < 32; i++)
	{
		if (result & (1 << i))
		{
			SFXFalloffArray[i] = soundTwo | (v13 << 16);
			break;
		}
	}


	return result;
}

// @Ok
void SFX_LevelStart(void)
{
	SFXPaused = 0;
}

void INLINE SFX_SetReverbType(unsigned char reverb)
{
	gReverbType = reverb != 0;
}

// @Ok
void SFX_ReverbOff(void)
{
	SFX_SetReverbType(0);
}

// @Ok
// @Matching
INLINE void SFX_Stop(u32 a1)
{
	u32 v2 = 0;
	while (a1)
	{
		if (a1 & 1)
		{
			if (!gSfxEntries[v2].field_1A)
				return;
			SFX_KillVoice(v2);
		}

		a1 >>= 1;
		++v2;
	}
}

// @BIGTODO
void SFX_Play(u32, i16, i32)
{
	printf("void SFX_Play(u32, i16, i32)");
}

char* sfx_names[62] = {
	"dem1.sfx",
	"dem2.sfx",
	"dem3.sfx",
	"dem4.sfx",
	"l1a1.sfx",
	"l1a2.sfx",
	"l1a3.sfx",
	"l1a4.sfx",
	"l2a1.sfx",
	"l2a2.sfx",
	"l3a1.sfx",
	"l3a2.sfx",
	"l3a3.sfx",
	"l3a4.sfx",
	"l3a5.sfx",
	"l4a1.sfx",
	"l5a1.sfx",
	"l5a2.sfx",
	"l5a3.sfx",
	"l5a4.sfx",
	"l5a5.sfx",
	"l5a6.sfx",
	"l5a7.sfx",
	"l6a1.sfx",
	"l6a2.sfx",
	"l6a3.sfx",
	"l6a4.sfx",
	"l7a1.sfx",
	"l7a2.sfx",
	"l7a3.sfx",
	"l7a4.sfx",
	"l7a5.sfx",
	"l8a1.sfx",
	"l8a2.sfx",
	"l8a3.sfx",
	"l8a4.sfx",
	"l8a5.sfx",
	"l8a6.sfx",
	"l9a1.sfx",
	"l9a2.sfx",
	"l9a3.sfx",
	"l9a4.sfx",
	"laa1.sfx",
	"laa2.sfx",
	"laa3.sfx",
	"laa4.sfx",
	"lba1.sfx",
	"lba2.sfx",
	"lba3.sfx",
	"lba4.sfx",
	"lca1.sfx",
	"lca2.sfx",
	"lca3.sfx",
	"lca4.sfx",
	"lda1.sfx",
	"lda2.sfx",
	"lda3.sfx",
	"lfa1.sfx",
	"lga1.sfx",
	"lha1.sfx",
	"menu.sfx",
	"zArt.sfx",
};

u32 myAray[192];
u16 myAliasAray[64];

i32 validate_sfx(char *name, i32 mask)
{

	memset(testBuf, 0, 0x800);

	FILE *fp = fopen(name, "rb");

	if (!fp)
	{
		printf("Failed opening file for %s\n", name);
		return 1;
	}

	fseek(fp, 0, SEEK_END);
	i32 size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	if (!fread(testBuf, size, 1, fp))
	{
		printf("Failed reading file %s\n", name);
		return 2;
	}

	fclose(fp);

	memset(myAray, 0, 192*4);
	memset(myAliasAray, 0, 64*2);


	SFX_ParseSFXFile(name, myAray, myAliasAray, 64, mask);

	u32 tmpArray[192];


	char path[256];
	path[0] = '\0';
	strcpy(path, name);
	strcat(path, "_array.bin");

	fp = fopen(path, "rb");
	if (!fp)
	{
		return 3;
	}

	if (!fread(tmpArray, 192*4, 1, fp))
	{
		return 4;
	}

	fclose(fp);


	u16 tmpAlias[64];

	path[0] = '\0';
	strcpy(path, name);
	strcat(path, "_alias.bin");

	fp = fopen(path, "rb");
	if (!fp)
	{
		return 5;
	}

	if (!fread(tmpAlias, 64*2, 1, fp))
	{
		return 6;
	}

	fclose(fp);

	if (memcmp(tmpArray, myAray, 192*4))
	{
		FILE *fp_my = fopen("my_oops.bin", "wb");
		fwrite(myAray, 192*4, 1, fp_my);
		fclose(fp_my);
		printf("SFX: Array validation failed for: %s\n", name);
		return 6;
	}

	if (memcmp(tmpAlias, myAliasAray, 64*2))
	{
		printf("SFX: Alias validation failed for: %s\n", name);
		return 7;
	}


	printf("Done for %s\n", name);

	return 0;
}

extern i32 FAIL_VALIDATION;

void validate_SFXParse(void)
{
	if (validate_sfx("spidey.sfx", 0))
	{
		puts("failed for spidey");
		FAIL_VALIDATION = 1;
		return;
	}

	for (i32 i = 0; i < sizeof(sfx_names) / sizeof (char*); i++)
	{
		if (validate_sfx(sfx_names[i], 0x40000000))
		{
			printf("failed for %s\n", sfx_names[i]);
			FAIL_VALIDATION = 1;
			return;
		}
	}


}

void validate_SSFXBank(void)
{
	VALIDATE_SIZE(SSFXBank, 0x19B0);

	VALIDATE(SSFXBank, mNumAssets, 0x0);
	VALIDATE(SSFXBank, field_4, 0x4);
	VALIDATE(SSFXBank, field_8, 0x8);

	VALIDATE(SSFXBank, mAssets, 0x40);

#ifdef VALIDATE_PARSESFX
	validate_SFXParse();
#endif
}

void validate_SSfxEntry(void)
{
	VALIDATE_SIZE(SSfxEntry, 0x28);

	VALIDATE(SSfxEntry, field_0, 0x0);
	VALIDATE(SSfxEntry, field_4, 0x4);
	VALIDATE(SSfxEntry, field_8, 0x8);
	VALIDATE(SSfxEntry, field_C, 0xC);

	VALIDATE(SSfxEntry, field_18, 0x18)

	VALIDATE(SSfxEntry, field_1A, 0x1A);
	VALIDATE(SSfxEntry, field_1B, 0x1B);
	VALIDATE(SSfxEntry, field_1C, 0x1C);

	VALIDATE(SSfxEntry, field_20, 0x20);

	VALIDATE(SSfxEntry, field_24, 0x24);
}

void validate_SSfxRelated(void)
{
	VALIDATE_SIZE(SSfxRelated, 0x1C);

	VALIDATE(SSfxRelated, field_0, 0x0);
	VALIDATE(SSfxRelated, field_4, 0x4);
	VALIDATE(SSfxRelated, field_8, 0x8);
	VALIDATE(SSfxRelated, field_C, 0xC);

	VALIDATE(SSfxRelated, field_10, 0x10);
	VALIDATE(SSfxRelated, field_14, 0x14);
	VALIDATE(SSfxRelated, field_18, 0x18);
}

void validate_SSfxAsset(void)
{
	VALIDATE_SIZE(SSfxAsset, 0x2C);

	VALIDATE(SSfxAsset, field_4, 0x4);
	VALIDATE(SSfxAsset, field_8, 0x8);
	VALIDATE(SSfxAsset, field_C, 0xC);

	VALIDATE(SSfxAsset, field_14, 0x14);
}
