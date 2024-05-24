#include "switch.h"
#include "validate.h"

// @Ok
void __inline CSwitch::SwitchInactive(void)
{
	this->field_100 = 0;
}

void validate_CSwitch(void)
{
	VALIDATE_SIZE(CSwitch, 0x128);

	VALIDATE(CSwitch, field_100, 0x100);
}
