#pragma once

#include "export.h"
#include "baddy.h"


class CTurret : public CBaddy {
public:
	unsigned char padFull[0x37C - 0x324];
};

void validate_CTurret(void);