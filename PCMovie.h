#pragma once

#ifndef PCMOVIE_H
#define PCMOVIE_H

#include "export.h"

EXPORT void CloseMovieFile(void);
EXPORT void CreateMovieSurface(void);
EXPORT void NextMovieFrame(void);
EXPORT void OpenMovieFile(char *,bool);
EXPORT void PCMOVIE_ClosePKR(void);
EXPORT void PCMOVIE_Init(void);
EXPORT void PCMOVIE_InitOnce(void);
EXPORT void PCMOVIE_NextFrame(void);
EXPORT void PCMOVIE_OpenPKR(void);
EXPORT void PCMOVIE_Play(char *,i32);
EXPORT void PCMOVIE_SetVolume(i32);
EXPORT void PCMOVIE_Stop(void);
EXPORT void findFileOffsetPKR(char *,char const *);

#endif
