#include "powerup.h"
#include "spool.h"
#include "trig.h"
#include "exp.h"
#include "my_assert.h"

#include "validate.h"

extern i32 TotalBitUsage;
CBody* PowerUpList;
i32 TTime;

// @MEDIUMTODO
void CPowerUp::DoPhysics(void)
{
	printf("CPowerUp::DoPhysics");
}

// @Ok
void CPowerUp::AI(void)
{
	if ( (this->mFlags & 1) && this->mIs3d)
		this->mShadowScale = 0;
	else
		this->mShadowScale = 32;

	if (this->field_124)
	{
		this->mRGB = 0x101010;
		this->mFlags |= 0xC00;
		this->field_124 = 0;
	}
	else
	{
		this->mFlags &= 0xF3FF;
	}


	if (this->field_128)
	{
		if (this->field_128 > 2)
		{
			this->mFlags |= 0x400;

			this->field_128 -= 2;

			u32 tmp = (255 * this->field_128 / 64);
			tmp |= ((tmp << 8) | tmp) << 8;
			this->mRGB = tmp;
		}
		else
		{
			this->Die();
			return;
		}
	}

	this->CheckAge();

	if (this->mPlayerDist > 0x1F40)
	{
		this->DeleteStuff();
	}
	else
	{
		if (this->field_10C != 0xFFFFFFFF)
		{
			this->ShadowOn();
		}

		this->DoPhysics();

		if (!this->mIs3d)
		{
			if (!this->pPickupBit)
				this->CreateBit();
			DoAssert(this->pPickupBit != 0, "Non-3d pickup has no pickup bit");
			this->pPickupBit->SetPos(this->mPos);
		}
	}
}

// @Ok
void CPowerUp::CheckAge(void)
{
	if (this->mLifetime != 0xFFFF)
	{
		if (this->mLifetime)
			this->mLifetime--;

		if (this->mLifetime < 0x3C)
			this->field_120 = this->mLifetime * this->field_11E / 60;

		if (this->mLifetime < 0x3C && this->mLifetime > 0x1E)
		{
				if (TTime & 2)
					this->mDropping = 1;
				else
					this->mDropping = 0;
		}
		if (this->mLifetime <= 0x1E)
		{
			if (TTime & 1)
				this->mDropping = 1;
			else
				this->mDropping = 0;
		}

		if (this->mIs3d)
		{
			if (this->mDropping)
				this->mFlags &= 0xFFFE;
			else
				this->mFlags |= 1;
		}

		if (!this->mLifetime)
		{
			if (this->mPlayerDist <= 0x1F40)
				Exp_GlowFlash(&this->mPos, 20, 0xFF, 0xFF, 0xFF, 4, 1, 20);
			this->Die();
		}
	}
}

// @Ok
CPowerUp::~CPowerUp(void)
{
	this->DeleteFrom(&PowerUpList);
	this->DeleteStuff();
}

// @Ok
void CPowerUp::Die(void)
{
	if (!this->IsDead())
	{
		if (this->mType != 11 && this->mHasNode)
		{
			Trig_SendPulse(Trig_GetLinksPointer(this->mNodeIndex));
		}

		if (this->field_108 != 0xFFFF)
		{
			u16 LinkInfo[2];
			LinkInfo[0] = 1;
			LinkInfo[1] = this->field_108;

			Trig_SendSignalToLinks(LinkInfo);
		}

		this->mCBodyFlags |= 0x40;
		this->mFlags |= 1;
	}
}

// @MEDIUMTODO
CPowerUp::CPowerUp(
		u16,
		CVector*,
		CVector*,
		u32,
		i32,
		i32)
{
	printf("CPowerUp");
}

// @Ok
// @Matching
void CPowerUp::DeleteStuff(void)
{
	this->KillShadow();

	if (this->pPickupBit)
		delete this->pPickupBit;
	this->pPickupBit = 0;

	if (this->mpGlow)
		delete this->mpGlow;

	this->mpGlow = 0;
}

// @Ok
void CPowerUp::CreateBit(void)
{
	TotalBitUsage = 0; 
	if (this->mType == 18)
	{
		this->pPickupBit = new CFlatBit();

		Texture *pTexture = Spool_FindTextureEntry("TrainingPick-Up_01");
		this->pPickupBit->SetTexture(pTexture);
		this->pPickupBit->SetSemiTransparent();

		switch (this->mHealth)
		{
			case 0xA:
				this->pPickupBit->SetTint(0x6Au, 212, 105);
				break;
			case 0x14:
				this->pPickupBit->SetTint(0x85u, 133, 255);
				break;
			case 0x28:
				this->pPickupBit->SetTint(0xFFu, 77, 77);
				break;
			case 0x50:
				this->pPickupBit->SetTint(0xD8u, 216, 216);
				break;
			default:
				this->pPickupBit->SetTint(0x80u, 128, 32);
				break;
		}
	}

	if (this->pPickupBit)
		this->pPickupBit->mProtected = 1;

	TotalBitUsage = 1; 
}

// @Ok
void CPowerUp::SetGravity(i32 g, i32 fric)
{
	this->mAcc.vy = g;
	this->mFric.vy = fric;
}

// @Ok
// @Matching
void CPowerUp::SetNode(i32 NodeIndex)
{
	this->mHasNode = 1;
	this->mNodeIndex = NodeIndex;
}

void validate_CPowerUp(void)
{
	VALIDATE_SIZE(CPowerUp, 0x138);

	VALIDATE(CPowerUp, mpGlow, 0xF8);

	VALIDATE(CPowerUp, mHasNode, 0x100);
	VALIDATE(CPowerUp, mIs3d, 0x101);
	VALIDATE(CPowerUp, mDropping, 0x102);

	VALIDATE(CPowerUp, mNodeIndex, 0x106);
	VALIDATE(CPowerUp, field_108, 0x108);

	VALIDATE(CPowerUp, field_10C, 0x10C);

	VALIDATE(CPowerUp, field_11E, 0x11E);
	VALIDATE(CPowerUp, field_120, 0x120);
	VALIDATE(CPowerUp, field_124, 0x124);
	VALIDATE(CPowerUp, field_128, 0x128);

	VALIDATE(CPowerUp, mLifetime, 0x12C);

	VALIDATE_VTABLE(CPowerUp, DeleteStuff, 4);
}
