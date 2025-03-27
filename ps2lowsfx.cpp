#include "ps2lowsfx.h"
#include "DXsound.h"
#include "ps2redbook.h"
#include "my_assert.h"
#include "PCGfx.h"
#include "pcdcMem.h"
#include "stubs.h"
#include <cstring>

#include "validate.h"

// @Ok
EXPORT bool gBootRomSoundMode;

// @Ok
u8 gSfxVolArr[256] =
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


// @FIXME: get proper size
EXPORT u32 gSfxArrayOne[256];

// @FIXME: get proper size
EXPORT u16 gSfxArraAliasyOne[256];

// @IGNOREME
// @Note: exists purely for matching purposes
static void nullsub_3(void)
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

	char *dot = strrchr(dst, 46);
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

// @SMALLTODO
void PSXPitchToDCPitch(i32)
{
    printf("PSXPitchToDCPitch(i32)");
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
		pBank->field_0 = 0;

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

// @SMALLTODO
void SFX_InitAtStart(void)
{
    printf("SFX_InitAtStart(void)");
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

// @MEDIUMTODO
void SFX_LoadBank(const char*,SSFXBank *)
{
    printf("SFX_LoadBank(char const *,SSFXBank *)");
}

// @SMALLTODO
void SFX_ModifyPos(u32,const CVector *,i32)
{
    printf("SFX_ModifyPos(u32,CVector const *,i32)");
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

// @MEDIUMTODO
void SFX_ParseSFXFile(char *,u32 *,u16 *,i32,i32)
{
    printf("SFX_ParseSFXFile(char *,u32 *,u16 *,i32,i32)");
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

// @SMALLTODO
void SFX_SpoolInLevelSFX(const char *)
{
    printf("SFX_SpoolInLevelSFX(char const *)");
}

// @SMALLTODO
void SFX_SpoolOutLevelSFX(void)
{
    printf("SFX_SpoolOutLevelSFX(void)");
}

// @SMALLTODO
void SFX_Unpause(void)
{
    printf("SFX_Unpause(void)");
}

// @MEDIUMTODO
void playSFX(u32,u8,i16,i16,i32,u16)
{
    printf("playSFX(u32,u8,i16,i16,i32,u16)");
}

// @SMALLTODO
void translateLevelSpecificAliasToIndex(u32)
{
    printf("translateLevelSpecificAliasToIndex(u32)");
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

// @BIGTODO
i32 SFX_PlayPos(u32, CVector*, i32)
{
	return 0x23072024;
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

void validate_SSFXBank(void)
{
	VALIDATE_SIZE(SSFXBank, 0x19B0);

	VALIDATE(SSFXBank, field_0, 0x0);
	VALIDATE(SSFXBank, field_4, 0x4);
	VALIDATE(SSFXBank, field_8, 0x8);

	VALIDATE(SSFXBank, field_40, 0x40);
}

void validate_SSfxEntry(void)
{
	VALIDATE_SIZE(SSfxEntry, 0x28);

	VALIDATE(SSfxEntry, field_0, 0x0);
	VALIDATE(SSfxEntry, field_4, 0x4);
	VALIDATE(SSfxEntry, field_8, 0x8);
	VALIDATE(SSfxEntry, field_C, 0xC);

	VALIDATE(SSfxEntry, field_10, 0x10);

	VALIDATE(SSfxEntry, field_16, 0x16);

	VALIDATE(SSfxEntry, field_1A, 0x1A);
	VALIDATE(SSfxEntry, field_1B, 0x1B);
	VALIDATE(SSfxEntry, field_1C, 0x1C);

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
