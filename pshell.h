#pragma once

#ifndef PSHELL_H
#define PSHELL_H

#include "export.h"
#include "ob.h"
#include "main.h"

struct SCheat
{
	const char* pCode;
	const char* pDescription;
};

class CExpandingBox : public CClass
{

public: 

	i32 field_4;
	i32 field_8;
	i32 field_C;
	i32 field_10;
	i32 field_14;
	i32 field_18;
	i32 field_1C;
	i32 field_20;
	i32 field_24;
	u8 padAfter24[4];

	i32 field_2C;
	u8 padBottom[0x34-0x2C-4];

	EXPORT CExpandingBox(i32 a2,i32 a3,i32 a4,i32 a5,i32 a6,i32 a7,i32 a8,i32 a9,i32 a10);
	EXPORT virtual ~CExpandingBox(void);

	EXPORT i32 Display();
	EXPORT i32 ScrollBarHitTest(i32 a2, i32 a3);
};

EXPORT i32 PShell_GetNumCostumePSXs(void);
EXPORT void PShell_BigCheat(void);
EXPORT void PShell_NormalFont(void);
EXPORT void PShell_DefaultText(void);
EXPORT void PShell_SmallFont(void);
EXPORT void PShell_InstructionalText(void);
EXPORT void PShell_Initialise(void);

EXPORT i32 ActivateCheat(i32);
EXPORT void DisplayScore(i32,i32,i32,i32);
EXPORT i32 PShell_ActivateCheat(char *);
EXPORT void PShell_ApplyGameState(void);
EXPORT void PShell_BigFont(void);
EXPORT void PShell_DrawHighlight(i32,i32,i32,i32);
EXPORT void PShell_EndTrainingDisplay(void);
EXPORT void PShell_EndTrainingInit(void);
EXPORT void PShell_EndTrainingUpdate(void);
EXPORT void PShell_MaybeSaveGame(void);
EXPORT void PShell_MaybeUnlockStuff(void);
EXPORT i32 PShell_MoveTowards(i32,i32);

void validate_CExpandingBox(void);
void validate_SCheat(void);


static const i32 NUM_CHEATS = 24;
EXPORT extern SCheat gCheats[NUM_CHEATS];

#endif
