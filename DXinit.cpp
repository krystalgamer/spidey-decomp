#include "DXinit.h"
#include "SpideyDX.h"
#include "dcmodel.h"
#include "PCGfx.h"
#include "DXsound.h"
#include "spool.h"
#include "dcfileio.h"
#include "validate.h"

#include "my_assert.h"

#include <cstring>
#include <cstdlib>

// @Ok
EXPORT SPushOffset *gPushOffsetAddr;
// @Ok
EXPORT i32 gPushOffsetOne;

EXPORT int gResolutionX;
EXPORT int gResolutionY;

i32 gLowGraphics;
EXPORT void* gLowGraphicsRelated;

u32 gColorCount;

EXPORT HWND gDxHwnd;
i32 gDxOptionRelated;

EXPORT LPDIRECTDRAWSURFACE7 pDDS;

LPDIRECTINPUT8 gDirectInputRelated;
LPDIRECTSOUND8 g_pDS;

EXPORT DSCAPS gDsCaps;

// @Ok
EXPORT DXVideoModeContext gDisplayModeContext;

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
D3DDEVICEDESC7 gD3DDevCaps;

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
i32 AUDIOGROUPS_GetGroup(char *)
{
    printf("AUDIOGROUPS_GetGroup(char *)");
	return 0x06042025;
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

// @Ok
// @Matching
void DXINIT_GetCurrentResolution(
		u32 *a1,
		u32 *a2)
{
	*a1 = gDxResolutionX;
	*a2 = gDxResolutionY;
}

// @Ok
// @Matching
u32 DXINIT_GetNextColorDepth(u32 a1)
{
	u32 result = -1;
	u32 secondResult = -1;
#ifdef _WIN32
	for (i32 i = 0; i < gDisplayModeContext.mNumEntries; i++)
	{
		if (gDisplayModeContext.mFlags[i] & 1)
		{
			if (gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount > a1
					&& gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount < result)
			{
				result = gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount;
			}
		}

		if (gDisplayModeContext.mFlags[i] & 1)
		{
			if(gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount < secondResult)
			{
				secondResult = gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount;
			}
		}
	}
#endif

	if (result == -1)
	{
		result = secondResult;
	}

	if (result == -1)
	{
		result = 0;
	}

	return result;
}

// @Ok
// @AlmostMatching: the original materializes the height compare with seta and moves
// the equal-width block past the loop end, ours folds it into plain branches
u8 DXINIT_GetNextResolution(
		u32 *a1,
		u32 *a2,
		u32 a3,
		i32 a4,
		bool a5)
{
	u32 v11 = -1;
	u32 v12 = -1;
	u8 v13 = 0;
#ifdef _WIN32
	DDSURFACEDESC2* pSurface = gDisplayModeContext.mSurfaces;

	for (i32 i = 0; i < gDisplayModeContext.mNumEntries; i++)
	{
		u8 flags = gDisplayModeContext.mFlags[i];

		if (a4)
		{
			if ((flags & 2) == 0)
			{
				continue;
			}
		}
		else if ((flags & 4) == 0)
		{
			continue;
		}

		if (pSurface[i].ddpfPixelFormat.dwRGBBitCount != a3)
		{
			continue;
		}

		if (!DXINIT_ZBufSupported(a3))
		{
			continue;
		}

		DWORD dwWidth = pSurface[i].dwWidth;
		if (dwWidth < *a1)
		{
			continue;
		}

		if (dwWidth == *a1)
		{
			if (pSurface[i].dwHeight == *a2)
			{
				if (a5)
				{
					return 1;
				}

				continue;
			}
		}

		if (dwWidth > v11)
		{
			continue;
		}

		if (dwWidth < v11)
		{
			if (dwWidth == *a1)
			{
				u8 bigger = pSurface[i].dwHeight > *a2;
				if (!bigger)
				{
					continue;
				}
			}
		}
		else
		{
			DWORD dwHeight = pSurface[i].dwHeight;

			if (dwHeight <= *a2)
			{
				continue;
			}

			if (dwHeight >= v12)
			{
				continue;
			}
		}

		v11 = dwWidth;
		v12 = pSurface[i].dwHeight;
		v13 = 1;
	}

	if (v13)
	{
		*a1 = v11;
		*a2 = v12;
	}
#endif
	return v13;
}

// @Ok
// @Matching
u32 DXINIT_GetPrevColorDepth(u32 a1)
{
	u32 v1 = 0;
	u32 v2 = 0;

#ifdef _WIN32

	for (i32 i = 0; i < gDisplayModeContext.mNumEntries; i++)
	{

		if (gDisplayModeContext.mFlags[i] & 1)
		{
			if (gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount < a1
					&& gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount > v1)
			{
				v1 = gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount;
			}
		}

		if (gDisplayModeContext.mFlags[i] & 1)
		{
			if(gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount > v2)
			{
				v2 = gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount;
			}
		}
	}
#endif

	if (!v1)
	{
		v1 = v2;
	}

	return v1;
}

// @Ok
// @AlmostMatching: the original materializes the height compare with setb and moves
// the equal-width block past the loop end, ours folds it into plain branches
u8 DXINIT_GetPrevResolution(
		u32 *a1,
		u32 *a2,
		u32 a3,
		i32 a4,
		bool a5)
{
	u32 v11 = 0;
	u32 v12 = 0;
	u8 v13 = 0;
#ifdef _WIN32
	DDSURFACEDESC2* pSurface = gDisplayModeContext.mSurfaces;

	for (i32 i = 0; i < gDisplayModeContext.mNumEntries; i++)
	{
		u8 flags = gDisplayModeContext.mFlags[i];

		if (a4)
		{
			if ((flags & 2) == 0)
			{
				continue;
			}
		}
		else if ((flags & 4) == 0)
		{
			continue;
		}

		if (pSurface[i].ddpfPixelFormat.dwRGBBitCount != a3)
		{
			continue;
		}

		if (!DXINIT_ZBufSupported(a3))
		{
			continue;
		}

		DWORD dwWidth = pSurface[i].dwWidth;
		if (dwWidth > *a1)
		{
			continue;
		}

		if (dwWidth == *a1)
		{
			if (pSurface[i].dwHeight == *a2)
			{
				if (a5)
				{
					return 1;
				}

				continue;
			}
		}

		if (dwWidth < v11)
		{
			continue;
		}

		if (dwWidth > v11)
		{
			if (dwWidth == *a1)
			{
				u8 smaller = pSurface[i].dwHeight < *a2;
				if (!smaller)
				{
					continue;
				}
			}
		}
		else
		{
			DWORD dwHeight = pSurface[i].dwHeight;

			if (dwHeight >= *a2)
			{
				continue;
			}

			if (dwHeight <= v12)
			{
				continue;
			}
		}

		v11 = dwWidth;
		v12 = pSurface[i].dwHeight;
		v13 = 1;
	}

	if (v13)
	{
		*a1 = v11;
		*a2 = v12;
	}
#endif
	return v13;
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

// @NotOk
// @Validate: when done
INLINE u8 DXINIT_ZBufSupported(u32 a1)
{
#ifdef _WIN32
	for (i32  i = 0; i < gDisplayModeContext.mNumEntries; i++)
	{
		if (gDisplayModeContext.mSurfaces[i].ddpfPixelFormat.dwRGBBitCount == a1)
		{
			return gDisplayModeContext.mFlags[i] & 1;
		}
	}
#endif

	return 0;
}

// @Ok
// @Matching
void FreePushOffsets(void)
{
	if (gPushOffsetAddr)
	{
		free(gPushOffsetAddr);
	}

	gPushOffsetAddr = 0;
	gPushOffsetOne = 0;
}

// @NotOk
// @Note: looks fine but registers are saved at different places
void LoadPushOffsets(void)
{
	char path[32];

	if (gPushOffsetAddr)
	{
		free(gPushOffsetAddr);
		gPushOffsetAddr = 0;
		gPushOffsetOne = 0;
	}

	sprintf(path, "offsets\\%s.off", PSXRegion[gSpoolCurrentOpenSpot].Filename);

	i32 fileSize = FileIO_Open(path);
	if (fileSize)
	{
		void *fileBuf = malloc(fileSize);

		if (fileBuf)
		{
			FileIO_Load(fileBuf);

			char *v15 = getNextNumber(static_cast<char*>(fileBuf), &gPushOffsetOne);

			gPushOffsetAddr = static_cast<SPushOffset*>(
					malloc(sizeof(SPushOffset) * gPushOffsetOne));

			if (gPushOffsetAddr)
			{

				for (i32 i = 0; i < gPushOffsetOne; i++)
				{
					char *v19 = getNextNumber(v15, &gPushOffsetAddr[i].field_0);

					i32 v22, v21;
					char *v20 = getNextNumber(v19, &v22);
					v15 = getNextNumber(v20, &v21);

					gPushOffsetAddr[i].field_6 = v22;
					gPushOffsetAddr[i].field_4 = v21;
				}
			}
		}
		else
		{
			DXERR_printf("Out of memory loading: %s [%i entries]\r\n", path, gPushOffsetOne);
			gPushOffsetOne = 0;
		}

		free(fileBuf);
	}
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

// @Ok
// @Matching
// the two DESTORY strings keep the original game's typo
void displayD3DError(long error, char* file, i32 line)
{
#ifdef _WIN32
	char* msg;

	switch (error)
	{
	case DDERR_GENERIC:
		msg = "DDERR_GENERIC";
		break;
	case DDERR_UNSUPPORTED:
		msg = "DDERR_UNSUPPORTED";
		break;
	case DDERR_NOTINITIALIZED:
		msg = "DDERR_NOTINITIALIZED";
		break;
	case DDERR_INVALIDPARAMS:
		msg = "DDERR_INVALIDPARAMS";
		break;
	case DDERR_OUTOFMEMORY:
		msg = "DDERR_OUTOFMEMORY";
		break;
	case DDERR_ALREADYINITIALIZED:
		msg = "DDERR_ALREADYINITIALIZED";
		break;
	case DDERR_CANNOTATTACHSURFACE:
		msg = "DDERR_CANNOTATTACHSURFACE";
		break;
	case DDERR_CANNOTDETACHSURFACE:
		msg = "DDERR_CANNOTDETACHSURFACE";
		break;
	case DDERR_CURRENTLYNOTAVAIL:
		msg = "DDERR_CURRENTLYNOTAVAIL";
		break;
	case DDERR_EXCEPTION:
		msg = "DDERR_EXCEPTION";
		break;
	case DDERR_HEIGHTALIGN:
		msg = "DDERR_HEIGHTALIGN";
		break;
	case DDERR_INCOMPATIBLEPRIMARY:
		msg = "DDERR_INCOMPATIBLEPRIMARY";
		break;
	case DDERR_INVALIDCAPS:
		msg = "DDERR_INVALIDCAPS";
		break;
	case DDERR_INVALIDCLIPLIST:
		msg = "DDERR_INVALIDCLIPLIST";
		break;
	case DDERR_INVALIDMODE:
		msg = "DDERR_INVALIDMODE";
		break;
	case DDERR_INVALIDOBJECT:
		msg = "DDERR_INVALIDOBJECT";
		break;
	case DDERR_INVALIDPIXELFORMAT:
		msg = "DDERR_INVALIDPIXELFORMAT";
		break;
	case DDERR_INVALIDRECT:
		msg = "DDERR_INVALIDRECT";
		break;
	case DDERR_LOCKEDSURFACES:
		msg = "DDERR_LOCKEDSURFACES";
		break;
	case DDERR_NO3D:
		msg = "DDERR_NO3D";
		break;
	case DDERR_NOALPHAHW:
		msg = "DDERR_NOALPHAHW";
		break;
	case DDERR_NOCLIPLIST:
		msg = "DDERR_NOCLIPLIST";
		break;
	case DDERR_NOCOLORCONVHW:
		msg = "DDERR_NOCOLORCONVHW";
		break;
	case DDERR_NOCOLORKEY:
		msg = "DDERR_NOCOLORKEY";
		break;
	case DDERR_NOCOLORKEYHW:
		msg = "DDERR_NOCOLORKEYHW";
		break;
	case DDERR_NOCOOPERATIVELEVELSET:
		msg = "DDERR_NOCOOPERATIVELEVELSET";
		break;
	case DDERR_NODIRECTDRAWSUPPORT:
		msg = "DDERR_NODIRECTDRAWSUPPORT";
		break;
	case DDERR_NOEXCLUSIVEMODE:
		msg = "DDERR_NOEXCLUSIVEMODE";
		break;
	case DDERR_NOFLIPHW:
		msg = "DDERR_NOFLIPHW";
		break;
	case DDERR_NOGDI:
		msg = "DDERR_NOGDI";
		break;
	case DDERR_NOMIRRORHW:
		msg = "DDERR_NOMIRRORHW";
		break;
	case DDERR_NOOVERLAYHW:
		msg = "DDERR_NOOVERLAYHW";
		break;
	case DDERR_NORASTEROPHW:
		msg = "DDERR_NORASTEROPHW";
		break;
	case DDERR_NOROTATIONHW:
		msg = "DDERR_NOROTATIONHW";
		break;
	case DDERR_NOSTRETCHHW:
		msg = "DDERR_NOSTRETCHHW";
		break;
	case DDERR_NOT4BITCOLOR:
		msg = "DDERR_NOT4BITCOLOR";
		break;
	case DDERR_NOT4BITCOLORINDEX:
		msg = "DDERR_NOT4BITCOLORINDEX";
		break;
	case DDERR_NOT8BITCOLOR:
		msg = "DDERR_NOT8BITCOLOR";
		break;
	case DDERR_NOTEXTUREHW:
		msg = "DDERR_NOTEXTUREHW";
		break;
	case DDERR_NOTFOUND:
		msg = "DDERR_NOTFOUND";
		break;
	case DDERR_NOVSYNCHW:
		msg = "DDERR_NOVSYNCHW";
		break;
	case DDERR_NOZBUFFERHW:
		msg = "DDERR_NOZBUFFERHW";
		break;
	case DDERR_NOZOVERLAYHW:
		msg = "DDERR_NOZOVERLAYHW";
		break;
	case DDERR_OVERLAPPINGRECTS:
		msg = "DDERR_OVERLAPPINGRECTS";
		break;
	case DDERR_OUTOFCAPS:
		msg = "DDERR_OUTOFCAPS";
		break;
	case DDERR_BLTFASTCANTCLIP:
		msg = "DDERR_BLTFASTCANTCLIP";
		break;
	case DDERR_CANTLOCKSURFACE:
		msg = "DDERR_CANTLOCKSURFACE";
		break;
	case DDERR_CLIPPERISUSINGHWND:
		msg = "DDERR_CLIPPERISUSINGHWND";
		break;
	case DDERR_COLORKEYNOTSET:
		msg = "DDERR_COLORKEYNOTSET";
		break;
	case DDERR_DIRECTDRAWALREADYCREATED:
		msg = "DDERR_DIRECTDRAWALREADYCREATED";
		break;
	case DDERR_EXCLUSIVEMODEALREADYSET:
		msg = "DDERR_EXCLUSIVEMODEALREADYSET";
		break;
	case DDERR_HWNDALREADYSET:
		msg = "DDERR_HWNDALREADYSET";
		break;
	case DDERR_HWNDSUBCLASSED:
		msg = "DDERR_HWNDSUBCLASSED";
		break;
	case DDERR_INVALIDDIRECTDRAWGUID:
		msg = "DDERR_INVALIDDIRECTDRAWGUID";
		break;
	case DDERR_INVALIDPOSITION:
		msg = "DDERR_INVALIDPOSITION";
		break;
	case DDERR_INVALIDSTREAM:
		msg = "DDERR_INVALIDSTREAM";
		break;
	case DDERR_NOBLTHW:
		msg = "DDERR_NOBLTHW";
		break;
	case DDERR_NOCLIPPERATTACHED:
		msg = "DDERR_NOCLIPPERATTACHED";
		break;
	case DDERR_NODDROPSHW:
		msg = "DDERR_NODDROPSHW";
		break;
	case DDERR_NODIRECTDRAWHW:
		msg = "DDERR_NODIRECTDRAWHW";
		break;
	case DDERR_NOEMULATION:
		msg = "DDERR_NOEMULATION";
		break;
	case DDERR_NOHWND:
		msg = "DDERR_NOHWND";
		break;
	case DDERR_NOOVERLAYDEST:
		msg = "DDERR_NOOVERLAYDEST";
		break;
	case DDERR_NOPALETTEATTACHED:
		msg = "DDERR_NOPALETTEATTACHED";
		break;
	case DDERR_NOPALETTEHW:
		msg = "DDERR_NOPALETTEHW";
		break;
	case DDERR_NOTAOVERLAYSURFACE:
		msg = "DDERR_NOTAOVERLAYSURFACE";
		break;
	case DDERR_NOTFLIPPABLE:
		msg = "DDERR_NOTFLIPPABLE";
		break;
	case DDERR_OUTOFVIDEOMEMORY:
		msg = "DDERR_OUTOFVIDEOMEMORY";
		break;
	case DDERR_OVERLAYCANTCLIP:
		msg = "DDERR_OVERLAYCANTCLIP";
		break;
	case DDERR_OVERLAYCOLORKEYONLYONEACTIVE:
		msg = "DDERR_OVERLAYCOLORKEYONLYONEACTIVE";
		break;
	case DDERR_OVERLAYNOTVISIBLE:
		msg = "DDERR_OVERLAYNOTVISIBLE";
		break;
	case DDERR_PALETTEBUSY:
		msg = "DDERR_PALETTEBUSY";
		break;
	case DDERR_PRIMARYSURFACEALREADYEXISTS:
		msg = "DDERR_PRIMARYSURFACEALREADYEXISTS";
		break;
	case DDERR_REGIONTOOSMALL:
		msg = "DDERR_REGIONTOOSMALL";
		break;
	case DDERR_SURFACEALREADYATTACHED:
		msg = "DDERR_SURFACEALREADYATTACHED";
		break;
	case DDERR_SURFACEALREADYDEPENDENT:
		msg = "DDERR_SURFACEALREADYDEPENDENT";
		break;
	case DDERR_SURFACEBUSY:
		msg = "DDERR_SURFACEBUSY";
		break;
	case DDERR_SURFACEISOBSCURED:
		msg = "DDERR_SURFACEISOBSCURED";
		break;
	case DDERR_SURFACELOST:
		msg = "DDERR_SURFACELOST";
		break;
	case DDERR_SURFACENOTATTACHED:
		msg = "DDERR_SURFACENOTATTACHED";
		break;
	case DDERR_TOOBIGHEIGHT:
		msg = "DDERR_TOOBIGHEIGHT";
		break;
	case DDERR_TOOBIGSIZE:
		msg = "DDERR_TOOBIGSIZE";
		break;
	case DDERR_TOOBIGWIDTH:
		msg = "DDERR_TOOBIGWIDTH";
		break;
	case DDERR_UNSUPPORTEDFORMAT:
		msg = "DDERR_UNSUPPORTEDFORMAT";
		break;
	case DDERR_UNSUPPORTEDMASK:
		msg = "DDERR_UNSUPPORTEDMASK";
		break;
	case DDERR_VERTICALBLANKINPROGRESS:
		msg = "DDERR_VERTICALBLANKINPROGRESS";
		break;
	case DDERR_WASSTILLDRAWING:
		msg = "DDERR_WASSTILLDRAWING";
		break;
	case DDERR_XALIGN:
		msg = "DDERR_XALIGN";
		break;
	case DDERR_CANTDUPLICATE:
		msg = "DDERR_CANTDUPLICATE";
		break;
	case DDERR_CANTCREATEDC:
		msg = "DDERR_CANTCREATEDC";
		break;
	case DDERR_IMPLICITLYCREATED:
		msg = "DDERR_IMPLICITLYCREATED";
		break;
	case DDERR_INVALIDSURFACETYPE:
		msg = "DDERR_INVALIDSURFACETYPE";
		break;
	case DDERR_NODC:
		msg = "DDERR_NODC";
		break;
	case DDERR_NOFOCUSWINDOW:
		msg = "DDERR_NOFOCUSWINDOW";
		break;
	case DDERR_NOMIPMAPHW:
		msg = "DDERR_NOMIPMAPHW";
		break;
	case DDERR_NOOPTIMIZEHW:
		msg = "DDERR_NOOPTIMIZEHW";
		break;
	case DDERR_NOTLOADED:
		msg = "DDERR_NOTLOADED";
		break;
	case DDERR_NOTLOCKED:
		msg = "DDERR_NOTLOCKED";
		break;
	case DDERR_NOTPALETTIZED:
		msg = "DDERR_NOTPALETTIZED";
		break;
	case DDERR_UNSUPPORTEDMODE:
		msg = "DDERR_UNSUPPORTEDMODE";
		break;
	case DDERR_WRONGMODE:
		msg = "DDERR_WRONGMODE";
		break;
	case DDERR_DCALREADYCREATED:
		msg = "DDERR_DCALREADYCREATED";
		break;
	case DDERR_CANTPAGELOCK:
		msg = "DDERR_CANTPAGELOCK";
		break;
	case DDERR_CANTPAGEUNLOCK:
		msg = "DDERR_CANTPAGEUNLOCK";
		break;
	case DDERR_DEVICEDOESNTOWNSURFACE:
		msg = "DDERR_DEVICEDOESNTOWNSURFACE";
		break;
	case DDERR_EXPIRED:
		msg = "DDERR_EXPIRED";
		break;
	case DDERR_MOREDATA:
		msg = "DDERR_MOREDATA";
		break;
	case DDERR_NONONLOCALVIDMEM:
		msg = "DDERR_NONONLOCALVIDMEM";
		break;
	case DDERR_NOTPAGELOCKED:
		msg = "DDERR_NOTPAGELOCKED";
		break;
	case DDERR_VIDEONOTACTIVE:
		msg = "DDERR_VIDEONOTACTIVE";
		break;
	case D3DERR_BADMAJORVERSION:
		msg = "D3DERR_BADMAJORVERSION";
		break;
	case D3DERR_BADMINORVERSION:
		msg = "D3DERR_BADMINORVERSION";
		break;
	case D3DERR_INVALID_DEVICE:
		msg = "D3DERR_INVALID_DEVICE";
		break;
	case D3DERR_INITFAILED:
		msg = "D3DERR_INITFAILED";
		break;
	case D3DERR_DEVICEAGGREGATED:
		msg = "D3DERR_DEVICEAGGREGATED";
		break;
	case D3DERR_TEXTURE_NO_SUPPORT:
		msg = "D3DERR_TEXTURE_NO_SUPPORT";
		break;
	case D3DERR_TEXTURE_CREATE_FAILED:
		msg = "D3DERR_TEXTURE_CREATE_FAILED";
		break;
	case D3DERR_TEXTURE_DESTROY_FAILED:
		msg = "D3DERR_TEXTURE_DESTROY_FAILED";
		break;
	case D3DERR_TEXTURE_LOCK_FAILED:
		msg = "D3DERR_TEXTURE_LOCK_FAILED";
		break;
	case D3DERR_TEXTURE_UNLOCK_FAILED:
		msg = "D3DERR_TEXTURE_UNLOCK_FAILED";
		break;
	case D3DERR_TEXTURE_LOAD_FAILED:
		msg = "D3DERR_TEXTURE_LOAD_FAILED";
		break;
	case D3DERR_TEXTURE_SWAP_FAILED:
		msg = "D3DERR_TEXTURE_SWAP_FAILED";
		break;
	case D3DERR_TEXTURE_LOCKED:
		msg = "D3DERR_TEXTURE_LOCKED";
		break;
	case D3DERR_TEXTURE_NOT_LOCKED:
		msg = "D3DERR_TEXTURE_NOT_LOCKED";
		break;
	case D3DERR_TEXTURE_GETSURF_FAILED:
		msg = "D3DERR_TEXTURE_GETSURF_FAILED";
		break;
	case D3DERR_MATRIX_CREATE_FAILED:
		msg = "D3DERR_MATRIX_CREATE_FAILED";
		break;
	case D3DERR_MATRIX_DESTROY_FAILED:
		msg = "D3DERR_MATRIX_DESTORY_FAILED";
		break;
	case D3DERR_MATRIX_SETDATA_FAILED:
		msg = "D3DERR_MATRIX_SETDATA_FAILED";
		break;
	case D3DERR_MATRIX_GETDATA_FAILED:
		msg = "D3DERR_MATRIX_GETDATA_FAILED";
		break;
	case D3DERR_SETVIEWPORTDATA_FAILED:
		msg = "D3DERR_SETVIEWPORTDATA_FAILED";
		break;
	case D3DERR_INVALIDCURRENTVIEWPORT:
		msg = "D3DERR_INVALIDCURRENTVIEWPORT";
		break;
	case D3DERR_INVALIDPRIMITIVETYPE:
		msg = "D3DERR_INVALIDPRIMITIVETYPE";
		break;
	case D3DERR_INVALIDVERTEXTYPE:
		msg = "D3DERR_INVALIDVERTEXTYPE";
		break;
	case D3DERR_TEXTURE_BADSIZE:
		msg = "D3DERR_TEXTURE_BADSIZE";
		break;
	case D3DERR_INVALIDRAMPTEXTURE:
		msg = "D3DERR_INVALIDRAMPTEXTURE";
		break;
	case D3DERR_MATERIAL_CREATE_FAILED:
		msg = "D3DERR_MATERIAL_CREATE_FAILED";
		break;
	case D3DERR_MATERIAL_DESTROY_FAILED:
		msg = "D3DERR_MATERIAL_DESTORY_FAILED";
		break;
	case D3DERR_MATERIAL_SETDATA_FAILED:
		msg = "D3DERR_MATERIAL_SETDATA_FAILED";
		break;
	case D3DERR_MATERIAL_GETDATA_FAILED:
		msg = "D3DERR_MATERIAL_GETDATA_FAILED";
		break;
	case D3DERR_INVALIDPALETTE:
		msg = "D3DERR_INVALIDPALETTE";
		break;
	case D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY:
		msg = "D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY";
		break;
	case D3DERR_ZBUFF_NEEDS_VIDEOMEMORY:
		msg = "D3DERR_ZBUFF_NEEDS_VIDEOMEMORY";
		break;
	case D3DERR_SURFACENOTINVIDMEM:
		msg = "D3DERR_SURFACENOTINVIDMEM";
		break;
	case D3DERR_LIGHT_SET_FAILED:
		msg = "D3DERR_LIGHT_SET_FAILED";
		break;
	case D3DERR_LIGHTHASVIEWPORT:
		msg = "D3DERR_LIGHTHASVIEWPORT";
		break;
	case D3DERR_LIGHTNOTINTHISVIEWPORT:
		msg = "D3DERR_LIGHTNOTINTHISVIEWPORT";
		break;
	case D3DERR_SCENE_IN_SCENE:
		msg = "D3DERR_SCENE_IN_SCENE";
		break;
	case D3DERR_SCENE_NOT_IN_SCENE:
		msg = "D3DERR_SCENE_NOT_IN_SCENE";
		break;
	case D3DERR_SCENE_BEGIN_FAILED:
		msg = "D3DERR_SCENE_BEGIN_FAILED";
		break;
	case D3DERR_SCENE_END_FAILED:
		msg = "D3DERR_SCENE_END_FAILED";
		break;
	case D3DERR_INBEGIN:
		msg = "D3DERR_INBEGIN";
		break;
	case D3DERR_NOTINBEGIN:
		msg = "D3DERR_NOTINBEGIN";
		break;
	case D3DERR_NOVIEWPORTS:
		msg = "D3DERR_NOVIEWPORTS";
		break;
	case D3DERR_VIEWPORTDATANOTSET:
		msg = "D3DERR_VIEWPORTDATANOTSET";
		break;
	case D3DERR_VIEWPORTHASNODEVICE:
		msg = "D3DERR_VIEWPORTHASNODEVICE";
		break;
	case D3DERR_NOCURRENTVIEWPORT:
		msg = "D3DERR_NOCURRENTVIEWPORT";
		break;
	case D3DERR_INVALIDVERTEXFORMAT:
		msg = "D3DERR_INVALIDVERTEXFORMAT";
		break;
	case D3DERR_COLORKEYATTACHED:
		msg = "D3DERR_COLORKEYATTACHED";
		break;
	case D3DERR_VERTEXBUFFEROPTIMIZED:
		msg = "D3DERR_VERTEXBUFFEROPTIMIZED";
		break;
	case D3DERR_VBUF_CREATE_FAILED:
		msg = "D3DERR_VBUF_CREATE_FAILED";
		break;
	case D3DERR_VERTEXBUFFERLOCKED:
		msg = "D3DERR_VERTEXBUFFERLOCKED";
		break;
	case D3DERR_ZBUFFER_NOTPRESENT:
		msg = "D3DERR_ZBUFFER_NOTPRESENT";
		break;
	case D3DERR_STENCILBUFFER_NOTPRESENT:
		msg = "D3DERR_STENCILBUFFER_NOTPRESENT";
		break;
	case D3DERR_WRONGTEXTUREFORMAT:
		msg = "D3DERR_WRONGTEXTUREFORMAT";
		break;
	case D3DERR_UNSUPPORTEDCOLOROPERATION:
		msg = "D3DERR_UNSUPPORTEDCOLOROPERATION";
		break;
	case D3DERR_UNSUPPORTEDCOLORARG:
		msg = "D3DERR_UNSUPPORTEDCOLORARG";
		break;
	case D3DERR_UNSUPPORTEDALPHAOPERATION:
		msg = "D3DERR_UNSUPPORTEDALPHAOPERATION";
		break;
	case D3DERR_UNSUPPORTEDALPHAARG:
		msg = "D3DERR_UNSUPPORTEDALPHAARG";
		break;
	case D3DERR_TOOMANYOPERATIONS:
		msg = "D3DERR_TOOMANYOPERATIONS";
		break;
	case D3DERR_CONFLICTINGTEXTUREFILTER:
		msg = "D3DERR_CONFLICTINGTEXTUREFILTER";
		break;
	case D3DERR_UNSUPPORTEDFACTORVALUE:
		msg = "D3DERR_UNSUPPORTEDFACTORVALUE";
		break;
	case D3DERR_CONFLICTINGRENDERSTATE:
		msg = "D3DERR_CONFLICTINGRENDERSTATE";
		break;
	case D3DERR_UNSUPPORTEDTEXTUREFILTER:
		msg = "D3DERR_UNSUPPORTEDTEXTUREFILTER";
		break;
	case D3DERR_TOOMANYPRIMITIVES:
		msg = "D3DERR_TOOMANYPRIMITIVES";
		break;
	case D3DERR_INVALIDMATRIX:
		msg = "D3DERR_INVALIDMATRIX";
		break;
	case D3DERR_TOOMANYVERTICES:
		msg = "D3DERR_TOOMANYVERTICES";
		break;
	case D3DERR_CONFLICTINGTEXTUREPALETTE:
		msg = "D3DERR_CONFLICTINGTEXTUREPALETTE";
		break;
	default:
		msg = "Unknown";
		break;
	}

	DXERR_printf("D3D Error: [%s], line %d: %s (%08x)\r\n", file, line, msg, error);
#endif
}

// @Ok
// @Matching
void displayDIError(HRESULT error, char* file, i32 line)
{
#ifdef _WIN32
	char* msg;

	switch (error)
	{
	case DI_OK:
		msg = "DI_OK: The operation completed successfully. This value is equal to the S_OK standard COM return value.";
		break;
	case DI_BUFFEROVERFLOW:
		msg = "DI_BUFFEROVERFLOW or DI_NOEFFECT or DI_NOTATTACHED or DI_PROPNOEFFECT.";
		break;
	case DI_POLLEDDEVICE:
		msg = "DI_POLLEDDEVICE: The device is a polled device. As a result, device buffering does not collect any data and event notifications is not signaled until the IDirectInputDevice8::Poll method is called.";
		break;
	case DI_DOWNLOADSKIPPED:
		msg = "DI_DOWNLOADSKIPPED: The parameters of the effect were successfully updated, but the effect could not be downloaded because the associated device was not acquired in exclusive mode.";
		break;
	case DI_EFFECTRESTARTED:
		msg = "DI_EFFECTRESTARTED: The effect was stopped, the parameters were updated, and the effect was restarted.";
		break;
	case DI_TRUNCATED:
		msg = "DI_TRUNCATED: The parameters of the effect were successfully updated, but some of them were beyond the capabilities of the device and were truncated to the nearest supported value.";
		break;
	case DI_SETTINGSNOTSAVED:
		msg = "DI_SETTINGSNOTSAVED: The action map was applied to the device, but the settings could not be saved.";
		break;
	case DI_TRUNCATEDANDRESTARTED:
		msg = "DI_TRUNCATEDANDRESTARTED: Equal to DI_EFFECTRESTARTED | DI_TRUNCATED.";
		break;
	case DI_WRITEPROTECT:
		msg = "DI_WRITEPROTECT: A SUCCESS code indicating that settings cannot be modified.";
		break;
	case E_PENDING:
		msg = "E_PENDING: Data is not yet available.";
		break;
	case DIERR_UNSUPPORTED:
		msg = "DIERR_UNSUPPORTED: The function called is not supported at this time. This value is equal to the E_NOTIMPL standard COM return value.";
		break;
	case DIERR_NOINTERFACE:
		msg = "DIERR_NOINTERFACE: The object does not support the specified interface. This value is equal to the E_NOINTERFACE standard COM return value.";
		break;
	case E_POINTER:
		msg = "E_POINTER: An invalid pointer, usually NULL, was passed as a parameter.";
		break;
	case DIERR_GENERIC:
		msg = "DIERR_GENERIC: An undetermined error occurred inside the DirectInput subsystem. This value is equal to the E_FAIL standard COM return value.";
		break;
	case DIERR_NOAGGREGATION:
		msg = "DIERR_NOAGGREGATION: This object does not support aggregation.";
		break;
	case DIERR_DEVICENOTREG:
		msg = "DIERR_DEVICENOTREG: The device or device instance is not registered with DirectInput. This value is equal to the REGDB_E_CLASSNOTREG standard COM return value.";
		break;
	case DIERR_DEVICEFULL:
		msg = "DIERR_DEVICEFULL: The device is full.";
		break;
	case DIERR_MOREDATA:
		msg = "DIERR_MOREDATA: Not all the requested information fit into the buffer.";
		break;
	case DIERR_NOTDOWNLOADED:
		msg = "DIERR_NOTDOWNLOADED: The effect is not downloaded.";
		break;
	case DIERR_HASEFFECTS:
		msg = "DIERR_HASEFFECTS: The device cannot be reinitialized because effects are attached to it.";
		break;
	case DIERR_NOTEXCLUSIVEACQUIRED:
		msg = "DIERR_NOTEXCLUSIVEACQUIRED: The operation cannot be performed unless the device is acquired in DISCL_EXCLUSIVE mode.";
		break;
	case DIERR_INCOMPLETEEFFECT:
		msg = "DIERR_INCOMPLETEEFFECT: The effect could not be downloaded because essential information is missing. For example, no axes have been associated with the effect, or no type-specific information has been supplied.";
		break;
	case DIERR_NOTBUFFERED:
		msg = "DIERR_NOTBUFFERED: The device is not buffered. Set the DIPROP_BUFFERSIZE property to enable buffering.";
		break;
	case DIERR_EFFECTPLAYING:
		msg = "DIERR_EFFECTPLAYING: The parameters were updated in memory but were not downloaded to the device because the device does not support updating an effect while it is still playing.";
		break;
	case DIERR_UNPLUGGED:
		msg = "DIERR_UNPLUGGED: The operation could not be completed because the device is not plugged in.";
		break;
	case DIERR_REPORTFULL:
		msg = "DIERR_REPORTFULL: More information was requested to be sent than can be sent to the device.";
		break;
	case DIERR_MAPFILEFAIL:
		msg = "DIERR_MAPFILEFAIL: An error has occured either reading the vendor-supplied action-mapping file for the device or reading or writing the user configuration mapping file for the device.";
		break;
	case DIERR_OBJECTNOTFOUND:
		msg = "DIERR_NOTFOUND or DIERR_OBJECTNOTFOUND: The requested object does not exist.";
		break;
	case DIERR_OTHERAPPHASPRIO:
		msg = "DIERR_OTHERAPPHASPRIO or DIERR_READONLY or DIERR_HANDLEEXISTS.";
		break;
	case E_HANDLE:
		msg = "E_HANDLE: The HWND parameter is not a valid top-level window that belongs to the process.";
		break;
	case DIERR_NOTACQUIRED:
		msg = "DIERR_NOTACQUIRED: The operation cannot be performed unless the device is acquired.";
		break;
	case DIERR_OUTOFMEMORY:
		msg = "DIERR_OUTOFMEMORY: The DirectInput subsystem could not allocate sufficient memory to complete the call. This value is equal to the E_OUTOFMEMORY standard COM return value.";
		break;
	case DIERR_NOTINITIALIZED:
		msg = "DIERR_NOTINITIALIZED: This object has not been initialized.";
		break;
	case DIERR_INPUTLOST:
		msg = "DIERR_INPUTLOST: Access to the input device has been lost. It must be reacquired.";
		break;
	case DIERR_INVALIDPARAM:
		msg = "DIERR_INVALIDPARAM: An invalid parameter was passed to the returning function, or the object was not in a state that permitted the function to be called. This value is equal to the E_INVALIDARG standard COM return value.";
		break;
	case DIERR_BADDRIVERVER:
		msg = "DIERR_BADDRIVERVER: The object could not be created due to an incompatible driver version or mismatched or incomplete driver components.";
		break;
	case DIERR_ACQUIRED:
		msg = "DIERR_ACQUIRED: The operation cannot be performed while the device is acquired.";
		break;
	case DIERR_OLDDIRECTINPUTVERSION:
		msg = "DIERR_OLDDIRECTINPUTVERSION: The application requires a newer version of DirectInput.";
		break;
	case DIERR_BETADIRECTINPUTVERSION:
		msg = "DIERR_BETADIRECTINPUTVERSION: The application was written for an unsupported prerelease version of DirectInput.";
		break;
	case DIERR_ALREADYINITIALIZED:
		msg = "DIERR_ALREADYINITIALIZED: This object is already initialized.";
		break;
	default:
		msg = "Unknown";
		break;
	}

	DXERR_printf("DI Error: [%s], line %d: %s (%08x)\r\n", file, line, msg, error);
#endif
}

// @Ok
// @Matching
void displayDSError(long error, char* file, i32 line)
{
#ifdef _WIN32
	char* msg;

	switch (error)
	{
	case DS_OK:
		msg = "DS_OK: The method succeeded.";
		break;
	case DS_NO_VIRTUALIZATION:
		msg = "DS_NO_VIRTUALIZATION: The buffer was created, but another 3-D algorithm was substituted.";
		break;
	case DS_INCOMPLETE:
		msg = "DS_INCOMPLETE: The method succeeded, but not all the optional effects were obtained.";
		break;
	case DSERR_ACCESSDENIED:
		msg = "DSERR_ACCESSDENIED: The request failed because access was denied.";
		break;
	case DSERR_ALLOCATED:
		msg = "DSERR_ALLOCATED: The request failed because resources, such as a priority level, were already in use by another caller.";
		break;
	case DSERR_ALREADYINITIALIZED:
		msg = "DSERR_ALREADYINITIALIZED: The object is already initialized.";
		break;
	case DSERR_BADFORMAT:
		msg = "DSERR_BADFORMAT: The specified wave format is not supported.";
		break;
	case DSERR_BUFFERLOST:
		msg = "DSERR_BUFFERLOST: The buffer memory has been lost and must be restored.";
		break;
	case DSERR_BUFFERTOOSMALL:
		msg = "DSERR_BUFFERTOOSMALL: The buffer size is not great enough to enable effects processing.";
		break;
	case DSERR_CONTROLUNAVAIL:
		msg = "DSERR_CONTROLUNAVAIL: The buffer control (volume, pan, and so on) requested by the caller is not available.";
		break;
	case DSERR_DS8_REQUIRED:
		msg = "DSERR_DS8_REQUIRED: A DirectSound object of class CLSID_DirectSound8 or later is required for the requested functionality. For more information, see IDirectSound8.";
		break;
	case DSERR_GENERIC:
		msg = "DSERR_GENERIC: An undetermined error occurred inside the DirectSound subsystem.";
		break;
	case DSERR_INVALIDCALL:
		msg = "DSERR_INVALIDCALL: This function is not valid for the current state of this object.";
		break;
	case DSERR_INVALIDPARAM:
		msg = "DSERR_INVALIDPARAM: An invalid parameter was passed to the returning function.";
		break;
	case DSERR_NOAGGREGATION:
		msg = "DSERR_NOAGGREGATION: The object does not support aggregation.";
		break;
	case DSERR_NODRIVER:
		msg = "DSERR_NODRIVER: No sound driver is available for use, or the given GUID is not a valid DirectSound device ID.";
		break;
	case DSERR_NOINTERFACE:
		msg = "DSERR_NOINTERFACE: The requested COM interface is not available.";
		break;
	case DSERR_OBJECTNOTFOUND:
		msg = "DSERR_OBJECTNOTFOUND: The requested object was not found.";
		break;
	case DSERR_OTHERAPPHASPRIO:
		msg = "DSERR_OTHERAPPHASPRIO: Another application has a higher priority level, preventing this call from succeeding.";
		break;
	case DSERR_OUTOFMEMORY:
		msg = "DSERR_OUTOFMEMORY: The DirectSound subsystem could not allocate sufficient memory to complete the caller's request.";
		break;
	case DSERR_PRIOLEVELNEEDED:
		msg = "DSERR_PRIOLEVELNEEDED: The caller does not have the priority level required for the function to succeed.";
		break;
	case DSERR_UNINITIALIZED:
		msg = "DSERR_UNINITIALIZED: The IDirectSound8::Initialize method has not been called or has not been called successfully before other methods were called.";
		break;
	case DSERR_UNSUPPORTED:
		msg = "Unknown";
		break;
	default:
		msg = "Unknown";
		break;
	}

	DXERR_printf("DS Error: [%s], line %d: %s (%08x)\r\n", file, line, msg, error);
#endif
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
	HRESULT hr = lpDD->EnumDisplayModes(0, &v123, &gDisplayModeContext, enumerateModesCB);
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

// @Ok
// @Note: windows and powerpc versions are diff
INLINE char* getNextNumber(
		char *a1,
		i32 *a2)
{
	while (*a1 <= ' ')
	{
		a1++;
	}

	char *start = a1;

	for (char cur = *a1; cur > ' '; a1++)
	{
		DoAssert(cur >= '0' && cur <= '9', "found non-digit when reading a decimal number!");
		cur = a1[1];
	}
	
	/*
	while (1)
	{
		orig = *a1;

		if (*a1 <= ' ')
		{
			break;
		}

		//DoAssert(orig >= '0' && orig <= '9', "found non-digit when reading a decimal number!");
		a1++;
	}
	*/

	char bkup = *a1;
	*a1 = 0;
	*a2 = strtol(start, 0, 10);
	*a1 = bkup;

	return a1;
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
	memset(&gDisplayModeContext, 0, sizeof(gDisplayModeContext));
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

	VALIDATE_SIZE(gDisplayModeContext, 8004);
	VALIDATE_SIZE(DXVideoModeContext, 0x1F44);

	VALIDATE(DXVideoModeContext, mNumEntries, 0x0);
	VALIDATE(DXVideoModeContext, mSurfaces, 0x4);
	VALIDATE(DXVideoModeContext, mFlags, 0x1F04);

	VALIDATE_SIZE(DDSURFACEDESC2, 0x7C);
	VALIDATE(DDSURFACEDESC2, dwDepth, 0x14);
	VALIDATE(DDSURFACEDESC2, ddpfPixelFormat.dwRGBBitCount, 0x54);
	VALIDATE(DDSURFACEDESC2, lpSurface, 0x24);
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

void validate_SPushOffset(void)
{
	VALIDATE_SIZE(SPushOffset, 0x8);

	VALIDATE(SPushOffset, field_0, 0x0);
	VALIDATE(SPushOffset, field_4, 0x4);
	VALIDATE(SPushOffset, field_6, 0x6);
}
