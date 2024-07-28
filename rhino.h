#pragma once

#ifndef RHINO_H
#define RHINO_H

#include "export.h"
#include "baddy.h"

class CRhino : public CBaddy {
public:
	EXPORT CRhino(int*, int);
	EXPORT CRhino(void);
	EXPORT virtual ~CRhino(void);

	EXPORT void PlaySingleAnim(u32, i32, i32);
	EXPORT u32 GetNextFootstepSFX(void);
	EXPORT i32 GetShockDamage(void);
	EXPORT void ShakePad(void);
	EXPORT void StandStill(void);
	EXPORT void FuckUpSomeBarrels(void);
	EXPORT void RhinoInit(void);
	EXPORT void Laugh(void);
	EXPORT void HitWall(void);

	unsigned char padTop[0x344 - 0x324];
	i32 field_344;
	u8 padAfter344[0x358-0x344-4];

	i32 field_358;
	u8 padAfter358[0x388-0x358-4];

	i32 field_388;
	u8 padAfter88[0x3E0-0x388-4];

	u32 field_3E0;
	u32 field_3E4[5];
	u32 field_3F8[5];
	u32 field_40C[5];

	u8 padBottom[0x424-0x420];
};

class CRhinoNasalSteam : public CFlatBit
{
	public:
		EXPORT CRhinoNasalSteam(CVector*, CVector*);
		EXPORT void Move(void);
};

void validate_CRhino(void);
void validate_CRhinoNasalSteam(void);
EXPORT void Rhino_CreateRhino(const unsigned int *stack, unsigned int *result);


#endif
