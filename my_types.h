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
#else
#define EXPORT
#define FASTCALL __attribute__((fastcall))
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
#endif

#endif

