#pragma once

#ifndef PCMUSIC_H
#define PCMUSIC_H

#include "export.h"

EXPORT void CloseMusicFile(void);
EXPORT void MusicThreadProc(void *);
EXPORT i32 NextFrame(void);
EXPORT u8 OpenMusicFile(char *,bool);
EXPORT void PCMUSIC_Finish(void);
EXPORT i32 PCMUSIC_GetStatus(void);
EXPORT void PCMUSIC_Init(void);
EXPORT void PCMUSIC_Pause(i32);
EXPORT u8 PCMUSIC_Play(i32);
EXPORT void PCMUSIC_SetVolume(i32);
EXPORT void PCMUSIC_Stop(void);


#endif
