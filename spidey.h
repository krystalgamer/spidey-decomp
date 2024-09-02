#pragma once


#ifndef SPIDEY_H
#define SPIDEY_H

#include "export.h"
#include "ob.h"
#include "manipob.h"

class CPlayer : public CSuper 
{
	public:

		int field_194;
		unsigned char padAfter194[0x1A8-0x194-4];

		int field_1A8;
		char field_1AC;
		unsigned char padAfter1AC[0x1BC-0x1AC-1];

		int* field_1BC;
		unsigned char padAfter1BC[0x350-0x1BC-4];

		i32 field_350;
		u8 padAfter350[0x528-0x350-4];

		int field_528;
		int field_52C;
		unsigned char padAfter52C[0x538-0x52C-4];

		u32 field_538;
		u8 padAfter538[0x54C-0x538-4];

		u8 field_54C;
		u8 padAfter54C[0x568-0x54C-4];

		i32 field_568;
		i32 field_56C;
		u8 padAfter56C[0x57C-0x56C-4];

		i8 field_57C;
		u8 padAfter57C[0x580-0x57C-1];

		i32 field_580;
		CSmokeTrail* field_584;
		CSmokeTrail* field_588;
		CSmokeTrail* field_58C;
		CSmokeTrail* field_590;
		unsigned char padAfter584[0x5D0-0x590-4];


		i32 field_5D0;
		i32 mWebbing;
		i32 field_5D8;
		i32 field_5DC;
		u8 padAfter5DC[0x5E8-0x5DC-4];

		char field_5E8;
		unsigned char padAfter5E8[0x89C-0x5E8-4];

		MATRIX field_89C;
		unsigned char padAfter89C[0x8E8-0x89C-sizeof(MATRIX)];

		unsigned char field_8E8;
		unsigned char field_8E9;
		unsigned char field_8EA;
		unsigned char padAFter8Ea;

		unsigned char gCamAngleLock; //8EC
		u8 padAfterLock[0xAC8-0x8EC-1];

		CVector field_AC8;

		u8 field_AD4;
		u8 padAfterAD4[0xAD7-0xAD4-1];

		u8 field_AD7;
		u8 padAfterAD7[0xAE5-0xAD7-1];

		u8 field_AE5;
		u8 field_AE6;
		u8 padAfterAE6[0xB74-0xAE6-1];

		i32 field_B74;
		u8 padAfterB74[0xB84-0xB74-4];

		CSVector field_B84;
		u8 padAfterB84[0xB8C-0xB84-sizeof(CSVector)];

		// @FIXME guess the type
		i32* field_B8C;
		u8 padAfterB8C[0xC18-0xB8C-4];

		i32 field_C18;
		CVector field_C1C;
		CSVector field_C28;
		u8 padAfterC28[2];


		// @FIXME
		i32* field_C30;
		u8 padAfterC30[0xC6C-0xC30-4];

		CVector field_C6C;
		i32 field_C78;
		i32 field_C7C;
		i32 field_C80;
		CVector field_C84;
		int field_C90;
		unsigned char padAfterC90[0xCB4-0xC90-4];

		i32 field_CB4;
		unsigned char padAfterCB4[0xCE4-0xCB4-4];

		i32 field_CE4;
		u8 padAfterCE4[0xD3C-0xCE4-4];

		CVector field_D3C;
		u8 padAfterD3C[((0xD4E)-0xD3C)-sizeof(CVector)];

		CSVector field_D4E;
		u8 padAfterD4E[(0xD80-(0xD4E))-sizeof(CSVector)];

		CSVector field_D80;
		CSVector field_D86;
		CSVector field_D8C;
		u8 padAfterD8C[0xDA0-0xD8C-sizeof(CSVector)];

		CVector field_DA0;
		u8 padAfterDA0[0xDB8-0xDA0-sizeof(CVector)];

		i32 field_DB8;
		u8 padAfterDB8[0xDC0-0xDB8-4];

		CVector field_DC0;
		unsigned char padAfterDC0[0xDE4-0xDC0-sizeof(CVector)];

		char field_DE4;
		unsigned char padAfterDE4[0xDF0-0xDE4-1];

		int field_DF0;
		int field_DF4;

		int field_DF8;
		int field_DFC;

		int field_E00;
		unsigned char padAfterE00[0xE0C-0xE00-4];

		int field_E0C;
		char field_E10;
		__int16 field_E12;
		unsigned char padAfterE12[4];

		int field_E18;
		i32 field_E1C;
		unsigned char padAfterE1C[0xE2D-0xE1C-4];

		char field_E2D;
		char field_E2E;
		u8 padAfterE2E[(0xE38-0xE2E)-0x1];

		i32 field_E38;
		u8 padAfterE38[(0xE48-0xE38)-0x4];

		CManipOb* mHeldObject;
		u8 padAfterE48[0xE84-0xE48-4];

		i32 field_E84;
		i32 field_E88;

		u8 field_E8C;
		u8 padAfterE8C[0xEA4-0xE8C-1];


		u8 field_EA4;
		u8 padAFterEA4[(0xEA8-0xEA4)-0x1];

		i16 field_EA8;
		u8 padBottomPlayer[(0xEFC-0xEA8)-0x2];


		EXPORT void SetCamAngleLock(unsigned __int16);
		EXPORT void ExitLookaroundMode(void);
		EXPORT void SetIgnoreInputTimer(int);
		EXPORT void PutCameraBehind(int);
		EXPORT void SetSpideyLookaroundCamValue(unsigned __int16, unsigned __int16, __int16);
		EXPORT void SetTargetTorsoAngleToThisPoint(CVector *a2);

		EXPORT __int16 GetEffectiveHeading(void);
		EXPORT void SetTargetTorsoAngle(__int16, int);
		EXPORT char DecreaseWebbing(int);
		EXPORT void RenderLookaroundReticle(void);
		EXPORT void DrawRecticle(unsigned __int16, unsigned __int16, unsigned int);
		EXPORT void SetTargetTorsoAngle(__int16, bool);
		EXPORT void CreateJumpingSmashKickTrail(void);
		EXPORT void PlaySingleAnim(int, int, int);
		EXPORT void CutSceneSkipCleanup(void);
		EXPORT void OrientToNormal(bool, CVector*);
		EXPORT void PriorToVenomDistanceAttack(CVector);
		EXPORT void SwitchToStandMode(void);
		EXPORT void TidyUpZipWebLandingPosition(int);
		EXPORT void CreateFists(unsigned char);
		EXPORT unsigned char CanITalkRightNow(void);
		EXPORT unsigned char SetFireWebbing(void);
		EXPORT void GetHookPosition(CVector*, unsigned char);
		EXPORT void DestroyJumpingSmashKickTrail(void);
		EXPORT void DestroyHandTrails(void);
		EXPORT void DeleteStuff(void);
		EXPORT void StopAlertMusic(void);
		EXPORT void KillAllCommandBlocks(void);
		EXPORT i32* KillCommandBlock(i32*);
		EXPORT void Die(void);
		EXPORT void SetStartOrientation(CSVector*);
		EXPORT u8 IncreaseWebbing(i32);

		EXPORT void AI(void);
		EXPORT void AdjustBrightness(u16);
		EXPORT void BuildOffscreenSpideySenseIndicatorList(void);
		EXPORT CPlayer(void);
		EXPORT i32 CalculateIntermediateTrailSteps(CVector *,CVector *,CVector *);
		EXPORT void CalculateSwingWebParameters(CVector *);
		EXPORT void CalculateTugWebPathPoints(void);
		EXPORT void CheckCeilingJumpingSmashPunch(void);
		EXPORT void CheckExteriorSurfaceTransition(void);
		EXPORT void CheckFenceSurfaceTransition(void);
		EXPORT void CheckForwards(bool);
		EXPORT i32 CheckGroundGone(void);
		EXPORT void CheckInteriorSurfaceTransition(void);
		EXPORT void CheckJump(void);
		EXPORT void CheckJumpingR1ZipWeb(void);
		EXPORT void CheckJumpingR2ZipWeb(void);
		EXPORT void CheckJumpingSmashKick(void);
		EXPORT void CheckJumpingSwingWeb(void);
		EXPORT void CheckKick(void);
		EXPORT void CheckLanded(void);
		EXPORT i32 CheckRunIntoWall(void);
		EXPORT i32 CheckStickToCeiling(void);
		EXPORT void CheckStickToWall(void);
		EXPORT void CheckSwingWebAvailability(SLineInfo *);
		EXPORT void CheckSwitchToGrabbedMode(CVector const *,CVector *);
		EXPORT void CheckWebShot(void);
		EXPORT void CheckZipWebAvailability(SLineInfo *,i32);
		EXPORT void CollideWithObject(CBody *);
		EXPORT void CreateCombatImpactEffect(CVector *,i32);
		EXPORT void CreateWebDrips(bool,bool);
		EXPORT void DoMGSShadow(void);
		EXPORT void DoShadowCheck(void);
		EXPORT void DrawOffscreenSpideySenseIndicatorList(void);
		EXPORT void DrawReticle(u16,u16,u32);
		EXPORT void EnterLookaroundMode(void);
		EXPORT void FireWeb(bool,i32,CVector *,bool,CSVector *);
		EXPORT void GetComboFrameInfoPointer(u16);
		EXPORT void GetComboPartsInfoPointer(u16);
		EXPORT void GetDamageInflictedFromDifficulty(i32);
		EXPORT void GetEnterExitFrameInfoPointer(u16);
		EXPORT void GetFreeIndicatorListEntry(void);
		EXPORT void GetNewCommandBlock(u32);
		EXPORT void GetPerpendicularisationRadius(void);
		EXPORT void GrabUpdate(CVector *,i16 *);
		EXPORT void HandleControlsForSurfaceTransition(bool);
		EXPORT i32 Hit(SHitInfo *) OVERRIDE;
		EXPORT void IfPlayerCeilingCheck(i32,i32);
		EXPORT void IncHealth(i32);
		EXPORT void InitialiseOffscreenSpideySenseIndicatorList(void);
		EXPORT void InitialiseSFXArray(void);
		EXPORT void InitiateCombo(u16,i32);
		EXPORT void IsInIndicatorList(SHandle *);
		EXPORT void KnockSpideyFromCrawlPosition(void);
		EXPORT void LockTargetTorsoAngle(void);
		EXPORT void NotifyKill(u16);
		EXPORT void ParseFightData(void);
		EXPORT void ProcessSFXArray(void);
		EXPORT void ReadAnalogueInput(void);
		EXPORT void SelectAutoAimTarget(void);
		EXPORT void SelectTargetBaddy(i32,i32,i32,i32);
		EXPORT void SelectTargetSwitch(i32,i32,SHandle *,i32,i32);
		EXPORT void SetArmor(bool);
		EXPORT void SetCeilingCamera(i32);
		EXPORT void SetFallingCamera(i32);
		EXPORT void SetFirstContactDetails(void);
		EXPORT void SetFloorCamera(i32);
		EXPORT void SetFocusLockTarget(CBody const *);
		EXPORT void SetSpideyCamValue(u16,u16,i16,u16,u16);
		EXPORT void SetSwingCamera(i32);
		EXPORT void SetWallCamera(i32);
		EXPORT void SetupLookaroundCamera(void);
		EXPORT void ShouldPlayerDropFlail(void);
		EXPORT void SortAnimationFollowOnData(void);
		EXPORT void SortFistsData(void);
		EXPORT void SwitchToDeathMode(bool);
		EXPORT void SwitchToSynthesizedInput(i16 *);
		EXPORT void SynthesizeAnalogueInput(void);
		EXPORT void UpdateAndTrackCombo(void);
		EXPORT void UpdateOffscreenSpideySenseIndicatorList(void);
		EXPORT void UpdateTrails(void);
		EXPORT ~CPlayer(void);
		EXPORT void nullsub_one(i32);
};

EXPORT void Bruce_Sync(void);

EXPORT void Spidey_SetUserFunction(const char *, unsigned int);
EXPORT void Spidey_FreeHeadModel(void);
EXPORT void Spidey_CopyHeadModel(i32);

EXPORT void Spidey_BagHead(i32,i32);
EXPORT void Spidey_DoArmorVRAMProcessing(bool);
EXPORT void Spidey_LoadAlternativeHealthIcon(i32);
EXPORT void Spidey_LoadAlternativeTextureSet(u32 const *,i32);
EXPORT void Spidey_StoreTextureEntry(Texture const *,i16,i16);
EXPORT void Spidey_SwapSuitTextures(i32,i32);
EXPORT void spideyLog(char *,...);

void validate_CPlayer(void);

#endif
