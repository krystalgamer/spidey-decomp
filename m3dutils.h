#pragma once

#ifndef M3DUTILS_H
#define M3DUTILS_H

#include "ob.h"
#include "export.h"

struct SHook
{
	CSVector Part;
	i16 Offset;
};

EXPORT void M3dUtils_ReadLinksPacket(CSuper*, void*);
EXPORT void M3dUtils_InBetween(CSuper*);
EXPORT void M3dUtils_BuildPose(CSuper*);
EXPORT void M3dUtils_InterpolateVectors(i32, i32, u32* ,CItem*, i32, i32);
EXPORT void M3dUtils_GetHookPosition(VECTOR*, CSuper*, int);
EXPORT void M3dUtils_GetDynamicHookPosition(VECTOR*, CSuper*, SHook*);
EXPORT void M3dUtils_ReadHooksPacket(CSuper*, void*);

void validate_SHook(void);

#endif
