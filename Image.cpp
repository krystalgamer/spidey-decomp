#include "Image.h"
#include "validate.h"

// @Ok
Image::Image(void)
{
	this->field_4 = 0;
	this->field_5 = 0;
	this->field_6 = 0;
	this->field_7 = 0x80;
	this->field_8 = 0x80;
	this->field_9 = 0x80;
	this->field_A = 0;
	this->field_B = 0;
	this->field_C = 4096;
}

// @Ok
int SlicedImage2::screenHeight(void)
{
	return (this->field_C * this->field_16) >> 12;
}

void validate_SlicedImage(void)
{
	VALIDATE_SIZE(SlicedImage2, 0x20);
	VALIDATE(SlicedImage2, field_16, 0x16);
}

void validate_Image(void)
{
	VALIDATE(Image, field_4, 0x4);
	VALIDATE(Image, field_5, 0x5);
	VALIDATE(Image, field_6, 0x6);
	VALIDATE(Image, field_7, 0x7);
	VALIDATE(Image, field_8, 0x8);
	VALIDATE(Image, field_9, 0x9);
	VALIDATE(Image, field_A, 0xA);
	VALIDATE(Image, field_B, 0xB);
	VALIDATE(Image, field_C, 0xC);
}
