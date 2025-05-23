#pragma once

#ifndef PS2CARD_H
#define PS2CARD_H

#include "export.h"

struct SCardHead
{
	char Magic[2];
	char Type;
	char BlockEntry;
	char Title[64];
	char reserve[28];
	char Clut[32];
	char Icon[3][128];
};

struct SSaveFile
{
	SCardHead mCardHead;

	PADDING(0xA24 - sizeof(SCardHead));
};


EXPORT i32 Card_CheckStatus(i32,i32);
EXPORT i32 Card_FormatCard(i32,i32);
EXPORT i32 Card_GetFreeBlocks(i32,i32);
EXPORT void Card_Init(i32);
EXPORT i32 Card_Load(void);
EXPORT void Card_SetHeader(void);
EXPORT void Card_Stop(void);
EXPORT i32 Card_Write(void);

EXPORT extern i32 CardStatus;

void validate_SCardHead(void);
void validate_SSaveFile(void);

#endif
