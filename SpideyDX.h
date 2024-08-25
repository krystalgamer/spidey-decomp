#pragma once

#ifndef SPIDEYDX_H
#define SPIDEYDX_H

#include "export.h"
#include "non_win32.h"

EXPORT extern i32 gRenderTest;

EXPORT extern i32 gGameResolutionX;
EXPORT extern i32 gGameResolutionY;

EXPORT extern u32 gDxResolutionX;
EXPORT extern u32 gDxResolutionY;

EXPORT extern u8 gMMXSupport;
EXPORT extern u8 g3DAccelator;

EXPORT void BuildTwiddleTable(void);
EXPORT void CalcUntwiddledPos(u32,u32,u32,u32);
EXPORT void ComputeMaskShift(u32,u32,u32 *,u32 *);
EXPORT void SPIDEYDX_DisplayDeviceSettings(char *);
EXPORT void SPIDEYDX_LoadSettings(void);
EXPORT void SPIDEYDX_SaveSettings(void);
EXPORT void SPIDEYDX_Shutdown(void);
EXPORT void DXERR_printf(const char*, ...);

EXPORT LRESULT CALLBACK SpideyWndProc(HWND, UINT, WPARAM, LPARAM);
EXPORT i32 WinYield(void);

EXPORT void debugSettings(void);
EXPORT void mipmapOffset(u32,u32,float);
EXPORT void parseCommandLine(char *);

EXPORT i32 WINAPI RealWinMain(HINSTANCE, HINSTANCE, LPSTR, i32);

EXPORT extern HWND gHwnd;

#endif
