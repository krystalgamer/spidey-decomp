#pragma once

#ifndef LIZMAN_H
#define LIZMAN_H

#include "export.h"
#include "baddy.h"
#include "mem.h"

class CMessage;

class CLizMan : public CBaddy {
public:
	EXPORT void PlaySingleAnim(__int16, int, int);
	EXPORT void StandStill(void);
	EXPORT void SwitchFromMatrixToEuler(void);
	EXPORT void StopClimbing(void);
	EXPORT int IsSafeToSwitchToFollowWaypoints(void);
	EXPORT void FlyAcrossRoom(void);
	EXPORT void ClearAttackFlags(void);
	EXPORT void HelpOutBuddy(CMessage*);
	EXPORT void RunToWhereActionIs(CVector*);
	EXPORT void SwitchFromEulerToMatrix(void);
	EXPORT void Acknowledge(void);

	unsigned char padLizStart[0x4];

	int field_328;
	int field_32C;
	unsigned char padAfter32C[0x338-0x32C-4];

	int field_338;
	unsigned char padAfter338[0x340-0x338-4];

	int field_340;
	unsigned char padAfter340[0x36C-0x340-4];

	SHandle hLizHandle;
	i32 field_374;
	unsigned char padAfter374[0x390-0x374-4];

	u8 field_390;
	u8 padAfter390[0x398-0x390-1];

	int field_398;
	u8 field_39C;
	u8 field_39D;
	u8 padAfter39C[0x3AC - 0x39C - 4];

	int field_3AC;
	unsigned char padLizManEnd[0x3B8-0x3AC-4];
};

void validate_CLizMan(void);

#endif
