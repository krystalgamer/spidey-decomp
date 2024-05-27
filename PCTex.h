#pragma once

#ifndef PCTEX_H
#define PCTEX_H

#include "export.h"
#include "bitmap256.h"

struct WeirdTextureHolder
{
	Bitmap256* texture;
	float wScale;
	float hScale;
	int flags;
	int *split;
	unsigned char pad[0x68-6-0x10];
};

EXPORT void PCTex_SetTextureUserData(int, Bitmap256*);
EXPORT float PCTex_GetTextureWScale(int);
EXPORT float PCTex_GetTextureHScale(int);
EXPORT int PCTex_GetTextureFlags(int);
EXPORT int countBits(unsigned int);
EXPORT int countLeadingBits(unsigned int);
EXPORT int PCTex_GetTextureSplitID(int, int);

void validate_WeirdTextureHolder(void);

#endif
