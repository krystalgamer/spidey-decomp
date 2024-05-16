#include "hostage.h"
#include "validate.h"


CHostage::CHostage(int* a2, int a3)
{
	__int16 *afterAngles = this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));

	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));
	this->ShadowOn();

	int v6 = this->field_2A8 | 1;

	this->field_D0 = 48;
	this->field_1F4 = a3;
	this->field_DE = a3;
	this->field_DC = 128;
	this->field_230 = 0;
	this->field_216 = 32;

	this->field_D8 = 64;
	this->field_324 = 0;

	this->field_2A8 = v6;

	unsigned char * ptr = reinterpret_cast<unsigned char*>(0x551FF0);
	this->field_294 = ptr[0];
	this->field_295 = ptr[1];
	this->field_296 = ptr[2];
	this->field_297 = ptr[3];
	this->field_298 = ptr[4];
	this->field_299 = ptr[5];
	this->field_29A = ptr[6];
	this->field_29B = ptr[7];

	this->mCBodyFlags &= 0xFFEF;
	this->ParseScript(reinterpret_cast<unsigned __int16*>(afterAngles));
}

void validate_CHostage(void){
	VALIDATE_SIZE(CHostage, 0x334);


	VALIDATE(CHostage, field_324, 0x324);
	VALIDATE(CHostage, field_328, 0x328);
	VALIDATE(CHostage, field_32C, 0x32C);
}
