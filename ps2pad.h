#pragma once

#ifndef PS2PAD_H
#define PS2PAD_H

#include "export.h"

struct SControl
{
	unsigned char pad[0x140];

	int field_140;
	int field_144;
	int field_148;
	int field_14C;
};

EXPORT void Pad_SetDigitalMapping(SControl*, int, int, int, int);
EXPORT void Pad_ActuatorOff(unsigned char, unsigned char);

void validate_SControl(void);

#endif
