#pragma once

#ifndef VRAM_H
#define VRAM_H

#include "export.h"

// @FIXME
#define tagSVRAMRect i32

EXPORT void VRAMRectPack(i32,i32,i32,i32 *,i32 *,i32,u8,u32);
EXPORT void VRAMRectUnpack(tagSVRAMRect *);

#endif
