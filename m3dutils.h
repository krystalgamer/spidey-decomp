#pragma once

#ifndef M3DUTILS_H
#define M3DUTILS_H

#include "ob.h"
#include "export.h"

EXPORT void M3dUtils_ReadLinksPacket(CSuper*, void*);
EXPORT void M3dUtils_InBetween(CSuper*);
EXPORT void M3dUtils_BuildPose(CSuper*);
EXPORT void M3dUtils_InterpolateVectors(int, int, unsigned int*, CItem*, int, int);
EXPORT void M3dUtils_GetHookPosition(VECTOR*, CSuper*, int);

#endif
