#include "exp.h"
#include "utils.h"
#include "mem.h"

#include "validate.h"

// @Ok
void Exp_SmallExplosion(CVector* a1)
{
	if ( !LowMemory )
	{
		Exp_Frag(a1, Rnd(20), 6u, 750, 80);
		Exp_GlowFlash(a1, 70, 0xF0u, 0xC8u, 0, 5, 0, 100);
	}
}

// @Ok
void Exp_Frag(CVector* a1, i32 a2, i32 a3, i32 a4, i32 a5)
{
	if (!LowMemory)
	{
		for (i32 i = 0; i < a2; i++)
		{
			new CFrag(a1, 0x80u, 0x80u, 0x80u, a3, a4, 1, a5, 12288, 30);
		}
	}
}

// @Ok
void Exp_BigExplosion(CVector *a1)
{
	if ( !LowMemory )
	{
		Exp_Frag(a1, Rnd(20), 6u, 750, 80);
		Exp_GlowFlash(a1, 200, 0xF0u, 0xC8u, 0, 5, 0, 100);
	}
}

// @NotOk
// @FIXME guess type of field_40
CFlameExplosion::~CFlameExplosion(void)
{
	for (i32 i = 0; i < 20; i++)
	{
		delete reinterpret_cast<CItem*>(field_40[i]);
	}
}

// @Ok
CFlameExplosion::CFlameExplosion(
		CVector* a2,
		i32 a3,
		i32 a4,
		i32 a5)
{
	this->mPos = *a2;
	this->field_E = a3;

	this->field_3E = a5;
	this->field_3F = a4;
}

// @Ok
CGlowFlash::CGlowFlash(
		CVector* a2,
		i32 a3,
		u8 a4,
		u8 a5,
		u8 a6,
		i32 a7,
		u8 a8,
		u8 a9,
		u8 a10,
		i32 a11,
		i32 a12,
		i32 a13,
		i32 a14,
		i32 a15,
		i32 a16,
		i32 a17,
		i32 a18,
		i32 a19,
		i32 a20)
	: CGlow(a3, 1)
{
	this->mPos = *a2;
	this->SetCentreRGB(a4, a5, a6);
	this->field_5C = a7;
	this->SetRGB(a8, a9, a10);
	this->field_5E = a11;
	this->SetFringeRGB(0, 0, 0, 0);
	this->SetFringeWidth(0, a12);
	this->field_60 = a13;
	this->field_6C = a14;
	this->field_64 = a16;
	this->field_62 = a15;
	this->field_6A = a19;
	this->field_66 = a17;
	this->field_68 = a18;
	this->field_E = a20;
	print_if_false(a20 || this->field_5C, "CGlowFlash centrefaderate and lifetime both zero.");
	this->ChooseRadii();
}

// @SMALLTODO
void CGlowFlash::ChooseRadii(void)
{
	printf("CGlowFlash::ChooseRadii(void)");
}

// @SMALLTODO
void CGlowFlash::Move(void)
{
	printf("CGlowFlash::Move(void)");
}

// @SMALLTODO
void Exp_HitEnvItem(CItem* pItem, u32* pFace, i32 Damage)
{
	printf("Exp_HitEnvItem");
}

// @Ok
void Exp_GlowFlash(
		CVector* a1,
		i32 a2,
		u8 a3,
		u8 a4,
		u8 a5,
		i32 a6,
		i32 a7,
		i32 a8)
{
	if ( !LowMemory )
	{
		if ( a7 )
		{
			new CGlowFlash(
				a1,
				a6,
				a3,
				a4,
				a5,
				2,
				a3,
				a4,
				a5,
				20,
				a8,
				0,
				0,
				a2,
				a2,
				a2 / 2,
				a2 / 2,
				0,
				0);
		}
		else
		{
			new CGlowFlash(a1, a6, a3, a4, a5, 2, a3, a4, a5, 20, a8, 0, 0, a2, 0, a2, 0, 0, 0);
		}
	}
}


void validate_CItemFrag(void)
{
	VALIDATE_SIZE(CItemFrag, 0xB8);
}

void validate_CGlowFlash(void)
{
	VALIDATE_SIZE(CGlowFlash, 0x70);

	VALIDATE(CGlowFlash, field_5C, 0x5C);
	VALIDATE(CGlowFlash, field_5E, 0x5E);
	VALIDATE(CGlowFlash, field_60, 0x60);
	VALIDATE(CGlowFlash, field_62, 0x62);
	VALIDATE(CGlowFlash, field_64, 0x64);
	VALIDATE(CGlowFlash, field_66, 0x66);
	VALIDATE(CGlowFlash, field_68, 0x68);
	VALIDATE(CGlowFlash, field_6A, 0x6A);
	VALIDATE(CGlowFlash, field_6C, 0x6C);
}

void validate_CFlameExplosion(void)
{
	VALIDATE_SIZE(CFlameExplosion, 0x90);

	VALIDATE(CFlameExplosion, field_3E, 0x3E);
	VALIDATE(CFlameExplosion, field_3F, 0x3F);

	VALIDATE(CFlameExplosion, field_40, 0x40);
}
