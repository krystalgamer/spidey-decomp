#pragma once

#include "export.h"

struct SHandle{};

EXPORT void* DCMem_New(size_t size, int unk1, int unk2, int unk3, int unk4); 
EXPORT void* Mem_RecoverPointer(SHandle*);


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

void validate_SBlockHeader(void);
