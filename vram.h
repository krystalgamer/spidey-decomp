#pragma once

#ifndef VRAM_H
#define VRAM_H

#include "export.h"
#include "pack.h"

struct tagSVRAMRect
{
	u8 flags;
	u8 padAfter1[3];

	SPack *p_pack;
	void *p_poly;
	u8 update_type;

	u8 padAfter4[0x10-0xC-1];

	tagSVRAMRect *p_next;
};

EXPORT tagSVRAMRect* VRAMRectPack(i32,i32,i32,i32 *,i32 *,i32,u8,u32);
EXPORT void VRAMRectUnpack(tagSVRAMRect *);

void validate_tagSVRAMRect(void);

#endif
