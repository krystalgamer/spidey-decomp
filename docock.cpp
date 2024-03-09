#include "docock.h"
#include "validate.h"


void validate_CDocOc(void){
	VALIDATE_SIZE(CDocOc, 0x590);

	VALIDATE(CDocOc, field_324, 0x324);
	VALIDATE(CDocOc, field_328, 0x328);
	VALIDATE(CDocOc, field_32C, 0x32C);
	VALIDATE(CDocOc, field_330, 0x330);
	VALIDATE(CDocOc, field_334, 0x334);
	VALIDATE(CDocOc, field_4A8, 0x4A8);
	VALIDATE(CDocOc, field_4EC, 0x4EC);
	VALIDATE(CDocOc, field_50C, 0x50C);
	VALIDATE(CDocOc, field_510, 0x510);
	VALIDATE(CDocOc, field_514, 0x514);
	VALIDATE(CDocOc, field_554, 0x554);
}