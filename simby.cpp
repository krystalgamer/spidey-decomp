#include "simby.h"
#include "validate.h"
#include "trig.h"
#include "utils.h"


// @Ok
void __inline CSimby::SetAlertModeTimer(int timer)
{
	if (this->field_348 < timer)
		this->field_348 = timer;
}

// @TODO
CSimby::CSimby(int* a2, int a3)
{
}

// @NotOk
// Globals
CSimby::CSimby(void)
{
	this->field_350 = 0;
	this->field_354 = 0;
	this->field_358 = 0;
	this->field_35C = 0;
	this->field_360 = 0;
	this->field_364 = 0;

	this->field_368.vx = 0;
	this->field_368.vy = 0;
	this->field_368.vz = 0;

	this->field_374 = 0;
	this->field_378 = 0;
	this->field_37C = 0;
	this->field_380 = 0;
	this->field_384 = 0;
	this->field_388 = 0;
	this->field_38C = 0;
	this->field_390 = 0;
	this->field_394 = 0;
	this->field_3DC = 0;
	this->field_3E0 = 0;
	this->field_3E4 = 0;
	this->field_3F8 = 0;
	this->field_3FC = 0;
	this->field_400 = 0;
	this->field_404 = 0;
	this->field_408 = 0;
	this->field_40C = 0;

	this->InitItem("symbi_02");
	this->field_38 = 324;

	int * dword_682C5C = reinterpret_cast<int*>(0x682C5C);
	if (!*dword_682C5C)
		MakeVertexWibbler();

	*dword_682C5C = *dword_682C5C + 1;
}

// @Ok
void Simby_CreateSimby(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	if (v2)
	{
		*result = reinterpret_cast<unsigned int>(new CSimby(v2, v3));
	}
	else
	{
		*result = reinterpret_cast<unsigned int>(new CSimby());
	}
}

// @TODO
void MakeVertexWibbler(void)
{}

// @NotOk
// can't get it to match should be good enough
void CSimby::FlashUpdate(void)
{
	
#define BYTE0(x) ((x) & 0xFF)
#define BYTE1(x) (BYTE0((x >> 8)))
#define BYTE2(x) (BYTE0((x >> 16)))

	if (this->field_328)
	{
		this->mFlags |= 0x400;

		/*
		this->field_24 = ((this->field_32A + this->field_24) & 0xFF) | (((this->field_32E + (this->field_24 >> 0x10)) << 16) & 0xFF0000) | ((((this->field_24 >> 8) + this->field_32C) << 8) & 0xFF00);
		*/

		this->field_24 = BYTE0(this->field_24 + this->field_32A) | ((BYTE1(this->field_24) + this->field_32C) << 8) | ((BYTE2(this->field_24) + this->field_32E) << 16) ;

																							                            

		if (!--this->field_328)
		{

			if (this->field_330 & 0x2000000)
			{
				this->mFlags |= 0x400;
			}
			else
			{
				this->mFlags &= 0xFBFF;
			}

			this->field_24 = this->field_330;
			this->field_330 = 0;
		}
	}
}

// @Ok
void CSimbySlimeBase::ScaleUp(void)
{
	this->field_A4 = 32;
}

// @Ok
void CSimbySlimeBase::ScaleDown(void)
{
	this->field_A4 = -32;
}

// @Ok
void CSimbySlimeBase::ScaleDownAndDie(void)
{
	this->ScaleDown();
	this->field_9C = 1;
	this->mProtected = 0;
}

static int gSimbyAttackData;

// @NotOk
// global
void __inline CSimby::ClearAttackData(void)
{
	gSimbyAttackData &= ~this->field_3F0;
	this->field_3F0 = 0;
}

// @Ok
void CPunchOb::SendPulse(void)
{
	if (!this->field_328)
	{
		this->field_328 = 1;
		Trig_SendPulse(reinterpret_cast<unsigned __int16*>(Trig_GetLinksPointer(this->field_DE)));
	}
}

// @Ok
void __inline CSimby::SetUpUnitFromDirection(CVector* a2, int a3)
{
	CSVector v4;
	v4.vy = a3;
	v4.vx = 0;
	v4.vz = 0;

	Utils_GetVecFromMagDir(a2, 1, &v4);
}


// @TODO
CEmber::CEmber(const CVector*, int)
{}

// @Ok
void Simby_CreateEmber(const unsigned int* a1, unsigned int*)
{
	const CVector *vec = reinterpret_cast<const CVector*>(a1);
	new CEmber(vec, vec->vy);
}

void validate_CPunchOb(void){
	VALIDATE_SIZE(CPunchOb, 0x32C);

	VALIDATE(CPunchOb, field_328, 0x328);
}

void validate_CSimby(void){
	VALIDATE_SIZE(CSimby, 0x460);

	VALIDATE(CSimby, field_328, 0x328);
	VALIDATE(CSimby, field_32A, 0x32A);
	VALIDATE(CSimby, field_32C, 0x32C);
	VALIDATE(CSimby, field_32E, 0x32E);
	VALIDATE(CSimby, field_330, 0x330);

	VALIDATE(CSimby, field_348, 0x348);

	VALIDATE(CSimby, field_350, 0x350);
	VALIDATE(CSimby, field_354, 0x354);
	VALIDATE(CSimby, field_358, 0x358);
	VALIDATE(CSimby, field_35C, 0x35C);
	VALIDATE(CSimby, field_360, 0x360);
	VALIDATE(CSimby, field_364, 0x364);

	VALIDATE(CSimby, field_368, 0x368);

	VALIDATE(CSimby, field_374, 0x374);
	VALIDATE(CSimby, field_378, 0x378);
	VALIDATE(CSimby, field_37C, 0x37C);
	VALIDATE(CSimby, field_380, 0x380);
	VALIDATE(CSimby, field_384, 0x384);
	VALIDATE(CSimby, field_388, 0x388);
	VALIDATE(CSimby, field_38C, 0x38C);
	VALIDATE(CSimby, field_390, 0x390);
	VALIDATE(CSimby, field_394, 0x394);

	VALIDATE(CSimby, field_398, 0x398);

	VALIDATE(CSimby, field_39C, 0x39C);
	VALIDATE(CSimby, field_3DC, 0x3DC);
	VALIDATE(CSimby, field_3E0, 0x3E0);
	VALIDATE(CSimby, field_3E4, 0x3E4);

	VALIDATE(CSimby, field_3F0, 0x3F0);

	VALIDATE(CSimby, field_3F8, 0x3F8);
	VALIDATE(CSimby, field_3FC, 0x3FC);
	VALIDATE(CSimby, field_400, 0x400);
	VALIDATE(CSimby, field_404, 0x404);
	VALIDATE(CSimby, field_408, 0x408);
	VALIDATE(CSimby, field_40C, 0x40C);
}

void validate_CSimbyBase(void){
	VALIDATE_SIZE(CSimbyBase, 0x334);
}

void validate_CSimbySlimeBase(void)
{
	VALIDATE_SIZE(CSimbySlimeBase, 0x114);
	
	VALIDATE(CSimbySlimeBase, field_9C, 0x9C);
	VALIDATE(CSimbySlimeBase, field_A4, 0xA4);
}

void validate_CEmber(void)
{
	VALIDATE_SIZE(CEmber, 0x90);
}
