#pragma once

#ifndef TRIG_H
#define TRIG_H

#include "export.h"
#include "vector.h"

EXPORT int Trig_GetLevelId(void);
EXPORT void Trig_GetPosition(CVector*, int);
EXPORT void* Trig_GetLinksPointer(int);

#endif
