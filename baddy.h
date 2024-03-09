#pragma once

#include "export.h"
#include "ob.h"


class CBaddy : public CSuper {

public:
	EXPORT int DistanceToPlayer(int a2);
	EXPORT int TrapWeb(void);
	EXPORT int TugWeb(void);
	EXPORT void CleanUpMessages(int, int);
	EXPORT void Die(int);

	unsigned char asdfaPad[0x14];
	CVector field_1A8;

	unsigned char baddyPad[0x40];
	int field_1F4;
	
	unsigned char padasdf[0x4];
	__int16 field_1FC;
	__int16 field_1FE;
	unsigned char pad[0x1];

	int field_204;
	int field_208;

	unsigned char field_20C;

	unsigned char fusdakjfasdPad[0x2];


	unsigned char field_20F;
	unsigned char field_210;
	unsigned char field_211;
	unsigned char morerererPad[0x12-7];
	__int16 field_21E;

	__int16 registerArr[6];
	unsigned char adsfPad[0x2C - 0x18 - 4 - 0xC];

	int field_230;
	unsigned char field_234;

	unsigned char jasdkfasdkjfajsdfPad[4];

	int field_23C;

	unsigned char asdfkjfdsPad[0x15-0xC];

	int field_24C;


	unsigned char morerPad[0x84 - 0x14 - 4 - 0x10 - 0x30 - 0xC];
	__int16 attributeArr[6];
	CVector field_27C;
	
	unsigned char weirdpad[0x06];
	int field_290;
	unsigned char field_294;
	unsigned char field_295;
	unsigned char field_296;
	unsigned char field_297;
	unsigned char field_298;
	unsigned char morePad[0xA0 - 8 - 0x84 - 8];

	int field_2A8;
	int field_2AC;
	int field_2B0;

	int field_2B4;
	CVector field_2B8;
	unsigned char shittestPad[0x14-8];
	CVector field_2D0;

	unsigned char shitPad[0x14];


	int field_2F0;
	int field_2F4;

	unsigned char shitterPad[0x4];
	CVector field_2FC;


	unsigned char ajskdfdfgsjkdfgjksdfgjkPad[11];
	__int16 field_314;
	unsigned char asdfahsudfausdhuasduhPad[4];
	int field_31C;
	int dumbAssPad;
};


void validate_CBaddy(void);