#pragma once


#ifndef PS2LOWSFX_H
#define PS2LOWSFX_H

#include "export.h"
#include "vector.h"

EXPORT void SFX_PlayPos(unsigned int, CVector*, i32);
EXPORT void SFX_LevelStart(void);
EXPORT void SFX_SetReverbType(unsigned char);
EXPORT void SFX_ReverbOff(void);
EXPORT void SFX_Stop(unsigned int);
EXPORT void SFX_Play(u32, i16, i32);

#endif

