#include "ps2pad.h"
#include "PCInput.h"
#include "PCShell.h"
#include "utils.h"
#include "pcdcPad.h"
#include "dcmemcard.h"

#include "validate.h"

SControl gSControl[NUM_CONTROLLERS];
EXPORT i32 Pad_IdleTime;

// @OK
EXPORT u8 gPadVibrate[5];

// @Ok
// @FIXME - is it really 2?
EXPORT i32 gPadActuator[2];

// @Ok
EXPORT u8 gPadOne = 0x3B;
// @Ok
EXPORT u8 gPadTwo;

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

// @Ok
// @Matching
void Pad_ActuatorOn(
		u8 a1,
		u16 a2,
		u8 a3,
		u8 a4)
{
	gPadActuator[a1] = Vblanks + a2 + 10;
	DCPad_Vibrate(a1, 5 * a3 + 2, gPadOne, gPadTwo);
}

// @Ok
// @Matching
void DCPad_ExpireVibrations(void)
{
	for (i32 i = 0; i < 2; i++)
	{
		u32 v4 = gPadActuator[i];
		if (v4)
		{
			if (Vblanks > v4)
			{
				pdVibMxStop(gAlarmFirst[2 * i]);
				pdVibMxStop(gAlarmFirst[2 * i + 1]);
				gPadActuator[i] = 0;
			}
		}
	}
}

static void nullsub_3(void)
{
}

// @Ok
// @Matching
void DCPad_ShutDownVibrations(void)
{
	for (i32 i = 0; i < 4; i++)
	{
		pdVibMxStop(gAlarmFirst[i]);
	}

	nullsub_3();
	gPadActuator[0] = 1;
	gPadActuator[1] = 1;
}

// @Ok
// @NotMatching: uses one more register
i32 DCPad_Vibrate(
		i32 a1,
		i8 a2,
		u8 a3,
		u8 a4)
{
	i32 limit = (a1*2)+2;
	for (i32 i = a1 *2; i < limit; i++)
	{
		if (pdGetPeripheral(6 * (i/2))->pBig->field_0)
		{
			i32 val = gAlarmFirst[i];
			if (pdVibMxIsReady(val) == 1)
			{
				gPadVibrate[0] = 1;
				gPadVibrate[1] = 1;
				gPadVibrate[2] = a2;
				gPadVibrate[3] = a3;
				gPadVibrate[4] = a4;
				do
				{
				}
				while (pdVibMxStart(val, gPadVibrate));
				break;
			}
		}
	}


	return 0;
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

// @Ok
// @Matching
void Pad_SetAnalogueMapping(
		SControl *pControl,
		u8 a2,
		u8 a3,
		u8 a4,
		u8 a5,
		i32 a6,
		i32 a7,
		i32 a8,
		i32 a9)
{
	pControl->field_160 = a2;
	pControl->field_161 = a3;
	pControl->field_162 = a4;
	pControl->field_163 = a5;

	pControl->field_150 = a6;
	pControl->field_154 = a7;
	pControl->field_158 = a8;
	pControl->field_15C = a9;
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

	VALIDATE(SControl, field_150, 0x150);
	VALIDATE(SControl, field_154, 0x154);
	VALIDATE(SControl, field_158, 0x158);
	VALIDATE(SControl, field_15C, 0x15C);

	VALIDATE(SControl, field_160, 0x160);
	VALIDATE(SControl, field_161, 0x161);
	VALIDATE(SControl, field_162, 0x162);
	VALIDATE(SControl, field_163, 0x163);

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
