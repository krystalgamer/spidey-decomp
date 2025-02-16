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

	i32 mNumSegs;

	SLineSeg* mSegs;
	CVector mStart;
	
	u8 mStartR;
	u8 mStartG;
	u8 mStartB;
	u8 mCode;

	unsigned char padAfter53[0x3];


	u8 field_57;
};

class CGLine : public CBit
{
	public:
		EXPORT void SetRGB1(unsigned char, unsigned char, unsigned char);
		EXPORT CGLine(void);

		int field_3C;
		int field_40;
		int field_44;
		int field_48;
		int field_4C;
		int field_50;
		int field_54;
		int field_58;
};

class CPolyLine : public CBit
{
	public:
		EXPORT CPolyLine(i32);
		EXPORT void SetSemiTransparent(void);
		unsigned char topPad[4];

		i32 mNumSegs;
		SLineSeg* mSegs;
		CVector mStart;
};

void validate_CGPolyLine(void);
void validate_CPolyLine(void);
void validate_CGLine(void);
void validate_SLineSeg(void);

#endif
