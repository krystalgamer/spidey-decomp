#pragma once

#ifndef FRONT_H
#define FRONT_H

#include "export.h"

struct SEntry
{
	char* name;
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
	EXPORT void SetRedText(unsigned char);
	EXPORT int ChoiceIs(const char*);
	EXPORT void AdjustWidth(int);
	EXPORT int FinishedZooming(void);
	EXPORT void CentreX(void);
	EXPORT int FindEntry(const char*);
	EXPORT void EntryOff(const char*);
	EXPORT void EntryOn(const char* a2);
	EXPORT void SetSelColor(unsigned int, int, int, int);
	EXPORT void SetNormalColor(unsigned int, int, int, int);
	EXPORT void NonGouraud(void);
	EXPORT int GetMenuHeight(void);
	EXPORT void CentreY(void);
	EXPORT void GetEntryXY(const char*, int*, int*);
	EXPORT void EntryEnable(unsigned int, unsigned int);
	EXPORT void AddEntry(const char*);
	EXPORT void Zoom(i32);

	int ptr_to;
	unsigned __int16 menu_width;
	__int16 text_val_b;
	int width_val_a;

	char scrollbar_one;
	char scrollbar_zero;

	unsigned char mJustification;
	unsigned char padAfterJust;

	unsigned char mLine;
	unsigned char mCursorLine;
	unsigned char padAfterCursorLine[4];

	unsigned char mNumLines;
	unsigned char field_1B;
	unsigned char padAfterNumLines[2];

	__int16 field_1E;
	unsigned char padAfter1E[4];

	int mX;
	int mY; int mLineSep;
	__int16 field_30;
	__int16 field_32;
	int field_34;
	int field_38;

	SEntry mEntry[40];
};

void validate_SEntry(void);
void validate_CMenu(void);

// @FIXME
struct SSaveGame;

EXPORT void Front_GaugeOff(void);
EXPORT void Front_ClearScreen(void);
EXPORT void Front_Display(void);
EXPORT void Front_FindLevel(char *);
EXPORT void Front_GetButtons(i32 *,i32 *,i32 *,i32 *);
EXPORT void Front_GetLevelIndex(char *);
EXPORT void Front_Init(void);
EXPORT void Front_LoadGame(SSaveGame *,i32,bool);
EXPORT void Front_MiniUpdate(void);
EXPORT void Front_RGBRed(void);
EXPORT void Front_SaveGameState(void);
EXPORT void Front_Update(void);
EXPORT void PrintPaused(void);

#endif
