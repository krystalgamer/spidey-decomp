#pragma once

#include "export.h"
#include "baddy.h"


class CHostage : public CBaddy {

public:
	int field_324;
	int field_328;
	int field_32C;

	unsigned char hostagePadp[0x4];
};


void validate_CHostage(void);