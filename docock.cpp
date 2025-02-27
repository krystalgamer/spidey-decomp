#include "docock.h"
#include "validate.h"
#include "trig.h"
#include "panel.h"
#include "ps2m3d.h"
#include "web.h"
#include "mem.h"
#include "utils.h"
#include "spidey.h"
#include "panel.h"

extern CPlayer* MechList;
extern CBaddy* BaddyList;
extern i32 gBossRelated;
extern CBody* ControlBaddyList;

// @Ok
// @Matching
void DocOck_RelocatableModuleClear(void)
{
	CItem *pSearch = BaddyList;

	while (pSearch)
	{
		CItem *pNext = pSearch->field_20;

		if (pSearch->field_38 == 308)
			delete pSearch;

		pSearch = pNext;
	}
}

// @Ok
// @Matching
void DocOck_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = DocOck_RelocatableModuleClear;
	pMod->field_C[0] = DocOck_CreateDocOck;
}

// @Ok
INLINE i32* CDocOc::GetNewCommandBlock(u32 a1)
{
	i32* res = static_cast<i32*>(DCMem_New(4 * a1, 0, 1, 0, 1));
	res[a1 - 1] = 0;

	if (!this->field_4AC)
	{
		this->field_4AC = res;
	}
	else
	{
		i32* it = this->field_4AC;
		while (1)
		{
			if (!it[it[1] - 1])
				break;

			it = reinterpret_cast<i32*>(it[it[1] - 1]);
		}

		it[it[1] - 1] = reinterpret_cast<i32>(res);
	}

	return res;
}

// @Ok
CDocOc::~CDocOc(void)
{
	gBossRelated = 0;
	Panel_DestroyHealthBar();
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
	this->KillAllCommandBlocks();

	for (i32 i = 0; i<4; i++)
	{
		if (this->field_530[i])
			Mem_Delete(this->field_530[i]);

		delete reinterpret_cast<CClass*>(this->field_580[i]);
		delete reinterpret_cast<CClass*>(this->field_570[i]);
	}
}

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
			this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2))));

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
	M3d_Render(this->field_570[0]);
}

// @Ok
void INLINE CDocOc::PlaySingleAnim(unsigned int a2, int a3, int a4)
{
	this->field_4C4 = 0;
	this->RunAnim(a2, a3, a4);
}


// @Ok
void CDocOc::PlayIdleOrGloatAnim(void)
{
	if ((this->field_218 & 8) == 0)
	{
		if (!this->field_554)
		{
			this->PlaySingleAnim(32, 0, -1);
		}
		else
		{
			this->CalculateStage();
			if (this->field_55C <= 600 && MechList->field_E2 > 0)
			{
				if (this->field_550 == 1)
					this->PlaySingleAnim(5, 0, -1);
				else
					this->PlaySingleAnim(0, 0, -1);
			}
			else
			{
				if (this->field_550 == 1)
					this->PlaySingleAnim(35, 0, -1);
				else
					this->PlaySingleAnim(1, 0, -1);

				this->field_55C = 0;
				this->field_31C.bothFlags = 0x8000;
				this->dumbAssPad = 0;
			}
		}
	}
}

// @Ok
INLINE void CDocOc::Gloat(void)
{
	if (this->field_142)
	{
		this->field_31C.bothFlags = 2;
		this->dumbAssPad = 0;
		this->PlayIdleOrGloatAnim();
	}
}

// @Ok
// @Matching
INLINE i32* CDocOc::KillCommandBlock(i32* a1)
{
	i32* res = reinterpret_cast<i32*>(a1[a1[1]-1]);

	if (this->field_4AC == a1)
	{
		this->field_4AC = res;
	}
	else
	{
		i32* it = this->field_4AC;

		while (it)
		{
			if (a1 == reinterpret_cast<i32*>(it[it[1]-1]))
			{
				it[it[1]-1] = reinterpret_cast<i32>(res);
				break;
			}

			it = reinterpret_cast<i32*>(it[it[1]-1]);
		}
	}

	Mem_Delete(reinterpret_cast<void*>(a1));
	return res;
}

// @Ok
// @Matching
INLINE void CDocOc::KillAllCommandBlocks(void)
{
	for (int* cur = this->field_4AC; cur; cur = this->KillCommandBlock(cur))
		;
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

// @NotOk
// missing tag
INLINE void CDocOc::ResolveSwitches(void)
{
	i32 index = 0;
	for (CBaddy* pBaddy = reinterpret_cast<CBaddy*>(ControlBaddyList);
			pBaddy;
			pBaddy = reinterpret_cast<CBaddy*>(pBaddy->field_20))
	{
		if (pBaddy->field_38 == 407)
		{
			this->field_4FC[index++] = pBaddy;
		}
	}

	print_if_false(index == 4, "Error");
}

// @NotOk
// missing tag
void CDocOc::Initialise(void)
{
	this->field_518 = 455;
	this->ResolveSwitches();
	this->field_4EC = 1;
	this->field_4F4 = Rnd(4);

	print_if_false(this->field_4FC[0]->field_100 == 1, "Error0");
	print_if_false(this->field_4FC[1]->field_100 == 1, "Error1");
	print_if_false(this->field_4FC[2]->field_100 == 1, "Error2");
	print_if_false(this->field_4FC[3]->field_100 == 1, "Error3");

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

	VALIDATE(CDocOc, field_50C, 0x50C);
	VALIDATE(CDocOc, field_518, 0x518);

	VALIDATE(CDocOc, field_530, 0x530);

	VALIDATE(CDocOc, field_550, 0x550);

	VALIDATE(CDocOc, field_554, 0x554);
	VALIDATE(CDocOc, field_55C, 0x55C);
	VALIDATE(CDocOc, field_570, 0x570);
	VALIDATE(CDocOc, field_580, 0x580);
}
