#include "thug.h"
#include "validate.h"
#include "trig.h"

// @NotOk
// Globals
// also a little out of order with the v6 | 1 thing :(
CThug::CThug(int *a2, int a3)
{
	__int16 *v5 = this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));

	this->field_3B8 = Trig_GetLevelId();

	this->ShadowOn();
	this->field_D0 = 50;
	this->field_3B0 = *dword_5FCCF4;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E990));

	int v6 = this->field_2A8;
	this->field_1F4 = a3;
	this->field_DE = a3;

	__int16 v7 = this->field_38;
	this->field_230 = 0;
	this->field_216 = 32;
	this->field_2A8 = v6 | 1;

	this->field_DC = v7 != 304 ? 150 : 96;
	this->field_D8 = 64;
	this->field_380 = v7 != 304 ? 400 : 300;
	this->field_31C.bothFlags = 0;


	this->field_370 = 3500;
	this->field_374 = 400;
	this->field_378 = 2047;
	this->field_37C = 100;
	this->field_384 = 1500;
	this->field_388 = 10;
	this->field_38C = 10;

	this->field_1FC = 10;
	this->field_394 = 2000;
	this->ParseScript(reinterpret_cast<unsigned __int16*>(v5));
	this->field_212 = 60;
}

// @Ok
void Thug_CreateTHug(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CThug(v2, v3));
}

void validate_CThug(void){
	VALIDATE_SIZE(CThug, 0x3C0);


	VALIDATE(CThug, field_370, 0x370);
	VALIDATE(CThug, field_374, 0x374);
	VALIDATE(CThug, field_378, 0x378);
	VALIDATE(CThug, field_37C, 0x37C);
	VALIDATE(CThug, field_380, 0x380);
	VALIDATE(CThug, field_384, 0x384);
	VALIDATE(CThug, field_388, 0x388);
	VALIDATE(CThug, field_38C, 0x38C);

	VALIDATE(CThug, field_394, 0x394);
	VALIDATE(CThug, field_3B0, 0x3B0);
	VALIDATE(CThug, field_3B8, 0x3B8);
}
