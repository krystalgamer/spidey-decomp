#pragma once

#ifndef EXPORT_H
#define EXPORT_H

#ifdef _WIN32
#define EXPORT __declspec( dllexport )
#define FASTCALL __fastcall
#else
#define EXPORT
#define FASTCALL __attribute__((fastcall))
#endif

#include <cstdio>

#ifdef __linux__
#define __int16 short
#define __int8 char
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef char i8;
typedef short i16;
typedef int i32;

static int *Animations = (int*)0x006B245C;

static int * const dword_5FCCF4 = (int*)0x5FCCF4;

static unsigned char * const submarinerDieRelated = (unsigned char*)0x0060CFC4;

static unsigned __int16 * const word_6B2478 = (unsigned __int16*)0x6B2478;
static int * const gTimerRelated = (int*)0x006B4CA8;

static void print_if_false(unsigned char cry, char * message, ...) {
	if (cry) {
		printf(message);
	}
}

static void printf_fancy(const char *message, ...) {
	// TODO
}

static void stubbed_printf(char *message){
	puts(message);
}

#endif
