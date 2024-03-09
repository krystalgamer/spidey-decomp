#pragma once

#include "export.h"
#include "baddy.h"


class CCop : public CBaddy {

public:
	unsigned char copStartPad[0x1C];

	int field_340;
	unsigned char padAfter340[0x20 - 4];

	int field_360;
	int field_364;
	int field_368;
	int field_36C;
	int field_370;
	int field_374;

	unsigned char endPad[0x1C];
};

void validate_CCop(void);