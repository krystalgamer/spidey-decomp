#include "db.h"
#include "mem.h"
#include "validate.h"

SDoubleBuffer* pDoubleBuffer;
SDoubleBuffer* pOtherBuffer;
SDoubleBuffer DoubleBuffer[2];
i32 gDbRelated;
u8* PolyBufferEnd;

// @SMALLTODO
void Db_CreateOTsAndPolyBuffers(void)
{
    printf("Db_DefaultScreenOffsets(void)");
}

// @SMALLTODO
void Db_DefaultScreenOffsets(void)
{
    printf("Db_DefaultScreenOffsets(void)");
}

// @Ok
// @Matching
void Db_DeleteOTsAndPolyBuffers(void)
{
	u32* const minus_one = (u32*)0xFFFFFFFF;
	if (DoubleBuffer[0].OrderingTable)
	{
		Mem_Delete(DoubleBuffer[0].OrderingTable);
		DoubleBuffer[0].OrderingTable = minus_one;
	}
	if (DoubleBuffer[1].OrderingTable)
	{
		Mem_Delete(DoubleBuffer[1].OrderingTable);
		DoubleBuffer[1].OrderingTable = minus_one;
	}

	if (DoubleBuffer[0].Polys)
	{
		Mem_Delete(DoubleBuffer[0].Polys);
		DoubleBuffer[0].Polys = minus_one;
	}
	if (DoubleBuffer[1].Polys)
	{
		Mem_Delete(DoubleBuffer[1].Polys);
		DoubleBuffer[1].Polys = minus_one;
	}

	gDbRelated = 1;
}

// @SMALLTODO
void Db_FlipClear(void)
{
    printf("Db_FlipClear(void)");
}

// @SMALLTODO
void Db_Init(void)
{
    printf("Db_Init(void)");
}

// @SMALLTODO
void Db_UpdateSky(void)
{
    printf("Db_UpdateSky(void)");
}

void validate_SDoubleBuffer(void)
{
	VALIDATE_SIZE(SDoubleBuffer, 0x7C);

	VALIDATE(SDoubleBuffer, OrderingTable, 0x70);
	VALIDATE(SDoubleBuffer, Polys, 0x78);
}
