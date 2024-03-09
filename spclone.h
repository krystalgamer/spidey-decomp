#pragma once

#include "export.h"
#include "baddy.h"


class CSpClone : public CBaddy {
public:
	unsigned char padFull[0x350-0x324];
};

void validate_CSpClone(void);