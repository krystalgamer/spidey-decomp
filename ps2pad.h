#pragma once

#ifndef PS2PAD_H
#define PS2PAD_H

#include "export.h"

struct SControl
{
	u8 pad[0x140];

	i32 field_140;
	i32 field_144;
	i32 field_148;
	i32 field_14C;
};

EXPORT void Pad_SetDigitalMapping(SControl*, i32, i32, i32, i32);
EXPORT void Pad_ActuatorOff(u8, u8);
EXPORT u16 Pad_GetActuatorTime(u8, u8);
EXPORT void Pad_ActuatorOn(u8, u16, u8, u8);
EXPORT extern SControl gSControl;

void validate_SControl(void);

#endif
