#include "exp.h"
#include "validate.h"

static i32 gMemInitRelatedTop;

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

// @SMALLTODO
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
	if ( !gMemInitRelatedTop )
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
