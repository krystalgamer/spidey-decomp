#include "hostage.h"
#include "validate.h"


void validate_CHostage(void){
	VALIDATE_SIZE(CHostage, 0x334);


	VALIDATE(CHostage, field_324, 0x324);
	VALIDATE(CHostage, field_328, 0x328);
	VALIDATE(CHostage, field_32C, 0x32C);
}