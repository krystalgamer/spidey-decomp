#include "baddy.h"
#include "validate.h"
#include "utils.h"
#include "mem.h"
#include "message.h"
#include "web.h"
#include <cmath>
#include "trig.h"
#include "ai.h"
#include "ps2lowsfx.h"
#include "my_assert.h"
#include "spool.h"
#include "m3dcolij.h"


CBody* ControlBaddyList;
CBaddy* BaddyList;
EXPORT CSVector gTrajectoryVector;
i32 gAttackRelated;
u8 gObjFileRegion;

// @FIXME - incorrect type
i32 gBossRelated;

extern i16** gTrigNodes;

// @Ok
// @Matching
INLINE i16 CBaddy::GetScriptValue(void)
{
	u16 result = *this->field_24C;
	this->field_24C++;

	if ((result & 0x8000u) == 0 && ((result & 0x2000u)))
		return this->GetVariable(result);

	return result;
}

// @Ok
void CBaddy::GetWaypointNearTarget(
		CVector* a2,
		i32 a3,
		i32 a4,
		CVector* a5)
{
	i32 unk;
	i32 v5; // eax
	i32 v6; // edi
	i32 v7; // ecx

	unk = a4 & 0x3F;
	v5 = 1 << (unk & 7);
	*a5 = *a2;
	v6 = unk & 8 ? 2 : 1;
	v7 = unk & 0x10 ? 2 : 1;

	if ( unk > 0x1F )
	{
		v6 += 2;
		v7 += 2;
	}
	if ( (v5 & 0xEE) != 0 )
		a5->vx += a3 * v6 * (v5 > 8 ? -1 : 1);
	if ( (v5 & 0xBB) != 0 )
		a5->vz += a3 * v7 * ((v5 & 0x83) != 0 ? 1 : -1);
}

// @NotOk
// check when pathcheck is done <3
i32 CBaddy::AddPointToPath(
		CVector* pVec,
		i32 a3)
{
	CVector v21;
	v21.vx = 0;
	v21.vy = 0;
	v21.vz = 0;

	CVector v20;
	v20 = *pVec;
	v20.vy = this->mPos.vy;

	if (this->field_1F4 > 0)
	{
		Trig_GetPosition(&v21, this->field_1F4);
		v21.vy = this->field_29C;

		if ((!a3 || Utils_CrapDist(v21, v20) < a3) && this->PathCheck(&v21, &v20, 0, 55))
		{
			this->field_1F0 = 1;
			this->field_1A8[1] = v20;
			this->field_2A8 |= 0x20000000;
			return 1;
		}
	}
	else if (!this->field_1F0)
	{
		this->field_1F0 = 1;
		this->field_1A8[1] = v20;
		return 1;
	}

	for (i32 i = 0; i<4 && i < this->field_1F0; i++)
	{
		if ( (!a3 || Utils_CrapDist(this->field_1A8[1+i], v20) < a3)
				&& this->PathCheck(&this->field_1A8[1+i], &v20, 0, 55))
		{
			this->field_1F0 = i + 2;
			this->field_1A8[i+2] = v20;
			this->field_2A8 |= 0x20000000;
			return 1;
		}
	}

	return 0;
}


// @Ok
i32 CBaddy::GetNextWaypoint(void)
{
	if (this->field_1F4 >= 0)
	{
		u16 *LinksPointer = reinterpret_cast<u16*>(Trig_GetLinksPointer(this->field_1F4));
		if (!*LinksPointer)
			return 0;

		this->field_1F4 = LinksPointer[1];

		u16* v4 = reinterpret_cast<u16*>(gTrigNodes[this->field_1F4]);
		this->field_2F0 = 0;

		if (*v4 == 1000 || *v4 == 1002)
		{
			CVector v9;
			v9.vx = 0;
			v9.vy = 0;
			v9.vz = 0;

			u16 *position = Trig_GetPosition(&v9, this->field_1F4);
			this->field_2F4 = 0;

			this->ParseScript(&position[3]);
		}

		return 1;
	}

	return 0;
}

// @NotOk
// Revisit, slightly different assembly, related to zx
void CBaddy::RunAppropriateAnim(void)
{
	if (this->field_2AC & 0x40000)
	{
		u8 v2 = this->field_294.Bytes[0];
		u8 v3 = this->field_294.Bytes[1];

		if (v2 != v3)
		{
			if (this->mAnim != v3
					&& this->mAnim != v2)
			{
				this->RunAnim(this->field_294.Bytes[0], 0, -1);
				return;
			}
		}

		if (v2 == v3
				|| this->mAnim != v2
				|| this->mAnimFinished)
		{
			this->CycleAnim(this->field_294.Bytes[1], 1);
		}
	}
	else if (this->field_2AC & 0x10000)
	{
		if (this->mAnim != this->field_294.Bytes[2] || this->mAnimFinished)
				this->RunAnim(this->field_294.Bytes[2], 0, -1);
	}
	else if (this->field_2AC & 0x20000)
	{
		if (this->mAnim != this->field_294.Bytes[3] || this->mAnimFinished)
				this->RunAnim(this->field_294.Bytes[3], 0, -1);
	}
	else
	{
		this->CycleAnim(this->field_298.Bytes[0], 1);
	}
}

// @Ok
// @Test
// @Note: offsets on the a3[v19] thingy are -4 somehow
i32 CBaddy::SmackSpidey(
		i32 a2,
		CVector *a3,
		i32 a4,
		i32 a5)
{
	SHook v21, v22;

	v21.Part.vx = 0;
	v21.Part.vy = 0;
	v21.Part.vz = 0;
	v22.Part.vx = 0;
	v22.Part.vy = 0;
	v22.Part.vz = 0;

	i32 v19 = 0;

	CVector firstVec;

	if (!gNumDomes)
	{
		for (i32 i = 0; ; i++)
		{
			if (i >= 32)
				return 0;

			if (a2 & (1 << i))
			{
				v21.Offset = i;
				v21.Part.vz = 0;
				v21.Part.vy = 0;
				v21.Part.vx = 0;

				firstVec = a3[v19];

				M3dUtils_GetDynamicHookPosition(
						reinterpret_cast<VECTOR*>(&a3[v19++]),
						this,
						&v21);

				if (a4)
				{
					CVector secondVec;
					secondVec = a3[v19 - 1];

					secondVec += (secondVec - firstVec) >> 1;

					if (Web_CollideWithSuper(MechList, &firstVec, &secondVec, &v22, 0x2000))
						break;
				}
			}
		}

		this->CreateCombatImpactEffect(&a3[v19 - 1], 0);

		if (this->field_1FC < 0xA)
		{
			SFX_PlayPos(0xFu, &MechList->mPos, 0);
		}
		else if (this->field_1FC < 0x14)
		{
			SFX_PlayPos(0x10u, &MechList->mPos, 0);
		}
		else
		{
			SFX_PlayPos(0x11u, &MechList->mPos, 0);
		}

		if (!a5)
		{
			SHitInfo v27;

			v27.field_C.vx = 0;
			v27.field_C.vy = 0;
			v27.field_C.vz = 0;

			v27.field_0 = 15;
			v27.field_4 = 8;
			v27.field_8 = this->field_1FC;
			v27.field_1 = v22.Offset;

			v27.field_C.vz = (MechList->mPos.vz - this->mPos.vz) >> 12;
			v27.field_C.vx = (MechList->mPos.vx - this->mPos.vx) >> 12;
			v27.field_C.vy = 0;

			VectorNormal(
					reinterpret_cast<VECTOR*>(&v27.field_C),
					reinterpret_cast<VECTOR*>(&v27.field_C));

			MechList->Hit(&v27);

			if (MechList->mHealth <= 0)
				this->Victorious();
		}
		return 1;
	}
	return 0;
}

// @Ok
// @Matching
INLINE i32 CBaddy::DistanceToPlayer(i32 a2){

	if (this->field_208 && gAttackRelated - this->field_208 <= a2 )
		return this->field_204;

	this->field_208 = gAttackRelated;
	this->field_204 = Utils_CrapXZDist(this->mPos, MechList->mPos);

	return this->field_204;
}

// @Ok
int CBaddy::TrapWeb(void){
	if((this->field_2A8 & 0x10000) || (this->mHealth <= 0)){
		return 0;
	}

	new CMessage(NULL, this, 5, 0);

	return 1;
}

// @Ok
INLINE void CBaddy::CleanUpMessages(i32 a2, i32 a3)
{

	CMessage *pMessage = this->pMessage;
	while (pMessage)
	{
		CMessage *curMessage = pMessage;
		pMessage = pMessage->mNext;
		if (
				curMessage->field_10 & 1
				|| a2
				|| curMessage->field_14 == a3)
		{
			delete curMessage;
		}
	}
}

// @Ok
u16 CBaddy::CheckStateFlags(SStateFlags *sFlags, int a3){

	if(this->field_314 < 0){
		if (this->field_31C.bothFlags == -this->field_314)
			return 0;
	}
	else if(this->field_31C.bothFlags == sFlags[this->field_314].flags[0]){
		print_if_false(sFlags[this->field_314].flags[1] != 0, "This shouldn't be zero.  Remove state from table.");
		return sFlags[this->field_314].flags[1];
	}

	for (i32 i = 0; i< a3; i++){

		if (this->field_31C.bothFlags != (u16) sFlags[i].flags[0]){
			continue;
		}

		this->field_314 = i;
		print_if_false(sFlags[i].flags[1] != 0, "This shouldn't be zero.  Remove state from table.");
		return sFlags[i].flags[1];
	}

	this->field_314 = -this->field_31C.flags[0];
	return 0;	
}

// @NotOk
// Revisit??
int CBaddy::YawTowards(int a2, int a3){

	int vy; // edi
	int v4; // eax
	int v5; // edx


	vy = this->mAngles.vy;
	v4 = a2 - vy;

	if ( a2 - vy < -2048 )
		v4 += 4096;
	if ( v4 > 2048 )
		v4 -= 4096;

	if ( !v4 )
	{
		this->mAngAcc.vy = 0;
		this->mAngVel.vy = 0;
		return v4;
	}

	v5 = (a3 * v4) >> 8;
	this->mAngles.vy += v5;
	if ( v5 && ((int)this->mAngles.vy - a2 > 0) != (vy - a2> 0))
	{
		return v4;
	}

	this->mAngles.vy = a2;
	this->mAngAcc.vy = 0;
	this->mAngVel.vy = 0;
	return 0;
}

// @Ok
int CBaddy::RunTimer(int *a2)
{
	*a2 -= this->field_80;
	if ( *a2 < 0 )
		*a2 = 0;
	return *a2;
}

// @BIGTODO
int CBaddy::PathCheckGuts(CVector*, CVector*, CVector*, int)
{
	return 0x14141414;
}

// @Ok
// @Matching
INLINE i32 CBaddy::PathCheck(CVector* a2, CVector* a3, CVector* a4, i32 a5)
{

	i32 v5 = BaddyCollisionCheck;

	if ((this->field_2A8 & 0x2000))
		BaddyCollisionCheck = 1;

	i32 result = this->PathCheckGuts(a2, a3, a4, a5);
	BaddyCollisionCheck = v5;
	return result;
}


// @Ok
// @Matching
CBody* CBaddy::StruckGameObject(i32 a2, i32 a3)
{
	CBody *result;
	  if ( !a2
			|| (result = Utils_CheckObjectCollision(
				&this->field_2FC,
				&this->mPos,
				MechList,
				this)) == 0 )
	  {
		  if (a3 && (result = Utils_CheckObjectCollision(&this->field_2FC, &this->mPos, BaddyList, this)))
		  {
			  DoAssert(result != this, "smoething's wrong in the state of denmark");
			  return result;
		  }

		  return NULL;
	  }

	  return result;
}

// @Ok
void CBaddy::Neutralize(void)
{
	this->MarkAIProcList(1, 0, 0);

	this->mAcc.vz = 0;
	this->mAcc.vy = 0;
	this->mAcc.vz = 0;

	this->mVel.vz = 0;
	this->mVel.vy = 0;
	this->mVel.vx = 0;

	this->mAcc.vz = 0;
	this->mAcc.vy = 0;
	this->mAcc.vx = 0;

	this->mAngVel.vz = 0;
	this->mAngVel.vy = 0;
	this->mAngVel.vx = 0;

	this->mAngAcc.vz = 0;
	this->mAngAcc.vy = 0;
	this->mAngAcc.vx = 0;

	this->field_27C.vz = 0;
	this->field_27C.vy = 0;
	this->field_27C.vx = 0;

	this->field_2A8 &= 0xB7FFFFFB;
}

// @NotOk
int CBaddy::TugWeb(void)
{
	if ( (this->field_2A8 & 0x200) || this->mHealth <= 0)
	{

		CTrapWebEffect *trapWeb = reinterpret_cast<CTrapWebEffect*>(
				Mem_RecoverPointer(reinterpret_cast<SHandle*>(&this->field_10C)));

		if (trapWeb)
			trapWeb->Burst();

		return 0;
	}

	new CMessage(0, this, 6, 0);
	return 1;
}

// @Ok
INLINE void CBaddy::GetLocalPos(CVector *a2, CVector *a3, CSVector *a4)
{
	MATRIX v7;

	if (a4)
	{
		M3dMaths_RotMatrixYXZ(
				reinterpret_cast<SVECTOR*>(a4),
				&v7);
	}
	else
	{
		M3dMaths_RotMatrixYXZ(
				reinterpret_cast<SVECTOR*>(&this->mAngles),
				&v7);
	}

	gte_SetRotMatrix(&v7);
	*a3 = *a2;
	gte_ldlvl(reinterpret_cast<VECTOR*>(a3));
	gte_rtir();
	gte_stlvnl(reinterpret_cast<VECTOR*>(a3));

}

// @Ok
int CBaddy::MakeSpriteRing(CVector* arg0)
{
	CVector mPos;
	mPos.vx = 0;
	mPos.vy = 0;
	mPos.vz = 0;
	
	if (!arg0)
	{
		mPos = this->mPos;
	}
	else
	{
		CVector tmp = *arg0;

		tmp >>= 12;
		this->GetLocalPos(&tmp, &mPos, 0);

		mPos <<= 12;
		mPos += this->mPos;
	}

	mPos.vy = Utils_GetGroundHeight(&this->mPos, 300, 600, 0) - 0xA000;
	return Bit_MakeSpriteRing(&mPos, 24, 8, 1, 512, 32, 16, 0);
}

// @Ok
// @AlmostMatching: vector assingment is different
int CBaddy::SetHeight(int a2, int a3, int a4)
{
	if (this->field_2A8 & 0x8000)
	{
		return 1;
	}

	if (this->field_2A4
			|| a2
			|| (this->field_2A8 & 0x40000) != 0
			|| (this->field_2A8 & 0x8000000) != 0 && ((this->field_2A8 & 0x20000000) != 0 || (this->field_2F0 & 4) != 0) )
	{
		u8 v9;

		if (a2 || ( 
					v9 = this->field_80, v9 += this->field_213,
				v9 >= this->field_212))
		{
			CVector v16;
			v16.vx = this->mPos.vx;
			v16.vy = this->mPos.vy + (this->field_21E << 12);
			v16.vz = this->mPos.vz;

			i32 height = Utils_GetGroundHeight(&v16, a3, a4, &this->field_2A4);
			if (height == -1)
			{
				return 0;
			}

			if (this->field_2A4)
			{
				if (this->field_2A4->mVel.vy == 0)
				{
					this->field_2A4 = 0;
				}
				else
				{
					height += this->field_2A4->mVel.vy;
				}
			}

			this->field_2A0 = height;
			if (!this->field_212)
				this->field_212 = 30;
			this->field_213 = 0;
		}
	}

	i32 v13 = this->field_2A0 - (this->field_21E << 12);

	if (v13 != this->mPos.vy)
	{
		this->mPos.vy += ((v13 - this->mPos.vy) >> 2);
		if (my_abs(this->mPos.vy - v13) <= (this->field_2A4 == 0 ? 12288 : 122880))
		{
			this->mPos.vy = v13;
		}
		else
		{
			return 1;
		}
		
	}

	return 2;
}


// @Ok
void INLINE CBaddy::SendDeathPulse(void)
{

	if (!this->field_211 && this->mNode != 0xFFFF)
	{
		this->field_211 = 1;
		Trig_SendPulse(
				reinterpret_cast<u16*>(Trig_GetLinksPointer(this->mNode & 0xFFFF)));
	}
}

// @Ok
int CBaddy::Die(int a2)
{
	if(!this->IsDead())
	{
		int v8;
		int v9;
		switch (a2)
		{
			case 0:
				if (!(this->field_2A8 & 0x4000))
				{
					this->SendDeathPulse();
				}
			case 3:
				this->mCBodyFlags |= 0x40;
				this->mFlags |= 1;
				break;
			case 1:
				if (!(this->field_2A8 & 0x4000))
				{
					this->SendDeathPulse();
				}

				this->mFlags |= 0x800;
				this->mTRN = 128;
				this->KillShadow();

				this->mFlags |= 0x400;
				this->mRGB = 0x404040;
				this->field_1F8 = 0;
				break;
			case 2:
				v8 = this->field_1F8;
				v9 = v8 + 1;
				this->field_1F8 = v9;
				if ( v8 >= 40 )
					return 1;

				v9 = ((6553 * (40 - v9)) >> 12);
				v8 = v9;

				v8 <<= 8;
				v8 |= v9;
				v8 <<= 8;
				v8 |= v9;

				this->mRGB =  v8;
				break;


			default:
				print_if_false(0, "Unknown die state");
		}
	}

	return 0;
}

// @Ok
INLINE void CBaddy::CleanUpAIProcList(i32 a2)
{
	CAIProc *pProc = this->mAIProcList;
	while (pProc)
	{
		CAIProc *curProc = pProc;
		pProc = pProc->mNext;
		if (
				 a2
				|| curProc->field_10 & 1)
		{
			delete curProc;
		}
	}
}

// @Ok
// @Matching
i32 CBaddy::BumpedIntoSpidey(i32 a2)
{
	i32 v4;

	if (this->field_208 && gAttackRelated - this->field_208 <= 4)
	{
		v4 = this->field_204;
	}
	else
	{
		this->field_208 = gAttackRelated;
		v4 = Utils_CrapXZDist(this->mPos, MechList->mPos);
		this->field_204 = v4;
	}

	if (v4 < a2)
	{
		i32 res = this->field_21E - MechList->field_EA8 - (MechList->mPos.vy >> 12) + (this->mPos.vy >> 12);

		if (my_abs(res) < 200)
			return 1;
	}

	return 0;
}


// @Ok
// @AlmostMatching: vector assingment is different
i32 CBaddy::PlayerIsVisible()
{
	if (!MechList->IsDead() &&
			Utils_LineOfSight(&this->mPos, &MechList->mPos, 0, 0)
			)
	{
		if (!this->PathCheck( &this->mPos, &MechList->mPos, 0, 55))
		{
			this->field_1A8[0] = MechList->mPos;
			this->field_2A8 |= 0x800;
		}
		return 1;
	}

	return 0;
}

// @Ok
int CBaddy::ShouldFall(int a2, int a3)
{
	int GroundHeight = Utils_GetGroundHeight(&this->mPos, a2, 4096, 0);
	if (GroundHeight == -1)
	{
		this->field_308 = this->mPos.vy - 100;
		this->KillShadow();

		this->field_2A8 &= 0xFFFFFBFF;

		return GroundHeight;
	}

	int v7 = GroundHeight - (this->field_21E << 12);

	if (v7 - this->mPos.vy > a3)
	{
		this->KillShadow();

		this->field_308 = v7;
		this->field_2A8 |= 0x400;

		return v7 - this->mPos.vy;
	}

	return 0;
}

// @Ok
// @Matching
i32 CBaddy::CheckSightCone(i32 a2, i32 a3, i32 a4, i32 a5, CBody *a6)
{
	CSVector v16;
	if (!a3)
		return 0;


	i32 v12 = a6->mPos.vy - this->mPos.vy;
	if (my_abs(v12) > (a3 << 12))
		return 0;

	i32 v13;
	if (a6 == MechList)
	{
		v13 = this->DistanceToPlayer(2);
	}
	else
	{
		v13 = Utils_CrapXZDist(this->mPos, a6->mPos);
	}

	if (v13 < a5)
		return 1;

	if (v13 > a4)
		return 0;

	Utils_CalcAim(&v16, &this->mPos, &a6->mPos);
	i32 v14 = v16.vy - this->mAngles.vy;
	if (v14 < -2048)
	{
		v14 += 4096;
	}
	else if (v14 >= -2048)
	{
		if (v14 > 2048)
		{
			v14 -= 4096;
		}
	}

	return my_abs(v14) <= (a2 >> 1);
}

// @MEDIUMTODO
void CBaddy::ParseScript(u16*)
{
	printf("void CBaddy::ParseScript(u16*)");
}

i32 NumBaddies;

// @NotOk
// Globals
CBaddy::CBaddy(void)
{
	this->field_1A8[0].vx = 0;
	this->field_1A8[0].vy = 0;
	this->field_1A8[0].vz = 0;

	for(int i=0; i<5; i++)
	{
		this->field_1A8[1+i].vx = 0;
		this->field_1A8[1+i].vy = 0;
		this->field_1A8[1+i].vz = 0;
	}

	this->field_240.vx = 0;
	this->field_240.vy = 0;
	this->field_240.vz = 0;
	this->field_27C.vx = 0;
	this->field_27C.vy = 0;
	this->field_27C.vz = 0;
	this->field_2B8.vx = 0;
	this->field_2B8.vy = 0;
	this->field_2B8.vz = 0;
	this->field_2C4 = 0;
	this->field_2C8 = 0;
	this->field_2CC = 0;
	this->field_2D0.vx = 0;
	this->field_2D0.vy = 0;
	this->field_2D0.vz = 0;
	this->field_2DC = 0;
	this->field_2DE = 0;
	this->field_2E0 = 0;
	this->field_2E2 = 0;
	this->field_2E4 = 0;
	this->field_2E6 = 0;
	this->field_2E8.vx = 0;
	this->field_2E8.vy = 0;
	this->field_2E8.vz = 0;
	this->field_2FC.vx = 0;
	this->field_2FC.vy = 0;
	this->field_2FC.vz = 0;

	this->field_21D = NumBaddies++;
	this->mCBodyFlags |= 0x200;

	this->mRMinor = 128;
	this->field_F4 = 128;
	this->mNode = -1;
	this->field_216 = 32;
	this->mPushVal = 64;
}

// @Ok
void CBaddy::CreateCombatImpactEffect(CVector*, int)
{
}

// @Ok
u8 CBaddy::TugImpulse(CVector*, CVector*, CVector* a4)
{
	if (a4)
		Mem_Delete(a4);
	return 0;
}

// @Ok
void CBaddy::Victorious()
{
}

// @Ok
void CBaddy::SetParamByIndex(i32, i32)
{
}

// @Ok
u8 CBaddy::Grab(CVector*)
{
	return 0;
}

// @Ok
void CBaddy::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics(0);
}

// @NotOk
// Figure out name
void CBaddy::UnknownCBaddyFunctionFive(int)
{
}

// @Ok
CBaddy* CBaddy::GetClosest(i32 baddyType, i32 inSight)
{
	i32 distance = 10656;
	CBaddy* result = 0;

	for ( CBaddy* i = BaddyList; i; i = reinterpret_cast<CBaddy*>(i->mNextItem))
	{
		if ( (!baddyType || i->mType == baddyType) && i != this )
		{
			i32 v9 = Utils_CrapXZDist(this->mPos, i->mPos);
			if ( distance > v9
				&& (!inSight || Utils_LineOfSight(&i->mPos, &this->mPos, 0, 0)) )
			{
				distance = v9;
				result = i;
			}
		}
	}

	return result;
}

// @BIGTODO
int CBaddy::ExecuteCommand(u16)
{
	return 0x21052025;
}

// @Ok
// @AlmostMatching: for the case 2120 the code for GetScriptVariable was inlined differently
// dunno why, already spent an un-godly amount of time matching others (cough cough 2121)
void CBaddy::SetVariable(u16 a2)
{
	switch (a2)
	{
		case 0x2103:
			this->field_1FC = *this->field_24C;
			this->field_24C++;
			break;
		case 0x2106:
			this->field_1FE = *this->field_24C;
			this->field_24C++;
			break;
		case 0x2135:
			{
				u32 *v6 = reinterpret_cast<u32*>((reinterpret_cast<i32>(this->field_24C) + 3) & 0xFFFFFFFC);

				this->field_23C = *v6;
				this->field_24C = reinterpret_cast<i16*>(&v6[1]);
			}
			break;
		case 0x212F:
			{
				u32 *v7 = reinterpret_cast<u32*>((reinterpret_cast<u32>(this->field_24C) + 3) & 0xFFFFFFFC);
				u16 Model = Spool_GetModel(*v7, this->mRegion);
				this->field_24C = reinterpret_cast<i16*>(&v7[1]);
				this->mModel = Model;
			}
			break;
		case 0x2140:
			this->mPos.vx = this->GetScriptValue() << 12;
			break;
		case 0x2141:
			this->mPos.vy = this->GetScriptValue() << 12;
			break;
		case 0x2142:
			this->mPos.vz = this->GetScriptValue() << 12;
			break;
		case 0x2131:
			if (*(this->field_24C++))
				this->mFlags |= 8;
			else
				this->mFlags &= ~8;
			break;
		case 0x212E:
			this->field_216 = *this->field_24C;
			this->field_24C++;
			break;
		case 0x212C:

			this->field_210 = *this->field_24C;
			this->field_24C++;
			break;
		case 0x212D:
			this->field_20F = *this->field_24C;
			this->field_24C++;
			break;
		case 0x2100:
			this->mHealth = *this->field_24C;
			this->field_24C++;
			break;
		case 0x2101:
			this->mRMinor = *this->field_24C;
			this->field_24C++;
			break;
		case 0x2125:
			{
				u16 v20 = *this->field_24C;
				this->field_24C++;
				DoAssert(v20 < 6u, "Attribute index out of bounds");
				this->attributeArr[v20] = *this->field_24C++;
			}
			break;
		case 0x2120:
			{
				i16 v20 = *this->field_24C++;
				i16 v21 = this->GetScriptValue();

				DoAssert((u8)v20 < 6, "Bad register index");

				this->realRegisterArr[v20 & 0xFF] = v21;
			}
			break;

		case 0x2138:
			this->field_24C = reinterpret_cast<i16*>((reinterpret_cast<i32>(this->field_24C) + 3 & 0xFFFFFFFC) + 4);
			break;





		case 0x2121:
			{
				// @Note: wow
				i16 *tmp = this->field_24C;
				i16 tmp2 = *tmp;
				this->field_24C++;
				this->mAnimSpeed = tmp2;
			}
			break;

		case 0x2122:
			this->field_21E = *this->field_24C;
			this->field_24C++;
			break;


		default:
			DoAssert(0, "Unknown script variable");
			break;
	}
}

// @MEDIUMTODO
i16 CBaddy::GetVariable(u16 a2)
{
	return 696969;
}

// @BIGTODO
void CBaddy::DoPhysics(i32)
{
	printf("void CBaddy::DoPhysics(int)");
}

// @Ok
void CBaddy::Baddy_SendSignal(void)
{
	u16 *ptr = reinterpret_cast<u16*>(
			Trig_GetLinksPointer(this->mNode));
	if (ptr)
		Trig_SendSignalToLinks(ptr);
}

// @Ok
// @Matching
CBaddy* FindBaddyOfType(i32 type)
{
	CItem *current = BaddyList;

	while (current)
	{
		if (current->mType == type)
		{
			return reinterpret_cast<CBaddy*>(current);
		}

		current = current->mNextItem;
	}

	return 0;
}

// @Ok
// @Matching
void CBaddy::MarkAIProcList(i32 a2, i32 a3, i32 a4)
{
	CAIProc* it = this->mAIProcList;

	while (it)
	{
		CAIProc *current = it;
		it = it->mNext;


		if (a2 && (current->mAIProcType & AI_TYPE_UNK_20000) == 0 ||
				a3 && (current->mAIProcType & 0xFF00) == a3)
		{
			current->field_10 |= 1;
		}
		else if (a4)
		{
			if ((current->mAIProcType & 0xFF00) == a4)
			{
				current->field_10 |= 4;
			}
		}
	}
}

// @Ok
CBaddy::~CBaddy(void)
{
	print_if_false(NumBaddies > 0, "Negative NumBaddies");
	--NumBaddies;

	this->CleanUpAIProcList(1);
	this->CleanUpMessages(1, 0);
}

void validate_CBaddy(void){
	VALIDATE_SIZE(CBaddy, 0x324);

	VALIDATE(CBaddy, field_194, 0x194);
	VALIDATE(CBaddy, field_198, 0x198);

	VALIDATE(CBaddy, field_1A8, 0x1A8);

	VALIDATE(CBaddy, field_1F0, 0x1F0);
	VALIDATE(CBaddy, field_1F4, 0x1F4);
	VALIDATE(CBaddy, field_1F8, 0x1F8);
	VALIDATE(CBaddy, field_1FC, 0x1FC);
	VALIDATE(CBaddy, field_1FE, 0x1FE);

	VALIDATE(CBaddy, field_204, 0x204);
	VALIDATE(CBaddy, field_208, 0x208);
	VALIDATE(CBaddy, field_20C, 0x20C);
	VALIDATE(CBaddy, field_20F, 0x20F);
	VALIDATE(CBaddy, field_210, 0x210);


	VALIDATE(CBaddy, field_211, 0x211);
	VALIDATE(CBaddy, field_212, 0x212);
	VALIDATE(CBaddy, field_213, 0x213);

	VALIDATE(CBaddy, field_216, 0x216);
	VALIDATE(CBaddy, field_218, 0x218);
	VALIDATE(CBaddy, field_21D, 0x21D);
	VALIDATE(CBaddy, field_21E, 0x21E);

	VALIDATE(CBaddy, field_220, 0x220);
	VALIDATE(CBaddy, realRegisterArr, 0x222);

	VALIDATE(CBaddy, field_230, 0x230);
	VALIDATE(CBaddy, field_234, 0x234);
	VALIDATE(CBaddy, field_23C, 0x23C);

	VALIDATE(CBaddy, field_240, 0x240);

	VALIDATE(CBaddy, field_24C, 0x24C);


	VALIDATE(CBaddy, attributeArr, 0x270);
	VALIDATE(CBaddy, field_27C, 0x27C);

	VALIDATE(CBaddy, field_288, 0x288);

	VALIDATE(CBaddy, mAIProcList, 0x28C);
	VALIDATE(CBaddy, pMessage, 0x290);

	VALIDATE(CBaddy, field_294, 0x294);
	VALIDATE(CBaddy, field_298, 0x298);
	VALIDATE(CBaddy, field_29C, 0x29C);

	VALIDATE(CBaddy, field_2A0, 0x2A0);
	VALIDATE(CBaddy, field_2A4, 0x2A4);
	VALIDATE(CBaddy, field_2A8, 0x2A8);
	VALIDATE(CBaddy, field_2AC, 0x2AC);

	VALIDATE(CBaddy, field_2B0, 0x2B0);
	VALIDATE(CBaddy, field_2B4, 0x2B4);
	VALIDATE(CBaddy, field_2B8, 0x2B8);


	VALIDATE(CBaddy, field_2C4, 0x2C4);
	VALIDATE(CBaddy, field_2C8, 0x2C8);
	VALIDATE(CBaddy, field_2CC, 0x2CC);

	VALIDATE(CBaddy, field_2D0, 0x2D0);

	VALIDATE(CBaddy, field_2DC, 0x2DC);
	VALIDATE(CBaddy, field_2DE, 0x2DE);

	VALIDATE(CBaddy, field_2E0, 0x2E0);
	VALIDATE(CBaddy, field_2E2, 0x2E2);
	VALIDATE(CBaddy, field_2E4, 0x2E4);
	VALIDATE(CBaddy, field_2E6, 0x2E6);
	VALIDATE(CBaddy, field_2E8, 0x2E8);


	VALIDATE(CBaddy, field_2F0, 0x2F0);
	VALIDATE(CBaddy, field_2F4, 0x2F4);
	VALIDATE(CBaddy, field_2F8, 0x2F8);
	VALIDATE(CBaddy, field_2FC, 0x2FC);


	VALIDATE(CBaddy, field_308, 0x308);
	VALIDATE(CBaddy, field_310, 0x310);
	VALIDATE(CBaddy, field_314, 0x314);
	VALIDATE(CBaddy, field_318, 0x318);
	VALIDATE(CBaddy, field_31C, 0x31C);
	VALIDATE(CBaddy, dumbAssPad, 0x320);

	VALIDATE_VTABLE(CBaddy, AI, 2);
	VALIDATE_VTABLE(CBaddy, Hit, 3);
	VALIDATE_VTABLE(CBaddy, PlayerIsVisible, 5);
	VALIDATE_VTABLE(CBaddy, CreateCombatImpactEffect, 6);
	VALIDATE_VTABLE(CBaddy, TugImpulse, 7);
	VALIDATE_VTABLE(CBaddy, Victorious, 8);

	VALIDATE_VTABLE(CBaddy, SetParamByIndex, 9);
	VALIDATE_VTABLE(CBaddy, Grab, 10);

	VALIDATE_VTABLE(CBaddy, Shouldnt_DoPhysics_Be_Virtual, 11);
	VALIDATE_VTABLE(CBaddy, GetClosest, 13);
	VALIDATE_VTABLE(CBaddy, ExecuteCommand, 14);
	VALIDATE_VTABLE(CBaddy, SetVariable, 15);
	VALIDATE_VTABLE(CBaddy, GetVariable, 16);
}


void validate_CScriptOnlyBaddy(void){

	VALIDATE_SIZE(CScriptOnlyBaddy, 0x330);
	VALIDATE(CScriptOnlyBaddy, field_328, 0x328);
	VALIDATE(CScriptOnlyBaddy, field_32C, 0x32C);
	VALIDATE(CScriptOnlyBaddy, field_32E, 0x32E);
}

void validate_SStateFlags(void){
	VALIDATE_SIZE(SStateFlags, 0x4);
}
