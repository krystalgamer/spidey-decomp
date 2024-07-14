#pragma once

#ifndef M3DCOLIJ_H
#define M3DCOLIJ_H


#include "export.h"
#include "vector.h"
#include "ps2funcs.h"

class CBody;
struct SLineInfo
{
	CVector vec_0;
	CVector vec_C;

	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	unsigned char padAfter2C[0x40-0x2C-4];

	int field_40;
	int field_44;
	MATRIX field_48;
	int field_68;

	int field_6C;
	int field_70;
	int field_74;
	__int16 field_78;
	__int16 field_7A;
	__int16 field_7C;

	int field_80;
	int field_84;
	unsigned char field_88;
	unsigned char field_89;
	u16 field_8A;
	int field_8C;
};


void validate_SLineInfo(void);
EXPORT void M3dColij_InitLineInfo(SLineInfo *);
EXPORT i32 M3dColij_LineToSphere(CVector*, CVector*, CVector*, CBody*, CBody*, i32);

EXPORT void M3dColij_LineToItem(CItem*, SLineInfo*);
EXPORT void M3dColij_LineToThisItem(CItem*, SLineInfo*);

#endif
