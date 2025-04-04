#include "switch.h"
#include "trig.h"
#include "baddy.h"
#include "spidey.h"
#include "validate.h"

extern CBody* ControlBaddyList;
extern CPlayer* MechList;
extern i32 NumNodes;
extern i16 **gTrigNodes;

// @MEDIUMTODO
CSwitch::CSwitch(i16 *,i32)
{
    printf("CSwitch::CSwitch(i16 *,i32)");
}

// @SMALLTODO
void Switch_SetSwitchFaceFlags(CItem *)
{
    printf("Switch_SetSwitchFaceFlags(CItem *)");
}

// @Ok
// @Test
void CSwitch::AI(void)
{
	if (this->mInputFlags & 1)
	{
		this->mInputFlags &= ~1;
		switch (this->field_100)
		{
			case 0:
				this->SwitchOff();
				break;
			case 1:
				this->SwitchOn();
				this->SignalAttachedItems();
				break;
			case 2:
				this->SwitchInactive();
				break;
			default:
				print_if_false(0, "invalid switch state");
				break;
		}
	}

	if (this->field_100 == 2 || this->field_100 == 3 || this->field_100 == 4)
	{
		if (this->field_FC)
		{
			this->field_F8 += this->field_80;

			if (this->field_F8 > this->field_FC)
			{
				this->field_F8 = 0;

				if (this->field_100 == 2)
				{
					this->SwitchOff();
				}
				else
				{
					this->PulseLFA1Node(this->field_124 == 0 ? 3 : 2);
					this->field_100 = 5;
				}
			}
		}
	}

	if (this->field_100 == 3 || this->field_100 == 4)
	{
		this->field_108->mFlags &= 0xFFFE;

		u32 res;
		u32 Int = this->field_108->mRGB & 0xFF;
		if (Int < 0x80)
		{
			Int += this->field_80;

			res = (((Int << 8 ) | Int) << 8) | Int;
		}
		else
		{
			res = 0x808080;
		}

		this->mRGB = res;
	}

	if (this->field_100 == 5)
	{
		u32 v18 = 4 * this->field_80;
		u32 v19 = this->field_108->mRGB & 0xFF;

		if (v19 > v18)
		{
			u32 diff = v19 - v18;
			this->field_108->mRGB = (((diff << 8) | diff) << 8) | diff;
		}
		else
		{
			this->field_108->mFlags |= 0x21;
			reinterpret_cast<CBody*>(this->field_108)->Die();
			this->field_108->mRGB = 0;
		}
	}
}

// @Ok
void CSwitch::PulseLFA1Node(i32 a1)
{
	CVector v3;
	i32 nodeIndex = 1;
	v3.vx = 0;
	v3.vy = 0;
	v3.vz = 0;

	if (NumNodes > 1)
	{
		for (; nodeIndex < NumNodes; nodeIndex++)
		{
			if (*gTrigNodes[nodeIndex] != 1)
				continue;
			Trig_GetPosition(&v3, nodeIndex);
			switch (a1)
			{
				case 0:
					if ( (v3.vx & 0xFFFFF000) != 409600 || v3.vy || v3.vz)
						break;
					Trig_SendPulseToNode(nodeIndex);
					return;
				case 1:
					if (v3.vx || v3.vy || v3.vz)
						break;
					Trig_SendPulseToNode(nodeIndex);
					return;
				case 2:
					if ( (v3.vx & 0xFFFFF000) != 409600 || v3.vy || (v3.vz & 0xFFFFF000) != 409600)
						break;
					Trig_SendPulseToNode(nodeIndex);
					return;
				case 3:
					if ( v3.vx || v3.vy || (v3.vz & 0xFFFFF000) != 409600)
						break;
					Trig_SendPulseToNode(nodeIndex);
					return;
			}
		}
	}

	print_if_false(0, "Node not found?");
}

// @Ok
void CSwitch::Flick(void)
{
	switch (this->field_100)
	{
		case 1:
			this->SwitchOn();
			this->SignalAttachedItems();
			break;
		case 2:
			this->SwitchOff();
			if (!this->field_FC)
				this->SignalAttachedItems();
			break;
		case 3:
		case 4:
			if (MechList)
				MechList->field_568 += this->field_124 ? -1 : 1;
			this->PulseLFA1Node(this->field_124 == 0);
			this->field_100 = 5;
			break;
		case 5:
			if (MechList)
				MechList->field_568 += this->field_124 ? -1 : 1;
			break;
		default:
			return;
	}
}

// @Ok
CSwitch* Switch_GetCSwitchObjectFromItem(CItem *pItem)
{
	print_if_false(pItem != 0, "Bad item");

	for (CItem *cur = ControlBaddyList; cur; cur = reinterpret_cast<CItem*>(cur->mNextItem))
	{
		if (cur->mType == 407)
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
INLINE void CSwitch::SignalAttachedItems(void)
{
	Trig_SendPulse(Trig_GetLinksPointer(this->mNode));
}

// @Ok
void INLINE CSwitch::SwitchInactive(void)
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
void INLINE Switch_SetVisible(bool a1, CItem* pItem)
{
	print_if_false(pItem != 0, "Bad item");

	if (a1)
		pItem->mFlags &= 0xFFDE;
	else
		pItem->mFlags |= 0x21;
}

// @Ok
void INLINE CSwitch::SwitchOff(void)
{
	this->field_100 = 1;
	Switch_SetVisible(false, this->field_108);
	Switch_SetVisible(true, this->field_104);
}


void validate_CSwitch(void)
{
	VALIDATE_SIZE(CSwitch, 0x128);

	VALIDATE(CSwitch, field_F8, 0xF8);
	VALIDATE(CSwitch, field_FC, 0xFC);

	VALIDATE(CSwitch, field_100, 0x100);

	VALIDATE(CSwitch, field_104, 0x104);
	VALIDATE(CSwitch, field_108, 0x108);

	VALIDATE(CSwitch, field_10C, 0x10C);
	VALIDATE(CSwitch, field_118, 0x118);

	VALIDATE(CSwitch, field_124, 0x124);
}
