#include "DXinit.h"
#include "SpideyDX.h"
#include "dcmodel.h"
#include "PCGfx.h"
#include "DXsound.h"

#include <cstring>
#include <cstdlib>

EXPORT int gResolutionX;
EXPORT int gResolutionY;

EXPORT i32 gLowGraphics;
EXPORT void* gLowGraphicsRelated;

i32 gColorCount;

EXPORT HWND gDxHwnd;
EXPORT i32 gDxOptionRelated;

EXPORT LPDIRECTDRAWSURFACE7 pDDS;

LPDIRECTINPUT8 gDirectInputRelated;
LPDIRECTSOUND8 g_pDS;

EXPORT DSCAPS gDsCaps;

// @Ok
void gsub_5027A0(void)
{
	if (gLowGraphics)
	{
		if (gLowGraphicsRelated)
		{
			free(gLowGraphicsRelated);
			gLowGraphicsRelated = 0;
		}
	}
}

// @MEDIUMTODO
void AUDIOGROUPS_GetGroup(char *)
{
    printf("AUDIOGROUPS_GetGroup(char *)");
}

// @Ok
void DXINIT_DirectX8(
		HWND hwnd,
		HINSTANCE hInstance,
		u32 a3)
{
	i32 v3 = a3;
	gDxOptionRelated = a3 & 1;
	gDxHwnd = hwnd;

	PreComputeConvertedColors(1.0);
	PCGfx_SetBrightness(gBrightnessRelated);

	if (gLowGraphics)
		v3 &= 0xFFFFFFFD;
	initDirectDraw7(hwnd);

	if (!initDirect3D7(v3))
	{
		i32 v4 = gColorCount;
		shutdownDirect3D7(1);
		gColorCount = 16;
		initDirectDraw7(hwnd);
		initDirect3D7(v3);
		gColorCount = v4;
	}

	if (gLowGraphics || !pDDS)
		v3 &= ~2;

	initDirectSound8(hwnd);
	initDirectInput8(hInstance);

	DXPOLY_Init(v3);
}

// @SMALLTODO
void DXINIT_GetCurrentResolution(u32 *,u32 *)
{
    printf("DXINIT_GetCurrentResolution(u32 *,u32 *)");
}

// @SMALLTODO
void DXINIT_GetNextColorDepth(u32)
{
    printf("DXINIT_GetNextColorDepth(u32)");
}

// @SMALLTODO
void DXINIT_GetNextResolution(u32 *,u32 *,u32,i32,bool)
{
    printf("DXINIT_GetNextResolution(u32 *,u32 *,u32,i32,bool)");
}

// @SMALLTODO
void DXINIT_GetPrevColorDepth(u32)
{
    printf("DXINIT_GetPrevColorDepth(u32)");
}

// @SMALLTODO
void DXINIT_GetPrevResolution(u32 *,u32 *,u32,i32,bool)
{
    printf("DXINIT_GetPrevResolution(u32 *,u32 *,u32,i32,bool)");
}

// @MEDIUMTODO
void DXINIT_SetDisplayOptions(u32,u32,u32,i32,i32)
{
    printf("DXINIT_SetDisplayOptions(u32,u32,u32,i32,i32)");
}

// @Ok
INLINE void DXINIT_ShutDown(void)
{
	gsub_5027A0();
	shutdownDirect3D7(1);
	shutdownDirectSound8();
	shutdownDirectInput8();
}

// @SMALLTODO
void DXINIT_ZBufSupported(u32)
{
    printf("DXINIT_ZBufSupported(u32)");
}

// @SMALLTODO
void FreePushOffsets(void)
{
    printf("FreePushOffsets(void)");
}

// @SMALLTODO
void LoadPushOffsets(void)
{
    printf("LoadPushOffsets(void)");
}

// @SMALLTODO
void MyD3DEnumCallback(char *,char *, D3DDEVICEDESC7 *,void *)
{
    printf("MyD3DEnumCallback(char *,char *,_D3DDeviceDesc7 *,void *)");
}

// @SMALLTODO
void displayD3DError(long,char *,i32)
{
    printf("displayD3DError(long,char *,i32)");
}

// @SMALLTODO
void displayDIError(HRESULT error, char* buf, i32 line)
{
    printf("displayDIError(long,char *,i32)");
}

// @SMALLTODO
void displayDSError(long,char *,i32)
{
    printf("displayDSError(long,char *,i32)");
}

// @SMALLTODO
void enumDisplayModes(void)
{
    printf("enumDisplayModes(void)");
}

// @SMALLTODO
void enumerateModesCB(DDSURFACEDESC2 *,void *)
{
    printf("enumerateModesCB(_DDSURFACEDESC2 *,void *)");
}

// @SMALLTODO
void enumerateZBuffersCB(DDPIXELFORMAT *,void *)
{
    printf("enumerateZBuffersCB(_DDPIXELFORMAT *,void *)");
}

// @SMALLTODO
void getNextNumber(char *,i32 *)
{
    printf("getNextNumber(char *,i32 *)");
}

// @MEDIUMTODO
u8 initDirect3D7(u32)
{
    printf("initDirect3D7(u32)");
	return (u8)0x07092024;
}

// @MEDIUMTODO
void initDirectDraw7(HWND)
{
    printf("initDirectDraw7(HWND__ *)");
}

// @Ok
INLINE void initDirectInput8(HINSTANCE hInstance)
{
#ifdef _WIN32
	HRESULT hr = DirectInput8Create(
			hInstance,
			DIRECTINPUT_VERSION,
			IID_IDirectInput8,
			reinterpret_cast<void**>(&gDirectInputRelated),
			0);

	DI_ERROR_LOG_AND_QUIT(hr);
#endif
}

// @Ok
INLINE void initDirectSound8(HWND hwnd)
{
#ifdef _WIN32
	HRESULT hr = DirectSoundCreate8(
			&DSDEVID_DefaultPlayback,
			&g_pDS,
			0);

	hr = g_pDS->SetCooperativeLevel(hwnd, DSSCL_EXCLUSIVE);
	if (hr)
	{
		DISPLAY_DS_ERROR(hr);
		shutdownDirectSound8();
	}

	memset(&gDsCaps, 0, sizeof(gDsCaps));
	gDsCaps.dwSize = sizeof(gDsCaps);
	hr = g_pDS->GetCaps(&gDsCaps);
	if (hr)
	{
		DISPLAY_DS_ERROR(hr);
		shutdownDirectSound8();
	}

	DXSOUND_Init();
#endif
}

// @MEDIUMTODO
void shutdownDirect3D7(i32)
{
    printf("shutdownDirect3D7(i32)");
}

// @Ok
INLINE void shutdownDirectInput8(void)
{
#ifdef _WIN32
	if (gDirectInputRelated)
	{
		HRESULT hr = gDirectInputRelated->Release();
		DI_ERROR_LOG_AND_QUIT(hr);

		gDirectInputRelated = 0;
	}
#endif
}

// @Ok
INLINE void shutdownDirectSound8(void)
{
#ifdef _WIN32
	DXSOUND_ShutDown();

	if(g_pDS)
	{
		HRESULT hr = g_pDS->Release();
		DS_ERROR_LOG_AND_QUIT(hr);
		g_pDS = 0;
	}
#endif
}

// @NotOk
// Globals
void DXINIT_GetCurrentResolution(int *x, int *y)
{
	*x = gResolutionX;
	*y = gResolutionY;
}
