#pragma once

#include "export.h"
#include "baddy.h"

class CPunchOb : public CBaddy {
public:
	unsigned char padFull[0x32C - 0x324];
};

void validate_CPunchOb(void);