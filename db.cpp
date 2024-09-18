#include "db.h"
#include "validate.h"

SDoubleBuffer* pDoubleBuffer;
SDoubleBuffer* pOtherBuffer;
SDoubleBuffer DoubleBuffer[2];

// @SMALLTODO
void Db_CreateOTsAndPolyBuffers(void)
{
    printf("Db_CreateOTsAndPolyBuffers(void)");
}

// @SMALLTODO
void Db_DefaultScreenOffsets(void)
{
    printf("Db_DefaultScreenOffsets(void)");
}

// @SMALLTODO
void Db_DeleteOTsAndPolyBuffers(void)
{
    printf("Db_DeleteOTsAndPolyBuffers(void)");
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
}
