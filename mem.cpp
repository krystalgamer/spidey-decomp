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

static i32 Scribble = 1;

// Returns a pointer to the first byte after free block p
// p is a pointer to a block header, not a pointer returned by Mem_New
#define FREEAFTER(p) (SBlockHeader*)(((char*)((p)+1))+(p)->Size)

// Proper definition is diff between debug def of SBlockHeader and SDebugBlockHeader
#define MEMDIFF 32

#define BIGHEAPOVERLOAD 98   // 2% left give about 20K
#define PRINTHEAPSIZES 1

#define ClearMem(p,n)                                 \
         {                                            \
            u32* pMem=(u32*)(p);                \
            for (i32 ii=0; ii<(n)/4; ++ii) *pMem++=0x33333333; \
         }

// @Note: yes, there's a typo
static u32 UniqueIndentifier = 0;

// @Ok
// @Leak
// @Matching
void Mem_AlignedDelete(void *p)
{
	Mem_Delete(p);
}

// @Ok
// @Matching
// @Leak
void AddToFreeList(SBlockHeader *pNewFreeBlock, i32 Heap)
{
	register SBlockHeader *pAfter=FirstFreeBlock[Heap];
	register SBlockHeader *pBefore=NULL;

	i32	OriginalSize = pNewFreeBlock->Size;

	// Find the blocks either side of pNewFreeBlock
	while ((u32)pAfter<(u32)pNewFreeBlock && pAfter)
	{
		pBefore=pAfter;
		pAfter=pAfter->Next;
	}
	// Either of pBefore or pAfter could now be NULL

	if (pBefore)
	{
		if (FREEAFTER(pBefore)==pNewFreeBlock)
		{
			if (FREEAFTER(pNewFreeBlock)==pAfter)
			{
				// pNewFreeBlock is adjacent to pBefore and pAfter, so merge pNewFreeBlock
				// and pAfter into pBefore
				pBefore->Next=pAfter->Next;
				pBefore->Size+=pNewFreeBlock->Size+pAfter->Size+2*sizeof(SBlockHeader);

				// Scribble over the new free block and the headers on either side
				// of it. We don't need to scribble over the other two free blocks
				// because they will have already been scribbled over.

				if (Scribble)
				{
					u32* pFree=(u32*)pNewFreeBlock;
					i32 NumLWords=(pNewFreeBlock->Size+2*sizeof(SBlockHeader))/4;
					for (i32 i=0; i<NumLWords; ++i) *pFree++=SCRIBBLE;
				}
			}
			else
			{
				// pNewFreeBlock is adjacent to pBefore, so merge it into pBefore by
				// just increasing the size of pBefore
				pBefore->Size+=pNewFreeBlock->Size+sizeof(SBlockHeader);

				// Scribble over the new free block just merged, and its header

				if (Scribble)
				{
					u32* pFree=(u32*)pNewFreeBlock;
					i32 NumLWords=(pNewFreeBlock->Size+sizeof(SBlockHeader))/4;
					for (i32 i=0; i<NumLWords; ++i) *pFree++=SCRIBBLE;
				}
			}

			return; // That's that
		}
		else
		{
			// pNewFreeBlock isn't adjacent to pBefore, so insert it into the linked
			// list after pBefore. pNewFreeBlock->Next isn't set yet though cos we still
			// need to check if it is adjacent to pAfter
			pBefore->Next=pNewFreeBlock;
		}
	}
	else
	{
		// There is no pBefore, so insert pNewFreeBlock into the linked list by setting
		// FirstFreeBlock equal to it. pNewFreeBlock->Next isn't set yet though cos we still
		// need to check if it is adjacent to pAfter
		FirstFreeBlock[Heap] = pNewFreeBlock;
	}

	// Scribble over the memory contained in the new free block
	// but only the original size
	if (Scribble)
	{
		u32* pFree=(u32*)(pNewFreeBlock+1);
		i32 NumLWords=pNewFreeBlock->Size/4;
		for (i32 i=0; i<NumLWords; ++i) *pFree++=SCRIBBLE;
	}

	// Note: pAfter could be NULL, but this bit will still work if it is
	if (FREEAFTER(pNewFreeBlock)==pAfter)
	{
		// pNewFreeBlock is adjacent to pAfter, so merge pAfter with pNewFreeBlock by
		// making pNewFreeBlock->Next jump over pAfter, then increase the size 
		// of pNewFreeBlock to absorb pAfter
		pNewFreeBlock->Next=pAfter->Next;
		pNewFreeBlock->Size+=pAfter->Size+sizeof(SBlockHeader);

		// Scribble over pAfter's header, since it has become part of the
		// free block

		if (Scribble)
		{
			u32* pFree=(u32*)pAfter;
			i32 NumLWords=sizeof(SBlockHeader)/4;
			for (i32 i=0; i<NumLWords; ++i) *pFree++=SCRIBBLE;
		}
	}
	else
	{
		// pNewFreeBlock is not adjacent to pAfter, so just set pNewFreeBlock->Next to
		// point to pAfter
		pNewFreeBlock->Next = pAfter;
	}

	pNewFreeBlock->Id = 0;
}

// @Ok
// @Leak
// @Matching
void Mem_Init(void)
{
	// @FIXME: remove this when Init_AtStart is done
	{
		const u32 *real = (u32*)0x0060D214;

		HeapDefs[0][0] = real[0];
		HeapDefs[0][1] = real[1];
		HeapDefs[1][0] = real[2];
		HeapDefs[1][1] = real[3];
	}

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

	// @FIXME: remove me later
	*reinterpret_cast<u32*>(0x0060D228) = CriticalBigHeapUsage;
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

// @Ok
// @Matching
// @Leak
void *Mem_NewTop(size_t size)
{
	i32 Heap = 1;
	UniqueIndentifier=(UniqueIndentifier+1)&0x7fffffff;
	if ( !UniqueIndentifier )
		UniqueIndentifier = 1;

	size=(size+3)&0xfffffffc;

	print_if_false(size != 0, "Zero size sent to Mem_New");
	print_if_false(size < 0xFFFFFFF, "size exceeds 28 bit range");

	// Search for a big enough free block (this is the slow bit)
	register SBlockHeader* pBlock=FirstFreeBlock[Heap];
	register SBlockHeader* pLast=NULL;
	register SBlockHeader* pChoice = pBlock;
	register SBlockHeader* pChoiceLast = NULL;

	// pChoice is the suitable block last in the heap 
	// pChoiceLast is the one before pChoice
	while (pBlock)
	{
		if (pBlock->Size >= size)
			{ 
			pChoice = pBlock;
			pChoiceLast = pLast;
		}

		pLast=pBlock;
		pBlock=pBlock->Next;
#if DEBUG & COUNTSEARCHS
		++search;
#endif
	}
	pBlock = pChoice;
	pLast = pChoiceLast;

	// if the found block is too small, error
	if (pBlock->Size<size)
	{
		return NULL;
	}

	if (pBlock->Size>size+sizeof(SBlockHeader))
	{
		// The found block is sufficiently big to make a new free block
		// out of the leftover space
		// Sufficiently big=more than enough space for the block header
		// pBlock->Size doesn't include space that is taken up by header

		// new block starts at current block ptr + current block header size + requested space size
		i32 old_size = pBlock->Size;

		SBlockHeader* pLeftOver = pBlock;
		pLeftOver->Size = old_size - size - sizeof(SBlockHeader);

		pBlock = (SBlockHeader*) ((char *)(pLeftOver+1) + old_size - size - sizeof(SBlockHeader));
		pBlock->Size = size;

		// pBlock is now hanging in space

		// set up info
		pBlock->Id=UniqueIndentifier;	
		pBlock->ParentHeap=Heap;

		Used[Heap]+=sizeof(SBlockHeader)+pBlock->Size;

		// Check if the LowMemory indicator needs to come on.
		if (Heap==BIGHEAP)
		{
			if (Used[Heap]>=CriticalBigHeapUsage)
				LowMemory=TRUE;
			else	
				LowMemory=FALSE;
		}


		ClearMem(pBlock+1,size);

		// Return the newly allocated block
#if RECORDEVERYTHING
		Mem_Record(pBlock, ReturnAddress);
#endif
#if DEBUG&&BITFIELD
		FlagLocationUsed((Uint32)(pBlock+1));
#endif
		return (void*)(pBlock+1);
	}
	// if there is enough room for the requested amount of space in pBlock,
	// but not enough left over to form a new free block
	else
	{
		// Remove pBlock from the linked list and make it into a used block
		if (pLast)
			pLast->Next=pBlock->Next;
		else
			FirstFreeBlock[Heap]=pBlock->Next;

		pBlock->Id=UniqueIndentifier;	
		pBlock->ParentHeap=Heap;

		// pBlock->Size is not changed, because we've had to allocate
		// the whole block.

		Used[Heap]+=sizeof(SBlockHeader)+pBlock->Size;

		// Check if the LowMemory indicator needs to come on.
		if (Heap==BIGHEAP)
		{
		if (Used[Heap]>=CriticalBigHeapUsage)
			LowMemory=TRUE;
		else	
			LowMemory=FALSE;
		}

		// Return the newly allocated block
		ClearMem(pBlock+1,size);

#if RECORDEVERYTHING
		Mem_Record(pBlock, ReturnAddress);
#endif
#if DEBUG&&BITFIELD
		FlagLocationUsed((Uint32)(pBlock+1));
#endif
		return (void*)(pBlock+1);
	}

}

// @Ok
// @Matching
// @NoLeak
void *Mem_NewX(u32 a1, i32 a2, i32 a3, void* a4)
{
	return Mem_NewTop(a1);
}

// @Ok
// @Matching
// @NoLeak
void *Mem_CoreNew(u32 a1, i32 a2, i32 a3, void* a4)
{
	if (a1 <= 4)
		a1 = 8;

	if (!a4)
		a4 = NULL;

	void *res = Mem_NewX(a1, a2, a3, a4);
	if (!res)
		return NULL;

	return res;
}

// @Ok - meh
u32 dword_54D560 = 0x3039;

// @Ok
// @AlmostMatching - maybe missing some inline shit
// @NoLeak
void *DCMem_New(u32 a1, i32 a2, i32 a3, void* a4, bool a5)
{
	print_if_false(a4 == 0, "Bad Mem_new");
	if (a5)
		dword_54D560 = a5;

	void *v8 = Mem_CoreNew(a1 + sizeof(SBlockHeader), a2, a3, 0);

	i32 v9 = sizeof(SBlockHeader) - ((u32)v8 & 0x1F);

	void* result = reinterpret_cast<void*>(v9 + reinterpret_cast<i32>(v8));

	*(reinterpret_cast<i8*>(result) - 1) = v9;

	return result;
}


// @Ok
// @Matching
// @NoLeak
SHandle Mem_MakeHandle(void* a1)
{
	SHandle tmp;
	tmp.pWhatever = 0;

	if (a1)
	{
		i32* v1 = (i32*)((char*)a1 - *((char*)a1 - 1));
		SBlockHeader* pBlock = reinterpret_cast<SBlockHeader*>(v1 - 8);
		u32 v2 = pBlock->Id;
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
					result.Id = pBlock->Id;
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
// @NoLeak
void *Mem_RecoverPointer(SHandle *a1)
{
	if (a1->pWhatever)
	{
		i32 v2 = *((char *)a1->pWhatever - 1);
		u32 v3 = reinterpret_cast<u32>((char *)a1->pWhatever - v2);
		if ( v2 > ' ' || (v3 & 3) ||
				(reinterpret_cast<SBlockHeader*>(v3)[-1].Id) != a1->Id )
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
	VALIDATE(SBlockHeader, Id, 0x8);

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
	PATCH_PUSH_RET(0x00457C90, AddToFreeList);
	PATCH_PUSH_RET(0x00457EE0, Mem_NewTop);

	PATCH_PUSH_RET(0x00457ED0, Mem_NewX);
	PATCH_PUSH_RET(0x004581A0, DCMem_New);

	PATCH_PUSH_RET(0x004583F0, Mem_RecoverPointer);
	PATCH_PUSH_RET(0x00458360, Mem_MakeHandle);
}
