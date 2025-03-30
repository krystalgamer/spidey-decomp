#pragma once


#ifndef PS2LOWSFX_H
#define PS2LOWSFX_H

#include "export.h"
#include "vector.h"
#include <cstring>

struct SSfxAsset
{
	PADDING(4);

	i32 field_4;
	u32 field_8;
	i32 field_C;

	PADDING(0x14-0xC-4);

	i32 field_14;

	PADDING(0x2C-0x14-4);
};

struct SSfxRelated
{
	SSfxRelated(void)
	{
		this->field_0 = 0;
		this->field_8 = 0;
		this->field_4 = 0;
		this->field_10 = 0;
		this->field_C = 0;
		this->field_18 = 0;

		this->field_14 = 0;
	}

	void *field_0;
	i32 field_4;
	i32 field_8;
	i32 field_C;
	i32 field_10;
	i32 field_14;
	i32 field_18;
};

struct SSfxEntry
{
	i32 field_0;
	i32 field_4;
	i32 field_8;
	i32 field_C;

	i32 field_10;

	u16 field_14;

	u16 field_16;
	u16 field_18;

	u8 field_1A;
	u8 field_1B;
	i32 field_1C;

	i32 field_20;

	i32 field_24;
};

#define NUM_ASSETS_PER_BANK 148

struct SSFXBank
{
	// @Ok
	SSFXBank(void)
	{
		this->mNumAssets = 0;
		this->field_4 = 0;
		this->field_8[0] = 0;

		memset(&this->mAssets, 0, sizeof(SSfxAsset) * NUM_ASSETS_PER_BANK);
	}

	i32 mNumAssets;
	i32 field_4;
	char field_8[0x38];
	
	SSfxAsset mAssets[NUM_ASSETS_PER_BANK];
};

EXPORT u32 SFX_PlayPos(u32, CVector*, i32);
EXPORT void SFX_LevelStart(void);
EXPORT void SFX_SetReverbType(unsigned char);
EXPORT void SFX_ReverbOff(void);
EXPORT void SFX_Stop(u32);
EXPORT void SFX_Play(u32, i16, i32);
EXPORT void SFX_StopAll(void);

EXPORT void CopyFilenameDefaultExtension(char *,i32,const char*,const char*);
EXPORT i32 DCSFX_AdjustVol(i32);
EXPORT void DCSetBootROMSoundMode(bool);
EXPORT i32 PSXPitchToDCPitch(i32);
EXPORT i32 SFX_AllocVoice(i32,bool);
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
EXPORT u32 playSFX(u32,u8,i16,i16,i32,u16);
EXPORT u32 translateLevelSpecificAliasToIndex(u32);

void validate_SSFXBank(void);
void validate_SSfxEntry(void);
void validate_SSfxRelated(void);
void validate_SSfxAsset(void);

#endif

