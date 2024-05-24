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
		unsigned char pad[0x10];
};

EXPORT void validate_Image(void);
EXPORT void validate_SlicedImage(void);
#endif
