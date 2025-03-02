#include "PCMovie.h"
#include "pkr.h"
#include "non_win32.h"
#include "SpideyDX.h"
#include "my_bink.h"
#include "DXinit.h"
#include "DXsound.h"

#include <cstring>

EXPORT LIBPKR_HANDLE* gMediaPkr;

EXPORT char gMovieCurrentDirectory[0x200];
EXPORT u8 gFoundMediaPkr;

EXPORT char gCdPath[0x100];
EXPORT u8 gPcMovieInited;

EXPORT HBINK gMovieBinkRelated;
EXPORT HANDLE gMovieFileHandle;

EXPORT BINKSUMMARY g_BinkSummaryOne;
EXPORT u32 g_CloneBinkSummaryOne;
EXPORT u32 g_CloneBinkSummaryTwo;
EXPORT u32 g_BinkDestx;
EXPORT u32 g_BinkDesty;

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

// @Ok
INLINE u8 CreateMovieSurface(void)
{
#ifdef _WIN32

	DDSURFACEDESC2 v12;
	memset(&v12, 0, sizeof(v12));

	v12.dwSize = sizeof(v12);
	v12.dwFlags = 7;
	v12.ddsCaps.dwCaps = 64;
	v12.dwWidth = g_BinkSummaryOne.Width;
	v12.dwHeight = g_BinkSummaryOne.Height;

	HRESULT hr = g_MovieDD7->CreateSurface(
			&v12,
			&g_MovieDD7Surface, 0);
	D3D_ERROR_LOG_AND_QUIT(hr);

	g_MoviePrimarySurfaceType = BinkDDSurfaceType(g_MovieDD7Surface);
	if (g_MoviePrimarySurfaceType == -1 || !g_MoviePrimarySurfaceType)
		DXERR_printf("Bink: Unsupported primary surface format %d.", g_MoviePrimarySurfaceType);

#endif
	return 1;
}

// @Ok
// @Matching
INLINE i32 NextMovieFrame(void)
{
#ifdef _WIN32
	if (!gMovieBinkRelated)
		return 0;
	BinkDoFrame(gMovieBinkRelated);

	DDSURFACEDESC2 v6;
	memset(&v6, 0, sizeof(v6));
	v6.dwSize = sizeof(v6);

	HRESULT v1 = g_MovieDD7Surface->Lock(
			0,
			&v6,
			2081,
			0);
	if (v1 == DDERR_SURFACELOST)
	{
		v1 = g_MovieDD7Surface->Restore();
	}

	D3D_ERROR_LOG_AND_QUIT(v1);

	BinkCopyToBuffer(
		gMovieBinkRelated,
		v6.lpSurface,
		v6.lPitch,
		g_BinkSummaryOne.Height,
		g_BinkDestx,
		g_BinkDesty,
		g_MoviePrimarySurfaceType);

	HRESULT v2 = g_MovieDD7Surface->Unlock(0);

	D3D_ERROR_LOG_AND_QUIT(v2);


	DDBLTFX v7;
	memset(&v7, 0, sizeof(v7));
	v7.dwSize = sizeof(v7);
	HRESULT v4 = g_pDDS_Scene->Blt(
			0,
			g_MovieDD7Surface,
			0,
			0x1000000,
			&v7);

	D3D_ERROR_LOG_AND_QUIT(v4);

	DXPOLY_Flip();

	if (gMovieBinkRelated->FrameNum == gMovieBinkRelated->Frames)
	{
		return 0;
	}

	BinkNextFrame(gMovieBinkRelated);
	return 1;
#else
	return 0;
#endif
}

// @Ok
INLINE u8 OpenMovieFile(char *a1, bool)
{
	char v14[256];

	strcpy(v14, "movie\\");
	strcat(v14, a1);

	DXERR_printf("\t\tMOVIE PLAYING %s\r\n", v14);
	if (gMediaPkr)
	{
		char v10[32];
		char a3[32];
		char a2[32];
		CHAR FileName[256];

		strcpy(FileName, gMediaPkr->name);
		strcpy(v10, v14);

		strcpy(a3, strrchr(v14, '\\') + 1);

		strrchr(v10, '\\')[1] = 0;
		strcpy(a2, "data\\");
		strcat(a2, v10);

		i32 fileOffset = findFileOffsetPKR(a2, a3);
		if (fileOffset == -1)
			goto open_movie_file_error;
		PKR_UnlockFile(gMediaPkr);

#ifdef _WIN32
		HANDLE FileA = CreateFileA(FileName, 0x80000000, 1u, 0, 3u, 1u, 0);
		gMovieFileHandle = FileA;
		if (FileA == INVALID_HANDLE_VALUE)
		{
			PKR_LockFile(gMediaPkr);
			gMovieFileHandle = 0;
			goto open_movie_file_error;
		}

		SetFilePointer(FileA, fileOffset, 0, 0);
#endif
	}

	HBINK v5;
	if (gMovieFileHandle)
	{
		v5 = BinkOpen(
				gMovieFileHandle,
				BINKIOSIZE | BINKFILEHANDLE);
	}
	else
	{
		strcpy(v14, "data\\movie\\");
		strcat(v14, a1);
		v5 = BinkOpen(v14, BINKIOSIZE);
	}

	gMovieBinkRelated = v5;

	if (!gMovieBinkRelated)
		goto open_movie_file_error;

	BinkSetVideoOnOff(v5, 1);
	BinkGetSummary(gMovieBinkRelated, &g_BinkSummaryOne);

	g_BinkDestx = 0;
	g_BinkDesty = 0;

	g_CloneBinkSummaryOne = g_BinkSummaryOne.Width;
	g_CloneBinkSummaryTwo = g_BinkSummaryOne.Height;

	return 1;

open_movie_file_error:
	DXERR_printf("\t\tUnable to open movie file %s\r\n", a1);
	return 0;
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
INLINE void PCMOVIE_Init(void)
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

// @Ok
// @Matching
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

// @Ok
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
INLINE void PCMOVIE_Stop(void)
{
	CloseMovieFile();
}

// @Ok
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
