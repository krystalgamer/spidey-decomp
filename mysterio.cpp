#include "mysterio.h"
#include "validate.h"
#include "ps2redbook.h"
#include "ps2pad.h"
#include "trig.h"
#include "ai.h"
#include "utils.h"
#include "panel.h"
#include "ps2lowsfx.h"
#include "m3dutils.h"
#include "m3dcolij.h"
#include "spidey.h"

i32 gAttackRelated;
extern CPlayer* MechList;

// @Ok
// not matching but good enough
i32 CMysterio::MonitorAttack(
		i32 a2,
		VECTOR* a3,
		i32 a4)
{
	SHook hook;


	hook.Part.vy = a3->vy;
	i32 res = 0;
	hook.Part.vz = a3->vz;
	hook.Part.vx = a3->vx;

	if (this->field_388 != gAttackRelated - 1)
	{
		M3dUtils_GetDynamicHookPosition(
				reinterpret_cast<VECTOR*>(&this->field_37C),
				this,
				&hook);
	}
	else
	{
		CVector v13;
		CVector v14;

		v13.vx = 0;
		v13.vy = 0;
		v13.vz = 0;

		v14.vx = 0;
		v14.vy = 0;
		v14.vz = 0;

		M3dUtils_GetDynamicHookPosition(
				reinterpret_cast<VECTOR*>(&v13),
				this,
				&hook);

		if (M3dColij_LineToSphere(
					&this->field_37C,
					&v13,
					&v14,
					MechList,
					0,
					((MechList->field_DC + a4) << 12) / MechList->field_DC))
		{
			res = 1;
		}

		this->field_37C = v13;
	}

	this->field_388 = gAttackRelated;

	return res;
}

i32 gBossRelated;
extern CBaddy* BaddyList;

// @Ok
CMysterio::~CMysterio(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
	gBossRelated = 0;
	Panel_DestroyHealthbar();

	if (this->field_3B8)
		SFX_Stop(this->field_3B8);

	this->field_3B8 = 0;

	if (this->field_324)
		delete this->field_324;


	CItem* first = reinterpret_cast<CItem*>(Mem_RecoverPointer(&this->field_360));
	if (first)
		delete first;

	CItem* second = reinterpret_cast<CItem*>(Mem_RecoverPointer(&this->field_368));
	if (second)
		delete second;



}

// @MEDIUMTODO
CMysterio::CMysterio(int*, int)
{
}

// @NotOk
// Globals
CMysterio::CMysterio(void)
{
	this->field_37C.vx = 0;
	this->field_37C.vy = 0;
	this->field_37C.vz = 0;

	this->InitItem("mysterio");

	this->mFlags |= 0x480;
	this->field_3C = 0x54E0F0;
}

// @Ok
void Mysterio_CreateMysterio(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	if (v2)
	{
		*result = reinterpret_cast<unsigned int>(new CMysterio(v2, v3));
	}
	else
	{
		*result = reinterpret_cast<unsigned int>(new CMysterio());
	}
}

// @Ok
void __inline CMysterioLaser::SetDamage(int damage)
{
	this->field_4C = damage;
}

// @Ok
void __inline CGoldFish::AngryMode(void)
{
	this->field_F8 = 1;
}

// @Ok
void __inline CGoldFish::NormalMode(void)
{
	this->field_F8 = 0;
}

void validate_CMystFoot(void){
	VALIDATE_SIZE(CMystFoot, 0x324);
}

// @Ok
void __inline CMysterioHeadCircle::NormalMode(void)
{
	if (this->field_8C)
		this->field_88 >>= 1;
	this->field_8C = 0;
}

// @Ok
void __inline CMysterioHeadCircle::AngryMode(void)
{
	if (!this->field_8C)
		this->field_88 <<= 1;
	this->field_8C = 1;
}

// @Ok
u8 INLINE CMysterio::MystRedbook_XAPlayPos(
		i32 a2,
		i32 a3,
		CVector *a4,
		i32 a5)
{
	u8 res = Redbook_XAPlay(a2, a3, a5);
	if (res)
	{
		this->field_3A0 = 0;
		this->field_39C = 480;
	}

	return res;
}

// @Ok
i32 INLINE CMysterio::PlayAndAttachXAPlease(
		i32 a2,
		i32 a3,
		CBody* pBody,
		i32 a5)
{
	if (this->MystRedbook_XAPlayPos(a2, a3, &pBody->mPos, a5))
	{
		pBody->AttachXA(a2, a3);
	}
	
	return 0;
}

EXPORT u8 gActuatorRelated;

// @NotOk
// globals
void INLINE CMysterio::ShakePad(void)
{
	if (gActuatorRelated)
	{
		if (Pad_GetActuatorTime(0, 0) <= 2)
			Pad_ActuatorOn(0, 6, 0, 1);
		if (Pad_GetActuatorTime(0, 1) <= 2)
			Pad_ActuatorOn(0, 10, 1, 0xC8);
	}
}

extern CCamera *CameraList;

// @NotOk
// globals
i32 INLINE CMysterio::CheckforCameraShake(i32 a2)
{

	if (this->field_218 & 8 || this->field_218 < a2)
		return 0;

	CameraList->Shake(&this->mPos, EShake_0x0);

	this->ShakePad();

	this->field_218 |= 8;
	return 1;
}

// @Ok
void INLINE CMysterio::EnterP2(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->RunAnim(10, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
			{
				this->field_31C.bothFlags = 1;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

extern i32 DifficultyLevel;

// @NotOk
// globals
// good candidate for tests
// there's a strange assignemnt but can't tell if it's due to inline or comma operator
i32 INLINE CMysterio::GetAttackRotSpeed(void)
{
	if (!DifficultyLevel)
	{
		if (this->field_34C && this->field_350)
		{
			return 2;
		}

		return 5;
	}
	else
	{
		if (DifficultyLevel == 1)
		{
			if (this->field_34C && this->field_350)
			{
				return 3;
			}

			return 9;
		}
		else if (this->field_34C && this->field_350)
		{
			return 12;
		}

		return 5;

	}
}

// @Ok
void CMysterio::SummonAttack(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->RunAnim(10, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_218 >= 58)
			{
				Trig_SendPulse(reinterpret_cast<u16*>(
							Trig_GetLinksPointer(this->field_DE)));
				this->dumbAssPad++;
			}
			break;
		case 2:
			if (this->field_142)
			{
				this->field_31C.bothFlags = 1;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @NotOk
// globals
void CMysterio::LookMenacing(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			new CAIProc_LookAt(this, MechList, 0, 1, 60, 341);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
			{
				this->RunAnim(8, 0, -1);
			}
			break;
		default:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @Ok
void CMysterio::RotateToOptimalAttackAngle(
		i32 a2,
		i32 a3)
{
	CSVector v7;

	v7.vx = 0;
	v7.vy = 0;
	v7.vz = 0;

	Utils_CalcAim(&v7, &this->mPos, &MechList->mPos);

	i32 v4 = v7.vy - this->mAngles.vy;

	if (v4 < -2056)
	{
		v4 += 4096;
	}
	else if (v4 > 2056)
	{
		v4 -= 4096;
	}

	v4 -= a2;
	if (v4 < -2056)
	{
		v4 += 4096;
	}
	else if (v4 > 2056)
	{
		v4 -= 4096;
	}

	new CAIProc_LookAt(
			this,
			v4 + this->mAngles.vy,
			1,
			a3,
			200);
}

void validate_CMysterio(void){
	VALIDATE_SIZE(CMysterio, 0x3D0);

	VALIDATE(CMysterio, field_324, 0x324);
	VALIDATE(CMysterio, field_32C, 0x32C);

	VALIDATE(CMysterio, field_34C, 0x34C);
	VALIDATE(CMysterio, field_350, 0x350);

	VALIDATE(CMysterio, field_358, 0x358);

	VALIDATE(CMysterio, field_360, 0x360);
	VALIDATE(CMysterio, field_368, 0x368);

	VALIDATE(CMysterio, field_374, 0x374);

	VALIDATE(CMysterio, field_378, 0x378);
	VALIDATE(CMysterio, field_37C, 0x37C);

	VALIDATE(CMysterio, field_388, 0x388);

	VALIDATE(CMysterio, field_38C, 0x38C);
	VALIDATE(CMysterio, field_398, 0x398);

	VALIDATE(CMysterio, field_39C, 0x39C);
	VALIDATE(CMysterio, field_3A0, 0x3A0);

	VALIDATE(CMysterio, field_3A8, 0x3A8);

	VALIDATE(CMysterio, field_3B8, 0x3B8);
}

void validate_CSoftSpot(void){
	VALIDATE_SIZE(CSoftSpot, 0x338);

	VALIDATE(CSoftSpot, field_324, 0x324);
	VALIDATE(CSoftSpot, field_328, 0x328);
	VALIDATE(CSoftSpot, field_32c, 0x32c);
	VALIDATE(CSoftSpot, field_330, 0x330);
	VALIDATE(CSoftSpot, field_334, 0x334);
}

void validate_CMysterioLaser(void)
{
	VALIDATE_SIZE(CMysterioLaser, 0x64);

	VALIDATE(CMysterioLaser, field_4C, 0x4C);
}

void validate_CGoldFish(void)
{
	VALIDATE_SIZE(CGoldFish, 0x110);

	VALIDATE(CGoldFish, field_F8, 0xF8);
}

void validate_CMysterioHeadCircle(void)
{
	VALIDATE_SIZE(CMysterioHeadCircle, 0x90);

	VALIDATE(CMysterioHeadCircle, field_88, 0x88);
	VALIDATE(CMysterioHeadCircle, field_8C, 0x8C);
}

void validate_CFadePalettes(void)
{
	VALIDATE_SIZE(CFadePalettes, 0x460);
}
