#include "cop.h"
#include "validate.h"
#include "ps2lowsfx.h"
#include "mem.h"
#include "utils.h"
#include "spidey.h"
#include "exp.h"
#include "ai.h"


EXPORT CCop* gCopGlobal;
static unsigned char gAttackFlagsRelated;

extern CVector gGlobalNormal;
extern CPlayer *MechList;
extern CBaddy *BaddyList;

EXPORT CCop* gCopList;

// @MEDIUMTODO
i32 CCop::WallHitCheck(CVector*, CVector*, i32)
{
	printf("i32 CCop::WallHitCheck(CVector*, CVector*, i32)");
	return 0x29072024;
}

// @Ok
void CCop::Acknowledge(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->mCBodyFlags |= 0x10u;
			this->Neutralize();
			this->RunAnim(2, 0, -1);

			if ( Mem_RecoverPointer(&this->field_34C) )
			{
				new CAIProc_LookAt(
						this,
						reinterpret_cast<CBody*>(this->field_34C.field_0),
						0,
						2,
						70,
						200);
			}

			SFX_PlayPos(0x800Eu, &this->mPos, 0);
			this->dumbAssPad++;
			break;
		case 1:
			if ( this->field_142 )
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

// @Ok
INLINE void CCop::CheckToShoot(i32 a2, i32 a3)
{
	if ( MechList->field_57C && !gCopList && !MechList->field_E48)
	{
		if ( ((this->field_218 & 0x800) && a2 < this->field_37C)
				||
			 (this->field_324 && a2 < 1500 && (a3 != -1 || this->PathCheck(&this->mPos, &MechList->mPos, 0, 55))))
		{
			this->Neutralize();
			gCopList = this;
			this->field_31C.bothFlags = 9;
			this->dumbAssPad = 0;
		}
	}
}

// @SMALLTODO
i32 CCop::SetUpLaser(CGPolyLine**, CVector*, CVector*)
{
	printf("i32 CCop::SetUpLaser(CGPolyLine**, CVector*, CVector*)");
	return 0x25042024;
}

// @Ok
INLINE i32 CCop::DrawBarrelFlash(
		CVector *a2,
		CVector *a3,
		SLineInfo *a4,
		u8 a5,
		u8 a6,
		u8 a7)
{
	new CGlowFlash(a2, 5, a5, a6, a7, 32, 0, 0, 0, 0, 50, 20, 1, 20, 10, 40, 20, 10, 1);
	return CCop::SetUpLaser(&this->field_380, a2, a3);
}

// @Ok
// @Test
void CCop::GetAttackPosition(CVector* pAttackerPos)
{
	*pAttackerPos = MechList->mPos;
	if (!(this->field_390 & 1) && (this->field_390 & 2))
	{
		if (this->field_391 & 0xEE)
		{
			pAttackerPos->vx += (this->field_391 & 0xAA ? 0x12C000 : 0x190000) * (this->field_391 > 8 ? 0xFFFFFFFF : 1);
		}

		if (this->field_391 & 0xBB)
		{
			pAttackerPos->vz += (this->field_391 & 0x83 ? 1 : -1) * (this->field_391 & 0xAA ? 0x12C000 : 0x190000);
		}
	}
}

// @Ok
void CCop::SetParamByIndex(i32 Index, i32 Param)
{
	switch ( Index )
	{
		case 1:
			this->field_364 = Param;
			break;
		case 2:
			this->field_360 = Param;
			break;
		case 3:
			this->field_368 = Param;
			break;
		case 4:
			this->field_36C = Param;
			break;
		case 5:
			this->field_370 = Param;
			break;
		case 8:
			this->field_374 = Param;
			break;
		case 9:
			this->field_1FC = Param;
			break;
		case 10:
			this->field_37C = Param;
			break;
		case 11:
			if ( Param )
				this->field_218 |= 0x800;
			else
				this->field_218 &= 0xFFFFF7FF;
			break;
		default:
			print_if_false(0, "Unknown index in C_SET_PARAMETER_BY_INDEX");
			break;
	}
}

// @Ok
INLINE i32 CCop::TryAddingCollidePointToPath(CVector *a2)
{
	if (Utils_CrapDist(*a2, this->mPos) < 0x64)
		return 0;

	CVector v6 = *a2 - this->mPos;
	v6 >>= 12;
	v6 *= 3700;
	v6 += this->mPos;

	return this->AddPointToPath(&v6, 0);
}

// @NotOk
// does baddy not have 324???
void CCop::WarnOtherCops(void)
{
	CCop *nearest = reinterpret_cast<CCop*>(this->GetClosest(306, 0));
	if ( (nearest || ((nearest = reinterpret_cast<CCop*>(this->GetClosest(320, 0))) != 0))
			&& !nearest->field_324)
	{
		new CMessage(this, nearest, 7, 0);
	}
}

// @Ok
INLINE void CCop::StopShooting(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->RunAnim(12, 0, -1);
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

// @NotOk
// globals flags :(
u8 CCop::Grab(CVector* a2)
{
	if ( (this->CheckStateFlags(reinterpret_cast<SStateFlags*>(0x549220), 17) & 2)
		|| !this->AddPointToPath(a2, 0) )
	{
		return 0;
	}

	this->field_31C.bothFlags = 20;


	this->dumbAssPad = 0;
	this->field_2A8 |= 0x40;
	return 1;
}

// @Ok
void CCop::CreateCombatImpactEffect(CVector *a2, i32)
{
	new CCombatImpactRing(a2, 0x6Cu, 108, 18, 384, 1792, 144);
	new CCombatImpactRing(a2, 0x90u, 144, 72, 192, 896, 72);
}

// @Ok
void CCop::DieAfterFlyingAcrossRoom(void)
{
	if (this->ShouldFall(200, 0x5F000))
	{
		this->field_218 &= 0xFFFFFFFD;
		this->field_31C.bothFlags = 22;
	}
	else
	{
		this->PlayHitWallSound();
		this->SetHeight(1, 100, 600);
		this->field_31C.bothFlags = 26;
	}

	this->dumbAssPad = 0;
}

// @Ok
INLINE void CCop::StandStill(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->CycleAnim(17, 1);
			this->dumbAssPad++;

			break;
		default:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @Ok
void CCop::PlayHitWallSound(void)
{
	if ( !this->field_1F8 )
	{
		if ( (this->field_218 & 0x400) != 0 )
			SFX_PlayPos(0x802Fu, &this->mPos, 0);
		else
			SFX_PlayPos(0x802Eu, &this->mPos, 0);
	}
}

// @Ok
INLINE void CCop::SetAttacker(void)
{
	if (gCopGlobal != this)
	{
		this->ClearAttackFlags();
		if (gCopGlobal)
		{
			gCopGlobal->ClearAttackFlags();
		}

		gCopGlobal = this;
		this->field_390 = 1;
	}
}

// @BIGTODO
void CCop::RunToWhereTheActionIs(CVector*)
{}

// @Ok
void CCop::HelpOutBuddy(CMessage *pMessage)
{
	if (this->field_31C.bothFlags == 2 || this->field_31C.bothFlags == 1)
	{
		CItem *pItem = reinterpret_cast<CItem*>(Mem_RecoverPointer(&pMessage->mHandle));

		if (pItem)
			this->RunToWhereTheActionIs(&pItem->mPos);
	}
}

// @Ok
INLINE i32 CCop::SpideyAnimUppercut(void)
{
	return MechList->field_12A == 106
		|| MechList->field_12A == 113
		|| MechList->field_12A == 284;
}

// @NotOk
// figure type of 380
CCop::~CCop(void)
{
	if (this->field_380)
		delete this->field_380;
	this->field_380 = 0;

	if (this->field_384)
		Mem_Delete(static_cast<void*>(this->field_384));
	this->field_384 = 0;

	if (gCopList == this)
		gCopList = 0;

	this->ClearAttackFlags();
	this->DeleteFrom(reinterpret_cast<CBody**>(BaddyList));
}

// @Ok
i32 CCop::GetLaunched(CVector* a2, i32 a3, i32 a4, i32 a5)
{
	CVector v13;
	v13.vx = 0;
	v13.vy = 0;
	v13.vz = 0;

	v13 = this->mPos;
	v13.vx += a2->vx * (a4 + 1);
	v13.vz += a2->vz * (a4 + 1);

	i32 v10 = this->WallHitCheck(&v13, a2, a4);
	if (v10 == 3)
		return 0;

	this->Neutralize();
	this->mAccellorVel = *a2;
	this->mAccellorVel.vy = 0;
	if (!a3 || v10 == 2)
	{
		new CAIProc_LookAt(this, 0, &v13, 0, 80, 200);
	}

	return 10;
}

// @Ok
u8 CCop::TugImpulse(
		CVector* a2,
		CVector* a3,
		CVector* a4)
{
	this->field_2A8 &= ~8;

	if (a4)
	{
			this->field_31C.bothFlags = 16;
			this->dumbAssPad = 0;

			if ( this->field_384 )
				Mem_Delete(this->field_384);

			this->field_384 = a4;
			return 1;
	}

	i32 Launched = this->GetLaunched(a3, 0, 80, 0);
	if (!Launched)
	{
		return 0;
	}

	if ( this->field_E2 <= 50 )
	{
		if ( Launched == 1 )
			this->field_2A8 |= 0x10;
		else
			this->field_2A8 &= 0xFFFFFFEF;
	}

	this->field_31C.bothFlags = 14;
	this->field_218 |= 0x4000;
	this->dumbAssPad = 0;
	return 1;
}

// @Ok
void CCop::LookForPlayer(void)
{
	CVector v5;
	v5.vx = 0;
	v5.vy = 0;
	v5.vz = 0;

	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->CycleAnim(this->field_298.Bytes[0], 1);
			this->dumbAssPad++;
			this->field_21D = Rnd(64);
			this->field_1F8 = 0;
			break;
		case 1:
			CVector *mPos;

			if (this->field_1F8 < 64)
				mPos = &MechList->mPos;
			else
				mPos = &this->mPos;

			this->GetWaypointNearTarget(mPos, 409600, this->field_21D, &v5);
			this->field_21D++;
			if ( !this->PathCheck(&this->mPos, &v5, 0, 55)
				&& (this->AddPointToPath(&v5, 0)
				|| this->AddPointToPath(&this->mPos, 0)
				&& this->AddPointToPath(&v5, 0)) )
			{
				this->field_31C.bothFlags = 24;
				this->dumbAssPad = 0;
			}
			else
			{
				if ( this->field_1F8++ > 128 )
				{
					this->field_324 = 0;
					this->field_31C.bothFlags = 2;
					this->dumbAssPad = 0;
				}
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @SMALLTODO
void CCopBulletTracer::Move(void)
{
	printf("void CCopBulletTracer::Move(void)");
}

// @SMALLTODO
void CCopBulletTracer::SetWidth(void)
{
	printf("void CCopBulletTracer::SetWidth(void)");
}

// @SMALLTODO
CCopBulletTracer::CCopBulletTracer(CVector*, CVector*, CSuper*, SLineInfo*, u8, u8, u8)
{
	printf("CCopBulletTracer::CCopBulletTracer(CVector*, CVector*, CSuper*, SLineInfo*, u8, u8, u8)");
}

// @Ok
CCopBulletTracer::~CCopBulletTracer(void)
{
	if (this->field_3C)
		delete this->field_3C;

	if (this->field_40)
		delete this->field_40;

	this->field_3C = 0;
	this->field_40 = 0;
}

// @Ok
CCopPing::CCopPing(CSuper* pHost, SHook* pHook)
	: CSimpleAnim(&gGlobalNormal, 10, 0, 1, 0, -1)
{
	this->field_78.Part.vx = 0;
	this->field_78.Part.vy = 0;
	this->field_78.Part.vz = 0;

	print_if_false(pHost != 0, "NULL pHost");
	print_if_false(pHook != 0, "NULL pHook");

	this->field_78 = *pHook;
	this->field_70 = Mem_MakeHandle(pHost);

	this->SetFrame(1);
	this->SetTint(128, 128, 128);
	this->field_58 = Rnd(1024);

	if (Rnd(2))
		this->field_58 *= -1;

	this->mScale = 400;
	this->SetPosition();
}

// @NotOk
// globals
CCop::CCop(int* a2, int a3)
{
	i16 *v5 = this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));
	this->ShadowOn();
	this->field_D0 = 50;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));


	this->field_230 = 0;
	this->field_1F4 = a3;
	this->field_DE = a3;

	__int16 v6 = this->field_38;
	this->field_216 = 32;
	this->field_D8 = 64;
	this->field_31C.bothFlags = 0;
	this->field_DC = v6 != 306 ? 150 : 96;

	this->field_2A8 |= 1;

	this->field_370 = v6 != 306 ? 400 : 300;
	this->field_340 = *dword_5FCCF4;
	this->field_360 = 3500;
	this->field_364 = 400;
	this->field_368 = 2047;
	this->field_36C = 100;
	this->field_374 = 10;
	this->field_1FC = 10;
	this->field_37C = 2000;

	this->ParseScript(reinterpret_cast<unsigned __int16*>(v5));
	this->field_212 = 60;
}

// @Ok
void Cop_CreateCop(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CCop(v2, v3));
}

// @Ok
void CCop::Victorious(void)
{
	SFX_PlayPos(0x8024, &this->mPos, 0);
}

// @Ok
void __inline CCopPing::SetPosition(void)
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
void CCopPing::Move(void)
{
	this->SetPosition();
	Bit_ReduceRGB(&this->mCodeBGR, 7);

	if ((this->mCodeBGR & 0xFFFFFF) == 0)
		this->Die();
}

// @NotOk
// globals
void CCop::ClearAttackFlags(void)
{
	if (gCopGlobal == this)
	{
		gCopGlobal = NULL;
	}
	else if((this->field_390 & 2))
	{
		gAttackFlagsRelated &= ~this->field_391;
	}

	this->field_390 = 0;
	this->field_391 = 0;
}

void validate_CCop(void){
	VALIDATE_SIZE(CCop, 0x394);

	VALIDATE(CCop, field_324, 0x324);

	VALIDATE(CCop, field_340, 0x340);

	VALIDATE(CCop, field_34C, 0x34C);

	VALIDATE(CCop, field_360, 0x360);
	VALIDATE(CCop, field_364, 0x364);
	VALIDATE(CCop, field_368, 0x368);
	VALIDATE(CCop, field_36C, 0x36C);
	VALIDATE(CCop, field_370, 0x370);
	VALIDATE(CCop, field_374, 0x374);

	VALIDATE(CCop, field_37C, 0x37C);

	VALIDATE(CCop, field_380, 0x380);
	VALIDATE(CCop, field_384, 0x384);

	VALIDATE(CCop, field_390, 0x390);
	VALIDATE(CCop, field_391, 0x391);
}

void validate_CCopPing(void)
{
	VALIDATE_SIZE(CCopPing, 0x80);

	VALIDATE(CCopPing, field_70, 0x70);
	VALIDATE(CCopPing, field_78, 0x78);
}

void validate_CCopBulletTracer(void)
{
	VALIDATE_SIZE(CCopBulletTracer, 0x48);

	VALIDATE(CCopBulletTracer, field_3C, 0x3C);
	VALIDATE(CCopBulletTracer, field_40, 0x40);
}
