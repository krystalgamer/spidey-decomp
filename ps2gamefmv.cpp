#include "ps2gamefmv.h"
#include "PCMovie.h"

#include "validate.h"

EXPORT i32 GameFMV_Active;

// @MEDIUMTODO
void GameFMV_PlayMovie(u8, bool, bool, float)
{
	printf("void GameFMV_PlayMovie(u8, bool, book, float)");
}

// @Ok
int GameFMV_GetNumMovies(void)
{
	return 27;
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

// @SMALLTODO
void GameFMV_SetStartTrack(u8)
{
    printf("GameFMV_SetStartTrack(u8)");
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
