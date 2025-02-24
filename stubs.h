#pragma once

#ifndef STUBS_H
#define STUBS_H

#include "export.h"

struct MEMORY_ALLOC
{
	void* mAddress;
	u32 mSize;
	MEMORY_ALLOC* mNext;
	MEMORY_ALLOC* mPrev;
};

EXPORT i32 syRtcInit(void);
EXPORT void removeMemoryAlloc(MEMORY_ALLOC*);
EXPORT void syMallocFinish(void);
EXPORT void syMallocInit(void);
EXPORT void *syMalloc(u32);
EXPORT i32 gsExit(void);
EXPORT i32 syCblCheck(void);
EXPORT i32 syCblCheckBroadcast(void);

EXPORT void ADXT_Finish(void);
EXPORT void ADXT_StartAfs(i32, i32, i32);
EXPORT i32 ADXT_GetStat(void);

void validate_MEMORY_ALLOC(void);

#endif
