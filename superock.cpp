#include "superock.h"
#include "validate.h"

// @NotOk
// globals
CSuperDocOck::CSuperDocOck(int *a2, int a3)
{
	this->field_32C = 0;
	this->field_330 = 0;
	this->field_334 = 0;

	this->field_344 = reinterpret_cast<int>(
			this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2))));

	this->InitItem("superock");
	this->mFlags |= 0x480;
	this->mCBodyFlags &= 0xFFEF;
	this->field_3C = 0x557928;

	this->field_E2 = 500;
	this->field_DC = 0;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->field_38 = 309;
	this->field_1F4 = a3;
	this->field_DE = a3;

	this->field_36C = 1024;
	this->field_374 = 0x10000;
	this->field_370 = 0x10000;
	this->field_3D8 = 4;
	this->field_31C.bothFlags = 1;
	this->field_21E = 100;

	*reinterpret_cast<int*>(0x54E8D4) = 4096;
	*reinterpret_cast<int*>(0x60F774) = 0xFFFFFF;
	*reinterpret_cast<unsigned char*>(0x60F772) = 1;
	*reinterpret_cast<int*>(0x60F778) = *gTimerRelated;

	this->field_194 = 0xFFFE0000;
	this->field_198 = 0x1FFF;
}

// @Ok
void SuperDocOck_CreateSuperDocOck(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CSuperDocOck(v2, v3));
}

// @Ok
void CSuperDocOck::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @TODO
void CSuperDocOck::DoPhysics(void)
{}

void validate_CSuperDocOck(void){
	VALIDATE_SIZE(CSuperDocOck, 0x414);

	VALIDATE(CSuperDocOck, field_32C, 0x32C);
	VALIDATE(CSuperDocOck, field_330, 0x330);
	VALIDATE(CSuperDocOck, field_334, 0x334);

	VALIDATE(CSuperDocOck, field_344, 0x344);
	VALIDATE(CSuperDocOck, field_36C, 0x36C);
	VALIDATE(CSuperDocOck, field_370, 0x370);
	VALIDATE(CSuperDocOck, field_374, 0x374);
	VALIDATE(CSuperDocOck, field_3D8, 0x3D8);
}
