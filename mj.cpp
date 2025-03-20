#include "mj.h"
#include "validate.h"
#include "ps2m3d.h"

extern u8 submarinerDieRelated;

EXPORT SLight M3d_MJLight =
{
  { { -2430, -2228, -2430 }, { 2509, -2896, 1447 }, { -648, -3711, -1607 } },
  0,
  { { 3200, 1040, 2048 }, { 2720, 1600, 1920 }, { 2400, 2560, 2048 } },
  0,
  { 1200, 1200, 960 }
};


// @Ok
// @Matching
void MJ_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = MJ_RelocatableModuleClear;
	pMod->field_C[0] = MJ_CreateMJ;
}

// @Ok
CMJ::~CMJ(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
}

// @Ok
void MJ_RelocatableModuleClear(void)
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

// @Ok
void CMJ::AI(void) 
{
	if (this->pMessage){
		this->CleanUpMessages(1, 0);
	}

	if(this->field_44 & 1){
		this->field_44 &= 0xFFFE;
		this->CycleAnim(1 - this->field_12A, 1);
	}

	M3d_BuildTransform(this);
}

// @NotOk
// globals
CMJ::CMJ(int* a2, __int16 a3)
{
	this->InitItem("mj");

	this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));

	this->CycleAnim(0, 1);
	this->mFlags |= 0x480;
	this->mpLight = &M3d_MJLight;

	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));
	this->field_38 = 303;

	this->field_DE = a3;
	this->field_DC = 0;

	if (submarinerDieRelated)
		this->Die(0);
}

// @Ok
void MJ_CreateMJ(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CMJ(v2, v3));
}

void validate_CMJ(void){
	VALIDATE_SIZE(CMJ, 0x324);
}
