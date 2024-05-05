#pragma once

#include "export.h"


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
EXPORT int Mem_MakeHandle(void*);

struct SHandle
{
	int field_0;
};

EXPORT void *Mem_RecoverPointer(SHandle*);

void validate_SBlockHeader(void);
void validate_SHandle(void);
