#pragma once

#ifndef M3DZONE_H
#define M3DZONE_H

#include "export.h"
#include "m3dcolij.h"


EXPORT void M3dZone_LineToItem(SLineInfo *, i32);
EXPORT void M3dZone_FreePSX(i32);
EXPORT void M3dZone_Init(void);
EXPORT void M3dZone_SetZone(i32,u32 *);

#endif
