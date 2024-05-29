#pragma once

#ifndef IMAGE_H
#define IMAGE_H

#include "export.h"
#include "main.h"

class Image : public CClass
{
	public:
		EXPORT Image(void);
		unsigned char field_4;
		unsigned char field_5;
		unsigned char field_6;
		unsigned char field_7;
		unsigned char field_8;
		unsigned char field_9;
		unsigned char field_A;
		unsigned char field_B;
		int field_C;
};

class SlicedImage2 : public Image
{
	public:
		EXPORT int screenHeight(void);

		unsigned char padTop[0x6];

		__int16 field_16;

		unsigned char padBottom[0x20-0x16-4];
};

EXPORT int Load8BitBMP_2(char *, char **, int *, int *, unsigned __int16 *);

void validate_Image(void);
void validate_SlicedImage(void);
#endif
