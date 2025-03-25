#pragma once

#ifndef DB_H
#define DB_H

#include "export.h"

EXPORT extern u32* pPoly;
EXPORT extern u8* PolyBufferEnd;

// @Note: real name is RECT but don't want collisions with win32
struct DB_RECT {
	// offset: 0000
	i16 x;
	// offset: 0002
	i16 y;
	// offset: 0004
	i16 w;
	// offset: 0006
	i16 h;
};

struct DISPENV {
	// offset: 0000 (8 bytes)
	struct DB_RECT disp;
	// offset: 0008 (8 bytes)
	struct DB_RECT screen;
	// offset: 0010
	u8 isinter;
	// offset: 0011
	u8 isrgb24;
	// offset: 0012
	u8 pad0;
	// offset: 0013
	u8 pad1;
};

// size: 0x40
struct DR_ENV {
	// offset: 0000
	u32 tag;
	// offset: 0004 (60 bytes)
	u32 code[15];
};

struct DRAWENV {
	// offset: 0000 (8 bytes)
	struct DB_RECT clip;
	// offset: 0008 (4 bytes)
	i16 ofs[2];
	// offset: 000C (8 bytes)
	struct DB_RECT tw;
	// offset: 0014
	u16 tpage;
	// offset: 0016
	u8 dtd;
	// offset: 0017
	u8 dfe;
	// offset: 0018
	u8 isbg;
	// offset: 0019
	u8 r0;
	// offset: 001A
	u8 g0;
	// offset: 001B
	u8 b0;
	// offset: 001C (64 bytes)
	struct DR_ENV dr_env;
};

struct SDoubleBuffer
{
	struct DRAWENV Draw;

	struct DISPENV Disp;

	u32* OrderingTable;
	u8 padAfter70[4];
	u8* Polys;
};


EXPORT extern SDoubleBuffer* pDoubleBuffer;
EXPORT extern SDoubleBuffer* pOtherBuffer;
EXPORT extern SDoubleBuffer DoubleBuffer[2];
EXPORT extern u32 Db_SkyColor;

EXPORT void Db_CreateOTsAndPolyBuffers(void);
EXPORT void Db_DefaultScreenOffsets(void);
EXPORT void Db_DeleteOTsAndPolyBuffers(void);
EXPORT void Db_FlipClear(void);
EXPORT void Db_Init(void);
EXPORT void Db_UpdateSky(void);

void validate_SDoubleBuffer(void);
void validate_DB_RECT(void);
void validate_DR_ENV(void);
void validate_DRAWENV(void);
void validate_DISPENV(void);

#endif
