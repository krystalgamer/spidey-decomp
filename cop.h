#pragma once

#ifndef COP_H
#define COP_H

#include "export.h"
#include "baddy.h"
#include "mem.h"
#include "m3dutils.h"
#include "weapons.h"


class CCop : public CBaddy {

public:
	EXPORT CCop(int*, int);
	EXPORT void ClearAttackFlags(void);
	EXPORT void LookForPlayer(void);

	EXPORT virtual void Victorious(void);

	i32 field_324;
	u8 padAfter324[0x340-0x324-4];

	int field_340;
	unsigned char padAfter340[0x20 - 4];

	int field_360;
	int field_364;
	int field_368;
	int field_36C;
	int field_370;
	int field_374;
	unsigned char padAfter374[0x37C - 0x374 - 4];
	int field_37C;
	unsigned char padAfter37C[0x390 - 0x37C - 4];

	unsigned char field_390;
	unsigned char field_391;
	unsigned char endPad[0x394 - 0x391 - 1];
};

class CCopPing : public CSimpleAnim
{
	public:
		EXPORT CCopPing(CSuper*, SHook*);
		EXPORT void Move(void);
		EXPORT void SetPosition(void);

		unsigned char padTop[8];
		SHandle field_70;
		SHook field_78;
};

class CCopBulletTracer : public CNonRenderedBit
{
	public:
		EXPORT CCopBulletTracer(CVector*, CVector*, CSuper*, SLineInfo*, u8, u8, u8);
		EXPORT virtual ~CCopBulletTracer(void);

		EXPORT void SetWidth(void);

		EXPORT virtual void Move(void);

		CGouradRibbon *field_3C;
		CGouradRibbon *field_40;

		u8 padBottom[0x48-0x40-4];
};


void validate_CCop(void);
void validate_CCopPing(void);
void validate_CCopBulletTracer(void);

EXPORT void Cop_CreateCop(const unsigned int *stack, unsigned int *result);


#endif
