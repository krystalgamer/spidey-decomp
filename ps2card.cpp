#include "ps2card.h"
#include "dcmemcard.h"
#include "pcdcBkup.h"

#include "validate.h"

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

// @Ok
// @Matching
i32 Card_GetFreeBlocks(i32,i32)
{
	return buGetDiskFree(gFirstCard, 0) > buCalcBackupFileSize(1, 0, 0xA24u);
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

void validate_SCardHead(void)
{
	VALIDATE_SIZE(SCardHead, 0x200);

	VALIDATE(SCardHead, Magic, 0x0);

	VALIDATE(SCardHead, Type, 0x2);
	VALIDATE(SCardHead, BlockEntry, 0x3);

	VALIDATE(SCardHead, Title, 0x4);
	VALIDATE(SCardHead, reserve, 0x44);
	VALIDATE(SCardHead, Clut, 0x60);
	VALIDATE(SCardHead, Icon, 0x80);
}
