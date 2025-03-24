#pragma once

#ifndef HOSTAGE_H
#define HOSTAGE_H

#include "export.h"
#include "baddy.h"
#include "mem.h"
#include "reloc.h"


class CHostage : public CBaddy {

public:
	EXPORT CHostage(i16*, i32);
	EXPORT void GetUp(void);
	EXPORT void DisappearBitch(void);
	EXPORT void WaitForPlayer(void);
	EXPORT void CheckIfFreed(void);
	EXPORT void HostageXAPlay(i32, i32, i32);
	EXPORT void BegMotherfucker(void);
	EXPORT void TellSomebodyToShootMe(void);

	EXPORT void AI(void) OVERRIDE;
	EXPORT void DieHostage(void);
	EXPORT void FollowWaypoints(void);
	EXPORT void SetHostageType(i32);
	EXPORT ~CHostage(void);


	i32 field_324;
	i32 field_328;
	SHandle field_32C;
};


void validate_CHostage(void);
EXPORT void Hostage_CreateHostage(const unsigned int *, unsigned int *);
EXPORT void Hostage_RelocatableModuleClear(void);
EXPORT void Hostage_RelocatableModuleInit(reloc_mod *);

#endif
