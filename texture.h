#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include "pal.h"

// @TODO go to types.h
struct Texture
{
	u8 u0;
	u8 v0;

	u16 clut;

	u8 u1;
	u8 v1;

	u16 tpage;

	u8 u2;
	u8 v2;

	u8 u3;
	u8 v3;


	u32 TexWin;
	u16 field_10;
	u16 Usage;
	u32 Checksum;

	tag_S_Pal* pPalette;
	u16 x;
	u16 y;

	Texture *pNext;
	Texture *pPrevious;
	u8 padBottom[4];
};

struct TextureEntry
{
	u8 Active;
	char Name[35];
	u32 Checksum;
};

#endif
