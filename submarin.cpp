#include "submarin.h"
#include "validate.h"
#include "ps2m3d.h"

EXPORT u8 submarinerDieRelated;
extern CBaddy* BaddyList;

EXPORT SLight M3d_SubmarinerLight =
{
  { { -2430, -2228, -2430 }, { 2509, -2896, 1447 }, { -648, -3711, -1607 } },
  0,
  { { 3200, 1040, 2048 }, { 2720, 1600, 1920 }, { 2400, 2560, 2048 } },
  0,
  { 1200, 1200, 960 }
};

// @Ok
// @Matching
void Submariner_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Submariner_RelocatableModuleClear;
	pMod->field_C[0] = Submariner_CreateSubmariner;
}

// @NotOk
// fix the address for 3C
CSubmariner::CSubmariner(i16 * a2, i32 a3)
{
	this->InitItem("mariner");
	this->SquirtAngles(this->SquirtPos(a2));
	this->CycleAnim(0, 1);
	this->mFlags |= 0x480u;

	this->mpLight = &M3d_SubmarinerLight;

	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));
	this->field_38 = 326;
	this->field_DE = a3;
	this->field_DC = 0;

	if ( submarinerDieRelated )
		this->Die(0);
}

// @Ok
CSubmariner::~CSubmariner(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
}

// @Ok
void Submariner_CreateSubmariner(const u32 * a2,u32 * a3)
{
	i16* v2 = reinterpret_cast<i16*>(a2[0]);
	i32 v3 = static_cast<i32>(a2[1]);

	*a3 = reinterpret_cast<u32>(new CSubmariner(v2, v3));
}

// @Ok
void Submariner_RelocatableModuleClear(void)
{
	for (CBody* cur = BaddyList; cur; )
	{
		CBody* next = reinterpret_cast<CBody*>(cur->mNextItem);
		if (cur->field_38 == 319)
		{
			delete cur;
		}

		cur = next;
	}
}

// @Ok
void CSubmariner::AI(void){
	if (submarinerDieRelated){
		this->Die(0);
	}
	else{
		M3d_BuildTransform(this);
	}
}


void validate_CSubmariner(void){
	VALIDATE_SIZE(CSubmariner, 0x324);
}
