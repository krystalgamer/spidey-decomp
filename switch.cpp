#include "switch.h"
#include "trig.h"
#include "validate.h"

// @Ok
void CSwitch::SignalAttachedItems(void)
{
	Trig_SendPulse(Trig_GetLinksPointer(this->field_DE));
}

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

// @Ok
void __inline Switch_SetVisible(bool a1, CItem* pItem)
{
	print_if_false(pItem != 0, "Bad item");

	if (a1)
		pItem->mFlags &= 0xFFDE;
	else
		pItem->mFlags |= 0x21;
}

// @Ok
void __inline CSwitch::SwitchOff(void)
{
	this->field_100 = 1;
	Switch_SetVisible(false, this->field_108);
	Switch_SetVisible(true, this->field_104);
}


void validate_CSwitch(void)
{
	VALIDATE_SIZE(CSwitch, 0x128);

	VALIDATE(CSwitch, field_100, 0x100);

	VALIDATE(CSwitch, field_104, 0x104);
	VALIDATE(CSwitch, field_108, 0x108);

	VALIDATE(CSwitch, field_10C, 0x10C);
	VALIDATE(CSwitch, field_118, 0x118);
}
