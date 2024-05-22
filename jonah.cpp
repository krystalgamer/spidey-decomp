#include "jonah.h"
#include "validate.h"
#include "panel.h"

int JoelJewtCheatCode = 0;

// @NotOk
// globals
CJonah::CJonah(void)
{
	this->field_34C = 0;
	this->field_350 = 0;
	this->field_354 = 0;

	if (JoelJewtCheatCode)
	{
		this->InitItem("jjjj");
	}
	else
	{
		this->InitItem("jameson");
	}

	this->mFlags |= 0x480;
	this->field_3C = 0x552010;
	this->field_38 = 316;

}

// @NotOk
// Globals
CJonah::CJonah(int* a2, int a3)
{
	this->field_34C = 0;
	this->field_350 = 0;
	this->field_354 = 0;

	__int16 *v5 = this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));


	if (JoelJewtCheatCode)
	{
		this->InitItem("jjjj");
	}
	else
	{
		this->InitItem("jameson");
	}

	this->mFlags |= 0x480;
	this->field_3C = 0x552010;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E990));

	this->field_1F4 = a3;
	this->field_DE = a3;
	this->field_38 = 316;
	this->field_21E = 100;
	this->field_DC = 100;

	this->field_230 = 0;
	this->field_216 = 32;
	this->field_D8 = 64;
	this->field_31C.bothFlags = 0;

	this->field_2A8 |= 0x2002001;
	this->field_E2 = 120;

	unsigned char * ptr = reinterpret_cast<unsigned char*>(0x552008);
	this->field_294 = ptr[0];
	this->field_295 = ptr[1];
	this->field_296 = ptr[2];
	this->field_297 = ptr[3];
	this->field_298 = ptr[4];
	this->field_299 = ptr[5];
	this->field_29A = ptr[6];
	this->field_29B = ptr[7];

	this->mCBodyFlags &= 0xFFEF;
	this->ParseScript(reinterpret_cast<unsigned __int16*>(v5));
	Panel_CreateHealthBar(this, 316);
}

// @Ok
void Jonah_CreateJonah(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	if (v2)
	{
		*result = reinterpret_cast<unsigned int>(new CJonah(v2, v3));
	}
	else
	{
		*result = reinterpret_cast<unsigned int>(new CJonah());
	}
}

// @Ok
void CJonah::GraspWaypoint(SLinkInfo* a2)
{
	this->field_2F8 = a2->field_0;
	this->field_1F4 = a2->field_8;
}

void validate_CJonah(void){
	VALIDATE_SIZE(CJonah, 0x380);

	VALIDATE(CJonah, field_34C, 0x34C);
	VALIDATE(CJonah, field_350, 0x350);
	VALIDATE(CJonah, field_354, 0x354);
}
