#pragma once

#ifndef AI_H
#define AI_H

#include "export.h"
#include "main.h"
#include "vector.h"
#include "baddy.h"
#include "mem.h"
#include "stateflags.h"

enum AIProcType
{
	UNK_257 = 257,
	UNK_258 = 258,
	LOOKAT_TWO = 259,

	UNK_260 = 260,

	PROC_FALL_TYPE = 770,

	STATE_SWITCH_SEND_MESSAGE = 0x60601,

	MONITOR_ATTACK = 1281,
};

class CAIProc : public CClass
{
	public:
		EXPORT int Wait(void);
		EXPORT void AttachProc(AIProcType, CBaddy*, int);

		CBaddy* pBaddy;
		AIProcType mAIProcType;
		int field_C;
		int field_10;
		int field_14;

		CAIProc* field_18;
		CAIProc* field_1C;
};

class CAIProc_LookAt : public CAIProc
{
	public:
		EXPORT CAIProc_LookAt(CBaddy*, CBody*, CVector *, int, int, int);
		EXPORT CAIProc_LookAt(CBaddy*, int, int, int, int);
		EXPORT void SetUpVariables(int, int);

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
		int field_20;
		int field_24;
};

class CAIProc_Fall : public CAIProc
{
	public:
		EXPORT CAIProc_Fall(CBaddy *, int);
};

class CAIProc_StateSwitchSendMessage : public CAIProc
{
	public:
		EXPORT CAIProc_StateSwitchSendMessage(CBaddy *, int);
		SStateFlags mFlags;
		int field_24;
};

class CAIProc_MonitorAttack : public CAIProc
{
	public:
		EXPORT CAIProc_MonitorAttack(CBaddy*, int, int, int, int);
		int field_20;
		int field_24;
		int field_28;
		int field_2C;
		CVector *field_30;
		unsigned char pad[4];
};

void validate_CAIProc(void);
void validate_CAIProc_LookAt(void);
void validate_CAIProc_RotY(void);
void validate_CAIProc_Fall(void);
void validate_CAIProc_StateSwitchSendMessage(void);
void validate_CAIProc_MonitorAttack(void);

#endif
