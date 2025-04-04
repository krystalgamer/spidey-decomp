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
	EXPORT i16 GetScriptValue(void);

	EXPORT virtual int PlayerIsVisible();
	EXPORT virtual void CreateCombatImpactEffect(CVector*, i32);
	EXPORT virtual u8 TugImpulse(CVector*, CVector*, CVector*);
	EXPORT virtual void Victorious(void);
	EXPORT virtual void SetParamByIndex(i32, i32);
	EXPORT virtual u8 Grab(CVector*);
	EXPORT virtual void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT virtual void UnknownCBaddyFunctionFive(int);
	EXPORT virtual CBaddy* GetClosest(int, int);
	EXPORT virtual int ExecuteCommand(u16);
	EXPORT virtual void SetVariable(u16);
	EXPORT virtual i16 GetVariable(u16);

	PADDING(4);

	CVector field_1A8[6];

	i32 field_1F0;
	i32 field_1F4;
	i32 field_1F8;
	u16 field_1FC;
	i16 field_1FE;
	PADDING(1);

	i32 field_204;
	i32 field_208;

	u8 field_20C;

	PADDING(0x2);


	u8 field_20F;
	u8 field_210;
	u8 field_211;
	u8 field_212;
	u8 field_213;

	PADDING(1);

	i16 field_216;
	i32 field_218;

	PADDING(0x1);

	u8 field_21D;

	i16 field_21E;

	//i16 registerArr[6];
	i16 field_220;
	i16 realRegisterArr[6];

	PADDING(2);

	i32 field_230;
	u8 field_234;

	PADDING(4);

	i32 field_23C;

	CVector field_240;
	i16 *field_24C;


	PADDING(0x84 - 0x14 - 4 - 0x10 - 0x30 - 0xC);

	i16 attributeArr[6];
	CVector field_27C;

	i32 field_288;
	
	CAIProc *mAIProcList;
	CMessage* pMessage;

	IntToBytes field_294;
	IntToBytes field_298;
	i32 field_29C;

	i32 field_2A0;
	CBody *field_2A4;
	i32 field_2A8;
	i32 field_2AC;
	i32 field_2B0;

	i32 field_2B4;
	CVector field_2B8;

	i32 field_2C4;
	i32 field_2C8;
	i32 field_2CC;


	CVector field_2D0;

	i16 field_2DC;
	i16 field_2DE;
	i16 field_2E0;
	i16 field_2E2;
	i16 field_2E4;
	i16 field_2E6;
	CSVector field_2E8;
	PADDING(0x2F0 - 0x2E8 - sizeof(CSVector));


	i32 field_2F0;
	i32 field_2F4;
	i32 field_2F8;

	CVector field_2FC;
	i32 field_308;
	PADDING(0x310 - 0x308 - 4);

	i32 field_310;
	i16 field_314;
	PADDING(2);

	i32 field_318;
	SStateFlags field_31C;
	i32 dumbAssPad;
};


class CScriptOnlyBaddy : public CBaddy {

public:
	PADDING(4);

	i32 field_328;
	i16 field_32C;
	i16 field_32E;
};

EXPORT CBaddy* FindBaddyOfType(int);
EXPORT extern CBaddy* BaddyList;
EXPORT extern CBody* ControlBaddyList;
EXPORT extern i32 gAttackRelated;
EXPORT extern i32 gBossRelated;
EXPORT extern u8 gObjFileRegion;

void validate_CBaddy(void);
void validate_CScriptOnlyBaddy(void);
void validate_SStateFlags(void);

#endif
