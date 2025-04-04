#ifndef EXP_H
#define EXP_H

#pragma once

#include "ob.h"

class CRipple : public CGlow
{
	public:
		u8 field_5C[4];
		i32 field_60;
		i32 field_64;
		i32 field_68;
		

		EXPORT CRipple(const CVector *,u8,u8,u8,i32,i32,i32,i32);
		EXPORT ~CRipple(void);

		EXPORT virtual void Move(void);
};

class CGrenadeWave : public CRipple
{
	public:
		EXPORT CGrenadeWave(const CVector *,u8,u8,u8,i32,i32);
		EXPORT ~CGrenadeWave(void);

		EXPORT void Move(void);

		i32 field_6C;
};

class C3DExplosion : public CBody
{
	public:
		EXPORT C3DExplosion(const CVector *,char *,i32,i32,i32,i32,i32,i32,i32,i32,i32);
		EXPORT ~C3DExplosion(void);
		EXPORT virtual void AI(void);

		PADDING(4);

		u8 field_F8;

		PADDING(3);

		i32 field_FC;
		i32 field_100;

		i32 field_104;
		i32 field_108;
		i32 field_10C;
		i32 field_110;
};

class CWibbling3DExplosion : public C3DExplosion
{
	public:
		EXPORT CWibbling3DExplosion(const CVector *,char *,i32,i32,i32,i32,i32,i32,i32,i32,i32);
		EXPORT ~CWibbling3DExplosion(void);
};


class CGrenadeExplosion : public CNonRenderedBit
{
	public:
		EXPORT CGrenadeExplosion(const CVector*);
		EXPORT virtual ~CGrenadeExplosion(void) OVERRIDE;

		EXPORT virtual void Move(void);

		SHandle hExp;

		PADDING(0x4C-0x3C-sizeof(SHandle));
};

class CFlameExplosion : public CNonRenderedBit
{
	public:
		EXPORT CFlameExplosion(const CVector*, i32, i32, i32);
		EXPORT virtual ~CFlameExplosion(void) OVERRIDE;

		PADDING(2);

		u8 field_3E;
		u8 field_3F;

		// @FIXME guess type
		void* field_40[20];

		// @FIXME missing vmethod
};

class CItemFrag : public CBit
{
	public:

		EXPORT CItemFrag(u32 *,CVector *,CVector *,i32);
		EXPORT ~CItemFrag(void);

		EXPORT virtual void Move(void);

		u8 itemFragPad[0x7C];

};

class CGlowFlash : public CGlow
{
	public:
		EXPORT CGlowFlash(CVector*, i32, u8, u8, u8, i32, u8, u8, u8, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32);
		EXPORT ~CGlowFlash(void);

		EXPORT void ChooseRadii(void);
		EXPORT virtual void Move(void);

		i16 field_5C;
		i16 field_5E;
		i16 field_60;
		i16 field_62;
		i16 field_64;
		i16 field_66;
		i16 field_68;
		i16 field_6A;
		u8 field_6C;

		PADDING(0x70-0x6C-1);
};

EXPORT extern i32 g3DExplosions;
EXPORT extern i32 gWibblingExpCount;

EXPORT void Exp_HitEnvItem(CItem*, u32*, i32);
EXPORT void Exp_GlowFlash(CVector*, i32, u8, u8, u8, i32, i32, i32);

EXPORT void Exp_BigExplosion(CVector*);
EXPORT void Exp_Frag(CVector*, i32, i32, i32, i32);
EXPORT void Exp_SmallExplosion(CVector*);

EXPORT void Exp_Big3DExplosion(const CVector *);
EXPORT void GetRandomPosition(const CVector *,CVector *,i32);


void validate_CItemFrag(void);
void validate_CGlowFlash(void);
void validate_CFlameExplosion(void);

void validate_CWibbling3DExplosion(void);
void validate_C3DExplosion(void);
void validate_CGrenadeWave(void);
void validate_CGrenadeExplosion(void);
void validate_CRipple(void);

#endif
