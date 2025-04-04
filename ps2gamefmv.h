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
EXPORT u8 GameFMV_PlayMovie(u8, bool, bool, float);

EXPORT void GameFMV_Init(void);
EXPORT void GameFMV_SetStartTrack(u8);
EXPORT void GameFMV_StopFMV(void);

void validate_SMovieDetails(void);

#endif
