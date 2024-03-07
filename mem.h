#pragma once

#include "export.h"

struct SHandle{};

EXPORT void* DCMem_New(size_t size, int unk1, int unk2, int unk3, int unk4); 
EXPORT void* Mem_RecoverPointer(SHandle*);