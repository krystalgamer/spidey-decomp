#pragma once

#include "export.h"
#include "baddy.h"

class CCarnage : public CBaddy {
public:
	EXPORT CCarnage(int*, int);

	unsigned char carnageStartPad[0x10];

	int field_334;
	int field_338;
	int field_33C;
	unsigned char padAfter33c[0x18 - 4];

	int field_354;
	int field_358;
	int field_35C;
	unsigned char padAfter35C[0x10-4];

	int field_36C;
	int field_370;
	int field_374;
	int field_378;
};


void validate_CCarnage(void);
EXPORT void CreateSonicBubbleVertexWobbler(void);
