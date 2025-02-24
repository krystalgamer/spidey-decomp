#include "ps2lowsfx.h"
#include "DXsound.h"
#include "ps2redbook.h"
#include <cstring>

#include "validate.h"


EXPORT u8 SFXPaused;
#define LEN_SFX_ENTRIES 32
EXPORT SSfxEntry gSfxEntries[LEN_SFX_ENTRIES];

EXPORT SSFXBank gSoundBank;
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
	if ( dot )
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
void SFX_CloseBank(SSFXBank *)
{
    printf("SFX_CloseBank(SSFXBank *)");
}

// @SMALLTODO
void SFX_FreeVoice(i32)
{
    printf("SFX_FreeVoice(i32)");
}

// @Ok
void SFX_Init(char* pSfxBankName)
{
	char buf[56];
	print_if_false(pSfxBankName && *pSfxBankName, "bad sfx bank filename");

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

// @SMALLTODO
void SFX_KillVoice(u32)
{
    printf("SFX_KillVoice(u32)");
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

// @BIGTODO
void SFX_Stop(u32)
{
	printf("void SFX_Stop(unsigned int)");
}

// @BIGTODO
void SFX_Play(u32, i16, i32)
{
	printf("void SFX_Play(u32, i16, i32)");
}

void validate_SSFXBank(void)
{
}

void validate_SSfxEntry(void)
{
	VALIDATE_SIZE(SSfxEntry, 0x28);

	VALIDATE(SSfxEntry, field_1A, 0x1A);
}
