#include "SpideyDX.h"
#include "main.h"
#include "PCTimer.h"
#include "DXinit.h"

i32 gRenderTest;

i32 gGameResolutionX = 640;
i32 gGameResolutionY = 480;

i32 gDxResolutionX;
i32 gDxResolutionY;

u8 gMMXSupport;
u8 g3DAccelator = 1;

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

#ifdef _WIN32
// @SMALLTODO
LRESULT CALLBACK SpideyWndProc(HWND, UINT, WPARAM, LPARAM)
{
    printf("SpideyWndProc(HWND__ *,u32,u32,long)");
	return 0;
}
#endif

// @SMALLTODO
void WinYield(void)
{
    printf("WinYield(void)");
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
EXPORT void gDrmShit(i32)
{
	printf("void gDrmShit(i32)");
}

// @Ok
void DXERR_printf(const char*, ...)
{
	printf("void DXERR_printf(const char*, ...)");
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
	gDrmShit(0);
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
