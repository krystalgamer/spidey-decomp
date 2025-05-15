#pragma once

#ifndef SIMBY_H
#define SIMBY_H

#include "export.h"
#include "baddy.h"
#include "reloc.h"

class CPunchOb : public CBaddy {
public:
	EXPORT CPunchOb(i16*, i32);
	EXPORT virtual ~CPunchOb(void);
	EXPORT virtual i32 Hit(SHitInfo*);
	EXPORT virtual void AI(void);

	EXPORT void SendPulse(void);

	PADDING(4);

	u8 field_328;
	PADDING(0x32C - 0x328 - 1);
};

class CSimby : public CBaddy {
public:
	EXPORT CSimby(i32*, i32);
	EXPORT CSimby(void);
	EXPORT void FlashUpdate(void);
	EXPORT void SetAlertModeTimer(i32);
	EXPORT void ClearAttackData(void);
	EXPORT void SetUpUnitFromDirection(CVector*, i32);
	EXPORT void SetUpJumpData(i32, i32);
	EXPORT void RunAppropriateHitAnim(void);
	EXPORT i32 FireTrappedToDeath(void);
	EXPORT i32 PlayAndAttachXAPlease(i32, i32, CBody*, i32);
	EXPORT void PlayGruntSound(void);
	EXPORT void TakeHit(void);
	EXPORT void Shoot(void);
	EXPORT void SetUpHandPos(void);
	EXPORT void SimbyKnockSpideyDown(i32);


	i32 field_324;
	i16 field_328;
	u16 field_32A;
	u16 field_32C;
	i16 field_32E;
	i32 field_330;

	PADDING(0x348-0x330-4);

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

	PADDING(0x3CC-0x39C-4);

	i32 field_3CC;
	i32 field_3D0;

	PADDING(0x3DC-0x3D0-4);

	CVector field_3DC;

	PADDING(0x3F0-0x3E4-4);

	i32 field_3F0;

	PADDING(4);

	i32 field_3F8;
	i32 field_3FC;
	i32 field_400;
	i32 field_404;
	i32 field_408;
	i32 field_40C;

	PADDING(0x460 - 0x40C-4);
};

class CSimbyBase : public CBaddy
{
	public:
		PADDING(0x334 - 0x324);
};

class CSimbySlimeBase : public CQuadBit
{
	public:
		EXPORT void ScaleUp(void);
		EXPORT void ScaleDown(void);
		EXPORT void ScaleDownAndDie(void);

		PADDING(0x9C-0x84);

		i32 field_9C;

		PADDING(0xA4-0x9C-4);

		i32 field_A4;

		PADDING(0x114-0xA4-4);
};

class CEmber : public CFlatBit
{
	public:
		EXPORT CEmber(const CVector*, int);
		EXPORT virtual ~CEmber(void);

		CVector field_68;
		i32 field_74;
		CVector field_78;
		i32 field_84;
		i32 field_88;
		i32 field_8C;
};

class CSimbyShot : public CQuadBit
{
	public:
		EXPORT CSimbyShot(CVector*);

		PADDING(0x34);
};

class CSkidMark : public CQuadBit
{
	public:
		EXPORT CSkidMark(void);
		EXPORT virtual void Move(void);
};

class CFireySpark : public CPixel
{
	public:
		EXPORT CFireySpark(CVector*, CVector*, i32);
		EXPORT virtual ~CFireySpark(void);

		EXPORT virtual void Move(void);

		i32 field_48;
		i32 field_4C;
};


class CSimbyDroplet : public CFlatBit
{
	public:
		EXPORT CSimbyDroplet(i16*, i32);
		EXPORT virtual ~CSimbyDroplet(void);

		EXPORT virtual void Move(void);

#ifndef _WIN32
		// @FIXME
		PADDING(2);
#endif
		u16 field_68;
		u16 field_6A;
		i32 field_6C;
};

class CSymBurn : public CSuper
{
	public:
		EXPORT CSymBurn(CVector*);
		EXPORT virtual ~CSymBurn(void);

		EXPORT void AI(void) OVERRIDE;

		i32 field_1A4;

};

class CFlamingImpactWeb : public CFlatBit
{
	public:
		EXPORT CFlamingImpactWeb(CVector*, CSVector*, i32);
		EXPORT virtual ~CFlamingImpactWeb(void);

		PADDING(4);

		i32 field_6C;
		i32 field_70;
		CItem *pItem;
		u32 *pFace;
		CVector mLinePos;
		CSVector mLineNormal;
};

void validate_CPunchOb(void);
void validate_CSimby(void);
void validate_CSimbyBase(void);
void validate_CSimbySlimeBase(void);
void validate_CEmber(void);
void validate_CSimbyShot(void);
void validate_CSkidMark(void);
void validate_CFireySpark(void);
void validate_CSimbyDroplet(void);
void validate_CSymBurn(void);
void validate_CFlamingImpactWeb(void);

EXPORT void MakeVertexWibbler(void);
EXPORT void Simby_CreateSimby(const u32 *stack, u32 *result);
EXPORT void Simby_CreateEmber(const u32*, u32*);
EXPORT void Simby_CreateSimbyDroplet(const u32 *, u32 *);
EXPORT void Simby_CreateSimbyPunchOb(const u32 *, u32 *);

EXPORT void Simby_SplattyExplosion(CVector*, CVector*, i32);
EXPORT void Simby_RelocatableModuleInit(reloc_mod*);
EXPORT void Simby_RelocatableModuleClear(void);
EXPORT void Simby_CreateFlamingImpactWeb(const u32 *,u32 *);
EXPORT void Simby_CreatePunchOb(const u32 *stack, u32 *result);
EXPORT void Simby_TestDrop(const u32 *, u32 *);

class CPlayer;
EXPORT void SpideyAI_WaitForSimbyGrab(CPlayer *);
EXPORT void SpideyAI_ThrownBySimby(CPlayer *);

#endif
