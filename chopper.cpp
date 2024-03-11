#include "chopper.h"
#include "validate.h"


void validate_CChopper(void){
	VALIDATE_SIZE(CChopper, 0x3D8);

	VALIDATE(CChopper, field_330, 0x330);
	VALIDATE(CChopper, field_334, 0x334);
	VALIDATE(CChopper, field_338, 0x338);
	VALIDATE(CChopper, field_33C, 0x33C);
	VALIDATE(CChopper, field_340, 0x340);
	VALIDATE(CChopper, field_344, 0x344);
	VALIDATE(CChopper, field_358, 0x358);
	VALIDATE(CChopper, field_360, 0x360);
	VALIDATE(CChopper, field_364, 0x364);
	VALIDATE(CChopper, field_368, 0x368);
	VALIDATE(CChopper, field_36C, 0x36C);
	VALIDATE(CChopper, field_380, 0x380);
	VALIDATE(CChopper, field_388, 0x388);
	VALIDATE(CChopper, field_38C, 0x38C);
	VALIDATE(CChopper, field_390, 0x390);
	VALIDATE(CChopper, field_394, 0x394);
	VALIDATE(CChopper, field_398, 0x398);
	VALIDATE(CChopper, field_39C, 0x39C);
	VALIDATE(CChopper, field_3A8, 0x3A8);
	VALIDATE(CChopper, field_3AC, 0x3AC);
	VALIDATE(CChopper, field_3B0, 0x3B0);
	VALIDATE(CChopper, field_3B4, 0x3B4);
	VALIDATE(CChopper, field_3B8, 0x3B8);
	VALIDATE(CChopper, field_3BC, 0x3BC);
	VALIDATE(CChopper, field_3C0, 0x3C0);
	VALIDATE(CChopper, field_3C8, 0x3C8);
	VALIDATE(CChopper, field_3CC, 0x3CC);
	VALIDATE(CChopper, field_3D0, 0x3D0);
}

void validate_CBulletFrag(void){
	VALIDATE_SIZE(CBulletFrag, 0x68);
}