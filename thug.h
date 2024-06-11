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
	EXPORT void StandStill(void);
	EXPORT i32 ShouldFall(i32, i32);
	EXPORT void DieAfterFlyingAcrossRoom(void);
	EXPORT void RunAppropriateHitAnim(void);
	EXPORT void StopShooting(void);
	EXPORT i32 AddPointToPath(CVector*, i32);
	EXPORT i32 TryAddingCollidePointToPath(CVector*);
	EXPORT void SetHitDirectionFlag(CVector*);
	EXPORT void SetParamByIndex(i32, i32);
	EXPORT void GetReadyToShootHostage(CMessage*);
	EXPORT void CheckFallBack(void);
	EXPORT i32 GetLaunched(CVector*, i32, i32, i32);
	EXPORT u8 TugImpulse(CVector*, CVector*, CVector*);
	EXPORT void LookConfused(void);
	EXPORT void Acknowledge(void);
	EXPORT void StrikeUpConversation(void);
	EXPORT i32 DistanceToPlayer(i32);
	EXPORT u32 CheckStateFlags(SStateFlags*, int);

	EXPORT virtual void SetThugType(int);

	EXPORT virtual i32 GetClosest(i32, i32);

	u8 padTop[0x330-0x324];

	i32 field_330;
	u8 padAfter330[0x33C-0x330-4];

	i32 field_33C;
	u8 padAfter33C[0x354-0x33C-4];

	SHandle mHandle;
	SHandle mHandleTwo;
	u8 padAfter354[0x370-0x35C-sizeof(SHandle)];

	i32 field_370;
	i32 field_374;
	i32 field_378;
	i32 field_37C;
	i32 field_380;
	i32 field_384;
	i32 field_388;
	i32 field_38C;
	u8 padAfter38C[0x394 - 0x38C - 4];

	i32 field_394;
	i32 field_398;
	i32 field_39C;
	u8 padAfter39C[0x3A4-0x39C-4];

	CVector* field_3A4;
	u8 padAfter3A4[0x3B0-0x3A4-4];

	i32 field_3B0;
	u8 padAfter3B0[0x3B8-0x3B0-4];

	i32 field_3B8;

	u8 field_3BC;
	u8 field_3BD;
	u8 padBottom[0x3C0 - 0x3BD - 1];
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
