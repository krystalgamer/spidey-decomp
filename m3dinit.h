#ifndef M3DINIT_H
#define M3DINIT_H

#pragma once

#include "export.h"

EXPORT extern u32 M3d_FadeColour;

union ItemOffsetUnion
{
	unsigned Full;
	unsigned char Byte[4];
};

union UnionItemInfo
{
	unsigned __int16 Full;
	unsigned char Byte[2];
};

struct STexWibItemInfo
{
	ItemOffsetUnion ItemOffset;
	unsigned char padAfterOffset[2];

	unsigned char field_6;
	unsigned char field_7;
	unsigned char field_8;
	unsigned char field_9;

	unsigned char padAfter9[2];

	UnionItemInfo field_C;

	unsigned char ZeroUAmplitudes;
	unsigned char ZeroVAmplitudes;
};


EXPORT void M3dInit_FlagZeroWibbles(STexWibItemInfo *pTexWibItemInfo);
EXPORT void DCClearRegion(i32);
EXPORT void M3dInit_InitAtStart(void);
EXPORT void M3dInit_ParsePSX(i32);
EXPORT void M3dInit_SetFoggingParams(long,long,u32);
EXPORT void M3dInit_SetResolution(u32,u32);
EXPORT void alloc_dc_models(i32,i32);
EXPORT void setup_pulsing_colors(i32);

void validate_STexWibItemInfo();

#endif
