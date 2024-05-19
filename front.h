#pragma once

#ifndef FRONT_H
#define FRONT_H

#include "export.h"

struct SEntry
{
	unsigned char fullPad[0x20];
};

class CMenu {

public:
	EXPORT virtual ~CMenu();

	EXPORT CMenu(int x,int y,unsigned char Justification,int HiScale,int LowScale, int LineSep);

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

	unsigned char selected_index;
	unsigned char mCursorLine;
	unsigned char padAfterCursorLine[4];

	unsigned char mNumLines;
	unsigned char padAfterNumLines[2];

	__int16 field_1E;
	unsigned char padAfter1E[4];

	int mX;
	int mY;
	int mLineSep;
	unsigned char padAfterLineSep[0xC];

	SEntry mEntry[40];
};

void validate_SEntry(void);
void validate_CMenu(void);

#endif
