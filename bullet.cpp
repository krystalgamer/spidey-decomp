#include "bullet.h"
#include "validate.h"


EXPORT i32 gBullets;

// @Ok
CBullet::~CBullet(void)
{
	--gBullets;

	delete reinterpret_cast<CItem*>(this->field_10C);

	if (this->field_120)
	{
		reinterpret_cast<u8*>(this->field_120)[58] = 0;
		reinterpret_cast<u32*>(this->field_120)[21] = 1;
	}
}

// @NotOk
// Global
CBullet::CBullet(void)
{
	this->field_114 = 0;
	this->field_118 = 0;
	this->field_11C = 0;

	this->field_130 = 0;
	this->field_134 = 0;
	this->field_138 = 0;

	this->InitItem("items");
	gBullets++;

	this->field_28 = 2048;
	this->field_2A = 2048;
	this->field_2C = 2048;

	this->mFlags |= 0x200;
	this->mCBodyFlags &= 0xFFFD;
}

void validate_CBullet(void)
{
	VALIDATE_SIZE(CBullet, 0x13C);

	VALIDATE(CBullet, field_10C, 0x10C);

	VALIDATE(CBullet, field_114, 0x114);
	VALIDATE(CBullet, field_118, 0x118);
	VALIDATE(CBullet, field_11C, 0x11C);
	VALIDATE(CBullet, field_120, 0x120);

	VALIDATE(CBullet, field_130, 0x130);
	VALIDATE(CBullet, field_134, 0x134);
	VALIDATE(CBullet, field_138, 0x138);
}
