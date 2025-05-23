#include "lizard.h"
#include "validate.h"
#include "ps2m3d.h"

EXPORT SLight M3d_LizardLight =
{
  { { -2430, -2228, -2430 }, { 2509, -2896, 1447 }, { -648, -3711, -1607 } },
  0,
  { { 3200, 1040, 2048 }, { 2720, 1600, 1920 }, { 2400, 2560, 2048 } },

  0,
  { 1200, 1200, 960 }
};


// @Ok
// @Matching
void Lizard_RelocatableModuleInit(reloc_mod *pMod)
{
  pMod->mClearFunc = Lizard_RelocatableModuleClear;
  pMod->field_C[0] = Lizard_CreateLizard;
}

// @Ok
CLizard::~CLizard(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
}

// @Ok
void Lizard_RelocatableModuleClear(void)
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
void CLizard::AI(void)
{
	i16 v2 = this->mInputFlags;
	if (v2 & 1)
	{
		this->mInputFlags = v2 & 0xFFFE;
		this->CycleAnim(this->mAnim == 0 ? 5 : 0, 1);
	}

	if (this->pMessage)
	{
		this->CleanUpMessages(1, 0);
	}

	M3d_BuildTransform(this);
}

// @Ok
// @Matching
CLizard::CLizard(i16 *a2, i32 a3)
{
	this->InitItem("lizard");

	this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));

	this->CycleAnim(0, 1);
	this->mFlags |= 0x480;

	this->mpLight = &M3d_LizardLight;

	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));
	this->mType = 326;

	this->mNode = a3;
	this->mRMinor = 0;
}

// @Ok
void Lizard_CreateLizard(const u32 *stack, u32 *result)
{
	i16* v2 = reinterpret_cast<i16*>(*stack);
	i32 v3 = static_cast<i32>(stack[1]);

	*result = reinterpret_cast<u32>(new CLizard(v2, v3));
}

void validate_CLizard(void){
	VALIDATE_SIZE(CLizard, 0x324);
}
