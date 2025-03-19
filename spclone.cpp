#include "spclone.h"
#include "validate.h"

extern CBaddy* BaddyList;
extern u8 submarinerDieRelated;

// @Ok
// @Matching
void SpClone_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = SpClone_RelocatableModuleClear;
	pMod->field_C[0] = SpClone_CreateSpClone;
}

// @MEDIUMTODO
void CSpClone::AI(void)
{
    printf("CSpClone::AI(void)");
}

// @Ok
// @Matching
CSpClone::CSpClone(i16 * a2,i32 a3)
{
	this->InitItem("spidey");
	this->field_194 &= 0xFFFFFFDF;
	this->field_194 |= 0x40u;
	this->field_194 &= 0xFFFFFBFF;
	this->field_194 |= 0x800u;

	i16 *v5 = this->SquirtAngles(this->SquirtPos(a2));

	this->ShadowOn();
	this->field_D0 = 48;
	this->field_21E = 100;
	this->field_32C = 2;
	this->field_330 = 2;

	this->RunAnim(0xCAu, 0, -1);
	this->mFlags |= 0x480u;

	// @FIXME figure this shit
	this->mpLight = 0x555920;

	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));

	this->field_38 = 327;
	this->field_31C.bothFlags = 1;
	this->field_DE = a3;
	this->field_DC = 0;
	this->field_348 = reinterpret_cast<i32>(v5);

	if ( submarinerDieRelated )
		this->Die(0);
}

// @MEDIUMTODO
void CSpClone::DoMGSShadow(void)
{
    printf("CSpClone::DoMGSShadow(void)");
}

// @Ok
INLINE i32* CSpClone::GetNewCommandBlock(u32 a1)
{
	i32* res = static_cast<i32*>(DCMem_New(4 * a1, 0, 1, 0, 1));
	res[a1 - 1] = 0;

	if (!this->field_34C)
	{
		this->field_34C = res;
	}
	else
	{
		i32* it = this->field_34C;
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
// @Matching
void CSpClone::KillCommandBlockByID(i32 a2)
{
	i32* i = this->field_34C;
	while(i)
	{
		if (*i == a2)
			this->KillCommandBlock(i);

		i = reinterpret_cast<i32*>(i[i[1] - 1]);
	}
}

// @MEDIUMTODO
void CSpClone::SynthesizeAnalogueInput(void)
{
    printf("CSpClone::SynthesizeAnalogueInput(void)");
}

// @Ok
CSpClone::~CSpClone(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));

	delete this->field_338;

	this->KillAllCommandBlocks();
}

// @Ok
// @Matching
void SpClone_CreateSpClone(const u32 * a2,u32 * a3)
{
	i16* v2 = reinterpret_cast<i16*>(a2[0]);
	i32 v3 = static_cast<i32>(a2[1]);

	*a3 = reinterpret_cast<u32>(new CSpClone(v2, v3));
}

// @Ok
// @Matching
void SpClone_RelocatableModuleClear(void)
{
	for (CBody* cur = BaddyList; cur; )
	{
		CBody* next = reinterpret_cast<CBody*>(cur->field_20);
		if (cur->field_38 == 327)
		{
			delete cur;
		}

		cur = next;
	}
}

// @Ok
void CSpClone::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @BIGTODO
void CSpClone::DoPhysics(void)
{}

// @Ok
// @Matching
INLINE i32* CSpClone::KillCommandBlock(i32* a1)
{
	i32* res = reinterpret_cast<i32*>(a1[a1[1]-1]);

	if (this->field_34C == a1)
	{
		this->field_34C = res;
	}
	else
	{
		i32* it = this->field_34C;

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
void CSpClone::KillAllCommandBlocks(void)
{
	for (int* cur = reinterpret_cast<int*>(this->field_34C); cur; cur = this->KillCommandBlock(cur));
	this->field_34C = 0;
}

void validate_CSpClone(void){
	VALIDATE_SIZE(CSpClone, 0x350);

	VALIDATE(CSpClone, field_328, 0x328);
	VALIDATE(CSpClone, field_32C, 0x32C);
	VALIDATE(CSpClone, field_330, 0x330);
	VALIDATE(CSpClone, field_334, 0x334);
	VALIDATE(CSpClone, field_338, 0x338);

	VALIDATE(CSpClone, field_348, 0x348);

	VALIDATE(CSpClone, field_34C, 0x34C);
}
