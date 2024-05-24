#include "powerup.h"

#include "validate.h"

// @Ok
void CPowerUp::SetGravity(int a2, int a3)
{
	this->gVec.vy = a2;
	this->field_79 = a3;
}

// @Ok
void CPowerUp::SetNode(int a2)
{
	this->field_100 = 1;
	this->field_106 = a2;
}

void validate_CPowerUp(void)
{
	VALIDATE_SIZE(CPowerUp, 0x138);

	VALIDATE(CPowerUp, field_100, 0x100);
	VALIDATE(CPowerUp, field_106, 0x106);
}
