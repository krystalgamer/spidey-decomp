#pragma once

#ifndef WIRE_H
#define WIRE_H

#include "ob.h"
#include "export.h"

class CLaserFence : public CBody
{
	public:
		EXPORT void SetPushback(bool);
		unsigned char topPad[0x114-0xF4];

		bool field_114;

		unsigned char bottomPad[0x11C-0x114-1];
};

void validate_CLaserFence(void);

#endif
