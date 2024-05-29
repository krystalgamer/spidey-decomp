#include "switch.h"
#include "validate.h"

// @Ok
void __inline CSwitch::SwitchInactive(void)
{
	this->field_100 = 0;
}

// @Ok
CVector* CSwitch::GetAutoAimTargetPointer(void)
{
	switch(this->field_100)
	{
		case 1:
			return &this->field_10C;
		case 2:
		case 3:
		case 4:
		case 5:
			return &this->field_118;
		default:
			return NULL;
	}
}

void validate_CSwitch(void)
{
	VALIDATE_SIZE(CSwitch, 0x128);

	VALIDATE(CSwitch, field_100, 0x100);

	VALIDATE(CSwitch, field_10C, 0x10C);
	VALIDATE(CSwitch, field_118, 0x118);
}
