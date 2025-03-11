#pragma once

#ifndef BADDY_H
#define BADDY_H

#include "export.h"
#include "ob.h"
#include "stateflags.h"

union IntToBytes
{
	i32 Int;
	u8 Bytes[4];
};

class CMessage;
class CAIProc;
class CBaddy : public CSuper {

public:
	EXPORT CBaddy(void);
	EXPORT ~CBaddy(void);
	EXPORT int DistanceToPlayer(int a2);
	EXPORT int TrapWeb(void);
	EXPORT void CleanUpMessages(i32, i32);
	EXPORT u16 CheckStateFlags(SStateFlags *, int);
	EXPORT int YawTowards(int, int);
	EXPORT int RunTimer(int*);
	EXPORT int PathCheckGuts(CVector*, CVector*, CVector*, int);
	EXPORT int PathCheck(CVector*, CVector*, CVector*, int);
	EXPORT CBody* StruckGameObject(int, int);
	EXPORT void MarkAIProcList(int, int, int);
	EXPORT void Neutralize(void);
	EXPORT int TugWeb(void);
	EXPORT int MakeSpriteRing(CVector*);
	EXPORT void GetLocalPos(CVector *, CVector *, CSVector *);
	EXPORT int SetHeight(int, int, int);
	EXPORT void SendDeathPulse(void);
	EXPORT int Die(int);
	EXPORT void CleanUpAIProcList(i32);
	EXPORT int BumpedIntoSpidey(int);
	EXPORT int ShouldFall(int, int);
	EXPORT int CheckSightCone(int, int, int, int, CBody*);
	EXPORT void ParseScript(u16*);
	EXPORT void DoPhysics(int);
	EXPORT void Baddy_SendSignal(void);
	EXPORT int SmackSpidey(int, CVector*, int, int);
	EXPORT void RunAppropriateAnim(void);
	EXPORT i32 GetNextWaypoint(void);
	EXPORT i32 AddPointToPath(CVector*, i32);
	EXPORT void GetWaypointNearTarget(CVector*, i32, i32, CVector*);

	EXPORT virtual int PlayerIsVisible();
	EXPORT virtual void CreateCombatImpactEffect(CVector*, i32);
	EXPORT virtual u8 TugImpulse(CVector*, CVector*, CVector*);
	EXPORT virtual void Victorious(void);
	EXPORT virtual void SetParamByIndex(i32, i32);
	EXPORT virtual u8 Grab(CVector*);
	EXPORT virtual void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT virtual void UnknownCBaddyFunctionFive(int);
	EXPORT virtual CBaddy* GetClosest(int, int);
	EXPORT virtual int ExecuteCommand(unsigned __int16);
	EXPORT virtual void SetVariable(unsigned __int16);
	EXPORT virtual unsigned __int16 GetVariable(unsigned __int16);

	u8 padAfter1A4[4];

	CVector field_1A8[6];

	int field_1F0;
	int field_1F4;
	int field_1F8;
	__int16 field_1FC;
	__int16 field_1FE;
	unsigned char pad[0x1];

	int field_204;
	int field_208;

	unsigned char field_20C;

	unsigned char fusdakjfasdPad[0x2];


	unsigned char field_20F;
	unsigned char field_210;
	unsigned char field_211;
	unsigned char field_212;
	unsigned char field_213;
	unsigned char padAfter213[1];

	__int16 field_216;
	i32 field_218;
	unsigned char padAFter218[0x1];
	u8 field_21D;

	__int16 field_21E;

	i16 registerArr[6];
	unsigned char adsfPad[0x2C - 0x18 - 4 - 0xC];

	int field_230;
	unsigned char field_234;

	unsigned char jasdkfasdkjfajsdfPad[4];

	int field_23C;

	CVector field_240;
	int field_24C;


	unsigned char morerPad[0x84 - 0x14 - 4 - 0x10 - 0x30 - 0xC];
	__int16 attributeArr[6];
	CVector field_27C;

	int field_288;
	
	CAIProc *mAIProcList;
	CMessage* pMessage;

	IntToBytes field_294;
	IntToBytes field_298;
	i32 field_29C;

	int field_2A0;
	int field_2A4;
	i32 field_2A8;
	int field_2AC;
	int field_2B0;

	int field_2B4;
	CVector field_2B8;

	int field_2C4;
	int field_2C8;
	int field_2CC;


	CVector field_2D0;

	__int16 field_2DC;
	__int16 field_2DE;
	__int16 field_2E0;
	__int16 field_2E2;
	__int16 field_2E4;
	__int16 field_2E6;
	CSVector field_2E8;
	unsigned char padAfter2E8[0x2F0 - 0x2E8 - sizeof(CSVector)];


	int field_2F0;
	int field_2F4;
	int field_2F8;

	CVector field_2FC;
	int field_308;
	unsigned char padAfter308[0x310 - 0x308 - 4];

	i32 field_310;
	__int16 field_314;
	unsigned __int16 padAfter314;

	int field_318;
	SStateFlags field_31C;
	int dumbAssPad;
};


class CScriptOnlyBaddy : public CBaddy {

public:
	unsigned char padSOBStart[0x4];
	int field_328;
	__int16 field_32C;
	__int16 field_32E;
};

EXPORT CBaddy* FindBaddyOfType(int);
EXPORT extern CBaddy* BaddyList;
EXPORT extern CBody* ControlBaddyList;
EXPORT extern i32 gAttackRelated;
EXPORT extern i32 gBossRelated;

void validate_CBaddy(void);
void validate_CScriptOnlyBaddy(void);
void validate_SStateFlags(void);

#endif
