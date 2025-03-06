#pragma once

#ifndef PS2CARD_H
#define PS2CARD_H

#include "export.h"

EXPORT i32 Card_CheckStatus(i32,i32);
EXPORT i32 Card_FormatCard(i32,i32);
EXPORT i32 Card_GetFreeBlocks(i32,i32);
EXPORT void Card_Init(i32);
EXPORT void Card_Load(void);
EXPORT void Card_SetHeader(void);
EXPORT void Card_Stop(void);
EXPORT void Card_Write(void);

EXPORT extern i32 CardStatus;
#endif
