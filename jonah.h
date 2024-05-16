#pragma once

#include "export.h"
#include "baddy.h"

class CJonah : public CBaddy {
public:
	EXPORT CJonah(void);
	EXPORT CJonah(int*, int);
	unsigned char padStartJonah[0x28];
	int field_34C;
	int field_350;
	int field_354;
	unsigned char padEnd[0x380-0x354-4];
};

void validate_CJonah(void);
EXPORT void Jonah_CreateJonah(const unsigned int *stack, unsigned int *result);
