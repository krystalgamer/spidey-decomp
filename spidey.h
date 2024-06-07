#pragma once


#ifndef SPIDEY_H
#define SPIDEY_H

#include "export.h"
#include "ob.h"

class CPlayer : public CSuper 
{
	public:

		int field_194;
		unsigned char padAfter194[0x1A8-0x194-4];

		int field_1A8;
		char field_1AC;
		unsigned char padAfter1AC[0x1BC-0x1AC-1];

		int* field_1BC;
		unsigned char padAfter1BC[0x528-0x1BC-4];

		int field_528;
		int field_52C;
		unsigned char padAfter52C[0x538-0x52C-4];

		unsigned int field_538;
		unsigned char padAfter538[0x56C-0x538-4];

		int field_56C;
		unsigned char padAfter56C[0x580-0x56C-4];

		int field_580;
		CSmokeTrail* field_584;
		CSmokeTrail* field_588;
		CSmokeTrail* field_58C;
		CSmokeTrail* field_590;
		unsigned char padAfter584[0x5D0-0x590-4];


		int field_5D0;
		int field_5D4;
		int field_5D8;
		unsigned char padAfter5D8[0x5E8-0x5D8-4];

		char field_5E8;
		unsigned char padAfter5E8[0x89C-0x5E8-4];

		MATRIX field_89C;
		unsigned char padAfter89C[0x8E8-0x89C-sizeof(MATRIX)];

		unsigned char field_8E8;
		unsigned char field_8E9;
		unsigned char field_8EA;
		unsigned char padAFter8Ea;

		unsigned char gCamAngleLock; //8EC
		unsigned char padAfterLock[0xAD4-0x8EC-1];

		char field_AD4;
		unsigned char padAfterAD4[0xC6C-0xAD4-1];


		CVector field_C6C;
		int field_C78;
		int field_C7C;
		int field_C80;
		int field_C84;
		unsigned int padAfterC84;

		int field_C8C;
		int field_C90;
		unsigned char padAfterC90[0xCB4-0xC90-4];

		int field_CB4;
		unsigned char padAfterCB4[0xCE4-0xCB4-4];

		int field_CE4;
		unsigned char padAfterCE4[0xDC0-0xCE4-4];

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
		int field_E1C;
		unsigned char padAfterE1C[0xE2D-0xE1C-4];

		char field_E2D;
		char field_E2E;

		unsigned char padBottomPlayer[(0xEFC-0xE2E)-0x1];


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
		EXPORT int* KillCommandBlock(int*);
		EXPORT void Die(void);
};

EXPORT void Spidey_SetUserFunction(const char *, unsigned int);

void validate_CPlayer(void);

#endif
