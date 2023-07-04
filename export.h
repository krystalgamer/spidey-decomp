#pragma once
#define EXPORT __declspec( dllexport )
#include <cstdio>


static void print_if_false(unsigned char cry, char * message) {
	if (cry) {
		printf(message);
	}
}
