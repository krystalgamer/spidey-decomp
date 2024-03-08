#pragma once

#include "export.h"
#include "ob.h"


class CBaddy : public CSuper {

public:
	EXPORT int DistanceToPlayer(int a2);
	EXPORT int TrapWeb(void);
	EXPORT int TugWeb(void);

	unsigned char asdfaPad[0x14];
	CVector field_1A8;

	unsigned char baddyPad[0x40];
	int field_1F4;

	unsigned char pad[0x9];

	int field_204;
	int field_208;

	unsigned char morerererPad[0x12];
	__int16 field_21E;

	unsigned char adsfPad[0x2C - 0x18];

	unsigned char field_234;

	unsigned char asdfkjfdsPad[0x15];

	int field_24C;


	unsigned char morerPad[0x84 - 0x14 - 4 - 0x10 - 0x30];
	int field_27C;
	int field_280;
	int field_284;
	
	unsigned char weirdpad[0x06];
	int field_290;
	unsigned char field_294;
	unsigned char field_295;
	unsigned char field_296;
	unsigned char morePad[0xA0 - 8 - 0x84 - 4];

	int field_2A8;
	int field_2AC;
	unsigned char shitPad[0x50 - 0xC - 4];

	int field_2F0;
	int field_2F4;

	unsigned char shitterPad[0x4];
	CVector field_2FC;

};


void validate_CBaddy(void);