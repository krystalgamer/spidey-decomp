#include "ps2pad.h"
#include "validate.h"

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

void validate_SControl(void)
{
	VALIDATE(SControl, field_140, 0x140);
	VALIDATE(SControl, field_144, 0x144);
	VALIDATE(SControl, field_148, 0x148);
	VALIDATE(SControl, field_14C, 0x14C);
}
