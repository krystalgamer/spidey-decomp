#pragma once

#ifndef VALIDATE_H
#define VALIDATE_H

#include <stddef.h>
#include <cstdio>
#include "my_types.h"

void validate_class(int cur, int expected, const char *cls, const char *member);
#define VALIDATE(cls, member, expected) validate_class(offsetof(cls, member), expected, #cls, #member);


void validate_size(int cur, int expected, const char *name);
#define VALIDATE_SIZE(cls, size) validate_size(sizeof(cls), size, #cls);

u32* get_thunk_address(void*, ...);

void validate_vtable_index(
		u32 expected_index,
		const u32* known_address,
		const char *cls,
		const char *name);
#define VALIDATE_VTABLE(cls, member, expected) {\
	validate_vtable_index(expected, get_thunk_address(0, &cls::member), #cls, #member);\
}


#endif
