#include "db.h"
#include "mem.h"
#include "main.h"
#include "ps2funcs.h"

#include "validate.h"

SDoubleBuffer* pDoubleBuffer;
SDoubleBuffer* pOtherBuffer;
SDoubleBuffer DoubleBuffer[2];
u32* pPoly;
u8* PolyBufferEnd;

u32 Db_SkyColor;

// @Ok
// @Matching
void Db_CreateOTsAndPolyBuffers(void)
{
	print_if_false(DoubleBuffer[0].OrderingTable == (void*)-1, "OrderingTable 0 not NULL");
	print_if_false(DoubleBuffer[1].OrderingTable == (void*)-1, "OrderingTable 1 not NULL");
	print_if_false(DoubleBuffer[0].Polys == (void*)-1, "Poly buffer 0 not NULL");
	print_if_false(DoubleBuffer[1].Polys == (void*)-1, "Poly buffer 1 not NULL");
	DoubleBuffer[0].OrderingTable = (u32*)DCMem_New(0x4000u, 1, 1, 0, 1);
	DoubleBuffer[1].OrderingTable = (u32*)DCMem_New(0x4000u, 1, 1, 0, 1);
	DoubleBuffer[0].Polys = (u8*)DCMem_New(0x17000u, 1, 1, 0, 1);
	DoubleBuffer[1].Polys = (u8*)DCMem_New(0x17000u, 1, 1, 0, 1);

	Db_FlipClear();

	CalcPolyBufferEnd();
}

// @Ok
// @Matching
INLINE void Db_DefaultScreenOffsets(void)
{
	DoubleBuffer[0].field_64 = 0;
	DoubleBuffer[1].field_64 = 0;
	DoubleBuffer[0].field_66 = 0;
	DoubleBuffer[1].field_66 = 0;
}

// @Ok
// @Matching
void Db_DeleteOTsAndPolyBuffers(void)
{
	if (DoubleBuffer[0].OrderingTable)
	{
		Mem_Delete(DoubleBuffer[0].OrderingTable);
		DoubleBuffer[0].OrderingTable = (u32*)0xFFFFFFFF;
	}
	if (DoubleBuffer[1].OrderingTable)
	{
		Mem_Delete(DoubleBuffer[1].OrderingTable);
		DoubleBuffer[1].OrderingTable = (u32*)0xFFFFFFFF;
	}

	if (DoubleBuffer[0].Polys)
	{
		Mem_Delete(DoubleBuffer[0].Polys);
		DoubleBuffer[0].Polys = (u8*)0xFFFFFFFF;
	}
	if (DoubleBuffer[1].Polys)
	{
		Mem_Delete(DoubleBuffer[1].Polys);
		DoubleBuffer[1].Polys = (u8*)0xFFFFFFFF;
	}

	pPoly = reinterpret_cast<u32*>(1);
}

// @Ok
// @Matching
INLINE void Db_FlipClear(void)
{
	pDoubleBuffer = pDoubleBuffer == &DoubleBuffer[0] ?
		&DoubleBuffer[1] :
		&DoubleBuffer[0];

	ClearOTagR();
	pPoly = reinterpret_cast<u32*>(reinterpret_cast<u32>(pDoubleBuffer->Polys) & 0x7FFFFFFF);
}

// @SMALLTODO
void Db_Init(void)
{
	SetDefDrawEnv();
	SetDefDrawEnv();
	SetDefDispEnv();
	SetDefDispEnv();

	Db_DefaultScreenOffsets();
	DoubleBuffer[0].field_18 = 1;

	setRGB0();
	DoubleBuffer[1].field_18 = 1;
	setRGB0();

	DoubleBuffer[0].OrderingTable = (u32*)0xFFFFFFFF;
	DoubleBuffer[1].OrderingTable = (u32*)0xFFFFFFFF;
	DoubleBuffer[0].Polys = (u8*)0xFFFFFFFF;
	DoubleBuffer[1].Polys = (u8*)0xFFFFFFFF;

	Db_CreateOTsAndPolyBuffers();
	Db_FlipClear();

	PutDispEnv();
	PutDrawEnv();
	DrawOTag();
}

// @SMALLTODO
void Db_UpdateSky(void)
{
    printf("Db_UpdateSky(void)");
}

void validate_SDoubleBuffer(void)
{
	VALIDATE_SIZE(SDoubleBuffer, 0x7C);

	VALIDATE(SDoubleBuffer, field_18, 0x18);

	VALIDATE(SDoubleBuffer, field_64, 0x64);
	VALIDATE(SDoubleBuffer, field_66, 0x66);

	VALIDATE(SDoubleBuffer, OrderingTable, 0x70);
	VALIDATE(SDoubleBuffer, Polys, 0x78);
}

void validate_DB_RECT(void)
{
	VALIDATE_SIZE(DB_RECT, 0x8);

	VALIDATE(DB_RECT, x, 0x0);
	VALIDATE(DB_RECT, y, 0x2);
	VALIDATE(DB_RECT, w, 0x4);
	VALIDATE(DB_RECT, h, 0x6);
}

void validate_DR_ENV(void)
{
	VALIDATE_SIZE(DR_ENV, 0x40);

	VALIDATE(DR_ENV, tag, 0x0);

	VALIDATE(DR_ENV, code, 0x4);
}

void validate_DRAWENV(void)
{
	VALIDATE_SIZE(DRAWENV, 0x5C);

	VALIDATE(DRAWENV, clip, 0x0);

	VALIDATE(DRAWENV, ofs, 0x8);
	VALIDATE(DRAWENV, tw, 0xC);
	VALIDATE(DRAWENV, tpage, 0x14);
	VALIDATE(DRAWENV, dtd, 0x16);
	VALIDATE(DRAWENV, dfe, 0x17);
	VALIDATE(DRAWENV, isbg, 0x18);

	VALIDATE(DRAWENV, r0, 0x19);
	VALIDATE(DRAWENV, g0, 0x1A);
	VALIDATE(DRAWENV, b0, 0x1B);

	VALIDATE(DRAWENV, dr_env, 0x1C);
}
