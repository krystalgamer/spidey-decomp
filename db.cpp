#include "db.h"
#include "mem.h"
#include "main.h"
#include "ps2funcs.h"

#include "validate.h"

SDoubleBuffer* pDoubleBuffer;
SDoubleBuffer* pOtherBuffer;
SDoubleBuffer DoubleBuffer[2];
i32 gDbRelated;
u8* PolyBufferEnd;

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

	gDbRelated = 1;
}

// @Ok
// @Matching
INLINE void Db_FlipClear(void)
{
	pDoubleBuffer = pDoubleBuffer == &DoubleBuffer[0] ?
		&DoubleBuffer[1] :
		&DoubleBuffer[0];

	ClearOTagR();
	gDbRelated = reinterpret_cast<i32>(pDoubleBuffer->Polys) & 0x7FFFFFFF;
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

}

// @SMALLTODO
void Db_UpdateSky(void)
{
    printf("Db_UpdateSky(void)");
}

void validate_SDoubleBuffer(void)
{
	VALIDATE_SIZE(SDoubleBuffer, 0x7C);

	VALIDATE(SDoubleBuffer, field_64, 0x64);
	VALIDATE(SDoubleBuffer, field_66, 0x66);

	VALIDATE(SDoubleBuffer, OrderingTable, 0x70);
	VALIDATE(SDoubleBuffer, Polys, 0x78);
}
