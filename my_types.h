#pragma once

#ifndef MY_TYPES_H
#define MY_TYPES_H

#ifdef _MSC_VER

#if _MSC_VER < 1300
#define _OLD_WINDOWS
#else
#define _NEW_WINDOWS
#endif

#endif

#ifdef _WIN32
#define EXPORT __declspec( dllexport )
#define FASTCALL __fastcall
#define STDCALL __stdcall
#else
#define EXPORT
#define FASTCALL __attribute__((fastcall))
#define STDCALL __attribute__((stdcall))
#endif

#include <cstdio>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;

typedef float f32;
typedef double f64;

#ifdef _WIN32
#define INLINE __inline
#else
#define INLINE
#endif

#ifndef _OLD_WINDOWS
#define OVERRIDE override
#else
#define OVERRIDE
#endif

// From SO: 42837863 - modified for PADDING
#define CONCAT(x, y) x##y
#define EXPAND(x, y) CONCAT(x, y)
#define PADDING(x) EXPAND(u8 pad_, __LINE__)[(x)]


#ifndef _WIN32
#define FAILED(x) ((i32)(x) < 0)

typedef struct _GUID
{
	PADDING(0x10);
} GUID;

typedef u32 HRESULT;
typedef i32 BOOL;
typedef char* LPSTR;
typedef void* LPVOID;
typedef i32 HMONITOR;

struct RECT
{};

struct tagPOINT
{
};

#define TRUE 1
#define FALSE 0


#endif

#endif

