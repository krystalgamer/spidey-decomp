#include "spidey.h"
#include "validate.h"
#include "mem.h"
#include "camera.h"
#include "screen.h"
#include "ps2funcs.h"
#include <cmath>
#include "ps2lowsfx.h"
#include "ps2redbook.h"
#include "utils.h"
#include "m3dutils.h"
#include "bit.h"
#include "trig.h"
#include "m3dcolij.h"
#include "m3dzone.h"
#include "ps2lowsfx.h"
#include "spool.h"
#include "DXinit.h"
#include "my_assert.h"

// @Ok
EXPORT i16 gSpideyFloorCamXOffset;
// @Ok
EXPORT i16 gSpideyFloorCamYOffset;
// @Ok
EXPORT i16 gSpideyFloorCamZOffset;

// @Ok
EXPORT i16 gSpideyFloorCamXZDistance;
// @Ok
EXPORT i16 gSpideyFloorCamYDistance;

// @Ok
EXPORT i16 gSpideySwingCamXOffset;
// @Ok
EXPORT i16 gSpideySwingCamYOffset;
// @Ok
EXPORT i16 gSpideySwingCamZOffset;

// @Ok
EXPORT i16 gSpideySwingCamXZDistance;
// @Ok
EXPORT i16 gSpideySwingCamYDistance;

// @Ok
EXPORT i16 gSpideyWallCamXOffset;
// @Ok
EXPORT i16 gSpideyWallCamYOffset;
// @Ok
EXPORT i16 gSpideyWallCamZOffset;

// @Ok
EXPORT i16 gSpideyWallCamXZDistance;

// @Ok
EXPORT i16 gSpideyWallCamYDistance;


// @Ok
EXPORT u8 gSpideyVramProcessing;

// @Ok
EXPORT SAnimFrame *gSpideyAnim;

// @Ok
EXPORT SAnimFrame *gSpideyAnimTwo;

// @Ok
EXPORT i16 gSpideyFallingCamXOff;
// @Ok
EXPORT i16 gSpideyFallingCamYOff;
// @Ok
EXPORT i16 gSpideyFallingCamZOff;

// @Ok
EXPORT i16 gSpideyFallingCamXZDist;
// @Ok
EXPORT i16 gSpideyFallingCamYDist;


// @Ok
EXPORT SLight M3d_PlayerLight =
{

  { { -2430, -2228, -2430 }, { 2509, -2896, 1447 }, { -648, -3711, -1607 } },

  0,
  { { 3200, 1040, 2048 }, { 2720, 1600, 1920 }, { 2400, 2560, 2048 } },
  0,

  { 1800, 1800, 1440 }
};


CItem* SpideyAdditionalBodyPartsList;
CItem* MiscellaneousRenderingList;

u8 gSpideyPsxIndex;
CPlayer* MechList;
extern i32 CurrentSuit;

EXPORT i32* gPlayerAnimRelated[1];
EXPORT void *gSpideyHeadModel;

extern CCamera* CameraList;

// @IGNOREME
void CPlayer::nullsub_one(i32)
{
	printf("void CPlayer::nullsub_one(i32)");
}

// @Ok
void Bruce_Sync(void)
{
	print_if_false(MechList != 0, "NULL pointer");
	MechList->field_D3C = MechList->mPos;
	MechList->field_D4E = MechList->mAngles;
}

// @MEDIUMTODO
void CPlayer::AI(void)
{
    printf("CPlayer::AI(void)");
}

// @Ok
// @NotMatching: the light assingment does not match, didn't care enough
void CPlayer::AdjustBrightness(u16 a2)
{
	// @Ok - according to PPC it's a static variable
	static u32 gPlayerBrightness = -1;
	if (this->field_570 < a2)
	{
		this->field_570 += 8 * this->field_80;

		if (this->field_570 > a2)
		{
			this->field_570 = a2;
		}
	}
	else if (this->field_570 > a2)
	{
		this->field_570 -= 8 * this->field_80;

		if (this->field_570 > a2)
		{
			this->field_570 = a2;
		}
	}

	u32 v5 = this->field_570;
	if (gPlayerBrightness != v5)
	{
		M3d_PlayerLight.ColorMatrix[0][0] = (3200 * v5) >> 8;
		M3d_PlayerLight.ColorMatrix[0][1] = (1040 * v5) >> 8;
		M3d_PlayerLight.ColorMatrix[0][2] = 8 * v5;

		M3d_PlayerLight.ColorMatrix[1][0] = (2720 * v5) >> 8;
		M3d_PlayerLight.ColorMatrix[1][1] = (1600 * v5) >> 8;
		M3d_PlayerLight.ColorMatrix[1][2] = (1920 * v5) >> 8;

		M3d_PlayerLight.ColorMatrix[2][0] = (2400 * v5) >> 8;
		M3d_PlayerLight.ColorMatrix[2][1] = 10 * v5;
		M3d_PlayerLight.ColorMatrix[2][2] = 8 * v5;

		M3d_PlayerLight.BackColor[0] = (1800 * v5) >> 8;
		M3d_PlayerLight.BackColor[1] = (1800 * v5) >> 8;
		M3d_PlayerLight.BackColor[2] = (1440 * v5) >> 8;
		gPlayerBrightness = v5;
	}
}

// @MEDIUMTODO
void CPlayer::BuildOffscreenSpideySenseIndicatorList(void)
{
    printf("CPlayer::BuildOffscreenSpideySenseIndicatorList(void)");
}

// @MEDIUMTODO
CPlayer::CPlayer(void)
{
    printf("CPlayer::CPlayer(void)");
}

// @Ok
// @Test
i32 CPlayer::CalculateIntermediateTrailSteps(CVector *a2,CVector * a3,CVector * a4)
{
	u32 v8 = Utils_Dist(a3, a2) >> 5;
	if (v8 > 1)
		v8 = 1;

	i32 len_a3 = a3->Length();
	i32 len_a2 = a2->Length();

	CVector v18;
	switch (v8)
	{
		case 0:
			return 0;
		case 1:

			v18.vx = a3->vx + (a2->vx - a3->vx) / 2;
			v18.vy = a3->vy + (a2->vy - a3->vy) / 2;
			v18.vz = a3->vz + (a2->vz - a3->vz) / 2;

			v8 >>= 8;
			VectorNormal(
					reinterpret_cast<VECTOR*>(&v18),
					reinterpret_cast<VECTOR*>(&v18));

			v18 *= (len_a3 + len_a2) / 2;

			*a4 = (v18 + this->mPos);
			return 1;
		default:
			return 0;
	}
}

// @Ok
// @Test
void CPlayer::CalculateSwingWebParameters(CVector * a2)
{
	VECTOR v3;
	VECTOR v4;
	VECTOR v5;
	v5.vx = (this->mPos.vx - a2->vx) >> 12;
	v5.vy = (this->mPos.vy - a2->vy) >> 12;
	v5.vz = (this->mPos.vz - a2->vz) >> 12;
	VectorNormal(&v5, &v5);
	gte_ldopv1(&v5);
	gte_ldopv2(reinterpret_cast<VECTOR*>(&this->field_DA0));
	gte_op12();
	gte_stlvnl(&v4);
	VectorNormal(&v4, &v4);
	gte_ldopv1(&v5);
	gte_ldopv2(&v4);
	gte_op12();
	gte_stlvnl(&v3);

	this->field_D80.vx = v4.vx;
	this->field_D86.vx = v4.vy;
	this->field_D8C.vx = v4.vz;
	this->field_D80.vy = v5.vx;
	this->field_D86.vy = v5.vy;
	this->field_D8C.vy = v5.vz;
	this->field_D80.vz = v3.vx;
	this->field_D86.vz = v3.vy;
	this->field_D8C.vz = v3.vz;
	this->field_DB8 = abs(v5.vy);
}

// @SMALLTODO
void CPlayer::CalculateTugWebPathPoints(void)
{
    printf("CPlayer::CalculateTugWebPathPoints(void)");
}

// @Ok
// @AlmostMatching: SetTargetTorsoAngleToThisPoint arg pushed one instruction earlier
u8 CPlayer::CheckCeilingJumpingSmashPunch(void)
{
	if (this->field_8EA || !this->field_8E9 && !this->field_8E8)
	{
		return 0;
	}

	if (!this->field_DCC)
	{
		return 0;
	}

	// @FIXME
	u8 *v3 = reinterpret_cast<u8*>(this->field_E0C);
	if (!v3[289] && !v3[305])
	{
		return 0;
	}

	CVector v17 = (this->field_DCC->mPos - this->mPos) >> 12;
	VectorNormal(
			reinterpret_cast<VECTOR*>(&v17),
			reinterpret_cast<VECTOR*>(&v17));

	this->field_AE4 = 0;
	this->field_A8.vx = 0;
	this->field_A8.vy = -4096;
	this->field_A8.vz = 0;

	this->OrientToNormal(0, &ZeroVector);

	this->field_AD4 = 0;
	this->field_8DC = 0;
	this->field_8CC = this->field_DCC->mPos;

	this->SetTargetTorsoAngleToThisPoint(&this->field_8CC);

	this->field_E1C = 0x1000000;
	this->field_8C8 = this->field_8C4;
	this->field_8C4 = gTimerRelated;
	this->field_8D8 = 0;

	// @FIXME
	if (reinterpret_cast<u8*>(this->field_E0C)[289])
		this->PlaySingleAnim(133, 0, -1);
	else
		this->PlaySingleAnim(129, 0, -1);

	return 1;
}

// @MEDIUMTODO
void CPlayer::CheckExteriorSurfaceTransition(void)
{
    printf("CPlayer::CheckExteriorSurfaceTransition(void)");
}

// @SMALLTODO
void CPlayer::CheckFenceSurfaceTransition(void)
{
    printf("CPlayer::CheckFenceSurfaceTransition(void)");
}

// @MEDIUMTODO
void CPlayer::CheckForwards(bool)
{
    printf("CPlayer::CheckForwards(bool)");
}

// @Ok
i32 CPlayer::CheckGroundGone(void)
{
	if (!(this->mCollision & 2))
	{
		if ( this->field_EA4 )
			this->field_EA4--;

		if (this->field_EA4)
			return 0;

		if ( this->mHeldObject )
		{
			CVector v11 = (4 * this->field_C84);
			this->mHeldObject->Drop(&v11);
			this->mHeldObject = 0;
		}

		this->field_E38 = this->mPos.vy;
		this->PlaySingleAnim(212, 0, -1);

		this->field_E8C = 0;
		this->field_AE5 = 0;
		this->field_AE6 = 0;
		if ( this->field_AD4 )
		{
			this->field_AD4 = 0;
			this->field_A8.vx = 0;
			this->field_A8.vy = -4096;
			this->field_A8.vz = 0;

			CVector v11;
			v11.vx = 0;
			v11.vy = 0;
			v11.vz = 4096;
			this->OrientToNormal(true, &v11);
		}

		this->field_E1C = 4;

		return 1;
	}

	return 0;
}

// @MEDIUMTODO
void CPlayer::CheckInteriorSurfaceTransition(void)
{
    printf("CPlayer::CheckInteriorSurfaceTransition(void)");
}

// @MEDIUMTODO
void CPlayer::CheckJump(void)
{
    printf("CPlayer::CheckJump(void)");
}

// @MEDIUMTODO
void CPlayer::CheckJumpingR1ZipWeb(void)
{
    printf("CPlayer::CheckJumpingR1ZipWeb(void)");
}

// @MEDIUMTODO
void CPlayer::CheckJumpingR2ZipWeb(void)
{
    printf("CPlayer::CheckJumpingR2ZipWeb(void)");
}

// @MEDIUMTODO
void CPlayer::CheckJumpingSmashKick(void)
{
    printf("CPlayer::CheckJumpingSmashKick(void)");
}

// @MEDIUMTODO
void CPlayer::CheckJumpingSwingWeb(void)
{
    printf("CPlayer::CheckJumpingSwingWeb(void)");
}

// @MEDIUMTODO
void CPlayer::CheckKick(void)
{
    printf("CPlayer::CheckKick(void)");
}

// @MEDIUMTODO
void CPlayer::CheckLanded(void)
{
    printf("CPlayer::CheckLanded(void)");
}

// @NotOk
// fix type
i32 CPlayer::CheckRunIntoWall(void)
{
	if ( this->mHeldObject )
		return 0;

	u8 v3 = 1;

	if (this->mCollision & 1)
	{
		if ( this->field_B84.vy <= 3400
				&& this->field_B74
				&& this->field_B84.vy >= -2600
				// @FIXME
				&& !(this->field_B8C[3] & 0x40000))
		{

			if (((this->field_C6C.vx - this->field_B84.vx) >> 12) +
					((this->field_C6C.vy - this->field_B84.vy) >> 12) +
					((this->field_C6C.vz - this->field_B84.vz) >> 12) > 3800)
			{
				v3 = 0;
				this->field_AD7 += this->field_80;
			}

			if (this->field_AD7 > 0x14)
			{
				this->field_AD7 = 0;
				this->PlaySingleAnim(14, 0, -1);
				this->field_E1C = 0x80000;
				return 1;
			}
		}

	}

	if (v3)
		this->field_AD7 = 0;
	return 0;
}

// @Ok
i32 CPlayer::CheckStickToCeiling(void)
{
	if ( this->mVel.vy > 0
		|| !(this->mCollision & 0x100)
		|| !this->field_C18
		|| !(reinterpret_cast<u8*>(this->field_E0C)[256])
		|| this->field_C28.vy <= 3400
		|| this->field_C30[3] & 0x40000)
	{
		return 0;
	}

	this->field_AD4 = 1;
	this->field_A8 = this->field_C28;
	this->field_AC8 = this->field_C6C;
	this->OrientToNormal(true, &this->field_AC8);

	this->field_E88 = 0;
	this->field_E84 = 0;

	this->mPos = this->field_C1C;
	this->mPos.vx += this->field_A8.vx * this->field_EA8;
	this->mPos.vy += this->field_A8.vy * this->field_EA8;
	this->mPos.vz += this->field_A8.vz * this->field_EA8;

	if ( this->mAnim == 232 )
		this->PlaySingleAnim(234, 0, -1);
	else
		this->PlaySingleAnim(227, 0, -1);

	if (this->field_E1C & 0x300)
		CameraList->field_12C = -1;

	this->field_E1C = 1;
	SFX_Play(9u, 0x2000, 0);
	this->field_AE5 = 0;
	this->field_54C = 0;

	return 1;
}

// @MEDIUMTODO
void CPlayer::CheckStickToWall(void)
{
    printf("CPlayer::CheckStickToWall(void)");
}

// @MEDIUMTODO
void CPlayer::CheckSwingWebAvailability(SLineInfo *)
{
    printf("CPlayer::CheckSwingWebAvailability(SLineInfo *)");
}

// @SMALLTODO
void CPlayer::CheckSwitchToGrabbedMode(CVector const *,CVector *)
{
    printf("CPlayer::CheckSwitchToGrabbedMode(CVector const *,CVector *)");
}

// @MEDIUMTODO
void CPlayer::CheckWebShot(void)
{
    printf("CPlayer::CheckWebShot(void)");
}

// @SMALLTODO
void CPlayer::CheckZipWebAvailability(SLineInfo *,i32)
{
    printf("CPlayer::CheckZipWebAvailability(SLineInfo *,i32)");
}

// @Ok
void CPlayer::CollideWithObject(CBody* a2)
{
	CVector v8;

	v8 = (this->mPos - a2->mPos) >> 6;
	VectorNormal(
			reinterpret_cast<VECTOR*>(&v8),
			reinterpret_cast<VECTOR*>(&v8));

	i32 v5 = v8.vz * (this->mVel.vz >> 6) + v8.vx * (this->mVel.vx >> 6);
	if (v5 <= 0)
	{
		v5 >>= 12;
		this->mVel.vx -= (v5 * v8.vx) >> 6;
		this->mVel.vz -= (v5 * v8.vz) >> 6;
	}
}

// @MEDIUMTODO
void CPlayer::CreateCombatImpactEffect(CVector *,i32)
{
    printf("CPlayer::CreateCombatImpactEffect(CVector *,i32)");
}

// @MEDIUMTODO
void CPlayer::CreateWebDrips(bool,bool)
{
    printf("CPlayer::CreateWebDrips(bool,bool)");
}

// @MEDIUMTODO
void CPlayer::DoMGSShadow(void)
{
    printf("CPlayer::DoMGSShadow(void)");
}

// @MEDIUMTODO
void CPlayer::DoShadowCheck(void)
{
    printf("CPlayer::DoShadowCheck(void)");
}

// @MEDIUMTODO
void CPlayer::DrawOffscreenSpideySenseIndicatorList(void)
{
    printf("CPlayer::DrawOffscreenSpideySenseIndicatorList(void)");
}

// @MEDIUMTODO
void CPlayer::DrawReticle(u16,u16,u32)
{
    printf("CPlayer::DrawReticle(u16,u16,u32)");
}

// @MEDIUMTODO
void CPlayer::EnterLookaroundMode(void)
{
    printf("CPlayer::EnterLookaroundMode(void)");
}

// @MEDIUMTODO
void CPlayer::FireWeb(bool,i32,CVector *,bool,CSVector *)
{
    printf("CPlayer::FireWeb(bool,i32,CVector *,bool,CSVector *)");
}

// @SMALLTODO
void CPlayer::GetComboFrameInfoPointer(u16)
{
    printf("CPlayer::GetComboFrameInfoPointer(u16)");
}

// @SMALLTODO
void CPlayer::GetComboPartsInfoPointer(u16)
{
    printf("CPlayer::GetComboPartsInfoPointer(u16)");
}

// @Ok
// @Matching
i32 CPlayer::GetDamageInflictedFromDifficulty(i32 a2)
{
	if (CurrentSuit == 2 || CurrentSuit == 3 || CurrentSuit == 4)
	{
		a2 *= 2;
	}

	if (DifficultyLevel != 2)
	{
		if (!DifficultyLevel)
		{
			return a2 << 13 >> 12;
		}

		i32 dmg = a2 * 3;

		if (DifficultyLevel == 1)
		{
			return dmg << 11 >> 12;
		}

		return dmg << 10 >> 12;
	}

	return a2;
}

// @SMALLTODO
void CPlayer::GetEnterExitFrameInfoPointer(u16)
{
    printf("CPlayer::GetEnterExitFrameInfoPointer(u16)");
}

// @Ok
// @Matching
i32 CPlayer::GetFreeIndicatorListEntry(void)
{
	for (i32 i = 0; i < 6; i++)
	{
		if (!this->field_5F0[i].field_C.field_0)
		{
			this->field_5F0[i].mInUse = 0;
			return i;
		}
	}

	return -1;
}

// @Ok
INLINE i32* CPlayer::GetNewCommandBlock(u32 a1)
{
	i32* res = static_cast<i32*>(DCMem_New(4 * a1, 0, 1, 0, 1));
	res[a1 - 1] = 0;

	if (!this->field_1BC)
	{
		this->field_1BC = res;
	}
	else
	{
		i32* it = this->field_1BC;
		while (1)
		{
			if (!it[it[1] - 1])
				break;

			it = reinterpret_cast<i32*>(it[it[1] - 1]);
		}

		it[it[1] - 1] = reinterpret_cast<i32>(res);
	}

	return res;
}

// @SMALLTODO
void CPlayer::GetPerpendicularisationRadius(void)
{
    printf("CPlayer::GetPerpendicularisationRadius(void)");
}

// @MEDIUMTODO
void CPlayer::GrabUpdate(CVector *,i16 *)
{
    printf("CPlayer::GrabUpdate(CVector *,i16 *)");
}

// @SMALLTODO
void CPlayer::HandleControlsForSurfaceTransition(bool)
{
    printf("CPlayer::HandleControlsForSurfaceTransition(bool)");
}

// @MEDIUMTODO
i32 CPlayer::Hit(SHitInfo *)
{
    printf("CPlayer::Hit(SHitInfo *)");
    return 0x04082024;
}

// @Ok
// @matching
u8 CPlayer::IfPlayerCeilingCheck(i32 a2, i32 a3)
{
	DoAssert(a2 <= a3, "Bad min and max for C_IF_PLAYER_CEILING_CHECK");
	if (!this->field_8EA || this->field_CB4)
	{
		if (this->mPos.vy >= a2 && this->mPos.vy <= a3)
		{
			if (this->field_8E9 || this->field_8E8 && this->field_B84.vy > 3400)
			{
				return 1;
			}
		}
	}

	return 0;
}

// @Ok
// @Matching
i32 CPlayer::IncHealth(i32 a2)
{
	if (this->mHealth < this->mMaxHealth && this->mHealth > 0)
	{
		this->mHealth += a2;

		if (this->mHealth > this->mMaxHealth)
		{
			this->mHealth = this->mMaxHealth;
		}

		this->field_5E0 = gTimerRelated;
		this->field_5D0++;
		return 1;
	}

	return 0;
}

// @SMALLTODO
void CPlayer::InitialiseOffscreenSpideySenseIndicatorList(void)
{
    printf("CPlayer::InitialiseOffscreenSpideySenseIndicatorList(void)");
}

// @SMALLTODO
void CPlayer::InitialiseSFXArray(void)
{
    printf("CPlayer::InitialiseSFXArray(void)");
}

// @MEDIUMTODO
void CPlayer::InitiateCombo(u16,i32)
{
    printf("CPlayer::InitiateCombo(u16,i32)");
}

// @Ok
// @Matching
u8 CPlayer::IsInIndicatorList(SHandle &a2)
{
	for (i32 i = 0; i < 6; i++)
	{
		if (this->field_5F0[i].field_C.field_0 && this->field_5F0[i].field_C.field_4 == a2.field_4)
		{
			return 1;
		}
	}

	return 0;
}

// @SMALLTODO
void CPlayer::KnockSpideyFromCrawlPosition(void)
{
    printf("CPlayer::KnockSpideyFromCrawlPosition(void)");
}

// @SMALLTODO
void CPlayer::LockTargetTorsoAngle(void)
{
    printf("CPlayer::LockTargetTorsoAngle(void)");
}

// @MEDIUMTODO
void CPlayer::NotifyKill(u16)
{
    printf("CPlayer::NotifyKill(u16)");
}

// @MEDIUMTODO
void CPlayer::ParseFightData(void)
{
    printf("CPlayer::ParseFightData(void)");
}

// @SMALLTODO
void CPlayer::ProcessSFXArray(void)
{
    printf("CPlayer::ProcessSFXArray(void)");
}

// @MEDIUMTODO
void CPlayer::ReadAnalogueInput(void)
{
    printf("CPlayer::ReadAnalogueInput(void)");
}

// @SMALLTODO
void CPlayer::SelectAutoAimTarget(void)
{
    printf("CPlayer::SelectAutoAimTarget(void)");
}

// @SMALLTODO
void CPlayer::SelectTargetBaddy(i32,i32,i32,i32)
{
    printf("CPlayer::SelectTargetBaddy(i32,i32,i32,i32)");
}

// @MEDIUMTODO
void CPlayer::SelectTargetSwitch(i32,i32,SHandle *,i32,i32)
{
    printf("CPlayer::SelectTargetSwitch(i32,i32,SHandle *,i32,i32)");
}

// @Ok
EXPORT u8 gSpideyArmorSet;

// @Ok
// @Matching
u8 CPlayer::SetArmor(bool a2)
{
	gSpideyAnimTwo = 0;
	if (a2)
	{
		gSpideyAnimTwo = Spool_FindAnim("costarm", 1);
		switch (DifficultyLevel)
		{
			case 0:
				this->field_5EC = 600;
				break;
			case 1:
				this->field_5EC = 200;
				break;
			case 2:
				this->field_5EC = 100;
				break;
			case 3:
				this->field_5EC = 80;
				break;
			default:
				break;
		}
	}

	if (a2 && gSpideyArmorSet)
	{
		return 1;
	}

	if (!a2 && !gSpideyArmorSet)
	{
		return 1;
	}

	Spidey_DoArmorVRAMProcessing(a2);
	this->field_5E9 = a2;
	gSpideyArmorSet = a2;

	return 1;
}

// @SMALLTODO
void CPlayer::SetCeilingCamera(i32)
{
    printf("CPlayer::SetCeilingCamera(i32)");
}

// @Ok
// @Matching
void CPlayer::SetFloorCamera(i32 a3)
{
	CCamera *pCamera = CameraList;
	if (pCamera)
	{
		if (pCamera->mCameraMode == 3)
		{
			pCamera->SetCamXOffset(gSpideyFloorCamXOffset, a3);
			pCamera->SetCamYOffset(gSpideyFloorCamYOffset, a3);
			pCamera->SetCamZOffset(gSpideyFloorCamZOffset, a3);
			pCamera->SetCamXZDistance(gSpideyFloorCamXZDistance, a3);
			pCamera->SetCamYDistance(gSpideyFloorCamYDistance, a3);
			this->field_540 = 0;
		}
	}
}

// @SMALLTODO
void CPlayer::SetFirstContactDetails(void)
{
	if (!this->field_354)
	{
		this->field_354 = 1;
		this->field_358 = this->mHealth;
		this->field_35C = gTimerRelated;
	}
}

// @Ok
// @Matching
void CPlayer::SetFallingCamera(i32 a3)
{
	CCamera *pCamera = CameraList;
	if (pCamera->mCameraMode == 3)
	{
		pCamera->SetCamXOffset(gSpideyFallingCamXOff, a3);
		pCamera->SetCamYOffset(gSpideyFallingCamYOff, a3);
		pCamera->SetCamZOffset(gSpideyFallingCamZOff, a3);

		pCamera->SetCamXZDistance(gSpideyFallingCamXZDist, a3);
		pCamera->SetCamYDistance(gSpideyFallingCamYDist, a3);

		this->field_540 = 5;
	}
}

// @Ok
// @Matching
void CPlayer::SetFocusLockTarget(const CBody *a2)
{
	this->hLockTarget = Mem_MakeHandle(const_cast<CBody*>(a2));
}

// @MEDIUMTODO
void CPlayer::SetSpideyCamValue(u16,u16,i16,u16,u16)
{
    printf("CPlayer::SetSpideyCamValue(u16,u16,i16,u16,u16)");
}

// @Ok
// @matching
void CPlayer::SetSwingCamera(i32 a3)
{
	CCamera *pCamera = CameraList;
	if (pCamera->mCameraMode == 3)
	{
		pCamera->SetCamXOffset(gSpideySwingCamXOffset, a3);
		pCamera->SetCamYOffset(gSpideySwingCamYOffset, a3);
		pCamera->SetCamZOffset(gSpideySwingCamZOffset, a3);
		pCamera->SetCamXZDistance(gSpideySwingCamXZDistance, a3);
		pCamera->SetCamYDistance(gSpideySwingCamYDistance, a3);
		this->field_540 = 4;
	}
}

// @Ok
// @Matching
void CPlayer::SetWallCamera(i32 a3)
{
	CCamera *pCamera = CameraList;
	if (pCamera->mCameraMode == 3)
	{
		pCamera->SetCamXOffset(gSpideyWallCamXOffset, a3);
		pCamera->SetCamYOffset(gSpideyWallCamYOffset, a3);
		pCamera->SetCamZOffset(gSpideyWallCamZOffset, a3);
		pCamera->SetCamXZDistance(gSpideyWallCamXZDistance, a3);
		pCamera->SetCamYDistance(gSpideyWallCamYDistance, a3);
		this->field_540 = 1;
	}
}

// @MEDIUMTODO
void CPlayer::SetupLookaroundCamera(void)
{
    printf("CPlayer::SetupLookaroundCamera(void)");
}

// @Ok
// @Matching
u8 CPlayer::ShouldPlayerDropFlail(void)
{
	return Utils_GetGroundHeight(&this->mPos, 0, 4096, 0) != -1;
}

// @SMALLTODO
void CPlayer::SortAnimationFollowOnData(void)
{
    printf("CPlayer::SortAnimationFollowOnData(void)");
}

// @SMALLTODO
void CPlayer::SortFistsData(void)
{
    printf("CPlayer::SortFistsData(void)");
}

// @MEDIUMTODO
void CPlayer::SwitchToDeathMode(bool)
{
    printf("CPlayer::SwitchToDeathMode(bool)");
}

// @SMALLTODO
void CPlayer::SwitchToSynthesizedInput(i16 *)
{
    printf("CPlayer::SwitchToSynthesizedInput(i16 *)");
}

// @MEDIUMTODO
void CPlayer::SynthesizeAnalogueInput(void)
{
    printf("CPlayer::SynthesizeAnalogueInput(void)");
}

// @MEDIUMTODO
void CPlayer::UpdateAndTrackCombo(void)
{
    printf("CPlayer::UpdateAndTrackCombo(void)");
}

// @SMALLTODO
void CPlayer::UpdateOffscreenSpideySenseIndicatorList(void)
{
    printf("CPlayer::UpdateOffscreenSpideySenseIndicatorList(void)");
}

// @MEDIUMTODO
void CPlayer::UpdateTrails(void)
{
    printf("CPlayer::UpdateTrails(void)");
}

// @MEDIUMTODO
CPlayer::~CPlayer(void)
{
    printf("CPlayer::~CPlayer(void)");
}

// @SMALLTODO
void Spidey_BagHead(i32,i32)
{
    printf("Spidey_BagHead(i32,i32)");
}

// @Ok
// @Matching
INLINE void Spidey_DoArmorVRAMProcessing(bool a1)
{
	if (gLowGraphics)
	{
		if ((a1 && gSpideyVramProcessing) || (!a1 && !gSpideyVramProcessing))
		{
		   return;
		}

		if (a1)
		{
			Spidey_SwapSuitTextures(CurrentSuit, 0);
		}
		else
		{
			Spidey_SwapSuitTextures(0, CurrentSuit);
		}

		
		gSpideyVramProcessing = !gSpideyVramProcessing;
	}
}

// @Ok
// @Matching
void Spidey_LoadAlternativeHealthIcon(i32 a1)
{
	gSpideyAnimTwo = 0;
	gSpideyAnim = 0;
	switch ( a1 )
	{
		case 2:
			Spool_PSX("cost99", 0);
			gSpideyAnim = Spool_FindAnim("cost99", 1);
			break;
		case 3:
		case 9:
			Spool_PSX("costblk", 0);
			gSpideyAnim = Spool_FindAnim("costblk", 1);
			break;
		case 4:
			Spool_PSX("costcapt", 0);
			gSpideyAnim = Spool_FindAnim("costcapt", 1);
			break;
		case 6:
			Spool_PSX("costbag", 0);
			gSpideyAnim = Spool_FindAnim("costbag", 1);
			break;
		case 7:
			Spool_PSX("costscar", 0);
			gSpideyAnim = Spool_FindAnim("costscar", 1);
			break;
		case 10:
			Spool_PSX("costpete", 0);
			gSpideyAnim = Spool_FindAnim("costpete", 1);
			break;
		default:
			break;
	}
}

// @MEDIUMTODO
void Spidey_LoadAlternativeTextureSet(u32 const *,i32)
{
    printf("Spidey_LoadAlternativeTextureSet(u32 const *,i32)");
}

// @SMALLTODO
void Spidey_StoreTextureEntry(Texture const *,i16,i16)
{
    printf("Spidey_StoreTextureEntry(Texture const *,i16,i16)");
}

// @SMALLTODO
void Spidey_SwapSuitTextures(i32,i32)
{
    printf("Spidey_SwapSuitTextures(i32,i32)");
}

// @SMALLTODO
void spideyLog(char *,...)
{
    printf("spideyLog(char *,...)");
}

// @MEDIUMTODO
// understand ppModels
void Spidey_CopyHeadModel(i32 Region)
{
	// @FIXME
	return;

	if (!gSpideyHeadModel)
	{
		u16 * ptr = reinterpret_cast<u16*>(PSXRegion[Region].ppModels[7]);
		u16 size = ptr[1];

		u16* result = static_cast<u16*>(DCMem_New(8 * size, 1, 1, 0, 1));
		gSpideyHeadModel = static_cast<void*>(result);

		for (u16 *i = &reinterpret_cast<u16*>(ptr)[14];
				size-- != 0;
				i += 4)
		{
			result[0] = i[0];
			result[1] = i[1];
			result[2] = i[2];
			result[3] = i[3];

			result += 4;
		}

	}
}

// @Ok
void Spidey_FreeHeadModel(void)
{
	Mem_Delete(static_cast<void*>(gSpideyHeadModel));
	gSpideyHeadModel = 0;
}

// @Ok
u8 CPlayer::IncreaseWebbing(i32 amount)
{
	if (this->mHealth <= 0)
		return 0;

	i32 v3 = 10;
	if (CurrentSuit == 6 || CurrentSuit == 9 || CurrentSuit == 10)
		v3 = 2;

	if ( (this->mWebbing >= 4096 || this->field_5E8) && this->field_5D8 >= v3)
		return 0;

	this->mWebbing += amount;

	if (this->mWebbing > 4096)
	{
		if (this->field_5D8 < v3)
		{
			this->field_5D8++;
			this->mWebbing -= 4096;
			this->field_5DC = gTimerRelated;
			this->field_5D0++;
			return 1;
		}

		this->mWebbing = 4096;
	}

	this->field_5D0++;
	return 1;
}

// @Ok
void CPlayer::SetStartOrientation(CSVector* pVector)
{
	SVECTOR a1;
	MATRIX a2;

	a1.vx = 0;
	a1.vy = pVector->vy;
	a1.vz = 0;

	M3dMaths_RotMatrixYXZ(&a1, &a2);
	MulMatrix(&this->mTransform, &a2);
	this->OrientToNormal(0, &ZeroVector);
}

// @NotOk
// validate later
void CPlayer::CreateFists(unsigned char a2)
{
	if (a2 & 1)
	{
		this->field_194 &= 0xFFFFFFDF;
		this->field_194 |= 0x40;
	}
	else
	{
		this->field_194 &= 0xFFFFFFBF;
		this->field_194 |= 0x20;
	}

	if (a2 & 2)
	{
		this->field_194 &= 0xFFFFFBFF;
		this->field_194 |= 0x800;
	}
	else
	{
		this->field_194 &= 0xFFFFF7FF;
		this->field_194 |= 0x400;
	}
}

// @Ok
void CPlayer::SetIgnoreInputTimer(int a2)
{
	this->field_E18 = a2;
	if (a2)
	{
		this->field_E12 = this->mAnimSpeed;
		if (this->field_8EA)
		{
			this->ExitLookaroundMode();
		}
	}
}

// @Ok
void CPlayer::SetCamAngleLock(u16 a1)
{
	if (a1)
	{
		this->gCamAngleLock = 0;
	}
	else
	{
		this->gCamAngleLock = 1;
	}
}

static CCamera * const gGlobalThisCamera = (CCamera*)0x69696969;
static int * const dword_660F80 = (int*)0x660F80;
static int * const dword_60F76C = (int*)0x60F76C;

// @NotOk
// globals need to replace
void CPlayer::ExitLookaroundMode(void)
{
	if (this->field_8EA)
	{
		int c90 = this->field_C90;
		this->field_CB4 = 0;
		this->field_CE4 = 0;
		this->field_56C = 0;
		this->field_8EA = 0;

		*dword_660F80 = 0;
		*dword_60F76C = 0;


		if (c90)
		{
			Mem_Delete(reinterpret_cast<void*>(c90));
			this->field_C90 = 0;
		}

		gGlobalThisCamera->PopMode();
		this->PutCameraBehind(0);
		this->field_DE4 = 0;
		Screen_TargetOn(false);

		i16 *v3 = reinterpret_cast<i16*>(this->field_188);
		if (v3)
		{
			v3[6] = 0;
			v3[7] = 0;
			v3[18] = 0;
			v3[19] = 0;
		}
	}
}

static int * const dword_6A81FC = (int*)0x6A81FC;
static int * const dword_6A8208 = (int*)0x6A8208;
static int * const dword_6A8260 = (int*)0x6A8260;

// @NotOk
// Remove globals, there's an extra test for some reason
void CPlayer::SetSpideyLookaroundCamValue(u16 a1, u16 a2, i16 a3)
{
	u32 actualA1 = a1;
	if (actualA1)
	{
		actualA1--;
		if (actualA1)
		{
			actualA1--;
			if (!actualA1)
			{
				if (a2)
				{
					print_if_false(0, "Bad spidey cam param type");
				}
				else
				{
					*dword_6A8208 = a3;
				}
			}
		}
		else
		{
			if (a2)
			{
				print_if_false(0, "Bad spidey cam param type");
			}
			else
			{
				*dword_6A81FC = a3;
			}
		}

	}
	else if (a2)
	{
		print_if_false(0, "Bad spidey cam param type");
	}
	else
	{
		*dword_6A8260 = a3;
	}
}

// @Ok
// slightly different register allocation
void CPlayer::SetTargetTorsoAngleToThisPoint(CVector *a2)
{
	gte_SetRotMatrix(&this->field_89C);


	CVector v8;
	v8.vx = (a2->vx - this->mPos.vx) >> 12;
	v8.vy = (a2->vy - this->mPos.vy) >> 12;
	v8.vz = (a2->vz - this->mPos.vz) >> 12;

	gte_ldlvl(reinterpret_cast<VECTOR*>(&v8));
	gte_rtir();
	gte_stlvnl(reinterpret_cast<VECTOR*>(&v8));

	i16 v6 = (1024 - ratan2(-v8.vz, -v8.vx)) & 0xFFF;

	i16 v7;
	if (this->field_8E9)
	{
		v7 = this->GetEffectiveHeading() - v6;
	}
	else
	{
		v7 = this->GetEffectiveHeading() + v6;
	}

	this->SetTargetTorsoAngle(v7 & 0xFFF, 0);
}

// @Ok
i16 CPlayer::GetEffectiveHeading(void)
{ 
	if (!this->field_8E8)
	{
		return (1024 - ratan2(this->field_C6C.vz, this->field_C6C.vx)) & 0xFFF;
	}

	CVector fourth;
	fourth.vx = 0;
	fourth.vy = -4096;
	fourth.vz = 0;

	CVector second;
	second.vx = 0;
	second.vy = 0;
	second.vz = 0;

	gte_ldopv1(reinterpret_cast<VECTOR*>(&fourth));
	gte_ldopv2(reinterpret_cast<VECTOR*>(&this->field_C84));
	gte_op12();
	gte_stlvnl(reinterpret_cast<VECTOR*>(&second));
	VectorNormal(reinterpret_cast<VECTOR*>(&second), reinterpret_cast<VECTOR*>(&second));

	CVector first;
	first.vx = 0;
	first.vy = 0;
	first.vz = 0;

	gte_ldopv1(reinterpret_cast<VECTOR*>(&second));
	gte_ldopv2(reinterpret_cast<VECTOR*>(&this->field_C84));
	gte_op12();
	gte_stlvnl(reinterpret_cast<VECTOR*>(&first));

	first.vx = -first.vx;
	first.vy = -first.vy;
	first.vz = -first.vz;

	gte_SetRotMatrix(&this->field_89C);
	gte_ldlvl(reinterpret_cast<VECTOR*>(&first));
	gte_rtir();

	CVector third;
	third.vx = 0;
	third.vy = 0;
	third.vz = 0;

	gte_stlvnl(reinterpret_cast<VECTOR*>(&third));

	return (ratan2(third.vz, third.vx) + 1024) & 0xFFF;
}

// @MEDIUMTODO
void CPlayer::SetTargetTorsoAngle(i16, int)
{
	printf("void CPlayer::SetTargetTorsoAngle(i16, int)");
}


static i32 * const dword_60CFE8 = (i32*)0x60CFE8;
static i32 * const dword_54D474 = (i32*)0x54D474;
static char * const byte_682770 = (char*)0x682770;
extern int CurrentSuit;

// @NotOk
// Globals
// The part with >> 12 has a jump in the original rather than it's perfect
char CPlayer::DecreaseWebbing(i32 a2)
{
	if (!this->field_1AC &&
			!*dword_60CFE8 &&
			CurrentSuit != 3 &&
			CurrentSuit != 4)
	{
		int v3;
		int v4;

		int tmpDword = *dword_54D474;
		if (!tmpDword)
		{
			v3 = a2 << 7;
			v4 = v3 >> 12;
		}
		else if (tmpDword == 1)
		{
			v3 = a2 << 11;
			v4 = v3 >> 12;
		}

		int v5 = this->mWebbing;
		if (v5 > v4)
		{
			this->mWebbing = v5 - v4;
			return 1;
		}

		int v7 = this->field_5D8;
		if (v7)
		{
			this->mWebbing = v5 - v4 + 4096;
			this->field_5D8 = v7 - 1;
			SFX_PlayPos(0x1E, &this->mPos, 0);
			this->field_5E8 = 0;
			return 1;
		}

		if (!this->field_E10)
		{
			if (!*byte_682770)
			{
				Redbook_XAPlay(33, Rnd(3) + 2, 0);
			}

			this->field_5E8 = 0;
			return 0;
		}

		return 1;
	}

	return 1;
}


static CVector * const stru_56F1B4 = (CVector*)0x56F1B4;
static MATRIX * const stru_56F224 = (MATRIX*)0x56F224;

// @NotOk
// Globals
// Can be optimized (remove tmp)
// gte_ldlv0 is dangerous it reads more memory than needed
void CPlayer::RenderLookaroundReticle(void)
{
	if (this->field_DE4)
	{

		CVector tmp = *stru_56F1B4;
		CVector vec  = (this->field_DC0 >> 12) - tmp;
		
		gte_SetRotMatrix(stru_56F224);
		m3d_ZeroTransVector();
		gte_ldlv0(reinterpret_cast<VECTOR*>(&vec));
		gte_rtps();

		int v5;
		gte_stlvnl2(&v5);

		i16 v6[2];
		gte_stsxy(reinterpret_cast<i32*>(v6));

		i32 v3 = 3072 - v5;
		if (v3 < 768)
		{
			v3 = 768;
		}

		this->DrawRecticle(v6[0], v6[1], v3);
	}
}

// @BIGTODO
void CPlayer::DrawRecticle(u16, u16, u32)
{
	printf("void CPlayer::DrawRecticle(unsigned __int16, unsigned __int16, unsigned int)");
}


// @Ok
// instead of sub 0x1000 we do add 0xFFFFF000, dunno why
// also abs is different but wtv
void CPlayer::SetTargetTorsoAngle(i16 a2, bool a3)
{
	int v4 = (a2 & 0xFFF);
	i16 EffectiveHeading = this->GetEffectiveHeading();

	if ( (i16)v4 == EffectiveHeading)
	{
		this->field_DF8 = 0;
		return;
	}

	i32 v6 = this->field_E1C;
	if (v6 & 6)
		this->field_DF8 = 5 * this->field_DFC;
	else
		this->field_DF8 = 10;


	if (v6 & 0x2000000)
		this->field_DF8 <<= 1;

	this->field_DF0 = v4;

	i32 v7;
	if (v4 > EffectiveHeading)
	{
		v7 = v4 - EffectiveHeading;
		if ( v7 >= 2048 )
			v7 = (i16)(v4 - 0x1000) - EffectiveHeading;
	}
	else
	{
		i32 v8 = EffectiveHeading;
		if ( EffectiveHeading - v4 >= 2048 )
			v8 = (i16)(EffectiveHeading - 0x1000);
		v7 = v4 - v8;
	}

	int v9 = this->field_DF8;
	int v10 = v7 / v9;
	bool v11 = this->field_AD4 == 0;
	this->field_DF4 = v7 / v9;
	int v12 = 384;
	if ( v11 )
		v12 = 512;
	int v13 = v12 / v9;
	if ( a3 )
		v13 <<= 1;
	if ( v10 > v13 )
	{
		this->field_DF4 = v13;
		this->field_DF8 = abs(v7 / v13);
	}
	if ( this->field_DF4 < -v13 )
	{
		this->field_DF4 = -v13;
		this->field_DF8 = abs(v7 / v13);
	}
}

static i16 * const word_6A8C66 = (i16*)0x6A8C66;
static i16 * const word_610C4A = (i16*)0x610C4A;
static i16 * const word_610C48 = (i16*)0x610C48;

// @NotOk
// globals
void CPlayer::PutCameraBehind(i32 a2)
{
	if (!this->gCamAngleLock)
	{
		if (!this->field_8E8)
		{
			gGlobalThisCamera->SetCamAngle(this->GetEffectiveHeading(), a2);
		}
		else
		{
			int v5 = (1024 - ratan2(this->field_C84.vz, this->field_C84.vx)) & 0xFFF;
			gGlobalThisCamera->SetCamAngle(v5, a2);

			if (gGlobalThisCamera->mCameraMode == CAMERAMODE_DEMO)
			{
				if ((this->field_E2E | this->field_E2D) && this->field_E1C == 16)
				{
					i32 v6 = 2 * (this->field_E2D & 0xFFF);
					gGlobalThisCamera->SetCamYDistance(*word_6A8C66 + ((500 * word_6A8C66[v6]) >> 12), a2);
					gGlobalThisCamera->SetCamAngle(v5 + ((700 * word_610C48[v6]) >> 12), a2);
				}
				else
				{
					gGlobalThisCamera->SetCamYDistance(*word_6A8C66, a2);
				}
			}
		}


	}
}


// @NotOk
// not matching become smoke trai lhas no cosntructor so it's inlined af
void CPlayer::CreateJumpingSmashKickTrail(void)
{
	CVector vec;
	vec.vx = 0;
	vec.vy = 0;
	vec.vz = 0;

	if (!this->field_584)
	{
		M3dUtils_GetHookPosition(reinterpret_cast<VECTOR*>(&vec),
				this,
				5);

		int args = this->field_580;
		CSmokeTrail *smokeTrail = new CSmokeTrail(
				&vec,
				4,
				args,
				*(reinterpret_cast<unsigned char*>(&args) + 2),
				*(reinterpret_cast<unsigned char*>(&args) + 1));

		this->field_584 = smokeTrail;
	}

	if (!this->field_588)
	{
		M3dUtils_GetHookPosition(reinterpret_cast<VECTOR*>(&vec),
				this,
				6);

		int args = this->field_580;
		CSmokeTrail *smokeTrail = new CSmokeTrail(
				&vec,
				4,
				static_cast<unsigned char>(args),
				*(reinterpret_cast<unsigned char*>(&args) + 2),
				*(reinterpret_cast<unsigned char*>(&args) + 1));

		this->field_588 = smokeTrail;
	}
}


// @Ok
// @Matching
INLINE void CPlayer::PlaySingleAnim(int a2, int a3, int a4)
{

	i32* v4 = gPlayerAnimRelated[a2];

	this->field_350 = reinterpret_cast<i32>(v4);

	if (this->field_350)
	{
		for (i32 i = *v4; i != -1; v4++, i = *v4)
		{
			*v4 = i & 0xFFFFF;
		}
	}

	CSuper::RunAnim(a2, a3, a4);
}

// @BIGTODO
void CPlayer::OrientToNormal(bool, CVector*)
{
	printf("CPlayer::OrientToNormal");
}

// @BIGTODO
void CPlayer::PriorToVenomDistanceAttack(CVector)
{}

// @BIGTODO
void CPlayer::SwitchToStandMode(void)
{}

// @NotOk
// Globals
// raw memory accesses
void CPlayer::CutSceneSkipCleanup(void)
{
	Redbook_XAStop();

	if (gGlobalThisCamera->mCameraMode != CAMERAMODE_DEMO && Trig_GetLevelId() != 514)
	{
		gGlobalThisCamera->SetMode(static_cast<ECameraMode>(3));
	}

	int v3 = this->field_1A8;
	CVector v14;
	v14.vx = 0;
	v14.vy = 0;
	v14.vz = 0;


	if (v3)
	{
		int* ptr = reinterpret_cast<int*>(Trig_GetLinksPointer(v3));
		if (ptr[0])
		{
			Trig_GetPosition(&v14, ptr[1]);

			v14.vy = 0;
			v14.vx = (this->mPos.vx - v14.vx) >> 12;
			v14.vz = (this->mPos.vz - v14.vz) >> 12;
			VectorNormal(
					reinterpret_cast<VECTOR*>(&v14),
					reinterpret_cast<VECTOR*>(&v14));

			this->field_A8.vx = 0;
			this->field_A8.vy = -4096;
			this->field_A8.vz = 0;
		}
		else
		{
			v14 = this->field_C6C;
		}

		this->PriorToVenomDistanceAttack(v14);
	}

	this->PlaySingleAnim(0, 0, -1);
	this->SwitchToStandMode();
	gGlobalThisCamera->SetStartPosition();

	char * v13 = reinterpret_cast<char*>(this->field_E0C);
	*(v13  + 256) = 1;
	*(v13  + 48) = 1;

}

// @NotOk
// globals
// variables
void CPlayer::TidyUpZipWebLandingPosition(int a2)
{
	SLineInfo v21;

	int v2 = 0;

	v21.MinCoords.vx = 0;
	v21.MinCoords.vy = 0;
	v21.MinCoords.vz = 0;

	v21.MaxCoords.vx = 0;
	v21.MaxCoords.vy = 0;
	v21.MaxCoords.vz = 0;

	v21.Position.vx = 0;
	v21.Position.vy = 0;
	v21.Position.vz = 0;

	v21.Normal.vx = 0;
	v21.Normal.vy = 0;
	v21.Normal.vz = 0;

	int i = 0;
	do
	{
		int y = this->mPos.vy;
		int v6 = 2 * (i & 0xFFF);

		int v7 = word_610C4A[v6];
		int v8 = word_610C48[v6];

		int v9 = v2 * (((this->field_C78 * v7) >> 12) + ((this->field_C6C.vx * v8) >> 12));
		int v10 = this->field_C7C * v7;
		int v11 = this->field_C80 * v7;

		v21.StartCoords.vx = v9 + this->mPos.vx;
		int v12 = (v10 >> 12) + ((this->field_C6C.vy * v8) >> 12);
		v2 = a2;
		int v13 = a2 * v12;
		int v14 = (v11 >> 12) + ((this->field_C6C.vz * v8) >> 12);
		int z = this->mPos.vz;

		int v16 = a2 * v14;
		v21.StartCoords.vy = v13 + y;
		v21.StartCoords.vz = v16 + z;
		v21.EndCoords.vx = this->mPos.vx - v9;

		int v17 = this->mPos.vy;
		v21.EndCoords.vy = v17 - v13;
		v21.EndCoords.vz = z - v16;
		M3dColij_InitLineInfo(&v21);
		M3dZone_LineToItem(&v21, 1);
		if (v21.pItem)
		{
			int v18 = a2 * v21.Normal.vz;
			int v19 = v17 + a2 * v21.Normal.vy;
			this->mPos.vx += a2 * v21.Normal.vx;
			this->mPos.vy = v19;
			this->mPos.vz = z + v18;
		}

		i += 512;
	}while(i<4096);
}

static const char* gUserFunctionName;
static unsigned int gUserFunctionSize;

// @NotOk
// global
void Spidey_SetUserFunction(const char *a1, unsigned int a2)
{
	gUserFunctionName = a1;
	gUserFunctionSize = a2;
}

// @Ok
unsigned char CPlayer::CanITalkRightNow(void)
{
	if (this->field_E1C & 0x800080)
		return 0;
	return 1;
}

// @Ok
unsigned char CPlayer::SetFireWebbing(void)
{
	this->field_5E8 = 1;
	this->mWebbing = 4096;
	this->field_5D0++;
	return 1;
}

// @Ok
void INLINE CPlayer::GetHookPosition(CVector* a2, unsigned char a3)
{
	M3dUtils_GetHookPosition(reinterpret_cast<VECTOR*>(a2), this, a3);
}

// @NotOk
// revisit without casts
void CPlayer::DestroyJumpingSmashKickTrail(void)
{
	if (this->field_584)
	{
		int *tmp = reinterpret_cast<int*>(this->field_584);
		tmp[21] = 1;
		this->field_584 = NULL;
	}

	if (this->field_588)
	{
		int *tmp = reinterpret_cast<int*>(this->field_588);
		tmp[21] = 1;
		this->field_588 = NULL;
	}
}

// @NotOk
// revisit without casts
void CPlayer::DestroyHandTrails(void)
{
	if (this->field_58C)
	{
		int *tmp = reinterpret_cast<int*>(this->field_58C);
		tmp[21] = 1;
		this->field_58C = NULL;
	}

	if (this->field_590)
	{
		int *tmp = reinterpret_cast<int*>(this->field_590);
		tmp[21] = 1;
		this->field_590 = NULL;
	}
}

// @Ok
void CPlayer::DeleteStuff(void)
{
	Screen_TargetOn(false);
	if (this->field_C90)
	{
		Mem_Delete(reinterpret_cast<void*>(this->field_C90));
		this->field_C90 = 0;
	}
}

// @Ok
void CPlayer::StopAlertMusic(void)
{
	this->field_52C = 0;
	this->field_528 = 0;
	if (this->field_538)
	{
		SFX_Stop(this->field_538);
		this->field_538 = 0;
	}
}

// @Ok
INLINE i32* CPlayer::KillCommandBlock(i32* a1)
{
	i32* res = reinterpret_cast<i32*>(a1[a1[1]-1]);

	if (this->field_1BC == a1)
	{
		this->field_1BC = res;
	}
	else
	{
		i32* it = this->field_1BC;

		while (it)
		{
			if (a1 == reinterpret_cast<i32*>(it[it[1]-1]))
			{
				it[it[1]-1] = reinterpret_cast<i32>(res);
				break;
			}

			it = reinterpret_cast<i32*>(it[it[1]-1]);
		}
	}

	Mem_Delete(reinterpret_cast<void*>(a1));
	return res;
}

// @NotOk
// Revisit
void CPlayer::KillAllCommandBlocks(void)
{
	for (int* cur = reinterpret_cast<int*>(this->field_1BC); cur; cur = this->KillCommandBlock(cur));
	this->field_1BC = 0;
}

// @Ok
void CPlayer::Die(void)
{
	if (!this->IsDead())
	{
		this->mCBodyFlags |= 0x40;
		this->mFlags |= 1;
	}
}

void validate_CPlayer(void)
{
	VALIDATE_SIZE(CPlayer, 0xEFC);

	VALIDATE(CPlayer, field_194, 0x194);

	VALIDATE(CPlayer, field_1A8, 0x1A8);
	VALIDATE(CPlayer, field_1AC, 0x1AC);

	VALIDATE(CPlayer, field_1BC, 0x1BC);

	VALIDATE(CPlayer, field_350, 0x350);

	VALIDATE(CPlayer, field_354, 0x354);
	VALIDATE(CPlayer, field_358, 0x358);
	VALIDATE(CPlayer, field_35C, 0x35C);

	VALIDATE(CPlayer, field_528, 0x528);
	VALIDATE(CPlayer, field_52C, 0x52C);
	VALIDATE(CPlayer, field_530, 0x530);

	VALIDATE(CPlayer, field_538, 0x538);

	VALIDATE(CPlayer, field_540, 0x540);

	VALIDATE(CPlayer, field_54C, 0x54C);

	VALIDATE(CPlayer, field_568, 0x568);
	VALIDATE(CPlayer, field_56C, 0x56C);

	VALIDATE(CPlayer, field_570, 0x570);

	VALIDATE(CPlayer, field_57C, 0x57C);

	VALIDATE(CPlayer, field_580, 0x580);

	VALIDATE(CPlayer, field_584, 0x584);
	VALIDATE(CPlayer, field_588, 0x588);

	VALIDATE(CPlayer, field_58C, 0x58C);
	VALIDATE(CPlayer, field_590, 0x590);

	VALIDATE(CPlayer, field_5E9, 0x5E9);
	VALIDATE(CPlayer, field_5EC, 0x5EC);

	VALIDATE(CPlayer, field_5F0, 0x5F0);

	VALIDATE(CPlayer, field_5D0, 0x5D0);
	VALIDATE(CPlayer, mWebbing, 0x5D4);
	VALIDATE(CPlayer, field_5D8, 0x5D8);
	VALIDATE(CPlayer, field_5DC, 0x5DC);

	VALIDATE(CPlayer, field_5E0, 0x5E0);

	VALIDATE(CPlayer, field_5E8, 0x5E8);

	VALIDATE(CPlayer, field_89C, 0x89C);

	VALIDATE(CPlayer, field_8C4, 0x8C4);
	VALIDATE(CPlayer, field_8C8, 0x8C8);

	VALIDATE(CPlayer, field_8CC, 0x8CC);

	VALIDATE(CPlayer, field_8D8, 0x8D8);
	VALIDATE(CPlayer, field_8DC, 0x8DC);

	VALIDATE(CPlayer, field_8E8, 0x8E8);
	VALIDATE(CPlayer, field_8E9, 0x8E9);
	VALIDATE(CPlayer, field_8EA, 0x8EA);

	VALIDATE(CPlayer, gCamAngleLock, 0x8EC);

	VALIDATE(CPlayer, field_AC8, 0xAC8);

	VALIDATE(CPlayer, field_AD4, 0xAD4);

	VALIDATE(CPlayer, field_AD7, 0xAD7);

	VALIDATE(CPlayer, field_AE4, 0xAE4);
	VALIDATE(CPlayer, field_AE5, 0xAE5);
	VALIDATE(CPlayer, field_AE6, 0xAE6);


	VALIDATE(CPlayer, field_B74, 0xB74);
	VALIDATE(CPlayer, field_B84, 0xB84);
	VALIDATE(CPlayer, field_B8C, 0xB8C);

	VALIDATE(CPlayer, field_C18, 0xC18);
	VALIDATE(CPlayer, field_C1C, 0xC1C);
	VALIDATE(CPlayer, field_C28, 0xC28);


	VALIDATE(CPlayer, field_C30, 0xC30);


	VALIDATE(CPlayer, field_C6C, 0xC6C);

	VALIDATE(CPlayer, field_C78, 0xC78);
	VALIDATE(CPlayer, field_C7C, 0xC7C);
	VALIDATE(CPlayer, field_C80, 0xC80);
	VALIDATE(CPlayer, field_C84, 0xC84);

	VALIDATE(CPlayer, field_C90, 0xC90);
	VALIDATE(CPlayer, field_CB4, 0xCB4);
	VALIDATE(CPlayer, field_CE4, 0xCE4);

	VALIDATE(CPlayer, field_D3C, 0xD3C);
	VALIDATE(CPlayer, field_D4E, 0xD4E);

	VALIDATE(CPlayer, field_D80, 0xD80);
	VALIDATE(CPlayer, field_D86, 0xD86);
	VALIDATE(CPlayer, field_D8C, 0xD8C);

	VALIDATE(CPlayer, field_DA0, 0xDA0);

	VALIDATE(CPlayer, field_DB8, 0xDB8);

	VALIDATE(CPlayer, field_DC0, 0xDC0);
	VALIDATE(CPlayer, field_DCC, 0xDCC);

	VALIDATE(CPlayer, field_DE4, 0xDE4);


	VALIDATE(CPlayer, field_DF0, 0xDF0);
	VALIDATE(CPlayer, field_DF4, 0xDF4);
	VALIDATE(CPlayer, field_DF8, 0xDF8);
	VALIDATE(CPlayer, field_DFC, 0xDFC);

	VALIDATE(CPlayer, field_E00, 0xE00);
	VALIDATE(CPlayer, field_E0C, 0xE0C);

	VALIDATE(CPlayer, field_E10, 0xE10);
	VALIDATE(CPlayer, field_E12, 0xE12);
	VALIDATE(CPlayer, field_E18, 0xE18);
	VALIDATE(CPlayer, field_E1C, 0xE1C);

	VALIDATE(CPlayer, field_E2D, 0xE2D);
	VALIDATE(CPlayer, field_E2E, 0xE2E);

	VALIDATE(CPlayer, field_E38, 0xE38);

	VALIDATE(CPlayer, hLockTarget, 0xE70);

	VALIDATE(CPlayer, field_E84, 0xE84);
	VALIDATE(CPlayer, field_E88, 0xE88);
	VALIDATE(CPlayer, field_E8C, 0xE8C);

	VALIDATE(CPlayer, mHeldObject, 0xE48);

	VALIDATE(CPlayer, field_EA4, 0xEA4);

	VALIDATE(CPlayer, field_EA8, 0xEA8);

	VALIDATE(CPlayer, mMaxHealth, 0xEF0);
}

void validate_SIndicator(void)
{
	VALIDATE_SIZE(SIndicator, 0x68);

	VALIDATE(SIndicator, field_C, 0xC);

	VALIDATE(SIndicator, mInUse, 0x64);
}
