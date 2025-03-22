#include "chopper.h"
#include "validate.h"
#include "utils.h"
#include "baddy.h"
#include "trig.h"
#include "spool.h"
#include "ps2lowsfx.h"
#include "m3dutils.h"
#include "exp.h"
#include "spidey.h"
#include "camera.h"
#include "chunk.h"
#include "ps2pad.h"
#include "front.h"
#include <cmath>
#include "ai.h"

extern CBody* ControlBaddyList;
extern CBaddy* BaddyList;
extern SSinCos rcossin_tbl[];

extern i32 DifficultyLevel;
extern i16 **gTrigNodes;

extern const char *gObjFile;
extern CPlayer* MechList;

extern CCamera* CameraList;

// @Ok
// @Matching
void Chopper_RelocatableModuleClear(void)
{
	CItem *pSearch = BaddyList;

	while (pSearch)
	{
		CItem *pNext = pSearch->mNextItem;

		if (pSearch->field_38 == 318)
		{
			delete pSearch;
		}
		else if (pSearch->field_38 == 322)
		{
			delete pSearch;
		}
		else if (pSearch->field_38 == 323)
		{
			delete pSearch;
		}

		pSearch = pNext;
	}
}

// @Ok
// @Matching
void Chopper_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Chopper_RelocatableModuleClear;
	pMod->field_C[0] = Chopper_CreateChopper;
	pMod->field_C[1] = Chopper_CreateSearchlight;
	pMod->field_C[2] = Chopper_CreateSniper;
}

// @Ok
CBulletFrag::~CBulletFrag(void)
{
}

// @Ok
// @Test
void CChopper::TrackSpidey(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->MarkAIProcList(0, 256, 0);
			this->SetHeightMode(4);

			this->SetDesiredPosForTrackMode();
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_218 & 1)
			{
				this->field_31C.bothFlags = 2;
				this->dumbAssPad = 0;
			}
			else if (this->GetToDesiredPos())
			{
				this->field_1F8 = 0;
				this->SetHeightMode(5);
				this->dumbAssPad++;
			}
			else
			{
				this->GetOutOfCameraPath();
				this->field_35C |= 1;
			}
			break;
		case 2:

			this->field_35C |= 1;
			if (this->field_218 & 1)
			{
				this->field_37C = 0;

				this->field_31C.bothFlags = 2;
				this->dumbAssPad = 0;
			}
			else
			{
				this->field_1F8 += this->field_80;
				if (this->field_1F8 > 30)
				{
					if (this->field_380)
						this->StartStrafeOnslaught();
					this->dumbAssPad++;
				}
			}


			break;
		case 3:
			this->field_35C |= 1;

			if (!this->field_384 || !this->field_380)
			{
				if (this->field_218 & 1)
					this->field_31C.bothFlags = 2;

				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @MEDIUMTODO
// @FIXME name does not have a V
void CChopper::FireMachineGunAtWaypointV(void)
{
	printf("void CChopper::FireMachineGunAtWaypoint(void)");
}

// @Ok
INLINE i32 CChopper::GetToDesiredPos(void)
{
	CVector v13 = (MechList->mPos - this->field_33C);

	v13.vy = this->field_34C;
	return this->GetToPos(&v13);
}

// @Ok
void INLINE CChopper::GetOutOfCameraPath(void)
{
	if (this->InCameraPath())
	{
		i32 newY = CameraList->mPos.vy - 409600;
		if (this->field_34C > newY)
			this->field_34C = newY;
	}
}


// @Ok
i32 INLINE CChopper::InCameraPath(void)
{
	i32 v1 = this->field_360 - CameraList->field_23A;
	if (v1 < -2048)
	{
		v1 += 4096;
	}
	else if (v1 > 2048)
	{
		v1 -= 4096;
	}

	return my_abs(v1) < 250;
}

// @Ok
// @Test
void CChopper::StartStrafeOnslaught(void)
{
	if (MechList->field_8E8)
	{
		CVector v18(0, (Vblanks & 1) != 0 ? 4096 : -4096, 0);

		gte_ldopv1(reinterpret_cast<VECTOR*>(&MechList->field_C84));
		gte_ldopv2(reinterpret_cast<VECTOR*>(&v18));

		gte_op12();
		gte_stlvnl(reinterpret_cast<VECTOR*>(&v18));
		VectorNormal(
				reinterpret_cast<VECTOR*>(&v18),
				reinterpret_cast<VECTOR*>(&v18));

		v18 *= 400;
		
		this->field_388 = MechList->mPos - v18;
		this->field_3A4 = Rnd(4) + 8;

		v18 /= (this->field_3A4 >> 1);

		this->field_394 = v18;
	}
	else
	{
		i32 v6 = this->field_360 - this->field_358;

		if (v6 < -2048)
		{
			v6 += 4096;
		}
		else if (v6 > 2048)
		{
			v6 -= 4096;
		}

		
		CSVector v13;

		v13.vy = this->field_358 + (v6 < 0 ? -800 : 800);
		v13.vx = 0;
		v13.vz = 0;

		CVector v17;
		Utils_GetVecFromMagDir(&v17, 4096, &v13);

		v17 >>= 12;
		v17 *= 200;

		CVector v16 = MechList->mPos;
		if (!MechList->field_AD4)
		{
			i32 GroundHeight = Utils_GetGroundHeight(&MechList->mPos, 300, 300, 0);

			if (GroundHeight != -1)
				v16.vy = GroundHeight;
		}

		this->field_388 = v16 - v17;
		this->field_3A4 = Rnd(4) + 8;

		v17 /= (this->field_3A4 >> 1);
		this->field_394 = v17;
	}

	this->field_3A0 = 0;
	this->field_384 = 1;
}

// @Ok
// @Test
void CChopper::Shoot(void)
{
	if (this->field_384)
	{
		if (!this->field_328)
			this->field_328 = SFX_PlayPos(0x8008u, &this->mPos, 0);

		switch (this->field_384)
		{
			case 1:
				if ((gAttackRelated & 3) == 0)
				{
					CVector v8;
					M3dUtils_GetHookPosition(reinterpret_cast<VECTOR *>(&v8), this, 1);

					CVector v7 = this->field_394 * this->field_3A0;
					v7 += this->field_388;

					v7 += (v7 - v8);

					this->field_3A8 = v7;
					M3dUtils_GetHookPosition(reinterpret_cast<VECTOR *>(&v8), this, 1);

					this->ShotCollision(&v8, &v7);

					if (++this->field_3A0 > this->field_3A4)
						this->field_384 = 0;
				}

				break;
			case 2:
				if ((gAttackRelated & 3) == 0)
				{
					CVector v8;
					M3dUtils_GetHookPosition(reinterpret_cast<VECTOR *>(&v8), this, 1);
					this->ShotCollision(&v8, &this->field_3B8);
					this->field_3C4 = 1;
				}
				break;
			default:
				print_if_false(0, "Unknown shooting mode!");
				break;
		}
	}
}

// @Ok
void CChopper::ShotCollision(CVector *a2, CVector *a3)
{
	new CGlowFlash(a2, 5, 0xA0u, 144, 96, 16, 0, 0, 0, 0, 50, 20, 1, 20, 10, 40, 20, 10, 2);
	new CMachineGunBullet(a2, a3, this);
}

// @Ok
// @AlmostMatching: vec assignement always differs dunno why
void CChopper::SetDesiredPosForTrackMode(void)
{
	this->field_360 = this->field_358;
	if (this->field_32C)
	{
		if (this->field_218 & 0x20)
		{
			this->field_360 -= 653;
			if (!Rnd(16))
				this->field_218 &= 0xFFFFFFDF;
			}
			else
			{
				this->field_360 += 653;
				if (!Rnd(16))
					this->field_218 |= 0x20u;
			}
	}

	this->field_360 = Rnd(796) + this->field_360 - 398;
	this->field_360 &= 0xFFFu;
	this->field_370 = 800;
	this->field_370 = Rnd(50) + this->field_370 - 25;

	CSVector v14;
	v14.vx = 0;
	v14.vy = this->field_360;
	v14.vz = 0;
	Utils_GetVecFromMagDir(&this->field_364, 4096, &v14);

	this->field_33C = (this->field_364 >> 12) * this->field_370;
	this->field_33C.vy = 3276800;

	this->field_33C.vy += (Rnd(614400) - 327680) + 20480;

	this->field_34C = MechList->mPos.vy - this->field_33C.vy;

	if (this->field_34C > this->field_350)
		this->field_34C = this->field_350;
}

// @NotOk
// @FIXME: ApplyPose fix
void CChopper::AI(void)
{
	if (this->pMessage)
		this->CleanUpMessages(1, 0);

	if ((gAttackRelated & 3) == 0)
	{
		if (!this->field_328)
		{
			SFX_Stop(this->field_328);
			this->field_328 = 0;
		}
		else
		{
			SFX_ModifyPos(this->field_328, &this->mPos, 0);
		}

		if (this->field_324)
			SFX_ModifyPos(this->field_324, &this->mPos, 0);
		else
			this->field_324 = SFX_PlayPos(0x8001u, &this->mPos, 0);
	}

	this->DoChopperPhysics();
	this->RotateBlades();
	this->AimGunPod();
	this->ApplyPose(reinterpret_cast<i16*>(0x1A2BD8));

	if (this->field_384)
	{
		this->Shoot();
	}
	else
	{
		this->field_3A8.vx = 0;
		this->field_3A8.vy = 0;
		this->field_3A8.vz = 0;
	}

	switch (this->field_31C.bothFlags)
	{
		case 0:
			this->field_348 = 45;
            this->field_31C.bothFlags = 2;
			this->dumbAssPad = 0;
			break;
		case 1:
			this->TrackSpidey();
			break;
		case 2:
			this->FollowWaypoints();
			break;
		case 3:
			this->WaitForTrigger();
			break;
		case 4:
			this->FireMachineGunAtWaypointV();
			break;
		default:
			print_if_false(0, "Unknown state!");
			break;
	}
}

// @Ok
void CChopper::FollowWaypoints(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->MarkAIProcList(0, 256, 0);
			this->field_218 &= 0xFFFFFFFE;
			Trig_GetPosition(&this->field_33C, this->field_1F4);

			this->SetHeightMode(4);
			this->field_34C = this->field_33C.vy;
			this->dumbAssPad++;

			this->DoWaypointAction();

			if (this->field_218 & 8)
			{
				this->SetTargetAngleFromPos(&this->field_33C);
			}
			else if (this->field_218 & 16)
			{
				new CAIProc_LookAt(this, MechList, 0, 0, 55, 200);
			}
		case 1:
			if (this->GetToPos(&this->field_33C))
			{
				this->SetHeightMode(5);
				if (!this->DoArrivalAction())
				{
					if (!this->GetNextWaypoint())
						this->field_31C.bothFlags = 1;
					this->dumbAssPad = 0;
				}
			}
			else if ((this->field_218 & 0x10) == 0)
			{
				this->field_35C |= 1u;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @NotOk
// @FIXME: the ApplyPose param, field_188
void CChopper::AimGunPod(void)
{
	if (this->field_3A8.vx)
	{
		CVector v4;
		M3dUtils_GetHookPosition(reinterpret_cast<VECTOR *>(&v4), this, 0);

		CSVector v3;

		Utils_CalcAim(&v3, &v4, &this->field_3A8);
		v3.vy = (v3.vy - this->mAngles.vy) & 0xFFF;

		if (!this->field_188)
			this->ApplyPose(reinterpret_cast<i16*>(0x548F48));

		i16* ptr = static_cast<i16*>(this->field_188);
		ptr[24] = v3.vx;
		ptr[18] = v3.vy;
	}
}

// @NotOk
// @Note: fix ApplyPose and 188
void INLINE CChopper::RotateBlades(void)
{
	if (!this->field_188)
		this->ApplyPose(reinterpret_cast<i16*>(0x1A2BD8));

	u16* ptr = static_cast<u16*>(this->field_188);

	ptr[6] += 35 * this->field_80;
	ptr[6] &= 0xFFF;

	ptr[13] += 35 * this->field_80;
	ptr[13] &= 0xFFF;
}

// @Ok
INLINE void CChopper::SetTargetAngleFromPos(CVector* a2)
{
	CSVector v4;
	v4.vx = 0;
	v4.vy = 0;
	v4.vz = 0;
	Utils_CalcAim(&v4, &this->mPos, a2);
	this->field_360 = v4.vy;
}

// @Ok
i32 INLINE CChopper::GetToPos(CVector* a2)
{
	if (Utils_CrapDist(this->field_330, *a2) < (2 * this->field_348))
		return 1;

	CSVector v6;
	Utils_CalcAim(&v6, &this->field_330, a2);

	i32 v5;
	if (my_abs(this->csVector1.vy) > 0x20)
		v5 = 0;
	else
		v5 = this->field_348 * (32 - my_abs(this->csVector1.vy)) / 32;

	Utils_GetVecFromMagDir(&this->mAccellorVel, v5, &v6);
	return 0;
}

// @Ok
i32 INLINE CChopper::DoWaypointAction(void)
{
	i16 *ptr = gTrigNodes[this->field_1F4];
	if ( ptr[0] == 1002 )
	{
		switch (ptr[1])
		{
			case 1:
				this->field_218 |= 8;
				break;
			case 2:
				this->field_218 &= 0xFFFFFFF7;
				break;
			case 3:
				this->field_218 |= 0x10;
				break;
			case 4:
				this->field_348 = 65;
				break;
			case 5:
				this->field_348 = 45;
				break;
			case 6:
				this->field_348 = 20;
				break;
			default:
				break;
		}
	}

	return 0;
}

// @Ok
i32 INLINE CChopper::DoArrivalAction(void)
{
	i16* ptr = gTrigNodes[this->field_1F4];
	if (ptr[0] == 1002 && ptr[1] == 7)
	{
		this->field_31C.bothFlags = 3;
		this->dumbAssPad = 0;
		return 1;
	}

	return 0;
}

// @Ok
void CChopper::DoChopperPhysics(void)
{
	CVector v15 = this->mAccellorVel;
	CVector v13;
	CVector v14;

	for (i32 i = this->field_80; i; i++)
	{
		this->mAccellorVel += this->gVec;
		this->mAccellorVel %= this->field_78;
		this->mAccellorVel.KillSmall();

		this->field_330 += this->mAccellorVel;
		this->AngleToTargetAngle();
		this->SetHeight();
		
		this->mPos.vx = this->field_330.vx;
		this->mPos.vz = this->field_330.vz;
	}

	v13 = this->mAccellorVel - v15;
	Utils_RotateWorldToObject(this, &v13, &v14);


	if (abs(v14.vz) > 20480)
		this->mAngles.vx = Utils_ShiftFilter(this->mAngles.vx, v14.vz > 0 ? 128 : -128, 5, 16);
	else
		this->mAngles.vx = Utils_ShiftFilter(this->mAngles.vx, 0, 1, 2);

	if (abs(v14.vx) > 20480)
		this->mAngles.vz = Utils_ShiftFilter(this->mAngles.vz, v14.vx > 0 ? -256 : 256, 5, 16);
	else
		this->mAngles.vz = Utils_ShiftFilter(this->mAngles.vz, 0, 1, 2);
	this->field_35C = 0;
}

// @Ok
// @Matching
void CChopper::SetHeight(void)
{
	i32 v2;
	switch(this->field_374)
	{
		case 0:
			break;
		case 2:
			v2 = this->field_330.vy - (this->field_354 >> 12) * rcossin_tbl[this->field_378 & 0xFFF].sin;
			if (this->mPos.vy != v2)
			{
				this->mPos.vy = Utils_ShiftFilter(this->mPos.vy, v2, 1, 12288);
				break;
			}
			this->field_374 = 1;
		case 1:
			this->AdjustSineWaveAmplitude(0x10000, 182);
			this->field_378 += 51;
			this->mPos.vy = this->field_330.vy - (this->field_354 >> 12) * rcossin_tbl[this->field_378 & 0xFFF].sin;
			break;
		case 4:
			this->field_378 = 1024;
			this->field_374 = 3;
		case 3:
			this->AdjustSineWaveAmplitude(0x20000, 364);

			this->mPos.vy = this->field_330.vy +
				Utils_ShiftFilter(this->mPos.vy - this->field_330.vy,
					-this->field_354,
					1,
					12288);
			break;
		case 5:
			this->mPos.vy = this->field_330.vy + Utils_ShiftFilter(
					this->mPos.vy - this->field_330.vy,
					this->field_354,
					1,
					12288);
			if (this->mPos.vy == this->field_330.vy + this->field_354)
			{
				this->field_378 = 3072;
				this->field_374 = 2;
			}
			break;
		default:
			print_if_false(0, "Unknown height mode!");
			break;
	}

}

// @Ok
void CChopper::FireMachineGunAtWaypoint(u32 a2, u32 a3)
{
	Trig_GetPosition(&this->field_33C, a2);
	print_if_false(1u, "Bad register index");
	this->realRegisterArr[0] = a3;
	this->field_31C.bothFlags = 4;
	this->dumbAssPad = 0;
}

// @Ok
void CChopper::FireMissileAtWaypoint(u32 a2)
{
	CVector v10;

	M3dUtils_GetHookPosition(
			reinterpret_cast<VECTOR*>(&v10),
			this,
			this->field_3B4);

	u32 res;
	if ( this->field_3B4 == 9 )
		res = 2;
	else
		res = this->field_3B4 + 1;

	this->field_3B4 = res;

	new CChopperMissile(&v10, this, a2, 0);
}

// @Ok
void CChopper::SetFlag(u16 a2, i16 a3)
{
	if (a2)
		print_if_false(0, "Bad param");
	else
		this->field_380 = a3 != 0;
}

// @Ok
CChopper::~CChopper(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));

	if (this->field_328)
		SFX_Stop(this->field_328);

	if (this->field_324)
		SFX_Stop(this->field_324);
}

// @MEDIUMTODO
void CChopperMissile::AI(void)
{
	printf("void CChopperMissile::AI(void)");
}

// @Ok
// @Matching
void CChopperMissile::Explode(void)
{
	if (this->field_11C)
	{
		Chunk_ChunkItemByChecksum(this->field_11C);
	}

	u32 v2 = Utils_Dist(&this->mPos, &MechList->mPos);

	if (v2 < 0x19A)
	{
		SHitInfo v7;

		v7.field_0 = 6;
		v7.field_4 = 24;

		if ( v2 < 0x118 )
			v7.field_8 = 100;
		else
			v7.field_8 = 100 - 95 * (v2 - 280) / 130;

		MechList->Hit(&v7);
	}

	if (v2 < 0x320 && gSaveGame.field_7B)
	{
		Pad_ActuatorOn(0, 0x3Cu, 1, 0x64u);
	}

	new CGrenadeWave(
			&this->mPos,
			0x80u,
			0x60u,
			0x10u,
			512,
			7);


	this->field_F8->field_54 = 1;
	this->field_F8->mProtected = 0;
	this->field_F8 = 0;
	this->Die();
}

// @BIGTODO
void CChopperMissile::DrawTargetRecticle(void)
{
	printf("void CChopperMissile::DrawTargetRecticle(void)");
}

// @Ok
CChopperMissile::~CChopperMissile(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));

	if (this->field_10C)
		SFX_Stop(this->field_10C);

	if (this->field_F8)
		delete this->field_F8;
}

// @Ok
INLINE i32 CChopperMissile::GetFinalTargetNode(i32 a2)
{
	for (u16 *LinksPointer = Trig_GetLinksPointer(a2);
			LinksPointer;
			LinksPointer = Trig_GetLinksPointer(LinksPointer[1]))
	{
		
		i32 v9 = LinksPointer[1];

		if (*gTrigNodes[v9] != 1002)
			return v9;
	}
	return 0;
}

// @Ok
void CChopperMissile::CommonInitialisation(void)
{
	this->field_38 = 321;

	this->InitItem(gObjFile);
	this->mFlags &= ~2u;
	this->mCBodyFlags &= ~0x10u;

	this->mModel = Spool_GetModel(0x8CEF63CD, gObjFileRegion);
	this->field_DC = 0;
	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));

	this->field_F8 = new CSmokeTrail(&this->mPos, 6, 80, 80, 96);

	this->field_F8->mProtected = 1;
	this->field_F8->SetScale(768);
	
	char v7[16] = "ChopperTarget01";
	this->field_124 = Spool_FindTextureEntry(v7);
	this->field_10C = SFX_PlayPos(0x8001u, &this->mPos, 0);
}

// @Ok
INLINE CChopperMissile::CChopperMissile(
		CVector* a2,
		CSuper* a3,
		i32 a4,
		i32 a5)
{
	this->field_110.vx = 0;
	this->field_110.vy = 0;
	this->field_110.vz = 0;

	this->field_FC = a5;
	this->field_100 = a4;

	this->mPos = *a2;

	Trig_GetPosition(&this->field_110, a4);

	this->field_104 = this->GetFinalTargetNode(a4);

	if (DifficultyLevel == 3)
		this->field_120 = 20;

	this->CommonInitialisation();
}

// @MEDIUMTODO
void CSearchlight::CalculateSearchlight(CSVector*)
{
	printf("CSearchlight::CalculateSearchlight(CSVector*)");
}

// @MEDIUMTODO
void CSearchlight::CheckPointInScreenTri(u32, u32, u32, u32)
{
	printf("CSearchlight::CheckPointInScreenTri(u32, u32, u32, u32)");
}

// @BIGTODO
void CSniperTarget::DrawTargetRecticle(void)
{
	printf("CSniperTarget::DrawTargetRecticle(void)");
}

// @MEDIUMTODO
void CSniperTarget::AI(void)
{
	printf("CSniperTarget::AI(void)");
}

// @BIGTODO
void CMachineGunBullet::Move(void)
{
	printf("CMachineGunBullet::Move(void)");
}

// @MEDIUMTODO
void CMachineGunBullet::Common(CVector*, CVector*)
{
	printf("CMachineGunBullet::Common(CVector*, CVector*)");
}

// @Ok
INLINE CMachineGunBullet::CMachineGunBullet(CVector* a2, CVector* a3)
{
	this->field_5C = 0;
	this->field_60 = 0;
	this->field_64 = 0;

	this->field_68 = 0;
	this->field_6C = 0;
	this->field_70 = 0;

	this->field_80 = 0;
	this->field_82 = 0;
	this->field_84 = 0;

	this->field_A8 = 0;
	this->field_AC = 0;
	this->field_B0 = 0;

	this->Common(a2, a3);

	this->field_A4 = 15;
}

// @Ok
INLINE CMachineGunBullet::CMachineGunBullet(CVector* a2, CVector* a3, CChopper* pChopper)
{
	this->field_5C = 0;
	this->field_60 = 0;
	this->field_64 = 0;

	this->field_68 = 0;
	this->field_6C = 0;
	this->field_70 = 0;

	this->field_80 = 0;
	this->field_82 = 0;
	this->field_84 = 0;

	this->field_A8 = 0;
	this->field_AC = 0;
	this->field_B0 = 0;

	this->Common(a2, a3);

	this->field_94 = Mem_MakeHandle(static_cast<void*>(pChopper));
	this->field_A4 = 5;
}

// @Ok
INLINE CMachineGunBullet::CMachineGunBullet(CVector* a2, CVector* a3, CSniperTarget* pSniper)
{
	this->field_5C = 0;
	this->field_60 = 0;
	this->field_64 = 0;

	this->field_68 = 0;
	this->field_6C = 0;
	this->field_70 = 0;

	this->field_80 = 0;
	this->field_82 = 0;
	this->field_84 = 0;

	this->field_A8 = 0;
	this->field_AC = 0;
	this->field_B0 = 0;

	this->Common(a2, a3);

	this->field_8C = Mem_MakeHandle(static_cast<void*>(pSniper));
	this->field_A4 = 10;
}

// @Ok
CBulletFrag::CBulletFrag(CVector* a2)
{
	this->mPos = *a2;
	this->SetTexture(0xF5A14AFF);
	this->mScale = Rnd(200) + 350;

	i32 v3 = Rnd(4096);
	i32 v4 = Rnd(10) + 10;

	this->mVel.vx = v4 * rcossin_tbl[v3 & FLATBIT_VELOCITIES_MAX_INDEX].sin;
	this->mVel.vz = v4 * rcossin_tbl[v3 & FLATBIT_VELOCITIES_MAX_INDEX].cos;

	this->mVel.vy = -81920 - (Rnd(30) << 12);
	this->field_5A = 500;

	if (Rnd(2))
		this->field_5A *= -1;

	this->mPostScale = 0xC001000;
	this->field_E = Rnd(10) + 10;
}

// @Ok
void CSniperSplat::Move(void)
{
	switch (this->field_84)
	{
		case 0:
			this->field_84 = 1;
			break;
		case 1:
			if (++this->field_C > 30)
				this->field_84 = 2;
			break;
		case 2:
			Bit_ReduceRGB(&this->mTint, 3);
			if (!(0xFFFFFF & this->mTint))
				this->Die();
			break;
		default:
			print_if_false(0, "Bad CSplat mode");
			break;
	}
}

// @Ok
CSniperSplat::CSniperSplat(CVector* a2, SVECTOR* a3)
{
	this->SetTexture(Spool_FindTextureChecksum("WebBall_Crater_01"));
	this->SetTint(64, 64, 64);
	this->SetSubtractiveTransparency();

	i32 first = Rnd(30) + 30;
	i32 second = Rnd(30) + 30;
	i32 third = Rnd(4096);

	this->OrientUsing(a2, a3, first, second, third);

	this->mType = 33;
}

// @Ok
CSniperTarget::~CSniperTarget(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&ControlBaddyList));
}

// @Ok
CSniperTarget::CSniperTarget(i32 a2)
{
	this->field_104.vx = 0;
	this->field_104.vy = 0;
	this->field_104.vz = 0;
	this->field_110 = 0;
	this->field_114 = 0;
	this->field_118 = 0;
	this->field_13C = 0;
	this->field_140 = 0;
	this->field_144 = 0;
	this->field_148 = 0;
	this->field_14C = 0;
	this->field_150 = 0;

	this->field_38 = 323;
	Trig_GetPosition(&this->mPos, a2);

	u16* LinksPointer = Trig_GetLinksPointer(a2);
	print_if_false(*LinksPointer != 0, "No link for snipertarget");

	Trig_GetPosition(&this->field_104, LinksPointer[1]);

	this->field_11C = Spool_FindTextureEntry("snipertarget02");
	this->field_120 = 180;

	this->AttachTo(reinterpret_cast<CBody**>(&ControlBaddyList));
}

// @NotOk
// unknown global
CChopper::CChopper(i16* a2, i32 a3)
{
	this->field_330.vx = 0;
	this->field_330.vy = 0;
	this->field_330.vz = 0;

	this->field_33C.vx = 0;
	this->field_33C.vy = 0;
	this->field_33C.vz = 0;

	this->field_364.vx = 0;
	this->field_364.vy = 0;
	this->field_364.vz = 0;

	this->field_388.vx = 0;
	this->field_388.vy = 0;
	this->field_388.vz = 0;

	this->field_394.vx = 0;
	this->field_394.vy = 0;
	this->field_394.vz = 0;

	this->field_3A8.vx = 0;
	this->field_3A8.vy = 0;
	this->field_3A8.vz = 0;

	this->field_3B8.vx = 0;
	this->field_3B8.vy = 0;
	this->field_3B8.vz = 0;

	this->field_3C8 = 0;
	this->field_3CC = 0;
	this->field_3D0 = 0;


	this->InitItem("chopper");
	this->mFlags |= 4u;

	this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(reinterpret_cast<i32*>(a2))));

	this->field_38 = 318;

	this->field_78.vx = 3;
	this->field_78.vy = 3;
	this->field_78.vz = 3;

	this->mCBodyFlags &= ~0x10u;
	this->field_DC = 0;
	CBody::AttachTo(reinterpret_cast<CBody**>(&BaddyList));

	this->field_1F4 = a3;
	this->field_DE = a3;
	this->field_31C.bothFlags = 0;

	this->field_380 = 1;
	this->field_3B4 = 2;

	this->field_33C = this->mPos;
	this->field_330 = this->field_33C;

	this->field_360 = 2048;
	this->field_358 = 2048;
	this->mAngles.vy = 2048;
	M3dUtils_ReadHooksPacket(this, reinterpret_cast<void*>(0x548F88));
}

// @Ok
void Chopper_CreateChopper(const u32* a1, u32* a2)
{
	i16* v3 = reinterpret_cast<i16*>(a1[0]);
	i32 v4 = a1[1];

	*a2 = reinterpret_cast<u32>(new CChopper(v3, v4));
}


// @Ok
void Chopper_CreateSniper(const u32* a1, u32* a2)
{
	i32 v3 = *a1;

	*a2 = reinterpret_cast<u32>(new CSniperTarget(v3));
}

// @Ok
void Chopper_CreateSearchlight(const u32* a1, u32* a2)
{
	i32 v3 = *a1;

	*a2 = reinterpret_cast<u32>(new CSearchlight(v3));
}

// @MEDIUMTODO
void CSearchlight::SpecialRenderer(void)
{
	printf("CSearchlight::SpecialRenderer(void)");
}

// @Ok
CSearchlight::~CSearchlight(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&ControlBaddyList));
}

// @BIGTODO
void CSearchlight::AI(void)
{
}

// @Ok
CSearchlight::CSearchlight(i32 a2)
{
	this->field_104.vx = 0;
	this->field_104.vy = 0;
	this->field_104.vz = 0;

	this->field_110.vx = 0;
	this->field_110.vy = 0;
	this->field_110.vz = 0;

	this->field_11C.vx = 0;
	this->field_11C.vy = 0;
	this->field_11C.vz = 0;

	for (i32 i = 0; i < 66; i++)
	{
		this->field_138[i].vx = 0;
		this->field_138[i].vy = 0;
		this->field_138[i].vz = 0;
	}

	this->field_38 = 322;
	this->AttachTo(reinterpret_cast<CBody**>(&ControlBaddyList));

	Trig_GetPosition(&this->mPos, a2);
	u16 *LinksPointer = Trig_GetLinksPointer(a2);
	print_if_false(*LinksPointer == 0, "No path for searchlight");

	this->field_F8 = LinksPointer[1];
	Trig_GetPosition(&this->field_104, this->field_F8);

	u16 *OtherLinks = Trig_GetLinksPointer(this->field_F8);
	print_if_false(*OtherLinks == 0, "No path for searchlight");

	this->field_FC = OtherLinks[1];
	Trig_GetPosition(&this->field_110, this->field_FC);

	this->field_11C = (this->field_110 - this->field_104) / 240;
	this->field_100 = 0;
}

// @Ok
INLINE void CChopper::WaitForTrigger(void)
{
	switch (this->dumbAssPad)
	{
		case 0:

			if (this->field_218 & 4)
			{
				this->field_218 &= 0xFB;
				if (this->GetNextWaypoint())
				{
					this->dumbAssPad = 0;
					this->field_31C.bothFlags = 2;
				}
				else
				{
					this->dumbAssPad = 0;
					this->field_31C.bothFlags = 1;
				}
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
	}
}

// @Ok
void CBulletFrag::Move()
{
  this->mPos.vx += this->mVel.vx;
  this->mPos.vy += this->mVel.vy;
  this->mPos.vz += this->mVel.vz;
  this->mVel.vy += 0x7390;

  this->field_58 += this->field_5A;

  if ( ++this->field_C > (i32)(u16)this->field_E )
	  this->Die();
}

// @Ok
INLINE void CChopper::SetHeightMode(int mode)
{
	this->field_374 = mode;
}

// @Ok
INLINE void CSniperTarget::BulletResult(bool result)
{
	this->field_FC++;
	if (result)
		this->field_128 = true;
}

// @Ok
void INLINE CChopper::AdjustSineWaveAmplitude(int a2, int a3)
{
	int tmp = this->field_354;
	if (tmp != a2)
	{
		this->field_354 = Utils_LinearFilter(tmp, a2, a3);
	}
}

// @Ok
void INLINE CChopper::AngleToTargetAngle(void)
{
	i32 v1 = (this->field_360 & 0xFFF) - (this->mAngles.vy & 0xFFF);

	if (v1 > 2048)
	{
		v1 -= 4096;
	}
	else if (v1 < -2048)
	{
		v1 += 4096;
	}


	this->csVector1.vy = v1 >> 5;
	this->mAngles.vy += this->csVector1.vy;
}

void validate_CChopper(void){
	VALIDATE_SIZE(CChopper, 0x3D8);

	VALIDATE(CChopper, field_324, 0x324);
	VALIDATE(CChopper, field_328, 0x328);

	VALIDATE(CChopper, field_32C, 0x32C);

	VALIDATE(CChopper, field_330, 0x330);

	VALIDATE(CChopper, field_33C, 0x33C);

	VALIDATE(CChopper, field_348, 0x348);
	VALIDATE(CChopper, field_34C, 0x34C);

	VALIDATE(CChopper, field_350, 0x350);
	VALIDATE(CChopper, field_354, 0x354);

	VALIDATE(CChopper, field_358, 0x358);
	VALIDATE(CChopper, field_35C, 0x35C);

	VALIDATE(CChopper, field_360, 0x360);
	VALIDATE(CChopper, field_364, 0x364);

	VALIDATE(CChopper, field_370, 0x370);

	VALIDATE(CChopper, field_374, 0x374);
	VALIDATE(CChopper, field_378, 0x378);
	VALIDATE(CChopper, field_37C, 0x37C);

	VALIDATE(CChopper, field_380, 0x380);
	VALIDATE(CChopper, field_384, 0x384);

	VALIDATE(CChopper, field_388, 0x388);

	VALIDATE(CChopper, field_394, 0x394);

	VALIDATE(CChopper, field_3A0, 0x3A0);
	VALIDATE(CChopper, field_3A4, 0x3A4);

	VALIDATE(CChopper, field_3A8, 0x3A8);

	VALIDATE(CChopper, field_3B4, 0x3B4);
	VALIDATE(CChopper, field_3B8, 0x3B8);

	VALIDATE(CChopper, field_3C4, 0x3C4);

	VALIDATE(CChopper, field_3C8, 0x3C8);
	VALIDATE(CChopper, field_3CC, 0x3CC);
	VALIDATE(CChopper, field_3D0, 0x3D0);

	VALIDATE_VTABLE(CChopper, FireMissileAtWaypoint, 17);
	VALIDATE_VTABLE(CChopper, FireMachineGunAtWaypoint, 18);
	VALIDATE_VTABLE(CChopper, SetFlag, 19);
}

void validate_CBulletFrag(void){
	VALIDATE_SIZE(CBulletFrag, 0x68);
}

void validate_CSniperSplat(void){
	VALIDATE_SIZE(CSniperSplat, 0x88);
}

void validate_CSniperTarget(void)
{
	VALIDATE_SIZE(CSniperTarget, 0x15C);

	VALIDATE(CSniperTarget, field_FC, 0xFC);

	VALIDATE(CSniperTarget, field_104, 0x104);
	VALIDATE(CSniperTarget, field_110, 0x110);
	VALIDATE(CSniperTarget, field_114, 0x114);
	VALIDATE(CSniperTarget, field_118, 0x118);
	VALIDATE(CSniperTarget, field_11C, 0x11C);
	VALIDATE(CSniperTarget, field_120, 0x120);

	VALIDATE(CSniperTarget, field_128, 0x128);

	VALIDATE(CSniperTarget, field_13C, 0x13C);
	VALIDATE(CSniperTarget, field_140, 0x140);
	VALIDATE(CSniperTarget, field_144, 0x144);
	VALIDATE(CSniperTarget, field_148, 0x148);
	VALIDATE(CSniperTarget, field_14C, 0x14C);
	VALIDATE(CSniperTarget, field_150, 0x150);

	VALIDATE_VTABLE(CSniperTarget, DrawTargetRecticle, 5);
}

void validate_CSearchlight(void)
{
	VALIDATE_SIZE(CSearchlight, 0x450);

	VALIDATE(CSearchlight, field_F8, 0xF8);
	VALIDATE(CSearchlight, field_FC, 0xFC);
	VALIDATE(CSearchlight, field_100, 0x100);
	VALIDATE(CSearchlight, field_104, 0x104);
	VALIDATE(CSearchlight, field_110, 0x110);
	VALIDATE(CSearchlight, field_11C, 0x11C);
	VALIDATE(CSearchlight, field_138, 0x138);

	VALIDATE_VTABLE(CSearchlight, SpecialRenderer, 5);
}

void validate_CMachineGunBullet(void)
{
	VALIDATE_SIZE(CMachineGunBullet, 0xB8);

	VALIDATE(CMachineGunBullet, field_5C, 0x5C);
	VALIDATE(CMachineGunBullet, field_60, 0x60);
	VALIDATE(CMachineGunBullet, field_64, 0x64);

	VALIDATE(CMachineGunBullet, field_68, 0x68);
	VALIDATE(CMachineGunBullet, field_6C, 0x6C);
	VALIDATE(CMachineGunBullet, field_70, 0x70);

	VALIDATE(CMachineGunBullet, field_80, 0x80);
	VALIDATE(CMachineGunBullet, field_82, 0x82);
	VALIDATE(CMachineGunBullet, field_84, 0x84);

	VALIDATE(CMachineGunBullet, field_8C, 0x8C);
	VALIDATE(CMachineGunBullet, field_94, 0x94);

	VALIDATE(CMachineGunBullet, field_A4, 0xA4);

	VALIDATE(CMachineGunBullet, field_A8, 0xA8);
	VALIDATE(CMachineGunBullet, field_AC, 0xAC);
	VALIDATE(CMachineGunBullet, field_B0, 0xB0);
}

void validate_CChopperMissile(void)
{
	VALIDATE_SIZE(CChopperMissile, 0x128);

	VALIDATE(CChopperMissile, field_F8, 0xF8);

	VALIDATE(CChopperMissile, field_FC, 0xFC);
	VALIDATE(CChopperMissile, field_100, 0x100);
	VALIDATE(CChopperMissile, field_104, 0x104);

	VALIDATE(CChopperMissile, field_10C, 0x10C);

	VALIDATE(CChopperMissile, field_110, 0x110);
	VALIDATE(CChopperMissile, field_11C, 0x11C);

	VALIDATE(CChopperMissile, field_120, 0x120);
	VALIDATE(CChopperMissile, field_124, 0x124);

	VALIDATE_VTABLE(CChopperMissile, DrawTargetRecticle, 5);
}
