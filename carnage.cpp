#include "carnage.h"
#include "validate.h"
#include "trig.h"
#include "panel.h"


// @NotOk
// globals
CCarnage::CCarnage(int* a2, int a3)
{
	this->field_334 = 0;
	this->field_338 = 0;
	this->field_33C = 0;
	this->field_370 = 0;
	this->field_374 = 0;
	this->field_378 = 0;


	this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));
	this->InitItem("carnage");
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->mFlags |= 0x480;
	this->field_3C = 0x548980;
	this->field_194 = 278528;

	this->field_38 = 314;
	this->field_31C.bothFlags = 1;

	this->field_E2 = 3000;
	this->field_DC = 160;
	this->field_21E = 100;
	this->field_35C = 1;
	this->field_354 = 241;

	unsigned __int16 *LinksPointer = reinterpret_cast<unsigned __int16*>(Trig_GetLinksPointer(a3));
	print_if_false(*LinksPointer == 1, "Error");
	this->field_358 = LinksPointer[1];
	Panel_CreateHealthBar(this, 314);
	CreateSonicBubbleVertexWobbler();
}

// @TODO
void CreateSonicBubbleVertexWobbler(void)
{}

// @Ok
void Carnage_Create_Carnage(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CCarnage(v2, v3));
}

void validate_CCarnage(void){
	VALIDATE_SIZE(CCarnage, 0x37C);

	VALIDATE(CCarnage, field_334, 0x334);
	VALIDATE(CCarnage, field_338, 0x338);
	VALIDATE(CCarnage, field_33C, 0x33C);
	VALIDATE(CCarnage, field_354, 0x354);
	VALIDATE(CCarnage, field_358, 0x358);
	VALIDATE(CCarnage, field_35C, 0x35C);
	VALIDATE(CCarnage, field_36C, 0x36C);
	VALIDATE(CCarnage, field_370, 0x370);
	VALIDATE(CCarnage, field_374, 0x374);
	VALIDATE(CCarnage, field_378, 0x378);
}
