#include "blackcat.h"
#include "validate.h"
#include "trig.h"

extern u8 submarinerDieRelated;
extern CBaddy* BaddyList;

EXPORT SLight M3d_BlackCatLight =
{
  { { -2047, -2896, -2047 }, { 0, 0, 4096 }, { 0, 0, -4096 } },
  0,
  { { 1520, 2000, 1840 }, { 1440, 1920, 1760 }, { 1440, 1920, 1760 } },
  0,
  { 1760, 1600, 1600 }
};


// @Ok
// @Matching
void BlackCat_RelocatableModuleInit(reloc_mod* pMod)
{
	pMod->mClearFunc = BlackCat_RelocatableModuleClear;
	pMod->field_C[0] = BlackCat_CreateBlackCat;
}

// @Ok
void BlackCat_RelocatableModuleClear(void)
{
	for (CBody* cur = BaddyList; cur; )
	{
		CBody* next = reinterpret_cast<CBody*>(cur->field_20);
		if (cur->field_38 == 319)
		{
			delete cur;
		}

		cur = next;
	}
}

// @MEDIUMTODO
void CBlackCat::AI(void)
{
    printf("CBlackCat::AI(void)");
}

// @MEDIUMTODO
void CBlackCat::DoMGSShadow(void)
{
    printf("CBlackCat::DoMGSShadow(void)");
}

// @Ok
i32* CBlackCat::GetNewCommandBlock(u32 a1)
{
	i32* res = static_cast<i32*>(DCMem_New(4 * a1, 0, 1, 0, 1));
	res[a1 - 1] = 0;

	if (!this->field_350)
	{
		this->field_350 = res;
	}
	else
	{
		i32* it = this->field_350;
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

// @SMALLTODO
void CBlackCat::KillCommandBlockByID(i32)
{
    printf("CBlackCat::KillCommandBlockByID(i32)");
}

// @MEDIUMTODO
void CBlackCat::SynthesizeAnalogueInput(void)
{
    printf("CBlackCat::SynthesizeAnalogueInput(void)");
}

// @NotOk
// guess type of 33C
CBlackCat::~CBlackCat(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
	delete reinterpret_cast<CClass*>(this->field_33C);

	this->KillAllCommandBlocks();
}

// @NotOk
// globals
CBlackCat::CBlackCat(i16* a2, i32 a3)
{
	if (Trig_GetLevelId() != 2051)
	{
		this->InitItem("blackcat");
	}
	else
	{
		this->InitItem("bc2");
	}

	i16 *v5 = this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));

	this->field_21E = 100;
	this->RunAnim(0xC, 0, -1);
	this->mFlags |= 0x480;

	this->mpLight = &M3d_BlackCatLight;
	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));

	this->field_38 = 319;
	this->field_31C.bothFlags = 1;

	this->field_DE = a3;
	this->field_DC = 0;
	this->field_34C = reinterpret_cast<i32>(v5);

	if (submarinerDieRelated && Trig_GetLevelId() != 2051)
		this->Die(0);
}

// @Ok
void BlackCat_CreateBlackCat(const u32 *stack, u32 *result)
{
	i16* v2 = reinterpret_cast<i16*>(*stack);
	i32 v3 = static_cast<i32>(stack[1]);

	*result = reinterpret_cast<u32>(new CBlackCat(v2, v3));
}


// @Ok
void CBlackCat::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @BIGTODO
void CBlackCat::DoPhysics(void)
{}

// @Ok
// @Matching
i32* CBlackCat::KillCommandBlock(i32* a1)
{
	i32* res = reinterpret_cast<i32*>(a1[a1[1]-1]);

	if (this->field_350 == a1)
	{
		this->field_350 = res;
	}
	else
	{
		i32* it = this->field_350;

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

// @NotOk
// Revisit
void CBlackCat::KillAllCommandBlocks(void)
{
	for (i32* cur = this->field_350; cur; cur = this->KillCommandBlock(cur));
	this->field_350 = 0;
}

void validate_CBlackCat(void){
	VALIDATE_SIZE(CBlackCat, 0x354);


	VALIDATE(CBlackCat, field_324, 0x324);
	VALIDATE(CBlackCat, field_328, 0x328);
	VALIDATE(CBlackCat, field_32C, 0x32C);

	VALIDATE(CBlackCat, field_33C, 0x33C);


	VALIDATE(CBlackCat, field_340, 0x340);
	VALIDATE(CBlackCat, field_344, 0x344);
	VALIDATE(CBlackCat, field_348, 0x348);

	VALIDATE(CBlackCat, field_34C, 0x34C);
	VALIDATE(CBlackCat, field_350, 0x350);
}
