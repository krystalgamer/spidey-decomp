#pragma once

#ifndef PCDCBKUP_H
#define PCDCBKUP_H

#include "export.h"
#include "ps2card.h"
#include "stubs.h"

struct SBackupFile
{
	char mName[16];

	PADDING(2);

	char mDesc[20];

	PADDING(0x12-4);

	char field_34[16];

	i16* field_44;
	u8* field_48;

	i16 field_4C;
	i16 field_4E;

	i32 field_50;
	i16 field_54;

	PADDING(2);

	SCardHead* pCardHead;
	i32 mBackupSize;
};

EXPORT i32 buInit(i32, i32, void*, void (*a4)(void));
EXPORT void buSetCompleteCallback(i32 (*pFunc)(i32, i32, i32, u32));
EXPORT i32 buIsReady(i32);
EXPORT char* MUSICTRACKS_GetTrackName(i32);
EXPORT i32 buIsFormat(i32);
EXPORT i32 buStat(i32);
EXPORT i32 buGetLastError(i32);
EXPORT i32 buExit(void);
EXPORT i32 buGetDiskFree(i32, i32);
EXPORT i32 buCalcBackupFileSize(u32, u32, u32);
EXPORT i32 buGetFileSize(i32, const char*);
EXPORT i32 buLoadFile(i32, const char*, void*, i32);
EXPORT i32 buAnalyzeBackupFileImage(SBackupFile*, void*);
EXPORT i32 buMakeBackupFileImage(void*, SBackupFile*);
EXPORT i32 buSaveFile(i32, const char*, void *, i32, SDCCardTime*);

void validate_SBackupFile(void);

#endif
