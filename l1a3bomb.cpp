#include "l1a3bomb.h"
#include "validate.h"

u32 gBombRelated;

// @Ok
CL1A3Bomb::CL1A3Bomb(
		u16* a2,
		i32 a3)
	: CManipOb(a2, a3)
{
	this->field_128 = 0;
	this->field_129 = 0;

	gBombRelated = 4096;
}

void validate_CL1A3Bomb(void)
{
	VALIDATE_SIZE(CL1A3Bomb, 0x12C);

	VALIDATE(CL1A3Bomb, field_128, 0x128);
	VALIDATE(CL1A3Bomb, field_129, 0x129);
}
