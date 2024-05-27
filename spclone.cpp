#include "spclone.h"
#include "validate.h"


// @Ok
void CSpClone::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @TODO
void CSpClone::DoPhysics(void)
{}

void validate_CSpClone(void){
	VALIDATE_SIZE(CSpClone, 0x350);

	VALIDATE(CSpClone, field_328, 0x328);
	VALIDATE(CSpClone, field_32C, 0x32C);
	VALIDATE(CSpClone, field_330, 0x330);
	VALIDATE(CSpClone, field_334, 0x334);
	VALIDATE(CSpClone, field_338, 0x338);
	VALIDATE(CSpClone, field_34C, 0x34C);
}
