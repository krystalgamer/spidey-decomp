#include "mysterio.h"
#include "validate.h"


void validate_CMystFoot(void){
	VALIDATE_SIZE(CMystFoot, 0x324);
}

void validate_CMysterio(void){
	VALIDATE_SIZE(CMysterio, 0x3D0);

	VALIDATE(CMysterio, field_324, 0x324);
	VALIDATE(CMysterio, field_32C, 0x32C);
	VALIDATE(CMysterio, field_358, 0x358);
	VALIDATE(CMysterio, field_360, 0x360);

	VALIDATE(CMysterio, field_364, 0x364);
	VALIDATE(CMysterio, field_368, 0x368);
	VALIDATE(CMysterio, field_36C, 0x36C);
	VALIDATE(CMysterio, field_374, 0x374);

	VALIDATE(CMysterio, field_378, 0x378);
	VALIDATE(CMysterio, field_37C, 0x37C);
	VALIDATE(CMysterio, field_380, 0x380);
	VALIDATE(CMysterio, field_384, 0x384);

	VALIDATE(CMysterio, field_38C, 0x38C);
	VALIDATE(CMysterio, field_398, 0x398);
	VALIDATE(CMysterio, field_3A8, 0x3A8);
}

void validate_CSoftSpot(void){
	VALIDATE_SIZE(CSoftSpot, 0x338);

	VALIDATE(CSoftSpot, field_324, 0x324);
	VALIDATE(CSoftSpot, field_328, 0x328);
	VALIDATE(CSoftSpot, field_32c, 0x32c);
	VALIDATE(CSoftSpot, field_330, 0x330);
	VALIDATE(CSoftSpot, field_334, 0x334);
}