#include "mem.h"
#include <cstdlib>
#include <cstring>
#include "validate.h"

void* DCMem_New(size_t size, int unk1, int unk2, int unk3, int unk4) { 
	return NULL;
}

void* Mem_RecoverPointer(SHandle*){
	return NULL;
}

static SBlockHeader ** const Heaps = (SBlockHeader**)0x0060D118;

int dword_54D55C = 1;

// @OK
// @CM: Different register allocation
void AddToFreeList(SBlockHeader *pNewFreeBlock, int Heap)
{
	register SBlockHeader *pAfter = Heaps[Heap];
	register SBlockHeader *pBefore = NULL;

	while ( pAfter < pNewFreeBlock && pAfter )
	{
		pBefore = pAfter;
		pAfter = pAfter->Next;
	}


	if (pBefore)
	{
		if ((SBlockHeader *)((char*)(pBefore + 1) + (pBefore->ParentHeap >> 4)) == pNewFreeBlock)
		{
			if ( (SBlockHeader *)((char *)(pNewFreeBlock + 1) + (pNewFreeBlock->ParentHeap >> 4)) == pAfter )
			{
				pBefore->Next = pAfter->Next;
				pBefore->ParentHeap = (pAfter->ParentHeap + (pBefore->ParentHeap & 0xFFFFFFF0) + pNewFreeBlock->ParentHeap + 1024) ^ (pBefore->ParentHeap ^ (pAfter->ParentHeap + pNewFreeBlock->ParentHeap)) & 0xF;

				if ( dword_54D55C )
				{
					int size = ((pNewFreeBlock->ParentHeap >> 4) + 64) >> 2;
					if ( size > 0)
					{
						memset(pNewFreeBlock, 0x55u, 4 * size);
						return;
					}
				}
			}
			else
			{
				pBefore->ParentHeap = (pBefore->ParentHeap ^ pNewFreeBlock->ParentHeap) & 0xF ^ ((pBefore->ParentHeap & 0xFFFFFFF0) + pNewFreeBlock->ParentHeap + 512);
				if ( dword_54D55C )
				{
					int size = ((pNewFreeBlock->ParentHeap >> 4) + 32) >> 2;
					if ( size > 0 )
					{
						memset(pNewFreeBlock, 0x55, 4 * size);
						return;
					}
				}
			}

			return;
		}

		pBefore->Next = pNewFreeBlock;
	}
	else
	{
		Heaps[Heap] = pNewFreeBlock;
	}

	if ( dword_54D55C )
	{
		int size = pNewFreeBlock->ParentHeap >> 6;
		if ( size > 0 )
			memset((pNewFreeBlock+1), 0x55u, 4 * size);
	}

	unsigned int ParentHeap = pNewFreeBlock->ParentHeap;
	if ( (SBlockHeader *)((char *)(pNewFreeBlock + 1) + (pNewFreeBlock->ParentHeap >> 4)) == pAfter )
	{
		pNewFreeBlock->Next = pAfter->Next;
		pNewFreeBlock->ParentHeap = (ParentHeap ^ pAfter->ParentHeap) & 0xF ^ ((ParentHeap & 0xFFFFFFF0) + pAfter->ParentHeap + 0x200);

		if ( dword_54D55C )
		{
			memset(pAfter, 0x55u, sizeof(SBlockHeader));
			pNewFreeBlock->field_8 = 0;
			return;
		}
	}
	else
	{
		pNewFreeBlock->Next = pAfter;
	}

	pNewFreeBlock->field_8 = 0;

}

struct MemRelated {
	int HeapBottom;
	int HeapTop;
};

//Guessed the number
int gMemInitRelatedOne[32];

static MemRelated * const gMemInitRelatedBottom =  (MemRelated*)0x0060D214;
static int * const gMemInitRelatedTop =  (int*)0x0060D224;

unsigned int dword_60D228;
unsigned int dword_60D220;
unsigned int dword_60D21C;

// @Ok
// @Revisit, too many globals
// ebx is used for some reason to write 0
void Mem_Init(void)
{

	int Heap; // edi
	MemRelated *v1; // esi
	SBlockHeader *pAllFreeMem; // eax
	int v4; // ecx
	int HeapBottom; // edx

	printf_fancy("Heap sizes: ");
	Heap = 0;
	v1 = gMemInitRelatedBottom;
	do
	{

		print_if_false((unsigned int)(v1->HeapBottom + 32) < (unsigned int)v1->HeapTop, "Bad values for HEAPBOT and HEAPTOP");

		pAllFreeMem = (SBlockHeader *)v1->HeapBottom;
		v4 = v1->HeapTop;
		HeapBottom = v1->HeapBottom;
		Heaps[Heap] = 0;
		gMemInitRelatedOne[Heap] = 0;
		pAllFreeMem->ParentHeap = pAllFreeMem->ParentHeap & 0xF ^ (16
				* ((HeapBottom << 28) - (unsigned int)pAllFreeMem + v4 + 0xFFFFFE0));
		AddToFreeList(pAllFreeMem, Heap);

		printf_fancy("Heap %d: %ld bytes, ", Heap, v1->HeapTop - v1->HeapBottom);
		++v1;
		++Heap;
	}
	while ( (int)v1 < (int)gMemInitRelatedTop );
	printf_fancy("\n");
	dword_60D228 = (98 * dword_60D220 - 98 * dword_60D21C) / 0x64u;
}

unsigned int dword_60D208;

// @Ok
// @Revisit, different registers at begin
void Mem_Delete(void* a1)
{
	void *v1; // ecx
	char *v2; // esi
	unsigned int v3; // eax
	SBlockHeader *v4; // ecx
	int Heap; // esi

	v1 = (void *)*((char *)a1 - 1);
	v2 = (char *)((unsigned char *)a1 - (unsigned char *)v1);
	print_if_false(a1 != v1, "NULL pointer sent to Mem_Delete");
	v3 = *((unsigned int*)v2 - 8);
	v4 = (SBlockHeader *)(v2 - 32);
	Heap = (int)(v3 << 28) >> 28;
	if ( Heap < 0 || Heap >= 2 )
	{
		print_if_false(0, "Invalid pointer sent to Mem_Delete");
	}
	else
	{
		gMemInitRelatedOne[Heap] += -32 - (v3 >> 4);
		AddToFreeList(v4, Heap);
		if ( Heap == 1 )
			*gMemInitRelatedTop = dword_60D208 >= (unsigned int)dword_60D228;
	}
}

// @Ok
// not matching in one area, but logic same
void Mem_ShrinkX(void* a1, unsigned int newSize)
{
	unsigned int v2; // eax
	int v3; // esi
	unsigned int v5; // eax

	v2 = *((unsigned int *)a1 - 8);
	v3 = (int)(v2 << 28) >> 28;
	print_if_false(newSize <= v2 >> 4, "Illegal newsize %ld sent to Mem_Shrink", newSize);
	print_if_false((newSize & 3) == 0, "newsize %ld not lword aligned", newSize);

	print_if_false(v3 >= 0 && v3 < 2, "Corrupt block header, parent heap (%d) out of range", v3);

	v5 = *((unsigned int *)a1 - 8);
	if ( newSize < (v5 >> 4) - 32 )
	{
		v5 &= 0xFFFFFFF0;
		*(unsigned int *)((char *)a1 + newSize) = ~*(unsigned int *)((char *)a1 + newSize) & 0xF ^ (v5 - 16 * newSize - 497);
		gMemInitRelatedOne[v3] += newSize - (*((unsigned int *)a1 - 8) >> 4);
		*((unsigned int *)a1 - 8) = (16 * newSize) | *((unsigned int *)a1 - 8) & 0xF;
		AddToFreeList((SBlockHeader *)((char *)a1 + newSize), v3);
		if ( v3 == 1 )
			*gMemInitRelatedTop = dword_60D208 >= (unsigned int)dword_60D228;
	}
}

// @Ok
// Slightly different register allocation
void Mem_Copy(void* dst, void* src, int size)
{
	print_if_false(((int)dst & 3) == 0, "Not long-aligned");
	print_if_false(((int)src & 3) == 0, "Not long-aligned");

	int *dstF = reinterpret_cast<int*>(dst);
	int *srcF = reinterpret_cast<int*>(src);

	int numFours = size >> 2;
	int lastBytes = size & 3;
	if (numFours > 0)
	{
		while(numFours)
		{
			*dstF++ = *srcF++;
			numFours--;
		}
	}

	unsigned char *dstS = reinterpret_cast<unsigned char*>(dstF);
	unsigned char *srcS = reinterpret_cast<unsigned char*>(srcF);

	if (lastBytes > 0)
	{
		while(lastBytes)
		{
			*dstS = *srcS;
			dstS++;
			srcS++;
			lastBytes--;
		}
	}
}

void validate_SBlockHeader(void){

	VALIDATE_SIZE(SBlockHeader, 0x20);


	VALIDATE(SBlockHeader, ParentHeap, 0x0);
	VALIDATE(SBlockHeader, Next, 0x4);
	VALIDATE(SBlockHeader, field_8, 0x8);
}
