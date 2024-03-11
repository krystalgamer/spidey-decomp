#include "turret.h"
#include "validate.h"


void __inline CTurret::TargetLockAbsolute(const CVector &a1){
	this->field_344 = a1;
	this->field_218 |= 4;
}

void validate_CTurret(void){
	VALIDATE_SIZE(CTurret, 0x37C);

	VALIDATE(CTurret, field_324, 0x324);
	VALIDATE(CTurret, field_344, 0x344);
}
