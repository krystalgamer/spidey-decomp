#include "pcdcBkup.h"
#include "non_win32.h"

#include "validate.h"

#include <cstring>

EXPORT CHAR gMemorycardPath[688];

// @FIXME
EXPORT char* gMusicTracks[1] = { "lol" };

// @Ok
// @Matching
i32 buCalcBackupFileSize(
		u32,
		u32,
		u32 a3)
{
	i32 result = a3 >> 9;
	if (a3 & 0x1FF)
		++result;
	return result;
}

// @Ok
// @Matching
i32 buGetDiskFree(i32, i32)
{
	return 0x7FFFFFFF;
}

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

// @Ok
// @Matching
i32 buGetLastError(i32)
{
	return 0;
}

// @Ok
// @Matching
i32 buExit(void)
{
	return 0;
}

// @SMALLTODO
i32 buGetFileSize(i32, const char*)
{
	printf("i32 buGetFileSize(i32, const char*)");
	return 0x06032025;
}

// @SMALLTODO
i32 buLoadFile(i32, const char*, void*, i32)
{
	printf("i32 buLoadFile(i32, const char*, void*, i32)");
	return 0x06032025;
}

// @SMALLTODO
i32 buAnalyzeBackupFileImage(SBackupFile*, void*)
{
	printf("i32 buAnalyzeBackupFileImage(SBackupFile*, void*)");
	return 0x06032025;
}

void validate_SBackupFile(void)
{
	VALIDATE_SIZE(SBackupFile, 0x60);

	VALIDATE(SBackupFile, pCardHead, 0x58);
	VALIDATE(SBackupFile, mBackupSize, 0x5C);
}
