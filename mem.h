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

	PADDING(0x20-0x8-4);
};

EXPORT void Mem_AlignedDelete(void *);
EXPORT void AddToFreeList(SNewBlockHeader *pNewFreeBlock, i32 Heap);
EXPORT void Mem_Init(void);
EXPORT void Mem_Delete(void*);
EXPORT void Mem_Shrink(void*, u32);
EXPORT void Mem_CoreShrink(void*, u32);
EXPORT void Mem_ShrinkX(void*, u32);
EXPORT void Mem_Copy(void*, void*, i32);
EXPORT void *Mem_NewTop(u32);
EXPORT void *Mem_CoreNew(u32);
EXPORT void *DCMem_New(u32, i32, i32, void*, bool);
EXPORT SHandle Mem_MakeHandle(void*);

EXPORT void *Mem_RecoverPointer(SHandle*);

void validate_SBlockHeader(void);
void validate_SHandle(void);
