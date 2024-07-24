#pragma once

#ifndef PS2GAMEFMV_H
#define PS2GAMEFMV_H

#include "export.h"

EXPORT int GameFMV_GetNumMovies(void);
EXPORT void GameFMV_PlayMovie(u8, bool, bool, float);

#endif
