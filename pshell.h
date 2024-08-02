#pragma once

#ifndef PSHELL_H
#define PSHELL_H

#include "export.h"
#include "ob.h"
#include "main.h"

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

	EXPORT CExpandingBox(int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10);
	EXPORT virtual ~CExpandingBox(void);

	EXPORT int Display();
	EXPORT int ScrollBarHitTest(int a2, int a3);
};

EXPORT int PShell_GetNumCostumePSXs(void);
EXPORT void PShell_BigCheat(void);
EXPORT void PShell_NormalFont(void);
EXPORT void PShell_DefaultText(void);
EXPORT void PShell_SmallFont(void);
EXPORT void PShell_InstructionalText(void);

void validate_CExpandingBox(void);

#endif
