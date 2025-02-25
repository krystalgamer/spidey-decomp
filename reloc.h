#pragma once

#ifndef RELOC_H
#define RELOC_H

#include "export.h"

typedef void (*relocFunc)(void);

struct reloc_mod
{
	relocFunc field_0;
	u8 padAfter0[4];

	u32 mCRC;
	u32 field_C[8];
	reloc_mod *pNext;
	reloc_mod *pPrev;
};

struct SRelocEntry
{
	char Name[16];
	void (*Func)(reloc_mod*);
};


EXPORT void Reloc_Unload(char*);
EXPORT void Reloc_Unload(u32);
EXPORT void Reloc_CallUserFunction(const char*, u32, const u32*, u32*);
EXPORT void NullFunc(void);
EXPORT void Reloc_Load(char *,i32);
EXPORT void Reloc_UnloadAll(void);


void validate_reloc_mod(void);
void validate_SReloc(void);
void validate_SRelocEntry(void);

#endif
