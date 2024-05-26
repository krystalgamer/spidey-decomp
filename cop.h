#pragma once

#ifndef COP_H
#define COP_H

#include "export.h"
#include "baddy.h"


class CCop : public CBaddy {

public:
	EXPORT CCop(int*, int);
	EXPORT void Victorious(void);

	unsigned char copStartPad[0x1C];

	int field_340;
	unsigned char padAfter340[0x20 - 4];

	int field_360;
	int field_364;
	int field_368;
	int field_36C;
	int field_370;
	int field_374;
	unsigned char padAfter374[0x37C - 0x374 - 4];
	int field_37C;
	unsigned char endPad[0x394 - 0x37C - 4];
};

void validate_CCop(void);
EXPORT void Cop_CreateCop(const unsigned int *stack, unsigned int *result);
#endif
