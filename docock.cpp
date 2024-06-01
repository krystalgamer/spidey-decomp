#include "docock.h"
#include "validate.h"
#include "trig.h"
#include "panel.h"
#include "ps2m3d.h"

// @NotOk
// globals
// also the loops starts at 338 not 334 (it offsets negatively for some reason...)
CDocOc::CDocOc(int *a2, int a3)
{
	this->field_328 = 0;
	this->field_32C = 0;
	this->field_330 = 0;

	for (int i = 0; i<30;i++)
	{
		this->field_334[i].vx = 0;
		this->field_334[i].vy = 0;
		this->field_334[i].vz = 0;
	}

	this->field_50C.vx = 0;
	this->field_50C.vy = 0;
	this->field_50C.vz = 0;

	unsigned __int16 *LinksPointer = reinterpret_cast<unsigned __int16*>(Trig_GetLinksPointer(a3));
	print_if_false(*LinksPointer == 1, "Error");
	Trig_GetPosition(&this->field_50C, LinksPointer[1]);

	this->field_4A8 = reinterpret_cast<int>(
			this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2))));

	this->InitItem("docock");

	this->mFlags |= 0x480;
	this->mCBodyFlags &= 0xFFEF;
	this->field_3C = 0x549E80;

	this->field_E2 = 600;
	this->field_DC = 0;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->field_1F4 = a3;
	this->field_DE = a3;
	this->field_38 = 308;
	this->field_31C.bothFlags = 1;

	this->field_554 = 4;
	this->field_4EC = 1;
	this->field_324 = 25;
	this->field_21E = 100;

	if (*reinterpret_cast<unsigned char*>(0x0060CFC5))
	{
		this->mFlags |= 0x200;
		this->field_28 = 2048;
		this->field_2A = 2048;
		this->field_2C = 2048;
	}

	Panel_CreateHealthBar(this, 308);
	this->field_194 = 0xFFFC0000;
	this->field_198 = 0x3FFF;
}

// @Ok
void DocOck_CreateDocOck(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CDocOc(v2, v3));
}

// @Ok
void CDocOc::RenderClaws(void)
{
	M3d_Render(this->field_570);
}

// @Ok
void __inline CDocOc::PlaySingleAnim(unsigned int a2, int a3, int a4)
{
	this->field_4C4 = 0;
	this->RunAnim(a2, a3, a4);
}

// @TODO
void CDocOc::PlayIdleOrGloatAnim(void)
{}

void __inline CDocOc::Gloat(void)
{
	if(this->field_142)
	{
		this->field_31C.bothFlags = 2;
		this->dumbAssPad = 0;
		this->PlayIdleOrGloatAnim();
	}
}

void validate_CDocOc(void){
	VALIDATE_SIZE(CDocOc, 0x590);

	VALIDATE(CDocOc, field_324, 0x324);
	VALIDATE(CDocOc, field_328, 0x328);
	VALIDATE(CDocOc, field_32C, 0x32C);
	VALIDATE(CDocOc, field_330, 0x330);
	VALIDATE(CDocOc, field_334, 0x334);
	VALIDATE(CDocOc, field_4A8, 0x4A8);

	VALIDATE(CDocOc, field_4C4, 0x4C4);

	VALIDATE(CDocOc, field_4EC, 0x4EC);
	VALIDATE(CDocOc, field_50C, 0x50C);
	VALIDATE(CDocOc, field_554, 0x554);
	VALIDATE(CDocOc, field_570, 0x570);
}
