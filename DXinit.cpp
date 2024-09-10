#include "DXinit.h"
#include "SpideyDX.h"
#include "dcmodel.h"
#include "PCGfx.h"
#include "DXsound.h"
#include "validate.h"

#include <cstring>
#include <cstdlib>

EXPORT int gResolutionX;
EXPORT int gResolutionY;

EXPORT i32 gLowGraphics;
EXPORT void* gLowGraphicsRelated;

u32 gColorCount;

EXPORT HWND gDxHwnd;
i32 gDxOptionRelated;

EXPORT LPDIRECTDRAWSURFACE7 pDDS;

LPDIRECTINPUT8 gDirectInputRelated;
LPDIRECTSOUND8 g_pDS;

EXPORT DSCAPS gDsCaps;

EXPORT u8 gD3DOptionsRelated[8004];

EXPORT u32 gDisplayDeviceIndex;
EXPORT LPDIRECTDRAW7 lpDD;

EXPORT DWORD gTotalVideoMemory;
LPDIRECTDRAWSURFACE7 g_pDDS_SaveScreen;
LPDIRECTDRAWSURFACE7 g_pDDS_Scene;

EXPORT LPDIRECTDRAWCLIPPER g_pClipper;

EXPORT SVideoMode gVideoModes[5] =
{
	{ 0x200, 0x180, 2 },
	{ 0x280, 0x1E0, 6 },
	{ 0x320, 0x258, 4 },
	{ 0x400, 0x300, 4 },
	{ 0x500, 0x400, 4 },
};

EXPORT struct tagPOINT Point;
RECT gRect;

EXPORT LPDIRECT3D7 g_D3D7;

LPDIRECT3DDEVICE7 g_D3DDevice7;
EXPORT D3DDEVICEDESC7 gD3DDevCaps;

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

// @Ok
// @Matching
BOOL WINAPI MyDDEnumCallback(
		GUID* pGUID,
		LPSTR pDescription,
		LPSTR,
		LPVOID pUnkContext,
		HMONITOR)
{
	DXContext* pContext = reinterpret_cast<DXContext*>(pUnkContext);
	if (pContext->mNumEntries < 8)
	{
		DXContextEntry* pEntry = &pContext->mEntry[pContext->mNumEntries];
		if (pGUID)
		{
			pEntry->mGUID = *pGUID;
		}
		else
		{
			memset(&pEntry->mGUID, 0, sizeof(pEntry->mGUID));
		}

		pEntry->pDescription = static_cast<char*>(malloc(strlen(pDescription) + 1));
		strcpy(pEntry->pDescription, pDescription);
		DXERR_printf("Got DD Device: %s\n", pEntry->pDescription);

		pContext->mNumEntries++;
		return TRUE;
	}

	return FALSE;
}

// @Ok
// @Matching
HRESULT WINAPI MyD3DEnumCallback(
		LPSTR pDesc,
		LPSTR,
		LPD3DDEVICEDESC7 a3,
		LPVOID pUnkContext)
{
#ifdef _WIN32
	DXContext* pContext = reinterpret_cast<DXContext*>(pUnkContext);

	if (pContext->mNumEntries < 8)
	{
		DXContextEntry* pEntry = &pContext->mEntry[pContext->mNumEntries];
		memcpy(
				&pEntry->mDeviceDesc,
				a3,
				sizeof(pEntry->mDeviceDesc));

		 pEntry->pDescription = static_cast<char*>(malloc(strlen(pDesc)+1));

		 strcpy(pEntry->pDescription, pDesc);
		 DXERR_printf("Got D3D Device: %s\n", pEntry->pDescription);
		 pContext->mNumEntries++;

		return TRUE;
	}

#endif
	return FALSE;
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

// @Ok
INLINE void enumDisplayModes(void)
{
#ifdef _WIN32
	DDSURFACEDESC2 v123;

	memset(&v123, 0, sizeof(v123));
	v123.dwSize = 124;
	v123.ddpfPixelFormat.dwRGBBitCount = 16;
	v123.ddsCaps.dwCaps = DDSCAPS_3DDEVICE;
	HRESULT hr = lpDD->EnumDisplayModes(0, &v123, gD3DOptionsRelated, enumerateModesCB);
	D3D_ERROR_LOG_AND_QUIT(hr);
#endif
}

// @Ok
// Slightly different register allocation
HRESULT WINAPI enumerateModesCB(LPDDSURFACEDESC2 pDesc, void* pUnkContext)
{
#ifdef _WIN32
	DXVideoModeContext* pContext = reinterpret_cast<DXVideoModeContext*>(pUnkContext);

	if (pContext->mNumEntries < 64)
	{
		LPDDSURFACEDESC2 pCurDesc = &pContext->mSurfaces[pContext->mNumEntries];

		// @BUG
		// I think the devs wanted to skip devices that don't support RGB
		if ((pDesc->ddpfPixelFormat.dwFlags | DDPF_RGB) == 0)
		{
			return TRUE;
		}

		if (pDesc->ddpfPixelFormat.dwRGBBitCount < 16)
			return TRUE;

		for (i32 i = 0; i <= 5; i++)
		{
			if (i == 5)
				return TRUE;


			if (pDesc->dwWidth == gVideoModes[i].dwWidth
					&& pDesc->dwHeight == gVideoModes[i].dwHeight)
			{
				pContext->mFlags[pContext->mNumEntries] |= gVideoModes[i].field_8;
				break;
			}
		}

		memcpy(pCurDesc, pDesc, sizeof(pContext->mSurfaces[pContext->mNumEntries]));
		DXERR_printf(
			"Got Video Mode: %ix%ix%ibpp\n",
				pCurDesc->dwWidth,
				pCurDesc->dwHeight,
				pCurDesc->ddpfPixelFormat.dwRGBBitCount);
		pContext->mFlags[pContext->mNumEntries] |= 1;
		pContext->mNumEntries++;
		return TRUE;
	}
#endif
	return FALSE;
}

// @Ok
// @Matching
HRESULT WINAPI enumerateZBuffersCB(LPDDPIXELFORMAT a1, LPVOID a2)
{
#ifdef _WIN32
	DxZBufferContext* pContext = reinterpret_cast<DxZBufferContext*>(a2);
	if (pContext->mNumEntries < 8)
	{
		if (a1->dwFlags == 1024)
		{
			memcpy(&pContext->mEntry[pContext->mNumEntries], a1, sizeof(*a1));
			DXERR_printf("Got ZBuffer: %i\n", pContext->mEntry[pContext->mNumEntries].dwRGBBitCount);
			pContext->mNumEntries++;
		}
		return TRUE;
	}

#endif

	return FALSE;
}

// @SMALLTODO
void getNextNumber(char *,i32 *)
{
    printf("getNextNumber(char *,i32 *)");
}

// @Ok
u8 initDirect3D7(u32 a1)
{
#ifdef _WIN32
	u32 v77 = (a1 & 2);
	HRESULT hr;

	LPDIRECT3D7 v1 = g_D3D7;
	if (!v1)
	{
		hr = lpDD->QueryInterface(IID_IDirect3D7, reinterpret_cast<void**>(&g_D3D7));
		D3D_ERROR_LOG_AND_QUIT(hr);

		v1 = g_D3D7;
	}

	DXContext Context;
	memset(&Context, 0, sizeof(Context));

	hr = v1->EnumDevices(MyD3DEnumCallback, reinterpret_cast<void**>(&Context));
	D3D_ERROR_LOG_AND_QUIT(hr);


	i32 i_d3dDevice = -1;
	i32 i_RGB = -1;
	i32 i_hal = -1;
	i32 i_tnl = -1;

	if (Context.mNumEntries >= 1)
	{
		for (
				i32 i = Context.mNumEntries - 1;
				i >= 0;
				i--)
		{
			if (!memcmp(&Context.mEntry[i].mDeviceDesc.deviceGUID, &IID_IDirect3DTnLHalDevice, sizeof(_GUID)))
			{
				i_tnl = i;
			}
			else if (!memcmp(&Context.mEntry[i].mDeviceDesc.deviceGUID, &IID_IDirect3DHALDevice, sizeof(_GUID)))
			{
				i_hal = i;
			}
			else if (!memcmp(&Context.mEntry[i].mDeviceDesc.deviceGUID, &IID_IDirect3DRGBDevice, sizeof(_GUID)))
			{
				i_RGB = i;
			}
		}

		if (i_tnl == -1 && i_hal == -1)
		{
			g3DAccelator = 0;
		}
		else
		{
			g3DAccelator = 1;
		}
	}
	else
	{
		g3DAccelator = 0;
	}

	if (!gLowGraphics)
	{
		if (i_tnl != -1)
		{
			i_d3dDevice = i_tnl;
		}
		else if (i_hal != -1)
		{
			i_d3dDevice = i_hal;
		}
		else if (i_RGB != -1)
		{
			i_d3dDevice = -1;
		}

		if (!g3DAccelator)
		{
			if (pDDS)
			{
				hr = g_pDDS_Scene->DeleteAttachedSurface(0, pDDS);
				D3D_ERROR_LOG_AND_QUIT(hr);

				hr = pDDS->Release();
				D3D_ERROR_LOG_AND_QUIT(hr);
				pDDS = 0;
				v77 = 0;
			}

			gLowGraphics = 1;
			i_d3dDevice = i_RGB;
		}
	}
	else
	{
		i_d3dDevice = i_RGB;
	}

	print_if_false(i_d3dDevice != -1, "no D3D device found!");
	if (i_d3dDevice == i_tnl && i_hal != -1)
	{
		i_d3dDevice = i_hal;
	}
	DXERR_printf("D3D Device: %s\n", Context.mEntry[i_d3dDevice].pDescription);

	if (Context.mNumEntries > 0)
	{
		for (i32 i = 0; i < Context.mNumEntries; i++)
		{
			free(Context.mEntry[i].pDescription);
		}
	}

	DxZBufferContext zBufContext;
	memset(&zBufContext, 0, sizeof(zBufContext));

	GUID& pGUID = Context.mEntry[i_d3dDevice].mDeviceDesc.deviceGUID;
	hr = g_D3D7->EnumZBufferFormats(
			pGUID,
			enumerateZBuffersCB,
			reinterpret_cast<void*>(&zBufContext));
	D3D_ERROR_LOG_AND_QUIT(hr);

	if (v77 && !gLowGraphics)
	{
		i32 i_ZBuf = 0;
		for (
				i32 i = 1;
				i < zBufContext.mNumEntries;
				i++)
		{
			if (zBufContext.mEntry[i].dwRGBBitCount == 16)
				i_ZBuf = i;
		}

		if (zBufContext.mEntry[i_ZBuf].dwRGBBitCount != 16)
		{
			i_ZBuf = zBufContext.mNumEntries - 1;
			DXERR_printf(
					"No 16-bit ZBuffer found. Using %i-bit ZBuffer\r\n",
					zBufContext.mEntry[i_ZBuf].dwRGBBitCount);
		}

		DXERR_printf("ZBuffer: %i\n", zBufContext.mEntry[i_ZBuf].dwRGBBitCount);

		DDSURFACEDESC2 v81;
		memset(&v81, 0, sizeof(v81));

		v81.dwWidth = gDxResolutionX;
		v81.dwSize = sizeof(v81);
		v81.dwFlags = DDSD_PIXELFORMAT | DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
		v81.ddsCaps.dwCaps = DDSCAPS_ZBUFFER;
		v81.dwHeight = gDxResolutionY;
		memcpy(&v81.ddpfPixelFormat, &zBufContext.mEntry[i_ZBuf], sizeof(v81.ddpfPixelFormat));

		if ( i_d3dDevice == i_RGB )
			v81.ddsCaps.dwCaps = DDSCAPS_ZBUFFER | DDSCAPS_SYSTEMMEMORY;
		hr = lpDD->CreateSurface(&v81, &pDDS, 0);
		D3D_ERROR_LOG_AND_QUIT(hr);

		hr = g_pDDS_Scene->AddAttachedSurface(pDDS);
		if (hr == DDERR_CANNOTATTACHSURFACE)
		{
			if (gColorCount > 0x10)
			{
				return 0;
			}
		}
		D3D_ERROR_LOG_AND_QUIT(hr);
	}
	
	hr = g_D3D7->CreateDevice(pGUID, g_pDDS_Scene, &g_D3DDevice7);
	D3D_ERROR_LOG_AND_QUIT(hr);

	hr = g_D3DDevice7->GetCaps(&gD3DDevCaps);
	D3D_ERROR_LOG_AND_QUIT(hr);

	D3DVIEWPORT7 v80;
	v80.dwWidth = gDxResolutionX;
	v80.dwHeight = gDxResolutionY;
	v80.dwX = 0;
	v80.dwY = 0;
	v80.dvMinZ = 0.0;
	v80.dvMaxZ = 1.0;

	hr = g_D3DDevice7->SetViewport(&v80);
	D3D_ERROR_LOG_AND_QUIT(hr);

	if ( (gD3DDevCaps.dwTextureOpCaps & 5) == 0 )
		DXERR_printf("\tSelected 3D device does not support Modulate2X color mode!\r\n");
#endif

	return 1;
}

// @Ok
void initDirectDraw7(HWND hwnd)
{
#ifdef _WIN32
	GUID Guid;
	DXContext Context;

	memset(&Context, 0, sizeof(Context));
	memset(gD3DOptionsRelated, 0, sizeof(gD3DOptionsRelated));
	memset(&Guid, 0, sizeof(Guid));
	
	HRESULT hr = DirectDrawEnumerateEx(
			MyDDEnumCallback,
			&Context,
			DDENUM_ATTACHEDSECONDARYDEVICES |
			DDENUM_DETACHEDSECONDARYDEVICES |
			DDENUM_NONDISPLAYDEVICES);

	D3D_ERROR_LOG_AND_QUIT(hr);

	u32 chosenDisplayIndex = Context.mNumEntries - 1;
	if (gDisplayDeviceIndex < chosenDisplayIndex)
	{
		DXERR_printf("Using device %u instead of %i.\r\n", gDisplayDeviceIndex, Context.mNumEntries - 1);
		chosenDisplayIndex = gDisplayDeviceIndex;
	}

	Guid = Context.mEntry[chosenDisplayIndex].mGUID;
	char* pDesc = Context.mEntry[chosenDisplayIndex].pDescription;
	DXERR_printf("DD Device: %s\n", pDesc);

	if (Context.mNumEntries >= 1)
	{
		i32 entries = Context.mNumEntries;
		while(entries)
		{
			free(Context.mEntry[entries].pDescription);
			entries--;
		}
	}

	hr = DirectDrawCreateEx(&Guid, reinterpret_cast<void**>(&lpDD), IID_IDirectDraw7, NULL);
	D3D_ERROR_LOG_AND_QUIT(hr);


	DDSCAPS2 v117;
	memset(&v117, 0, sizeof(v117));
	v117.dwCaps = DDSCAPS_TEXTURE;

	DWORD freeVMem;
	hr = lpDD->GetAvailableVidMem(&v117, (LPDWORD)&gTotalVideoMemory, &freeVMem);
	D3D_ERROR_LOG_AND_QUIT(hr);

	DDDEVICEIDENTIFIER2 v124;
	memset(&v124, 0, sizeof(v124));
	hr = lpDD->GetDeviceIdentifier(&v124, 0);
	D3D_ERROR_LOG_AND_QUIT(hr);


	DXERR_printf("\t\tVideo Card: %s\r\n", v124.szDescription);
	if (strstr(v124.szDescription, "Voodoo Rush"))
	{
		gTotalVideoMemory *= 2;
		DXERR_printf("\t\tDoubling Video Mem on %s boards\r\n", "Voodoo Rush");
	}
	DXERR_printf("\t\tAvailiable Video Mem: %i\r\n", gTotalVideoMemory);

	enumDisplayModes();

	if (!gDxResolutionX && !gDxResolutionY)
	{
		gDxResolutionX = 640;
		gDxResolutionY = 480;
		gGameResolutionX = 640;
		gGameResolutionY = 480;
	}

	if (!gColorCount)
		gColorCount = 16;

	if (gDxOptionRelated)
	{
		hr = lpDD->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
		D3D_ERROR_LOG_AND_QUIT(hr);

		struct tagRECT v119;
		v119.left = 0;
		v119.top = 0;
		v119.right = gDxResolutionX;
		v119.bottom = gDxResolutionY;
		DWORD WindowLongA = GetWindowLongA(hwnd, -20);

		DWORD v42 = GetWindowLongA(hwnd, -16);
		AdjustWindowRectEx(&v119, v42, 0, WindowLongA);
		MoveWindow(hwnd, 0, 0, v119.right - v119.left, v119.bottom - v119.top, 1);

		Point.x = 0;
		Point.y = 0;
		ClientToScreen(hwnd, &Point);

		gRect.left = Point.x;
		gRect.top = Point.y;
		gRect.right = gDxResolutionX + Point.x;
		gRect.bottom = gDxResolutionY + Point.y;

		DDSURFACEDESC2 v121;
		memset(&v121, 0, sizeof(v121));
		v121.dwSize = sizeof(v121);
		v121.dwFlags = DDSD_CAPS;

		v121.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;
		hr = lpDD->CreateSurface(&v121, &g_pDDS_SaveScreen, 0);
		D3D_ERROR_LOG_AND_QUIT(hr);

		memset(&v121, 0, sizeof(v121));
		v121.dwWidth = gDxResolutionX;
		v121.dwHeight = gDxResolutionY;
		v121.dwSize = sizeof(v121);
		v121.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
		v121.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_OFFSCREENPLAIN;

		hr = lpDD->CreateSurface(&v121, &g_pDDS_Scene, 0);
		D3D_ERROR_LOG_AND_QUIT(hr);

		hr = lpDD->CreateClipper(0, &g_pClipper, 0);
		D3D_ERROR_LOG_AND_QUIT(hr);

		hr = g_pDDS_SaveScreen->SetClipper(g_pClipper);
		D3D_ERROR_LOG_AND_QUIT(hr);

		hr = g_pClipper->SetHWnd(0, hwnd);
		D3D_ERROR_LOG_AND_QUIT(hr);
	}
	else
	{
		hr = lpDD->SetCooperativeLevel(hwnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);
		if (hr != DDERR_EXCLUSIVEMODEALREADYSET)
		{
			D3D_ERROR_LOG_AND_QUIT(hr);
		}

		DXERR_printf("Video Mode %ix%ix%ibpp\r\n", gDxResolutionX, gDxResolutionY, gColorCount);
		hr = lpDD->SetDisplayMode(gDxResolutionX, gDxResolutionY, gColorCount, 0, 0);
		if (hr == DDERR_NOEXCLUSIVEMODE)
		{
			hr = lpDD->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
			D3D_ERROR_LOG_AND_QUIT(hr);
			lpDD->SetCooperativeLevel(hwnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);
			hr = lpDD->SetDisplayMode(gDxResolutionX, gDxResolutionY, gColorCount, 0, 0);
		}

		D3D_ERROR_LOG_AND_QUIT(hr);

		DDSURFACEDESC2 v121;
		memset(&v121, 0, sizeof(v121));
		v121.dwSize = sizeof(v121);
		v121.dwFlags = DDSD_BACKBUFFERCOUNT | DDSD_CAPS;
		v121.ddsCaps.dwCaps =
			DDSCAPS_3DDEVICE |
			DDSCAPS_PRIMARYSURFACE |
			DDSCAPS_FLIP |
			DDSCAPS_COMPLEX;
		v121.dwBackBufferCount = 1;

		hr = lpDD->CreateSurface(&v121, &g_pDDS_SaveScreen, 0);
		D3D_ERROR_LOG_AND_QUIT(hr);

		memset(&v117, 0, sizeof(v117));
		v117.dwCaps = DDSCAPS_BACKBUFFER;

		hr = g_pDDS_SaveScreen->GetAttachedSurface(&v117, &g_pDDS_Scene);
		D3D_ERROR_LOG_AND_QUIT(hr);
	}

	DDBLTFX v122;
	v122.dwSize = sizeof(v122);
	v122.dwFillColor = 0xFF000000;

	if (g_pDDS_SaveScreen)
	{
		if (gDxOptionRelated)
		{
			hr = g_pDDS_SaveScreen->Blt(
					&gRect,
					0,
					0,
					DDBLT_WAIT | DDBLT_COLORFILL,
					&v122);
		}
		else
		{
			hr = g_pDDS_SaveScreen->Blt(
					0,
					0,
					0,
					DDBLT_WAIT | DDBLT_COLORFILL,
					&v122);
		}
		D3D_ERROR_LOG_AND_QUIT(hr);
	}

	if (g_pDDS_Scene)
	{
		hr = g_pDDS_Scene->Blt(
				0,
				0,
				0,
				DDBLT_WAIT | DDBLT_COLORFILL,
				&v122);
		D3D_ERROR_LOG_AND_QUIT(hr);
	}

#endif
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

void validate_DXContext(void)
{
#ifdef _WIN32
	VALIDATE_SIZE(DXContext, 0x804);

	VALIDATE(DXContext, mNumEntries, 0x0);
	VALIDATE(DXContext, mEntry, 0x4);
#endif
}

void validate_DXContextEntry(void)
{
#ifdef _WIN32
	VALIDATE_SIZE(DXContextEntry, 0x100);

	VALIDATE(DXContextEntry, mGUID, 0x0);
	VALIDATE(DXContextEntry, mDeviceDesc, 0x10);
	VALIDATE(DXContextEntry, pDescription, 0xFC);
#endif
}

void validate_SVideoMode(void)
{
	VALIDATE_SIZE(SVideoMode, 0xC);

	VALIDATE(SVideoMode, dwWidth, 0x0);
	VALIDATE(SVideoMode, dwHeight, 0x4);
	VALIDATE(SVideoMode, field_8, 0x8);
}

void validate_DXVideoModeContext(void)
{
#ifdef _WIN32
	VALIDATE_SIZE(DXVideoModeContext, 0x1F44);

	VALIDATE(DXVideoModeContext, mNumEntries, 0x0);
	VALIDATE(DXVideoModeContext, mSurfaces, 0x4);
	VALIDATE(DXVideoModeContext, mFlags, 0x1F04);
#endif
}

void validate_DxZBufferContext(void)
{
#ifdef _WIN32
	VALIDATE_SIZE(DxZBufferContext, 0x104);
	VALIDATE(DxZBufferContext, mNumEntries, 0x0);
	VALIDATE(DxZBufferContext, mEntry, 0x4);
#endif
}
