#include "mem.h"
#include <cstdlib>
#include <cstring>
#include "validate.h"


EXPORT i32 Used[2];
u32 HeapDefs[2][2];
i32 LowMemory;
EXPORT u32 CriticalBigHeapUsage;
EXPORT SBlockHeader *FirstFreeBlock[2];

int dword_54D55C = 1;

// @OK
// @CM: Different register allocation
void AddToFreeList(SBlockHeader *pNewFreeBlock, int Heap)
{
	register SBlockHeader *pAfter = FirstFreeBlock[Heap];
	register SBlockHeader *pBefore = NULL;

	while ( pAfter < pNewFreeBlock && pAfter )
	{
		pBefore = pAfter;
		pAfter = pAfter->field_4;
	}


	if (pBefore)
	{
		if ((SBlockHeader *)((char*)(pBefore + 1) + (pBefore->Next >> 4)) == pNewFreeBlock)
		{
			if ( (SBlockHeader *)((char *)(pNewFreeBlock + 1) + (pNewFreeBlock->Next >> 4)) == pAfter )
			{
				pBefore->field_4 = pAfter->field_4;
				pBefore->Next = (pAfter->Next + (pBefore->Next & 0xFFFFFFF0) + pNewFreeBlock->Next + 1024) ^ (pBefore->Next ^ (pAfter->Next + pNewFreeBlock->Next)) & 0xF;

				if ( dword_54D55C )
				{
					i32 size = ((pNewFreeBlock->Next >> 4) + 64) >> 2;
					if ( size > 0)
					{
						memset(pNewFreeBlock, 0x55u, 4 * size);
						return;
					}
				}
			}
			else
			{
				pBefore->Next = (pBefore->Next ^ pNewFreeBlock->Next) & 0xF ^ ((pBefore->Next & 0xFFFFFFF0) + pNewFreeBlock->Next + 512);
				if ( dword_54D55C )
				{
					int size = ((pNewFreeBlock->Next >> 4) + 32) >> 2;
					if ( size > 0 )
					{
						memset(pNewFreeBlock, 0x55, 4 * size);
						return;
					}
				}
			}

			return;
		}

		pBefore->field_4 = pNewFreeBlock;
	}
	else
	{
		FirstFreeBlock[Heap] = pNewFreeBlock;
	}

	if ( dword_54D55C )
	{
		int size = pNewFreeBlock->Next >> 6;
		if ( size > 0 )
			memset((pNewFreeBlock+1), 0x55u, 4 * size);
	}

	unsigned int Next = pNewFreeBlock->Next;
	if ( (SBlockHeader *)((char *)(pNewFreeBlock + 1) + (pNewFreeBlock->Next >> 4)) == pAfter )
	{
		pNewFreeBlock->field_4 = pAfter->field_4;
		pNewFreeBlock->Next = (Next ^ pAfter->Next) & 0xF ^ ((Next & 0xFFFFFFF0) + pAfter->Next + 0x200);

		if ( dword_54D55C )
		{
			memset(pAfter, 0x55u, sizeof(SBlockHeader));
			pNewFreeBlock->field_8 = 0;
			return;
		}
	}
	else
	{
		pNewFreeBlock->field_4 = pAfter;
	}

	pNewFreeBlock->field_8 = 0;

}

EXPORT void Mem_Secret(SNewBlockHeader *p, i32 x)
{
	p->ParentHeap = x;
}

// @Ok
// @Matching
void Mem_Init(void)
{
	printf_fancy("Heap sizes: ");

	for (
			i32 Heap = 0;
			Heap < 2;
			Heap++)
	{
		print_if_false(HeapDefs[Heap][0] + 32 < HeapDefs[Heap][1], "Bad values for HEAPBOT and HEAPTOP");

		SNewBlockHeader* pNewFreeBlock = reinterpret_cast<SNewBlockHeader*>(HeapDefs[Heap][0]);

		i32 v4 = HeapDefs[Heap][1];
		i32 HeapBottom = HeapDefs[Heap][0];

		FirstFreeBlock[Heap] = 0;
		Used[Heap] = 0;

		pNewFreeBlock->Size = ((v4 - HeapBottom - 32));

		AddToFreeList(reinterpret_cast<SBlockHeader*>(pNewFreeBlock), Heap);
		printf_fancy("Heap %d: %ld bytes, ", Heap, HeapDefs[Heap][1] - HeapDefs[Heap][0]);
	}

	printf_fancy("\n");
	CriticalBigHeapUsage = (0x62 * (HeapDefs[1][1] - HeapDefs[1][0])) / 0x64;
}

unsigned int dword_60D208;

// @Ok
// @Matching
INLINE void Mem_DeleteX(void *p)
{
	print_if_false(p != 0, "NULL pointer sent to Mem_Delete");

	SNewBlockHeader* v4 = (SNewBlockHeader*)(reinterpret_cast<i32>(p) - 32);
	i32 Heap = v4->ParentHeap;

	if (Heap < 0 || Heap >= 2)
	{
		print_if_false(0, "Invalid pointer sent to Mem_Delete");
	}
	else
	{
		i32 newUsed = 32 + v4->Size;
		Used[Heap] -= newUsed;
		AddToFreeList(
				reinterpret_cast<SBlockHeader*>(v4),
				Heap);

		if (Heap == 1)
			LowMemory = Used[1] >= CriticalBigHeapUsage;
	}
}

// @Ok
// @Matching
INLINE void Mem_CoreDelete(void* a1)
{
	Mem_DeleteX(a1);
}

// @Ok
// @Matching
void Mem_Delete(void* a1)
{
	Mem_CoreDelete((char *)a1 - *((char *)a1 - 1));
}

// @Ok
// not matching inside the if on the Used assignement but that's fine
void Mem_ShrinkX(void* a1, u32 newSize)
{
	u32 v2; // eax
	i32 v3; // esi
	u32 v5; // eax

	v2 = *((u32 *)a1 - 8);
	v3 = (i32)(v2 << 28) >> 28;
	print_if_false(newSize <= v2 >> 4, "Illegal newsize %ld sent to Mem_Shrink", newSize);
	print_if_false((newSize & 3) == 0, "newsize %ld not lword aligned", newSize);

	print_if_false(v3 >= 0 && v3 < 2, "Corrupt block header, parent heap (%d) out of range", v3);

	v5 = *((u32 *)a1 - 8);
	if ( newSize < (v5 >> 4) - 32 )
	{
		v5 &= 0xFFFFFFF0;
		*(u32*)((char *)a1 + newSize) = ~*(u32*)((char *)a1 + newSize) & 0xF ^ (v5 - 16 * newSize - 497);
		Used[v3] += newSize - (*((u32*)a1 - 8) >> 4);
		*((u32*)a1 - 8) = (16 * newSize) | *((u32*)a1 - 8) & 0xF;
		AddToFreeList((SBlockHeader *)((char *)a1 + newSize), v3);
		if ( v3 == 1 )
			LowMemory = Used[1] >= CriticalBigHeapUsage;
	}
}

// @Ok
INLINE void Mem_CoreShrink(void* a1, u32 a2)
{
	if ( a2 <= 4 )
		a2 = 8;
	Mem_ShrinkX(a1, a2);
}

// @Ok
void Mem_Shrink(void* a1, u32 a2)
{
	Mem_CoreShrink(
			reinterpret_cast<char*>(a1) - *(reinterpret_cast<char *>(a1) - 1),
			a2 + 32);
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
// seems ok tbh
void *Mem_NewTop(unsigned int a1)
{
	/*
	unsigned int v1; // esi
	SBlockHeader *v2; // eax
	SBlockHeader *v3; // edx
	SBlockHeader *v4; // edi
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

	v2 = FirstFreeBlock[1];
	v3 = 0;
	v4 = 0;
	for ( i = FirstFreeBlock[1]; v2; v2 = v2->Next )
	{
		if ( v2->ParentHeap >> 4 >= v1 )
		{
			i = v2;
			v4 = v3;
		}
			v3 = v2;
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
		Used[1] += (v9 >> 4) + 32;
		LowMemory = Used[1] >= CriticalBigHeapUsage;
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
		LowMemory = Used[1] >= CriticalBigHeapUsage;
		if ( v1 >> 2 )
			memset(v10, 0x33u, 4 * (v1 >> 2));
	}
	return v10;
	*/
	return 0;
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


// @Ok
// v3 is not assigned early for some reason
SHandle Mem_MakeHandle(void* a1)
{
	if (a1)
	{
		i32* v1 = (i32*)((char*)a1 - *((char*)a1 - 1));
		i32 v2 = *(v1 - 6);
		i32* v3 = v1 - 8;

		if (v2 & 0x80000000)
		{
			print_if_false(0, "Tried to make handle out of a free block");
		}
		else
		{
			print_if_false(v2 != 0, "A unique identifier has not been assigned to the memory block");
			i32 v4 = *v3 << 28 >> 28;

			if (v4 >= 0 && v4 <= 1)
			{
				u32 v5 = *v3 & 0xFFFFFFF0;
				if ( v5 >= 0x40 && v5 <= 0x2000000 )
				{
					SHandle result;
					result.field_4 = v3[2];
					result.field_0 = reinterpret_cast<i32>(a1);
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

	SHandle tmp;
	tmp.field_0 = 0;
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


	VALIDATE(SBlockHeader, Next, 0x0);
	VALIDATE(SBlockHeader, field_4, 0x4);
	VALIDATE(SBlockHeader, field_8, 0x8);

	VALIDATE_SIZE(SNewBlockHeader, 0x8);
	/*
	VALIDATE(SNewBlockHeader, ParentHeap, 0x0);
	VALIDATE(SNewBlockHeader, Size, 0x0);
	*/
	VALIDATE(SNewBlockHeader, Next, 0x4);
}
