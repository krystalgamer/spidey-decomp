#pragma once

#ifndef VENOM_H
#define VENOM_H

#include "export.h"
#include "baddy.h"


class CVenom : public CBaddy {

public:

	EXPORT CVenom(i32*, i32);
	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);
	EXPORT i32* KillCommandBlock(i32*);
	EXPORT void KillAllCommandBlocks(void);
	EXPORT u8 TugImpulse(CVector *, CVector *, CVector *);
	EXPORT void PlayNextFootstepSFX(void);
	EXPORT void GetTargetPosFromNode(CVector *, i32);
	EXPORT void Lookaround(void);
	EXPORT void TugWeb(void);
	EXPORT void AdjustWaterModel(void);
	EXPORT void PulseL6A4Node(bool);
	EXPORT void VenomDie(void);

	u8 venomStartPad[0x18-0xC];
	i32 field_330;
	u8 padAfter330[4];

	i32 field_338;
	u8 field_33C;
	u8 field_33D;

	SHandle field_340;
	i32 field_348;
	u8 venomPadAfter348[0x358 - 0x348 - 4];

	i32 field_358;
	i32* field_35C;
	u8 venomPadAfter35C[0x37C-0x35C-4];

	i32 field_37C;
	i32 field_380;
	i32 field_384;
	u8 venomPadAfter384[0x14];

	i32 field_39C;
	i32 field_3A0;
	i32 field_3A4;
	i32 field_3A8;
	
	u8 venomPadAFter3A8[0x3C];

	i32 field_3E8;
	i32 field_3EC;
	i32 field_3F0;

	u8 venomPadAfter3F0[0xC];

	i32 field_400;
	i32 field_404;
	i32 field_408;
	i32 field_40C;
	i32 field_410;
	i32 field_414;
	i32 field_418;
	i32 field_41C;
	i32 field_420;
	u8 venomPadAfter420[0x30 - 0x24];

	i32 field_430;
	CQuadBit *field_434;
	u8 venomPadAfter434[0x20-4];


	i32 field_454;
	i32 field_458;
	i32 field_45C;
	i32 field_460;
	i32 field_464;
	
	// @TODO venom has two secret virtual fucnctions
};

class CVenomWrap : public CNonRenderedBit
{
	public:
		EXPORT void Die(void);
		u8 fullPad[0x20];
};

class CVenomElectrified : public CNonRenderedBit
{
	public:
		EXPORT CVenomElectrified(CSuper*);
		SHandle field_3C;
		u8 padBottom[4];
};

void validate_CVenom(void);
void validate_CVenomWrap(void);
void validate_CVenomElectrified(void);
EXPORT void Venom_CreateVenom(const unsigned int *stack, unsigned int *result);



#endif
