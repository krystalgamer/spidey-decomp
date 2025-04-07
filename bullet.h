#pragma once


#ifndef BULLET_H
#define BULLET_H

#include "export.h"
#include "ob.h"
#include "weapons.h"

EXPORT extern CBody* BulletList;
enum HitId
{
	ALWAYS_TWENTY_NINE = 29,
};

class CBullet : public CBody
{
	public:
		EXPORT CBullet(void);
		EXPORT virtual ~CBullet(void);

		EXPORT void BlowUp(void);
		EXPORT void GiveScaledDamageToEnviro(i32);
		EXPORT void GiveScaledDamageToObjects(CBody *,i32,i32,i32,HitId);

		PADDING(0x104-0xF4);

		u16 field_104;

		PADDING(0x10C-0x104-2);

		void* field_10C;

		PADDING(4);

		i32 field_114;
		i32 field_118;
		i32 field_11C;
		void *field_120;


		PADDING(0x130-0x120-4);

		i32 field_130;
		i32 field_134;
		i32 field_138;
};

class CSmokePuff : public CSmokeRing
{
	public:
		EXPORT CSmokePuff(CVector*);
		EXPORT virtual ~CSmokePuff(void) OVERRIDE;

		EXPORT virtual void Move(void) OVERRIDE;
};

void validate_CSmokePuff(void);
void validate_CBullet(void);
#endif
