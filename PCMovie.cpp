#include "PCMovie.h"
#include "pkr.h"

EXPORT LIBPKR_HANDLE* gMediaPkr;

// @SMALLTODO
void CloseMovieFile(void)
{
    printf("CloseMovieFile(void)");
}

// @SMALLTODO
void CreateMovieSurface(void)
{
    printf("CreateMovieSurface(void)");
}

// @MEDIUMTODO
void NextMovieFrame(void)
{
    printf("NextMovieFrame(void)");
}

// @MEDIUMTODO
void OpenMovieFile(char *,bool)
{
    printf("OpenMovieFile(char *,bool)");
}

// @Ok
// @Matching
void PCMOVIE_ClosePKR(void)
{
	if (gMediaPkr)
	{
		if (!PKR_Close(gMediaPkr))
		{
			char buf[512];
			if (PKR_GetLastError(buf))
				error("PKR\t: %s\r\n", buf);
		}
		gMediaPkr = 0;
		return;
	}

	error("PKR\t: No PKR currently open.\r\n");
}

// @SMALLTODO
void PCMOVIE_Init(void)
{
    printf("PCMOVIE_Init(void)");
}

// @SMALLTODO
void PCMOVIE_InitOnce(void)
{
    printf("PCMOVIE_InitOnce(void)");
}

// @SMALLTODO
void PCMOVIE_NextFrame(void)
{
    printf("PCMOVIE_NextFrame(void)");
}

// @SMALLTODO
void PCMOVIE_OpenPKR(void)
{
    printf("PCMOVIE_OpenPKR(void)");
}

// @SMALLTODO
void PCMOVIE_Play(char *,i32)
{
    printf("PCMOVIE_Play(char *,i32)");
}

// @SMALLTODO
void PCMOVIE_SetVolume(i32)
{
    printf("PCMOVIE_SetVolume(i32)");
}

// @SMALLTODO
void PCMOVIE_Stop(void)
{
    printf("PCMOVIE_Stop(void)");
}

// @SMALLTODO
void findCD(void)
{
    printf("findCD(void)");
}

// @SMALLTODO
void findFile(char *)
{
    printf("findFile(char *)");
}

// @SMALLTODO
void findFileOffsetPKR(char *,char const *)
{
    printf("findFileOffsetPKR(char *,char const *)");
}

// @SMALLTODO
void tryOpenFile(char *,char *)
{
    printf("tryOpenFile(char *,char *)");
}
