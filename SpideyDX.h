#pragma once

#ifndef SPIDEYDX_H
#define SPIDEYDX_H

#include "export.h"

#ifdef _WIN32
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>
#endif

EXPORT extern i32 gRenderTest;

EXPORT extern i32 gGameResolutionX;
EXPORT extern i32 gGameResolutionY;

EXPORT extern i32 gDxResolutionX;
EXPORT extern i32 gDxResolutionY;

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

#ifdef _WIN32
EXPORT LRESULT CALLBACK SpideyWndProc(HWND, UINT, WPARAM, LPARAM);
EXPORT i32 WinYield(void);
#endif

EXPORT void debugSettings(void);
EXPORT void mipmapOffset(u32,u32,float);
EXPORT void parseCommandLine(char *);

#ifdef _WIN32
EXPORT i32 WINAPI RealWinMain(HINSTANCE, HINSTANCE, LPSTR, i32);
#endif

#endif
