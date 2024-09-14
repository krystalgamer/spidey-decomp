#pragma once

#ifndef EXPORT_H
#define EXPORT_H

#include "my_types.h"

static int *Animations = (int*)0x006B245C;

static int * const dword_5FCCF4 = (int*)0x5FCCF4;

//static unsigned char * const submarinerDieRelated = (unsigned char*)0x0060CFC4;

static unsigned __int16 * const word_6B2478 = (unsigned __int16*)0x6B2478;
//static int * const gTimerRelated = (int*)0x006B4CA8;

static void print_if_false(unsigned char cry, char * message, ...) {
	if (!cry) {
		printf(message);
	}
}

static void printf_fancy(const char *message, ...) {
	// TODO
}

static void stubbed_printf(char *message){
	puts(message);
}

static void error(const char *message, ...) {
	printf("static void error(const char *message, ...)");
}

static void DebugPrintfX(const char *message, ...)
{
}

#endif
