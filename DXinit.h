#pragma once

#ifndef DXINIT_H
#define DXINIT_H

#include "export.h"

#include "non_win32.h"
#include "my_dx.h"

struct SPushOffset
{
	i32 field_0;
	i16 field_4;
	i16 field_6;
};

struct DxZBufferContext
{
	i32 mNumEntries;
	DDPIXELFORMAT mEntry[8];
};

struct DXVideoModeContext
{
	i32 mNumEntries;
	DDSURFACEDESC2 mSurfaces[64];
	u8 mFlags[64];
};
struct SVideoMode
{
	DWORD dwWidth;
	DWORD dwHeight;
	u8 field_8;
};

struct DXContextEntry
{
	GUID mGUID;
	D3DDEVICEDESC7 mDeviceDesc;
	char *pDescription;
};

struct DXContext
{
	i32 mNumEntries;
	DXContextEntry mEntry[8];
};

EXPORT extern i32 gLowGraphics;
EXPORT extern void* gLowGraphicsRelated;

EXPORT void DXINIT_GetCurrentResolution(i32 *, i32 *);
EXPORT i32 AUDIOGROUPS_GetGroup(char *);

EXPORT void DXINIT_DirectX8(HWND, HINSTANCE,u32);
EXPORT void DXINIT_GetCurrentResolution(u32 *,u32 *);
EXPORT u32 DXINIT_GetNextColorDepth(u32);
EXPORT u8 DXINIT_GetNextResolution(u32 *,u32 *,u32,i32,bool);
EXPORT u32 DXINIT_GetPrevColorDepth(u32);
EXPORT void DXINIT_GetPrevResolution(u32 *,u32 *,u32,i32,bool);
EXPORT void DXINIT_SetDisplayOptions(u32,u32,u32,i32,i32);
EXPORT void DXINIT_ShutDown(void);
EXPORT u8 DXINIT_ZBufSupported(u32);
EXPORT void FreePushOffsets(void);
EXPORT void LoadPushOffsets(void);
EXPORT HRESULT WINAPI MyD3DEnumCallback(LPSTR,LPSTR, LPD3DDEVICEDESC7, LPVOID);
EXPORT BOOL WINAPI MyDDEnumCallback(GUID*, LPSTR, LPSTR, LPVOID, HMONITOR);
EXPORT void displayD3DError(long,char *,i32);
EXPORT void displayDIError(long,char *,i32);
EXPORT void displayDSError(long,char *,i32);
EXPORT void enumDisplayModes(void);
EXPORT HRESULT WINAPI enumerateModesCB(LPDDSURFACEDESC2,void *);
EXPORT HRESULT WINAPI enumerateZBuffersCB(DDPIXELFORMAT *,void *);
EXPORT char* getNextNumber(char *,i32 *);
EXPORT u8 initDirect3D7(u32);
EXPORT void initDirectDraw7(HWND);
EXPORT void initDirectInput8(HINSTANCE);
EXPORT void initDirectSound8(HWND);
EXPORT void shutdownDirect3D7(i32);
EXPORT void shutdownDirectInput8(void);
EXPORT void shutdownDirectSound8(void);
EXPORT void gsub_5027A0(void);

EXPORT extern u32 gColorCount;
EXPORT extern LPDIRECTINPUT8 gDirectInputRelated;
EXPORT extern LPDIRECTSOUND8 g_pDS;

#define DISPLAY_DI_ERROR(x) displayDIError(x, __FILE__, __LINE__)
#define DISPLAY_DS_ERROR(x) displayDSError(x, __FILE__, __LINE__)
#define DISPLAY_D3D_ERROR(x) displayD3DError(x, __FILE__, __LINE__)

#define DI_ERROR_LOG_AND_QUIT(x) {\
	if (x)\
	{\
		DISPLAY_DI_ERROR(x);\
		if (FAILED(x))\
		{\
			DXINIT_ShutDown();\
			exit(x);\
		}\
	}\
}

#define DS_ERROR_LOG_AND_QUIT(x) {\
	if (x)\
	{\
		DISPLAY_DS_ERROR(x);\
		if (FAILED(x))\
		{\
			DXINIT_ShutDown();\
			exit(x);\
		}\
	}\
}

#define D3D_ERROR_LOG_AND_QUIT(x) {\
	if (x)\
	{\
		DISPLAY_D3D_ERROR(x);\
		if (FAILED(x))\
		{\
			DXINIT_ShutDown();\
			exit(x);\
		}\
	}\
}

EXPORT extern LPDIRECT3DDEVICE7 g_D3DDevice7;
EXPORT extern i32 gDxOptionRelated;
EXPORT extern LPDIRECTDRAWSURFACE7 g_pDDS_SaveScreen;
EXPORT extern RECT gRect;
EXPORT extern LPDIRECTDRAWSURFACE7 g_pDDS_Scene;
EXPORT extern D3DDEVICEDESC7 gD3DDevCaps;

void validate_DXContext(void);
void validate_DXContextEntry(void);
void validate_SVideoMode(void);
void validate_DXVideoModeContext(void);
void validate_DxZBufferContext(void);
void validate_SPushOffset(void);

#endif
