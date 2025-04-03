#include "bit2.h"
#include "mem.h"

#include "validate.h"

// @OK
// @Test
void CGPolyLine::SetStartAndEnd(
		CVector *pStart,
		CVector *pEnd)
{

	CVector segment = (*pEnd - *pStart) / this->mNumSegs;
	CVector current = *pStart;

	this->mStart = *pStart;

	for (i32 i = 0; i < this->mNumSegs; i++)
	{
		current += segment;
		this->mSegs[i].End = current;
	}
}

// @Ok
CGPolyLine::~CGPolyLine()
{
	Mem_Delete(this->mSegs);
	this->DeleteFrom(&GPolyLineList);
}

// @Ok
// @Test
void CGPolyLine::SetSemiTransparent(void)
{
	for (i32 i = 0; i < this->mNumSegs; i++)
	{
		this->mSegs[i].code |= 2;
	}

	this->mCode |= 2;
}

// @Ok
// @Note: not matching because there's a single write for the r,g,b,code
// it can match with that commented part but i don't want to do it that way
CGPolyLine::CGPolyLine(i32 numsegs)
{
	this->mStart.vx = 0;
	this->mStart.vy = 0;
	this->mStart.vz = 0;

	print_if_false((numsegs > 0 && numsegs < 100), "Bad numsegs sent to gpolyline constructor");

	this->mSegs = static_cast<SLineSeg*>(DCMem_New(16 * numsegs, 0, 1, 0, 1));

	for (i32 i = 0; i < numsegs; i++)
	{
		/*
		i32* dst = reinterpret_cast<i32*>(&this->mSegs[i].r);
		*dst = 0x50FFFFFF;
		*/

		this->mSegs[i].r = 0xFF;
		this->mSegs[i].g = 0xFF;
		this->mSegs[i].b = 0xFF;
		this->mSegs[i].code = 0x50;

		this->mSegs[i].End = gGlobalNormal;


	}

	this->mNumSegs = numsegs;
	this->AttachTo(&GPolyLineList);
	this->mStartR = -1;

	this->mStartG = -1;
	this->mStartB = -1;
	this->mCode = 80;
}

// @SMALLTODO
CPolyLine::CPolyLine(i32)
{
	printf("CPolyLine::CPolyLine(i32)");
}

// @Ok
// @Matching
CGLine::CGLine(void)
{
	this->mCodeBGR0 = 0x50808080;
	this->mPadBGR1 = 0x55808080;
	this->AttachTo(&GLineList);
}

// @Ok
void CGLine::SetRGB1(unsigned char a2, unsigned char a3, unsigned char a4)
{
	this->mPadBGR1 = a2 | (a4 << 16) | (a3 << 8);
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

	VALIDATE(CGLine, mCodeBGR0, 0x3C);
	VALIDATE(CGLine, mPadBGR1, 0x40);

	VALIDATE(CGLine, mStart, 0x44);

	VALIDATE(CGLine, mEnd, 0x50);
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

	VALIDATE(SLineSeg, End, 0x0);

	VALIDATE(SLineSeg, r, 0xC);
	VALIDATE(SLineSeg, g, 0xD);
	VALIDATE(SLineSeg, b, 0xE);
	VALIDATE(SLineSeg, code, 0xF);
}
