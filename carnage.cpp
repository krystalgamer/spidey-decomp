#include "carnage.h"
#include "validate.h"



void validate_CCarnage(void){
	VALIDATE_SIZE(CCarnage, 0x37C);

	VALIDATE(CCarnage, field_334, 0x334);
	VALIDATE(CCarnage, field_338, 0x338);
	VALIDATE(CCarnage, field_33C, 0x33C);
	VALIDATE(CCarnage, field_354, 0x354);
	VALIDATE(CCarnage, field_358, 0x358);
	VALIDATE(CCarnage, field_35C, 0x35C);
	VALIDATE(CCarnage, field_36C, 0x36C);
	VALIDATE(CCarnage, field_370, 0x370);
	VALIDATE(CCarnage, field_374, 0x374);
	VALIDATE(CCarnage, field_378, 0x378);
}