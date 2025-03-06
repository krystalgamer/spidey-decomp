#include "ps2card.h"
#include "dcmemcard.h"
#include "pcdcBkup.h"
#include "pcdcMem.h"

#include "validate.h"
#include <cstring>

EXPORT SCardHead Head;

i32 CardStatus;

EXPORT u8 gFirstCard;

EXPORT u8 gStubbedFormat = 0;

// @FIXME
EXPORT char gCardIcon[128];

// @FIXME
EXPORT char gCardClut[32];

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

// @Ok
// @Matching
i32 Card_Load(void)
{
	SBackupFile v4;

	i32 res = 2;
	i32 fileSize = buGetFileSize(gFirstCard, "SPIDRMAN.DAT");

	if (fileSize < 0)
	{
		DebugPrintfX("Card_Load: Invalid Block Size or File does not exist");
		res = 1;
	}
	else
	{
		void* v3 = syMalloc(fileSize << 9);
		if (buLoadFile(gFirstCard, "SPIDRMAN.DAT", v3, fileSize))
		{
			DebugPrintfX("Error Loading File");
		}
		else if (!DCCard_Wait(gFirstCard, 0x4B0u))
		{
			DebugPrintfX("backup file operation started ok, but then failed");
		}
		else if(buAnalyzeBackupFileImage(&v4, v3))
		{
			DebugPrintfX("backup file analyze failed");
		}
		else if (v4.mBackupSize != 0xA24)
		{
			DebugPrintfX("backup file size is wrong %ld", v4.mBackupSize);
		}
		else
		{
			// @FIXME - bro wtf
			memcpy(&Head, v4.pCardHead, 0xA24u);
			Card_SetHeader();
			syFree(v3);
			DCCard_HappyBeep(gFirstCard, 0x1Eu);
			return 0;
		}

		if (v3)
			syFree(v3);
		DCCard_SadBeep(gFirstCard, 0x1Eu);
	}

	return res;
}

// @Ok
// @Matching
void Card_SetHeader(void)
{
	Head.Magic[0] = 'S';
	Head.Magic[1] = 'C';
	Head.Type = 0x11;

	Head.BlockEntry = 1;

	for (i32 i = 0; i < sizeof(Head.Title); i++)
	{
		Head.Title[i] = 0;
	}
	strcpy(Head.Title, "SPIDRMAN.DAT");

	for (i32 j = 0; j < sizeof(Head.reserve); j++)
	{
		Head.reserve[j] = 0;
	}

	for (i32 k = 0; k < sizeof(Head.Clut); k++)
	{
		Head.Clut[k] = gCardClut[k];
	}

	for (i32 l = 0; l < sizeof(Head.Icon) / 3; l++)
	{
		char v1 = gCardIcon[l];

		Head.Icon[0][l] = v1;

		if (Head.Type >= 18)
			Head.Icon[1][l] = v1;
		if (Head.Type >= 19)
			Head.Icon[2][l] = v1;
	}
	
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
