#include "PCMovie.h"
#include "pkr.h"
#include "non_win32.h"

EXPORT LIBPKR_HANDLE* gMediaPkr;

EXPORT char gMovieCurrentDirectory[0x200];
EXPORT u8 gFoundMediaPkr;


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

EXPORT char gCdPath[0x100];

// @Ok
// @Matching
void PCMOVIE_InitOnce(void)
{
	CHAR RootPathName[32];
	char rootCdPath[0x80];
	char mediaPkrPath[0x100];

	char v0 = 'C';
	strcpy(RootPathName, "C:");
	strcpy(gCdPath, RootPathName);

	while (1)
	{
		RootPathName[0] = v0;
		if (GetDriveTypeA(RootPathName) == 5)
		{
			strcpy(rootCdPath, RootPathName);
			strcat(rootCdPath, "\\Setup");

			strcpy(mediaPkrPath, rootCdPath);
			strcat(mediaPkrPath, "\\");
			strcat(mediaPkrPath, "SpideyPC.exe");
			FILE* v1 = fopen(mediaPkrPath, "rb");
			if (v1)
			{
				fclose(v1);
				strcpy(gCdPath, rootCdPath);
				printf_fancy("CDPATH: %s\r\n", gCdPath);
				break;
			}
		}

		v0++;
		if (v0 < 'Z')
			continue;

		printf_fancy("CDPATH: %s - NOT FOUND\r\n", gCdPath);
		break;
	}

	GetCurrentDirectoryA(0x200u, gMovieCurrentDirectory);
	strcpy(mediaPkrPath, gMovieCurrentDirectory);
	strcat(mediaPkrPath, "\\");
	strcat(mediaPkrPath, "Media.pkr");
	FILE* mediaFp = fopen(mediaPkrPath, "rb");

	if (mediaFp)
	{
		fclose(mediaFp);
		gFoundMediaPkr = 1;
	}
	else
	{
		gFoundMediaPkr = 0;
	}
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
