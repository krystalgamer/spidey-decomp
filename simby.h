#pragma once

#include "export.h"
#include "baddy.h"

class CPunchOb : public CBaddy {
public:
	unsigned char padFull[0x32C - 0x324];
};

class CSimby : public CBaddy {
public:
	unsigned char padFull[0x460 - 0x324];
};

class CSimbyBase : public CBaddy {

public:
	unsigned char padFull[0x334 - 0x324];
};

void validate_CPunchOb(void);
void validate_CSimby(void);
void validate_CSimbyBase(void);