#include "DXsound.h"
#include "DXinit.h"
#include "SpideyDX.h"
#include "validate.h"

#include <cstring>

EXPORT LPDIRECTINPUTDEVICEA g_pKeyboard;
EXPORT LPDIRECTINPUTDEVICEA g_pMouse;
EXPORT i32 gControllerRelated;
EXPORT i32 gForceFeedbackRelated;

IDirectInputA* gDirectInputRelated;
EXPORT i32 gNumControllerButtons;
EXPORT u8 gKeyState[0x100];
EXPORT u8 gControllerButtonState[0x20];
EXPORT u8 gMouseButtonState[3];

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


EXPORT IDirectInputA* g_pDI;
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
void DXINPUT_Initialize(IDirectInputA* a1, HWND a2)
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

// @SMALLTODO
i32 DXINPUT_PollKeyboard(void)
{
    printf("DXINPUT_PollKeyboard(void)");
	return 0x23082024;
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
		DXERR_printf("Other application has priority when attempting to acquire mouse\n");
	}
	else
	{
		DI_ERROR_LOG_AND_QUIT(hr);
	}
	
	return 1;
}

// @Ok
i32 DXINPUT_SetupMouse(i32 exclusive)
{
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

// @SMALLTODO
void DXPOLY_BeginScene(void)
{
    printf("DXPOLY_BeginScene(void)");
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

// @SMALLTODO
void DXPOLY_EndScene(bool)
{
    printf("DXPOLY_EndScene(bool)");
}

// @SMALLTODO
void DXPOLY_Flip(void)
{
    printf("DXPOLY_Flip(void)");
}

// @SMALLTODO
void DXPOLY_Init(u32)
{
    printf("DXPOLY_Init(u32)");
}

// @MEDIUMTODO
void DXPOLY_SaveScreen(void)
{
    printf("DXPOLY_SaveScreen(void)");
}

// @MEDIUMTODO
void DXPOLY_SaveSurfaceAsBMP(char *,void *,i32,i32,i32,_DDPIXELFORMAT *,bool)
{
    printf("DXPOLY_SaveSurfaceAsBMP(char *,void *,i32,i32,i32,_DDPIXELFORMAT *,bool)");
}

// @SMALLTODO
void DXPOLY_SetBackgroundColor(u32)
{
    printf("DXPOLY_SetBackgroundColor(u32)");
}

// @MEDIUMTODO
void DXPOLY_SetBlendMode(u32)
{
    printf("DXPOLY_SetBlendMode(u32)");
}

// @SMALLTODO
void DXPOLY_SetDepthCompare(u32)
{
    printf("DXPOLY_SetDepthCompare(u32)");
}

// @SMALLTODO
void DXPOLY_SetDepthWriting(bool)
{
    printf("DXPOLY_SetDepthWriting(bool)");
}

// @SMALLTODO
void DXPOLY_SetFilterMode(u32)
{
    printf("DXPOLY_SetFilterMode(u32)");
}

// @SMALLTODO
void DXPOLY_SetHUDOffset(i32)
{
    printf("DXPOLY_SetHUDOffset(i32)");
}

// @SMALLTODO
void DXPOLY_SetOutlineColor(u32)
{
    printf("DXPOLY_SetOutlineColor(u32)");
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
	VALIDATE_SIZE(_GUID, 0x16);
}
