#include "stubs.h"
#include "validate.h"

#include <cstdlib>

EXPORT MEMORY_ALLOC* gSysMemory;

// @Ok
// @Matching
i32 syRtcInit(void)
{
	return 0;
}

// @Ok
// @Matching
void syMallocInit(void)
{
	gSysMemory = 0;
}

// @Ok
// @Matching
void syMallocFinish(void)
{
	while (gSysMemory)
	{
		error("MEMORY NOT FREE: %08X, %i\n", gSysMemory->mAddress, gSysMemory->mSize);
		removeMemoryAlloc(gSysMemory);
	}
}

// @Ok
// @Matching
INLINE void removeMemoryAlloc(MEMORY_ALLOC* pAlloc)
{
	if (gSysMemory == pAlloc)
		gSysMemory = pAlloc->mNext;

	if (pAlloc->mPrev)
		pAlloc->mPrev->mNext = pAlloc->mNext;

	if (pAlloc->mNext)
		pAlloc->mNext->mPrev = pAlloc->mPrev;

	free(pAlloc->mAddress);
	free(pAlloc);
}


void validate_MEMORY_ALLOC(void)
{
	VALIDATE_SIZE(MEMORY_ALLOC, 0x10);

	VALIDATE(MEMORY_ALLOC, mAddress, 0x0);
	VALIDATE(MEMORY_ALLOC, mSize, 0x4);
	VALIDATE(MEMORY_ALLOC, mNext, 0x8);
	VALIDATE(MEMORY_ALLOC, mPrev, 0xC);
}
