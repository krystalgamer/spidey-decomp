#include "bit2.h"
#include "ob.h"
#include "mem.h"
#include "my_assert.h"

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

		this->mSegs[i].End = ZeroVector;


	}

	this->mNumSegs = numsegs;
	this->AttachTo(&GPolyLineList);
	this->mStartR = -1;

	this->mStartG = -1;
	this->mStartB = -1;
	this->mCode = 80;
}

// @Ok
// @AlmostMatching: diff reg allocation for the reg for the loop
CPolyLine::CPolyLine(i32 numsegs)
{
	DoAssert(numsegs > 0 && numsegs < 100, "Bad numsegs sent to polyline constructor");

	this->mSegs = static_cast<SLineSeg *>(
			DCMem_New(sizeof(SLineSeg) * numsegs, 0, 1, 0, 1));

	for (i32 i = 0; i < numsegs; i++)
	{
		SLineSeg *pSeg = &this->mSegs[i];
		// @FIXME - affects portability, but it's how the devs did it
		*reinterpret_cast<u32*>(&pSeg->r) = 0x40FFFFFF;

		pSeg->End = ZeroVector;
	}


	this->mNumSegs = numsegs;
	this->AttachTo(&PolyLineList);
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
// @Matching
CGLine::~CGLine(void)
{
	this->DeleteFrom(&GLineList);
}

// @Ok
// @Matching
void CGLine::SetRGB0(u8 a2, u8 a3, u8 a4)
{
	this->mCodeBGR0 = (this->mCodeBGR0 & 0xFF000000) | (a4 << 16) | (a3 << 8) | a2;
}

// @Ok
// @Matching
void CGLine::SetRGB1(u8 a2, u8 a3, u8 a4)
{
	this->mPadBGR1 = a2 | (a4 << 16) | (a3 << 8);
}

// @Ok
// @Matching: man, the pointer thingy is needed
void CPolyLine::SetSemiTransparent(void)
{
	for (i32 i = 0; i < this->mNumSegs; i++)
	{
		SLineSeg *pSeg = &this->mSegs[i];
		pSeg->code |= 2;
	}
}

// @Ok
// @Matching
CPolyLine::~CPolyLine(void)
{
	Mem_Delete(this->mSegs);
	this->DeleteFrom(&PolyLineList);
}

// @Ok
// @Note: missing the SEH handler on the OG and mPos assingment is different
CSmokeGenerator::CSmokeGenerator(
		const CVector *a2,
		i32 a3,
		i32 a4,
		u8 a5,
		u8 a6,
		u8 a7,
		i32 a8,
		i32 a9,
		i32 a10,
		i32 a11)
{
	DoAssert(a3 != 0, "Smoke duration must be non zero");

	this->mPos = *a2;
	this->mLifetime = a3;

	this->mPuffs = a4;

	this->mR = a5;
	this->mG = a6;
	this->mB = a7;

	this->mVBase = a8;
	this->mVRandom = a9;

	this->mScaleBase = a10;
	this->mScaleRandom = a11;

	this->mFrigDeltaZ = 100;
}

// @SMALLTODO
void CSmokeGenerator::Move(void)
{
	if (++this->mAge == this->mLifetime && this->mLifetime != 0xFFFF )
		this->Die();
}

// @Ok
// @Matching
CSmokeGenerator::~CSmokeGenerator(void)
{
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

void validate_CSmokeGenerator(void)
{
	VALIDATE_SIZE(CSmokeGenerator, 0x54);

	VALIDATE(CSmokeGenerator, mPuffs, 0x3C);

	VALIDATE(CSmokeGenerator, mR, 0x40);
	VALIDATE(CSmokeGenerator, mG, 0x41);
	VALIDATE(CSmokeGenerator, mB, 0x42);

	VALIDATE(CSmokeGenerator, mVBase, 0x44);
	VALIDATE(CSmokeGenerator, mVRandom, 0x48);


	VALIDATE(CSmokeGenerator, mScaleBase, 0x4C);
	VALIDATE(CSmokeGenerator, mScaleRandom, 0x50);
}
