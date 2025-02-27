#pragma once

#ifndef TURRET_H
#define TURRET_H

#include "export.h"
#include "baddy.h"

#include "reloc.h"


class CTurret : public CBaddy {
public:
	EXPORT CTurret(i16 *,i32);

	EXPORT void TargetLockAbsolute(const CVector &);
	EXPORT void TargetLockDynamic(CBody *a2);
	EXPORT void ClearTargetLock(void);

	CVector field_324;
	unsigned char padAfter324[0x20 - sizeof(CVector)];

	CVector field_344;
	unsigned char padAfter344[0x378-0x344 - sizeof(CVector)];
	CBody *field_378;
};

class CTurretBase : public CBody {
public:
	unsigned char fullpad[0x8];
};

class CTurretLaser : public CNonRenderedBit
{
	public:
		EXPORT void SetDamage(int);

		unsigned char topPad[0x11-4];
		int field_4C;
		unsigned char bottomPad[0x64-0x4C-4];
};

void validate_CTurret(void);
void validate_CTurretBase(void);
void validate_CTurretLaser(void);

EXPORT void Turret_CreateTurret(const u32 *,u32 *);
EXPORT void Turret_RelocatableModuleClear(void);
EXPORT void Turret_RelocatableModuleInit(reloc_mod*);

#endif
