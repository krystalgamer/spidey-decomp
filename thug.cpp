#include "thug.h"
#include "validate.h"
#include "trig.h"
#include "m3dutils.h"
#include "message.h"
#include "ps2lowsfx.h"
#include "utils.h"
#include "ai.h"
#include "ps2redbook.h"
#include "spidey.h"
#include "exp.h"
#include <cmath>

EXPORT CThug* gGlobalThug;
EXPORT CThug* gThugList;

// @FIXME
EXPORT SStateFlags gThugStateFlags;

// @Ok
// @Matching
void Thug_RelocatableModuleClear(void)
{
	for (CBody* cur = BaddyList; cur; )
	{
		CBody* next = reinterpret_cast<CBody*>(cur->mNextItem);
		if (cur->mType == 304 || cur->mType == 312)
		{
			delete cur;
		}

		cur = next;
	}
}

// @Ok
// @Matching
void Thug_RelocatableModuleInit(reloc_mod* pMod)
{
	pMod->mClearFunc = Thug_RelocatableModuleClear;
	pMod->field_C[0] = Thug_CreateThug;
}

// @Ok
// @Test
void CThug::TakeHit(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->mCBodyFlags &= 0xFFEFu;
			this->field_310 = 0;
			this->ClearAttackFlags();

			if (this->field_318 == 1)
			{
				this->field_DC = 0;
				this->RunAnim(this->mType != 304 ? 19 : 14, 0, -1);
				this->dumbAssPad = 2;
			}
			else
			{
				new CAIProc_LookAt(this, MechList, 0, 0, 80, 200);
				this->RunAppropriateHitAnim();
				this->dumbAssPad = 3;
			}

			break;
		case 1:
			if ( this->field_142 )
			{
				this->field_318 = 0;
				this->field_31C.bothFlags = 28;
				this->dumbAssPad = 0;
			}
			break;
		case 2:
			if ( this->field_142 )
			{
				this->field_DC = this->mType == 304 ? 96 : 150;
				this->RunAnim(this->mType == 304 ? 15 : 20, 0, -1);
				this->dumbAssPad = 1;
			}

			break;
		case 3:
			if ( this->field_142 )
			{
				this->field_31C.bothFlags = 28;
				this->dumbAssPad = 0;
			}

			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
void CThug::BackpedalPlease(void)
{
	CVector v10;
	v10.vx = 0;
	v10.vy = 0;
	v10.vz = 0;

	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->field_1F8 = 0;
			v10 = this->mPos;

			v10.vx += 6 * ((this->mPos.vx - MechList->mPos.vx) >> 2);
			v10.vx += 6 * ((this->mPos.vz - MechList->mPos.vz) >> 2);

			if (this->AddPointToPath(&this->mPos, 0) && this->AddPointToPath(&v10, 0))
			{

				this->mVel = (this->mPos - MechList->mPos) >> 2;
				this->mVel.vy = 0;
			}

			this->RunAppropriateHitAnim();
			this->dumbAssPad++;

			break;
		case 1:
			this->DoPhysics(1);
			if (this->field_1F8 <= 0)
				this->Neutralize();
			if (this->field_142)
			{
				this->Neutralize();
				this->field_31C.bothFlags = 28;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
void CThug::LookForPlayer(void)
{
	CVector v5;
	v5.vx = 0;
	v5.vy = 0;
	v5.vz = 0;

	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->CycleAnim(this->field_298.Bytes[0], 1);
			this->dumbAssPad++;
			this->field_21D = Rnd(64);
			this->field_1F8 = 0;
			break;
		case 1:
			CVector *mPos;

			if (this->field_1F8 < 64)
				mPos = &MechList->mPos;
			else
				mPos = &this->mPos;

			this->GetWaypointNearTarget(mPos, 409600, this->field_21D, &v5);
			this->field_21D++;
			if ( !this->PathCheck(&this->mPos, &v5, 0, 55)
				&& (this->AddPointToPath(&v5, 0)
				|| this->AddPointToPath(&this->mPos, 0)
				&& this->AddPointToPath(&v5, 0)) )
			{
				this->field_31C.bothFlags = 24;
				this->dumbAssPad = 0;
			}
			else
			{
				if ( this->field_1F8++ > 128 )
				{
					this->field_330 = 0;
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

// @BIGTODO
i32 CThug::DetermineFightState(void)
{
	printf("i32 CThug::DetermineFightState(void)");
	return 0x26042024;
}

// @Ok
void CThug::Caution(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->field_310 = 0;
			this->Neutralize();

			SFX_PlayPos( (Rnd(3) + 14) | 0x8000, &this->mPos, 0);

			if ((abs(MechList->mPos.vy - this->field_29C - 0x4000) < 409600)
				&& this->PlayerIsVisible())
			{
				if (!this->ShouldIShootPlayer())
				{
					this->field_31C.bothFlags = MechList->field_57C != 0 ? 1 : 4;
					this->dumbAssPad = 0;
				}
			}
			else if (!this->DetermineFightState())
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
void CThug::CreateCombatImpactEffect(CVector* a2, i32 a3)
{
	if ( this->mType == 304 )
	{
		new CCombatImpactRing(a2, 0x12u, 18, 108, 384, 1792, 144);
		new CCombatImpactRing(a2, 0x48u, 72, 144, 192, 896, 72);
	}
	else
	{
		new CCombatImpactRing(a2, 0x6Cu, 108, 18, 384, 1792, 144);
		new CCombatImpactRing(a2, 0x90u, 144, 72, 192, 896, 72);
	}
}

// @Ok
// @Test
// two's complement a lil diff
INLINE i32 CThug::ShouldIShootPlayer(void)
{
	if ( MechList->field_57C
		|| gThugList
		|| this->DistanceToPlayer(2) >= 2000
		|| MechList->mHeldObject
		|| this->DistanceToPlayer(2) <= 650
		&& (abs(MechList->mPos.vy - this->field_29C - 0x4000) <= 409600) )
	{
		return 0;
	}

	this->Neutralize();
	gThugList = this;
	this->field_31C.bothFlags = 9;
	this->dumbAssPad = 0;
	return 1;
}

// @Ok
CThug::~CThug(void)
{
	if (this->field_3A0)
		delete this->field_3A0;
	this->field_3A0 = 0;

	if (this->field_3A4)
		Mem_Delete(this->field_3A4);
	this->field_3A4 = 0;

	if (gThugList == this)
		gThugList = 0;

	this->ClearAttackFlags();
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
}

// @SMALLTODO
i32 CThug::SetUpLaser(CGPolyLine**, CVector*, CVector*)
{
	printf("i32 CThug::SetUpLaser(CGPolyLine**, CVector*, CVector*)");
	return 0x26042024;
}

// @Ok
INLINE i32 CThug::DrawBarrelFlash(
		CVector *a2,
		CVector *a3,
		SLineInfo *a4,
		u8 a5,
		u8 a6,
		u8 a7)
{
	new CGlowFlash(a2, 5, a5, a6, a7, 32, 0, 0, 0, 0, 50, 20, 1, 20, 10, 40, 20, 10, 1);
	return this->SetUpLaser(&this->field_3A0, a2, a3);
}

// @NotOk
// Validate when used
INLINE void CThug::CheckToShoot(i32 a2, i32 a3)
{
	if ( MechList->field_57C && !gThugList && !MechList->mHeldObject)
	{
		if ( ((this->field_218 & 0x800) && a2 < this->field_37C)
				||
			 (this->field_330 && a2 < 1500 && (a3 != -1 || this->PathCheck(&this->mPos, &MechList->mPos, 0, 55))))
		{
			this->Neutralize();
			gThugList = this;
			this->ClearAttackFlags();
			this->field_31C.bothFlags = 9;
			this->dumbAssPad = 0;
		}
	}
}

// @NotOk
// Better type
void CThug::WarnOtherThugs(void)
{
	CThug *nearest = reinterpret_cast<CThug*>(this->GetClosest(304, 0));
	if ( (nearest || ((nearest = reinterpret_cast<CThug*>(this->GetClosest(312, 0))) != 0))
			&& !nearest->field_330)
	{
		new CMessage(this, nearest, 7, 0);
	}
}

// @NotOk
// validate when used
INLINE i32 CThug::AdjustPosPlaySound(i32 a2)
{
	CVector v4;
	v4.vx = 0;
	v4.vy = 0;
	v4.vz = 0;

	v4.vx = ((2400 * MechList->mPos.vx) >> 12) + ((1600 * this->mPos.vx) >> 12);
	v4.vy = ((2400 * MechList->mPos.vy) >> 12) + ((1600 * this->mPos.vy) >> 12);
	v4.vz = ((2400 * MechList->mPos.vz) >> 12) + ((1600 * this->mPos.vz) >> 12);

	return SFX_PlayPos(a2, &v4, 0);
}


// @Ok
u8 CThug::Grab(CVector* a2)
{
	if ( (this->CheckStateFlags(&gThugStateFlags, 17) & 2)
		|| !this->AddPointToPath(a2, 0) )
	{
		return 0;
	}

	this->field_31C.bothFlags = 20;


	this->dumbAssPad = 0;
	this->field_2A8 |= 0x40;
	return 1;
}

// @Ok
INLINE void CThug::SetAttacker(void)
{
	if (gGlobalThug != this)
	{
		this->ClearAttackFlags();
		if (gGlobalThug)
		{
			gGlobalThug->ClearAttackFlags();
		}

		gGlobalThug = this;
		this->field_3BC = 1;
	}
}

// @Ok
INLINE i32 CThug::SpideyAnimUppercut(void)
{
	return MechList->field_12A == 106
		|| MechList->field_12A == 113
		|| MechList->field_12A == 284;
}

// @NotOk
// validate
void CThug::PlaySounds(void)
{
	CVector v11;
	if (this->mType == 304)
	{
		switch ( this->field_12A )
		{
			case 1u:
				if ( this->field_128 == 27 || this->field_128 == 13 )
					SFX_PlayPos((Rnd(4) + 32) | 0x80, &this->mPos, 300);
					return;
				break;
			case 8u:
				if ( this->field_128 == 5 )
					SFX_PlayPos(0x801D, &this->mPos, 500);
				break;
			case 0xEu:
				if ( this->field_128 == 15 )
				{
					v11.vz = 409600;
					v11.vx = 0;
					v11.vy = 0;
					this->MakeSpriteRing(&v11);
				}
				break;
			case 0x1Au:
				if ( this->field_128 == 23 )
				{
					v11.vx = 0;
					v11.vy = 0;
					v11.vz = -122880;
					this->MakeSpriteRing(&v11);
				}
				break;
			case 0x1Cu:
				if ( this->field_128 == 4 || this->field_128 == 14)
					SFX_PlayPos((Rnd(4) + 32) | 0x80, &this->mPos, 50);
				break;
		}
	}
	else
	{
		switch ( this->field_12A )
		{
			case 5u:
				if ( this->field_128 == 1 || this->field_128 == 21 )
				{
					SFX_PlayPos((Rnd(4) + 32) | 0x80, &this->mPos, 300);
				}
				break;
			case 7u:
				if ( this->field_128 == 3 )
					SFX_PlayPos(0x801D, &this->mPos, 500);
				break;
			case 0x13u:
				if ( this->field_128 == 15 )
				{
					v11.vx = 0;
					v11.vy = 0;
					v11.vz = 204800;
					this->MakeSpriteRing(&v11);
				}
				break;
			case 0x18u:
				if ( this->field_128 == 1 || this->field_128 == 12)
					SFX_PlayPos((Rnd(4) + 32) | 0x80, &this->mPos, 50);
				break;
			case 0x1Au:
				if ( this->field_128 == 28 )
				{
					v11.vz = -204800;
					v11.vx = 0;
					v11.vy = 0;
					this->MakeSpriteRing(&v11);
				}
				break;
		}
	}

}

// @MEDIUMTODO
i32 CThug::MonitorSpitPlease(void)
{
	return 0x11062024;
}

// @Ok
void CThug::CycleOrContinueAnim(
		i32 a2,
		i32 a3,
		i32 a4,
		i32 a5)
{
	if ( this->field_12A != a2
			&& this->field_12A != a3
			&& this->field_12A != a4
			&& this->field_12A != a5 )
		this->CycleAnim(a2, 1);
}

// @Ok
void CThug::Guard(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->mCBodyFlags |= 0x10;
			if (this->mType != 304)
			{
				this->RunAnim(this->field_298.Bytes[0], 0, -1);
				this->field_1F8 = Rnd(5) + 8;
				this->dumbAssPad = 5;
				break;
			}

			this->dumbAssPad++;
			if (this->field_12A == 11)
			{
				this->field_142 = 1;
				break;
			}
			else if (this->field_12A != 10)
			{
				this->RunAnim(0xAu, 0, -1);
				break;
			}

			this->RunAnim(0xA, this->field_128, -1);
		case 1:
			if ( this->field_142 )
			{
				this->CycleOrContinueAnim(11, -1, -1, -1);
				this->field_230 = Rnd(30) + 20;
				this->dumbAssPad++;
			}
			break;
		case 2:
			if ( this->field_230-- <= 0 )
			{
				this->RunAnim(0xCu, 0, -1);
				this->dumbAssPad++;
			}
			break;
		case 3:
			if ( this->field_142 )
			{
				this->CycleAnim(3, 1);
				this->field_230 = Rnd(30) + 20;
				this->dumbAssPad++;
			}
			break;
		case 4:
			if ( this->field_230-- <= 0 )
				this->dumbAssPad = 0;
			break;
		case 5:
			if ( this->field_142 )
			{
				if ( --this->field_1F8 == 0 )
				{
					this->field_1F8 = Rnd(5) + 8;
					this->RunAnim(0x15, 0, -1);
					this->dumbAssPad++;
				}
				else
				{
					this->RunAnim(this->field_298.Bytes[0], 0, -1);
				}
			}
			break;
		case 6:
			if ( this->MonitorSpitPlease() )
				this->dumbAssPad = 5;
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
INLINE i32 CThug::CanAck(
		i32 a2,
		i32 a3,
		i32 a4,
		CThug* pThug)
{
		if (!this->field_330
			&& !this->field_33C
			&& (this->CheckStateFlags(&gThugStateFlags, 17) & 0x20))
		{
			this->mHandleTwo = Mem_MakeHandle(pThug);
			this->field_398 = a3;
			this->field_39C = a4;
			this->field_33C = a2;

			this->field_31C.bothFlags = 21;
			this->dumbAssPad = 0;

			return 1;
		}

		return 0;
}

// @Ok
void CThug::StrikeUpConversation(void)
{
	if (this->DistanceToPlayer(2) <= 1792)
	{
		CThug *pThug = reinterpret_cast<CThug*>(this->GetClosest(304, 1));

		if ((pThug || (pThug = reinterpret_cast<CThug*>(this->GetClosest(312, 1))))
				&& Utils_CrapDist(this->mPos, pThug->mPos) < 0x800)
		{

			i32 v5;
			i32 v4 = 4;
			this->field_398 = Rnd(7);
			this->field_39C = 4;
			i32 v6 = 4;
			switch ( this->field_398 )
			{
			case 0:
				this->field_398 = -3;
				v5 = 160;
				break;
			case 1:
				this->field_398 = -5;
				v4 = 6;
				v5 = 160;
				break;
			case 2:
				this->field_398 = -7;
				v4 = 8;
				v5 = 160;
				break;
			case 3:
				this->field_398 = -9;
				v4 = 10;
				v5 = 160;
				this->field_39C = 3;
				v6 = 3;
				break;
			case 4:
				this->field_398 = -11;
				v4 = 12;
				v5 = 160;
				this->field_39C = 3;
				v6 = 3;
				break;
			case 5:
				this->field_398 = -13;
				v4 = 14;
				v5 = 160;
				this->field_39C = 3;
				v6 = 3;
				break;
			case 6:
				this->field_398 = -15;
				v4 = 14;
				v5 = 160;
				this->field_39C = 3;
				break;
			default:
				print_if_false(0, "Too many ack response types.");
				v4 = 4;
				v5 = 4;
				break;
			}


			if (pThug->CanAck(v5, v4, v6, this))
			{
				this->field_33C = v5;
				this->mHandleTwo = Mem_MakeHandle(pThug);
				this->field_31C.bothFlags = 21;
				this->dumbAssPad = 0;
			}
		}
	}
}

// @Ok
void CThug::Acknowledge(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->mCBodyFlags |= 0x10;
			this->Neutralize();

			if (this->field_398 < 0)
			{
				this->RunAnim(this->mType != 304 ? 39 : 32, 0, -1);
				Redbook_XAPlayPos(this->field_39C, -this->field_398, &this->mPos, 20);
			}

			if (Mem_RecoverPointer(&this->mHandleTwo))
			{
				new CAIProc_LookAt(
						this,
						reinterpret_cast<CBody*>(this->mHandleTwo.field_0),
						0,
						2,
						70,
						200);
			}
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
				this->CycleAnim(this->field_298.Bytes[0], 1);

			if (!this->field_33C)
			{
				if (this->field_398 > 0)
				{
					Redbook_XAPlayPos(this->field_39C, this->field_398, &this->mPos, 20);
					this->RunAnim(this->mType != 304 ? 40 : 32, 0, -1);
					this->dumbAssPad++;
					return;
				}

				this->field_33C = 2000;
				this->field_31C.bothFlags = 2;
				this->dumbAssPad = 0;
			}

			break;
		case 2:
			if (this->field_142)
			{
				this->field_33C = 2000;
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
void CThug::LookConfused(void)
{
	i32 v3;

	switch ( this->dumbAssPad )
	{
		case 0:
			this->field_1F8 = Rnd(3) + 2;
			this->dumbAssPad++;
		case 1:
			this->Neutralize();
			if ( !this->field_1F8 )
			{
				this->field_330 = 0;
				this->field_31C.bothFlags = 28;
				this->dumbAssPad = 0;
			}
			else
			{
				this->dumbAssPad = 5;
				this->field_1F8 = this->field_1F8 - 1;
			}
			break;
		case 5:
			v3 = Rnd(1000) + 1000;
			if ( Rnd(2) )
				v3 = -v3;

			v3 += this->mAngles.vy;

			new CAIProc_LookAt(this, v3, 2, 80, 200);
			this->dumbAssPad++;

			break;
		case 6:
			this->RunAppropriateAnim();
			if ( (this->field_288 & 2) != 0 )
			{
				this->dumbAssPad = 1;
				this->field_288 &= 0xFFFFFFFD;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @MEDIUMTODO
i32 CThug::WallHitCheck(CVector*, CVector*, i32)
{
	return 0x13072024;
}

// @Ok
i32 CThug::GetLaunched(
		CVector* a2,
		i32 a3,
		i32 a4,
		i32 a5)
{
	i32 v10; // ebx
	CVector v13; // [esp+10h] [ebp-18h] BYREF

	v13.vy = this->mPos.vy;
	v13.vx = (a4 + 1) * a2->vx + this->mPos.vx;
	v13.vz = (a4 + 1) * a2->vz + this->mPos.vz;

	v10 = this->WallHitCheck(&v13, a2, a4);

	if ( v10 == 3 )
		return 0;

	this->Neutralize();
	this->mVel = *a2;
	this->mVel.vy = 0;

	if ( !a3 || v10 == 2 )
	{
		new CAIProc_LookAt(this, 0, &v13, 0, 80, 200);
	}

	return v10;
}

// @Ok
u8 CThug::TugImpulse(CVector* a2, CVector* a3, CVector* a4)
{
	this->field_2A8 &= 0xFFFFFFF7;
	if (a4)
	{
		this->field_31C.bothFlags = 16;
		this->dumbAssPad = 0;
		if (this->field_3A4)
			Mem_Delete(reinterpret_cast<void*>(this->field_3A4));

		this->field_3A4 = a4;
		return 1;
	}

	i32 Launched = this->GetLaunched(a3, 0, 80, 0);
	if (!Launched)
	{
		return 0;
	}

	if (this->field_E2 <= 50)
	{
		if (Launched == 1)
		{
			this->field_2A8 |= 0x10;
		}
		else
		{
			this->field_2A8 &= ~0x10;
		}
	}
	this->field_218 |= 0x80000;
	SFX_PlayPos(0x800F, &this->mPos, 0);
	this->field_31C.bothFlags = 14;
	this->dumbAssPad = 0;
	return 1;
}

// @Ok
void CThug::CheckFallBack(void)
{
	CVector v6;
	CVector a3;

	a3.vx = 0;
	a3.vy = 0;
	a3.vz = 0;

	v6.vz = ((this->field_2A8 & 0x10) ? -75 : 75) << 12;
	v6.vy = 0;
	v6.vx = 0;

	Utils_RotateY(&a3, &v6, this->mAngles.vy);

	if ( this->PathCheck(&this->mPos, &(this->mPos + a3), 0, 55) == 2 )
	{
		new CAIProc_RotY(this, 2047, 4, 0);
	}
}

// @Ok
void CThug::GetReadyToShootHostage(CMessage *pMessage)
{
	CItem *pItem = reinterpret_cast<CItem*>(Mem_RecoverPointer(&pMessage->mHandle));
	if ( pItem )
	{
		if ( Utils_LineOfSight(&this->mPos, &pItem->mPos, 0, 0) )
		{
			this->mHandle = pMessage->mHandle;

			this->field_31C.bothFlags = 8;
			this->dumbAssPad = 0;

			this->Neutralize();
			new CAIProc_StateSwitchSendMessage(this, 16);
		}
		else
		{
			new CMessage(this, reinterpret_cast<CBaddy*>(pMessage->mHandle.field_0), 1, 0);
		}

		pMessage->field_10 |= 1;
	}
}

// @Ok
// @Test
void CThug::SetParamByIndex(i32 Index, i32 Param)
{
	switch ( Index )
	{
		case 1:
			this->field_374 = Param;
			break;
		case 2:
			this->field_370 = Param;
			break;
		case 3:
			this->field_378 = Param;
			break;
		case 4:
			this->field_37C = Param;
			break;
		case 5:
			this->field_380 = Param;
			break;
		case 6:
			this->field_384 = Param;
			break;
		case 7:
			this->field_388 = Param;
			break;
		case 8:
			this->field_38C = Param;
			break;
		case 9:
			this->field_1FC = Param;
			break;
		case 10:
			this->field_394 = Param;
			break;
		case 11:
			if (Param)
				this->field_218 |= 0x800;
			else
				this->field_218 &= 0xFFFFF7FF;
			break;
		case 12:
			this->field_218 |= 0x8000;
			break;
		default:
			print_if_false(0, "Unknown index in C_SET_PARAMETER_BY_INDEX"); 
			break;
	}
}

// @Ok
void CThug::SetHitDirectionFlag(CVector* pVector)
{
	CSVector v4;
	v4.vx = 0;
	v4.vy = 0;
	v4.vz = 0;

	Utils_CalcAim(&v4, &(this->mPos + (*pVector * 300)), &this->mPos);

	i32 v3 = v4.vy - this->mAngles.vy;
	if (v3 < -2048)
	{
		v3 += 4096;
	}
	else
	{
		if (v3 > 2048)
			v3 -= 4096;
	}

	if (v3 < -455)
	{
		this->field_218 |= 0x20000;
	}
	else
	{
		if (v3 > 455)
			this->field_218 |= 0x10000;
	}
}

// @Ok
CThug::CThug(i16 *a2, i32 a3)
{
	i16 *v5 = this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));

	this->field_3B8 = Trig_GetLevelId();

	this->ShadowOn();
	this->field_D0 = 50;
	this->field_3B0 = gAttackRelated;
	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));

	this->field_1F4 = a3;
	this->field_DE = a3;

	this->field_230 = 0;
	this->field_216 = 32;
	this->field_2A8 |= 1;


	this->field_DC = this->mType != 304 ? 150 : 96;
	this->field_D8 = 64;
	this->field_380 = this->mType != 304 ? 400 : 300;
	this->field_31C.bothFlags = 0;


	this->field_370 = 3500;
	this->field_374 = 400;
	this->field_378 = 2047;
	this->field_37C = 100;
	this->field_384 = 1500;
	this->field_388 = 10;
	this->field_38C = 10;

	this->field_1FC = 10;
	this->field_394 = 2000;
	this->ParseScript(reinterpret_cast<u16*>(v5));
	this->field_212 = 60;
}

// @Ok
void Thug_CreateThug(const u32 *stack, u32 *result)
{
	i16* v2 = reinterpret_cast<i16*>(*stack);
	i32 v3 = static_cast<i32>(stack[1]);

	*result = reinterpret_cast<u32>(new CThug(v2, v3));
}

// @Ok
void __inline CThugPing::SetPosition(void)
{
	CSuper* v2 = reinterpret_cast<CSuper*>(Mem_RecoverPointer(&this->field_70));

	if (!v2)
		this->Die();
	else
		M3dUtils_GetDynamicHookPosition(
				reinterpret_cast<VECTOR*>(&this->mPos),
				v2,
				&this->field_78);
}

// @Ok
void CThugPing::Move(void)
{
	this->SetPosition();
	Bit_ReduceRGB(&this->mCodeBGR, 7);

	if ((this->mCodeBGR & 0xFFFFFF) == 0)
		this->Die();
}

static unsigned char gAttackFlagRelated;

// @Ok
void CThug::ClearAttackFlags(void)
{
	if ( gGlobalThug == this )
	{
		gGlobalThug = 0;
	}
	else if (this->field_3BC & 2)
	{
		gAttackFlagRelated &= ~this->field_3BD;
	}

	this->field_3BC = 0;
	this->field_3BD = 0;
}

EXPORT i32 gThugTypeRelatedFirstFirst[2] = { 0x0D0D0100, 3 };

// @FIXME - add data
EXPORT u8 gThugTypeRelatedFirstThird[1];

EXPORT i32 gThugTypeRelatedSecondFirst[2] = { 0x6040504, 0 };

// @FIXME - add data
EXPORT u8 gThugTypeRelatedSecondThird[1];

// @Ok
// @Matching
void CThug::SetThugType(int type)
{
	this->mType = type;
	switch (type)
	{
		case 304:
			this->InitItem("thug");
			this->field_21E = 100;

			this->field_294.Int = gThugTypeRelatedFirstFirst[0];
			this->field_298.Int = gThugTypeRelatedFirstFirst[1];
			M3dUtils_ReadHooksPacket(this, gThugTypeRelatedFirstThird);

			break;
		case 312:
			if (Trig_GetLevelId() == 513)
				this->InitItem("henchngt");
			else
				this->InitItem("henchman");

			this->field_21E = 100;
			this->field_294.Int = gThugTypeRelatedSecondFirst[0];
			this->field_298.Int = gThugTypeRelatedSecondFirst[1];
			M3dUtils_ReadHooksPacket(this, gThugTypeRelatedSecondThird);
			break;
		default:
			print_if_false(0, "Unknown thug type!");
	}

}

// @BIGTODO
void CThug::RunToWhereTheActionIs(CVector*)
{}

// @Ok
void CThug::HelpOutBuddy(CMessage *pMessage)
{
	if (this->field_31C.bothFlags == 2 || this->field_31C.bothFlags == 1)
	{
		CItem *pItem = reinterpret_cast<CItem*>(Mem_RecoverPointer(&pMessage->mHandle));

		if (pItem)
			this->RunToWhereTheActionIs(&pItem->mPos);
	}
}

// @Ok
INLINE void CThug::PlayHitWallSound(void)
{
	if (!this->field_1F8)
	{
		if (this->field_218 & 0x400)
		{
			SFX_PlayPos(0x802F, &this->mPos, 0);
		}
		else
		{
			SFX_PlayPos(0x802E, &this->mPos, 0);
		}
	}
}

// @Ok
INLINE void CThug::StandStill(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->CycleAnim(this->mType != 304 ? 15 : 17, 1);
			this->dumbAssPad++;

			break;
		default:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @Ok
void CThug::DieAfterFlyingAcrossRoom(void)
{
	if (this->ShouldFall(200, 0x5F000))
	{
		this->field_218 &= 0xFFFFFFFD;
		this->field_31C.bothFlags = 22;
	}
	else
	{
		this->SetHeight(1, 100, 600);
		this->PlayHitWallSound();
		this->field_31C.bothFlags = 26;
	}

	this->dumbAssPad = 0;
}

// @Ok
INLINE void CThug::RunAppropriateHitAnim(void)
{
	i32 anim;
	if (this->field_218 & 0x10000)
	{
		anim = this->mType != 304 ? 38 : 43;
	}
	else if (this->field_218 & 0x20000)
	{
		anim = this->mType != 304 ? 37 : 42;
	}
	else
	{
		anim = this->mType != 304 ? 18 : 25;
	}

	this->RunAnim(anim, 0, -1);
}

// @Ok
INLINE void CThug::StopShooting(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->RunAnim(9, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
			{
				this->field_31C.bothFlags = 28;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
i32 CThug::TryAddingCollidePointToPath(CVector* pVector)
{
	if (Utils_CrapDist(*pVector, this->mPos) < 0x64)
		return 0;

	CVector v5 = *pVector - this->mPos;
	v5 >>= 0xC;
	v5 *= 0xE74;
	v5 += this->mPos;
	return this->AddPointToPath(&v5, 0);
}


void validate_CThug(void){

	VALIDATE_SIZE(CThug, 0x3C0);

	VALIDATE(CThug, field_330, 0x330);
	VALIDATE(CThug, field_33C, 0x33C);

	VALIDATE(CThug, mHandle, 0x354);
	VALIDATE(CThug, mHandleTwo, 0x35C);

	VALIDATE(CThug, field_370, 0x370);
	VALIDATE(CThug, field_374, 0x374);
	VALIDATE(CThug, field_378, 0x378);
	VALIDATE(CThug, field_37C, 0x37C);
	VALIDATE(CThug, field_380, 0x380);
	VALIDATE(CThug, field_384, 0x384);
	VALIDATE(CThug, field_388, 0x388);
	VALIDATE(CThug, field_38C, 0x38C);

	VALIDATE(CThug, field_394, 0x394);
	VALIDATE(CThug, field_398, 0x398);
	VALIDATE(CThug, field_39C, 0x39C);

	VALIDATE(CThug, field_3A0, 0x3A0);
	VALIDATE(CThug, field_3A4, 0x3A4);

	VALIDATE(CThug, field_3B0, 0x3B0);
	VALIDATE(CThug, field_3B8, 0x3B8);

	VALIDATE_SIZE(IntToBytes, 0x4);
}

void validate_CThugPing(void)
{
	VALIDATE_SIZE(CThugPing, 0x80);

	VALIDATE(CThugPing, field_70, 0x70);
	VALIDATE(CThugPing, field_78, 0x78);
}
