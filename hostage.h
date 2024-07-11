#pragma once

#ifndef HOSTAGE_H
#define HOSTAGE_H

#include "export.h"
#include "baddy.h"
#include "mem.h"


class CHostage : public CBaddy {

public:
	EXPORT CHostage(i32*, i32);
	EXPORT void GetUp(void);
	EXPORT void DisappearBitch(void);
	EXPORT void WaitForPlayer(void);
	EXPORT void CheckIfFreed(void);
	EXPORT void HostageXAPlay(i32, i32, i32);
	EXPORT void BegMotherfucker(void);
	EXPORT void TellSomebodyToShootMe(void);


	i32 field_324;
	i32 field_328;
	SHandle field_32C;
};


void validate_CHostage(void);
EXPORT void Hostage_CreateHostage(const unsigned int *, unsigned int *);

#endif
