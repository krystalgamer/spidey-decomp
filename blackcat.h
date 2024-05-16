#pragma once

#include "export.h"
#include "baddy.h"

class CBlackCat : public CBaddy {
public:
	
	EXPORT CBlackCat(int*, int);
	int field_324;
	int field_328;
	int field_32C;
	unsigned char padAfter32C[0x10];

	unsigned char field_340;
	int field_344;

	unsigned char field_348;

	int field_34C;
	int field_350;
};

void validate_CBlackCat(void);
EXPORT void BlackCat_CreateBlackCat(const unsigned int *stack, unsigned int *result);
