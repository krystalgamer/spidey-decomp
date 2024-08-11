#include "lizard.h"
#include "validate.h"
#include "ps2m3d.h"

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
		CBody* next = reinterpret_cast<CBody*>(cur->field_20);
		if (cur->field_38 == 319)
		{
			delete cur;
		}

		cur = next;
	}
}

// @Ok
void CLizard::AI(void)
{
	__int16 v2 = this->field_44;
	if (v2 & 1)
	{
		this->field_44 = v2 & 0xFFFE;
		this->CycleAnim(this->field_12A == 0 ? 5 : 0, 1);
	}

	if (this->pMessage)
	{
		this->CleanUpMessages(1, 0);
	}

	M3d_BuildTransform(this);
}

// @NotOk
// gloabal in 3C
CLizard::CLizard(int* a2, __int16 a3)
{
	this->InitItem("lizard");

	this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));

	this->CycleAnim(0, 1);
	this->mFlags |= 0x480;
	// @FIXME
	this->field_3C = 0x0054B530;

	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));
	this->field_38 = 326;

	this->field_DE = a3;
	this->field_DC = 0;
}

// @Ok
void Lizard_CreateLizard(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CLizard(v2, v3));
}

void validate_CLizard(void){
	VALIDATE_SIZE(CLizard, 0x324);
}
