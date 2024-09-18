#pragma once

#ifndef DB_H
#define DB_H

#include "export.h"

EXPORT extern i32 gDbRelated;
EXPORT extern u8* PolyBufferEnd;
struct SDoubleBuffer
{
	u8 pad[0x64];

	u16 field_64;
	u16 field_66;
	u8 padAfter66[0x70-0x66-2];

	u32* OrderingTable;
	u8 padAfter70[4];
	u8* Polys;
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
