#pragma once

#ifndef CHOPPER_H
#define CHOPPER_H

#include "export.h"
#include "baddy.h"
#include "bit2.h"


class CChopper : public CBaddy {
public:

	EXPORT CChopper(i16*, i32);
	EXPORT virtual ~CChopper(void);
	EXPORT virtual void AI(void);

	EXPORT void SetHeightMode(int);
	EXPORT void AdjustSineWaveAmplitude(int, int);
	EXPORT void AngleToTargetAngle(void);
	EXPORT void WaitForTrigger(void);

	EXPORT void SetHeight(void);
	EXPORT void DoChopperPhysics(void);
	EXPORT i32 DoArrivalAction(void);
	EXPORT i32 DoWaypointAction(void);
	EXPORT i32 GetToPos(CVector*);
	EXPORT void SetTargetAngleFromPos(CVector*);
	EXPORT void RotateBlades(void);
	EXPORT void AimGunPod(void);
	EXPORT void FollowWaypoints(void);
	EXPORT void SetDesiredPosForTrackMode(void);
	EXPORT void ShotCollision(CVector*, CVector*);
	EXPORT void Shoot(void);
	EXPORT void StartStrafeOnslaught(void);
	EXPORT i32 InCameraPath(void);
	EXPORT void GetOutOfCameraPath(void);
	EXPORT i32 GetToDesiredPos(void);
	// @FIXME
	EXPORT void FireMachineGunAtWaypointV(void);
	EXPORT void TrackSpidey(void);
	

	EXPORT virtual void FireMissileAtWaypoint(u32);
	EXPORT virtual void FireMachineGunAtWaypoint(u32, u32);
	EXPORT virtual void SetFlag(u16, i16);

	u32 field_324;
	u32 field_328;
	u8 padAfter328[4];

	CVector field_330;

	CVector field_33C;
	i32 field_348;
	i32 field_34C;

	u8 padAfter34C[0x354-0x34C-4];

	i32 field_354;
	i32 field_358;
	i32 field_35C;

	i32 field_360;
	i32 field_364;
	i32 field_368;
	i32 field_36C;
	u8 padAfter36C[0x374-0x36C-4];

	i32 field_374;
	i32 field_378;
	u8 padAfter378[0x380-0x378-4];

	i32 field_380;
	i32 field_384;

	CVector field_388;

	CVector field_394;

	i32 field_3A0;
	i32 field_3A4;

	CVector field_3A8;
	i32 field_3B4;
	CVector field_3B8;

	u8 field_3C4;
	u8 padAfter3c4[0x3c8 - 0x3c4 - 1];

	i32 field_3C8;
	i32 field_3CC;
	i32 field_3D0;
	u8 endChopperPad[0x3d8-0x3d0-4];
};

class CBulletFrag : public CFlatBit {
public:
	EXPORT CBulletFrag(CVector*);
	EXPORT ~CBulletFrag(void);
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
		EXPORT virtual void AI(void);
		EXPORT virtual void DrawTargetRecticle(void);

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
		EXPORT void CalculateSearchlight(CSVector*);
		EXPORT void CheckPointInScreenTri(u32, u32, u32, u32);
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

class CChopperMissile : public CBody
{
	public:
		EXPORT CChopperMissile(CVector*, CSuper*, i32, i32);
		EXPORT virtual ~CChopperMissile(void);
		EXPORT i32 GetFinalTargetNode(i32);
		EXPORT void CommonInitialisation(void);
		EXPORT void Explode(void);


		EXPORT virtual void AI(void);
		EXPORT virtual void DrawTargetRecticle(void);

		u8 padTop[4];

		CSmokeTrail *field_F8;
		i32 field_FC;
		i32 field_100;
		i32 field_104;
		u8 padAfter104[4];

		i32 field_10C;
		CVector field_110;
		i32 field_11C;

		i32 field_120;
		Texture* field_124;
};

void validate_CChopper(void);
void validate_CBulletFrag(void);
void validate_CSniperSplat(void);
void validate_CSniperTarget(void);
void validate_CSearchlight(void);
void validate_CMachineGunBullet(void);
void validate_CChopperMissile(void);

EXPORT void Chopper_CreateSearchlight(u32*, u32*);
EXPORT void Chopper_CreateSniper(u32*, u32*);
EXPORT void Chopper_CreateChopper(u32*, u32*);

#endif
