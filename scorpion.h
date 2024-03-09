#pragma once

#include "export.h"
#include "baddy.h"


class CScorpion : public CBaddy {
	unsigned char padScoprtion[0xC28-0x324];
};

void validate_CScorpion(void);