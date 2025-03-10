#pragma once

#ifndef CARNAGE_H
#define CARNAGE_H

#include "export.h"
#include "baddy.h"
#include "reloc.h"

class CCarnage : public CBaddy {
public:
	EXPORT CCarnage(i32*, i32);
	EXPORT ~CCarnage(void);

	EXPORT void PulseL8A5Node(void);
	EXPORT void DieCarnage(void);
	EXPORT void PlayXA(i32, i32, i32);

	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);

	EXPORT virtual void CreateCombatImpactEffect(CVector*, i32);

	u8 carnageStartPad[0x8];

	void* field_32C;
	u8 padAfter32C[0x334-0x32C-4];

	i32 field_334;
	i32 field_338;
	i32 field_33C;
	u8 padAfter33c[0x344-0x33C-4];

	void* field_344;
	u8 padAfter344[0x354-0x344-4];

	i32 field_354;
	i32 field_358;
	i32 field_35C;
	unsigned char padAfter35C[0x10-4];

	int field_36C;
	int field_370;
	int field_374;
	int field_378;
};

class CSonicBubble : public CBody
{
	public:
		EXPORT CSonicBubble(void);
		EXPORT ~CSonicBubble(void);
		EXPORT void SetScale(int);

		int field_F4;
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

EXPORT void CreateSonicBubbleVertexWobbler(void);
EXPORT void Carnage_CreateCarnage(const unsigned int *stack, unsigned int *result);
EXPORT void Carnage_RelocatableModuleInit(reloc_mod *);
EXPORT void Carnage_RelocatableModuleClear(void);
EXPORT void SetTheCarnageGooSourcesChecksums(void);

#endif
