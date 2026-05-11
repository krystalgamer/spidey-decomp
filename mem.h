#pragma once

#ifndef MEM_H
#define MEM_H

#include "export.h"

EXPORT extern u32 HeapDefs[2][2];
EXPORT extern i32 LowMemory;


struct SHandle
{
	void* pWhatever;
	u32 Id;
};

struct SBlockHeader {

	i32 ParentHeap: 4;
	size_t Size: 28;
	SBlockHeader* Next;
	u32 UniqueIdentifier;

	PADDING(0x20-0x8-4);
};

EXPORT void Mem_AlignedDelete(void *);
EXPORT void AddToFreeList(SBlockHeader *pNewFreeBlock, i32 Heap);
EXPORT void Mem_Init(void);
EXPORT void Mem_Delete(void*);
EXPORT void Mem_Shrink(void*, size_t);
EXPORT void Mem_CoreShrink(void*, size_t);
EXPORT void Mem_ShrinkX(void*, size_t);
EXPORT void Mem_Copy(void*, void*, i32);
EXPORT void *Mem_NewTop(u32);
EXPORT void *Mem_CoreNew(u32);
EXPORT void *DCMem_New(u32, i32, i32, void*, bool);
EXPORT SHandle Mem_MakeHandle(void*);

EXPORT void *Mem_RecoverPointer(SHandle*);

void validate_SBlockHeader(void);
void validate_SHandle(void);

#define BIGHEAP 1
#define MAXHEAPS 2
#define GETBLOCKHEADER(p) (((SBlockHeader *)(p))-1)

#endif
