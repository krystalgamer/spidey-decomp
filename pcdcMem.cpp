#include "pcdcMem.h"
#include <cstdlib>

#include "validate.h"

EXPORT MEMORY_ALLOC* gSysMemory;

// @SMALLTODO
void syFree(void*)
{
	printf("void syFree(void*)");
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

	addMemoryAlloc(newBlock);

	return newBlock->mAddress;
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
void syMallocInit(void)
{
	gSysMemory = 0;
}

// @Ok
INLINE void addMemoryAlloc(MEMORY_ALLOC *pBlock)
{
	if (!gSysMemory)
	{
		gSysMemory = pBlock;
		pBlock->mPrev = 0;
		pBlock->mNext = 0;
	}
	else
	{
		MEMORY_ALLOC* openNext = gSysMemory;
		MEMORY_ALLOC* pSearch = gSysMemory->mNext;

		while (pSearch)
		{
			openNext = pSearch;
			pSearch = pSearch->mNext;
		}

		openNext->mNext = pBlock;
		pBlock->mPrev = openNext;
		pBlock->mNext = 0;
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
