#pragma once

#ifndef POWERUP_H
#define POWERUP_H

#include "ob.h"
#include "export.h"

class CPowerUp : public CBody
{
	public:
		EXPORT void SetGravity(i32, i32);
		EXPORT void SetNode(i32);
		EXPORT void CreateBit(void);

		u8 padTop[0x100-0xF4];
		u8 field_100;
		u8 padAfter100[0x106-0x100-1];

		i16 field_106;
		u8 padAfter106[0x130-0x106-2];

		CFlatBit* field_130;
		u8 padBottom[0x138-0x130-4];
};

void validate_CPowerUp(void);
#endif
