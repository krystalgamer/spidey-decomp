#pragma once

#ifndef RHINO_H
#define RHINO_H

#include "export.h"
#include "baddy.h"

class CRhino : public CBaddy {
public:
	EXPORT CRhino(int*, int);
	EXPORT CRhino(void);

	EXPORT void PlaySingleAnim(u32, i32, i32);
	EXPORT u32 GetNextFootstepSFX(void);
	EXPORT i32 GetShockDamage(void);
	EXPORT void ShakePad(void);

	unsigned char padTop[0x344 - 0x324];
	i32 field_344;
	u8 padAfter344[0x388-0x344-4];

	i32 field_388;
	u8 padBootm[0x424-0x388-4];
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
