#pragma once

#ifndef DXINIT_H
#define DXINIT_H

#include "export.h"

#ifdef _WIN32
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>
#else

// @FIXME
#define HWND__ i32
// @FIXME
#define HINSTANCE__ i32
#endif

// @FIXME
#define _D3DDeviceDesc7 i32
// @FIXME
#define _DDPIXELFORMAT i32
// @FIXME
#define _DDSURFACEDESC2 i32

EXPORT void DXINIT_GetCurrentResolution(int *, int *);
EXPORT void AUDIOGROUPS_GetGroup(char *);

#ifdef _WIN32
EXPORT void DXINIT_DirectX8(HWND, HINSTANCE,u32);
#endif

EXPORT void DXINIT_GetCurrentResolution(u32 *,u32 *);
EXPORT void DXINIT_GetNextColorDepth(u32);
EXPORT void DXINIT_GetNextResolution(u32 *,u32 *,u32,i32,bool);
EXPORT void DXINIT_GetPrevColorDepth(u32);
EXPORT void DXINIT_GetPrevResolution(u32 *,u32 *,u32,i32,bool);
EXPORT void DXINIT_SetDisplayOptions(u32,u32,u32,i32,i32);
EXPORT void DXINIT_ShutDown(void);
EXPORT void DXINIT_ZBufSupported(u32);
EXPORT void FreePushOffsets(void);
EXPORT void LoadPushOffsets(void);
EXPORT void MyD3DEnumCallback(char *,char *,_D3DDeviceDesc7 *,void *);
EXPORT void displayD3DError(long,char *,i32);
EXPORT void displayDIError(long,char *,i32);
EXPORT void displayDSError(long,char *,i32);
EXPORT void enumDisplayModes(void);
EXPORT void enumerateModesCB(_DDSURFACEDESC2 *,void *);
EXPORT void enumerateZBuffersCB(_DDPIXELFORMAT *,void *);
EXPORT void getNextNumber(char *,i32 *);
EXPORT void initDirect3D7(u32);
EXPORT void initDirectDraw7(HWND__ *);
EXPORT void initDirectInput8(HINSTANCE__ *);
EXPORT void initDirectSound8(HWND__ *);
EXPORT void shutdownDirect3D7(i32);
EXPORT void shutdownDirectInput8(void);
EXPORT void shutdownDirectSound8(void);

#endif
