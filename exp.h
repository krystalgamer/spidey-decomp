#ifndef EXP_H
#define EXP_H

#pragma once

#include "ob.h"

class CItemFrag : public CBit
{
	public:
		unsigned char itemFragPad[0x7C];
};

class CGlowFlash : public CGlow
{
	public:
		EXPORT CGlowFlash(CVector*, i32, u8, u8, u8, i32, u8, u8, u8, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32);
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

		u8 padBottom[0x70-0x6C-1];
};

EXPORT void Exp_HitEnvItem(CItem*, u32*, i32);
EXPORT void Exp_GlowFlash(CVector*, i32, u8, u8, u8, i32, i32, i32);

void validate_CItemFrag(void);
void validate_CGlowFlash(void);

#endif
