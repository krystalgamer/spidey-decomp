#pragma once

#ifndef AI_H
#define AI_H

#include "export.h"
#include "main.h"
#include "vector.h"
#include "baddy.h"
#include "mem.h"
#include "stateflags.h"

struct SMoveToInfo
{
	CVector field_0;
	int field_C;
	int field_10;
	int field_14;
};

enum AIProcType
{
	UNK_257 = 257,
	UNK_258 = 258,
	LOOKAT_TWO = 259,

	UNK_260 = 260,

	PROC_FALL_TYPE = 770,

	STATE_SWITCH_SEND_MESSAGE = 0x60601,

	MONITOR_ATTACK = 1281,

	ACCZ = 1025,
	MOVE_TO = 1794,
};

class CAIProc : public CClass
{
	public:
		EXPORT virtual ~CAIProc(void);

		EXPORT int Wait(void);
		EXPORT void AttachProc(AIProcType, CBaddy*, int);
		EXPORT virtual void Execute(void) = 0;

		CBaddy* pBaddy;
		AIProcType mAIProcType;
		int field_C;
		int field_10;
		int field_14;

		CAIProc* field_18;
		CAIProc* mNext;
};

class CAIProc_LookAt : public CAIProc
{
	public:
		EXPORT CAIProc_LookAt(CBaddy*, CBody*, CVector *, int, int, int);
		EXPORT CAIProc_LookAt(CBaddy*, int, int, int, int);
		EXPORT void SetUpVariables(int, int);
		EXPORT virtual void Execute(void);

		int field_20;
		SHandle field_24;
		CVector field_2C;

		int field_38;
		int field_3C;
};

class CAIProc_RotY : public CAIProc
{
	public:
		EXPORT CAIProc_RotY(CBaddy*, int, int ,int);

		// @TODO
		// this doesn't exist, i'm confused
		void Execute(void)
		{
		}

		int field_20;
		int field_24;
};

class CAIProc_Fall : public CAIProc
{
	public:
		EXPORT CAIProc_Fall(CBaddy *, int);
		EXPORT void Execute(void);
};

class CAIProc_StateSwitchSendMessage : public CAIProc
{
	public:
		EXPORT CAIProc_StateSwitchSendMessage(CBaddy *, int);
		EXPORT virtual ~CAIProc_StateSwitchSendMessage(void);
		EXPORT void Execute(void);

		SStateFlags mFlags;
		int field_24;
};

class CAIProc_MonitorAttack : public CAIProc
{
	public:
		EXPORT CAIProc_MonitorAttack(CBaddy*, int, int, int, int);
		EXPORT virtual ~CAIProc_MonitorAttack(void);
		EXPORT void Execute(void);

		int field_20;
		int field_24;
		int field_28;
		int field_2C;
		CVector *field_30;
		int field_34;
};

class CAIProc_AccZ : public CAIProc
{
	public:
		EXPORT CAIProc_AccZ(CBaddy*, int, int, int);
		EXPORT void Execute(void);

		int field_20;
		int field_24;
};

class CAIProc_MoveTo : public CAIProc
{
	public:
		EXPORT CAIProc_MoveTo(CBaddy*, SMoveToInfo*, int);
		EXPORT virtual void Execute(void);

		CVector field_20;
		int field_2C;
		CVector field_30;
		int field_3C;
};

void validate_CAIProc(void);
void validate_CAIProc_LookAt(void);
void validate_CAIProc_RotY(void);
void validate_CAIProc_Fall(void);
void validate_CAIProc_StateSwitchSendMessage(void);
void validate_CAIProc_MonitorAttack(void);
void validate_CAIProc_AccZ(void);
void validate_SMoveToInfo(void);
void validate_CAIProc_MoveTo(void);

#endif
