#pragma once

#ifndef DB_H
#define DB_H

#include "export.h"

EXPORT extern i32 gDbRelated;
EXPORT extern u8* PolyBufferEnd;
struct SDoubleBuffer
{
	u8 pad[0x70];
	u32* OrderingTable;
	u8 padAfter70[4];
	void* Polys;
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
