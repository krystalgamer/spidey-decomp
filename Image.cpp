#include "Image.h"
#include "validate.h"

void validate_SlicedImage(void)
{
	VALIDATE_SIZE(SlicedImage2, 0x20);
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
