#include "mem.h"
#include <cstdlib>
#include <cstring>
#include "validate.h"

#define FALSE 0
#define TRUE 1

EXPORT i32 Used[2];
u32 HeapDefs[MAXHEAPS][2] = { {NULL, NULL}, {NULL, NULL}};

i32 LowMemory = 0;
EXPORT u32 CriticalBigHeapUsage = 0;
EXPORT SBlockHeader *FirstFreeBlock[2];

EXPORT i32 dword_54D55C = 1;

// Proper definition is diff between debug def of SBlockHeader and SDebugBlockHeader
#define MEMDIFF 32

#define BIGHEAPOVERLOAD 98   // 2% left give about 20K
#define PRINTHEAPSIZES 1

// @Ok
// @Leak
// @Matching
void Mem_AlignedDelete(void *p)
{
	Mem_Delete(p);
}

// @Ok
// @CM: Different register allocation
// but code matches perfect :D
void AddToFreeList(SBlockHeader *pNewFreeBlock, int Heap)
{
	SBlockHeader* pAfter = FirstFreeBlock[Heap];
	SBlockHeader* pBefore = 0;

	while (reinterpret_cast<u32>(pAfter) < reinterpret_cast<u32>(pNewFreeBlock))
	{
		if (!pAfter)
			break;

		pBefore = pAfter;
		pAfter = pAfter->Next;
	}

	if (pBefore)
	{
		if ( (SBlockHeader *)((char *)&pBefore[1] + pBefore->Size) == pNewFreeBlock )
		{
			if ( (SBlockHeader *)((char *)&pNewFreeBlock[1] + pNewFreeBlock->Size) == pAfter )
			{
				pBefore->Next = pAfter->Next;
				pBefore->Size = pBefore->Size + pNewFreeBlock->Size + pAfter->Size + 2*32;

				if ( dword_54D55C )
				{
					i32* dst = reinterpret_cast<i32*>(pNewFreeBlock);
					i32 size = ((pNewFreeBlock->Size + 64) >> 2);
					for (i32 i = 0; i < size; i++)
					{
						dst[i] = 0x55555555;
					}
				}
				return;
			}
			else
			{
				pBefore->Size = pBefore->Size + pNewFreeBlock->Size + 32;
				if ( dword_54D55C )
				{
					i32* dst = reinterpret_cast<i32*>(pNewFreeBlock);
					i32 size = ((pNewFreeBlock->Size + 32) >> 2);
					for (i32 i = 0; i < size; i++)
					{
						dst[i] = 0x55555555;
					}
				}
				return;
			}

			return;
		}

		pBefore->Next = pNewFreeBlock;
	}
	else
	{
		FirstFreeBlock[Heap] = pNewFreeBlock;
	}

	if (dword_54D55C)
	{
		i32* dst = reinterpret_cast<i32*>(&pNewFreeBlock[1]);
		i32 size = (pNewFreeBlock->Size >> 2);
		for (i32 i = 0; i < size; i++)
		{
			dst[i] = 0x55555555;
		}
	}

	if ((SBlockHeader*)(reinterpret_cast<char*>(&pNewFreeBlock[1]) + pNewFreeBlock->Size) == pAfter)
	{
		pNewFreeBlock->Next = pAfter->Next;
		pNewFreeBlock->Size = pNewFreeBlock->Size + pAfter->Size + 32;

		if(dword_54D55C)
		{
			i32* dst = reinterpret_cast<i32*>(&pNewFreeBlock[1]);
			for (i32 i = 0; i < (sizeof(SBlockHeader) >> 2); i++)
			{
				dst[i] = 0x55555555;
			}
		}
	}
	else
	{
		pNewFreeBlock->Next = pAfter;
	}

	pNewFreeBlock->UniqueIdentifier = 0;
}

// @Ok
// @Leak
// @Matching
void Mem_Init(void)
{
	printf_fancy("Heap sizes: ");

	for (
			i32 i = 0;
			i < 2;
			i++)
	{
		print_if_false(HeapDefs[i][HBOT] + sizeof(SBlockHeader) < HeapDefs[i][HTOP], "Bad values for HEAPBOT and HEAPTOP");

		// Initialise free list head pointer
		FirstFreeBlock[i] = NULL;
		Used[i] = 0;

		SBlockHeader *pAllFreeMem=(SBlockHeader*)HeapDefs[i][HBOT];

		pAllFreeMem->Size=HeapDefs[i][HTOP]-HeapDefs[i][HBOT]-sizeof(SBlockHeader);

		AddToFreeList(pAllFreeMem,i);
#if PRINTHEAPSIZES
		printf_fancy("Heap %d: %ld bytes, ",i,HeapDefs[i][HTOP]-HeapDefs[i][HBOT]);
#endif
	}

	printf_fancy("\n");
	// Calculate the small heap usage above which the LowMemory global will be set to TRUE.	
	CriticalBigHeapUsage=BIGHEAPOVERLOAD*(HeapDefs[BIGHEAP][HTOP]-HeapDefs[BIGHEAP][HBOT])/100;
}

// @Ok
// @Leak
// @Matching
INLINE void Mem_DeleteX(void *p)
{
	print_if_false(p != 0, "NULL pointer sent to Mem_Delete");

	SBlockHeader *pBlock=GETBLOCKHEADER(p);
	i32 Heap=pBlock->ParentHeap;

	if (!(Heap>=0 && Heap<MAXHEAPS))
	{
		print_if_false(0, "Invalid pointer sent to Mem_Delete");
		return;
	}

	Used[Heap]-=sizeof(SBlockHeader)+pBlock->Size;

	AddToFreeList(pBlock, Heap);

	// Check if the LowMemory indicator needs to stay on or go off.
	if (Heap==BIGHEAP)
	{
		if (Used[Heap]>=CriticalBigHeapUsage)
			LowMemory=TRUE;
		else	
			LowMemory=FALSE;
	}
}

// @Ok
// @NoLeak
// @Matching
INLINE void Mem_CoreDelete(void* a1)
{
	Mem_DeleteX(a1);
}

// @Ok
// @NoLeak
// @Matching
void Mem_Delete(void* a1)
{
	Mem_CoreDelete((char *)a1 - *((char *)a1 - 1));
}

// @Ok
// @Matching
// @Leak
void Mem_ShrinkX(void* p, size_t newsize)
{
	SBlockHeader* pBlock = GETBLOCKHEADER(p);
	i32 Heap = pBlock->ParentHeap;

	print_if_false(newsize <= pBlock->Size, "Illegal newsize %ld sent to Mem_Shrink", newsize);
	print_if_false((newsize & 3) == 0, "newsize %ld not lword aligned", newsize);

	print_if_false(Heap >= 0 && Heap < MAXHEAPS,
			"Corrupt block header, parent heap (%d) out of range", Heap);

	if ( newsize < (pBlock->Size - sizeof(SBlockHeader)) )
	{
		SBlockHeader *pNewFreeBlock=(SBlockHeader*)((char*)p+newsize);
		pNewFreeBlock->Size=pBlock->Size-sizeof(SBlockHeader)-newsize;

		Used[Heap]-=pBlock->Size-newsize;

		pBlock->Size = newsize;
		AddToFreeList(pNewFreeBlock,Heap);

		if ( Heap == BIGHEAP )
		{
			if (Used[Heap] >= CriticalBigHeapUsage)
				LowMemory=TRUE;
			else	
				LowMemory=FALSE;

		}
	}
}

// @Ok
// @NoLeak
INLINE void Mem_CoreShrink(void* p, u32 newsize)
{
	if ( newsize <= 4 )
		newsize = 8;
//	printf ("S %d\n",newsize);
	Mem_ShrinkX(p, newsize);
}

// @Ok
// @AlmostMatching: weird logic, but close
// @Leak
void Mem_Shrink(void* p, size_t newsize)
{
	Mem_CoreShrink(
			(char *)p - *((char *)p - 1),
			newsize + MEMDIFF);
}

// @Ok
// @Matching
// @Leak
void Mem_Copy(void* dest, void* source, i32 bytes)
{
	print_if_false(((i32)dest & 3) == 0, "Not long-aligned");
	print_if_false(((i32)source & 3) == 0, "Not long-aligned");

	// copy 32 bits at a time, then 8 bits at a time
	i32 num32 = bytes >> 2;
	i32 num8 = bytes & 3;

	u32 *s1 = (u32 *) source;
	u32 *d1 = (u32 *) dest;

	while (num32 > 0)
	{
		*(d1++) = *(s1++);
		num32--;
	}

	u8 *s2 = (u8 *) s1;
	u8 *d2 = (u8 *) d1;

	while (num8 > 0)
	{
		*(d2++) = *(s2++);
		num8--;
	}
}

EXPORT u32 UniqueIdentifier;

// @Ok
// what a goofy function. a1 aka the size already contains the space for the head but
// then there's an extra +32 everywhere for some reason
void *Mem_NewTop(unsigned int a1)
{
	UniqueIdentifier = (UniqueIdentifier + 1) & 0x7FFFFFFF;
	if ( !UniqueIdentifier )
		UniqueIdentifier = 1;

	u32 roundedSize = (a1 + 3) & 0xFFFFFFFC;

	print_if_false(roundedSize != 0, "Zero size sent to Mem_New");
	print_if_false(roundedSize < 0xFFFFFFF, "size exceeds 28 bit range");

	SBlockHeader* pCurBlock = FirstFreeBlock[1];
	SBlockHeader* pPrevIterBlock = 0;
	SBlockHeader* pPrevBlock = 0;

	for (
			SBlockHeader* pIter = FirstFreeBlock[1];
			pIter;
			pIter = pIter->Next)
	{
		if (pIter->Size >= roundedSize)
		{
			pCurBlock = pIter;
			pPrevBlock = pPrevIterBlock;
		}

		pPrevIterBlock = pIter;
	}

	u32 v6 = pCurBlock->Size;
	if (v6 < roundedSize)
	{
		return 0;
	}

	if (v6 > roundedSize + 32)
	{
		pCurBlock->Size = v6 - roundedSize - 32;
		SBlockHeader* pNewBlock = reinterpret_cast<SBlockHeader*>(
				reinterpret_cast<char*>(pCurBlock) + v6 - roundedSize);



		pNewBlock->Size = roundedSize;
		pNewBlock->UniqueIdentifier = UniqueIdentifier;
		pNewBlock->ParentHeap = 1;

		void* ret = &pNewBlock[1];

		Used[1] += pNewBlock->Size + 32;
		LowMemory = Used[1] >= CriticalBigHeapUsage;

		for (i32 i = 0; i < (roundedSize >> 2); i++)
		{
			reinterpret_cast<i32*>(ret)[i] = 0x33333333;
		}

		return ret;
	}

	if ( pPrevBlock )
		pPrevBlock->Next = pCurBlock->Next;
	else
		FirstFreeBlock[1] = pCurBlock->Next;

	pCurBlock->UniqueIdentifier = UniqueIdentifier;
	pCurBlock->ParentHeap = 1;

	void* ret = &pCurBlock[1];
	Used[1] += pCurBlock->Size + 32;
	LowMemory = Used[1] >= CriticalBigHeapUsage;
	for (i32 i = 0; i < (roundedSize >> 2); i++)
	{
		reinterpret_cast<i32*>(ret)[i] = 0x33333333;
	}


	return ret;
}

// @Ok
void *Mem_CoreNew(unsigned int a1)
{
	return Mem_NewTop(a1);
}

u32 dword_54D560;

// @Ok
// Does not match, no need to revisit
void *DCMem_New(unsigned int a1, int a2, int a3, void* a4, bool a5)
{
	int v5; // eax
	void* v6; // eax
	int v7; // edx
	void *result; // eax

	print_if_false(a4 == 0, "Bad Mem_new");
	if (a5)
		dword_54D560 = a5;
	v5 = a1 + 32;
	if ( v5 <= 4 )
		v5 = 8;
	v6 = Mem_CoreNew(v5);
	v7 = (int)v6 & 0x1F;
	result = (void*)((int)v6 + 32 - v7);
	*((char *)result - 1) = 32 - v7;
	return result;
}


// @Ok
// @Matching
SHandle Mem_MakeHandle(void* a1)
{
	SHandle tmp;
	tmp.pWhatever = 0;

	if (a1)
	{
		i32* v1 = (i32*)((char*)a1 - *((char*)a1 - 1));
		SBlockHeader* pBlock = reinterpret_cast<SBlockHeader*>(v1 - 8);
		u32 v2 = pBlock->UniqueIdentifier;
		i32* v3 = v1 - 8;

		if (v2 & 0x80000000)
		{
			print_if_false(0, "Tried to make handle out of a free block");
		}
		else
		{
			print_if_false(v2 != 0, "A unique identifier has not been assigned to the memory block");
			i32 v4 = pBlock->ParentHeap;

			if (v4 >= 0 && v4 <= 1)
			{
				if (pBlock->Size  >= 0x4 && pBlock->Size <= 0x200000)
				{
					SHandle result;
					result.Id = pBlock->UniqueIdentifier;
					result.pWhatever = a1;
					return result;
				}
				print_if_false(0, "Tried to make handle out of invalid pointer\n bad size");
			}
			else
			{
				print_if_false(0, "Tried to make handle out of invalid pointer\n bad heap");
			}
		}
	}

	return tmp;
}


// @Ok
// @Matching
void *Mem_RecoverPointer(SHandle *a1)
{
	void *result; // eax
	int v2; // edx

	if (a1->pWhatever)
	{
		v2 = *((char *)result - 1);
		u32 v3 = reinterpret_cast<u32>((char *)result - v2);
		if ( v2 > ' ' || (v3 & 3) ||
				(reinterpret_cast<SBlockHeader*>(v3)[-1].UniqueIdentifier) != a1->Id )
		{
			a1->pWhatever = 0;
			return 0;
		}
		
		return a1->pWhatever;
	}

	return 0;
}

void validate_SHandle(void){
	VALIDATE_SIZE(SHandle, 8);

	VALIDATE(SHandle, pWhatever, 0x0);
	VALIDATE(SHandle, Id, 0x4);
}

void validate_SBlockHeader(void){

	VALIDATE_SIZE(SBlockHeader, 0x20);

	/*
	VALIDATE(SBlockHeader, ParentHeap, 0x0);
	VALIDATE(SBlockHeader, Size, 0x0);
	*/
	VALIDATE(SBlockHeader, Next, 0x4);
	VALIDATE(SBlockHeader, UniqueIdentifier, 0x8);

	//VALIDATE(SBlockHeader, padding, 0xC);
}

#include "my_patch.h"

// @Bogus
void patch_mem(void)
{
	PATCH_PUSH_RET(0x00458050, Mem_ShrinkX);
	PATCH_PUSH_RET(0x004582A0, Mem_Shrink);

	PATCH_PUSH_RET(0x00458130, Mem_Copy);

	PATCH_PUSH_RET(0x00458210, Mem_Delete);
	PATCH_PUSH_RET(0x004582D0, Mem_AlignedDelete);

	PATCH_PUSH_RET(0x00457E00, Mem_Init);
}
