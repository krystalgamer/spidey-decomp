#pragma once

#ifndef CHOPPER_H
#define CHOPPER_H

#include "export.h"
#include "baddy.h"
#include "bit2.h"


class CChopper : public CBaddy {
public:

	EXPORT CChopper(i16*, i32);
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
	EXPORT CBulletFrag(CVector*);
	EXPORT virtual void Move(void);
};

class CSniperSplat : public CQuadBit {
public:
	EXPORT CSniperSplat(CVector*, SVECTOR*);
	EXPORT virtual void Move(void);
	u8 field_84;
	u8 padBottom[3];
};

class CSniperTarget : public CBody
{
	public:
		EXPORT CSniperTarget(i32);
		EXPORT virtual ~CSniperTarget(void);
		EXPORT void BulletResult(bool);

		u8 padTop[0xFC-0xF4];
		i32 field_FC;
		u8 padAfterFC[0x104-0xFC-0x4];

		CVector field_104;
		i32 field_110;
		i32 field_114;
		i32 field_118;
		Texture* field_11C;
		i32 field_120;
		u8 padAfter120[0x128-0x120-4];

		bool field_128;
		u8 padAfter128[0x13C-0x128-1];

		i32 field_13C;
		i32 field_140;
		i32 field_144;
		i32 field_148;
		i32 field_14C;
		i32 field_150;

		u8 padBottom[0x15C-0x150-4];
};

class CSearchlight : public CBody
{
	public:
		EXPORT CSearchlight(i32);
		EXPORT virtual ~CSearchlight(void);
		EXPORT virtual void AI(void);
		EXPORT virtual void SpecialRenderer(void);


		u8 padTop[4];
		i32 field_F8;
		i32 field_FC;

		i32 field_100;
		CVector field_104;
		CVector field_110;
		CVector field_11C;
		u8 padAfter11C[0x138-0x11C-sizeof(CVector)];

		CVector field_138[66];
};

class CMachineGunBullet : public CGLine
{
	public:
		EXPORT CMachineGunBullet(CVector*, CVector*, CSniperTarget*);
		EXPORT CMachineGunBullet(CVector*, CVector*, CChopper*);
		EXPORT CMachineGunBullet(CVector*, CVector*);
		EXPORT void Common(CVector*, CVector*);
		EXPORT virtual void Move(void);

		i32 field_5C;
		i32 field_60;
		i32 field_64;

		i32 field_68;
		i32 field_6C;
		i32 field_70;
		u8 padAfter70[0x80-0x70-4];


		i16 field_80;
		i16 field_82;
		i16 field_84;
		u8 padAfter84[4];


		SHandle field_8C;
		SHandle field_94;
		u8 padAfter8C[0xA4-0x94-sizeof(SHandle)];



		i16 field_A4;
		u8 padAfterA4[0xA8-0xA4-2];


		i32 field_A8;
		i32 field_AC;
		i32 field_B0;
		u8 padBottom[0xB8-0xB0-4];
};

void validate_CChopper(void);
void validate_CBulletFrag(void);
void validate_CSniperSplat(void);
void validate_CSniperTarget(void);
void validate_CSearchlight(void);
void validate_CMachineGunBullet(void);

EXPORT void Chopper_CreateSearchlight(u32*, u32*);
EXPORT void Chopper_CreateSniper(u32*, u32*);
EXPORT void Chopper_CreateChopper(u32*, u32*);

#endif
