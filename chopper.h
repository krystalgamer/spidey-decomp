#pragma once

#ifndef CHOPPER_H
#define CHOPPER_H

#include "export.h"
#include "baddy.h"


class CChopper : public CBaddy {
public:

	EXPORT void SetHeightMode(int);
	EXPORT void AdjustSineWaveAmplitude(int, int);
	EXPORT void AngleToTargetAngle(void);
	EXPORT void WaitForTrigger(void);

	u8 padChopperStart[0xC-8];
	i32 field_328;
	u8 padAfter328[4];

	i32 field_330;
	i32 field_334;
	i32 field_338;
	i32 field_33C;
	i32 field_340;
	i32 field_344;
	i32 field_348;

	u8 padAfter348[0x354-0x348-4];

	i32 field_354;
	i32 field_358;
	u8 padAfter358[0x360-0x358-4];

	i32 field_360;
	i32 field_364;
	i32 field_368;
	i32 field_36C;
	u8 padAfter36C[0x374-0x36C-4];

	i32 field_374;
	u8 padAfter374[0x380-0x374-4];

	i32 field_380;
	i32 field_384;

	i32 field_388;
	i32 field_38C;
	i32 field_390;
	i32 field_394;
	i32 field_398;
	i32 field_39C;
	u8 padAfter39C[0x8];

	i32 field_3A8;
	i32 field_3AC;
	i32 field_3B0;
	i32 field_3B4;
	i32 field_3B8;
	i32 field_3BC;
	i32 field_3C0;
	u8 padAfter3c0[0x4];

	i32 field_3C8;
	i32 field_3CC;
	i32 field_3D0;
	u8 endChopperPad[0x3d8-0x3d0-4];
};

class CBulletFrag : public CFlatBit {
public:
	EXPORT void Move(void);

};

class CSniperSplat : public CQuadBit {
public:
	int field_84;
};

class CSniperTarget : public CBody
{
	public:
		EXPORT void BulletResult(bool);
		unsigned char padTop[0xFC-0xF4];
		int field_FC;
		unsigned char padAfterFC[0x128-0xFC-0x4];

		bool field_128;
		unsigned char padBottom[0x15C-0x128-1];
};

void validate_CChopper(void);
void validate_CBulletFrag(void);
void validate_CSniperSplat(void);
void validate_CSniperTarget(void);

#endif
