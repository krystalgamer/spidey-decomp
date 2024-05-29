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

		unsigned char padTop[0x100-0xF4];

		int field_100;
		unsigned char padAfter100[0x10C-0x100-4];

		CVector field_10C;
		CVector field_118;
		unsigned char padBottom[0x128-0x118-sizeof(CVector)];
};

void validate_CSwitch(void);
#endif
