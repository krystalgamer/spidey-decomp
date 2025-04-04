#pragma once

#ifndef LIZMAN_H
#define LIZMAN_H

#include "export.h"
#include "baddy.h"
#include "mem.h"
#include "reloc.h"

class CMessage;

class CLizMan : public CBaddy {
public:
	EXPORT CLizMan(i16 *,i32);

	EXPORT void PlaySingleAnim(i16, i32, i32);
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
	EXPORT void Guard(void);
	EXPORT i32 ScanNearbyNodesForJumpTarget(void);
	EXPORT void CalculateJumpPositionArray(CVector*);

	PADDING(0x4);

	i32 field_328;
	i32 field_32C;

	PADDING(0x338-0x32C-4);

	i32 field_338;

	PADDING(0x340-0x338-4);

	i32 field_340;
	PADDING(0x36C-0x340-4);

	SHandle hLizHandle;
	u32 field_374;

	PADDING(0x390-0x374-4);

	u8 field_390;

	PADDING(0x398-0x390-1);

	i32 field_398;
	u8 field_39C;
	u8 field_39D;

	PADDING(0x3AC - 0x39C - 4);

	i32 field_3AC;

	PADDING(0x3B8-0x3AC-4);
};

void validate_CLizMan(void);
EXPORT void LizMan_RelocatableModuleInit(reloc_mod *);
EXPORT void LizMan_RelocatableModuleClear(void);
EXPORT void LizMan_CreateLizMan(const u32*, u32*);

#endif
