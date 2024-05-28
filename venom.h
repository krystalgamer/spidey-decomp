#pragma once

#ifndef VENOM_H
#define VENOM_H

#include "export.h"
#include "baddy.h"


class CVenom : public CBaddy {

public:

	EXPORT CVenom(int*, int);
	EXPORT void Lookaround(void);
	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);

	unsigned char venomStartPad[0x18];
	unsigned char field_33C;
	unsigned char field_33D;
	unsigned char venomPadAfter33D[0x24 - 12];

	int field_358;
	unsigned char venomPadAfter358[0x20];

	int field_37C;
	int field_380;
	int field_384;
	unsigned char venomPadAfter384[0x14];

	int field_39C;
	int field_3A0;
	int field_3A4;
	int field_3A8;
	
	unsigned char venomPadAFter3A8[0x3C];

	int field_3E8;
	int field_3EC;
	int field_3F0;

	unsigned char venomPadAfter3F0[0xC];

	int field_400;
	int field_404;
	int field_408;
	int field_40C;
	int field_410;
	int field_414;
	int field_418;
	int field_41C;
	int field_420;
	unsigned char venomPadAfter420[0x30 - 0x24];

	int field_430;
	CQuadBit *field_434;
	unsigned char venomPadAfter434[0x20-4];


	int field_454;
	int field_458;
	int field_45C;
	int field_460;
	int field_464;
	
	// @TODO venom has two secret virtual fucnctions
};

class CVenomWrap : public CNonRenderedBit
{
	public:
		EXPORT void Die(void);
		unsigned char fullPad[0x20];
};

void validate_CVenom(void);
void validate_CVenomWrap(void);
EXPORT void Venom_CreateVenom(const unsigned int *stack, unsigned int *result);



#endif
