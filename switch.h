#pragma once

#ifndef SWITCH_H
#define SWITCH_H

#include "export.h"
#include "ob.h"

class CSwitch : public CBody
{
	public:
		EXPORT void SwitchInactive(void);
		unsigned char padTop[0x100-0xF4];

		int field_100;

		unsigned char padBottom[0x128-0x100-4];
};

void validate_CSwitch(void);
#endif
