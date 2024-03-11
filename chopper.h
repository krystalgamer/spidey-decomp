#pragma once

#include "export.h"
#include "baddy.h"


class CChopper : public CBaddy {
public:

	unsigned char padChopperStart[0xC];
	int field_330;
	int field_334;
	int field_338;
	int field_33C;
	int field_340;
	int field_344;
	unsigned char padAfter344[0x14-4];

	int field_358;
	unsigned char padAfter358[0x360-0x358-4];

	int field_360;
	int field_364;
	int field_368;
	int field_36C;
	unsigned char padAfter36C[0x10];

	int field_380;
	unsigned char padAfter380[0x4];

	int field_388;
	int field_38C;
	int field_390;
	int field_394;
	int field_398;
	int field_39C;
	unsigned char padAfter39C[0x8];

	int field_3A8;
	int field_3AC;
	int field_3B0;
	int field_3B4;
	int field_3B8;
	int field_3BC;
	int field_3C0;
	unsigned char padAfter3c0[0x4];

	int field_3C8;
	int field_3CC;
	int field_3D0;
	unsigned char endChopperPad[0x3d8-0x3d0-4];
};

class CBulletFrag : public CFlatBit {
public:
	EXPORT void Move(void);

};

void validate_CChopper(void);
void validate_CBulletFrag(void);