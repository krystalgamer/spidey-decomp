#include "simby.h"
#include "validate.h"
#include "trig.h"
#include "utils.h"
#include "mem.h"
#include "ps2redbook.h"
#include "ps2lowsfx.h"
#include "ai.h"
#include "utils.h"
#include "m3dutils.h"
#include "spidey.h"

static SStateFlags gSimbyFlags;
extern CPlayer* MechList;

// @BIGTODO
CSimbyShot::CSimbyShot(CVector*)
{}

// @Ok
void CSimby::SetUpHandPos(void)
{
	SHook v8;
	v8.Offset = 14;

	CVector a3;
	a3.vx = 0;
	a3.vy = 0;
	a3.vz = 0;

	CVector a2;
	a2.vx = 0;
	a2.vy = 0;
	a2.vz = 0;

	v8.Part.vz = 0;
	v8.Part.vy = 0;
	v8.Part.vx = 0;

	M3dUtils_GetDynamicHookPosition(
			reinterpret_cast<VECTOR*>(&a3),
			this,
			&v8);
	v8.Offset = 11;
	M3dUtils_GetDynamicHookPosition(
			reinterpret_cast<VECTOR*>(&a2),
			this,
			&v8);

	this->field_3DC = (a2 + a3) >> 1;
}

void CSimby::Shoot(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->CycleAnim(this->field_298.Bytes[0], 1);
			new CAIProc_LookAt(
					this,
					MechList,
					0,
					2,
					80,
					0);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_288 & 2)
			{
				this->field_288 &= 0xFFFFFFFD;
				this->RunAnim(0x2B, 0, -1);
				this->dumbAssPad++;
			}
			break;
		case 2:
			if (this->field_128 >= 14)
			{
				this->SetUpHandPos();
				new CSimbyShot(&this->field_3DC);
				SFX_PlayPos(0x815C, &this->mPos, 0);
				this->dumbAssPad++;
			}
			break;
		case 3:
			if (this->field_142)
			{
				this->field_31C.bothFlags = 4;
				this->field_324 = 450 - Rnd(150);
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @Ok
void CSimby::TakeHit(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->field_310 = 0;

			new CAIProc_LookAt(
					this,
					MechList,
					0,
					0,
					80,
					200);

			this->RunAppropriateHitAnim();
			this->field_230 = 10;
			this->dumbAssPad++;
			break;
		case 1:
			this->RunTimer(&this->field_230);
			if (!this->field_230)
			{
				this->RunAnim(this->field_298.Bytes[0], 0, -1);
				this->field_31C.bothFlags = 4;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @NotOk
// globals
void CSimby::PlayGruntSound(void)
{
	if (this->CheckStateFlags(&gSimbyFlags, 25) & 0x2000)
	{
		this->RunTimer(&this->field_34C);

		if (!this->field_34C)
		{
			this->field_34C = Rnd(180) + 180;

			u32 song;
			switch (Rnd(3))
			{
				case 0:
					song = 349;
					break;
				case 1:
					song = 350;
					break;
				case 2:
					song = 351;
					break;
				default:
					print_if_false(0, "Who's been smokin' crack today?");
					break;
			}

			SFX_PlayPos(song | 0x8000, &this->mPos, 0);
		}
	}
}

// @Ok
i32 CSimby::PlayAndAttachXAPlease(
		i32 a2,
		i32 a3,
		CBody *pBody,
		i32 a5)
{
	if (Redbook_XAPlayPos(a2, a3, &pBody->mPos, a5))
	{
		pBody->AttachXA(a2, a3);
		return 1;
	}

	return 0;
}

// @NotOk
// understand ptr
i32 __inline CSimby::FireTrappedToDeath(void)
{
	u8 *v2 = reinterpret_cast<u8*>(Mem_RecoverPointer(&this->field_104));
	if (!v2 || !v2[1048] || *(i32*)(*((u32*)v2 + 17) + 60) <= 40)
		return 0;
	this->field_31C.bothFlags = 23;
	this->dumbAssPad = 0;
	return 1;
}

// @Ok
void __inline CSimby::RunAppropriateHitAnim(void)
{
	if (this->field_218 & 0x10)
		this->RunAnim(17, 0, -1);
	else if (this->field_218 & 0x20)
		this->RunAnim(18, 0, -1);
	else
		this->RunAnim(19, 0, -1);
}

// @Ok
void __inline CSimby::SetUpJumpData(i32 a2, i32 a3)
{
	i32 v3;
	if(a3 <= a2)
	{
		v3 = 1;
	}
	else
	{
		v3 = a3 / a2;
	}

	this->field_3CC = v3;

	if (this->field_3CC < 14)
		this->field_3CC = 14;

	this->field_3D0 = 4096 / this->field_3CC;
}

// @Ok
void __inline CSimby::SetAlertModeTimer(int timer)
{
	if (this->field_348 < timer)
		this->field_348 = timer;
}

// @MEDIUMTODO
CSimby::CSimby(int* a2, int a3)
{
}

// @NotOk
// Globals
CSimby::CSimby(void)
{
	this->field_350 = 0;
	this->field_354 = 0;
	this->field_358 = 0;
	this->field_35C = 0;
	this->field_360 = 0;
	this->field_364 = 0;

	this->field_368.vx = 0;
	this->field_368.vy = 0;
	this->field_368.vz = 0;

	this->field_374 = 0;
	this->field_378 = 0;
	this->field_37C = 0;
	this->field_380 = 0;
	this->field_384 = 0;
	this->field_388 = 0;
	this->field_38C = 0;
	this->field_390 = 0;
	this->field_394 = 0;
	this->field_3DC.vx = 0;
	this->field_3DC.vy = 0;
	this->field_3DC.vz = 0;

	this->field_3F8 = 0;
	this->field_3FC = 0;
	this->field_400 = 0;
	this->field_404 = 0;
	this->field_408 = 0;
	this->field_40C = 0;

	this->InitItem("symbi_02");
	this->field_38 = 324;

	int * dword_682C5C = reinterpret_cast<int*>(0x682C5C);
	if (!*dword_682C5C)
		MakeVertexWibbler();

	*dword_682C5C = *dword_682C5C + 1;
}

// @Ok
void Simby_CreateSimby(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	if (v2)
	{
		*result = reinterpret_cast<unsigned int>(new CSimby(v2, v3));
	}
	else
	{
		*result = reinterpret_cast<unsigned int>(new CSimby());
	}
}

// @MEDIUMTODO
void MakeVertexWibbler(void)
{}

// @NotOk
// can't get it to match should be good enough
void CSimby::FlashUpdate(void)
{
	
#define BYTE0(x) ((x) & 0xFF)
#define BYTE1(x) (BYTE0((x >> 8)))
#define BYTE2(x) (BYTE0((x >> 16)))

	if (this->field_328)
	{
		this->mFlags |= 0x400;

		/*
		this->field_24 = ((this->field_32A + this->field_24) & 0xFF) | (((this->field_32E + (this->field_24 >> 0x10)) << 16) & 0xFF0000) | ((((this->field_24 >> 8) + this->field_32C) << 8) & 0xFF00);
		*/

		this->field_24 = BYTE0(this->field_24 + this->field_32A) | ((BYTE1(this->field_24) + this->field_32C) << 8) | ((BYTE2(this->field_24) + this->field_32E) << 16) ;

																							                            

		if (!--this->field_328)
		{

			if (this->field_330 & 0x2000000)
			{
				this->mFlags |= 0x400;
			}
			else
			{
				this->mFlags &= 0xFBFF;
			}

			this->field_24 = this->field_330;
			this->field_330 = 0;
		}
	}
}

// @Ok
void CSimbySlimeBase::ScaleUp(void)
{
	this->field_A4 = 32;
}

// @Ok
void CSimbySlimeBase::ScaleDown(void)
{
	this->field_A4 = -32;
}

// @Ok
void CSimbySlimeBase::ScaleDownAndDie(void)
{
	this->ScaleDown();
	this->field_9C = 1;
	this->mProtected = 0;
}

static int gSimbyAttackData;

// @NotOk
// global
void __inline CSimby::ClearAttackData(void)
{
	gSimbyAttackData &= ~this->field_3F0;
	this->field_3F0 = 0;
}

// @Ok
void CPunchOb::SendPulse(void)
{
	if (!this->field_328)
	{
		this->field_328 = 1;
		Trig_SendPulse(reinterpret_cast<unsigned __int16*>(Trig_GetLinksPointer(this->field_DE)));
	}
}

// @Ok
void __inline CSimby::SetUpUnitFromDirection(CVector* a2, int a3)
{
	CSVector v4;
	v4.vy = a3;
	v4.vx = 0;
	v4.vz = 0;

	Utils_GetVecFromMagDir(a2, 1, &v4);
}


// @NotOk
// missing texture related
CEmber::CEmber(const CVector* a2, int a3)
{
	this->field_68.vx = 0;
	this->field_68.vy = 0;
	this->field_68.vz = 0;

	this->mPos = *a2;

	this->field_68.vx = this->mPos.vz;
	this->field_68.vz = this->mPos.vz;

	this->field_78.vx = Rnd(10) + 10;
	this->field_78.vy = Rnd(4096);
	this->field_78.vz = Rnd(4096);

	//this->SetTexture(*(Texture **)(gTextureRelated + 44));

	this->mScale = Rnd(200) + 350;
	this->field_84 = 255;
	this->field_88 = 128;
	this->field_8C = 0;

	this->SetTint(0xFFu, 128, 0);
	this->SetSemiTransparent();
	this->field_74 = (a3 * (Rnd(5) + 5)) >> 8;

	this->mVel.vy = (a3 * (Rnd(5) + 6)) << 12 >> 8;
}

// @Ok
void Simby_CreateEmber(const unsigned int* a1, unsigned int*)
{
	const CVector *vec = reinterpret_cast<const CVector*>(a1);
	new CEmber(vec, vec->vy);
}

void validate_CPunchOb(void){
	VALIDATE_SIZE(CPunchOb, 0x32C);

	VALIDATE(CPunchOb, field_328, 0x328);
}

void validate_CSimby(void){
	VALIDATE_SIZE(CSimby, 0x460);

	VALIDATE(CSimby, field_324, 0x324);

	VALIDATE(CSimby, field_328, 0x328);
	VALIDATE(CSimby, field_32A, 0x32A);
	VALIDATE(CSimby, field_32C, 0x32C);
	VALIDATE(CSimby, field_32E, 0x32E);
	VALIDATE(CSimby, field_330, 0x330);

	VALIDATE(CSimby, field_348, 0x348);
	VALIDATE(CSimby, field_34C, 0x34C);

	VALIDATE(CSimby, field_350, 0x350);
	VALIDATE(CSimby, field_354, 0x354);
	VALIDATE(CSimby, field_358, 0x358);
	VALIDATE(CSimby, field_35C, 0x35C);
	VALIDATE(CSimby, field_360, 0x360);
	VALIDATE(CSimby, field_364, 0x364);

	VALIDATE(CSimby, field_368, 0x368);

	VALIDATE(CSimby, field_374, 0x374);
	VALIDATE(CSimby, field_378, 0x378);
	VALIDATE(CSimby, field_37C, 0x37C);
	VALIDATE(CSimby, field_380, 0x380);
	VALIDATE(CSimby, field_384, 0x384);
	VALIDATE(CSimby, field_388, 0x388);
	VALIDATE(CSimby, field_38C, 0x38C);
	VALIDATE(CSimby, field_390, 0x390);
	VALIDATE(CSimby, field_394, 0x394);

	VALIDATE(CSimby, field_398, 0x398);

	VALIDATE(CSimby, field_39C, 0x39C);

	VALIDATE(CSimby, field_3CC, 0x3CC);
	VALIDATE(CSimby, field_3D0, 0x3D0);

	VALIDATE(CSimby, field_3DC, 0x3DC);

	VALIDATE(CSimby, field_3F0, 0x3F0);

	VALIDATE(CSimby, field_3F8, 0x3F8);
	VALIDATE(CSimby, field_3FC, 0x3FC);
	VALIDATE(CSimby, field_400, 0x400);
	VALIDATE(CSimby, field_404, 0x404);
	VALIDATE(CSimby, field_408, 0x408);
	VALIDATE(CSimby, field_40C, 0x40C);
}

void validate_CSimbyBase(void){
	VALIDATE_SIZE(CSimbyBase, 0x334);
}

void validate_CSimbySlimeBase(void)
{
	VALIDATE_SIZE(CSimbySlimeBase, 0x114);
	
	VALIDATE(CSimbySlimeBase, field_9C, 0x9C);
	VALIDATE(CSimbySlimeBase, field_A4, 0xA4);
}

void validate_CEmber(void)
{
	VALIDATE_SIZE(CEmber, 0x90);

	VALIDATE(CEmber, field_68, 0x68);
	VALIDATE(CEmber, field_74, 0x74);
	VALIDATE(CEmber, field_78, 0x78);
	VALIDATE(CEmber, field_84, 0x84);
	VALIDATE(CEmber, field_88, 0x88);
	VALIDATE(CEmber, field_8C, 0x8C);
}

void validate_CSimbyShot(void)
{
	VALIDATE_SIZE(CSimbyShot, 0xB8);
}
