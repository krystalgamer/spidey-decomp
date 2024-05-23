#pragma once

#ifndef POWERUP_H
#define POWERUP_H

#include "ob.h"
#include "export.h"

class CPowerUp : public CBody
{
	public:
		EXPORT void SetGravity(int, int);
		unsigned char pad[0x138-0xF4];
};

void validate_CPowerUp(void);
#endif
