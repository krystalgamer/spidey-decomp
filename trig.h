#pragma once

#ifndef TRIG_H
#define TRIG_H

#include "export.h"
#include "vector.h"

struct SLinkInfo
{
	int field_0;
	int field_4;
	int field_8;
};

EXPORT int Trig_GetLevelId(void);
EXPORT u16* Trig_GetPosition(CVector*, int);
EXPORT void* Trig_GetLinksPointer(int);
EXPORT void Trig_SendPulse(u16*);
EXPORT void Trig_SendPulseToNode(int);
EXPORT void Trig_SendSignalToLinks(u16*);
EXPORT void Trig_ClearTrigMenu(void);
EXPORT unsigned char* SkipFlags(unsigned char*);
EXPORT void Trig_ResetCPCollisionFlags(void);
EXPORT int GetFlag(unsigned char, unsigned char *);

void validate_SLinkInfo(void);

#endif
