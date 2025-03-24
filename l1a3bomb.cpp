#include "l1a3bomb.h"
#include "validate.h"
#include "trig.h"
#include "spidey.h"

u32 gBombRelated;
u8 gBombDieRelatedOne;
u8 gBombDieRelatedTwo;
u32 gBombDieTimerRelated;
u32 gBombAIRelated;

extern CPlayer* MechList;
extern i32 DifficultyLevel;

// @Ok
CL1A3Bomb::~CL1A3Bomb(void)
{
	gBombDieRelatedOne = 0;
	gBombDieRelatedTwo = 0;
	gBombDieTimerRelated = gTimerRelated;
}

// @BIGTODO
void CL1A3Bomb::DoPhysics(void)
{
	printf("CL1A3Bomb::DoPhysics");
}

// @Ok
void CL1A3Bomb::AI(void)
{
	if (this->field_128 && !gBombAIRelated)
	{
		if (!this->field_129)
		{
			Trig_SendSignalToLinks(Trig_GetLinksPointer(this->mNode));
			this->field_129 = 1;
		}

		return;
	}
	else if (this->mInputFlags & 1)
	{
		this->mInputFlags &= 0xFFFE;

		if (!this->field_128)
		{
			this->field_128 = 1;
			gBombDieRelatedOne = 1;
			gBombDieRelatedTwo = 1;
			gBombAIRelated = DifficultyLevel != 3 ? 7260 : 4260;
			gBombDieTimerRelated = gTimerRelated;
		}
	}

	if (this->field_10C & 1)
		this->DoPhysics();
}

// @Ok
CL1A3Bomb::CL1A3Bomb(
		i16* a2,
		i32 a3)
	: CManipOb(a2, a3)
{
	this->field_128 = 0;
	this->field_129 = 0;

	gBombRelated = 4096;
}

// @Ok
void CL1A3Bomb::Die(void)
{
	Trig_SendPulse(Trig_GetLinksPointer(this->mNode));
	gBombDieRelatedOne = 0;
	gBombDieRelatedTwo = 0;
	gBombDieTimerRelated = gTimerRelated;
}

// @Ok
void CL1A3Bomb::Smash(void)
{
	CVector v9;
	v9.vx = 0;
	v9.vy = 0;
	v9.vz = 0;

	i32 vz = 0;

	if (MechList)
	{
		CVector v5 = (-24 * MechList->field_C6C) + (14 * MechList->field_C84);
		v9.vx = v5.vx;
		v9.vy = v5.vy;
		vz = v5.vz;
	}
	else
	{
		v9.vx = 0;
		v9.vy = -57344;
	}

	v9.vz = vz;

	this->Throw(&v9);
}

void validate_CL1A3Bomb(void)
{
	VALIDATE_SIZE(CL1A3Bomb, 0x12C);

	VALIDATE(CL1A3Bomb, field_128, 0x128);
	VALIDATE(CL1A3Bomb, field_129, 0x129);
}
