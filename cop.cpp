#include "cop.h"
#include "validate.h"
#include "ps2lowsfx.h"

// @NotOk
// globals
CCop::CCop(int* a2, int a3)
{
	__int16 *v5 = this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));
	this->ShadowOn();
	this->field_D0 = 50;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));


	this->field_230 = 0;
	this->field_1F4 = a3;
	this->field_DE = a3;

	__int16 v6 = this->field_38;
	this->field_216 = 32;
	this->field_D8 = 64;
	this->field_31C.bothFlags = 0;
	this->field_DC = v6 != 306 ? 150 : 96;

	this->field_2A8 |= 1;

	this->field_370 = v6 != 306 ? 400 : 300;
	this->field_340 = *dword_5FCCF4;
	this->field_360 = 3500;
	this->field_364 = 400;
	this->field_368 = 2047;
	this->field_36C = 100;
	this->field_374 = 10;
	this->field_1FC = 10;
	this->field_37C = 2000;

	this->ParseScript(reinterpret_cast<unsigned __int16*>(v5));
	this->field_212 = 60;
}

// @Ok
void Cop_CreateCop(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CCop(v2, v3));
}

// @Ok
void CCop::Victorious(void)
{
	SFX_PlayPos(0x8024, &this->mPos, 0);
}

void validate_CCop(void){
	VALIDATE_SIZE(CCop, 0x394);
	VALIDATE(CCop, field_340, 0x340);
	VALIDATE(CCop, field_360, 0x360);
	VALIDATE(CCop, field_364, 0x364);
	VALIDATE(CCop, field_368, 0x368);
	VALIDATE(CCop, field_36C, 0x36C);
	VALIDATE(CCop, field_370, 0x370);
	VALIDATE(CCop, field_374, 0x374);

	VALIDATE(CCop, field_37C, 0x37C);
}
