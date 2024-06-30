#include "venom.h"
#include "validate.h"
#include "mem.h"

//Revisit
void __inline CVenom::Lookaround(void)
{

	int v2; // r0

  v2 = this->dumbAssPad;
  if ( v2 == 1 )
  {
    if ( this->field_142 )
    {
      this->field_31C.bothFlags = 32;
      this->dumbAssPad = 0;
    }
  }
  else if ( v2 >= 1 || v2 < 0 )
  {
    print_if_false(0, "Unknown substate");
  }
  else
  {
    this->field_218 &= 0xFFFFFFF8;
    this->mAccellorVel.vz = 0;
    this->mAccellorVel.vy = 0;
    this->mAccellorVel.vx = 0;
    this->RunAnim(8, 0, -1);
    ++this->dumbAssPad;
  }

}

// @TODO
CVenom::CVenom(int*, int)
{}

// @Ok
void Venom_CreateVenom(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CVenom(v2, v3));
}

// @Ok
void CVenom::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @TODO
void CVenom::DoPhysics(void)
{}

// @Ok
void CVenomWrap::Die(void)
{
	CBit::Die();
}

// @TODO
__inline int* CVenom::KillCommandBlock(int*)
{
	return (int*)0x03062024;
}

// @NotOk
// Revisit
void CVenom::KillAllCommandBlocks(void)
{
	for (int* cur = reinterpret_cast<int*>(this->field_35C); cur; cur = this->KillCommandBlock(cur));
	this->field_35C = 0;
}

// @Ok
unsigned char CVenom::TugImpulse(CVector *a2, CVector *a3, CVector *a4)
{
	if (a4)
		Mem_Delete(a4);
	this->field_218 |= 0x200;

	return 0;
}

// @Ok
CVenomElectrified::CVenomElectrified(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper sent to CVenomWrap");
	print_if_false((pSuper->field_38 == 313), "Non venom sent to CVenomElectrified");

	this->field_3C = Mem_MakeHandle(pSuper);
}

void validate_CVenom(void){
	VALIDATE_SIZE(CVenom, 0x468);

	VALIDATE(CVenom, field_33C, 0x33C);
	VALIDATE(CVenom, field_33D, 0x33D);
	VALIDATE(CVenom, field_358, 0x358);
	VALIDATE(CVenom, field_35C, 0x35C);

	VALIDATE(CVenom, field_37C, 0x37C);
	VALIDATE(CVenom, field_380, 0x380);
	VALIDATE(CVenom, field_384, 0x384);

	VALIDATE(CVenom, field_39C, 0x39C);

	VALIDATE(CVenom, field_3A0, 0x3A0);
	VALIDATE(CVenom, field_3A4, 0x3A4);
	VALIDATE(CVenom, field_3A8, 0x3A8);

	VALIDATE(CVenom, field_3E8, 0x3E8);
	VALIDATE(CVenom, field_3EC, 0x3EC);
	VALIDATE(CVenom, field_3F0, 0x3F0);
	VALIDATE(CVenom, field_400, 0x400);
	VALIDATE(CVenom, field_404, 0x404);
	VALIDATE(CVenom, field_408, 0x408);
	VALIDATE(CVenom, field_40C, 0x40C);
	VALIDATE(CVenom, field_410, 0x410);
	VALIDATE(CVenom, field_414, 0x414);
	VALIDATE(CVenom, field_418, 0x418);
	VALIDATE(CVenom, field_41C, 0x41C);
	VALIDATE(CVenom, field_420, 0x420);

	VALIDATE(CVenom, field_430, 0x430);
	VALIDATE(CVenom, field_434, 0x434);


	VALIDATE(CVenom, field_454, 0x454);
	VALIDATE(CVenom, field_458, 0x458);
	VALIDATE(CVenom, field_45C, 0x45C);
	VALIDATE(CVenom, field_460, 0x460);
	VALIDATE(CVenom, field_464, 0x464);
}

void validate_CVenomWrap(void)
{
	VALIDATE_SIZE(CVenomWrap, 0x5C);
}

void validate_CVenomElectrified(void)
{
	VALIDATE_SIZE(CVenomElectrified, 0x48);

	VALIDATE(CVenomElectrified, field_3C, 0x3C);
}
