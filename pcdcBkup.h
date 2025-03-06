#pragma once

#ifndef PCDCBKUP_H
#define PCDCBKUP_H

#include "export.h"

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

#endif
