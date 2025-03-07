#include "pcdcBkup.h"
#include "non_win32.h"

#include "validate.h"

#include <cstring>

EXPORT CHAR gMemorycardPath[688];

// @FIXME
EXPORT char* gMusicTracks[1] = { "lol" };

// @Ok
// @Matching
INLINE i32 buCalcBackupFileSize(
		u32,
		u32,
		u32 a3)
{
	i32 result = a3 >> 9;
	if ((a3 & 0x1FF) > 0)
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

// @Ok
// @Matching
i32 buGetFileSize(
		i32 a1,
		const char* a2)
{
	char v6[260];
	strcpy(v6, gMemorycardPath);
	strcat(v6, a2);

	FILE* v2 = fopen(v6, "rb");
	if (v2)
	{
		fseek(v2, 0, 2);

		i32 v4 = ftell(v2);
		fclose(v2);
		return buCalcBackupFileSize(0, 0, v4);
	}

	return -1;

}

// @Ok
// @Matching
i32 buLoadFile(
		i32 a1,
		const char* a2,
		void* a3,
		i32 a4)
{
	char v7[260];

	strcpy(v7, gMemorycardPath);
	strcat(v7, a2);

	FILE *v4 = fopen(v7, "rb");
	if (!v4)
		return -249;

	fread(a3, 0x200u, a4, v4);
	fclose(v4);
	return 0;
}

// @SMALLTODO
i32 buAnalyzeBackupFileImage(SBackupFile*, void*)
{
	printf("i32 buAnalyzeBackupFileImage(SBackupFile*, void*)");
	return 0x06032025;
}

// @SMALLTODO
i32 buMakeBackupFileImage(void*, SBackupFile*)
{
	printf("i32 buMakeBackupFileImage(void*, SBackupFile*)");
	return 0x06032025;
}

// @SMALLTODO
i32 buSaveFile(i32, const char*, void *, i32, SDCCardTime*)
{
	printf("i32 buSaveFile(i32, i32, void *, i32, i32)");
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
