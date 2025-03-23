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
#include "ps2m3d.h"
#include "web.h"
#include "camera.h"

static SStateFlags gSimbyFlags;
extern CPlayer* MechList;
extern CBaddy* BaddyList;
extern i32 gAttackRelated;
extern i16 **gTrigNodes;

extern CBody *MiscList;
extern CCamera* CameraList;

// @Ok
// @Matching
void Simby_TestDrop(const u32 *, u32 *)
{
}

// @Ok
// @Matching
void Simby_CreateFlamingImpactWeb(const u32* stack,u32 *)
{
	CVector v6;
	v6.vx = stack[0];
	v6.vy = stack[1];
	v6.vz = stack[2];

	CSVector v5;
	v5.vx = stack[3];
	v5.vy = stack[4];
	v5.vz = stack[5];

	new CFlamingImpactWeb(&v6, &v5, stack[6]);
}

// @Ok
// @Matching
void Simby_RelocatableModuleClear(void)
{
	CItem *pSearch = BaddyList;

	while (pSearch)
	{
		CItem *pNext = pSearch->mNextItem;

		if (pSearch->mType == 324)
			delete pSearch;

		pSearch = pNext;
	}
}

// @Ok
// @Matching
void Simby_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Simby_RelocatableModuleClear;
	pMod->field_C[0] = Simby_CreateSimby;
	pMod->field_C[1] = Simby_CreateSimbyDroplet;
	pMod->field_C[2] = Simby_CreateFlamingImpactWeb;
	pMod->field_C[3] = Simby_TestDrop;
	pMod->field_C[4] = Simby_CreatePunchOb;
	pMod->field_C[5] = Simby_CreateEmber;
}

// @SMALLTODO
CFlamingImpactWeb::CFlamingImpactWeb(CVector*, CSVector*, i32)
{
	printf("CFlamingImpactWeb::CFlamingImpactWeb(CVector*, CSVector*, i32);");
}

// @Ok
CFlamingImpactWeb::~CFlamingImpactWeb(void)
{
}

// @Ok
CEmber::~CEmber(void)
{
}

// @Ok
void Simby_CreatePunchOb(const u32 *stack, u32 *result)
{
	i16* v2 = reinterpret_cast<i16*>(stack[0]);
	i32 v3 = static_cast<i32>(stack[1]);

	*result = reinterpret_cast<u32>(new CPunchOb(v2, v3));
}

// @Ok
void Simby_CreateSimbyDroplet(const u32 *stack, u32 *result)
{
	i16* v2 = reinterpret_cast<i16*>(stack[0]);
	i32 v3 = static_cast<i32>(stack[1]);

	*result = reinterpret_cast<u32>(new CSimbyDroplet(v2, v3));
}

// @Ok
void CSymBurn::AI(void)
{
	if ( CameraList )
		this->mAngles.vy = CameraList->field_236 + 2048;
	this->mScale.vx = 3000;
	this->mScale.vz = 3000;

	if ( ++this->field_1A4 > 60 )
	{
		i32 v4 = (this->mRGB & 0xFF) - 4;
		if ( v4 < 0 )
			v4 = 0;
		this->mRGB = v4 | ((v4 | (v4 << 8)) << 8);

		this->mScale.vy -= 75;
		if ( this->mScale.vy < 0 )
			this->mScale.vy = 0;

		if ( !v4 || !this->mScale.vy )
		{
			this->Die();
		}
	}
	else
	{
		i32 v7 = (this->mRGB & 0xFF) - 129;
		if ( v7 < 128 )
			v7 = 128;

		this->mRGB = v7 | ((v7 | (v7 << 8)) << 8);

		this->mScale.vy += 800;
		if ( this->mScale.vy > 4096 )
			this->mScale.vy = 4096;
	}

	M3d_BuildTransform(this);
}

// @NotOk
// globals
CSymBurn::~CSymBurn(void)
{
	this->DeleteFrom(&MiscList);
	(*reinterpret_cast<i32*>(0x60CF94)) -= 1;
}


// @NotOk
// globals
CSymBurn::CSymBurn(CVector *a2)
{
	this->mPos = *a2;
	this->InitItem("fire");
	this->mFlags |= 0x602u;
	this->mScale.vy = 0;
	this->mRGB = 0xFFFFFF;

	this->AttachTo(&MiscList);
	(*reinterpret_cast<i32*>(0x60CF94)) += 1;
}

// @Ok
void CSimbyDroplet::Move(void)
{
	this->mPos.vy += this->mVel.vy;
	this->mVel.vy += this->field_6A;
	this->field_C++;

	if (this->mPos.vy > this->field_6C || this->field_C > 60)
	{
		Trig_SendPulse(reinterpret_cast<u16*>(&gTrigNodes[this->field_68][3]));
		this->Die();
	}
}

// @Ok
CSimbyDroplet::~CSimbyDroplet(void)
{
}

// @NotOk
// @Test
// globals
CSimbyDroplet::CSimbyDroplet(i16* a2, i32 NodeIndex)
{
	print_if_false(NodeIndex != 0xFFFF, "Bad NodeIndex sent to CSimbyDroplet");
	this->field_68 = NodeIndex;

	CVector *pPos = reinterpret_cast<CVector*>(a2);
	this->mPos.vx = pPos->vx << 12;
	this->mPos.vy = pPos->vy << 12;
	this->mPos.vz = pPos->vz << 12;

	this->SetTexture(*(Texture **)(*reinterpret_cast<i32*>(0x56EAC4) + 12));

	this->field_6A = a2[12];
	this->SetScale(800);
	this->SetSemiTransparent();
	this->field_6C = Web_GetGroundY(&this->mPos);
	this->mType = 14;
}

// @Ok
void CFireySpark::Move(void)
{
	this->mPos.vx += this->mVel.vx;
	this->mPos.vy += this->mVel.vy;
	this->mPos.vz += this->mVel.vz;

	if ( this->mPos.vy > this->field_4C )
	{
		this->mPos.vy = this->field_4C;
		this->mVel.vx >>= 1;
		this->mVel.vz >>= 1;
	}

	this->mVel.vy += 29584;

	if ( this->field_40 >= this->field_48 )
		this->field_40 -= this->field_48;
	else
		this->field_40 = 0;

	if ( this->field_41 >= this->field_48 )
		this->field_41 -= this->field_48;
	else
		this->field_41 = 0;

	if ( this->field_42 >= this->field_48 )
		this->field_42 -= this->field_48;
	else
		this->field_42 = 0;

	if ( !(this->field_40 | (this->field_42 | this->field_41)) )
		this->Die();
}

// @Ok
CFireySpark::~CFireySpark(void)
{
}

// @Ok
CFireySpark::CFireySpark(CVector* a2, CVector* a3, i32 a4)
{
	this->mPos = *a2;
	this->mVel = *a3;

	this->field_4C = a4;

	if (Rnd(2))
	{
		this->field_43 = 106;
		this->field_3C = 0x2000000;
		this->field_44 = 1;
	}
	else
	{
		this->field_43 = 98;
		this->field_3C = 50331648;
		i32 v6 = Rnd(2) + 2;
		this->field_44 = (v6 << 16) | (v6 + 1);
	}

	this->field_40 = -1;
	this->field_41 = 0x80;
	this->field_42 = 0;
	this->field_48 = Rnd(10) + 10;
	this->mType = 16;
}

// @Ok
void CPunchOb::AI(void)
{
	if (this->pMessage)
		this->CleanUpMessages(1, 0);

	if (this->field_142)
		this->RunAnim(0, 0, -1);

	M3d_BuildTransform(this);

	if ( !(gAttackRelated & 0xF)
			&& this->field_31C.bothFlags != 1
			&& Mem_RecoverPointer(&this->field_104))
	{
		this->field_31C.bothFlags = 1;
		this->dumbAssPad = 0;
	}

	switch (this->field_31C.bothFlags)
	{
		case 1:
			switch (this->dumbAssPad)
			{
				case 0:
					this->field_1F8 += this->field_80;
					if (this->field_1F8 > 180)
					{
						this->mFlags |= 0x200;
						this->dumbAssPad = 1;
					}
					break;
				case 1:
					this->mScale.vz += 512;

					this->mScale.vy = this->mScale.vz;
					this->mScale.vx = this->mScale.vz;

					if (this->mScale.vz >= 6144)
					{
						CTrapWebEffect *pTrap = reinterpret_cast<CTrapWebEffect*>(Mem_RecoverPointer(&this->field_104));

						if (pTrap)
							pTrap->Burst();

						this->dumbAssPad++;
					}
					break;
				case 2:
					this->mScale.vz -= 256;

					this->mScale.vy = this->mScale.vz;
					this->mScale.vx = this->mScale.vz;

					if (this->mScale.vz <= 4096)
					{
						this->mFlags &= 0xFDFF;
						this->field_31C.bothFlags = 0;
						this->dumbAssPad = 0;
					}

					break;
				default:
					print_if_false(0, "Unknown substate.");
					break;
			}
			break;
	}

	if (this->mInputFlags & 1)
	{
		SHitInfo v9;
		v9.field_8 = this->mHealth;
		v9.field_C.vx = 0;
		v9.field_C.vy = 0;
		v9.field_C.vz = 0;

		v9.field_0 = 4;
		this->Hit(&v9);
	}
}

// @BIGTODO
void Simby_SplattyExplosion(CVector*, CVector*, i32)
{}

// @Ok
i32 CPunchOb::Hit(SHitInfo* pHitInfo)
{
	if (this->mHealth <= 0)
		return 0;

	if (pHitInfo->field_0 & 2 && pHitInfo->field_4 == 7)
		pHitInfo->field_8 = this->mHealth;

	if (pHitInfo->field_0 & 4)
	{
		this->mHealth -= pHitInfo->field_8;

		i32 v7 = 8;

		CVector v9;
		v9.vx = 0;
		v9.vy = 0;
		v9.vz = 0;

		Utils_GetVecFromMagDir(&v9, 4096, &this->mAngles);
		v9 >>= 12;

		if (this->mHealth <= 0)
		{
			v7 = 16;
			this->SendPulse();
			this->Die(0);
		}
		Simby_SplattyExplosion(&this->mPos, &v9, v7);
	}

	return 1;
}

// @Ok
CPunchOb::~CPunchOb(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
}

// @Ok
CPunchOb::CPunchOb(
		i16* a2,
		i32 a3)
{
	this->InitItem("sym_gen");
	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));

	this->mCBodyFlags |= 0x10;
	this->mNode = a3;

	this->mType = 412;
	this->field_2A8 |= 2;
	this->mRMinor = 100;

	u16* v6 = reinterpret_cast<u16*>(
			this->SquirtAngles(reinterpret_cast<i16*>(
				this->SquirtPos(reinterpret_cast<i32*>(a2)))
			));
	this->RunAnim(0, 0, -1);
	this->ParseScript(v6);
}

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
	this->mType = 324;

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

		this->mRGB = BYTE0(this->mRGB + this->field_32A) | ((BYTE1(this->mRGB) + this->field_32C) << 8) | ((BYTE2(this->mRGB) + this->field_32E) << 16) ;

																							                            

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

			this->mRGB = this->field_330;
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
INLINE void CPunchOb::SendPulse(void)
{
	if (!this->field_328)
	{
		this->field_328 = 1;
		Trig_SendPulse(reinterpret_cast<unsigned __int16*>(Trig_GetLinksPointer(this->mNode)));
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

// @Ok
// @Validate
CSkidMark::CSkidMark(void)
{
	this->SetTexture(gAnimTable[25]->pTexture);
	this->SetSemiTransparent();
	this->SetTint(0x2Fu, 9, 44);
	this->mType = 18;
}

// @Ok
void CSkidMark::Move(void)
{
	if (++this->field_C > 40)
	{
		Bit_ReduceRGB(&this->mTint, 2);
		if (!(0xFFFFFF & this->mTint))
			this->Die();
	}
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

void validate_CSkidMark(void)
{
	VALIDATE_SIZE(CSkidMark, 0x84);
}

void validate_CFireySpark(void)
{
	VALIDATE_SIZE(CFireySpark, 0x50);

	VALIDATE(CFireySpark, field_3C, 0x3C);
	VALIDATE(CFireySpark, field_40, 0x40);
	VALIDATE(CFireySpark, field_41, 0x41);
	VALIDATE(CFireySpark, field_42, 0x42);
	VALIDATE(CFireySpark, field_43, 0x43);

	VALIDATE(CFireySpark, field_44, 0x44);
	VALIDATE(CFireySpark, field_48, 0x48);

	VALIDATE(CFireySpark, field_4C, 0x4C);
}

void validate_CSimbyDroplet(void)
{
	VALIDATE_SIZE(CSimbyDroplet, 0x70);

	VALIDATE(CSimbyDroplet, field_68, 0x68);
	VALIDATE(CSimbyDroplet, field_6A, 0x6A);
	VALIDATE(CSimbyDroplet, field_6C, 0x6C);
}

void validate_CSymBurn(void)
{
	VALIDATE_SIZE(CSymBurn, 0x1A8);

	VALIDATE(CSymBurn, field_1A4, 0x1A4);

	VALIDATE_VTABLE(CSymBurn, Die, 1);
	VALIDATE_VTABLE(CSymBurn, AI, 2);
}

void validate_CFlamingImpactWeb(void)
{
	VALIDATE_SIZE(CFlamingImpactWeb, 0x90);
}
