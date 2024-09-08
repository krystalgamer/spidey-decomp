#pragma once

#ifndef DXINIT_H
#define DXINIT_H

#include "export.h"

#include "non_win32.h"
#include "my_dx.h"

struct DXContextEntry
{
	GUID mGUID;
	u8 padAfter010[0xFC-0x10];
	char *pDescription;
};

struct DXContext
{
	i32 mNumEntries;
	DXContextEntry mEntry[8];
};

EXPORT extern i32 gLowGraphics;
EXPORT extern void* gLowGraphicsRelated;

EXPORT void DXINIT_GetCurrentResolution(int *, int *);
EXPORT void AUDIOGROUPS_GetGroup(char *);

EXPORT void DXINIT_DirectX8(HWND, HINSTANCE,u32);
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
EXPORT void MyD3DEnumCallback(char *,char *, D3DDEVICEDESC7 *,void *);
EXPORT BOOL WINAPI MyD3DEnumCallback(GUID*, LPSTR, LPSTR, LPVOID, HMONITOR);
EXPORT void displayD3DError(long,char *,i32);
EXPORT void displayDIError(long,char *,i32);
EXPORT void displayDSError(long,char *,i32);
EXPORT void enumDisplayModes(void);
EXPORT void enumerateModesCB(DDSURFACEDESC2 *,void *);
EXPORT void enumerateZBuffersCB(DDPIXELFORMAT *,void *);
EXPORT void getNextNumber(char *,i32 *);
EXPORT u8 initDirect3D7(u32);
EXPORT void initDirectDraw7(HWND);
EXPORT void initDirectInput8(HINSTANCE);
EXPORT void initDirectSound8(HWND);
EXPORT void shutdownDirect3D7(i32);
EXPORT void shutdownDirectInput8(void);
EXPORT void shutdownDirectSound8(void);
EXPORT void gsub_5027A0(void);

EXPORT extern i32 gColorCount;
EXPORT extern LPDIRECTINPUT8 gDirectInputRelated;
EXPORT extern LPDIRECTSOUND8 g_pDS;

#define DISPLAY_DI_ERROR(x) displayDIError(x, __FILE__, __LINE__)
#define DISPLAY_DS_ERROR(x) displayDSError(x, __FILE__, __LINE__)

#define DI_ERROR_LOG_AND_QUIT(x) {\
	if (x)\
	{\
		DISPLAY_DI_ERROR(x);\
		if (FAILED(hr))\
		{\
			DXINIT_ShutDown();\
			exit(hr);\
		}\
	}\
}

#define DS_ERROR_LOG_AND_QUIT(x) {\
	if (x)\
	{\
		DISPLAY_DS_ERROR(x);\
		if (FAILED(hr))\
		{\
			DXINIT_ShutDown();\
			exit(hr);\
		}\
	}\
}

void validate_DXContext(void);
void validate_DXContextEntry(void);

#endif
