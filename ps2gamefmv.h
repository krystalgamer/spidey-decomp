#pragma once

#ifndef PS2GAMEFMV_H
#define PS2GAMEFMV_H

#include "export.h"

struct SMovieDetails
{
	char *name;
	u16 width;
	u16 height;
	u16 endframe;

	PADDING(0x10-0x8-2);

	i32 field_10;
	i32 field_14;
};

EXPORT int GameFMV_GetNumMovies(void);
EXPORT u8 GameFMV_PlayMovie(u8, bool, bool, f32);

EXPORT void GameFMV_Init(void);
EXPORT void GameFMV_SetStartTrack(u8);
EXPORT void GameFMV_StopFMV(void);

//#define G_GAME_FMV_ACTIVE (GameFMV_Active)
#define G_GAME_FMV_ACTIVE (*reinterpret_cast<i32*>(0x006151F8))

void validate_SMovieDetails(void);

#endif
