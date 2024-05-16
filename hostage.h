#pragma once

#include "export.h"
#include "baddy.h"


class CHostage : public CBaddy {

public:
	EXPORT CHostage(int*, int);
	int field_324;
	int field_328;
	int field_32C;

	unsigned char hostagePadp[0x4];
};


void validate_CHostage(void);
EXPORT void Hostage_CreateHostage(const unsigned int *, unsigned int *);
