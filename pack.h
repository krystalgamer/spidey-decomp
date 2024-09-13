#pragma once

#ifndef PACK_H
#define PACK_H

#include "export.h"

struct SPack
{
	u8 padTop[8];
	SPack* pNext;
};

EXPORT void Pack_Init(void);
EXPORT void Pack_Pack(i32,i32,i32,i32 *,i32 *,i32,i32,u32);
EXPORT void Pack_Unpack(SPack *);

void validate_SPack(void);

#endif
