#pragma once


#ifndef PS2LOWSFX_H
#define PS2LOWSFX_H

#include "export.h"
#include "vector.h"


struct SSfxEntry
{
	u8 padTop[0x1A];
	u8 field_1A;
	u8 padBottom[0x28-0x1A-1];
};

struct SSFXBank
{
};

EXPORT i32 SFX_PlayPos(u32, CVector*, i32);
EXPORT void SFX_LevelStart(void);
EXPORT void SFX_SetReverbType(unsigned char);
EXPORT void SFX_ReverbOff(void);
EXPORT void SFX_Stop(u32);
EXPORT void SFX_Play(u32, i16, i32);
EXPORT void SFX_StopAll(void);

EXPORT void CopyFilenameDefaultExtension(char *,i32,const char*,const char*);
EXPORT void DCSFX_AdjustVol(i32);
EXPORT void DCSetBootROMSoundMode(bool);
EXPORT void PSXPitchToDCPitch(i32);
EXPORT void SFX_AllocVoice(i32,bool);
EXPORT void SFX_CloseBank(SSFXBank *);
EXPORT void SFX_FreeVoice(i32);
EXPORT void SFX_Init(char *);
EXPORT void SFX_InitAtStart(void);
EXPORT void SFX_KillVoice(u32);
EXPORT void SFX_LoadBank(const char*,SSFXBank *);
EXPORT void SFX_ModifyPos(u32,const CVector *,i32);
EXPORT void SFX_ModifyVol(u32,i32,i32);
EXPORT void SFX_Off(void);
EXPORT void SFX_ParseSFXFile(char *,u32 *,u16 *,i32,i32);
EXPORT void SFX_Pause(void);
EXPORT void SFX_SetVoiceVolume(u32,i16);
EXPORT void SFX_ShutDown(void);
EXPORT void SFX_SpoolInLevelSFX(const char *);
EXPORT void SFX_SpoolOutLevelSFX(void);
EXPORT void SFX_Unpause(void);
EXPORT void playSFX(u32,u8,i16,i16,i32,u16);
EXPORT void translateLevelSpecificAliasToIndex(u32);

void validate_SSFXBank(void);
void validate_SSfxEntry(void);

#endif

