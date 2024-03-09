#pragma once

#include "export.h"
#include "baddy.h"

class CRhino : public CBaddy {
	unsigned char padAll[0x424-0x324];
};

void validate_CRhino(void);