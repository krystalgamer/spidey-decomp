#pragma once

#ifndef IMAGE_H
#define IMAGE_H

#include "export.h"
#include "main.h"

class Image : public CClass
{
	public:
		EXPORT Image(void);
		EXPORT ~Image(void);
		u8 field_4;
		u8 field_5;
		u8 field_6;
		u8 field_7;
		u8 field_8;
		u8 field_9;
		u8 field_A;
		u8 field_B;
		u32 field_C;
};

class SlicedImage2 : public Image
{
	public:
		EXPORT SlicedImage2(void);
		EXPORT ~SlicedImage2(void);
		EXPORT i32 screenHeight(void);

		EXPORT virtual void UnknownSlicedImageVirtualFunc(void);
		EXPORT virtual void setData(void*);
		EXPORT virtual void draw(i32, i32, i32, float);

		unsigned char padTop[0x6];

		i16 field_16;
		i32 field_18;

		unsigned char padBottom[0x20-0x18-4];
};

EXPORT int Load8BitBMP_2(char *, char **, int *, int *, unsigned __int16 *);
EXPORT void GetBMPBitDepth(char *);
EXPORT void Load4BitBMP_2(char *,char **,i32 *,i32 *,u16 *);
EXPORT void LoadNBitBMP_(char *,char **,i32 *,i32 *,u16 *,i32 *);

void validate_Image(void);
void validate_SlicedImage2(void);
#endif
