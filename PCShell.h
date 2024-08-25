#pragma once

#ifndef PCSHELL_H
#define PCSHELL_H

#include "export.h"

struct SActionMap
{
	i32 field_0;
	char field_4[1];

	u8 padAfter4[0x14-0x4-1];
	i32 field_14;
	u8 padAfter14[4];
};

EXPORT void PCSHELL_CheckTriggers(u32,i32,i32);
EXPORT void PCSHELL_CoordsDCtoPC(i32 *,i32 *);
EXPORT void PCSHELL_CoordsPCtoDC(i32 *,i32 *);
EXPORT void PCSHELL_DoControllerConfig(bool);
EXPORT void PCSHELL_DoDisplayOptions(void);
EXPORT void PCSHELL_DrawMouseCursor(void);
EXPORT void PCSHELL_Initialize(void);
EXPORT void PCSHELL_IsMouseOver(i32,i32,i32,i32);
EXPORT void PCSHELL_IsMouseOverText(char const *,i32,i32,i32);
EXPORT i32 PCSHELL_MouseMoved(void);
EXPORT void PCSHELL_Relax(void);
EXPORT void PCSHELL_Shutdown(void);
EXPORT u8 PCSHELL_UpdateMouse(void);
EXPORT void displayControllerScreen(void);
EXPORT void initActionMaps(void);
EXPORT void processControllerScreen(void);
EXPORT void resetActionMaps(bool);

void validate_SActionMap(void);

#endif
