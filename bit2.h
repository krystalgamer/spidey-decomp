#pragma once

#ifndef BIT2_H
#define BIT2_H


#include "bit.h"

class CGPolyLine : public CBit {
public:

	unsigned char padTop[0x40-0x3B-4];

	int field_40;
	CVector field_44;
	
	unsigned char field_50;
	unsigned char field_51;
	unsigned char field_52;
	unsigned char field_53;

	unsigned char padAfter53[0x3];


	unsigned char field_57;
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
		EXPORT void SetSemiTransparent(void);
		unsigned char topPad;

		int field_40;
		int field_44;
};

void validate_CGPolyLine(void);
void validate_CPolyLine(void);
void validate_CGLine(void);

#endif
