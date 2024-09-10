#include "SpideyDX.h"
#include "main.h"
#include "PCTimer.h"
#include "DXinit.h"

#include "stdarg.h"
#include <cstdio>
#include <cstring>

i32 gRenderTest;

i32 gGameResolutionX = 640;
i32 gGameResolutionY = 480;

u32 gDxResolutionX;
u32 gDxResolutionY;

u8 gMMXSupport;
u8 g3DAccelator = 1;

HWND gHwnd;

i32 gBrightnessRelated = 4;

EXPORT u8 gMissingCD;
EXPORT i32 gActive;

// @Ok
EXPORT u8 isMMX(void)
{
#ifdef _OLD_WINDOWS
	u32 flags;

	__asm
	{
		mov eax, 1
		cpuid
		mov [flags], edx
	};

	return (flags >> 23) & 1;
#else
	// @FIXME most processors have MMX so it shouldn't be a problem
	return 1;
#endif
}


// @SMALLTODO
void BuildTwiddleTable(void)
{
    printf("BuildTwiddleTable(void)");
}

// @SMALLTODO
void CalcUntwiddledPos(u32,u32,u32,u32)
{
    printf("CalcUntwiddledPos(u32,u32,u32,u32)");
}

// @SMALLTODO
void ComputeMaskShift(u32,u32,u32 *,u32 *)
{
    printf("ComputeMaskShift(u32,u32,u32 *,u32 *)");
}

// @SMALLTODO
void SPIDEYDX_DisplayDeviceSettings(char *)
{
    printf("SPIDEYDX_DisplayDeviceSettings(char *)");
}

// @MEDIUMTODO
void SPIDEYDX_LoadSettings(void)
{
    printf("SPIDEYDX_LoadSettings(void)");
}

// @MEDIUMTODO
void SPIDEYDX_SaveSettings(void)
{
    printf("SPIDEYDX_SaveSettings(void)");
}

// @SMALLTODO
void SPIDEYDX_Shutdown(void)
{
    printf("SPIDEYDX_Shutdown(void)");
}

// @Ok
LRESULT CALLBACK SpideyWndProc(
		HWND hWnd,
		UINT uMsg,
		WPARAM wParam,
		LPARAM lParam)
{
#ifdef _WIN32
	switch (uMsg)
	{
		case WM_KEYDOWN:
			switch (wParam)
			{
				case VK_TAB:
				case VK_SHIFT:
				case VK_CONTROL:
				case VK_LWIN:
				case VK_RWIN:
				case VK_APPS:
					return 0;
				case VK_F12:
					PostMessageA(hWnd, WM_CLOSE, 0, 0);
					return 0;
				default:
					return DefWindowProcA(hWnd, uMsg, wParam, lParam);
			}
			break;
		case WM_DESTROY:
			if (gMissingCD)
			{
				MessageBoxA(
					0,
					"Please insert the Spider-Man CD-ROM, select OK, and restart the game.",
					"Spider-Man Error",
					MB_TASKMODAL | MB_ICONEXCLAMATION);
			}
			PostQuitMessage(0);
			break;
		case WM_SIZE:
			break;
		case WM_ACTIVATE:
			gActive = wParam != WA_INACTIVE;
			break;
		case WM_CLOSE:
			DestroyWindow(hWnd);
			return DefWindowProcA(hWnd, uMsg, wParam, lParam);
		case WM_KEYUP:
		case WM_CHAR:
		case WM_DEADCHAR:
		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
		case WM_SYSCOMMAND:
		case WM_HOTKEY:
			break;
		default:
			return DefWindowProcA(hWnd, uMsg, wParam, lParam);
	}
#endif

	return 0;
}

// @Ok
// @Matching
INLINE i32 WinYield(void)
{
#ifdef _WIN32
	MSG msg;
	while (PeekMessageA(&msg, gHwnd, 0, 0, 0))
	{
		i32 bRet = GetMessageA(&msg, gHwnd, 0, 0);
		if (!bRet || bRet == -1)
		{
			return -1;
		}

		if (msg.message != 260 && msg.message != 261)
		{
			TranslateMessage(&msg);
			DispatchMessageA(&msg);
		}
	}
#endif

	return 117;
}

// @SMALLTODO
void debugSettings(void)
{
    printf("debugSettings(void)");
}

// @SMALLTODO
void mipmapOffset(u32,u32,float)
{
    printf("mipmapOffset(u32,u32,float)");
}

// @SMALLTODO
void parseCommandLine(char *)
{
    printf("parseCommandLine(char *)");
}

// @BIGTODO
// DRM stuff can ignore for now
EXPORT u8 gDrmShit(i32)
{
	printf("void gDrmShit(i32)");
	return 0;
}

// @Ok
void DXERR_printf(const char* format, ...)
{
	static char output_string[1024];

	memset(output_string, 0, sizeof(output_string));
	va_list args;
	va_start(args, format);
	vsprintf(output_string, format, args);

#ifdef _WIN32
	OutputDebugStringA(output_string);
#endif
	printf(output_string);
}

#if _WIN32
INLINE i32 filter(u32 code, struct _EXCEPTION_POINTERS *ep)
{
	DXERR_printf(
			"Exception %08X at %08X",
			ep->ExceptionRecord->ExceptionCode,
			ep->ExceptionRecord->ExceptionAddress);

	switch (ep->ExceptionRecord->ExceptionCode)
	{
		case EXCEPTION_ACCESS_VIOLATION:
			DXERR_printf("Access Violation\n");
			break;
		case EXCEPTION_INT_DIVIDE_BY_ZERO:
			DXERR_printf("floating-point ");
		case EXCEPTION_FLT_DIVIDE_BY_ZERO:
			DXERR_printf("Divide by 0\n");
			break;
	}

	return 0;
}
#endif

#ifdef _OLD_WINDOWS
// @Ok
// man so much to talk about this funciton
// starting with dumb filter that always continues and just logs
// to the numerous setters of globals
i32 WINAPI RealWinMain(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		i32 nCmdShow)
{
	if (gDrmShit(0))
	{
		MessageBoxA(
				0,
				"Please insert the Spider-Man CD-ROM, select OK, and restart the game",
				"Spider-Man Error",
				MB_TASKMODAL | MB_ICONEXCLAMATION);
		exit(1);
	}

	SPIDEYDX_LoadSettings();

	gRenderTest = 0;
	gGameResolutionX = 640;
	gDxResolutionX = 640;

	gGameResolutionY = 480;
	gDxResolutionY = 480;

	gMMXSupport = isMMX();


	if (hPrevInstance == 0)
	{
		WNDCLASSA wndClass;

		wndClass.style = 3;
		wndClass.lpfnWndProc = SpideyWndProc;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hInstance = hInstance;
		wndClass.hIcon = LoadIconA(0, (LPCSTR)0x65);
		wndClass.hCursor = LoadCursorA(0, (LPCSTR)0x7F00);
		wndClass.hbrBackground = (HBRUSH)GetStockObject(4);
		wndClass.lpszMenuName = 0;
		wndClass.lpszClassName = "Spiderman PC";

		if ( !RegisterClassA(&wndClass) )
			return -1;
	}

	HWND hwnd;
	if ( gRenderTest & 1)
	{
		hwnd = CreateWindowExA(
				0,
				"Spiderman PC",
				"Spiderman PC",
				WS_VISIBLE | WS_CAPTION,
				0,
				0,
				640,
				480,
				0,
				0,
				hInstance,
				0);
	}
	else
	{
		i32 yres = GetSystemMetrics(1);
		i32 xres = GetSystemMetrics(0);

		hwnd = CreateWindowExA(
				0,
				"Spiderman PC",
				"Spiderman PC",
				WS_VISIBLE | WS_POPUP,
				0,
				0,
				xres,
				yres,
				0,
				0,
				hInstance,
				0);
	}

	if (hwnd == 0)
	{
		DXERR_printf("Unable to create application window!\r\n");
		return -1;
	}

	gHwnd = hwnd;

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	SetFocus(hwnd);
	SetCursor(0);
	ShowCursor(0);
	WinYield();

	PCTIMER_Init();
	DXINIT_DirectX8(hwnd, hInstance, 2);

	if (g3DAccelator || gMMXSupport)
	{
		__try
		{
			if (gRenderTest & 2)
			{
				MessageBoxA(
						hwnd,
						"RENDERTEST flag not supported anymore!",
						"Spiderman Error",
						MB_ICONERROR);
				DXINIT_ShutDown();
			}
			else
			{
				SpideyMain();
			}
		}
		__except (filter(GetExceptionCode(), GetExceptionInformation()))
		{
		}
	}
	else
	{
		MessageBoxA(
				hwnd,
				"Your machine does not support MMX or have 3D accelerator hardware so this game can not run.",
				"SpideyPC Fatal Error",
				MB_ICONERROR);
	}

	SPIDEYDX_Shutdown();
	Sleep(0x64);

	PostMessage(hwnd, WM_CLOSE, 0, 0);
	WinYield();
	return 0;
}
#endif
