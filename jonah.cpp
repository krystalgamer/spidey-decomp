#include "jonah.h"
#include "validate.h"


void validate_CJonah(void){
	VALIDATE_SIZE(CJonah, 0x380);

	VALIDATE(CJonah, field_34C, 0x34C);
	VALIDATE(CJonah, field_350, 0x350);
	VALIDATE(CJonah, field_354, 0x354);
}