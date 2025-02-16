#include "bit2.h"
#include "validate.h"

// @SMALLTODO
CPolyLine::CPolyLine(i32)
{
	printf("CPolyLine::CPolyLine(i32)");
}

// @NotOk
// globals
CGLine::CGLine(void)
{
	this->field_44 = 0;
	this->field_48 = 0;
	this->field_4C = 0;
	this->field_50 = 0;
	this->field_54 = 0;
	this->field_58 = 0;

	this->field_3C = 0x50808080;
	this->field_40 = 0x55808080;
	this->AttachTo(reinterpret_cast<CBit**>(0x56E9CC));
}

// @Ok
void CGLine::SetRGB1(unsigned char a2, unsigned char a3, unsigned char a4)
{
	this->field_40 = a2 | (a4 << 16) | (a3 << 8);
}

// @NotOk
// figure out what the ptr is
void CPolyLine::SetSemiTransparent(void)
{
	for (int i = 0; i < this->mNumSegs; i++)
	{
		unsigned char * ptr = reinterpret_cast<unsigned char*>(this->mSegs);
		ptr[0x10*i] |= 2;
	}
}

void validate_CGPolyLine(void){
	VALIDATE_SIZE(CGPolyLine, 0x58);

	VALIDATE(CGPolyLine, mNumSegs, 0x3C);

	VALIDATE(CGPolyLine, mSegs, 0x40);
	VALIDATE(CGPolyLine, mStart, 0x44);

	VALIDATE(CGPolyLine, mStartR, 0x50);
	VALIDATE(CGPolyLine, mStartG, 0x51);
	VALIDATE(CGPolyLine, mStartB, 0x52);
	VALIDATE(CGPolyLine, mCode, 0x53);

	VALIDATE(CGPolyLine, field_57, 0x57);
}

void validate_CGLine(void)
{
	VALIDATE_SIZE(CGPolyLine, 0x58);

	VALIDATE(CGLine, field_3C, 0x3C);
	VALIDATE(CGLine, field_40, 0x40);
	VALIDATE(CGLine, field_44, 0x44);
	VALIDATE(CGLine, field_48, 0x48);
	VALIDATE(CGLine, field_4C, 0x4C);
	VALIDATE(CGLine, field_50, 0x50);
	VALIDATE(CGLine, field_54, 0x54);
	VALIDATE(CGLine, field_58, 0x58);
}

void validate_CPolyLine(void)
{
	VALIDATE_SIZE(CPolyLine, 0x54);

	VALIDATE(CPolyLine, mNumSegs, 0x40);
	VALIDATE(CPolyLine, mSegs, 0x44);
	VALIDATE(CPolyLine, mStart, 0x48);
}

void validate_SLineSeg(void)
{
	VALIDATE_SIZE(SLineSeg, 0x10);

	VALIDATE(SLineSeg, r, 0xC);
	VALIDATE(SLineSeg, g, 0xD);
	VALIDATE(SLineSeg, b, 0xE);
}
