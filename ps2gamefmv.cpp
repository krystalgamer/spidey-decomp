#include "ps2gamefmv.h"
#include "PCMovie.h"


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

// @SMALLTODO
void GameFMV_Init(void)
{
	PCMOVIE_Init();
}

// @SMALLTODO
void GameFMV_SetStartTrack(u8)
{
    printf("GameFMV_SetStartTrack(u8)");
}

// @SMALLTODO
void GameFMV_StopFMV(void)
{
    printf("GameFMV_StopFMV(void)");
}
