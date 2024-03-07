#pragma once

#include "export.h"
#include "ob.h"


class CBaddy : public CSuper {

public:
	EXPORT int DistanceToPlayer(int a2);
	unsigned char pad[0x69+4];

	int field_204;
	int field_208;

};


void validate_CBaddy(void);