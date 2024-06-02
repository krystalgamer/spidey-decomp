#pragma once

#ifndef PSHELL_H
#define PSHELL_H

#include "export.h"
#include "ob.h"

class CExpandingBox : public CItem {

public:
	EXPORT virtual ~CExpandingBox();
	int unk_1;
	int unk_2;
	int unk_3;
	int unk_4;
	int unk_5;
	int unk_6;
	int unk_7;
	int unk_8;
	int unk_9;
	int unk_10;
	int unk_11;
	int unk_12;

	EXPORT CExpandingBox(int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10);
	EXPORT int Display();
	EXPORT int ScrollBarHitTest(int a2, int a3);
};

EXPORT int PShell_GetNumCostumePSXs(void);
EXPORT void PShell_BigCheat(void);
EXPORT void PShell_NormalFont(void);
EXPORT void PShell_DefaultText(void);
EXPORT void PShell_SmallFont(void);
EXPORT void PShell_InstructionalText(void);

#endif
