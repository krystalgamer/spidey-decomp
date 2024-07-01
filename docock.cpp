#include "docock.h"
#include "validate.h"
#include "trig.h"
#include "panel.h"
#include "ps2m3d.h"
#include "web.h"
#include "mem.h"
#include "utils.h"

// @NotOk
// globals
// also the loops starts at 338 not 334 (it offsets negatively for some reason...)
CDocOc::CDocOc(int *a2, int a3)
{
	this->field_328 = 0;
	this->field_32C = 0;
	this->field_330 = 0;

	for (int i = 0; i<30;i++)
	{
		this->field_334[i].vx = 0;
		this->field_334[i].vy = 0;
		this->field_334[i].vz = 0;
	}

	this->field_50C.vx = 0;
	this->field_50C.vy = 0;
	this->field_50C.vz = 0;

	unsigned __int16 *LinksPointer = reinterpret_cast<unsigned __int16*>(Trig_GetLinksPointer(a3));
	print_if_false(*LinksPointer == 1, "Error");
	Trig_GetPosition(&this->field_50C, LinksPointer[1]);

	this->field_4A8 = reinterpret_cast<int>(
			this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2))));

	this->InitItem("docock");

	this->mFlags |= 0x480;
	this->mCBodyFlags &= 0xFFEF;
	this->field_3C = 0x549E80;

	this->field_E2 = 600;
	this->field_DC = 0;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->field_1F4 = a3;
	this->field_DE = a3;
	this->field_38 = 308;
	this->field_31C.bothFlags = 1;

	this->field_554 = 4;
	this->field_4EC = 1;
	this->field_324 = 25;
	this->field_21E = 100;

	if (*reinterpret_cast<unsigned char*>(0x0060CFC5))
	{
		this->mFlags |= 0x200;
		this->field_28 = 2048;
		this->field_2A = 2048;
		this->field_2C = 2048;
	}

	Panel_CreateHealthBar(this, 308);
	this->field_194 = 0xFFFC0000;
	this->field_198 = 0x3FFF;
}

// @Ok
void DocOck_CreateDocOck(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CDocOc(v2, v3));
}

// @Ok
void CDocOc::RenderClaws(void)
{
	M3d_Render(this->field_570);
}

// @Ok
void INLINE CDocOc::PlaySingleAnim(unsigned int a2, int a3, int a4)
{
	this->field_4C4 = 0;
	this->RunAnim(a2, a3, a4);
}

// @TODO
void CDocOc::PlayIdleOrGloatAnim(void)
{}

// @Ok
void __inline CDocOc::Gloat(void)
{
	if(this->field_142)
	{
		this->field_31C.bothFlags = 2;
		this->dumbAssPad = 0;
		this->PlayIdleOrGloatAnim();
	}
}

// @TODO
__inline int* CDocOc::KillCommandBlock(int*)
{
	return (int*)0x02062024;
}

// @NotOk
// Revisit
void CDocOc::KillAllCommandBlocks(void)
{
	for (int* cur = reinterpret_cast<int*>(this->field_4AC); cur; cur = this->KillCommandBlock(cur));
	this->field_4AC = 0;
}

// @Ok
void CDocOc::TakeHit(void)
{
	CTrapWebEffect *pWeb;
	switch (this->dumbAssPad)
	{
		case 0:

			pWeb = reinterpret_cast<CTrapWebEffect*>(
					Mem_RecoverPointer(&this->field_104));

			if (pWeb)
				pWeb->Burst();

			this->field_104.field_0 = 0;

			if (this->field_218 & 0x10)
			{
				this->PlaySingleAnim(0x1C, 0, -1);
			}
			else if (this->field_218 & 0x20)
			{
				this->PlaySingleAnim(0x1D, 0, -1);
			}
			else if (this->field_218 & 0x40)
			{
				this->PlaySingleAnim(0x1E, 0, -1);
			}
			else
			{
				this->PlaySingleAnim(0x1B, 0, -1);
			}

			this->dumbAssPad++;

			break;
		case 1:
			if (this->field_142)
			{
				this->PlayIdleOrGloatAnim();
				this->field_31C.bothFlags = 1024;
				this->dumbAssPad = 1;
			}
			break;
	}
}

// @Ok
INLINE void CDocOc::CalculateStage(void)
{
	if (this->field_E2 > 400)
	{
		this->field_550 = 1;
	}
	else if (this->field_E2 > 200)
	{
		this->field_550 = 2;
	}
	else
	{
		this->field_550 = 3;
	}
}

// @Ok
void CDocOc::HangAndGetBeaten(void)
{

	if (this->field_142)
	{
		if (this->field_12A == 23 || this->field_12A == 32)
		{
			this->PlaySingleAnim(0x17, 0, -1);
		}
		else
		{
			this->PlaySingleAnim(0x20, 0, -1);
		}
	}

	switch(this->dumbAssPad)
	{
		case 0:
			this->mCBodyFlags |= 0x10;
			this->field_DC = 100;
			this->dumbAssPad = 1;
			break;
		case 1:
			if (!this->field_4B8)
			{
				this->mCBodyFlags &= 0xFFEF;
				this->field_DC = 0;

				if (this->field_104.field_0)
				{
					CTrapWebEffect *pWeb = reinterpret_cast<CTrapWebEffect*>(
							Mem_RecoverPointer(&this->field_104));

					if (pWeb)
						pWeb->Burst();

					this->field_104.field_0 = 0;
				}

				this->PlaySingleAnim(0x18, 0, -1);
				this->field_31C.bothFlags = 2048;
				this->dumbAssPad = 0;
			}
			break;
	}
}

// @TODO
void CDocOc::ResolveSwitches(void)
{}

void CDocOc::Initialise(void)
{
	this->field_518 = 455;
	this->ResolveSwitches();
	this->field_4EC = 1;
	this->field_4F4 = Rnd(4);

	print_if_false(this->field_4FC[64] == 1, "Error0");
	print_if_false(this->field_500[64] == 1, "Error1");
	print_if_false(this->field_504[64] == 1, "Error2");
	print_if_false(this->field_508[64] == 1, "Error3");

	this->field_31C.bothFlags = 0x10000;
	this->dumbAssPad = 0;
	this->bodyVector.vy = Utils_GetGroundHeight(&this->mPos, 0, 0x2000, 0);
	if (this->bodyVector.vy != -1)
	{
		this->mPos.vy = this->bodyVector.vy - (this->field_21E << 12);
	}

	this->CalculateStage();
}

void validate_CDocOc(void){
	VALIDATE_SIZE(CDocOc, 0x590);

	VALIDATE(CDocOc, field_324, 0x324);
	VALIDATE(CDocOc, field_328, 0x328);
	VALIDATE(CDocOc, field_32C, 0x32C);
	VALIDATE(CDocOc, field_330, 0x330);
	VALIDATE(CDocOc, field_334, 0x334);

	VALIDATE(CDocOc, field_4A8, 0x4A8);
	VALIDATE(CDocOc, field_4B8, 0x4B8);
	VALIDATE(CDocOc, field_4AC, 0x4AC);

	VALIDATE(CDocOc, field_4C4, 0x4C4);

	VALIDATE(CDocOc, field_4EC, 0x4EC);

	VALIDATE(CDocOc, field_4F4, 0x4F4);

	VALIDATE(CDocOc, field_4FC, 0x4FC);
	VALIDATE(CDocOc, field_500, 0x500);
	VALIDATE(CDocOc, field_504, 0x504);
	VALIDATE(CDocOc, field_508, 0x508);


	VALIDATE(CDocOc, field_50C, 0x50C);
	VALIDATE(CDocOc, field_518, 0x518);

	VALIDATE(CDocOc, field_550, 0x550);

	VALIDATE(CDocOc, field_554, 0x554);
	VALIDATE(CDocOc, field_570, 0x570);
}
