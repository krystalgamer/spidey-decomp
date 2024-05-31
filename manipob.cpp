#include "manipob.h"
#include "utils.h"
#include "validate.h"

// @TODO
void CManipOb::CalculateThrowPosition(CVector*, int)
{
}

// @Ok
void CManipOb::ThrowPos(CVector *a2, int a3)
{
	this->CalculateThrowPosition(a2, a3);

	this->mFlags &= 0xF7FF;
	this->field_10C |= 1;
	this->csVector1.vx = Rnd(32) + 64;
}

// @Ok
void CManipOb::Throw(CVector *a2)
{
	this->mFlags &= 0xF7FF;
	this->field_10C |= 1;
	this->mAccellorVel = *a2;
	this->gVec.vy = 4096;
	this->csVector1.vx = Rnd(32) + 64;
}

void validate_CManipOb(void)
{
	VALIDATE_SIZE(CManipOb, 0x128);

	VALIDATE(CManipOb, field_10C, 0x10C);
}
