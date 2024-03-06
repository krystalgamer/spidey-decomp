#pragma once
#define EXPORT __declspec( dllexport )
#include <cstdio>


static int *Animations = (int*)0x006B245C;

static void print_if_false(unsigned char cry, char * message) {
	if (cry) {
		printf(message);
	}
}
