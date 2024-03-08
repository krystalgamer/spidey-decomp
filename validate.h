#pragma once

#include <stddef.h>
#include <cstdio>

void validate_class(int cur, int expected, const char *cls, const char *member);
#define VALIDATE(cls, member, expected) validate_class(offsetof(cls, member), expected, #cls, #member);


void validate_size(int cur, int expected, const char *name);
#define VALIDATE_SIZE(cls, size) validate_size(sizeof(cls), size, #cls);
