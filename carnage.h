#pragma once

#ifndef CARNAGE_H
#define CARNAGE_H

#include "export.h"
#include "baddy.h"
#include "reloc.h"
#include "bit2.h"

class CSonicRipple : public CGPolyLine
{
	public:
		EXPORT CSonicRipple(const CVector *,i32,i32,i32,i32,i32,i32,i32,i32,u8,u8,u8,i32,i32);
		EXPORT void CalcPos(CVector *,i16,i32);

		EXPORT virtual void Move(void);
		EXPORT virtual ~CSonicRipple(void);

		PADDING(0x5E-0x58);

		i16 field_5E;

		PADDING(0x74 - 0x5E - 2);

		i32 field_74;
		i32 field_78;
		i32 field_7C;

		i16 field_80;

		PADDING(0x88-0x80-2);
};

class CCarnage : public CBaddy {
public:
	EXPORT CCarnage(i16*, i32);
	EXPORT ~CCarnage(void);

	EXPORT void PulseL8A5Node(void);
	EXPORT void DieCarnage(void);
	EXPORT void PlayXA(i32, i32, i32);
	EXPORT void Laugh(void);
	EXPORT void CheckSlideParams(void);
	EXPORT void Initialise(void);
	EXPORT void SnapArenaPosition(CVector *);
	EXPORT void GetArenaPositionFromAngleOffset(i32,CVector *);
	EXPORT i32 CalculateAngleDelta(void);
	EXPORT void TugWebTrapped(void);
	EXPORT void GetTrapped(void);
	EXPORT void DoPhysics(void);
	EXPORT void TakeHit(void);
	EXPORT void StretchJumpFlow(void);
	EXPORT void DoubleAxeHandSlash(void);
	EXPORT void StretchJumpAdvance(void);
	EXPORT void DoMGSShadow(void);
	EXPORT void DoSonicBubbleProcessing(void);
	EXPORT void GetYankedBySpidey(void);
	EXPORT void BurnInBubble(void);
	EXPORT void SelectAttack(void);
	EXPORT void AxeHandSlash(void);
	EXPORT void ThrowBlades(void);
	EXPORT void GettingGrabbed(void);

	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);

	EXPORT virtual void AI(void);
	EXPORT virtual i32 Hit(SHitInfo*);
	EXPORT virtual u8 Grab(CVector*);
	EXPORT virtual void CreateCombatImpactEffect(CVector*, i32);
	EXPORT virtual void MakeSonicRipple(CVector*);
	EXPORT virtual u8 TugImpulse(CVector*, CVector*, CVector*);

	i32 field_324;


	i32 field_328;
	void* field_32C;

	i32 field_330;
	CVector field_334;

	i32 field_340;

	CVector *field_344;

	SHandle hBubble;

	i32 field_350;

	i32 field_354;
	i32 field_358;
	i32 field_35C;

	i32 field_360;

	PADDING(0x8);

	u8 field_36C;

	CVector field_370;
};

class CSonicBubble : public CBody
{
	public:
		EXPORT CSonicBubble(void);
		EXPORT ~CSonicBubble(void);
		EXPORT void SetScale(i32);

		i32 field_F4;
};

class CCarnageElectrified : public CNonRenderedBit
{
	public:
		EXPORT CCarnageElectrified(CSuper*);
		EXPORT virtual ~CCarnageElectrified(void);

		SHandle field_3C;
		i32 field_44;
};

class CCarnageHitSpark : public CQuadBit
{
	public:
		EXPORT CCarnageHitSpark(CVector*);

		EXPORT virtual void Move(void);

		EXPORT virtual ~CCarnageHitSpark(void);
};


void validate_CCarnage(void);
void validate_CSonicBubble(void);
void validate_CCarnageElectrified(void);
void validate_CCarnageHitSpark(void);
void validate_CSonicRipple(void);

EXPORT void CreateSonicBubbleVertexWobbler(void);
EXPORT void Carnage_CreateCarnage(const u32 *stack, u32 *result);
EXPORT void Carnage_RelocatableModuleInit(reloc_mod *);
EXPORT void Carnage_RelocatableModuleClear(void);
EXPORT void SetTheCarnageGooSourcesChecksums(void);

#endif
