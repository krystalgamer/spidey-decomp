#include "scorpion.h"
#include "validate.h"
#include "ai.h"
#include "ps2lowsfx.h"
#include "utils.h"
#include "web.h"
#include "ps2redbook.h"
#include "reloc.h"
#include "spidey.h"

CPlayer* MechList;

// @Ok
i32 CScorpion::ScorpPathCheck(
		CVector* a2,
		CVector* a3,
		CVector* a4,
		i32 a5)
{
	CVector v9; // [sp+38h] [-28h] BYREF
	CVector v10; // [sp+44h] [-1Ch] BYREF

	v10 = *a2;
	v9 = *a3;

	v9.vy = this->mPos.vy + ((this->field_21E - 20) << 12);
	v10.vy = v9.vy;
	this->FindJonah();

	return this->PathCheck(&v10, &v9, a4, a5);
}

// @Ok
i32 CScorpion::PathLooksGood(CVector *pVector)
{
	if (this->ScorpPathCheck(&this->mPos, pVector, 0, 20))
		return 0;

	pVector->vy = this->mPos.vy;
	this->field_1B4[0] = *pVector;
	this->field_1F0 = 1;
	this->field_31C.bothFlags = 1;
	this->dumbAssPad = 0;
	this->field_218 |= 0x80;

	return 1;
}

// @Ok
void __inline CScorpion::PlayXA_NoRepeat(i32 a2, i32 a3, i32 a4, i32 *a5, CBody* pBody)
{
	if (!this->field_C20)
	{
		i32 v11 = a3 + Rnd(a4);
		if (v11 == *a5 && ++v11 >= a3 + a4)
		{
			v11 = a3;
		}

		*a5 = v11;

		if (Redbook_XAPlayPos(a2, v11, &pBody->mPos, 0))
				pBody->AttachXA(a2, v11);
	}
}

// @NotOk
// case 1 is fucked up
void CScorpion::GetTrapped(void)
{
	i32 **v6;
	i32 v7;
	i32 v8;
	switch (this->dumbAssPad)
	{
		case 0:
			new CAIProc_StateSwitchSendMessage(this, 14);

			this->CycleAnim(12, 1);
			this->field_BD4 = 0;
			this->field_BD8 = 0;
			this->field_1F8 = 5;
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
				this->CycleAnim(12, 1);

			this->field_324 |= 2;
			if (this->field_BD8 > 0)
				this->field_BD8 -= 1;

			if (--this->field_1F8 <= 0)
			{
				v6 = reinterpret_cast<i32**>(Mem_RecoverPointer(&this->field_104));
				if (!v6 || (v7 = this->field_BD4, v8 = v6[17][15], v7 == v8))
				{
					this->dumbAssPad++;
				}
				else
				{
					this->field_BD8 += (8000 * (v8 - v7)) >> 12;
					this->field_1F8 = 5;
					this->field_BD4 = v6[17][15];
				}
			}

			break;
		case 2:
			this->field_324 |= 2;
			this->RunTimer(&this->field_BD8);
			if (this->field_BD8 <= 0)
			{
				this->RunAnim(0xC,
						this->field_12A == 12 ? this->field_128 : 0,
						-1);
				this->dumbAssPad++;
			}
			break;
		case 3:
			this->field_324 |= 2;
			if (this->field_142)
			{
				this->RunAnim(0xD, 0, -1);
				this->dumbAssPad++;
			}
			break;
		case 4:
			if (this->field_128 >= 10)
			{
				if (this->field_104.field_0)
				{
					CTrapWebEffect* pWeb = reinterpret_cast<CTrapWebEffect*>(
							Mem_RecoverPointer(&this->field_104));
					if (pWeb)
					{
						SFX_PlayPos(0x80C6, &this->mPos, 0);
						pWeb->Burst();
					}
					
					this->field_104.field_0 = 0;
				}
				this->field_31C.bothFlags = 12;
				this->dumbAssPad++;
			}
			else
			{
				this->field_324 |= 2;
			}
			break;
		case 5:
			if (this->field_142)
			{
				this->field_31C.bothFlags = 2;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
void __inline CScorpion::NextRoom(void)
{
	this->field_218 &= 0xFFFFFFE7;
}

// @Ok
__inline void* CScorpion::GetCurrentTarget(void)
{
	if (!this->field_BF8)
	{
		return NULL;
	}

	return Mem_RecoverPointer(&this->hCurrentTarget);
}

// @Ok
void Scorpion_GetCurrentTarget(unsigned int* pScorp, unsigned int* pTarget)
{
	*pTarget = reinterpret_cast<unsigned int>((*reinterpret_cast<CScorpion**>(pScorp))->GetCurrentTarget());
}

CBaddy* BaddyList;

// @NotOk
// globals
INLINE CSuper* CScorpion::FindJonah(void)
{
	if (this->field_BEC)
		return field_BEC;


	for (CSuper* cur = BaddyList; cur; cur = reinterpret_cast<CSuper*>(cur->field_20))
	{
		if (cur->field_38 == 316)
		{
			this->field_BEC = cur;
			return this->field_BEC;
		}
	}

	return NULL;
}

// @Ok
i32 __inline CScorpion::SetJonahHandle(SHandle* pHandle)
{
	print_if_false(&pHandle != 0, "what in the name of Dog?");
	CSuper *pJonah = this->FindJonah();
	if (!pJonah)
		return 0;

	*pHandle = Mem_MakeHandle(pJonah);
	return 1;
}


// @Ok
void CScorpion::DoIntroSequence(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			if (this->SetJonahHandle(&this->hCurrentTarget))
			{
				new CAIProc_LookAt(
						this,
						reinterpret_cast<CBody*>(this->hCurrentTarget.field_0),
						0,
						2,
						50,
						170);
				this->dumbAssPad++;
			}
			else
			{
				this->field_31C.bothFlags = 2;
				this->dumbAssPad = 0;
			}
			break;
		case 1:
			if (this->field_288 & 2)
			{
				this->field_1F8 = 600;
				this->field_288 &= 0xFFFFFFFD;
				this->dumbAssPad = 2;
			}
			break;
		case 2:
			this->field_1F8 -= this->field_80;
			if (this->field_1F8 <= 0)
			{
				this->field_31C.bothFlags = 2;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
INLINE u32 CScorpion::WhatShouldIDo(void)
{
	CSuper *pJonah = this->FindJonah();
	if (pJonah)
	{
		u32 res;
		Reloc_CallUserFunction("jonah", 1, reinterpret_cast<u32*>(&pJonah), &res);
		return res;
	}

	return 0;
}


// @Ok
INLINE void CScorpion::TargetPlayer(i32 a2)
{
	this->field_C10 = a2;
	this->field_BF8 = 2;
	this->hCurrentTarget = Mem_MakeHandle(MechList);
}

// @MEDIUMTODO
i32 CScorpion::GetEnvironmentalObjectTarget(void)
{
	return 0x13072024;
}

// @Ok
// @Test
void CScorpion::DetermineTarget(void)
{
	if (this->field_C10)
	{
		this->field_BF8 = 2;
		this->hCurrentTarget = Mem_MakeHandle(MechList);
	}
	else
	{
		if (!this->hCurrentTarget.field_0 || !Mem_RecoverPointer(&this->hCurrentTarget))
		{
			this->field_BF8 = 2;
			this->hCurrentTarget = Mem_MakeHandle(MechList);
		}

		switch (this->WhatShouldIDo())
		{
			case 1:
				if (this->SetJonahHandle(&this->hCurrentTarget))
				{
					this->field_BF8 = 1;
					this->field_31C.bothFlags = 2;
					this->dumbAssPad = 0;
				}
				break;
			case 2:
				if (this->field_C14 || !this->GetEnvironmentalObjectTarget())
				{
					if (this->field_31C.bothFlags != 3 || this->field_BF8 != 2)
					{
						this->hCurrentTarget = Mem_MakeHandle(MechList);
						this->field_BF8 = 2;
						this->field_31C.bothFlags = 3;
						this->dumbAssPad = 0;
					}
				}
				else
				{
					this->field_31C.bothFlags = 16;
					this->dumbAssPad = 0;
				}
				break;
			default:
				this->TargetPlayer(this->field_C10 <= 180 ? 180 : this->field_C10);

				if (this->field_31C.bothFlags != 3)
				{
					this->field_31C.bothFlags = 3;
					this->dumbAssPad = 0;
				}
				break;
		}
	}
}

// @Ok
void CScorpion::Gloat(void)
{
	switch ( this->dumbAssPad )
	{
		case 0:
			if ( (this->field_218 & 0x1000) == 0 )
				SFX_PlayPos(0x80A7, &this->mPos, 0);
			++this->dumbAssPad;
		case 1:
			this->Neutralize();
			this->field_1F8 = 0;
			this->RunAnim(0xE, 0, -1);
			++this->dumbAssPad;
			break;
		case 2:
			if ( this->field_142 )
				this->CycleAnim(this->field_298.Bytes[0], 1);
			this->RunTimer(&this->field_1F8);
			if ( !this->field_1F8 )
			{
				this->RunAnim(this->field_12A, this->field_128, -1);
				++this->dumbAssPad;
			}
			break;
		case 3:
			if ( this->field_142 )
			{
				if ( this->field_C18 )
				{
					this->RunAnim(this->field_298.Bytes[0], 0, -1);
				}
				else
				{
					this->DetermineTarget();
					this->field_31C.bothFlags = 2;
					this->dumbAssPad = 0;
				}
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}


// @NotOk
// globals
void CScorpion::TakeHit(void)
{
	switch( this->dumbAssPad)
	{
		case 0:
			this->field_310 = 0;
			new CAIProc_LookAt(
					this,
					MechList,
					0,
					2,
					80,
					200);

			this->field_230 = Utils_GetValueFromDifficultyLevel(40, 30, 21, 21);
			this->dumbAssPad = 4;

			if (this->field_12A != 10)
				this->RunAnim(0xA, 0, -1);

			break;
		case 4:
			this->RunTimer(&this->field_230);
			if (this->field_230)
			{
				this->field_31C.bothFlags = 2;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
CConstantLaser::CConstantLaser(i32 a2)
{
	this->field_60 = a2;
	this->SetRGB(128, 128, 0, 255, 255, 128, 128, 128, 0, 255, 255, 255);
}

// @Ok
INLINE void CConstantLaser::SetRGB(
		u8 a2,
		u8 a3,
		u8 a4,
		u8 a5,
		u8 a6,
		u8 a7,
		u8 a8,
		u8 a9,
		u8 a10,
		u8 a11,
		u8 a12,
		u8 a13)
{
	this->field_4C[0] = a2;
	this->field_4C[1] = a3;
	this->field_4C[2] = a4;
	this->field_4C[3] = a5;
	this->field_4C[4] = a6;
	this->field_4C[5] = a7;
	this->field_4C[6] = a8;
	this->field_4C[7] = a9;
	this->field_4C[8] = a10;
	this->field_4C[9] = a11;
	this->field_4C[10] = a12;
	this->field_4C[11] = a13;
}


void validate_CScorpion(void){
	VALIDATE_SIZE(CScorpion, 0xC28);

	VALIDATE(CScorpion, field_324, 0x324);

	VALIDATE(CScorpion, field_BD4, 0xBD4);
	VALIDATE(CScorpion, field_BD8, 0xBD8);

	VALIDATE(CScorpion, field_BE8, 0xBE8);
	VALIDATE(CScorpion, field_BEC, 0xBEC);

	VALIDATE(CScorpion, hCurrentTarget, 0xBF0);
	VALIDATE(CScorpion, field_BF8, 0xBF8);

	VALIDATE(CScorpion, field_C10, 0xC10);
	VALIDATE(CScorpion, field_C14, 0xC14);
	VALIDATE(CScorpion, field_C18, 0xC18);
	VALIDATE(CScorpion, field_C20, 0xC20);
}

void validate_CConstantLaser(void)
{
	VALIDATE_SIZE(CConstantLaser, 0x64);

	VALIDATE(CConstantLaser, field_4C, 0x4C);
	VALIDATE(CConstantLaser, field_60, 0x60);
}
