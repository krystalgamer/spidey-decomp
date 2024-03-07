#pragma once

#include "export.h"
#include "ob.h"


class CBaddy : public CSuper {

public:
	EXPORT int DistanceToPlayer(int a2);
	EXPORT int TrapWeb(void);
	EXPORT int TugWeb(void);


	unsigned char pad[0x69+4];

	int field_204;
	int field_208;

	unsigned char morerPad[0x84];
	int field_290;
	unsigned char morePad[0xA0 - 8 - 0x84];

	int field_2A8;

};


void validate_CBaddy(void);