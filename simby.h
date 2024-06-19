#pragma once

#ifndef SIMBY_H
#define SIMBY_H

#include "export.h"
#include "baddy.h"

class CPunchOb : public CBaddy {
public:
	EXPORT void SendPulse(void);
	unsigned char padTop[4];

	unsigned char field_328;
	unsigned char padFull[0x32C - 0x328 - 1];
};

class CSimby : public CBaddy {
public:
	EXPORT CSimby(int*, int);
	EXPORT CSimby(void);
	EXPORT void FlashUpdate(void);
	EXPORT void SetAlertModeTimer(int);
	EXPORT void ClearAttackData(void);
	EXPORT void SetUpUnitFromDirection(CVector*, int);
	EXPORT void SetUpJumpData(i32, i32);
	EXPORT void RunAppropriateHitAnim(void);
	EXPORT i32 FireTrappedToDeath(void);
	EXPORT i32 PlayAndAttachXAPlease(i32, i32, CBody*, i32);
	EXPORT void PlayGruntSound(void);

	u8 padTop[0x328-0x324];

	i16 field_328;
	u16 field_32A;
	u16 field_32C;
	i16 field_32E;
	i32 field_330;
	u8 padAfter330[0x348-0x330-4];

	i32 field_348;
	i32 field_34C;

	i32 field_350;
	i32 field_354;
	i32 field_358;
	i32 field_35C;
	i32 field_360;
	i32 field_364;

	CVector field_368;

	i32 field_374;
	i32 field_378;
	i32 field_37C;
	i32 field_380;
	i32 field_384;
	i32 field_388;
	i32 field_38C;
	i32 field_390;
	i32 field_394;
	i32 field_398;

	i32 field_39C;
	u8 padAfter39C[0x3CC-0x39C-4];

	i32 field_3CC;
	i32 field_3D0;
	u8 padAfter3D0[0x3DC-0x3D0-4];

	i32 field_3DC;
	i32 field_3E0;
	i32 field_3E4;
	u8 padAfter3E4[0x3F0-0x3E4-4];

	i32 field_3F0;
	u8 padAfter3F0[4];

	i32 field_3F8;
	i32 field_3FC;
	i32 field_400;
	i32 field_404;
	i32 field_408;
	i32 field_40C;
	u8 padBottom[0x460 - 0x40C-4];
};

class CSimbyBase : public CBaddy {

public:
	unsigned char padFull[0x334 - 0x324];
};

class CSimbySlimeBase : public CQuadBit
{
	public:
		EXPORT void ScaleUp(void);
		EXPORT void ScaleDown(void);
		EXPORT void ScaleDownAndDie(void);

		unsigned char topPad[0x9C-0x84];
		int field_9C;
		unsigned char padAfter9C[0xA4-0x9C-4];

		int field_A4;
		unsigned char bottomPad[0x114-0xA4-4];
};

class CEmber : public CFlatBit
{
	public:
		EXPORT CEmber(const CVector*, int);
		unsigned char pad[0x28];
};

void validate_CPunchOb(void);
void validate_CSimby(void);
void validate_CSimbyBase(void);
void validate_CSimbySlimeBase(void);
void validate_CEmber(void);

EXPORT void MakeVertexWibbler(void);
EXPORT void Simby_CreateSimby(const unsigned int *stack, unsigned int *result);
EXPORT void Simby_CreateEmber(const unsigned int*, unsigned int*);

#endif
