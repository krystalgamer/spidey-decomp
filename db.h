#pragma once

#ifndef DB_H
#define DB_H

#include "export.h"

struct SDoubleBuffer
{
	u8 pad[0x7C];
};


EXPORT extern SDoubleBuffer* pDoubleBuffer;
EXPORT extern SDoubleBuffer* pOtherBuffer;
EXPORT extern SDoubleBuffer DoubleBuffer[2];

EXPORT void Db_CreateOTsAndPolyBuffers(void);
EXPORT void Db_DefaultScreenOffsets(void);
EXPORT void Db_DeleteOTsAndPolyBuffers(void);
EXPORT void Db_FlipClear(void);
EXPORT void Db_Init(void);
EXPORT void Db_UpdateSky(void);

void validate_SDoubleBuffer(void);

#endif
