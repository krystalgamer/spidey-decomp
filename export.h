#pragma once
#define EXPORT __declspec( dllexport )
#include <cstdio>


static int *Animations = (int*)0x006B245C;

static int * const dword_5FCCF4 = (int*)0x5FCCF4;

static unsigned char * const submarinerDieRelated = (unsigned char*)0x0060CFC4;

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
