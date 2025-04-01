#pragma once

#ifndef COP_H
#define COP_H

#include "export.h"
#include "baddy.h"
#include "mem.h"
#include "m3dutils.h"
#include "weapons.h"
#include "message.h"
#include "bit2.h"
#include "reloc.h"


class CCop : public CBaddy {

public:
	EXPORT CCop(i16*, i32);
	EXPORT virtual ~CCop(void);

	EXPORT void ClearAttackFlags(void);
	EXPORT void LookForPlayer(void);
	EXPORT i32 GetLaunched(CVector*, i32, i32, i32);
	EXPORT i32 SpideyAnimUppercut(void);
	EXPORT void HelpOutBuddy(CMessage *);
	EXPORT void RunToWhereTheActionIs(CVector*);
	EXPORT void SetAttacker(void);
	EXPORT void PlayHitWallSound(void);
	EXPORT void StandStill(void);
	EXPORT void DieAfterFlyingAcrossRoom(void);
	EXPORT void StopShooting(void);
	EXPORT void WarnOtherCops(void);
	EXPORT i32 TryAddingCollidePointToPath(CVector *);
	EXPORT void GetAttackPosition(CVector*);
	EXPORT void DrawBarrelFlash(CVector*, CVector *, SLineInfo *, u8, u8, u8);
	EXPORT void SetUpLaser(CGPolyLine**, CVector*, CVector*);
	EXPORT void CheckToShoot(i32, i32);
	EXPORT void Acknowledge(void);
	EXPORT i32 WallHitCheck(CVector*, CVector*, i32);

	EXPORT virtual void CreateCombatImpactEffect(CVector*, i32);
	EXPORT virtual u8 TugImpulse(CVector*, CVector*, CVector*);
	EXPORT virtual void Victorious(void);
	EXPORT virtual void SetParamByIndex(i32, i32);
	EXPORT virtual u8 Grab(CVector*);

	i32 field_324;
	u8 padAfter324[0x340-0x324-4];

	i32 field_340;
	u8 padAfter340[0xC-4];

	SHandle field_34C;
	u8 padAfter34C[0x360-0x34C-sizeof(SHandle)];

	i32 field_360;
	i32 field_364;
	i32 field_368;
	i32 field_36C;
	i32 field_370;
	i32 field_374;
	u8 padAfter374[0x37C - 0x374 - 4];
	i32 field_37C;

	// @FIXME - find type
	CGPolyLine* field_380;
	CVector* field_384;
	u8 padAfter384[0x390 - 0x384 - 4];

	u8 field_390;
	u8 field_391;
	u8 endPad[0x394 - 0x391 - 1];
};

class CCopPing : public CSimpleAnim
{
	public:
		EXPORT CCopPing(CSuper*, SHook*);
		EXPORT virtual ~CCopPing(void);

		EXPORT void Move(void);
		EXPORT void SetPosition(void);

		SHandle field_70;
		SHook field_78;
};

class CCopBulletTracer : public CNonRenderedBit
{
	public:
		EXPORT CCopBulletTracer(CVector*, CVector*, CSuper*, SLineInfo*, u8, u8, u8);
		EXPORT virtual ~CCopBulletTracer(void);

		EXPORT void SetWidth(void);

		EXPORT virtual void Move(void) OVERRIDE;

		CGouraudRibbon *mpRibbon;
		CGouraudRibbon *mpRibbon2;
		u32 mMaxWidth;

};

class CCopLaserPing : public CQuadBit
{
	public:
		EXPORT CCopLaserPing(CVector*, CVector*, CVector*, u8, u8, u8);
		EXPORT virtual ~CCopLaserPing(void);
		
		i32 field_84;

		CVector field_88;
		CVector field_94;
		CVector field_A0;
};


void validate_CCop(void);
void validate_CCopPing(void);
void validate_CCopBulletTracer(void);
void validate_CCopLaserPing(void);

EXPORT void Cop_CreateCop(const unsigned int *stack, unsigned int *result);
EXPORT void CreateCopRicochet(SLineInfo *,u8,u8,u8);
EXPORT void Cop_RelocatableModuleInit(reloc_mod*);
EXPORT void Cop_RelocatableModuleClear(void);

#endif
