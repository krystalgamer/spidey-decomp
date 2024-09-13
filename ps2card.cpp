#include "ps2card.h"
#include "dcmemcard.h"

// @SMALLTODO
void Card_CheckStatus(i32,i32)
{
    printf("Card_CheckStatus(i32,i32)");
}

// @SMALLTODO
void Card_FormatCard(i32,i32)
{
    printf("Card_FormatCard(i32,i32)");
}

// @SMALLTODO
void Card_GetFreeBlocks(i32,i32)
{
    printf("Card_GetFreeBlocks(i32,i32)");
}

// @Ok
void Card_Init(i32)
{
	MemCardInit(1);
}

// @SMALLTODO
void Card_Load(void)
{
    printf("Card_Load(void)");
}

// @SMALLTODO
void Card_SetHeader(void)
{
    printf("Card_SetHeader(void)");
}

// @SMALLTODO
void Card_Stop(void)
{
    printf("Card_Stop(void)");
}

// @MEDIUMTODO
void Card_Write(void)
{
    printf("Card_Write(void)");
}
