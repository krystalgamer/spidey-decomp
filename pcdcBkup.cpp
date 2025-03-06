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

	VALIDATE(SBackupFile, mName, 0x0);
	VALIDATE(SBackupFile, mDesc, 0x12);

	VALIDATE(SBackupFile, field_34, 0x34);

	VALIDATE(SBackupFile, field_44, 0x44);
	VALIDATE(SBackupFile, field_48, 0x48);
	VALIDATE(SBackupFile, field_4C, 0x4C);
	VALIDATE(SBackupFile, field_4E, 0x4E);
	VALIDATE(SBackupFile, field_50, 0x50);
	VALIDATE(SBackupFile, field_54, 0x54);

	VALIDATE(SBackupFile, pCardHead, 0x58);
	VALIDATE(SBackupFile, mBackupSize, 0x5C);
}
