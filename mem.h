#pragma once

#include "export.h"

EXPORT extern u32 HeapDefs[2][2];
EXPORT extern i32 LowMemory;


struct SHandle
{
	void* field_0;
	i32 field_4;
};

struct SNewBlockHeader {

	i32 ParentHeap: 4;
	u32 Size: 28;
	SNewBlockHeader* Next;
	u32 UniqueIdentifier;
	unsigned char padding[0x20-0x8-4];
};

EXPORT void Mem_AlignedDelete(void *);
EXPORT void AddToFreeList(SNewBlockHeader *pNewFreeBlock, int Heap);
EXPORT void Mem_Init(void);
EXPORT void Mem_Delete(void*);
EXPORT void Mem_Shrink(void*, u32);
EXPORT void Mem_CoreShrink(void*, u32);
EXPORT void Mem_ShrinkX(void*, unsigned int);
EXPORT void Mem_Copy(void*, void*, int);
EXPORT void *Mem_NewTop(unsigned int);
EXPORT void *Mem_CoreNew(unsigned int);
EXPORT void *DCMem_New(unsigned int, int, int, void*, bool);
EXPORT SHandle Mem_MakeHandle(void*);

EXPORT void *Mem_RecoverPointer(SHandle*);

void validate_SBlockHeader(void);
void validate_SHandle(void);
