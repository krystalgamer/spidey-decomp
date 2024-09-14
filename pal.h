#pragma once

#ifndef PAL_H
#define PAL_H

#include "export.h"

struct tag_S_Pal
{
};

EXPORT void Free16Slot(u16);
EXPORT i32 GetFree16Slot(void);
EXPORT void GetFree256Slot(void);
EXPORT void NewPaletteEntry(u32);
EXPORT void Pal_FindPaletteEntry(u32);
EXPORT void Pal_Init(void);
EXPORT void Pal_LoadPalette(u32,u32 *,u8);
EXPORT void Pal_ProcessPalette(u16 *,i32);
EXPORT void Pal_RemoveUnusedPalettes(void);
EXPORT void RemovePaletteEntry(tag_S_Pal *);

void validate_tag_S_Pal(void);
#endif
