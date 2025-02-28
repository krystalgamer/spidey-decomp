#include "PCMovie.h"
#include "pkr.h"
#include "non_win32.h"

#include <cstring>

EXPORT LIBPKR_HANDLE* gMediaPkr;

EXPORT char gMovieCurrentDirectory[0x200];
EXPORT u8 gFoundMediaPkr;

EXPORT char gCdPath[0x100];
EXPORT u8 gPcMovieInited;



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
// wait for DXINIT stuff
void PCMOVIE_Init(void)
{
	if (!gPcMovieInited)
	{
		/*
		BinkSetSoundSystem(BinkOpenDirectSound, dword_6B7920);
		result = BinkSetIOSize(256);
		*/
		gPcMovieInited = 1;
	}
}

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
		if (GetDriveTypeA(RootPathName) == DRIVE_CDROM)
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

	GetCurrentDirectoryA(0x200, gMovieCurrentDirectory);
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
u8 PCMOVIE_NextFrame(void)
{
	printf("u8 PCMOVIE_NextFrame(void)");
	return (u8)0x28022025;
}

// @SMALLTODO
void PCMOVIE_OpenPKR(void)
{
    printf("PCMOVIE_OpenPKR(void)");
}

// @SMALLTODO
u8 PCMOVIE_Play(char *,i32)
{
    printf("PCMOVIE_Play(char *,i32)");
	return (u8)0x2802025;
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
void findFileOffsetPKR(char *,char const *)
{
    printf("findFileOffsetPKR(char *,char const *)");
}
