#include "ps2lowsfx.h"
#include "DXsound.h"
#include "ps2redbook.h"
#include "my_assert.h"
#include "PCGfx.h"
#include <cstring>

#include "validate.h"

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

// @SMALLTODO
void SFX_AllocVoice(i32,bool)
{
    printf("SFX_AllocVoice(i32,bool)");
}

// @SMALLTODO
void SFX_CloseBank(SSFXBank *pBank)
{
	SFX_StopAll();

	if (pBank->field_4)
	{
		DXSOUND_Unload(pBank->field_8, 0);
		
		if (pBank == &gSoundBank && gSfxRelatedOutLevel.field_4)
			SFX_CloseBank(&gSfxRelatedOutLevel);

		DebugPrintfX("unloading sound bank %s.", pBank->field_8);

		amHeapFree();
		pBank->field_4 = 0;
		pBank->field_0 = 0;
		/*
		if (*v )
			Mem_AlignedDelete(*v1);
		sub_18A1A0((int)v1, 0, 0x1Cu);
		*/
	}
}

// @IGNOREME
// @Note: exists purely for matching purposes
static void nullsub_3(void)
{
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

// @SMALLTODO
void SFX_ShutDown(void)
{
    printf("SFX_ShutDown(void)");
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
void SFX_StopAll(void)
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

	VALIDATE(SSfxEntry, field_10, 0x10);

	VALIDATE(SSfxEntry, field_1A, 0x1A);
	VALIDATE(SSfxEntry, field_1B, 0x1B);
	VALIDATE(SSfxEntry, field_1C, 0x1C);

	VALIDATE(SSfxEntry, field_24, 0x24);
}
