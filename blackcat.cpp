#include "blackcat.h"
#include "validate.h"
#include "trig.h"

extern u8 submarinerDieRelated;
extern CBaddy* BaddyList;

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

// @SMALLTODO
void CBlackCat::GetNewCommandBlock(u32)
{
    printf("CBlackCat::GetNewCommandBlock(u32)");
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
CBlackCat::CBlackCat(int* a2, int a3)
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
	this->field_3C = 0x548728;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->field_38 = 319;
	this->field_31C.bothFlags = 1;

	this->field_DE = a3;
	this->field_DC = 0;
	this->field_34C = reinterpret_cast<int>(v5);

	if (submarinerDieRelated && Trig_GetLevelId() != 2051)
		this->Die(0);
}

// @Ok
void BlackCat_CreateBlackCat(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CBlackCat(v2, v3));
}


// @Ok
void CBlackCat::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @BIGTODO
void CBlackCat::DoPhysics(void)
{}

// @BIGTODO
int* CBlackCat::KillCommandBlock(int*)
{
	return (int*)0x01062024;
}

// @NotOk
// Revisit
void CBlackCat::KillAllCommandBlocks(void)
{
	for (int* cur = reinterpret_cast<int*>(this->field_350); cur; cur = this->KillCommandBlock(cur));
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
