#include "shell.h"
#include "validate.h"
#include "ps2m3d.h"
#include "utils.h"
#include "ps2lowsfx.h"

// @Ok
void CDummy::SelectNewAnim(void)
{
	if (this->field_1B8)
	{
		this->field_1B8++;
		if (*this->field_1B8 == 0xFFFF)
		{
			this->SelectNewTrack(0);
		}
		else
		{
			this->RunAnim(*this->field_1B8, 0, -1);
		}
	}
	else
	{
		this->RunAnim(this->field_1C0, 0, -1);
	}
}

// @Ok
void CDummy::SelectNewTrack(int a2)
{
	this->field_1B8 = 0;
	this->field_1BC = 0;

	if (this->field_1A4 || this->field_1A8 || this->field_1AC)
	{
		do
		{
			switch(Rnd(3))
			{
				case 0:
					this->field_1B8 = this->field_1A4;
					break;
				case 1:
					this->field_1B8 = this->field_1A8;
					break;
				case 2:
					this->field_1B8 = this->field_1AC;
					break;
			}
		}
		while(!this->field_1B8);

		print_if_false(*this->field_1B8 != 0xFFFF, "First anim must not be 0xFFFF");

		if (a2)
		{
			u16 *v7 = this->field_1B8;
			i32 i = 0;
			for (i = 0; *v7 != 0xFFFF; i++)
				v7++;

			i32 v9 = 0;
			i32 v10;
			do
			{
				v10 = Rnd(i);
				v9++;
			}
			while (this->field_1B8[v10] == this->field_12A && v9 < 100);

			if (this->field_1B8[v10] != this->field_12A)
				this->field_1B8 = &this->field_1B8[v10];
		}

		this->field_1BC = this->field_1B8;
		this->RunAnim(*this->field_1BC, 0, -1);
	}
	else
	{
		this->RunAnim(this->field_1C0, 0, -1);
	}
}

// @Ok
void __inline CDummy::FadeAway(void)
{
	this->field_1F8 = 1;
	this->field_1FC = 0;

	this->mFlags &= 0xFF7F;
	this->mFlags |= 0x800;

	this->field_24 = 0x202020;

	this->OutlineOn();
	this->SetOutlineSemiTransparent();
	this->SetOutlineRGB(0, 0, 0);
}

// @Ok
void __inline CDummy::FadeBack(void)
{
	this->field_1FC = 1;
	this->field_1F8 = 0;
}

static const __int16 *word_610C48 = (__int16*)0x610C48;

// @Not
// Global
void __inline CWobblyGlow::Move(void)
{
	for (unsigned int i = 0; i < this->field_44; i++)
	{
		this->field_5C[8+i] += this->field_5C[i];
		int v3 = this->field_5C[8+i];
		this->field_3C[2*i] = this->field_A0 + this->field_9C * word_610C48[2 * (v3 & 0xFFF)] / 4096;
	}
}

// @Ok
void CShellMysterioHeadGlow::Move(void)
{
	CWobblyGlow::Move();
	this->field_54 += this->field_A4;
}

// @Ok
void Spidey_CIcon::AI(void)
{
	this->mAngles.vy += 50;
	if (this->mFlags & 2)
	{
		this->UpdateFrame();
		M3d_BuildTransform(this);
	}
}

// @NotOk
// globals
CRudeWordHitterSpidey::CRudeWordHitterSpidey(void)
{
	this->InitItem("spidey");
	this->mFlags |= 0x480;

	this->field_3C = 0x552710; // <- global

	this->field_194 |= 0x420;

	this->RunAnim(0, 0, -1);

	this->field_128 = 18;
	this->mPos.vx = 0xFFF92000;
	this->mPos.vy = 0x104000;
	this->mPos.vz = 0x1F4000;
	this->mAngles.vy = 0xFD76;
}

// @Ok
void CRudeWordHitterSpidey::AI(void)
{
	this->field_1A8++;
	if (this->field_1A8 > 60)
	{
		this->mPos.vy += 0x14000;
	}
	else
	{
		this->mPos.vy -= 0x14000;
		if (this->mPos.vy < 0x91000)
		{
			this->mPos.vy = 0x91000;
		}
	}

	if (this->field_142)
	{
		if (!this->field_12A)
		{
			this->RunAnim(0x64, 0, -1);
		}
		else
		{
			this->RunAnim(0, 0, -1);
		}
	}

	this->UpdateFrame();

	if (this->field_128 == 7 && !this->field_1A4)
	{
		switch (Rnd(4))
		{
			case 0:
				SFX_Play(0xE, 0x2000, 0);
				break;
			case 1:
				SFX_Play(0xF, 0x2000, 0);
				break;
			case 2:
				SFX_Play(0x10, 0x2000, 0);
				break;
			case 3:
				SFX_Play(0x11, 0x2000, 0);
				break;
			default:
				break;
		}

		this->field_1A4 = 1;
	}

	M3d_BuildTransform(this);
}

CBody *MiscList;

// @Ok
CShellSymBurn::CShellSymBurn(CVector* pVector)
{
	this->mPos = *pVector;
	this->InitItem("fire");
	this->mFlags |= 0x602;
	this->field_2A = 0;
	this->field_24 = 0xFFFFFF;
	this->AttachTo(&MiscList);
}

void validate_CRudeWordHitterSpidey(void){
	VALIDATE_SIZE(CRudeWordHitterSpidey, 0x1AC);

	
	VALIDATE(CRudeWordHitterSpidey, field_194, 0x194);
	VALIDATE(CRudeWordHitterSpidey, field_1A4, 0x1A4);
	VALIDATE(CRudeWordHitterSpidey, field_1A8, 0x1A8);
}

void validate_CDummy(void){
	VALIDATE_SIZE(CDummy, 0xA18);

	VALIDATE(CDummy, field_1A4, 0x1A4);
	VALIDATE(CDummy, field_1A8, 0x1A8);
	VALIDATE(CDummy, field_1AC, 0x1AC);
	VALIDATE(CDummy, field_1B8, 0x1B8);
	VALIDATE(CDummy, field_1BC, 0x1BC);
	VALIDATE(CDummy, field_1C0, 0x1C0);

	VALIDATE(CDummy, field_1F8, 0x1F8);
	VALIDATE(CDummy, field_1FC, 0x1FC);

	VALIDATE(CDummy, field_240, 0x240);
	VALIDATE(CDummy, field_288, 0x288);

	VALIDATE(CDummy, field_2D4, 0x2D4);
	VALIDATE(CDummy, field_304, 0x304);
	VALIDATE(CDummy, field_418, 0x418);
}

void validate_CShellMysterioHeadGlow(void)
{
	VALIDATE_SIZE(CShellMysterioHeadGlow, 0xA8);

	VALIDATE(CShellMysterioHeadGlow, field_A4, 0xA4);
}


void validate_CWobblyGlow(void)
{
	VALIDATE_SIZE(CWobblyGlow, 0xA4);

	VALIDATE(CWobblyGlow, field_5C, 0x5C);

	VALIDATE(CWobblyGlow, field_9C, 0x9C);
	VALIDATE(CWobblyGlow, field_A0, 0xA0);
}

void validate_Spidey_CIcon(void)
{
	VALIDATE_SIZE(Spidey_CIcon, 0x1A4);
}

void validate_CShellSymBurn(void)
{
	VALIDATE_SIZE(CShellSymBurn, 0x1A8);
}
