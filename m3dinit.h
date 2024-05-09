#ifndef M3DINIT_H
#define M3DINIT_H

#pragma once

#include "export.h"

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

void validate_STexWibItemInfo();

#endif
