#include "cop.h"
#include "validate.h"


void validate_CCop(void){
	VALIDATE_SIZE(CCop, 0x394);
	VALIDATE(CCop, field_340, 0x340);
	VALIDATE(CCop, field_360, 0x360);
	VALIDATE(CCop, field_364, 0x364);
	VALIDATE(CCop, field_368, 0x368);
	VALIDATE(CCop, field_36C, 0x36C);
	VALIDATE(CCop, field_370, 0x370);
	VALIDATE(CCop, field_374, 0x374);
}