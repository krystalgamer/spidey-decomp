#include "thug.h"
#include "validate.h"
#include "trig.h"
#include "m3dutils.h"
#include "message.h"
#include "ps2lowsfx.h"
#include "utils.h"
#include "ai.h"
#include "ps2redbook.h"

// @Ok
void CThug::Acknowledge(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->mCBodyFlags |= 0x10;
			this->Neutralize();

			if (this->field_398 < 0)
			{
				this->RunAnim(this->field_38 != 304 ? 39 : 32, 0, -1);
				Redbook_XAPlayPos(this->field_39C, -this->field_398, &this->mPos, 20);
			}

			if (Mem_RecoverPointer(&this->mHandleTwo))
			{
				new CAIProc_LookAt(
						this,
						reinterpret_cast<CBody*>(this->mHandleTwo.field_0),
						0,
						2,
						70,
						200);
			}
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
				this->CycleAnim(this->field_298.Bytes[0], 1);

			if (!this->field_33C)
			{
				if (this->field_398 > 0)
				{
					Redbook_XAPlayPos(this->field_39C, this->field_398, &this->mPos, 20);
					this->RunAnim(this->field_38 != 304 ? 40 : 32, 0, -1);
					this->dumbAssPad++;
					return;
				}

				this->field_33C = 2000;
				this->field_31C.bothFlags = 2;
				this->dumbAssPad = 0;
			}

			break;
		case 2:
			if (this->field_142)
			{
				this->field_33C = 2000;
				this->field_31C.bothFlags = 2;
				this->dumbAssPad = 0;
			}

			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
void CThug::LookConfused(void)
{
	i32 v3;

	switch ( this->dumbAssPad )
	{
		case 0:
			this->field_1F8 = Rnd(3) + 2;
			this->dumbAssPad++;
		case 1:
			this->Neutralize();
			if ( !this->field_1F8 )
			{
				this->field_330 = 0;
				this->field_31C.bothFlags = 28;
				this->dumbAssPad = 0;
			}
			else
			{
				this->dumbAssPad = 5;
				this->field_1F8 = this->field_1F8 - 1;
			}
			break;
		case 5:
			v3 = Rnd(1000) + 1000;
			if ( Rnd(2) )
				v3 = -v3;

			v3 += this->mAngles.vy;

			new CAIProc_LookAt(this, v3, 2, 80, 200);
			this->dumbAssPad++;

			break;
		case 6:
			this->RunAppropriateAnim();
			if ( (this->field_288 & 2) != 0 )
			{
				this->dumbAssPad = 1;
				this->field_288 &= 0xFFFFFFFD;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @TODO
i32 CThug::GetLaunched(CVector*, i32, i32, i32)
{
	return 0x10062024;
}

// @Ok
u8 CThug::TugImpulse(CVector* a2, CVector* a3, CVector* a4)
{
	this->field_2A8 &= 0xFFFFFFF7;
	if (a4)
	{
		this->field_31C.bothFlags = 16;
		this->dumbAssPad = 0;
		if (this->field_3A4)
			Mem_Delete(reinterpret_cast<void*>(this->field_3A4));

		this->field_3A4 = a4;
		return 1;
	}

	i32 Launched = this->GetLaunched(a3, 0, 80, 0);
	if (!Launched)
	{
		return 0;
	}

	if (this->field_E2 <= 50)
	{
		if (Launched == 1)
		{
			this->field_2A8 |= 0x10;
		}
		else
		{
			this->field_2A8 &= ~0x10;
		}
	}
	this->field_218 |= 0x80000;
	SFX_PlayPos(0x800F, &this->mPos, 0);
	this->field_31C.bothFlags = 14;
	this->dumbAssPad = 0;
	return 1;
}

// @Ok
void CThug::CheckFallBack(void)
{
	CVector v6;
	CVector a3;

	a3.vx = 0;
	a3.vy = 0;
	a3.vz = 0;

	v6.vz = ((this->field_2A8 & 0x10) ? -75 : 75) << 12;
	v6.vy = 0;
	v6.vx = 0;

	Utils_RotateY(&a3, &v6, this->mAngles.vy);

	if ( this->PathCheck(&this->mPos, &(this->mPos + a3), 0, 55) == 2 )
	{
		new CAIProc_RotY(this, 2047, 4, 0);
	}
}

// @Ok
void CThug::GetReadyToShootHostage(CMessage *pMessage)
{
	CItem *pItem = reinterpret_cast<CItem*>(Mem_RecoverPointer(&pMessage->mHandle));
	if ( pItem )
	{
		if ( Utils_LineOfSight(&this->mPos, &pItem->mPos, 0, 0) )
		{
			this->mHandle = pMessage->mHandle;

			this->field_31C.bothFlags = 8;
			this->dumbAssPad = 0;

			this->Neutralize();
			new CAIProc_StateSwitchSendMessage(this, 16);
		}
		else
		{
			new CMessage(this, reinterpret_cast<CBaddy*>(pMessage->mHandle.field_0), 1, 0);
		}

		pMessage->field_10 |= 1;
	}
}

// @Ok
// @Test
void CThug::SetParamByIndex(i32 Index, i32 Param)
{
	switch ( Index )
	{
		case 1:
			this->field_374 = Param;
			break;
		case 2:
			this->field_370 = Param;
			break;
		case 3:
			this->field_378 = Param;
			break;
		case 4:
			this->field_37C = Param;
			break;
		case 5:
			this->field_380 = Param;
			break;
		case 6:
			this->field_384 = Param;
			break;
		case 7:
			this->field_388 = Param;
			break;
		case 8:
			this->field_38C = Param;
			break;
		case 9:
			this->field_1FC = Param;
			break;
		case 10:
			this->field_394 = Param;
			break;
		case 11:
			if (Param)
				this->field_218 |= 0x800;
			else
				this->field_218 &= 0xFFFFF7FF;
			break;
		case 12:
			this->field_218 |= 0x8000;
			break;
		default:
			print_if_false(0, "Unknown index in C_SET_PARAMETER_BY_INDEX"); 
			break;
	}
}

// @Ok
void CThug::SetHitDirectionFlag(CVector* pVector)
{
	CSVector v4;
	v4.vx = 0;
	v4.vy = 0;
	v4.vz = 0;

	Utils_CalcAim(&v4, &(this->mPos + (*pVector * 300)), &this->mPos);

	i32 v3 = v4.vy - this->mAngles.vy;
	if (v3 < -2048)
	{
		v3 += 4096;
	}
	else
	{
		if (v3 > 2048)
			v3 -= 4096;
	}

	if (v3 < -455)
	{
		this->field_218 |= 0x20000;
	}
	else
	{
		if (v3 > 455)
			this->field_218 |= 0x10000;
	}
}

// @NotOk
// Globals
// also a little out of order with the v6 | 1 thing :(
CThug::CThug(int *a2, int a3)
{
	__int16 *v5 = this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));

	this->field_3B8 = Trig_GetLevelId();

	this->ShadowOn();
	this->field_D0 = 50;
	this->field_3B0 = *dword_5FCCF4;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E990));

	int v6 = this->field_2A8;
	this->field_1F4 = a3;
	this->field_DE = a3;

	__int16 v7 = this->field_38;
	this->field_230 = 0;
	this->field_216 = 32;
	this->field_2A8 = v6 | 1;

	this->field_DC = v7 != 304 ? 150 : 96;
	this->field_D8 = 64;
	this->field_380 = v7 != 304 ? 400 : 300;
	this->field_31C.bothFlags = 0;


	this->field_370 = 3500;
	this->field_374 = 400;
	this->field_378 = 2047;
	this->field_37C = 100;
	this->field_384 = 1500;
	this->field_388 = 10;
	this->field_38C = 10;

	this->field_1FC = 10;
	this->field_394 = 2000;
	this->ParseScript(reinterpret_cast<unsigned __int16*>(v5));
	this->field_212 = 60;
}

// @Ok
void Thug_CreateTHug(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CThug(v2, v3));
}

// @Ok
void __inline CThugPing::SetPosition(void)
{
	CSuper* v2 = reinterpret_cast<CSuper*>(Mem_RecoverPointer(&this->field_70));

	if (!v2)
		this->Die();
	else
		M3dUtils_GetDynamicHookPosition(
				reinterpret_cast<VECTOR*>(&this->mPos),
				v2,
				&this->field_78);
}

// @Ok
void CThugPing::Move(void)
{
	this->SetPosition();
	Bit_ReduceRGB(&this->mCodeBGR, 7);

	if ((this->mCodeBGR & 0xFFFFFF) == 0)
		this->Die();
}

static CThug* gGlobalThug;
static unsigned char gAttackFlagRelated;

// @Ok
void CThug::ClearAttackFlags(void)
{

	if ( gGlobalThug == this )
	{
		gGlobalThug = 0;
	}
	else if (this->field_3BC & 2)
	{
		gAttackFlagRelated &= ~this->field_3BD;
	}

	this->field_3BC = 0;
	this->field_3BD = 0;
}

static i32 gThugTypeRelatedFirstFirst;
static i32 gThugTypeRelatedFirstSecond;
static u8 gThugTypeRelatedFirstThird;

static i32 gThugTypeRelatedSecondFirst;
static i32 gThugTypeRelatedSecondSecond;
static u8 gThugTypeRelatedSecondThird;

// @NotOk
// globals
void CThug::SetThugType(int type)
{
	this->field_38 = type;
	switch (type)
	{
		case 304:
			this->InitItem("thug");
			this->field_21E = 100;

			this->field_294.Int = gThugTypeRelatedFirstFirst;
			this->field_298.Int = gThugTypeRelatedFirstSecond;
			M3dUtils_ReadHooksPacket(this, &gThugTypeRelatedFirstThird);

			break;
		case 312:
			if (Trig_GetLevelId() == 513)
				this->InitItem("henchngt");
			else
				this->InitItem("henchman");

			this->field_294.Int = gThugTypeRelatedSecondFirst;
			this->field_298.Int = gThugTypeRelatedSecondSecond;
			M3dUtils_ReadHooksPacket(this, &gThugTypeRelatedSecondThird);
			break;
		default:
			print_if_false(0, "Unknown thug type!");
	}

}

// @TODO
void CThug::RunToWhereTheActionIs(CVector*)
{}

// @Ok
void CThug::HelpOutBuddy(CMessage *pMessage)
{
	if (this->field_31C.bothFlags == 2 || this->field_31C.bothFlags == 1)
	{
		CItem *pItem = reinterpret_cast<CItem*>(Mem_RecoverPointer(&pMessage->mHandle));

		if (pItem)
			this->RunToWhereTheActionIs(&pItem->mPos);
	}
}

// @Ok
void __inline CThug::PlayHitWallSound(void)
{
	if (!this->field_1F8)
	{
		if (this->field_218 & 0x400)
		{
			SFX_PlayPos(0x802F, &this->mPos, 0);
		}
		else
		{
			SFX_PlayPos(0x802E, &this->mPos, 0);
		}
	}
}

// @Ok
void __inline CThug::StandStill(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->CycleAnim(this->field_38 != 304 ? 15 : 17, 1);
			this->dumbAssPad++;

			break;
		default:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @TODO
i32 CThug::ShouldFall(i32, i32)
{
	return 0x09062024;
}

// @Ok
void CThug::DieAfterFlyingAcrossRoom(void)
{
	if (this->ShouldFall(200, 0x5F000))
	{
		this->field_218 &= 0xFFFFFFFD;
		this->field_31C.bothFlags = 22;
	}
	else
	{
		this->SetHeight(1, 100, 600);
		this->PlayHitWallSound();
		this->field_31C.bothFlags = 26;
	}

	this->dumbAssPad = 0;
}

// @Ok
void __inline CThug::RunAppropriateHitAnim(void)
{
	i32 anim;
	if (this->field_218 & 0x10000)
	{
		anim = this->field_38 != 304 ? 38 : 43;
	}
	else if (this->field_218 & 0x20000)
	{
		anim = this->field_38 != 304 ? 37 : 42;
	}
	else
	{
		anim = this->field_38 != 304 ? 18 : 25;
	}

	this->RunAnim(anim, 0, -1);
}

// @Ok
void __inline CThug::StopShooting(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->RunAnim(9, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
			{
				this->field_31C.bothFlags = 28;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @TODO
i32 CThug::AddPointToPath(CVector*, i32)
{
	return 0x09062024;
}

// @Ok
i32 CThug::TryAddingCollidePointToPath(CVector* pVector)
{
	if (Utils_CrapDist(*pVector, this->mPos) < 0x64)
		return 0;

	CVector v5 = *pVector - this->mPos;
	v5 >>= 0xC;
	v5 *= 0xE74;
	v5 += this->mPos;
	return this->AddPointToPath(&v5, 0);
}


void validate_CThug(void){

	VALIDATE_SIZE(CThug, 0x3C0);

	VALIDATE(CThug, field_330, 0x330);
	VALIDATE(CThug, field_33C, 0x33C);

	VALIDATE(CThug, mHandle, 0x354);
	VALIDATE(CThug, mHandleTwo, 0x35C);

	VALIDATE(CThug, field_370, 0x370);
	VALIDATE(CThug, field_374, 0x374);
	VALIDATE(CThug, field_378, 0x378);
	VALIDATE(CThug, field_37C, 0x37C);
	VALIDATE(CThug, field_380, 0x380);
	VALIDATE(CThug, field_384, 0x384);
	VALIDATE(CThug, field_388, 0x388);
	VALIDATE(CThug, field_38C, 0x38C);

	VALIDATE(CThug, field_394, 0x394);
	VALIDATE(CThug, field_398, 0x398);
	VALIDATE(CThug, field_39C, 0x39C);

	VALIDATE(CThug, field_3A4, 0x3A4);

	VALIDATE(CThug, field_3B0, 0x3B0);
	VALIDATE(CThug, field_3B8, 0x3B8);

	VALIDATE_SIZE(IntToBytes, 0x4);
}

void validate_CThugPing(void)
{
	VALIDATE_SIZE(CThugPing, 0x80);

	VALIDATE(CThugPing, field_70, 0x70);
	VALIDATE(CThugPing, field_78, 0x78);
}
