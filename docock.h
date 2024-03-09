#pragma once

#include "export.h"
#include "baddy.h"

class CDocOc : public CBaddy {

public:
	int field_324;
	int field_328;
	int field_32C;
	int field_330;
	CVector field_334[30];
	unsigned char padAfter334[0xC];

	int field_4A8;
	unsigned char padAfter4A8[0x40];

	int field_4EC;
	unsigned char padAfter4EC[0x1C];

	int field_50C;
	int field_510;
	int field_514;
	unsigned char padAfter514[0x40-4];

	int field_554;
	unsigned char padAfter554[0x38];
};


void validate_CDocOc(void);