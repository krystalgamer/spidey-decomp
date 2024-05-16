#include "rhino.h"
#include "validate.h"
#include "utils.h"
#include "panel.h"

static __int16 * const word_682B64 = (__int16*)0x682B64;

// @NotOk
// globals
CRhino::CRhino(int* a2, int a3)
{

	__int16 *v5 = this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));
	this->InitItem("rhino");

	this->mFlags |= 0x480;
	this->field_3C = 0x552080;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E990));

	this->field_21E = 100;
	this->field_1F4 = a3;
	this->field_DE = a3;
	this->field_DC = 175;

	this->field_230 = 0;
	this->field_216 = 32;

	this->field_D8 = 64;
	this->field_31C.bothFlags = 0;
	this->field_2A8 |= 0x2000201;
	this->field_38 = 307;
	this->field_E2 = Utils_GetValueFromDifficultyLevel(1400, 1400, 1400, 1400);

	unsigned char * ptr = reinterpret_cast<unsigned char*>(0x552008);
	this->field_294 = ptr[0];
	this->field_295 = ptr[1];
	this->field_296 = ptr[2];
	this->field_297 = ptr[3];
	this->field_298 = ptr[4];
	this->field_299 = ptr[5];
	this->field_29A = ptr[6];
	this->field_29B = ptr[7];
	this->field_344 = *dword_5FCCF4 + 0xFFFFFF10;

	int i = 0;
	while (i < 5)
	{
		word_682B64[i++] = Rnd(4096);
	}

	int v7 = 0;
	int *v8 = (int*)0x552210;

	do
	{
		if (*v8 != v7)
			print_if_false(0, "Fire Matt, he fucked up the rhino XA.  Actually, kick him in the nuts first.");

		v8 += 3;
		v7++;
	}
	while(v7 < 0x17);



	this->ParseScript(reinterpret_cast<unsigned __int16*>(v5));
	Panel_CreateHealthBar(this, 307);
}

// @NotOk
// globals
CRhino::CRhino(void)
{
	this->InitItem("rhino");
	this->mFlags |= 0x480;
	this->field_3C = 0x552080;
	this->field_38 = 307;
}

// @Ok
void Rhino_CreateRhino(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	if (v2)
	{
		*result = reinterpret_cast<unsigned int>(new CRhino(v2, v3));
	}
	else
	{
		*result = reinterpret_cast<unsigned int>(new CRhino());
	}
}

void validate_CRhino(void){
	VALIDATE_SIZE(CRhino, 0x424);

	VALIDATE(CRhino, field_344, 0x344);
}
