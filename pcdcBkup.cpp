#include "pcdcBkup.h"
#include "non_win32.h"

#include <cstring>

EXPORT CHAR gMemorycardPath[688];

// @FIXME
EXPORT char* gMusicTracks[1] = { "lol" };

// @Ok
char* MUSICTRACKS_GetTrackName(i32 a1)
{
	return gMusicTracks[a1];
}

// @Ok
// @Matching
i32 buInit(i32, i32, void*, void (*a4)(void))
{
	GetCurrentDirectoryA(0x104u, gMemorycardPath);
	strcat(gMemorycardPath, "\\save\\");
	CreateDirectoryA(gMemorycardPath, 0);
	a4();
	return 0;
}

// @Ok
// @Matching
void buSetCompleteCallback(i32 (*pFunc)(i32, i32, i32, u32))
{
	for (i32 i = 0; i < 8; i++)
	{
		pFunc(i, 1, 0, 0);
	}
}

// @Ok
// @Matching
i32 buIsReady(i32)
{
	return 1;
}

// @Ok
// @Matching
i32 buIsFormat(i32)
{
	return 0;
}

// @Ok
// @Matching
i32 buStat(i32)
{
	return 0;
}
