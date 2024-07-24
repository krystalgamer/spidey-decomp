#pragma once


#ifndef PS2LOWSFX_H
#define PS2LOWSFX_H

#include "export.h"
#include "vector.h"

EXPORT i32 SFX_PlayPos(u32, CVector*, i32);
EXPORT void SFX_LevelStart(void);
EXPORT void SFX_SetReverbType(unsigned char);
EXPORT void SFX_ReverbOff(void);
EXPORT void SFX_Stop(u32);
EXPORT void SFX_Play(u32, i16, i32);
EXPORT void SFX_StopAll(void);

#endif

