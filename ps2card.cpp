#include "ps2card.h"
#include "dcmemcard.h"

i32 CardStatus;

EXPORT u8 gFirstCard;

EXPORT u8 gStubbedFormat = 0;

// @Ok
// @Matching
i32 Card_CheckStatus(i32 cnct,i32 slot)
{
	gFirstCard = DCCard_First();
	CardStatus = gFirstCard < 8 ? 1 : -1;

	return CardStatus;
}

// @Ok
// @Matching
i32 Card_FormatCard(i32,i32)
{
	if (!gStubbedFormat)
		stubbed_printf("stubbed out: Card_FormatCard");
	return 1;
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

// @Ok
void Card_Stop(void)
{
	MemCardStop();
}

// @MEDIUMTODO
void Card_Write(void)
{
    printf("Card_Write(void)");
}
