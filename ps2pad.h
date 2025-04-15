#pragma once

#ifndef PS2PAD_H
#define PS2PAD_H

#include "export.h"

struct SButton
{
	u8 Pressed;
	u8 Triggered;
	u8 field_2;

	i32 PressedTime;
	i32 ReleasedTime;
	i32 TriggeredTime;
};

struct SControl
{
	SButton Triangle;
	SButton Square;
	SButton Circle;
	SButton X;
	SButton LeftOne;
	SButton LeftTwo;
	SButton RightOne;
	SButton RightTwo;
	SButton Left;
	SButton Right;
	SButton Up;
	SButton Down;

	SButton AnalogueLeft;
	SButton AnalogueRight;

	SButton Start;
	SButton Select;

	SButton Crouch;
	SButton Jump;
	SButton SmartBomb;
	SButton SelectWeapon;

	i32 field_140;
	i32 field_144;
	i32 field_148;
	i32 field_14C;

	i32 field_150;
	i32 field_154;
	i32 field_158;
	i32 field_15C;

	u8 field_160;
	u8 field_161;
	u8 field_162;
	u8 field_163;

	PADDING(0x168-0x163-1);

	u8 field_168;
	u8 field_169;
	u8 field_16A;
	u8 field_16B;

	i32 field_16C;

	PADDING(0x18C-0x16C-4);
};

EXPORT void Pad_SetDigitalMapping(SControl*, i32, i32, i32, i32);
EXPORT void Pad_ActuatorOff(u8, u8);
EXPORT u16 Pad_GetActuatorTime(u8, u8);
EXPORT void Pad_ActuatorOn(u8, u16, u8, u8);
EXPORT void DCPad_ExpireVibrations(void);
EXPORT void DCPad_ShutDownVibrations(void);
EXPORT i32 DCPad_Vibrate(i32,signed char,u8,u8);
EXPORT void Pad_Button(SButton *,i32);
EXPORT void Pad_Clear(SControl *);
EXPORT void Pad_ClearAll(void);
EXPORT void Pad_ClearAllOne(i32);
EXPORT void Pad_ClearTriggers(SControl *);
EXPORT void Pad_InitAtStart(void);
EXPORT void Pad_SetAnalogueMapping(SControl *,u8,u8,u8,u8,i32,i32,i32,i32);
EXPORT i32 Pad_Update(void);

void validate_SControl(void);
void validate_SButton(void);

static const i32 NUM_CONTROLLERS = 1;
EXPORT extern SControl gSControl[NUM_CONTROLLERS];
EXPORT extern i32 Pad_IdleTime;

#endif
