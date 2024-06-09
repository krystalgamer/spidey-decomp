#pragma once

#ifndef THUG_H
#define THUG_H

#include "export.h"
#include "baddy.h"
#include "mem.h"
#include "m3dutils.h"

class CThug : public CBaddy {
public:
	EXPORT CThug(int*, int);
	EXPORT void ClearAttackFlags(void);
	EXPORT void HelpOutBuddy(CMessage*);
	EXPORT void RunToWhereTheActionIs(CVector*);
	EXPORT void PlayHitWallSound(void);

	EXPORT virtual void SetThugType(int);

	u8 padTop[0x370-0x324];

	int field_370;
	int field_374;
	int field_378;
	int field_37C;
	int field_380;
	int field_384;
	int field_388;
	int field_38C;
	unsigned char padAfter38C[0x394 - 0x38C - 4];

	int field_394;
	unsigned char padAfter394[0x3B0-0x394-4];

	int field_3B0;
	unsigned char padAfter3B0[0x3B8-0x3B0-4];

	int field_3B8;

	unsigned char field_3BC;
	unsigned char field_3BD;
	unsigned char padBottom[0x3C0 - 0x3BD - 1];
};

class CThugPing : public CSimpleAnim
{
	public:
		EXPORT void Move(void);
		EXPORT void SetPosition(void);

		unsigned char padTop[8];
		SHandle field_70;
		SHook field_78;
};

void validate_CThug(void);
void validate_CThugPing(void);

EXPORT void Thug_CreateTHug(const unsigned int *stack, unsigned int *result);

#endif
