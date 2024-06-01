#pragma once

#ifndef SWITCH_H
#define SWITCH_H

#include "export.h"
#include "ob.h"

class CSwitch : public CBody
{
	public:
		EXPORT void SwitchInactive(void);
		EXPORT CVector* GetAutoAimTargetPointer(void);
		EXPORT void SwitchOff(void);

		unsigned char padTop[0x100-0xF4];

		int field_100;

		CItem* field_104;
		CItem* field_108;

		CVector field_10C;
		CVector field_118;
		unsigned char padBottom[0x128-0x118-sizeof(CVector)];
};

void validate_CSwitch(void);
EXPORT void Switch_SetVisible(bool, CItem*);
#endif
