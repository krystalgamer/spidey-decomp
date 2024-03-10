#pragma once

#include "export.h"
#include "baddy.h"


class CSuperDocOck : public CBaddy {

public:
	unsigned char fullPad[0x414-0x324];
};


void validate_CSuperDocOck(void);