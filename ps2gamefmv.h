#pragma once

#ifndef PS2GAMEFMV_H
#define PS2GAMEFMV_H

#include "export.h"

EXPORT int GameFMV_GetNumMovies(void);
EXPORT void GameFMV_PlayMovie(u8, bool, bool, float);

EXPORT void GameFMV_Init(void);
EXPORT void GameFMV_SetStartTrack(u8);
EXPORT void GameFMV_StopFMV(void);

#endif
