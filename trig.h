#pragma once

#ifndef TRIG_H
#define TRIG_H

#include "export.h"
#include "vector.h"

struct SLinkInfo
{
	i32 field_0;
	i32 field_4;
	i32 field_8;
	i32 field_C;
};

struct SCommandPoint
{
	u8 padTop[4];

	u8 Collision;
	u8 Executed;

	u8 padAfter5[0x14-0x5-1];

	struct SCommandPoint* pNext;
};

EXPORT int Trig_GetLevelId(void);
EXPORT u16* Trig_GetPosition(CVector*, int);
EXPORT u16* Trig_GetLinksPointer(int);
EXPORT void Trig_SendPulse(u16*);
EXPORT void Trig_SendPulseToNode(int);
EXPORT void Trig_SendSignalToLinks(u16*);
EXPORT void Trig_ClearTrigMenu(void);
EXPORT unsigned char* SkipFlags(unsigned char*);
EXPORT void Trig_ResetCPCollisionFlags(void);
EXPORT u8 GetFlag(unsigned char, unsigned char *);
EXPORT void* Trig_GetLinkInfoList(i32, SLinkInfo*, i32);
EXPORT void Trig_ResetCPExecutedFlags(void);

void validate_SLinkInfo(void);
void validate_SCommandPoint(void);

#endif
