#include "powerup.h"

#include "validate.h"

// @Ok
void CPowerUp::SetGravity(int a2, int a3)
{
	this->gVec.vy = a2;
	this->field_79 = a3;
}

void validate_CPowerUp(void)
{
	VALIDATE_SIZE(CPowerUp, 0x138);
}
