#pragma once

#include "export.h"
#include "baddy.h"


class CMystFoot : public CBaddy {};

class CSoftSpot : public CBaddy {
public:
	int field_324;
	int field_328;
	int field_32c;
	int field_330;
	int field_334;
};

class CMysterio : public CBaddy {
	public:
	int field_324;
	unsigned char padAfter324[0x4];

	int field_32C;
	unsigned char padAfter32C[0x358-0x32c-4];

	int field_358;
	unsigned char padAfter358[0x4];


	int field_360;
	int field_364;
	int field_368;
	int field_36C;
	unsigned char padAfter36C[0x4];

	int field_374;
	int field_378;
	int field_37C;
	int field_380;
	int field_384;
	unsigned char padAfter384[0x4];

	int field_38C;
	unsigned char padAfter38c[0x8];

	int field_398;
	unsigned char padAfter398[0x3a8-0x398-4];


	int field_3A8;
	unsigned char mysterioEndPad[0x3d0-0x3a8-4];

};

void validate_CMystFoot(void);
void validate_CMysterio(void);
void validate_CSoftSpot(void);