#include "ai.h"
#include "validate.h"
#include <cmath>


// @NotOk
// validate
int __inline CAIProc::Wait(void)
{
	if (this->field_10 & 3)
		return 1;

	if (this->field_10 & 4)
	{
		this->field_10 |= 1;
		return 2;
	}

	int v3 = this->field_C;

	if (v3 <= 0)
		return 0;

	this->field_C--;
	return v3;
}

// @NotOk
// Fix casts
void __inline CAIProc::AttachProc(AIProcType a2, CBaddy* a3, int a4)
{
	this->pBaddy = a3;

	this->field_1C = reinterpret_cast<CAIProc*>(a3->field_28C);
	if (this->field_1C)
		this->field_1C->field_18 = this;

	a3->field_28C = reinterpret_cast<unsigned int*>(this);

	if (!(a2 & 0x40000))
		a3->MarkAIProcList(0, a2 & 0xFF00, 0);

	this->mAIProcType = a2;
	this->field_14 = a4;

	a3->field_288 &= ~a4;
}

// @Ok
void __inline CAIProc_LookAt::SetUpVariables(int a2, int a3)
{
	int v3 = abs(a2);

	if (v3 <= 16)
		v3 = 16;

	this->field_38 = v3;
	this->field_3C = abs(a3);
	this->pBaddy->field_2A8 &= 0xBFFFFFFF;
}

// @Ok
CAIProc_LookAt::CAIProc_LookAt(CBaddy* a2, CBody* a3, CVector * pTargetPos, int a5, int a6, int a7)
{
	this->field_2C.vx = 0;
	this->field_2C.vy = 0;
	this->field_2C.vz = 0;

	if (a3)
	{
		this->AttachProc(UNK_257, a2, a5);
		this->field_24 = Mem_MakeHandle(a3);
	}
	else
	{
		print_if_false(pTargetPos != 0, "NULL pointer to targetPos.");
		this->AttachProc(UNK_258, a2, a5);
		this->field_2C = *pTargetPos;
	}

	this->SetUpVariables(a7, a6);
}

// @Ok
CAIProc_RotY::CAIProc_RotY(CBaddy* pBaddy, int a3, int numFrames, int a5)
{
	this->AttachProc(UNK_260, pBaddy, a5);

	print_if_false(numFrames > 0, "numFrames <= 0 illegal. you're under arrest dipshit.");
	this->field_20 = numFrames;
	this->field_24 = a3 / numFrames;
}

// @Ok
CAIProc_Fall::CAIProc_Fall(CBaddy *pBaddy, int a3)
{
	this->AttachProc(PROC_FALL_TYPE, pBaddy, a3);
}

// @Ok
CAIProc_StateSwitchSendMessage::CAIProc_StateSwitchSendMessage(CBaddy *pBaddy, int a3)
{
	this->AttachProc(STATE_SWITCH_SEND_MESSAGE, pBaddy, 0);

	this->mFlags = pBaddy->field_31C;
	this->field_24 = a3;
}

// @Ok
CAIProc_MonitorAttack::CAIProc_MonitorAttack(CBaddy* pBaddy, int a3, int a4, int a5, int a6)
{
	this->AttachProc(MONITOR_ATTACK, pBaddy, a6);

	this->field_20 = pBaddy->field_12A;
	this->field_24 = a3;
	this->field_28 = a3 + a5 - 1;
	this->field_2C = a4;

	int setBits = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((1 << i) & a4)
			setBits++;
	}

	this->field_30 = reinterpret_cast<CVector*>(DCMem_New(12 * setBits, 0, 1, 0, 1));
}

void validate_CAIProc(void)
{
	VALIDATE(CAIProc, pBaddy, 0x4);
	VALIDATE(CAIProc, mAIProcType, 0x8);

	VALIDATE(CAIProc, field_C, 0xC);
	VALIDATE(CAIProc, field_10, 0x10);

	VALIDATE(CAIProc, field_14, 0x14);
	VALIDATE(CAIProc, field_18, 0x18);

	VALIDATE(CAIProc, field_1C, 0x1C);
}

void validate_CAIProc_LookAt(void)
{
	VALIDATE_SIZE(CAIProc_LookAt, 0x40);

	VALIDATE(CAIProc_LookAt, field_24, 0x24);
	VALIDATE(CAIProc_LookAt, field_2C, 0x2C);

	VALIDATE(CAIProc_LookAt, field_38, 0x38);
	VALIDATE(CAIProc_LookAt, field_3C, 0x3C);

}

void validate_CAIProc_RotY(void)
{
	VALIDATE_SIZE(CAIProc_RotY, 0x28);

	VALIDATE(CAIProc_RotY, field_20, 0x20);
	VALIDATE(CAIProc_RotY, field_24, 0x24);
}

void validate_CAIProc_Fall(void)
{
	VALIDATE_SIZE(CAIProc_Fall, 0x20);
}

void validate_CAIProc_StateSwitchSendMessage(void)
{
	VALIDATE_SIZE(CAIProc_StateSwitchSendMessage, 0x28);

	VALIDATE(CAIProc_StateSwitchSendMessage, mFlags, 0x20);
	VALIDATE(CAIProc_StateSwitchSendMessage, field_24, 0x24);
}

void validate_CAIProc_MonitorAttack(void)
{
	VALIDATE_SIZE(CAIProc_MonitorAttack, 0x38);

	VALIDATE(CAIProc_MonitorAttack, field_20, 0x20);
	VALIDATE(CAIProc_MonitorAttack, field_24, 0x24);
	VALIDATE(CAIProc_MonitorAttack, field_28, 0x28);
	VALIDATE(CAIProc_MonitorAttack, field_2C, 0x2C);
	VALIDATE(CAIProc_MonitorAttack, field_30, 0x30);
}
