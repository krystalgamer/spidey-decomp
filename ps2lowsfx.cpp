#include "ps2lowsfx.h"
#include "DXsound.h"
#include "ps2redbook.h"
#include "my_assert.h"
#include "PCGfx.h"
#include <cstring>

#include "validate.h"

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

// @SMALLTODO
void DCSFX_AdjustVol(i32)
{
    printf("DCSFX_AdjustVol(i32)");
}

// @SMALLTODO
void DCSetBootROMSoundMode(bool)
{
    printf("DCSetBootROMSoundMode(bool)");
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

// @SMALLTODO
void SFX_ModifyVol(u32,i32,i32)
{
    printf("SFX_ModifyVol(u32,i32,i32)");
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

// @SMALLTODO
void SFX_SetVoiceVolume(u32,i16)
{
    printf("SFX_SetVoiceVolume(u32,i16)");
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

static u8 gReverbType;
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
