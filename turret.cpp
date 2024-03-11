#include "turret.h"
#include "validate.h"


void __inline CTurret::TargetLockAbsolute(const CVector &a1){
	this->field_344 = a1;
	this->field_218 |= 4;
}

void __inline CTurret::TargetLockDynamic(CBody *a2)
{
	if ( !a2->IsDead() )
	{
		this->field_378 = a2;
		this->field_218 |= 0x10u;
	}
}

void validate_CTurret(void){
	VALIDATE_SIZE(CTurret, 0x37C);

	VALIDATE(CTurret, field_324, 0x324);
	VALIDATE(CTurret, field_344, 0x344);
	VALIDATE(CTurret, field_378, 0x378);
}

void validate_CTurretBase(void){
		VALIDATE_SIZE(CTurretBase, 0xFC);
}
