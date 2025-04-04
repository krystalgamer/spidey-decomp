#pragma once

#ifndef FRONT_H
#define FRONT_H

#include "export.h"
#include "main.h"
#include "pshell.h"
#include "shell.h"

EXPORT extern SSaveGame gSaveGame;

struct SLevel
{
	char* mDisplayName;
	char* mName;

	PADDING(0x4);

	u16 field_C;

	PADDING(0x14-0xC-4);
};

struct SEntry
{
	const char* name;
	i16 val_a;
	i16 val_b;
	i16 field_8;
	i16 field_A;
	u8 unk_a;
	u8 unk_b;
	u8 unk_c;
	u8 unk_d;
	u8 unk_e;
	u8 field_11;
	u8 field_12;
	u8 field_13;
	u8 field_14;
	u8 field_15;
	u8 field_16;
	u8 field_17;
	u8 field_18;
	u8 field_19;
	u8 field_1A;
	u8 field_1B;
	i32 what;
};

class CMenu : public CClass
{

public:
	EXPORT virtual ~CMenu();

	EXPORT CMenu(i32 x,i32 y,u8 Justification,i32 HiScale,i32 LowScale, i32 LineSep);
	EXPORT void SetLine(char);
	EXPORT void Reset(void);
	EXPORT void SetRedText(u8);
	EXPORT i32 ChoiceIs(const char*);
	EXPORT void AdjustWidth(i32);
	EXPORT i32 FinishedZooming(void);
	EXPORT void CentreX(void);
	EXPORT i32 FindEntry(const char*);
	EXPORT void EntryOff(const char*);
	EXPORT void EntryOn(const char* a2);
	EXPORT void SetSelColor(u32, i32, i32, i32);
	EXPORT void SetNormalColor(u32, i32, i32, i32);
	EXPORT void NonGouraud(void);
	EXPORT i32 GetMenuHeight(void);
	EXPORT void CentreY(void);
	EXPORT void GetEntryXY(const char*, i32*, i32*);
	EXPORT void EntryEnable(u32, u32);
	EXPORT void AddEntry(const char*);
	EXPORT void Zoom(i32);
	EXPORT void Display(void);
	EXPORT void KillBox(void);

	CExpandingBox* ptr_to;
	u16 menu_width;
	i16 text_val_b;
	i32 width_val_a;

	char scrollbar_one;
	char scrollbar_zero;

	u8 mJustification;

	PADDING(1);

	u8 mLine;
	u8 mCursorLine;

	PADDING(4);

	u8 mNumLines;
	u8 field_1B;
	u8 mZoomBoxType;

	PADDING(1);

	i16 field_1E;

	PADDING(4);

	i32 mX;
	i32 mY;
	i32 mLineSep;
	i16 field_30;
	u16 field_32;
	i32 field_34;
	i32 field_38;

	SEntry mEntry[40];
};

void validate_SEntry(void);
void validate_CMenu(void);

EXPORT void Front_GaugeOff(void);
EXPORT void Front_ClearScreen(void);
EXPORT void Front_Display(void);
EXPORT SLevel* Front_FindLevel(char *);
EXPORT void Front_GetButtons(i32 *,i32 *,i32 *,i32 *);
EXPORT i32 Front_GetLevelIndex(char *);
EXPORT void Front_Init(void);
EXPORT void Front_LoadGame(SSaveGame *,i32,bool);
EXPORT void Front_MiniUpdate(void);
EXPORT void Front_RGBRed(void);
EXPORT void Front_SaveGameState(void);
EXPORT void Front_Update(void);
EXPORT void PrintPaused(void);

EXPORT extern CMenu* pYesNoMenu;
const i32 FRONT_NUM_LEVELS = 41;
EXPORT extern SLevel Levels[FRONT_NUM_LEVELS];

void validate_SLevel(void);

#endif
