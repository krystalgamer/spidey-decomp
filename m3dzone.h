#pragma once

#ifndef M3DZONE_H
#define M3DZONE_H

#include "export.h"
#include "m3dcolij.h"

struct SZone
{
	// offset: 0000
	u32 Flags;
	// offset: 0004
	i32 xMin;
	// offset: 0008
	i32 zMin;
	// offset: 000C
	i32 xMax;
	// offset: 0010
	i32 zMax;
	// offset: 0014
	i32 ZoneWidth;
	// offset: 0018
	i32 ZoneHeight;
	// offset: 001C
	i16 Width;
	// offset: 001E
	i16 Height;
	// offset: 0020 (1600 bytes)
	u32 Ptr[20][20];
};

EXPORT void M3dZone_LineToItem(SLineInfo *, i32);
EXPORT void M3dZone_FreePSX(i32);
EXPORT void M3dZone_Init(void);
EXPORT void M3dZone_SetZone(i32,u32 *);

void validate_SZone(void);

#endif
