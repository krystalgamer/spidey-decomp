#include "lizman.h"
#include "validate.h"

void validate_CLizMan(void){
	VALIDATE_SIZE(CLizMan, 0x3B8);


	VALIDATE(CLizMan, field_328, 0x328);
	VALIDATE(CLizMan, field_32C, 0x32C);
	VALIDATE(CLizMan, field_338, 0x338);
	VALIDATE(CLizMan, field_374, 0x374);
	VALIDATE(CLizMan, field_398, 0x398);
	VALIDATE(CLizMan, field_3AC, 0x3AC);
}