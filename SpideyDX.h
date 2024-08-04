#pragma once

#ifndef SPIDEYDX_H
#define SPIDEYDX_H

#include "export.h"

EXPORT void BuildTwiddleTable(void);
EXPORT void CalcUntwiddledPos(u32,u32,u32,u32);
EXPORT void ComputeMaskShift(u32,u32,u32 *,u32 *);
EXPORT void SPIDEYDX_DisplayDeviceSettings(char *);
EXPORT void SPIDEYDX_LoadSettings(void);
EXPORT void SPIDEYDX_SaveSettings(void);
EXPORT void SPIDEYDX_Shutdown(void);

//@FIXME void* should be HWND
EXPORT void SpideyWndProc(void *,u32,u32,long);
EXPORT void WinYield(void);
EXPORT void debugSettings(void);
EXPORT void mipmapOffset(u32,u32,float);
EXPORT void parseCommandLine(char *);


#endif
