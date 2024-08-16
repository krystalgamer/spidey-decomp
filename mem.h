#pragma once

#include "export.h"


struct SHandle
{
	i32 field_0;
	i32 field_4;
};

struct SBlockHeader {

	unsigned int ParentHeap;
	SBlockHeader* Next;
	int field_8;
	unsigned char padding[0x20-0x8-4];

};

EXPORT void AddToFreeList(SBlockHeader *pNewFreeBlock, int Heap);
EXPORT void Mem_Init(void);
EXPORT void Mem_Delete(void*);
EXPORT void Mem_ShrinkX(void*, unsigned int);
EXPORT void Mem_Copy(void*, void*, int);
EXPORT void *Mem_NewTop(unsigned int);
EXPORT void *Mem_CoreNew(unsigned int);
EXPORT void *DCMem_New(unsigned int, int, int, void*, bool);
EXPORT SHandle Mem_MakeHandle(void*);

EXPORT void *Mem_RecoverPointer(SHandle*);

EXPORT extern i32 gMemInitRelatedTop;

void validate_SBlockHeader(void);
void validate_SHandle(void);
