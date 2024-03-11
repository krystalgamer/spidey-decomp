#pragma once

#include "export.h"
#include "baddy.h"


class CTurret : public CBaddy {
public:
	EXPORT void TargetLockAbsolute(const CVector &);

	CVector field_324;
	unsigned char padAfter324[0x20 - sizeof(CVector)];

	CVector field_344;
	unsigned char padFull[41];
};

void validate_CTurret(void);
