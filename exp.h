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

		u8 padBottom[0x14];
};

EXPORT void Exp_HitEnvItem(CItem*, u32*, i32);
EXPORT void Exp_GlowFlash(CVector*, i32, u8, u8, u8, i32, i32, i32);

void validate_CItemFrag(void);
void validate_CGlowFlash(void);

#endif
