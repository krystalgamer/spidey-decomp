#include "mem.h"
#include <cstdlib>
#include <cstring>
#include "validate.h"


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

unsigned int dword_60D11C;
unsigned int UniqueIdentifier;
// @NotOk
// Revisit
void *Mem_NewTop(unsigned int a1)
{
	unsigned int v1; // esi
	unsigned int *v2; // eax
	unsigned int *v3; // edx
	unsigned int *v4; // edi
	unsigned int *v5; // ecx
	unsigned int v6; // eax
	unsigned int *v8; // ecx
	unsigned int v9; // eax
	void *v10; // edx
	unsigned int v11; // eax

	UniqueIdentifier = (UniqueIdentifier + 1) & 0x7FFFFFFF;
	if ( !UniqueIdentifier )
		UniqueIdentifier = 1;
	v1 = (a1 + 3) & 0xFFFFFFFC;

	print_if_false(v1 != 0, "Zero size sent to Mem_New");
	print_if_false(v1 < 0xFFFFFFF, "size exceeds 28 bit range");

	v2 = (unsigned int *)dword_60D11C;
	v3 = 0;
	v4 = 0;
	v5 = (unsigned int *)dword_60D11C;
	if ( dword_60D11C )
	{
		do
		{
			if ( *v2 >> 4 >= v1 )
			{
				v5 = v2;
				v4 = v3;
			}
			v3 = v2;
			v2 = (unsigned int *)v2[1];
		}
		while ( v2 );
	}

	v6 = *v5 >> 4;
	if ( v6 < v1 )
		return 0;
	if ( v6 > v1 + 32 )
	{


		*v5 = *v5 & 0xF ^ (16 * (0xFFFFFFF * v1 + v6 + 0xFFFFFE0));
		v8 = (unsigned int *)((char *)v5 + v6 - v1);
		v9 = (16 * v1) | *v8 & 0xF;
		*v8 = v9;

		v9 &= 0xFFFFFFF0;
		v8[2] = UniqueIdentifier;
		v9 ^= 1u;
		*v8 = v9;
		v10 = v8 + 8;
		dword_60D208 += (v9 >> 4) + 32;
		*gMemInitRelatedTop = dword_60D208 >= (unsigned int)dword_60D228;
		if ( v1 >> 2 )
		{
			memset(v10, 0x33u, 4 * (v1 >> 2));
			return v8 + 8;
		}

	}
	else
	{
		if ( v4 )
			v4[1] = v5[1];
		else
			dword_60D11C = v5[1];
		v11 = *v5;

		v11 |= (unsigned char)(*v5 & 0xF0);
		v5[2] = UniqueIdentifier;
		v11 ^= 1u;
		*v5 = v11;
		v10 = v5 + 8;
		dword_60D208 += (v11 >> 4) + 32;
		*gMemInitRelatedTop = dword_60D208 >= (unsigned int)dword_60D228;
		if ( v1 >> 2 )
			memset(v10, 0x33u, 4 * (v1 >> 2));
	}
	return v10;
}

// @Ok
void *Mem_CoreNew(unsigned int a1)
{
	return Mem_NewTop(a1);
}

bool dword_54D560;
// @Ok
// Does not match, no need to revisit
void *DCMem_New(unsigned int a1, int a2, int a3, void* a4, bool a5)
{
	int v5; // eax
	void* v6; // eax
	int v7; // edx
	void *result; // eax

	print_if_false(a4 == 0, "Bad Mem_new");
	if ( a5 )
		dword_54D560 = a5;
	v5 = a1 + 32;
	if ( a1 + 32 <= 4 )
	v5 = 8;
	v6 = Mem_CoreNew(v5);
	v7 = (int)v6 & 0x1F;
	result = (void*)((int)v6 + 32 - v7);
	*((char *)result - 1) = 32 - v7;
	return result;
}


// @NotOk
// slightly different due to many jumps to same printf_if_false, no biggie
// completly wrong
SHandle Mem_MakeHandle(void* a1)
{
	/*
	char *v1; // esi
	int v2; // eax
	char *v3; // esi
	int v4; // eax
	unsigned int v5; // ecx

	if ( a1 )
	{
		v1 = (char *)a1 - *((char *)a1 - 1);
		v2 = *((unsigned int *)v1 - 6);
		v3 = v1 - 32;
		if ( v2 & 0x80000000 )
		{
			print_if_false(0, "Tried to make handle out of a free block");
		}
		else
		{
			print_if_false(v2 != 0, "A unique identifier has not been assigned to the memory block");
			v4 = (int)(*(unsigned int *)v3 << 28) >> 28;
			if ( v4 < 0 || v4 > 1 )
			{
				print_if_false(0, "Tried to make handle out of invalid pointer\n bad heap");
				}
			else
			{
				v5 = *(unsigned int *)v3 & 0xFFFFFFF0;
				if ( v5 >= 0x40 && v5 <= (unsigned int)0x2000000 )
					return reinterpret_cast<int>(a1);
				print_if_false(0, "Tried to make handle out of invalid pointer\n bad size");
			}
		}
	}
	return 0;
	*/

	SHandle tmp;
	return tmp;
}


// @Ok
// Small difference where if a1->field_0 is 0 it jumps to xor eax, eax, which is
// not needed :D
void *Mem_RecoverPointer(SHandle *a1)
{
	void *result; // eax
	int v2; // edx
	char *v3; // ecx

	result = (void *)a1->field_0;
	if ( a1->field_0 )
	{

		v2 = *((char *)result - 1);
		v3 = (char *)result - v2;
		if ( v2 > ' ' ||
				((unsigned __int8)v3 & ~0xFFFFFFFC) != 0 ||
				*((unsigned int *)v3 - 6) != (unsigned int)a1[1].field_0 )
		{
			a1->field_0 = 0;
			return 0;
		}

	}

	return (void*)a1->field_0;

}

void validate_SHandle(void){
	VALIDATE_SIZE(SHandle, 8);

	VALIDATE(SHandle, field_0, 0x0);
	VALIDATE(SHandle, field_4, 0x4);
}

void validate_SBlockHeader(void){

	VALIDATE_SIZE(SBlockHeader, 0x20);


	VALIDATE(SBlockHeader, ParentHeap, 0x0);
	VALIDATE(SBlockHeader, Next, 0x4);
	VALIDATE(SBlockHeader, field_8, 0x8);
}
