#include "DXsound.h"
#include "DXinit.h"
#include "SpideyDX.h"
#include "validate.h"

#include <cstring>

EXPORT float flt_56817C = 10.0f;
EXPORT i32 dword_568184;
EXPORT i32 gSceneBuffer[0x1001];
EXPORT u8 gInBeginScene;
EXPORT i32 gScreenshotNumber;
EXPORT u32 gCurrentBlendMode;
EXPORT char* gD3DDepthCompareNames[9] =
{
	"",
    "D3DCMP_NEVER",
    "D3DCMP_LESS",
    "D3DCMP_EQUAL",
    "D3DCMP_LESSEQUAL",
    "D3DCMP_GREATER",
    "D3DCMP_NOTEQUAL",
    "D3DCMP_GREATEREQUAL",
    "D3DCMP_ALWAYS",
};

EXPORT D3DVALUE gFlDepthCompare = 1.0f;
EXPORT u32 gDepthCompareIndex;
EXPORT u8 gDepthBuffering;
EXPORT DWORD gMagFilters[2] = { 1, 2 };
EXPORT DWORD gMinFilters[2] = { 1, 2 };

EXPORT u32 gCurrentFilterIndex;

EXPORT bool gDepthWriting;
EXPORT bool gDxPolyRelated;

EXPORT i32 gHudOffset;
EXPORT float gFlHudOffset = 1.0f;

EXPORT D3DCOLOR gDxPolyBackgroundColor = 0x0FF000000;
EXPORT u32 gDxOutlineColor = 0x0FF00FF00;

EXPORT LPDIRECTINPUTDEVICE8A g_pKeyboard;
EXPORT LPDIRECTINPUTDEVICE8A g_pMouse;
EXPORT i32 gControllerRelated;
EXPORT i32 gForceFeedbackRelated;

EXPORT i32 gNumControllerButtons;
EXPORT u8 gKeyState[0x100];
EXPORT u8 gControllerButtonState[0x20];
EXPORT u8 gMouseButtonState[3];

EXPORT char* gDxKeyNames[0x100] = 
{
	"NULL",
	"ESC",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"0",
	"DASH",
	"EQUAL",
	"BACK",
	"TAB",
	"Q",
	"W",
	"E",
	"R",
	"T",
	"Y",
	"U",
	"I",
	"O",
	"P",
	"LBRACE",
	"RBRACE",
	"RETURN",
	"LCTRL",
	"A",
	"S",
	"D",
	"F",
	"G",
	"H",
	"J",
	"K",
	"L",
	"COLON",
	"QUOTE",
	"TILDE",
	"LSHIFT",
	"BKSLASH",
	"Z",
	"X",
	"C",
	"V",
	"B",
	"N",
	"M",
	"COMMA",
	"PERIOD",
	"SLASH",
	"RSHIFT",
	"STAR",
	"LALT",
	"SPACE",
	"CAPSLOCK",
	"F1",
	"F2",
	"F3",
	"F4",
	"F5",
	"F6",
	"F7",
	"F8",
	"F9",
	"F10",
	"NUMLOCK",
	"SCROLL",
	"PAD7",
	"PAD8",
	"PAD9",
	"PADMINUS",
	"PAD4",
	"PAD5",
	"PAD6",
	"PADPLUS",
	"PAD1",
	"PAD2",
	"PAD3",
	"PAD0",
	"PadDel",
	".54.",
	".55.",
	"OEM_102",
	"F11",
	"F12",
	".59.",
	".5A.",
	".5B.",
	".5C.",
	".5D.",
	".5E.",
	".5F.",
	".60",
	".61.",
	".62.",
	".63.",
	"F13",
	"F14",
	"F15",
	".64.",
	".68",
	".69.",
	".6A.",
	".6B.",
	".6C.",
	".6D.",
	".6E.",
	".6F.",
	"KANA",
	".71.",
	".72.",
	"ABNT_C1",
	".74.",
	".75.",
	".76.",
	".77.",
	".78.",
	".79.",
	"CONVERT",
	".7B.",
	".7C.",
	".7D.",
	"NOCONVERT",
	".7F.",
	".80.",
	".81.",
	".82.",
	"YEN",
	"ABNT_C2",
	".85.",
	".86.",
	".87.",
	".88.",
	".89.",
	".8A.",
	".8B.",
	".8C.",
	"PADEQ",
	".8E.",
	".8F.",
	"PREVTRK",
	"AT",
	"COLON",
	"UNDERLINE",
	"KANJI",
	"STOP",
	"AX",
	".97.",
	".98.",
	"NEXTTRK",
	".9A.",
	".9B.",
	"PADENTR",
	"RCTRL",
	".9E.",
	"MUTE",
	"CALC",
	"PLAYPAUSE",
	".A2.",
	"MEDIASTOP",
	".A4.",
	".A5.",
	".A6.",
	".A7.",
	".A8.",
	".A9.",
	"VOLDOWN",
	".AB.",
	".AC.",
	".AD.",
	".AE.",
	"VOLUMEUP",
	".B0.",
	".B1.",
	"WEBHOME",
	"PADCOMMA",
	".B4.",
	"PADSLASH",
	".B6.",
	"SYSRQ",
	"RALT",
	".B0.",
	".BA.",
	".BB.",
	".BC.",
	".BD.",
	".BE.",
	".BF.",
	".C0.",
	".C1.",
	".C2.",
	".C3.",
	".C4.",
	"PAUSE",
	".C6.",
	"HOME",
	"UP",
	"PGUP",
	".CA.",
	"LEFT",
	".CC.",
	"RIGHT",
	".CE.",
	"END",
	"DOWN",
	"PGDOWN",
	"INS",
	"DEL",
	".D4.",
	".D5.",
	".D6.",
	".D7.",
	".D8.",
	".D9.",
	".DA.",
	"LWIN",
	"RWIN",
	"APPS",
	".DE.",
	"POWER",
	"SLEEP",
	".E1.",
	".E2.",
	".E3.",
	"WAKE",
	"WEBSEARCH",
	"WEBFAV",
	"WEBREF",
	".E8.",
	"WEBSTOP",
	"WEBFWD",
	"WEBBACK",
	"MYCOMPUTER",
	"MAIL",
	"MEDIASLCT",
	".EF.",
	".F0.",
	".F1.",
	".F2.",
	".F3.",
	".F4.",
	".F5.",
	".F6.",
	".F7.",
	".F8.",
	".F9.",
	".FA.",
	".FB.",
	".FC.",
	".FD.",
	".FE.",
	".FF.",
};


LPDIRECTINPUT8 g_pDI;
EXPORT HWND gDxInputHwnd;
EXPORT u8 gDxInputRelated;

// @Ok
// @Matching
void DXINPUT_GetKeyName(u8 key, char* dstName)
{
	strcpy(dstName, gDxKeyNames[key]);
}

// @Ok
// @Matching
u8 DXINPUT_GetControllerButtonState(u8 button)
{
	return gControllerButtonState[button];
}

// @Ok
// @Matching
u8 DXINPUT_GetKeyState(u8 key)
{
	return gKeyState[key];
}

// @Ok
// @Matching
u8 DXINPUT_GetMouseButtonState(u8 button)
{
	return gMouseButtonState[button];
}

// @Ok
// @Matching
i32 DXINPUT_GetNumControllerButtons(void)
{
	return gNumControllerButtons;
}

// @Ok
// @Matching
void DXINPUT_Initialize(LPDIRECTINPUT8 a1, HWND a2)
{
	g_pDI = a1;
	gDxInputHwnd = a2;

	g_pKeyboard = 0;
	g_pMouse = 0;
	gControllerRelated = 0;
	gForceFeedbackRelated = 0;
	
	memset(gKeyState, 0, sizeof(gKeyState));
	memset(gMouseButtonState, 0, sizeof(gMouseButtonState));
	memset(gControllerButtonState, 0, sizeof(gControllerButtonState));

	gDxInputRelated = 0;
	gNumControllerButtons = 0;
}

// @MEDIUMTODO
i32 DXINPUT_PollController(i32 *,i32 *,i32 *)
{
    printf("DXINPUT_PollController(i32 *,i32 *,i32 *)");
	return 0x24082024;
}

// @Ok
i32 DXINPUT_PollKeyboard(void)
{
#ifdef _WIN32
	DWORD dwElements = 16;
	DIDEVICEOBJECTDATA didod[16]; 
	memset(didod, 0, sizeof(didod));

	if (!g_pKeyboard)
	{
		return -1;
	}

	if (g_pKeyboard->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), didod, &dwElements, 0) == DIERR_INPUTLOST)
	{
		HRESULT hr = g_pKeyboard->Acquire();
		if (hr == DIERR_OTHERAPPHASPRIO)
		{
			DXERR_printf("Other application has priority when attempting to acquire keyboard\n");
			return -1;
		}

		DI_ERROR_LOG_AND_QUIT(hr);
		if (g_pKeyboard->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), didod, &dwElements, 0) == DIERR_NOTACQUIRED)
		{
			return -1;
		}
	}

	for (i32 i = 0; i < 256; i++)
		gKeyState[i] &= ~0x80u;

	for (DWORD k = 0; k < dwElements; k++)
	{
		if (didod[k].dwData & 0x80)
		{
			gKeyState[didod[k].dwOfs] = -1;
		}
		else
		{
			gKeyState[didod[k].dwOfs] = 0x80;
		}
	}

	return dwElements;
#endif
	return 0;
}

// @MEDIUMTODO
i32 DXINPUT_PollMouse(i32 *,i32 *)
{
    printf("DXINPUT_PollMouse(i32 *,i32 *)");
	return 0x23082024;
}

// @SMALLTODO
void DXINPUT_Release(void)
{
    printf("DXINPUT_Release(void)");
}

// @Ok
// @Matching
void DXINPUT_SetKeyState(u8 key, u8 state)
{
	gKeyState[key] = state;
}

// @Ok
// @Matching
void DXINPUT_SetMouseButtonState(u8 button, u8 state)
{
	gMouseButtonState[button] = state;
}

// @MEDIUMTODO
i32 DXINPUT_SetupController(void)
{
    printf("DXINPUT_SetupController(void)");
	return 0x23082024;
}

// @MEDIUMTODO
i32 DXINPUT_SetupForceFeedbackSineEffect(i32,float)
{
    printf("DXINPUT_SetupForceFeedbackSineEffect(i32,float)");
	return 0x24082024;
}

// @Ok
i32 DXINPUT_SetupKeyboard(i32 exclusive, i32 buffered)
{
#ifdef _WIN32
	HRESULT hr = g_pDI->CreateDevice(GUID_SysKeyboard, &g_pKeyboard, NULL);
	DI_ERROR_LOG_AND_QUIT(hr);

	hr = g_pKeyboard->SetCooperativeLevel(gDxInputHwnd,
			exclusive ? 
				DISCL_NOWINKEY | DISCL_FOREGROUND | DISCL_EXCLUSIVE :
				DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	DI_ERROR_LOG_AND_QUIT(hr);

	hr = g_pKeyboard->SetDataFormat(&c_dfDIKeyboard);
	DI_ERROR_LOG_AND_QUIT(hr);

	if (buffered)
	{
		DIPROPDWORD v12;
		v12.diph.dwHeaderSize = 16;
		v12.dwData = 16;
		v12.diph.dwSize = 20;
		v12.diph.dwObj = 0;
		v12.diph.dwHow = 0;

		hr = g_pKeyboard->SetProperty(DIPROP_BUFFERSIZE, &v12.diph);
		DI_ERROR_LOG_AND_QUIT(hr);
	}

	hr = g_pKeyboard->Acquire();
	if (hr == DIERR_OTHERAPPHASPRIO)
	{
		DXERR_printf("Other application has priority when attempting to acquire keyboard\n");
	}
	else
	{
		DI_ERROR_LOG_AND_QUIT(hr);
	}
#endif
	
	return 1;
}

// @Ok
i32 DXINPUT_SetupMouse(i32 exclusive)
{
#ifdef _WIN32
	HRESULT hr = g_pDI->CreateDevice(GUID_SysMouse, &g_pMouse, NULL);
	DI_ERROR_LOG_AND_QUIT(hr);

	DIPROPDWORD v12;
	v12.diph.dwHeaderSize = 16;
	v12.dwData = 16;
	v12.diph.dwSize = 20;
	v12.diph.dwObj = 0;
	v12.diph.dwHow = 0;

	hr = g_pMouse->SetProperty(DIPROP_BUFFERSIZE, &v12.diph);
	DI_ERROR_LOG_AND_QUIT(hr);

	hr = g_pMouse->SetDataFormat(&c_dfDIMouse);
	DI_ERROR_LOG_AND_QUIT(hr);

	hr = g_pMouse->SetCooperativeLevel(gDxInputHwnd,
			exclusive ? 
				DISCL_FOREGROUND | DISCL_EXCLUSIVE :
				DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	DI_ERROR_LOG_AND_QUIT(hr);

	hr = g_pMouse->Acquire();
	if (hr == DIERR_OTHERAPPHASPRIO)
	{
		DXERR_printf("Other application has priority when attempting to acquire mouse\n");
	}
	else
	{
		DI_ERROR_LOG_AND_QUIT(hr);
	}
#endif
	
	return 1;
}

// @SMALLTODO
i32 DXINPUT_StartForceFeedbackEffect(void)
{
    printf("DXINPUT_StartForceFeedbackEffect(void)");
	return 0x23082024;
}

// @SMALLTODO
i32 DXINPUT_StopForceFeedbackEffect(void)
{
    printf("DXINPUT_StopForceFeedbackEffect(void)");
	return 0x23082024;
}


// @MEDIUMTODO
// lowgraphics stuff
EXPORT void gsub_514DB0(LPVOID,
			i32,
			i32,
			LONG,
			u32,
			float,
			i32,
			float,
			float)
{
	printf("void gsub_514DB0(LPVOID,");
}

// @Ok
void DXPOLY_BeginScene(void)
{
	print_if_false(gInBeginScene == 0, "nested BeginScene() calls!");
	memset(gSceneBuffer, 0, sizeof(gSceneBuffer));
	gInBeginScene = 1;

	if (gLowGraphics)
	{
		DDSURFACEDESC2 v13;
		memset(&v13, 0, sizeof(v13));
		v13.dwSize = sizeof(v13);

		HRESULT hr = g_pDDS_Scene->Lock(0, &v13, 2048, 0);
		D3D_ERROR_LOG_AND_QUIT(hr);

		i32 width, height;
		DXINIT_GetCurrentResolution(&width, &height);
		float v9 = height;
		float v8 = v9 * 0.5f;
		float v10 = width;
		float v7 = v10 * 0.5f;
		gsub_514DB0(
			v13.lpSurface,
			width,
			height,
			v13.lPitch,
			(gDxPolyBackgroundColor & 0xF8 | ((gDxPolyBackgroundColor & 0xFC00 | (gDxPolyBackgroundColor >> 3) & 0x1F0000) >> 2)) >> 3,
			flt_56817C,
			dword_568184,
			v7,
			v8);
	}
	else
	{
		HRESULT hr = g_D3DDevice7->BeginScene();
		D3D_ERROR_LOG_AND_QUIT(hr);

		if (gDxPolyRelated)
			hr = g_D3DDevice7->Clear(0, 0, 3, gDxPolyBackgroundColor, gFlDepthCompare, 0);
		else
			hr = g_D3DDevice7->Clear(0, 0, 1, gDxPolyBackgroundColor, gFlDepthCompare, 0);
		D3D_ERROR_LOG_AND_QUIT(hr);
	}
}

// @MEDIUMTODO
void DXPOLY_DrawPoly(_DXPOLY *,i32,i32,float)
{
    printf("DXPOLY_DrawPoly(_DXPOLY *,i32,i32,float)");
}

// @SMALLTODO
void DXPOLY_EnableTexAlpha(bool)
{
    printf("DXPOLY_EnableTexAlpha(bool)");
}

// @MEDIUMTODO
// low graphics related and uses mmx :O
void gsub_514ED0(void)
{
	printf("void gsub_514ED0(void)");
}

// @Ok
void DXPOLY_EndScene(bool a1)
{
	if (gInBeginScene)
	{
		gInBeginScene = 0;
		renderScene();
		if (gLowGraphics)
		{
			gsub_514ED0();
			g_pDDS_Scene->Unlock(0);
		}
		else
		{
			HRESULT hr = g_D3DDevice7->EndScene();
			D3D_ERROR_LOG_AND_QUIT(hr);
		}

		if (a1)
		{
			DXPOLY_Flip();
		}
	}
}

// @Ok
// @Matching
void DXPOLY_Flip(void)
{
#ifdef _WIN32
	if (gDxOptionRelated)
	{
		DDBLTFX v4;
		memset(&v4, 0, sizeof(v4));
		v4.dwSize = sizeof(v4);

		HRESULT hr = g_pDDS_SaveScreen->Blt(&gRect, g_pDDS_Scene, 0, 0x1000000, &v4);
		D3D_ERROR_LOG_AND_QUIT(hr);
	}
	else
	{
		HRESULT hr = g_pDDS_SaveScreen->Flip(0, 1);
		D3D_ERROR_LOG_AND_QUIT(hr);
	}
#endif
}

EXPORT u8 byte_6B7A80 = 0;
EXPORT u8 byte_6B7A88 = 0;

EXPORT u32 gFogStart;
EXPORT u32 gFogEnd;
EXPORT u32 gFogColor;
EXPORT u32 dword_6B7A8C;
EXPORT u32 gAddressU;
EXPORT u32 gAddressV;
EXPORT u32 dword_6B7A74;

u32 dword_568F98;
u32 dword_568F94;
u32 dword_568F90;
u32 dword_2E096D4;

// @Ok
EXPORT void gsub_515270(void)
{
	dword_568F98 = 0;
	dword_568F94 = 0;
	dword_568F90 = 0;
	dword_2E096D4 = 0;
	gLowGraphicsRelated = 0;
}

// @NotOk
// fix names for enums
void DXPOLY_Init(u32 a1)
{
	if ( gLowGraphics )
		gsub_515270();

	gDxPolyRelated = (a1 & 2) != 0;
	gDepthCompareIndex = 4;
	byte_6B7A80 = 0;
	gDepthBuffering = (a1 & 2) != 0;
	gDepthWriting = (a1 & 2) != 0;
	byte_6B7A88 = 0;
	gCurrentFilterIndex = 1;
	gFogStart = 0x3DCCCCCD;
	gFogEnd = 0x3F7D70A4;
	gFogColor = 0xFFFFFF;
	dword_6B7A8C = 3;
	gAddressU = 3;
	gAddressV = 3;
	gCurrentBlendMode = 0;
	dword_6B7A74 = 0;

#ifdef _WIN32
	g_D3DDevice7->SetRenderState(D3DRENDERSTATE_ANTIALIAS, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)4, 1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)7, gDxPolyRelated != 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)8, 3);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)9, 2);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)10, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)14, 1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)15, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)16, 1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)19, 2);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)20, 1);
	if ( gLowGraphics )
		g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)22, 1);
	else
		g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)22, 3);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)23, 4);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)24, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)25, 8);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)26, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)27, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)28, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)29, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)33, 0);
	g_D3DDevice7->SetRenderState(D3DRENDERSTATE_FOGCOLOR, gFogColor);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)35, 0);
	g_D3DDevice7->SetRenderState(D3DRENDERSTATE_FOGSTART, gFogStart);
	g_D3DDevice7->SetRenderState(D3DRENDERSTATE_FOGEND, gFogEnd);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)38, 1065353216);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)40, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)41, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)47, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)48, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)52, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)53, 1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)54, 1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)55, 1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)56, 8);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)57, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)58, -1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)59, -1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)60, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)128, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)129, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)130, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)131, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)132, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)133, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)134, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)135, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)136, 1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)137, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)138, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)139, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)140, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)141, 1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)142, 1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)143, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)144, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)145, 1);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)146, 2);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)147, 2);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)148, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)151, 0);
	g_D3DDevice7->SetRenderState((D3DRENDERSTATETYPE)152, 0);

	g_D3DDevice7->SetTextureStageState(0, (D3DTEXTURESTAGESTATETYPE)1, 4);
	g_D3DDevice7->SetTextureStageState(0, (D3DTEXTURESTAGESTATETYPE)2, 2);
	g_D3DDevice7->SetTextureStageState(0, (D3DTEXTURESTAGESTATETYPE)3, 0);
	g_D3DDevice7->SetTextureStageState(0, (D3DTEXTURESTAGESTATETYPE)4, 4);
	g_D3DDevice7->SetTextureStageState(0, (D3DTEXTURESTAGESTATETYPE)5, 2);
	g_D3DDevice7->SetTextureStageState(0, (D3DTEXTURESTAGESTATETYPE)6, 0);
	g_D3DDevice7->SetTextureStageState(0, D3DTSS_ADDRESSU, gAddressU);
	g_D3DDevice7->SetTextureStageState(0, D3DTSS_ADDRESSV, gAddressV);
	g_D3DDevice7->SetTextureStageState(0, (D3DTEXTURESTAGESTATETYPE)16, gMagFilters[gCurrentFilterIndex]);
	g_D3DDevice7->SetTextureStageState(0, (D3DTEXTURESTAGESTATETYPE)17, gMinFilters[gCurrentFilterIndex]);
	g_D3DDevice7->SetTextureStageState(0, (D3DTEXTURESTAGESTATETYPE)18, 1);
#endif
}

// @Ok
// @Matching
void DXPOLY_SaveScreen(void)
{
#ifdef _WIN32
	char v7[32];
	sprintf(v7, "scrn%4.4i.bmp", ++gScreenshotNumber);

	DDSURFACEDESC2 v6;
	memset(&v6, 0, sizeof(v6));
	v6.dwSize = sizeof(v6);

	if (gDxOptionRelated)
	{
		u32 width, height;
		DXINIT_GetCurrentResolution(&width, &height);

		HRESULT hr = g_pDDS_SaveScreen->Lock(&gRect, &v6, 16, 0);
		D3D_ERROR_LOG_AND_QUIT(hr);

		DXPOLY_SaveSurfaceAsBMP(
				v7,
				v6.lpSurface,
				width,
				height,
				v6.lPitch,
				&v6.ddpfPixelFormat,
				false);
		g_pDDS_SaveScreen->Unlock(&gRect);
	}
	else
	{
		HRESULT hr = g_pDDS_SaveScreen->Lock(0, &v6, 16, 0);
		D3D_ERROR_LOG_AND_QUIT(hr);

		DXPOLY_SaveSurfaceAsBMP(
				v7,
				v6.lpSurface,
				v6.dwWidth,
				v6.dwHeight,
				v6.lPitch,
				&v6.ddpfPixelFormat,
				false);
		g_pDDS_SaveScreen->Unlock(0);
	}

	DXERR_printf("Saved Screenshot %i.\r\n", gScreenshotNumber);
#endif
}

// @MEDIUMTODO
void DXPOLY_SaveSurfaceAsBMP(char *,void *,i32,i32,i32,_DDPIXELFORMAT *,bool)
{
    printf("DXPOLY_SaveSurfaceAsBMP(char *,void *,i32,i32,i32,_DDPIXELFORMAT *,bool)");
}

// @Ok
// @Matching
void DXPOLY_SetBackgroundColor(u32 color)
{
	gDxPolyBackgroundColor = color;
}

// @Ok
void DXPOLY_SetBlendMode(u32 a1)
{

#ifdef _WIN32
	u32 newBlendMode = a1;
	if (gCurrentBlendMode != a1)
	{
		switch(a1)
		{
			default:
				DXERR_printf("ERROR: Invalid blend mode passed to DXPOLY_SetBlendMode(): %lu\r\n", a1);
				newBlendMode = 0;
			case 0:
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_SRCBLEND, 2);
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_DESTBLEND, 1);
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 0);
				DXPOLY_SetDepthWriting(1);
				break;
			case 3:
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_SRCBLEND, 1);
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_DESTBLEND, 4);
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 1);
				DXPOLY_SetDepthWriting(0);
				break;
			case 1:
			case 5:
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_SRCBLEND, 5);
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_DESTBLEND, 6);
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 1);
				DXPOLY_SetDepthWriting(0);
				break;
			case 2:
			case 4:
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_SRCBLEND, 5);
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_DESTBLEND, 2);
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, 1);
				DXPOLY_SetDepthWriting(0);
				break;

		}

		gCurrentBlendMode = newBlendMode;
	}
#endif
}

// @Ok
// @Matching
void DXPOLY_SetDepthCompare(u32 a1)
{
#ifdef _WIN32
	if (gDxPolyRelated)
	{
		if (!a1)
		{
			if (gDepthWriting)
			{
				g_D3DDevice7->SetRenderState(D3DRENDERSTATE_ZENABLE, 0);
				gDepthWriting = 0;
				DXERR_printf("Depth Buffering Disabled.\r\n");
			}

			return;
		}

		if (!gDepthWriting)
		{
			g_D3DDevice7->SetRenderState(D3DRENDERSTATE_ZENABLE, 1);
			gDepthWriting = 1;
			DXERR_printf("Depth Buffering Enabled.\r\n");
		}

		if (a1 != gDepthCompareIndex)
		{
			g_D3DDevice7->SetRenderState(D3DRENDERSTATE_ZFUNC, a1);
			char* status = gD3DDepthCompareNames[a1];
			gDepthCompareIndex = a1;

			DXERR_printf("Depth Compare = %s\r\n", status);
			if ( a1 == 5 || (gFlDepthCompare = 1.0f, a1 == 7) )
				gFlDepthCompare = 0.0f;
		}
	}
#endif
}

// @Ok
// @Matching
INLINE void DXPOLY_SetDepthWriting(bool a1)
{
#ifdef _WIN32
	if (gDxPolyRelated && a1 != gDepthWriting)
	{
		g_D3DDevice7->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE, a1);
		gDepthWriting = a1;

		char *status = "Enabled";
		if (!a1)
			status = "Disabled";

		DXERR_printf("Depth Buffer Writes %s.\r\n", status);
	}
#endif
}

// @Ok
// @Matching
void DXPOLY_SetFilterMode(u32 filterIndex)
{
#ifdef _WIN32
	if (filterIndex != gCurrentFilterIndex)
	{
		g_D3DDevice7->SetTextureStageState(0, D3DTSS_MAGFILTER, gMagFilters[filterIndex]);
		g_D3DDevice7->SetTextureStageState(0, D3DTSS_MINFILTER, gMinFilters[filterIndex]);

		gCurrentFilterIndex = filterIndex;

		char *status = "PointSample";
		if (filterIndex)
			status = "Bilinear";
		DXERR_printf("Filter %s.\r\n", status);
	}
#endif
}

// @Ok
// @Matching
void DXPOLY_SetHUDOffset(i32 a1)
{
	gHudOffset = a1;
	float v1 = (float)(4096 - a1);
	gFlHudOffset = v1 / 4096.0f;
}

// @Ok
// @Matching
void DXPOLY_SetOutlineColor(u32 a1)
{
	gDxOutlineColor = a1;
}

// @SMALLTODO
void DXPOLY_SetTexture(IDirectDrawSurface7 *)
{
    printf("DXPOLY_SetTexture(IDirectDrawSurface7 *)");
}

// @SMALLTODO
void DXSOUND_Close(i32)
{
    printf("DXSOUND_Close(i32)");
}

// @MEDIUMTODO
void DXSOUND_CreateDSBuffer(char *,i32)
{
    printf("DXSOUND_CreateDSBuffer(char *,i32)");
}

// @SMALLTODO
void DXSOUND_Init(void)
{
    printf("DXSOUND_Init(void)");
}

// @SMALLTODO
void DXSOUND_IsPlaying(i32)
{
    printf("DXSOUND_IsPlaying(i32)");
}

// @SMALLTODO
void DXSOUND_Load(char *)
{
    printf("DXSOUND_Load(char *)");
}

// @SMALLTODO
void DXSOUND_Open(i32,i32,i32)
{
    printf("DXSOUND_Open(i32,i32,i32)");
}

// @SMALLTODO
void DXSOUND_Play(i32,i32)
{
    printf("DXSOUND_Play(i32,i32)");
}

// @SMALLTODO
void DXSOUND_SetPan(i32,i32)
{
    printf("DXSOUND_SetPan(i32,i32)");
}

// @SMALLTODO
void DXSOUND_SetPitch(i32,i32)
{
    printf("DXSOUND_SetPitch(i32,i32)");
}

// @SMALLTODO
void DXSOUND_SetVolume(i32,i32)
{
    printf("DXSOUND_SetVolume(i32,i32)");
}

// @SMALLTODO
void DXSOUND_ShutDown(void)
{
    printf("DXSOUND_ShutDown(void)");
}

// @SMALLTODO
void DXSOUND_Stop(i32)
{
    printf("DXSOUND_Stop(i32)");
}

// @SMALLTODO
void DXSOUND_Unload(char *,i32)
{
    printf("DXSOUND_Unload(char *,i32)");
}

// @SMALLTODO
void EnumControllersCallback(DIDEVICEINSTANCEA const *,void *)
{
    printf("EnumControllersCallback(DIDEVICEINSTANCEA const *,void *)");
}

// @SMALLTODO
void ParseWavHeader(char *,tWAVEFORMATEX **,long *,u8 **)
{
    printf("ParseWavHeader(char *,tWAVEFORMATEX **,long *,u8 **)");
}

// @MEDIUMTODO
void initialSettings(void)
{
    printf("initialSettings(void)");
}

// @MEDIUMTODO
void loadWAV(char *,tWAVEFORMATEX *,long *)
{
    printf("loadWAV(char *,tWAVEFORMATEX *,long *)");
}

// @SMALLTODO
void renderScene(void)
{
    printf("renderScene(void)");
}

// @SMALLTODO
void stateLog(char const *,...)
{
    printf("stateLog(char const *,...)");
}

void validate_DXsound(void)
{
	VALIDATE_SIZE(_GUID, 0x10);
}
