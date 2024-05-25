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
EXPORT void Trig_GetPosition(CVector*, int);
EXPORT void* Trig_GetLinksPointer(int);
EXPORT void Trig_SendPulse(unsigned __int16*);
EXPORT void Trig_SendSignalToLinks(unsigned __int16*);

void validate_SLinkInfo(void);

#endif
