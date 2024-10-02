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
		u8 Shaded;
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
		EXPORT SlicedImage2(void*, i32, i32, i32, i32, u8, u16, u32);

		EXPORT ~SlicedImage2(void);
		EXPORT i32 screenHeight(void);

		EXPORT virtual void UnknownSlicedImageVirtualFunc(void);
		EXPORT virtual void setData(void*);
		EXPORT virtual void draw(i32, i32, i32, float);

		EXPORT void pack(void);
		EXPORT void removeFromMemory(void);

		u32 field_10;

		i16 field_14;
		i16 field_16;
		i32 field_18;
		u8 field_1C;
		u8 padAfter1C[1];

		u16 field_1E;
};

EXPORT int Load8BitBMP_2(char *, char **, i32 *, i32 *, u16*);
EXPORT i32 GetBMPBitDepth(char *);
EXPORT void Load4BitBMP_2(char *,char **,i32 *,i32 *,u16 *);
EXPORT i32 LoadNBitBMP_(const char *,char **,i32 *,i32 *,u16 *,i32 *);

EXPORT extern u16 gSlicedImageRelated[16];

void validate_Image(void);
void validate_SlicedImage2(void);
#endif
