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

#ifndef _WIN32
#define __int16 short
#define __int8 char

#endif

typedef unsigned char u8;
typedef unsigned __int16 u16;
typedef unsigned int u32;

typedef char i8;
typedef __int16 i16;
typedef int i32;

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

#ifndef _WIN32
#define FAILED(x) ((i32)(x) < 0)

typedef struct _GUID
{
	u8 pad[0x10];
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

