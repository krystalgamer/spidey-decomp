#pragma once

#ifndef WIRE_H
#define WIRE_H

#include "ob.h"
#include "export.h"

class CLaserFence : public CBody
{
	public:
		EXPORT CLaserFence(short *,i32,bool);
		EXPORT virtual ~CLaserFence(void);
		EXPORT virtual void AI(void);

		EXPORT void CommonInitialisation(bool);

		EXPORT void SetPushback(bool);
		unsigned char topPad[0x114-0xF4];

		bool field_114;

		unsigned char bottomPad[0x11C-0x114-1];
};

class CTripWire : public CBody
{
	public:
		EXPORT CTripWire(i16 *,u16);
		EXPORT virtual ~CTripWire(void);
		EXPORT virtual void AI(void);

		EXPORT void BuildTripWire(void);
		u8 padTop[0x1C];

		// @FIXME
		void *field_110;
};

void validate_CLaserFence(void);
void validate_CTripWire(void);

#endif
