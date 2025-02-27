#include "torch.h"
#include "export.h"
#include "validate.h"
#include "trig.h"
#include "mem.h"

extern u8 submarinerDieRelated;

// @Ok
// @Matching
void Torch_RelocatableModuleClear(void)
{
	CItem *pSearch = BaddyList;

	while (pSearch)
	{
		CItem *pNext = pSearch->field_20;

		if (pSearch->field_38 == 328)
			delete pSearch;

		pSearch = pNext;
	}
}

// @Ok
// @Matching
void Torch_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Torch_RelocatableModuleClear;
	pMod->field_C[0] = Torch_CreateTorch;
}

// @Ok
INLINE i32* CTorch::GetNewCommandBlock(u32 a1)
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

// @Ok
// @Matching
CTorch::~CTorch(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
	delete this->gTorchQuadBit;
	this->KillAllCommandBlocks();
}

// @NotOk
// Globals
CTorch::CTorch(int* a2, int a3)
{
	this->InitItem("torch");
	__int16 *v5 = this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));

	this->field_21E = 100;
	this->field_330 = 2;
	this->field_334 = 2;

	this->RunAnim(4, 0, -1);
	this->mFlags |= 0x480;

	this->field_3C = 0x557FE8;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E990));

	this->field_38 = 328;
	this->field_31C.bothFlags = 1;

	this->field_DE = a3;
	this->field_DC = 0;
	this->field_34C = reinterpret_cast<int>(v5);

	if (submarinerDieRelated && Trig_GetLevelId() != 2051)
		this->Die(0);
}

// @Ok
void Torch_CreateTorch(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CTorch(v2, v3));
}

// @Ok
void CTorch::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @BIGTODO
void CTorch::DoPhysics(void)
{}

// @Ok
// @Matching
INLINE i32* CTorch::KillCommandBlock(i32* a1)
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

// @Ok
// @Matching
INLINE void CTorch::KillAllCommandBlocks(void)
{
	for (i32* cur = this->field_350; cur; cur = this->KillCommandBlock(cur))
		;
	this->field_350 = 0;
}

void validate_CTorch(void){
	VALIDATE_SIZE(CTorch, 0x354);

	VALIDATE(CTorch, field_324, 0x324);
	VALIDATE(CTorch, field_328, 0x328);
	VALIDATE(CTorch, field_32C, 0x32C);
	VALIDATE(CTorch, field_330, 0x330);
	VALIDATE(CTorch, field_334, 0x334);
	VALIDATE(CTorch, field_338, 0x338);


	VALIDATE(CTorch, gTorchQuadBit, 0x33C);

	VALIDATE(CTorch, field_340, 0x340);
	VALIDATE(CTorch, field_344, 0x344);
	VALIDATE(CTorch, field_348, 0x348);

	VALIDATE(CTorch, field_34C, 0x34C);
	VALIDATE(CTorch, field_350, 0x350);
}
