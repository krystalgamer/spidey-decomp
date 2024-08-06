#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

// @TODO go to types.h
struct Texture
{
	u8 field_0;
	u8 field_1;
	u16 field_2;

	u8 field_4;
	u8 padAfter4;

	u16 field_6;
	u8 padAfter6[0x9-0x6-2];

	u8 field_9;
	u8 padAfter9[0xC-0x9-1];


	u32 TexWin;
	u8 padAfterC[0x12-0xC-4];
	u16 Usage;
	u32 Checksum;
	u8 padAfter14[0x20-0x14-4];
	Texture *pNext;
};

struct TextureEntry
{
	u8 Active;
	char Name[35];
	u32 Checksum;
};

#endif
