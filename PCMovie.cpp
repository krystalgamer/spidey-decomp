#include "PCMovie.h"
#include "pkr.h"
#include "non_win32.h"
#include "SpideyDX.h"
#include "my_bink.h"
#include "DXinit.h"

#include <cstring>

EXPORT LIBPKR_HANDLE* gMediaPkr;

EXPORT char gMovieCurrentDirectory[0x200];
EXPORT u8 gFoundMediaPkr;

EXPORT char gCdPath[0x100];
EXPORT u8 gPcMovieInited;

EXPORT i32 gMovieBinkRelated;
EXPORT HANDLE gMovieFileHandle;

EXPORT DWORD g_BinkSummaryOne;
EXPORT DWORD g_BinkSummaryTwo;

EXPORT LPDIRECTDRAW7 g_MovieDD7;
EXPORT LPDIRECTDRAWSURFACE7 g_MovieDD7Surface;
EXPORT i32 g_MoviePrimarySurfaceType;

// @Ok
// @Matching
void INLINE CloseMovieFile(void)
{
	if (gMovieBinkRelated)
	{
		BinkClose(gMovieBinkRelated);
		if (gMovieFileHandle)
		{
			CloseHandle(gMovieFileHandle);
			gMovieFileHandle = 0;
			PKR_LockFile(gMediaPkr);
		}

		gMovieBinkRelated = 0;
	}
}

// @NotOk
// @Note: Validate when inlined
INLINE u8 CreateMovieSurface(void)
{
#ifdef _WIN32

	DDSURFACEDESC2 v12;
	memset(&v12, 0, sizeof(v12));

	v12.dwSize = 124;
	v12.dwFlags = 7;
	v12.ddsCaps.dwCaps = 64;
	v12.dwWidth = g_BinkSummaryOne;
	v12.dwHeight = g_BinkSummaryTwo;

	HRESULT hr = g_MovieDD7->CreateSurface(
			&v12,
			&g_MovieDD7Surface, 0);
	D3D_ERROR_LOG_AND_QUIT(hr);

	g_MoviePrimarySurfaceType = BinkDDSurfaceType(g_MovieDD7Surface);

#endif
	return 1;
}

// @MEDIUMTODO
i32 NextMovieFrame(void)
{
    printf("NextMovieFrame(void)");
	return 0x28022025;
}

// @MEDIUMTODO
u8 OpenMovieFile(char *,bool)
{
    printf("OpenMovieFile(char *,bool)");
	return (u8)0x28022025;
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

// @Ok
// @Matching
void PCMOVIE_Init(void)
{
	if (!gPcMovieInited)
	{
		BinkSetSoundSystem(BinkOpenDirectSound, g_pDS);
		BinkSetIOSize(256);
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

// @NotOk
// @Note: validate inline
u8 PCMOVIE_NextFrame(void)
{
	if (!gMovieBinkRelated)
		return 0;

	if (BinkWait(gMovieBinkRelated) || NextMovieFrame())
		return 1;

	PCMOVIE_Stop();
	return 0;
}

// @Ok
// @Matching
void PCMOVIE_OpenPKR(void)
{
	char v2[512];
	char v3[512];

	if (!gMediaPkr)
	{
		const char *v0 = gMovieCurrentDirectory;
		if (!gFoundMediaPkr)
			v0 = gCdPath;

		strcpy(v2, v0);
		strcat(v2, "\\");
		strcat(v2, "Media.pkr");

		if (!PKR_Open(&gMediaPkr, v2, 1))
		{
			if (PKR_GetLastError(v3))
			{
				printf_fancy("PKR\t: %s\r\n", v3);
			}
		}
		else
		{
			printf_fancy("PKR\t: Name       : %s\r\n", gMediaPkr->name);
			printf_fancy("PKR\t: N.O. Dir   : %i\r\n", gMediaPkr->mFooter.numDirs);
			printf_fancy("PKR\t: N.O. Files : %i\r\n", gMediaPkr->mFooter.numFiles);
		}
	}
	else
	{
		printf_fancy("PKR\t: PKR %s already open\r\n", gMediaPkr->name);
	}
}

// @NotOk
// @Note: make sure everything is properly inlined
u8 PCMOVIE_Play(char *a1, i32 a2)
{
	PCMOVIE_Init();
	PCMOVIE_Stop();

	print_if_false(a2 != 0, "Request to play a non-full screen movie!");
	if (!OpenMovieFile(a1, 1))
		return 0;
	if (CreateMovieSurface())
	{
		WinYield();
		return 1;
	}

	CloseMovieFile();
	return 0;
}

// @Ok
// @Matching
void PCMOVIE_SetVolume(i32 a1)
{
	BinkSetVolume(gMovieBinkRelated, (a1 << 15) / 255);
	BinkSetPan(gMovieBinkRelated, 0x8000);
}

// @Ok
// @Matching
void PCMOVIE_Stop(void)
{
	CloseMovieFile();
}

// @NotOk
// @Note: validate when inlined
INLINE i32 findFileOffsetPKR(
		char *a1,
		const char *a2)
{
	PKR_FILEINFO v3;
	if (PKR_GetFileInfo(gMediaPkr, a1, a2, &v3))
		return v3.fileOffset;

	char v4[512];
	if (PKR_GetLastError(v4))
		printf_fancy("PKR\t: %s%s - %s\r\n", a1, a2, v4);

	return -1;
}
