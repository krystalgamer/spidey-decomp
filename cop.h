#pragma once

#ifndef COP_H
#define COP_H

#include "export.h"
#include "baddy.h"
#include "mem.h"
#include "m3dutils.h"


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

class CCopPing : public CSimpleAnim
{
	public:
		EXPORT void Move(void);
		EXPORT void SetPosition(void);

		unsigned char padTop[8];
		SHandle field_70;
		unsigned char padAfter70[4];

		SHook field_78;
};

void validate_CCop(void);
void validate_CCopPing(void);

EXPORT void Cop_CreateCop(const unsigned int *stack, unsigned int *result);


#endif
