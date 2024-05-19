#pragma once

#ifndef FRONT_H
#define FRONT_H

#include "export.h"

struct SEntry
{
	int name;
	__int16 val_a;
	__int16 val_b;
	__int16 field_8;
	__int16 field_A;
	unsigned char unk_a;
	unsigned char unk_b;
	unsigned char unk_c;
	unsigned char unk_d;
	unsigned char unk_e;
	unsigned char field_11;
	unsigned char field_12;
	unsigned char field_13;
	unsigned char field_14;
	unsigned char field_15;
	unsigned char field_16;
	unsigned char field_17;
	unsigned char field_18;
	unsigned char field_19;
	unsigned char field_1A;
	unsigned char field_1B;
	int what;
};

class CMenu {

public:
	EXPORT virtual ~CMenu();

	EXPORT CMenu(int x,int y,unsigned char Justification,int HiScale,int LowScale, int LineSep);
	EXPORT void SetLine(char);
	EXPORT void Reset(void);

	int ptr_to;
	__int16 menu_width;
	__int16 text_val_b;
	__int16 text_val_a;
	char unk_a;
	char unk_b;
	char scrollbar_one;
	char scrollbar_zero;

	char mJustification;
	unsigned char padAfterJust;

	unsigned char mLine;
	unsigned char mCursorLine;
	unsigned char padAfterCursorLine[4];

	unsigned char mNumLines;
	char field_1B;
	unsigned char padAfterNumLines[2];

	__int16 field_1E;
	unsigned char padAfter1E[4];

	int mX;
	int mY;
	int mLineSep;

	__int16 field_30;
	__int16 field_32;
	int field_34;
	int field_38;

	SEntry mEntry[40];
};

void validate_SEntry(void);
void validate_CMenu(void);

#endif
