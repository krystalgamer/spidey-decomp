#include "DXinit.h"

EXPORT int gResolutionX;
EXPORT int gResolutionY;

// @MEDIUMTODO
void AUDIOGROUPS_GetGroup(char *)
{
    printf("AUDIOGROUPS_GetGroup(char *)");
}

// @SMALLTODO
void DXINIT_DirectX8(HWND ,HINSTANCE,u32)
{
    printf("DXINIT_DirectX8(HWND__ *,HINSTANCE__ *,u32)");
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

// @SMALLTODO
void DXINIT_ShutDown(void)
{
    printf("DXINIT_ShutDown(void)");
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
void displayDIError(long,char *,i32)
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
void initDirect3D7(u32)
{
    printf("initDirect3D7(u32)");
}

// @MEDIUMTODO
void initDirectDraw7(HWND)
{
    printf("initDirectDraw7(HWND__ *)");
}

// @SMALLTODO
void initDirectInput8(HINSTANCE)
{
    printf("initDirectInput8(HINSTANCE__ *)");
}

// @SMALLTODO
void initDirectSound8(HWND)
{
    printf("initDirectSound8(HWND__ *)");
}

// @MEDIUMTODO
void shutdownDirect3D7(i32)
{
    printf("shutdownDirect3D7(i32)");
}

// @SMALLTODO
void shutdownDirectInput8(void)
{
    printf("shutdownDirectInput8(void)");
}

// @SMALLTODO
void shutdownDirectSound8(void)
{
    printf("shutdownDirectSound8(void)");
}

// @NotOk
// Globals
void DXINIT_GetCurrentResolution(int *x, int *y)
{
	*x = gResolutionX;
	*y = gResolutionY;
}
