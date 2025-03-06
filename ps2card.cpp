#include "ps2card.h"
#include "dcmemcard.h"
#include "pcdcBkup.h"
#include "pcdcMem.h"
#include "mem.h"

#include "validate.h"
#include <cstring>

// @FIXME - not 0xA24
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

// @NotOk
// @Test
// @Note: huge stack, code not matching in the loops
i32 Card_Write(void)
{
	void *pBackfupFile = 0;
	SBackupFile backupFile;
	i16 Clut[16];

	char v21[0x2000-0x5C];

	Card_SetHeader();

	for (i32 i = 0;
			i < 16;
			i++)
	{
		i16 v1 = *reinterpret_cast<i16*>(&gCardClut[i*2]);
		Clut[i] = ((v1 & 0x1E) << 7) | (v1 >> 11) & 0xF | (v1 >> 2) & 0xF0 | (15 * ((v1 >> 3) & 0x1000));
	}

	u8 v20[1024];
	for (i32 j = 0; j < 16; j++)
	{
		for (i32 k = 0; k < 8; k++)
		{
			u8 v11 = gCardIcon[8 * j + k];
			u8 v12 = v11 & 0xF | (16 * v11);

			i32 v13 = 32 * j + 2 * k;
			v20[v13 + 16] = v12;
			v20[v13] = v12;

			u32 v14 = (16 * (v11 >> 4)) & 0xF0 | (v11 >> 4) & 0xFFFFFF0F;
			v20[v13 + 17] = v14;
			v20[v13 + 1] = v14;

		}
	}


	SSaveFile *pSaveFile = static_cast<SSaveFile*>(
			DCMem_New(sizeof(SSaveFile), 0, 1, 0, 1));

	// @FIXME
	memcpy(pSaveFile, &Head, sizeof(SSaveFile));
	memset(&backupFile, 0, sizeof(backupFile));
	strcpy(
			backupFile.field_34,
			Head.Title);

	for (i32 l = 0; l < 0x10; l++)
	{
		u8 v11 = backupFile.field_34[l];

		if (v11 == ' ')
			backupFile.field_34[l] = '_';
		else if (v11 >= 'a')
			backupFile.field_34[l] = v11 - ' ';
	}

	strncpy(backupFile.mName, "SpiderMan Data", 0x10u);
	strcpy(backupFile.mDesc, "SpiderMan Save File");
	backupFile.field_4C = 1;
	backupFile.field_4E = 8;
	backupFile.field_48 = v20;
	backupFile.field_44 = Clut;
	backupFile.field_54 = 0;

	// @FIXME - wtf
	backupFile.field_50 = reinterpret_cast<i32>(&v21);

	backupFile.mBackupSize = sizeof(SSaveFile);
	backupFile.pCardHead = &pSaveFile->mCardHead;

	i32 fileSize = buCalcBackupFileSize(1, 0, sizeof(SSaveFile));
	
	if (fileSize < 0)
	{
		DebugPrintfX("Card_Save: Invalid Block Size");
	}
	else
	{
		pBackfupFile = syMalloc(fileSize << 9);

		if (!pBackfupFile)
		{
			DebugPrintfX("Out of system memory for save file buffer");
		}
		else
		{
			i32 backupSize = buMakeBackupFileImage(pBackfupFile, &backupFile);
			SDCCardTime v17 = *DCCard_CurTime();

			if (buSaveFile(gFirstCard, "SPIDRMAN.DAT", pBackfupFile, backupSize, &v17))
			{
				DebugPrintfX("Save Failed");
			}
			else if (DCCard_Wait(gFirstCard, 0x258u))
			{
				Mem_Delete(pSaveFile);
				syFree(pBackfupFile);
				DCCard_HappyBeep(gFirstCard, 0x1Eu);
				return 0;
			}
		}
	}

	syFree(pBackfupFile);
	if (pSaveFile)
		Mem_Delete(pSaveFile);

	DCCard_SadBeep(gFirstCard, 0x1Eu);
	return 1;
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

void validate_SSaveFile(void)
{
	VALIDATE_SIZE(SSaveFile, 0xA24);

	VALIDATE(SSaveFile, mCardHead, 0x0);
}
