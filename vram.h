#pragma once

#ifndef VRAM_H
#define VRAM_H

#include "export.h"
#include "pack.h"

struct tagSVRAMRect
{
	u8 padtop[4];

	SPack *p_pack;
	u8 padAfter4[0x10-0x8];

	tagSVRAMRect *p_next;
};

EXPORT void VRAMRectPack(i32,i32,i32,i32 *,i32 *,i32,u8,u32);
EXPORT void VRAMRectUnpack(tagSVRAMRect *);

void validate_tagSVRAMRect(void);

#endif
