#pragma once

#include "export.h"
#include "baddy.h"


class CTurret : public CBaddy {
public:
	EXPORT void TargetLockAbsolute(const CVector &);
	EXPORT void TargetLockDynamic(CBody *a2);

	CVector field_324;
	unsigned char padAfter324[0x20 - sizeof(CVector)];

	CVector field_344;
	unsigned char padAfter344[0x378-0x344 - sizeof(CVector)];
	CBody *field_378;
};

class CTurretBase : public CBody {
public:
	unsigned char fullpad[0x8];
};

void validate_CTurret(void);
void validate_CTurretBase(void);
