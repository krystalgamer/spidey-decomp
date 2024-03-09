#include "venom.h"
#include "validate.h"


void validate_CVenom(void){
	VALIDATE_SIZE(CVenom, 0x468);

	VALIDATE(CVenom, field_33C, 0x33C);
	VALIDATE(CVenom, field_33D, 0x33D);
	VALIDATE(CVenom, field_358, 0x358);

	VALIDATE(CVenom, field_37C, 0x37C);
	VALIDATE(CVenom, field_380, 0x380);
	VALIDATE(CVenom, field_384, 0x384);

	VALIDATE(CVenom, field_39C, 0x39C);

	VALIDATE(CVenom, field_3A0, 0x3A0);
	VALIDATE(CVenom, field_3A4, 0x3A4);
	VALIDATE(CVenom, field_3A8, 0x3A8);

	VALIDATE(CVenom, field_3E8, 0x3E8);
	VALIDATE(CVenom, field_3EC, 0x3EC);
	VALIDATE(CVenom, field_3F0, 0x3F0);
	VALIDATE(CVenom, field_400, 0x400);
	VALIDATE(CVenom, field_404, 0x404);
	VALIDATE(CVenom, field_408, 0x408);
	VALIDATE(CVenom, field_40C, 0x40C);
	VALIDATE(CVenom, field_410, 0x410);
	VALIDATE(CVenom, field_414, 0x414);
	VALIDATE(CVenom, field_418, 0x418);
	VALIDATE(CVenom, field_41C, 0x41C);
	VALIDATE(CVenom, field_420, 0x420);


	VALIDATE(CVenom, field_454, 0x454);
	VALIDATE(CVenom, field_45C, 0x45C);
	VALIDATE(CVenom, field_460, 0x460);
	VALIDATE(CVenom, field_464, 0x464);
}