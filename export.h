#pragma once

#ifndef EXPORT_H
#define EXPORT_H

#include "my_types.h"
#include <cstdarg>

static i32 *Animations = (int*)0x006B245C;

//static unsigned char * const submarinerDieRelated = (unsigned char*)0x0060CFC4;

static u16* const word_6B2478 = (u16*)0x6B2478;
//static int * const gTimerRelated = (int*)0x006B4CA8;

static void print_if_false(unsigned char cry, char * message, ...) {
	if (!cry) {
		puts(message);
	}
}

static void printf_fancy(const char *message, ...) {
	static char error_buf[512];
	va_list lst;
    va_start(lst, message);

#ifdef _WIN32
	_vsnprintf(error_buf, sizeof(error_buf), message, lst);
#else
	vsnprintf(error_buf, sizeof(error_buf), message, lst);
#endif

	va_end(lst);
	printf("FANCY: %s\n", error_buf);
}

static void stubbed_printf(char *message){
	puts(message);
}

static void error(const char *message, ...) {
	static char error_buf[512];
	va_list lst;
    va_start(lst, message);

#ifdef _WIN32
	_vsnprintf(error_buf, sizeof(error_buf), message, lst);
#else
	vsnprintf(error_buf, sizeof(error_buf), message, lst);
#endif

	va_end(lst);
	printf("ERROR: %s\n", error_buf);
}

static void DebugPrintfX(const char *message, ...)
{
}

#define my_abs(x) ( (x ^ ((i32)x >> 31)) - ((i32)x >> 31) )


#define STRINGIFICATE_INNER(x) #x
#define STRINGIFICATE(x) STRINGIFICATE_INNER(x)
#define DO_LOG puts("Running " __FILE__ ":" STRINGIFICATE(__LINE__))

#endif
