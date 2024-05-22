#pragma once

#include "export.h"
#include "baddy.h"

class CLizMan : public CBaddy {
public:
	EXPORT void PlaySingleAnim(__int16, int, int);
	EXPORT void StandStill(void);

	unsigned char padLizStart[0x4];

	int field_328;
	int field_32C;
	unsigned char padAfter32C[0x338-0x32C-4];

	int field_338;
	unsigned char padAfter338[0x340-0x338-4];

	int field_340;
	unsigned char padAfter340[0x374-0x340-4];


	int field_374;
	unsigned char padAfter374[0x398-0x374-4];

	int field_398;
	unsigned char padAfter398[0x3AC - 0x398 - 4];

	int field_3AC;
	unsigned char padLizManEnd[0x3B8-0x3AC-4];
};

void validate_CLizMan(void);
