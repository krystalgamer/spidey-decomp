#pragma once

#ifndef POWERUP_H
#define POWERUP_H

#include "ob.h"
#include "export.h"

class CPowerUp : public CBody
{
	public:
		EXPORT void SetGravity(int, int);
		EXPORT void SetNode(int);

		unsigned char padTop[0x100-0xF4];
		unsigned char field_100;
		unsigned char padAfter100[0x106-0x100-1];

		__int16 field_106;
		unsigned char padBottom[0x138-0x106-2];
};

void validate_CPowerUp(void);
#endif
