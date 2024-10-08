#pragma once

#ifndef VALIDATE_H
#define VALIDATE_H

#include <stddef.h>
#include <cstdio>
#include "my_types.h"

void validate_i32(int cur, int expected, const char *name, int line);
#define VALIDATE_I32(x,y) validate_i32(x, y, __FILE__, __LINE__);

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

i32 read_into(const char* fileName, void* dst, u32 size);

i32 compare_buffs(const char*, void*, void*, u32 size);

#endif
