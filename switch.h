#pragma once

#ifndef SWITCH_H
#define SWITCH_H

#include "export.h"
#include "ob.h"

class CSwitch : public CBody
{
	public:
		EXPORT CSwitch(i16 *,i32);
		EXPORT void SwitchInactive(void);
		EXPORT CVector* GetAutoAimTargetPointer(void);
		EXPORT void SwitchOff(void);
		EXPORT void SignalAttachedItems(void);
		EXPORT void SwitchOn(void);
		EXPORT void Flick(void);
		EXPORT void PulseLFA1Node(i32);

		EXPORT virtual ~CSwitch(void);
		EXPORT virtual void AI(void);

		unsigned char padTop[0xF8-0xF4];

		u32 field_F8;
		u16 field_FC;
		u8 padAfterF8[2];

		i32 field_100;

		CItem* field_104;
		CItem* field_108;

		CVector field_10C;
		CVector field_118;
		u8 field_124;
		unsigned char padBottom[0x128-0x124-1];
};

void validate_CSwitch(void);
EXPORT CSwitch* Switch_GetCSwitchObjectFromItem(CItem *);
EXPORT void Switch_SetVisible(bool, CItem*);
EXPORT void Switch_SetSwitchFaceFlags(CItem *);
#endif
