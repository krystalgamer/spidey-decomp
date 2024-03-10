#pragma once

#include "export.h"
#include "baddy.h"


class CThug : public CBaddy {
public:
	unsigned char fullPad[0x3C0 - 0x324];
};

void validate_CThug(void);