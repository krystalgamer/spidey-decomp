#include "ps2pad.h"
#include "validate.h"

SControl gSControl;

static int gPadActuator[255];
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

// @SMALLTODO
void Pad_Button(SButton *,i32)
{
    printf("Pad_Button(SButton *,i32)");
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
	VALIDATE(SControl, field_140, 0x140);
	VALIDATE(SControl, field_144, 0x144);
	VALIDATE(SControl, field_148, 0x148);
	VALIDATE(SControl, field_14C, 0x14C);
}
