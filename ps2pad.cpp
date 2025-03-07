#include "ps2pad.h"
#include "PCInput.h"
#include "PCShell.h"

#include "validate.h"

SControl gSControl[NUM_CONTROLLERS];
EXPORT i32 Pad_IdleTime;

i32 gPadActuator[255];

// @NotOk
// global
void Pad_ActuatorOff(u8 a1, u8)
{
	gPadActuator[a1] = 1;
}

// @Ok
void Pad_SetDigitalMapping(SControl *pControl, i32 a2, i32 a3, i32 a4, i32 a5)
{
	pControl->field_140 = a2;
	pControl->field_144 = a3;
	pControl->field_148 = a4;
	pControl->field_14C = a5;
}

// @MEDIUMTODO
u16 Pad_GetActuatorTime(u8, u8)
{
	return 0x020702024;
}

// @SMALLTODO
void Pad_ActuatorOn(u8, u16, u8, u8)
{
	printf("void Pad_ActuatorOn(u8, u16, u8, u8)");
}

// @SMALLTODO
void DCPad_ExpireVibrations(void)
{
    printf("DCPad_ExpireVibrations(void)");
}

// @SMALLTODO
void DCPad_ShutDownVibrations(void)
{
    printf("DCPad_ShutDownVibrations(void)");
}

// @SMALLTODO
void DCPad_Vibrate(i32,signed char,u8,u8)
{
    printf("DCPad_Vibrate(i32,signed char,u8,u8)");
}


// @Ok
// @Matching
void Pad_Button(SButton* pBut, i32 state)
{
	pBut->TriggeredTime++;
	if (!pBut->Pressed)
	{
		if (state)
		{
			pBut->Triggered = 1;
			pBut->field_2 = pBut->TriggeredTime < 10;
			pBut->TriggeredTime = 0;
		}
	}
	else
	{
		pBut->field_2 = 0;
	}

	if ( state )
	{
		Pad_IdleTime = 0;
		pBut->Pressed = 1;
	}
	else
	{
		pBut->Pressed = 0;
	}

	if ( pBut->Pressed )
	{
		pBut->PressedTime++;
		pBut->ReleasedTime = 0;
	}
	else
	{
		pBut->PressedTime = 0;
		pBut->ReleasedTime++;
	}
}

// @SMALLTODO
void Pad_Clear(SControl *)
{
    printf("Pad_Clear(SControl *)");
}

// @SMALLTODO
void Pad_ClearAll(void)
{
    printf("Pad_ClearAll(void)");
}

// @SMALLTODO
void Pad_ClearAllOne(i32)
{
    printf("Pad_ClearAllOne(i32)");
}

// @SMALLTODO
void Pad_ClearTriggers(SControl *)
{
    printf("Pad_ClearTriggers(SControl *)");
}

// @SMALLTODO
void Pad_InitAtStart(void)
{
    printf("Pad_InitAtStart(void)");
}

// @SMALLTODO
void Pad_SetAnalogueMapping(SControl *,u8,u8,u8,u8,i32,i32,i32,i32)
{
    printf("Pad_SetAnalogueMapping(SControl *,u8,u8,u8,u8,i32,i32,i32,i32)");
}

void validate_SControl(void)
{
	VALIDATE_SIZE(SControl, 0x18C);

	VALIDATE(SControl, Triangle, 0x0);
	VALIDATE(SControl, Square, 0x10);
	VALIDATE(SControl, Circle, 0x20);
	VALIDATE(SControl, X, 0x30);

	VALIDATE(SControl, LeftOne, 0x40);
	VALIDATE(SControl, LeftTwo, 0x50);

	VALIDATE(SControl, RightOne, 0x60);
	VALIDATE(SControl, RightTwo, 0x70);

	VALIDATE(SControl, Left, 0x80);
	VALIDATE(SControl, Right, 0x90);
	VALIDATE(SControl, Up, 0xA0);
	VALIDATE(SControl, Down, 0xB0);

	VALIDATE(SControl, AnalogueLeft, 0xC0);
	VALIDATE(SControl, AnalogueRight, 0xD0);

	VALIDATE(SControl, Start, 0xE0);
	VALIDATE(SControl, Select, 0xF0);

	VALIDATE(SControl, Crouch, 0x100);
	VALIDATE(SControl, Jump, 0x110);
	VALIDATE(SControl, SmartBomb, 0x120);
	VALIDATE(SControl, SelectWeapon, 0x130);

	VALIDATE(SControl, field_140, 0x140);
	VALIDATE(SControl, field_144, 0x144);
	VALIDATE(SControl, field_148, 0x148);

	VALIDATE(SControl, field_140, 0x140);
	VALIDATE(SControl, field_144, 0x144);
	VALIDATE(SControl, field_148, 0x148);
	VALIDATE(SControl, field_14C, 0x14C);

	VALIDATE(SControl, field_16C, 0x16C);
}

void validate_SButton(void)
{
	VALIDATE_SIZE(SButton, 0x10);

	VALIDATE(SButton, Pressed, 0x0);
	VALIDATE(SButton, Triggered, 0x1);
	VALIDATE(SButton, field_2, 0x2);


	VALIDATE(SButton, PressedTime, 0x4);
	VALIDATE(SButton, ReleasedTime, 0x8);
	VALIDATE(SButton, TriggeredTime, 0xC);
}
