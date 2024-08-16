#include "lizman.h"
#include "validate.h"
#include "message.h"
#include "ps2funcs.h"
#include "mem.h"
#include "ai.h"
#include "ps2lowsfx.h"
#include "utils.h"
#include "trig.h"
#include "ps2funcs.h"
#include "spidey.h"

// @MEDIUMTODO
void CLizMan::CalculateJumpPositionArray(CVector*)
{}

// @BIGTODO
i32 CLizMan::ScanNearbyNodesForJumpTarget(void)
{
	return 0x17062024;
}

extern CPlayer* MechList;
static u16 word_5FBC0C;

// @Ok
void CLizMan::Guard(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->field_1F8 = 0;
			this->Neutralize();

			if (gTimerRelated - this->field_374 < 0x12C)
			{
				new CAIProc_LookAt(
						this,
						MechList,
						0,
						0,
						128,
						200);
			}

			this->dumbAssPad++;
			break;
		case 1:

			if (word_5FBC0C != 0xFFFF && this->field_12A != 5)
			{
				this->PlaySingleAnim(5, 0, -1);
			}

			this->field_1F8 += this->field_80;
			if (this->field_1F8 > 120)
			{
				this->field_1F8 = 0;
				i32 target = this->ScanNearbyNodesForJumpTarget();
				if (target)
				{
					CVector v6;
					v6.vx = 0;
					v6.vy = 0;
					v6.vz = 0;
					this->field_1F0 = 0;

					SFX_PlayPos((Rnd(2) + 134) | 0x80, &this->mPos, 0);
					Trig_GetPosition(&v6, target);
					this->field_1F4 = target;

					this->CalculateJumpPositionArray(&v6);
					this->field_31C.bothFlags = 23;
					this->dumbAssPad = 0;
				}
			}

			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
void CLizMan::Acknowledge(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->field_340 = 0;
			this->RunAnim(0, 0, -1);

			if (Mem_RecoverPointer(&this->hLizHandle))
			{
				new CAIProc_LookAt(
						this,
						reinterpret_cast<CBody*>(this->hLizHandle.field_0),
						0,
						2,
						70,
						200);
			}

			this->dumbAssPad++;
			break;
		case 1:

			if(this->field_142)
			{
				this->field_31C.bothFlags = 25;
				this->dumbAssPad = 0;
			}
			
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
void CLizMan::SwitchFromEulerToMatrix(void)
{
	if ((this->outlineRelated & 1) == 0)
	{
		this->outlineRelated |= 1;
		M3dMaths_RotMatrixYXZ(
				reinterpret_cast<SVECTOR*>(&this->mAngles),
				&this->field_164);
	}
}

// @BIGTODO
void CLizMan::RunToWhereActionIs(CVector*)
{}

// @Ok
void __inline CLizMan::HelpOutBuddy(CMessage* pMessage)
{
	if (!this->field_390)
	{
		if (this->field_31C.bothFlags == 2 || this->field_31C.bothFlags == 1)
		{
			CItem *pItem = reinterpret_cast<CItem*>(
					Mem_RecoverPointer(&pMessage->mHandle));

			if (pItem)
				this->RunToWhereActionIs(&pItem->mPos);
		}
	}

}

// @Ok
void __inline CLizMan::PlaySingleAnim(__int16 a1, int a2, int a3)
{
	this->field_340 = 0;
	this->RunAnim(a1, a2, a3);
}

// @Ok
void __inline CLizMan::StandStill(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->PlaySingleAnim(19, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @Ok
void CLizMan::SwitchFromMatrixToEuler(void)
{
	if ( this->outlineRelated & 1)
	{
		this->outlineRelated &= 0xFFFFFFFE;
		this->mAngles.vz = 0;
		this->mAngles.vx = 0;
		this->mAngles.vy = (3072 - ratan2(-this->field_164.m[2][2], -this->field_164.m[0][2])) & 0xFFF;
	}
}

// @Ok
void CLizMan::StopClimbing(void)
{
	this->SwitchFromMatrixToEuler();
	this->field_390 = 0;
}

// @MEDIUMTODO
void CLizMan::FlyAcrossRoom(void)
{
	switch(this->dumbAssPad)
	{
		case 3:
			if (this->IsSafeToSwitchToFollowWaypoints())
			{
				this->field_31C.bothFlags = 2;
			}
			else
			{
				this->field_31C.bothFlags = 1;
			}
			this->dumbAssPad = 0;

	}
}

// @Ok
int __inline CLizMan::IsSafeToSwitchToFollowWaypoints(void)
{
	if (this->field_1F0 || this->field_1F4 > 0)
		return 1;
	return 0;
}

static CLizMan* gGlobalLizMan;
static unsigned char gLizManAttackFlag;

// @NotOk
// globals
void __inline CLizMan::ClearAttackFlags(void)
{
	if (gGlobalLizMan == this)
	{
		gGlobalLizMan = NULL;
	}
	else if ((this->field_39C & 2))
	{
		gLizManAttackFlag &= ~this->field_39D;
	}

	this->field_39C = 0;
	this->field_39D = 0;
}

void validate_CLizMan(void){
	VALIDATE_SIZE(CLizMan, 0x3B8);


	VALIDATE(CLizMan, field_328, 0x328);
	VALIDATE(CLizMan, field_32C, 0x32C);
	VALIDATE(CLizMan, field_338, 0x338);
	VALIDATE(CLizMan, field_340, 0x340);

	VALIDATE(CLizMan, hLizHandle, 0x36C);

	VALIDATE(CLizMan, field_374, 0x374);
	VALIDATE(CLizMan, field_390, 0x390);
	VALIDATE(CLizMan, field_398, 0x398);

	VALIDATE(CLizMan, field_39C, 0x39C);
	VALIDATE(CLizMan, field_39D, 0x39D);

	VALIDATE(CLizMan, field_3AC, 0x3AC);
}
