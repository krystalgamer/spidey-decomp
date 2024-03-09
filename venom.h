#pragma once

#include "export.h"
#include "baddy.h"


class CVenom : public CBaddy {

public:

	unsigned char venomStartPad[0x58];
	int field_37C;
	int field_380;
	int field_384;

	unsigned char venomPadAfter384[0x18];

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
};


void validate_CVenom(void);