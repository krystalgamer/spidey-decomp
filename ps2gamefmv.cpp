#include "ps2gamefmv.h"
#include "PCMovie.h"

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
