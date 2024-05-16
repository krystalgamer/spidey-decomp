#include "lizard.h"
#include "validate.h"
#include "ps2m3d.h"


// @Ok
void CLizard::AI(void)
{
	__int16 v2 = this->field_44;
	if (v2 & 1)
	{
		this->field_44 = v2 & 0xFFFE;
		this->CycleAnim(this->field_12A == 0 ? 5 : 0, 1);
	}

	if (this->field_290)
	{
		this->CleanUpMessages(1, 0);
	}

	M3d_BuildTransform(this);
}

// @NotOk
// globals
// also args to SquirtAngles wtf??
CLizard::CLizard(int* a2, __int16 a3)
{
	this->InitItem("lizard");

	this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));

	this->CycleAnim(0, 1);
	this->mFlags |= 0x480;
	this->field_3C = 0x0054B530;

	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));
	this->field_38 = 326;

	this->field_DE = a3;
	this->field_DC = 0;
}

void validate_CLizard(void){
	VALIDATE_SIZE(CLizard, 0x324);
}
