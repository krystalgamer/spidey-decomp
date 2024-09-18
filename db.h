#pragma once

#ifndef DB_H
#define DB_H

#include "export.h"

EXPORT extern i32 gDbRelated;
struct SDoubleBuffer
{
	u8 pad[0x70];
	void* field_70;
	u8 padAfter70[4];
	void* field_78;
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
