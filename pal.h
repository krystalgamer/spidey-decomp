#pragma once

#ifndef PAL_H
#define PAL_H

#include "export.h"

struct tag_S_Pal
{
	u16 Clut;
	u8 slot;
	u8 flags;
	u16 Usage;
	u8 InVRAM;

	PADDING(1);

	u32 Checksum;
	tag_S_Pal* pNext;

	PADDING(0x18-0xC-4);
};

EXPORT void Free16Slot(u16);
EXPORT i32 GetFree16Slot(void);
EXPORT i32 GetFree256Slot(void);
EXPORT tag_S_Pal* NewPaletteEntry(u32);
EXPORT tag_S_Pal* Pal_FindPaletteEntry(u32);
EXPORT void Pal_Init(void);
EXPORT tag_S_Pal* Pal_LoadPalette(u32,u32 *,u8);
EXPORT void Pal_ProcessPalette(u16 *,i32);
EXPORT void Pal_RemoveUnusedPalettes(void);
EXPORT void RemovePaletteEntry(tag_S_Pal *);

void validate_tag_S_Pal(void);
#endif
