#include "platform.h"
#include "ps2lowsfx.h"
#include "utils.h"
#include "shatter.h"
#include "spidey.h"

#include "validate.h"

extern CBody* EnvironmentalObjectList;
extern const char* gObjFile;

// @MEDIUMTODO
void CPlatform::AI(void)
{
    printf("CPlatform::AI(void)");
}

// @Ok
// @Matching
void CPlatform::AdjustBruceHealth(void)
{
	i16 value = this->field_330;
	if (value)
	{
		if (value < 0)
		{
			MechList->IncHealth(value - 1);
		}
		else
		{
			SHitInfo v2;
			v2.field_C.vx = 0;
			v2.field_C.vy = 0;
			v2.field_C.vz = 0;

			v2.field_8 = value;
			v2.field_0 = 4;

			MechList->Hit(&v2);
		}
	}
}

// @Ok
CPlatform::CPlatform(i16 * a2,i32 a3)
{
	this->field_344.vx = 0;
	this->field_344.vy = 0;
	this->field_344.vz = 0;
	this->field_350.vx = 0;
	this->field_350.vy = 0;
	this->field_350.vz = 0;

	this->InitItem(gObjFile);
	this->AttachTo(&EnvironmentalObjectList);

	this->mFlags |= 0x111;
	this->mFlags &= 0xFFFD;
	this->field_38 = 402;

	this->field_24C = this->SquirtAngles(this->SquirtPos(a2));

	this->field_340 = -1;
	this->field_DE = a3;
	this->attributeArr[0] = 32;
	this->field_20C = 1;
}

// @MEDIUMTODO
i32 CPlatform::ExecuteCommand(u16)
{
    printf("CPlatform::ExecuteCommand(u16)");
    return 0x04082024;
}

// @Ok
// @Matching
i32 CPlatform::Hit(SHitInfo* a2)
{
	this->field_20F++;
	if (this->attributeArr[1])
	{

		if (this->field_E2 > 0)
		{
			this->field_E2 -= a2->field_8;
			if (this->field_E2 <= 0)
			{
				this->Die(0);
				SFX_PlayPos(Rnd(2) + 1, &this->mPos, 0);
				Shatter_Item(this, 0, 1);
				this->mFlags |= 1;
			}
		}
	}

	return 1;
}

// @Ok
// @Validate
INLINE void CPlatform::MoveTo(CVector* pVec)
{
	if (this->field_240 != *pVec)
	{
		this->field_240 = *pVec;
		this->field_344 = ((this->mPos - *pVec) >> 12);
		this->field_218 |= 1;
	}
}

// @Ok
// @Matching
void CPlatform::NotifyTrodUpon(CBody *,CVector const *,CSVector const *)
{
	this->field_334 = 1;
	this->field_338 = 0;
}

// @MEDIUMTODO
void CPlatform::SetVariable(u16)
{
    printf("CPlatform::SetVariable(u16)");
}

// @Ok
CPlatform::~CPlatform(void)
{
	this->DeleteFrom(&EnvironmentalObjectList);
	if (this->field_33C)
	{
		SFX_Stop(this->field_33C);
		this->field_33C = 0;
	}
}
// @Ok
void CPlatform::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @BIGTODO
void CPlatform::DoPhysics(void)
{
	printf("void CPlatform::DoPhysics(void)");
}

// @Ok
i16 CPlatform::GetVariable(u16 a2)
{
	if (a2 != (u16)0x2200)
	{
		return CBaddy::GetVariable(a2);
	}

	return this->field_338;
}

void validate_CPlatform(void){
	VALIDATE_SIZE(CPlatform, 0x35C);

	VALIDATE(CPlatform, field_330, 0x330);

	VALIDATE(CPlatform, field_334, 0x334);
	VALIDATE(CPlatform, field_338, 0x338);
	VALIDATE(CPlatform, field_33C, 0x33C);

	VALIDATE(CPlatform, field_340, 0x340);

	VALIDATE(CPlatform, field_344, 0x344);
	VALIDATE(CPlatform, field_350, 0x350);
}

