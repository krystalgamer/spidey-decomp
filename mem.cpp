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
static MemRelated * const gMemInitRelatedTop =  (MemRelated*)0x0060D224;

unsigned int dword_60D228;
unsigned int dword_60D220;
unsigned int dword_60D21C;

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

void validate_SBlockHeader(void){

	VALIDATE_SIZE(SBlockHeader, 0x20);


	VALIDATE(SBlockHeader, ParentHeap, 0x0);
	VALIDATE(SBlockHeader, Next, 0x4);
	VALIDATE(SBlockHeader, field_8, 0x8);
}
