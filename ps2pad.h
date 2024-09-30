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

struct SButton
{
	u8 Pressed;
	u8 Triggered;
	u8 field_2;

	i32 PressedTime;
	i32 ReleasedTime;
	i32 TriggeredTime;
};

EXPORT void Pad_SetDigitalMapping(SControl*, i32, i32, i32, i32);
EXPORT void Pad_ActuatorOff(u8, u8);
EXPORT u16 Pad_GetActuatorTime(u8, u8);
EXPORT void Pad_ActuatorOn(u8, u16, u8, u8);
EXPORT void DCPad_ExpireVibrations(void);
EXPORT void DCPad_ShutDownVibrations(void);
EXPORT void DCPad_Vibrate(i32,signed char,u8,u8);
EXPORT void Pad_Button(SButton *,i32);
EXPORT void Pad_Clear(SControl *);
EXPORT void Pad_ClearAll(void);
EXPORT void Pad_ClearAllOne(i32);
EXPORT void Pad_ClearTriggers(SControl *);
EXPORT void Pad_InitAtStart(void);
EXPORT void Pad_SetAnalogueMapping(SControl *,u8,u8,u8,u8,i32,i32,i32,i32);
EXPORT void Pad_Update(void);

void validate_SControl(void);
void validate_SButton(void);
EXPORT extern SControl gSControl;

#endif
