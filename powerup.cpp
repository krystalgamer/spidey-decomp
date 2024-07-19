#include "powerup.h"
#include "spool.h"

#include "validate.h"

extern i32 TotalBitUsage;

// @Ok
void CPowerUp::CreateBit(void)
{
	TotalBitUsage = 0; 
	if (this->field_38 == 18)
	{
		this->field_130 = new CFlatBit();

		Texture *pTexture = Spool_FindTextureEntry("TrainingPick-Up_01");
		this->field_130->SetTexture(pTexture);
		this->field_130->SetSemiTransparent();

		switch (this->field_E2)
		{
			case 0xA:
				this->field_130->SetTint(0x6Au, 212, 105);
				break;
			case 0x14:
				this->field_130->SetTint(0x85u, 133, 255);
				break;
			case 0x28:
				this->field_130->SetTint(0xFFu, 77, 77);
				break;
			case 0x50:
				this->field_130->SetTint(0xD8u, 216, 216);
				break;
			default:
				this->field_130->SetTint(0x80u, 128, 32);
				break;
		}
	}

	if (this->field_130)
		this->field_130->mProtected = 1;

	TotalBitUsage = 1; 
}

// @Ok
void CPowerUp::SetGravity(i32 a2, i32 a3)
{
	this->gVec.vy = a2;
	this->field_79 = a3;
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

	VALIDATE(CPowerUp, field_100, 0x100);
	VALIDATE(CPowerUp, field_106, 0x106);
}
