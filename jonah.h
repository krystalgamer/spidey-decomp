#pragma once

#include "export.h"
#include "baddy.h"

class CJonah : public CBaddy {
public:
	unsigned char padStartJonah[0x28];
	int field_34C;
	int field_350;
	int field_354;
	unsigned char padEnd[0x380-0x354-4];
};

void validate_CJonah(void);