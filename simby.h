#pragma once

#ifndef SIMBY_H
#define SIMBY_H

#include "export.h"
#include "baddy.h"

class CPunchOb : public CBaddy {
public:
	unsigned char padFull[0x32C - 0x324];
};

class CSimby : public CBaddy {
public:
	EXPORT CSimby(int*, int);
	EXPORT CSimby(void);
	EXPORT void FlashUpdate(void);

	unsigned char padTop[0x328-0x324];

	__int16 field_328;
	unsigned __int16 field_32A;
	unsigned __int16 field_32C;
	__int16 field_32E;
	int field_330;
	unsigned char padAfter330[0x350-0x330-4];

	int field_350;
	int field_354;
	int field_358;
	int field_35C;
	int field_360;
	int field_364;
	int field_368;
	int field_36C;
	int field_370;
	int field_374;
	int field_378;
	int field_37C;
	int field_380;
	int field_384;
	int field_388;
	int field_38C;
	int field_390;
	int field_394;
	unsigned char padAfter394[4];

	int field_39C;
	unsigned char padAfter39C[0x3Dc-0x39C-4];

	int field_3DC;
	int field_3E0;
	int field_3E4;
	unsigned char padAfter3E4[0x3F8-0x3E4-4];


	int field_3F8;
	int field_3FC;
	int field_400;
	int field_404;
	int field_408;
	int field_40C;
	unsigned char padBottom[0x460 - 0x40C-4];
};

class CSimbyBase : public CBaddy {

public:
	unsigned char padFull[0x334 - 0x324];
};

class CSimbySlimeBase : public CQuadBit
{
	public:
		EXPORT void ScaleUp(void);
		EXPORT void ScaleDown(void);
		EXPORT void ScaleDownAndDie(void);

		unsigned char topPad[0x9C-0x84];
		int field_9C;
		unsigned char padAfter9C[0xA4-0x9C-4];

		int field_A4;
		unsigned char bottomPad[0x114-0xA4-4];
};

void validate_CPunchOb(void);
void validate_CSimby(void);
void validate_CSimbyBase(void);
void validate_CSimbySlimeBase(void);
EXPORT void MakeVertexWibbler(void);
EXPORT void Simby_CreateSimby(const unsigned int *stack, unsigned int *result);

#endif
