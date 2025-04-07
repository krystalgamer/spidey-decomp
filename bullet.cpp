#include "bullet.h"
#include "utils.h"
#include "exp.h"

#include "validate.h"

#include <cmath>


CBody* BulletList;
EXPORT i32 gBullets;


// @MEDIUMTODO
void CBullet::BlowUp(void)
{
    printf("CBullet::BlowUp(void)");
}

// @Ok
// @Matching
void CBullet::GiveScaledDamageToEnviro(i32 a2)
{
	CItem *pItem = EnviroList;

	while (pItem)
	{
		i32 dX = pItem->mPos.vx - this->mPos.vx;
		if (dX < 0)
		{
			dX = -dX;
		}

		if (dX < a2 << 12)
		{
			i32 dZ = pItem->mPos.vz - this->mPos.vz;
			if (dZ < 0)
			{
				dZ = -dZ;
			}

			if (dZ < a2 << 12)
			{
				CVector v7;
				v7.vx = pItem->mPos.vx;
				v7.vy = pItem->mPos.vy;
				v7.vz = pItem->mPos.vz;

				// @FIXME - CrapDist should be a u32 why the fuck it's a i32 here
				if (static_cast<i32>(Utils_CrapDist(this->mPos, v7)) < a2)
				{
					Exp_HitEnvItem(pItem, 0, this->field_104);
				}
			}
		}

		pItem = pItem->mNextItem;
	}
}

// @SMALLTODO
void CBullet::GiveScaledDamageToObjects(CBody *,i32,i32,i32,HitId)
{
    printf("CBullet::GiveScaledDamageToObjects(CBody *,i32,i32,i32,HitId)");
}

/*
// @SMALLTODO
void CSmokePuff::Move(void)
{
    printf("CSmokePuff::Move(void)");
}

// @SMALLTODO
CSmokePuff::~CSmokePuff(void)
{
    printf("CSmokePuff::~CSmokePuff(void)");
}
*/

// @NotOk
CBullet::~CBullet(void)
{
	--gBullets;

	// @FIXME
	delete reinterpret_cast<CItem*>(this->field_10C);

	if (this->field_120)
	{
		// @FIXME
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

	this->mScale.vx = 2048;
	this->mScale.vy = 2048;
	this->mScale.vz = 2048;

	this->mFlags |= 0x200;
	this->mCBodyFlags &= 0xFFFD;
}

void validate_CBullet(void)
{
	VALIDATE_SIZE(CBullet, 0x13C);

	VALIDATE(CBullet, field_104, 0x104);

	VALIDATE(CBullet, field_10C, 0x10C);

	VALIDATE(CBullet, field_114, 0x114);
	VALIDATE(CBullet, field_118, 0x118);
	VALIDATE(CBullet, field_11C, 0x11C);
	VALIDATE(CBullet, field_120, 0x120);

	VALIDATE(CBullet, field_130, 0x130);
	VALIDATE(CBullet, field_134, 0x134);
	VALIDATE(CBullet, field_138, 0x138);
}
