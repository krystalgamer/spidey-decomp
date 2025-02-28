#include "ps2gamefmv.h"
#include "PCMovie.h"

#include "validate.h"

EXPORT i32 GameFMV_Active;
EXPORT u8 GameFMV_CurrentTrack;

EXPORT i32 gGameFmvOne;
EXPORT u8 gGameFmvTwo;

EXPORT u16 GameFMV_Width;
EXPORT u16 GameFMV_Height;
EXPORT i32 GameFMV_EndFrame;


#define NUM_MOVIES 27

// @NotOk
// @FIXME
SMovieDetails movieDetails[NUM_MOVIES];

// @MEDIUMTODO
void GameFMV_PlayMovie(u8, bool, bool, float)
{
	printf("void GameFMV_PlayMovie(u8, bool, book, float)");
}

// @Ok
int GameFMV_GetNumMovies(void)
{
	return NUM_MOVIES;
}

// @Ok
int PShell_GetNumCostumePSXs(void)
{
	return 10;
}

// @Ok
// @Matching
void GameFMV_Init(void)
{
	PCMOVIE_Init();
}

// @Ok
// @Matching
void GameFMV_SetStartTrack(u8 track)
{
	if ( !GameFMV_Active )
	{
		print_if_false(track < 27u, "Bad track");
		print_if_false(GameFMV_Active == 0, "Track change when active");

		GameFMV_CurrentTrack = track;

		GameFMV_Width = movieDetails[track].width;
		GameFMV_Height = movieDetails[track].height;

		GameFMV_EndFrame = movieDetails[track].endframe;

		gGameFmvTwo = movieDetails[track].field_10;
		gGameFmvOne = movieDetails[track].field_14;
	}
}

// @Ok
// @Matching
void GameFMV_StopFMV(void)
{
	if (GameFMV_Active)
	{
		PCMOVIE_Stop();
		GameFMV_Active = 0;
	}
}

void validate_SMovieDetails(void)
{
	VALIDATE_SIZE(SMovieDetails, 0x18);

	VALIDATE(SMovieDetails, name, 0x0);

	VALIDATE(SMovieDetails, width, 0x4);
	VALIDATE(SMovieDetails, height, 0x6);
	VALIDATE(SMovieDetails, endframe, 0x8);

	VALIDATE(SMovieDetails, field_10, 0x10);
	VALIDATE(SMovieDetails, field_14, 0x14);
}
