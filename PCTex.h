#pragma once

#ifndef PCTEX_H
#define PCTEX_H

#include "export.h"
#include "bitmap256.h"

struct WeirdTextureHolder
{
	Bitmap256* texture;
	unsigned char pad[0x68-6];
};

EXPORT void PCTex_SetTextureUserData(int, Bitmap256*);

void validate_WeirdTextureHolder(void);

#endif
