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

void validate_SBlockHeader(void);
