#pragma once

#ifndef THUG_H
#define THUG_H

#include "export.h"
#include "baddy.h"


class CThug : public CBaddy {
public:
	EXPORT CThug(int*, int);

	unsigned char padTop[0x370-0x324];

	int field_370;
	int field_374;
	int field_378;
	int field_37C;
	int field_380;
	int field_384;
	int field_388;
	int field_38C;
	unsigned char padAfter38C[0x394 - 0x38C - 4];

	int field_394;
	unsigned char padAfter394[0x3B0-0x394-4];

	int field_3B0;
	unsigned char padAfter3B0[0x3B8-0x3B0-4];

	int field_3B8;
	unsigned char padBottom[0x3C0 - 0x3B8 - 4];
};

void validate_CThug(void);
EXPORT void Thug_CreateTHug(const unsigned int *stack, unsigned int *result);

#endif
