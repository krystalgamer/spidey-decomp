#pragma once

#include "export.h"
#include "baddy.h"

class CPlatform : public CBaddy {
public:
	unsigned char platPat[0x38];
};

void validate_CPlatform(void);