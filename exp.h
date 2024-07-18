#ifndef EXP_H
#define EXP_H

#pragma once

#include "ob.h"

class CItemFrag : public CBit
{
	public:
		unsigned char itemFragPad[0x7C];
};

EXPORT void Exp_HitEnvItem(CItem*, u32*, i32);
void validate_CItemFrag(void);

#endif
