#pragma once

#ifndef PCDCMEM_H
#define PCDCMEM_H

#include "export.h"

struct MEMORY_ALLOC
{
	void* mAddress;
	u32 mSize;
	MEMORY_ALLOC* mNext;
	MEMORY_ALLOC* mPrev;
};


EXPORT void syMallocFinish(void);
EXPORT void syMallocInit(void);
EXPORT void *syMalloc(u32);
EXPORT void syFree(void*);

EXPORT void addMemoryAlloc(MEMORY_ALLOC *);
EXPORT void removeMemoryAlloc(MEMORY_ALLOC *);

void validate_MEMORY_ALLOC(void);

#endif
