#include "hostage.h"
#include "validate.h"
#include "utils.h"
#include "ps2redbook.h"
#include "mem.h"
#include "ai.h"
#include "message.h"

extern i32 DifficultyLevel; 

// @Ok
void CHostage::BegMotherfucker(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();

			if (Mem_RecoverPointer(&this->field_32C))
			{
				new CAIProc_LookAt(
						this,
						reinterpret_cast<CBody*>(this->field_32C.field_0),
						0,
						0,
						80,
						200);
			}

			if (DifficultyLevel == 2)
			{
				this->field_230 = 100;
			}
			else if (DifficultyLevel == 3)
			{
				this->field_230 = 65;
			}

			this->CycleAnim((this->field_38 == 315) + 5, 1);
			this->dumbAssPad++;
			this->HostageXAPlay(7, Rnd(3) + 9, 50);

			break;
		case 1:
			if (--this->field_230 <= 0)
			{
				this->field_324 = 2;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

void __inline CHostage::HostageXAPlay(i32 a2, i32 a3, i32 a4)
{
	if (Redbook_XAPlayPos(a2, a3, &this->mPos, a4))
		this->AttachXA(a2, a3);
}

extern CBody* MechList[1];

// @Ok
void CHostage::TellSomebodyToShootMe(void)
{
	if (DifficultyLevel != 1 && DifficultyLevel)
	{
		CBaddy *pBaddy = this->GetClosest(304, 0);

		if (pBaddy)
		{
			new CMessage(this, pBaddy, 13, 0);
		}
		else
		{
			new CMessage(this, this, 1, 0);
		}
	}
}

INLINE void CHostage::CheckIfFreed(void)
{
	if (Utils_CrapDist(MechList[0]->mPos, this->mPos) < 0xC8 || this->field_44 & 1)
	{
		if (DifficultyLevel == 1 || DifficultyLevel == 0)
			this->field_218 |= 1;
		this->Baddy_SendSignal();
		this->field_324 = 4;
		this->dumbAssPad = 0;
		this->TellSomebodyToShootMe();
	}
}

// @Ok
void CHostage::WaitForPlayer(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			if (--this->field_230 <= 0)
			{
				this->RunAnim(1, 0, -1);
				this->dumbAssPad++;
				this->field_230 = Rnd(120) + 120;
			}

			this->CheckIfFreed();
			break;
		case 1:

			if (this->field_142)
			{
				this->CycleAnim(0, 1);
				this->dumbAssPad  = 0;
			}

			this->CheckIfFreed();
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
void __inline CHostage::DisappearBitch(void)
{
	switch (this->dumbAssPad)
	{
		case 2:
			if (this->Die(2))
			{
				this->Die(3);
				this->dumbAssPad++;
			}
			else
			{
				this->SetHeight(0, 100, 600);
			}
			break;
		case 0:
			this->Neutralize();
			this->dumbAssPad++;
		case 1:
			this->mCBodyFlags &= 0xFFEF;
			this->field_2A8 |= 0x5000;
			this->field_DC = 0;
			this->Die(1);
			this->dumbAssPad++;
			break;
		case 3:
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
void __inline CHostage::GetUp(void)
{
	switch(this->dumbAssPad)
	{
		case 0:
			this->RunAnim(2, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
			{
				if (this->GetNextWaypoint())
				{
					this->field_324 = 2;
					this->dumbAssPad = 0;
				}
				else
				{
					this->field_324 = 5;
					this->dumbAssPad = 1;
				}
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

CHostage::CHostage(int* a2, int a3)
{
	i16 *afterAngles = this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));

	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));
	this->ShadowOn();

	int v6 = this->field_2A8 | 1;

	this->field_D0 = 48;
	this->field_1F4 = a3;
	this->field_DE = a3;
	this->field_DC = 128;
	this->field_230 = 0;
	this->field_216 = 32;

	this->field_D8 = 64;
	this->field_324 = 0;

	this->field_2A8 = v6;

	unsigned char * ptr = reinterpret_cast<unsigned char*>(0x551FF0);
	this->field_294.Bytes[0] = ptr[0];
	this->field_294.Bytes[1] = ptr[1];
	this->field_294.Bytes[2] = ptr[2];
	this->field_294.Bytes[3] = ptr[3];

	this->field_298.Bytes[0] = ptr[4];
	this->field_298.Bytes[1] = ptr[5];
	this->field_298.Bytes[2] = ptr[6];
	this->field_298.Bytes[3] = ptr[7];

	this->mCBodyFlags &= 0xFFEF;
	this->ParseScript(reinterpret_cast<unsigned __int16*>(afterAngles));
}

// @Ok
void Hostage_CreateHostage(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CHostage(v2, v3));
}

void validate_CHostage(void){
	VALIDATE_SIZE(CHostage, 0x334);


	VALIDATE(CHostage, field_324, 0x324);
	VALIDATE(CHostage, field_328, 0x328);
	VALIDATE(CHostage, field_32C, 0x32C);
}
