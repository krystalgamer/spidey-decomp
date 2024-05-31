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

// @NotOk
// Revisit because of weird decomp
void CManipOb::Smash(void)
{
	CVector v3;
	v3.vx = 0;
	v3.vy = 4096;
	v3.vz = 0;

	SLineInfo v4;
	v4.vec_0.vx = 0;
	v4.vec_0.vy = 0;
	v4.vec_0.vz = 0;
	v4.vec_C.vx = 0;
	v4.vec_C.vy = 0;
	v4.vec_C.vz = 0;
	v4.field_18 = 0;
	v4.field_1C = 0;
	v4.field_20 = 0;
	v4.field_24 = 0;
	v4.field_28 = 0;
	v4.field_2C = 0;
	v4.field_6C = 0;
	v4.field_70 = 0;
	v4.field_74 = 0;
	v4.field_78 = 0;
	v4.field_7A = (__int16)0xF000;
	v4.field_7C = 0;

	this->mAccellorVel.vx = 0;
	this->mAccellorVel.vy = 0x20000;
	this->mAccellorVel.vz = 0x20000;

	this->Chunk(&v4, &v3);
	this->TurnOffShadow();
	this->SendPulse();

	this->Die();
}

// @TODO
void CManipOb::Chunk(SLineInfo*, CVector*)
{}

// @TODO
void CManipOb::TurnOffShadow(void)
{}

// @TODO
void CManipOb::SendPulse(void)
{}

void validate_CManipOb(void)
{
	VALIDATE_SIZE(CManipOb, 0x128);

	VALIDATE(CManipOb, field_10C, 0x10C);
}
