#include "switch.h"
#include "trig.h"
#include "baddy.h"
#include "validate.h"

extern CBaddy* ControlBaddyList;

// @Ok
CSwitch* Switch_GetCSwitchObjectFromItem(CItem *pItem)
{
	print_if_false(pItem != 0, "Bad item");

	for (CItem *cur = ControlBaddyList; cur; cur = reinterpret_cast<CItem*>(cur->field_20))
	{
		if (cur->field_38 == 407)
		{
			CSwitch* pSwitch = reinterpret_cast<CSwitch*>(cur);

			if (pSwitch->field_104 == pItem || pSwitch->field_108 == pItem)
				return pSwitch;
		}
	}

	return 0;
}

// @Ok
CSwitch::~CSwitch(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&ControlBaddyList));
}

// @Ok
INLINE void CSwitch::SwitchOn(void)
{
	this->field_F8 = 0;
	this->field_100 = 2;

	Switch_SetVisible(1, this->field_108);
	Switch_SetVisible(0, this->field_104);
}

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

	VALIDATE(CSwitch, field_F8, 0xF8);

	VALIDATE(CSwitch, field_100, 0x100);

	VALIDATE(CSwitch, field_104, 0x104);
	VALIDATE(CSwitch, field_108, 0x108);

	VALIDATE(CSwitch, field_10C, 0x10C);
	VALIDATE(CSwitch, field_118, 0x118);
}
