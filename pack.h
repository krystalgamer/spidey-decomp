#pragma once

#ifndef PACK_H
#define PACK_H

#include "export.h"

struct SPack
{
	u16 X;
	u16 Y;
	u16 W;
	u16 H;
	SPack* pNext;
};

EXPORT void Pack_Init(void);
EXPORT SPack* Pack_Pack(i32,i32,i32,i32 *,i32 *,i32,i32,u32);
EXPORT void Pack_Unpack(SPack *);

void validate_SPack(void);

#endif
