#pragma once

#ifndef BIT2_H
#define BIT2_H


#include "bit.h"

struct SLineSeg
{
	CVector End;

	u8 r;
	u8 g;
	u8 b;
	u8 code;
};

class CGPolyLine : public CBit {
public:

	EXPORT CGPolyLine(i32);
	EXPORT ~CGPolyLine();
	EXPORT void SetSemiTransparent(void);
	EXPORT void SetStartAndEnd(CVector*, CVector*);

	i32 mNumSegs;

	SLineSeg* mSegs;
	CVector mStart;
	
	u8 mStartR;
	u8 mStartG;
	u8 mStartB;
	u8 mCode;

	PADDING(0x3);

	u8 field_57;
};

class CGLine : public CBit
{
	public:
		EXPORT void SetRGB1(u8, u8, u8);
		EXPORT void SetRGB0(u8, u8, u8);

		EXPORT CGLine(void);
		EXPORT virtual ~CGLine(void);

		u32 mCodeBGR0;
		u32 mPadBGR1;

		CVector mStart;

		CVector mEnd;
};

class CPolyLine : public CBit
{
	public:
		EXPORT CPolyLine(i32);
		EXPORT virtual ~CPolyLine(void) OVERRIDE;

		EXPORT void SetSemiTransparent(void);

		PADDING(4);

		i32 mNumSegs;
		SLineSeg* mSegs;
		CVector mStart;
};

class CSmokeGenerator : public CNonRenderedBit
{
	public:
		EXPORT CSmokeGenerator(const CVector *,i32,i32,u8,u8,u8,i32,i32,i32,i32);
		EXPORT virtual void Move(void) OVERRIDE;
		EXPORT virtual ~CSmokeGenerator(void) OVERRIDE;

		i32 mPuffs;

		u8 mR;
		u8 mG;
		u8 mB;

		PADDING(1);

		i32 mVBase;
		i32 mVRandom;

		i32 mScaleBase;
		i32 mScaleRandom;
};

class CGLineParticle : public CGLine
{
	public:
		EXPORT CGLineParticle(CVector &,CVector &,u16,i32);
		EXPORT virtual ~CGLineParticle(void) OVERRIDE;

		EXPORT virtual void Move(void) OVERRIDE;

		i32 field_5C;
};

void validate_CGPolyLine(void);
void validate_CPolyLine(void);
void validate_CGLine(void);
void validate_SLineSeg(void);
void validate_CSmokeGenerator(void);
void validate_CGLineParticle(void);

#endif
