#pragma once

#include "export.h"
#include "baddy.h"


class CHostage : public CBaddy {

public:
	EXPORT CHostage(i32*, i32);
	EXPORT void GetUp(void);
	EXPORT void DisappearBitch(void);
	EXPORT void WaitForPlayer(void);
	EXPORT void CheckIfFreed(void);


	i32 field_324;
	i32 field_328;
	i32 field_32C;

	unsigned char hostagePadp[0x4];
};


void validate_CHostage(void);
EXPORT void Hostage_CreateHostage(const unsigned int *, unsigned int *);
