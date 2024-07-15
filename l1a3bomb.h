#pragma once

#ifndef L1A3BOMB_H
#define L1A3BOMB_H

#include "export.h"
#include "manipob.h"

class CL1A3Bomb : public CManipOb
{
	public:
		EXPORT CL1A3Bomb(u16*, i32);

		u8 field_128;
		u8 field_129;

		u8 padBottom[0x12C-0x129-1];
};

void validate_CL1A3Bomb(void);
#endif
