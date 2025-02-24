#include "stubs.h"
#include "PCMusic.h"
#include "validate.h"

#include <cstdlib>

EXPORT MEMORY_ALLOC* gSysMemory;

// @Ok
// @Matching
void ADXT_Init(void)
{
	PCMUSIC_Init();
}

// @Ok
// @Matching
i32 ADXT_GetStat(void)
{
	return PCMUSIC_GetStatus() ? 4 : 0;
}

// @Ok
// @Matching
void ADXT_StartAfs(i32, i32, i32 a3)
{
	PCMUSIC_Play(a3);
}

// @Ok
// @Matching
void ADXT_Finish(void)
{
	PCMUSIC_Finish();
}

// @Ok
void *syMalloc(u32 size)
{
	if (!size)
	{
		error("MEMORY ALLOC of size 0\n");
		return 0;
	}

	MEMORY_ALLOC* newBlock = static_cast<MEMORY_ALLOC*>(malloc(sizeof(MEMORY_ALLOC)));
	newBlock->mSize = size;
	newBlock->mAddress = malloc(newBlock->mSize);

	if (!gSysMemory)
	{
		gSysMemory = newBlock;
		newBlock->mPrev = 0;
		newBlock->mNext = 0;
		return newBlock->mAddress;
	}
	else
	{
		MEMORY_ALLOC* openNext = gSysMemory;

		for(
				MEMORY_ALLOC *pSearch = gSysMemory->mNext;
				pSearch;
				pSearch = pSearch->mNext)
		{
			openNext = pSearch;
		}

		openNext->mNext = newBlock;
		newBlock->mPrev = openNext;
		newBlock->mNext = 0;
	}

	return newBlock->mAddress;
}

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

// @Ok
i32 gsExit(void)
{
	return 1;
}

// @Ok
i32 syCblCheck(void)
{
	return 1;
}

// @Ok
i32 syCblCheckBroadcast(void)
{
	return 0;
}

void validate_MEMORY_ALLOC(void)
{
	VALIDATE_SIZE(MEMORY_ALLOC, 0x10);

	VALIDATE(MEMORY_ALLOC, mAddress, 0x0);
	VALIDATE(MEMORY_ALLOC, mSize, 0x4);
	VALIDATE(MEMORY_ALLOC, mNext, 0x8);
	VALIDATE(MEMORY_ALLOC, mPrev, 0xC);
}
