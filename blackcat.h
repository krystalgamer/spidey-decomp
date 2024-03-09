#pragma once

#include "export.h"
#include "baddy.h"

class CBlackCat : public CBaddy {
public:
	
	int field_324;
	unsigned char padAfter324[0x4];
	int field_32C;
	unsigned char padAfter32C[0x10];

	unsigned char field_340;
	unsigned char padAfter340[0x7];

	unsigned char field_348;

	int field_34C;

	int finalNotDefinedField;
};

void validate_CBlackCat(void);