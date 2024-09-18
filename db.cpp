#include "db.h"
#include "mem.h"
#include "validate.h"

SDoubleBuffer* pDoubleBuffer;
SDoubleBuffer* pOtherBuffer;
SDoubleBuffer DoubleBuffer[2];
i32 gDbRelated;

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
	void* const minus_one = (void*)0xFFFFFFFF;
	if (DoubleBuffer[0].field_70)
	{
		Mem_Delete(DoubleBuffer[0].field_70);
		DoubleBuffer[0].field_70 = minus_one;
	}
	if (DoubleBuffer[1].field_70)
	{
		Mem_Delete(DoubleBuffer[1].field_70);
		DoubleBuffer[1].field_70 = minus_one;
	}

	if (DoubleBuffer[0].field_78)
	{
		Mem_Delete(DoubleBuffer[0].field_78);
		DoubleBuffer[0].field_78 = minus_one;
	}
	if (DoubleBuffer[1].field_78)
	{
		Mem_Delete(DoubleBuffer[1].field_78);
		DoubleBuffer[1].field_78 = minus_one;
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

	VALIDATE(SDoubleBuffer, field_70, 0x70);
	VALIDATE(SDoubleBuffer, field_78, 0x78);
}
