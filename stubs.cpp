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
