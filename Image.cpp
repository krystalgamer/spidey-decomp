#include "Image.h"
#include "validate.h"
#include "dcshellutils.h"
#include "PCTex.h"

// @Ok
Image::~Image(void)
{
}

// @Ok
SlicedImage2::~SlicedImage2(void)
{
	if (this->field_18)
	{
		PCTex_ReleaseTexture(this->field_18, true);
	}
}

// @SMALLTODO
void SlicedImage2::UnknownSlicedImageVirtualFunc(void)
{
	printf("void SlicedImage2::UnknownSlicedImageVirtualFunc(void)");
}

// @SMALLTODO
void SlicedImage2::setData(void*)
{
	printf("void SlicedImage2::setData(void*)");
}

// @SMALLTODO
void SlicedImage2::draw(i32, i32, i32, float)
{
	printf("void SlicedImage2::draw(i32, i32, i32, float)");
}

// @SMALLTODO
void GetBMPBitDepth(char *)
{
    printf("GetBMPBitDepth(char *)");
}

// @MEDIUMTODO
void Load4BitBMP_2(char *,char **,i32 *,i32 *,u16 *)
{
    printf("Load4BitBMP_2(char *,char **,i32 *,i32 *,u16 *)");
}

// @SMALLTODO
void LoadNBitBMP_(char *,char **,i32 *,i32 *,u16 *,i32 *)
{
    printf("LoadNBitBMP_(char *,char **,i32 *,i32 *,u16 *,i32 *)");
}

// @Ok
// @Matching
SlicedImage2::SlicedImage2(void)
{
    printf_fancy("stubbed: SlicedImage2::SlicedImage2");
}

// @Ok
INLINE Image::Image(void)
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

// @Ok
int Load8BitBMP_2(char *a1, char **a2, int *a3, int *a4, unsigned __int16 *a5)
{
	Load8BitBMP2(a1, a2, a3, a4, a5, false);
	return 1;
}

void validate_SlicedImage2(void)
{
	VALIDATE_SIZE(SlicedImage2, 0x20);
	VALIDATE(SlicedImage2, field_16, 0x16);

	VALIDATE_VTABLE(SlicedImage2, UnknownSlicedImageVirtualFunc, 1);
	VALIDATE_VTABLE(SlicedImage2, setData, 2);
	VALIDATE_VTABLE(SlicedImage2, draw, 3);
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
