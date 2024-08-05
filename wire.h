#pragma once

#ifndef WIRE_H
#define WIRE_H

#include "ob.h"
#include "export.h"
#include "bit2.h"

class CLaserFence : public CBody
{
	public:
		EXPORT CLaserFence(i16 *,i32,bool);
		EXPORT virtual ~CLaserFence(void);
		EXPORT virtual void AI(void);

		EXPORT void CommonInitialisation(bool);

		EXPORT void SetPushback(bool);

		u8 topPad[0xF8-0xF4];

		CVector field_F8;

		i32 mVxMin;
		i32 mVxMax;
		i32 mVzMin;
		i32 mVzMax;

		bool field_114;

		unsigned char bottomPad[0x11C-0x114-1];
};

class CTripWire : public CBody
{
	public:
		EXPORT CTripWire(i16 *,u16);
		EXPORT virtual ~CTripWire(void);
		EXPORT void AI(void) OVERRIDE;

		EXPORT void BuildTripWire(void);
		u8 padTop[0x4];

		u8 field_F8;
		u8 field_F9;
		u8 field_FA;
		u8 field_FB;
		u8 field_FC;

		u8 padAfterFC;

		u16 field_FE;
		u16 field_100;
		u8 padAfter100[2];

		CVector field_104;

		CPolyLine* field_110;
};

void validate_CLaserFence(void);
void validate_CTripWire(void);

#endif
