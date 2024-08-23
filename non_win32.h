#pragma once

#ifndef NON_WIN32_h
#define NON_WIN32_h

#ifndef _WIN32

#include "my_types.h"

u32 GetTickCount();

typedef i32* HANDLE;
#define INVALID_HANDLE_VALUE ((HANDLE)(-1))

// @FIXME
typedef i32* HWND;

// @FIXME
typedef i32 HINSTANCE;

//@FIXME
typedef i32 tWAVEFORMATEX;

typedef i32 LRESULT;
typedef u32 UINT;
typedef i32 LPARAM;
typedef u32* WPARAM;
typedef char* LPSTR;
typedef char* PSTR;

#define WINAPI
#define CALLBACK


#else
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>
#endif

#endif
