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
	unsigned char pad[0x68-6-0xC];
};

EXPORT void PCTex_SetTextureUserData(int, Bitmap256*);
EXPORT float PCTex_GetTextureWScale(int);
EXPORT float PCTex_GetTextureHScale(int);
EXPORT int PCTex_GetTextureFlags(int);
EXPORT int countBits(unsigned int);

void validate_WeirdTextureHolder(void);

#endif
