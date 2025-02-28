#pragma once

#ifndef PCMOVIE_H
#define PCMOVIE_H

#include "export.h"

EXPORT void CloseMovieFile(void);
EXPORT u8 CreateMovieSurface(void);
EXPORT i32 NextMovieFrame(void);
EXPORT u8 OpenMovieFile(char *,bool);
EXPORT void PCMOVIE_ClosePKR(void);
EXPORT void PCMOVIE_Init(void);
EXPORT void PCMOVIE_InitOnce(void);
EXPORT u8 PCMOVIE_NextFrame(void);
EXPORT void PCMOVIE_OpenPKR(void);
EXPORT u8 PCMOVIE_Play(char *,i32);
EXPORT void PCMOVIE_SetVolume(i32);
EXPORT void PCMOVIE_Stop(void);
EXPORT void findFileOffsetPKR(char *,char const *);

#endif
