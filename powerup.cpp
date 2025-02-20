#include "powerup.h"
#include "spool.h"
#include "trig.h"
#include "exp.h"

#include "validate.h"

extern i32 TotalBitUsage;
CBody* PowerUpList;
i32 gPowerUpRelated;

// @MEDIUMTODO
void CPowerUp::DoPhysics(void)
{
	printf("CPowerUp::DoPhysics");
}

// @Ok
void CPowerUp::AI(void)
{
	if ( (this->mFlags & 1) && this->field_101)
		this->field_D0 = 0;
	else
		this->field_D0 = 32;

	if (this->field_124)
	{
		this->field_24 = 0x101010;
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
			this->field_24 = tmp;
		}
		else
		{
			this->Die();
			return;
		}
	}

	this->CheckAge();

	if (this->field_E4 > 0x1F40)
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

		if (!this->field_101)
		{
			if (!this->pPickupBit)
				this->CreateBit();
			print_if_false(this->pPickupBit != 0, "Non-3d pickup has no pickup bit");
			this->pPickupBit->SetPos(this->mPos);
		}
	}
}

// @Ok
void CPowerUp::CheckAge(void)
{
	if (this->field_12C != 0xFFFF)
	{
		if (this->field_12C)
			this->field_12C--;

		if (this->field_12C < 0x3C)
			this->field_120 = this->field_12C * this->field_11E / 60;

		if (this->field_12C < 0x3C && this->field_12C > 0x1E)
		{
				if (gPowerUpRelated & 2)
					this->field_102 = 1;
				else
					this->field_102 = 0;
		}
		if (this->field_12C <= 0x1E)
		{
			if (gPowerUpRelated & 1)
				this->field_102 = 1;
			else
				this->field_102 = 0;
		}

		if (this->field_101)
		{
			if (this->field_102)
				this->mFlags &= 0xFFFE;
			else
				this->mFlags |= 1;
		}

		if (!this->field_12C)
		{
			if (this->field_E4 <= 0x1F40)
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
		if (this->field_38 != 11 && this->field_100)
		{
			Trig_SendPulse(Trig_GetLinksPointer(this->field_106));
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

// @NotOk
// understand the type of F8
void CPowerUp::DeleteStuff(void)
{
	this->KillShadow();

	if (this->pPickupBit)
		delete this->pPickupBit;
	this->pPickupBit = 0;

	CItem *unk = reinterpret_cast<CItem*>(this->field_F8);
	if (unk)
		delete unk;
	this->field_F8 = 0;
}

// @Ok
void CPowerUp::CreateBit(void)
{
	TotalBitUsage = 0; 
	if (this->field_38 == 18)
	{
		this->pPickupBit = new CFlatBit();

		Texture *pTexture = Spool_FindTextureEntry("TrainingPick-Up_01");
		this->pPickupBit->SetTexture(pTexture);
		this->pPickupBit->SetSemiTransparent();

		switch (this->field_E2)
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
void CPowerUp::SetGravity(i32 a2, i32 a3)
{
	this->gVec.vy = a2;
	this->field_78.vy = a3;
}

// @Ok
void CPowerUp::SetNode(i32 a2)
{
	this->field_100 = 1;
	this->field_106 = a2;
}

void validate_CPowerUp(void)
{
	VALIDATE_SIZE(CPowerUp, 0x138);

	VALIDATE(CPowerUp, field_F8, 0xF8);

	VALIDATE(CPowerUp, field_100, 0x100);
	VALIDATE(CPowerUp, field_101, 0x101);
	VALIDATE(CPowerUp, field_102, 0x102);

	VALIDATE(CPowerUp, field_106, 0x106);
	VALIDATE(CPowerUp, field_108, 0x108);

	VALIDATE(CPowerUp, field_10C, 0x10C);

	VALIDATE(CPowerUp, field_11E, 0x11E);
	VALIDATE(CPowerUp, field_120, 0x120);
	VALIDATE(CPowerUp, field_124, 0x124);
	VALIDATE(CPowerUp, field_128, 0x128);

	VALIDATE(CPowerUp, field_12C, 0x12C);

	VALIDATE_VTABLE(CPowerUp, DeleteStuff, 4);
}
