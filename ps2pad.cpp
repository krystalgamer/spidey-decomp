#include "ps2pad.h"
#include "validate.h"

static int gPadActuator[255];
// @NotOk
// global
void Pad_ActuatorOff(unsigned char a1, unsigned char)
{
	gPadActuator[a1] = 1;
}

// @Ok
void Pad_SetDigitalMapping(SControl *pControl, int a2, int a3, int a4, int a5)
{
	pControl->field_140 = a2;
	pControl->field_144 = a3;
	pControl->field_148 = a4;
	pControl->field_14C = a5;
}

void validate_SControl(void)
{
	VALIDATE(SControl, field_140, 0x140);
	VALIDATE(SControl, field_144, 0x144);
	VALIDATE(SControl, field_148, 0x148);
	VALIDATE(SControl, field_14C, 0x14C);
}
