#pragma once

#ifndef CHAIN_H
#define CHAIN_H

#include "export.h"
#include "main.h"
#include "vector.h"

struct SChainData
{
	CVector field_0;
	CVector field_C;
	CVector field_18;
	u8 field_24;
	u8 padBottom[0x28-0x24-1];
};

class CChain : public CClass
{
	public:
		EXPORT CChain(CVector*, i32, i32, i32, i32, i32);
		EXPORT void SetGroundY(i32);
		EXPORT virtual ~CChain(void);
		EXPORT void Move(CVector*);

		SChainData* field_4;
		i32 field_8;
		i32 field_C;
		i32 field_10;
		i32 field_14;
		i32 field_18;
		i32 field_1C;
		i32 field_20;
		i32 field_24;
};

void validate_CChain(void);
void validate_SChainData(void);
#endif
