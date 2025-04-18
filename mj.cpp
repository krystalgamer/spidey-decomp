#include "mj.h"
#include "validate.h"
#include "ps2m3d.h"

extern u8 submarinerDieRelated;

// @Ok
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
		CBody* next = reinterpret_cast<CBody*>(cur->mNextItem);
		if (cur->mType == 319)
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

	if(this->mInputFlags & 1){
		this->mInputFlags &= 0xFFFE;
		this->CycleAnim(1 - this->mAnim, 1);
	}

	M3d_BuildTransform(this);
}

// @Ok
// @Matching
CMJ::CMJ(i16* a2, i32 a3)
{
	this->InitItem("mj");

	this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));

	this->CycleAnim(0, 1);
	this->mFlags |= 0x480;
	this->mpLight = &M3d_MJLight;

	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));
	this->mType = 303;

	this->mNode = a3;
	this->mRMinor = 0;

	if (submarinerDieRelated)
		this->Die(0);
}

// @Ok
void MJ_CreateMJ(const u32 *stack, u32 *result)
{
	i16* v2 = reinterpret_cast<i16*>(*stack);
	i32 v3 = static_cast<i32>(stack[1]);

	*result = reinterpret_cast<u32>(new CMJ(v2, v3));
}

void validate_CMJ(void){
	VALIDATE_SIZE(CMJ, 0x324);
}
