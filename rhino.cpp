#include "rhino.h"
#include "validate.h"
#include "utils.h"
#include "panel.h"
#include "ps2pad.h"
#include "spidey.h"
#include "ps2lowsfx.h"
#include "camera.h"
#include "ai.h"
#include "my_assert.h"


EXPORT i32 gRhinoStrangeInitData[2] = { 0x201, 0 };

EXPORT SLight M3d_RhinoLight =
{
  { { -2430, -2228, -2430 }, { 2509, -2896, 1447 }, { -648, -3711, -1607 } },
  0,
  { { 4800, 1560, 3072 }, { 4080, 2400, 2880 }, { 3600, 3840, 3072 } },
  0,
  { 1800, 1800, 1440 }
};



// @FIXME
#define LEN_RHINO_DATA 0x17
EXPORT SRhinoData gRhinoData[LEN_RHINO_DATA];

#define LEN_RHINO_DAZED_DATA 0x5
EXPORT i16 gRhinoDazedData[LEN_RHINO_DAZED_DATA];

EXPORT u32 gRhinoSound;
extern i32 DifficultyLevel;

u8 gActuatorRelated;
extern CBody* EnvironmentalObjectList;
extern CPlayer* MechList;
extern i32 gAttackRelated;
extern CBaddy *BaddyList;
extern CCamera *CameraList;

// @Ok
// @Matching
void Rhino_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Rhino_RelocatableModuleClear;
	pMod->field_C[0] = Rhino_CreateRhino;
}

// @MEDIUMTODO
void CRhino::AI(void)
{
    printf("CRhino::AI(void)");
}

// @MEDIUMTODO
void CRhino::AttackPlayer(void)
{
    printf("CRhino::AttackPlayer(void)");
}

// @MEDIUMTODO
void CRhino::ChargePlayer(void)
{
    printf("CRhino::ChargePlayer(void)");
}

// @MEDIUMTODO
void CRhino::ChasePlayer(i32)
{
    printf("CRhino::ChasePlayer(i32)");
}

// @SMALLTODO
void CRhino::CheckIfPlayerHit(void)
{
    printf("CRhino::CheckIfPlayerHit(void)");
}

// @MEDIUMTODO
void CRhino::DieRhino(void)
{
    printf("CRhino::DieRhino(void)");
}

// @MEDIUMTODO
void CRhino::DoDazedEffect(void)
{
    printf("CRhino::DoDazedEffect(void)");
}

// @MEDIUMTODO
void CRhino::DoMGSShadow(void)
{
    printf("CRhino::DoMGSShadow(void)");
}

// @Ok
// would love to remove the goto
void CRhino::FollowWaypoints(void)
{
	i32 v6;
	SMoveToInfo v8;
	v8.field_0.vx = 0;
	v8.field_0.vy = 0;
	v8.field_0.vz = 0;

	this->RunAppropriateAnim();

	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->field_310 = 0;

			if (this->field_1F0)
			{
				this->field_2A8 &= ~0x10000000;
				v8.field_0 = this->field_1A8[this->field_1F0];

				v8.field_C = 40;
				v8.field_10 = 40;
				v8.field_14 = 500;

				new CAIProc_MoveTo(this, &v8, 1);
				this->dumbAssPad++;
			}
			else
			{
				this->field_31C.bothFlags = 2;
				this->dumbAssPad = 0;
			}
			break;
		case 1:

			if (this->field_288 & 1)
			{
				this->field_288 &= ~1;
				v6 = 1;
			}
			else
			{
				v6 = 0;
			}

			if (v6)
			{
				if (this->field_1F0)
				{
					this->field_1F0--;
					// @FIXME this makes it match but i don't like it
					goto force_match;
				}
				else if (this->GetNextWaypoint())
				{
force_match:
					if ((this->field_2F0 & 2) == 0)
					{
						this->dumbAssPad = 0;
					}
				}
				else
				{
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

// @Ok
void CRhino::GetLaunched(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->dumbAssPad = 1;
			this->PlaySingleAnim(15, 0, -1);

			new CAIProc_LookAt(this, MechList, 0, 2, 80, 0);
			this->field_230 = Utils_GetValueFromDifficultyLevel(40, 30, 21, 21);

		case 1:
			this->DoPhysics(1);
			this->RunTimer(&this->field_230);
			if (!this->field_1F8)
			{
				this->dumbAssPad++;
				this->mVel.vx = 0;
				this->mVel.vy = 0;
				this->mVel.vz = 0;
			}

			break;
		case 2:
			this->RunTimer(&this->field_230);
			if (!this->field_230)
			{
				if (this->DetermineFightState(1))
				{
					if (this->DistanceToPlayer(0) > 500)
					{
						if (this->field_31C.bothFlags == 5 || this->field_31C.bothFlags == 4)
						{
								this->field_31C.bothFlags = 8;
								this->dumbAssPad = 0;
						}
					}
					else if (this->field_31C.bothFlags == 8)
					{
						this->field_31C.bothFlags = 5;
						this->dumbAssPad = 0;
					}
				}
				else
				{
					this->PlaySingleAnim(0, 0, -1);
					this->field_31C.bothFlags = 22;
					this->dumbAssPad = 0;
				}
			}

			break;
		default:
			print_if_false(0, "Unknown substate");
			break;
	}
}

// @MEDIUMTODO
void CRhino::GetShocked(void)
{
    printf("CRhino::GetShocked(void)");
}

// @MEDIUMTODO
void CRhino::GetTrapped(void)
{
    printf("CRhino::GetTrapped(void)");
}

// @MEDIUMTODO
void CRhino::GonnaHitWall(i32)
{
    printf("CRhino::GonnaHitWall(i32)");
}

// @MEDIUMTODO
void CRhino::LineOfSightCheck(CVector const *,i32)
{
    printf("CRhino::LineOfSightCheck(CVector const *,i32)");
}

// @MEDIUMTODO
void CRhino::PlaySounds(void)
{
    printf("CRhino::PlaySounds(void)");
}

// @SMALLTODO
void CRhino::PlayXAPlease(i32,i32,i32)
{
    printf("CRhino::PlayXAPlease(i32,i32,i32)");
}

// @MEDIUMTODO
void CRhino::SetUpStuckHorn(SLineInfo *,i32)
{
    printf("CRhino::SetUpStuckHorn(SLineInfo *,i32)");
}

// @MEDIUMTODO
void CRhino::SlideFromHit(i32,i32,CVector *)
{
    printf("CRhino::SlideFromHit(i32,i32,CVector *)");
}

// @MEDIUMTODO
void CRhino::StompGround(void)
{
    printf("CRhino::StompGround(void)");
}

// @MEDIUMTODO
void CRhino::StuckInWall(void)
{
    printf("CRhino::StuckInWall(void)");
}

// @Ok
CRhinoNasalSteam::~CRhinoNasalSteam(void)
{
}

// @Ok
// @Matching
void Rhino_RelocatableModuleClear(void)
{
	CItem *pSearch = BaddyList;

	while (pSearch)
	{
		CItem *pNext = pSearch->mNextItem;

		if (pSearch->mType == 307)
			delete pSearch;

		pSearch = pNext;
	}
}


// @MEDIUMTODO
i32 CRhino::DetermineFightState(i32)
{
	printf("i32 CRhino::DetermineFightState(i32)");
	return 0x28072024;
}

// @Ok
void CRhino::TakeHit(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->field_310 = 0;
			new CAIProc_LookAt(this, MechList, 0, 0, 80, 200);
			this->PlaySingleAnim(0xFu, 0, -1);
			this->field_230 = Utils_GetValueFromDifficultyLevel(40, 30, 21, 21);
			this->dumbAssPad++;
			break;
		case 1:
			this->RunTimer(&this->field_230);
			if (!this->field_230)
			{
				if (this->DetermineFightState(1))
				{
					if (this->DistanceToPlayer(0) > 500)
					{
						if (this->field_31C.bothFlags == 5 || this->field_31C.bothFlags == 4)
						{
							this->field_31C.bothFlags = 8;
							this->dumbAssPad = 0;
						}
					}
					else if (this->field_31C.bothFlags == 8)
					{
						this->field_31C.bothFlags = 5;
						this->dumbAssPad = 0;
					}
				}
				else
				{
					this->PlaySingleAnim(0, 0, -1);
					this->field_31C.bothFlags = 22;
					this->dumbAssPad = 0;
				}
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @Ok
void CRhino::HitWall(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->ShakePad();
			CameraList->Shake(&this->mPos, EShake_0x0);
			this->Neutralize();
			this->mCBodyFlags &= ~0x10;
			this->PlaySingleAnim(17, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
			{
				if ( this->field_E2 <= 0 )
				{
					this->field_31C.bothFlags = 21;
					this->dumbAssPad = 0;
				}
				else
				{
					this->PlaySingleAnim(0x12u, 0, -1);
				}
			}
			break;
		case 2:

			if ( this->field_142 )
			{
				if ( this->field_12A == 18 )
				{
					this->mAngles.vy = (this->mAngles.vy - 2048) & 0xFFF;
					this->PlaySingleAnim(0x15u, 0, -1);
				}
				else
				{
					this->mCBodyFlags |= 0x10u;
					this->PlaySingleAnim(0, 0, -1);
	
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

// @NotOk
// figure out types of fields that call destructors
CRhino::~CRhino(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
	Panel_DestroyHealthBar();

	if (this->field_3E0)
		delete reinterpret_cast<CItem*>(this->field_3E0);

	for (i32 i = 0; i < 5; i++)
	{
		if (this->field_3E4[i])
			delete reinterpret_cast<CItem*>(this->field_3E4[i]);
		this->field_3E4[i] = 0;

		if (this->field_3F8[i])
			delete reinterpret_cast<CItem*>(this->field_3F8[i]);
		this->field_3F8[i] = 0;

		if (this->field_40C[i])
			delete reinterpret_cast<CItem*>(this->field_40C[i]);
		this->field_40C[i] = 0;
	}

	gBossRelated = 0;
}

// @Ok
void CRhino::Laugh(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->field_230 = 100;
			this->PlaySingleAnim(20, 0, -1);
			SFX_PlayPos(((gAttackRelated & 1) == 0 ? 1 : 0) | 0x8046, &this->mPos, 0);
			this->dumbAssPad++;

			break;
		case 1:
			this->RunTimer(&this->field_230);
			if (this->field_142)
			{
				if (!this->field_230)
				{
					this->field_31C.bothFlags = 2;
					this->dumbAssPad = 0;
				}
				else
				{
					this->PlaySingleAnim(0, 0, -1);
				}
			}
			break;
		default:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @Ok
void CRhino::RhinoInit(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->field_358 = gAttackRelated - 155;
			i32 GroundHeight;
			GroundHeight = Utils_GetGroundHeight(&this->mPos, 300, 300, 0);
			if ( GroundHeight != -1 )
			{
				this->mPos.vy = GroundHeight - (this->field_21E << 12);
				this->field_29C = this->mPos.vy;
				this->field_2A0 = GroundHeight;
				this->dumbAssPad++;

				this->PlaySingleAnim(0, 0, -1);
			}
			break;
		case 1:
			this->field_31C.bothFlags = 8;
			this->dumbAssPad = 0;
			break;
		default:
			print_if_false(0, "Unknown sub-state!");
			break;
	}
}

// @NotOk
// understand if that's really PlayerIsVisible call
void CRhino::FuckUpSomeBarrels(void)
{
	i32 barrels = 0;

	for (
			CBody* cur = EnvironmentalObjectList;
			cur && barrels < 2;
			cur = reinterpret_cast<CBody*>(cur->mNextItem))
	{
		if (cur->mType == 401)
		{
			if (Utils_CrapDist(this->mPos, cur->mPos) < 0x2BC && cur != MechList->mHeldObject)
			{
				reinterpret_cast<CBaddy*>(cur)->PlayerIsVisible();
				barrels++;
			}
		}
	}
}

// @Ok
void CRhino::StandStill(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->dumbAssPad++;
		case 1:
			if (this->field_12A)
				this->PlaySingleAnim(0, 0, -1);
			break;
		default:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @Ok
INLINE void CRhino::ShakePad(void)
{
	if ( gActuatorRelated )
	{
		if ( Pad_GetActuatorTime(0, 0) <= 2u )
			Pad_ActuatorOn(0, 6u, 0, 1u);
		if ( Pad_GetActuatorTime(0, 1u) <= 2u )
			Pad_ActuatorOn(0, 0xAu, 1, 0xC8u);
	}
}

// @NotOk
// validate when get shocked
i32 CRhino::GetShockDamage(void)
{
	switch ( DifficultyLevel )
	{
		case 0:
		case 1:
			return 175;
		case 2:
			return 125;
		case 3:
			return 75;
		default:
			print_if_false(0, "Unknown difficulty level!");
			return 0;
	}
}

// @NotOk
// validate when playsounds is done
u32 CRhino::GetNextFootstepSFX(void)
{
	u32 res;
	for (res = (Rnd(3) + 76) | 0x8000; res == gRhinoSound; res = (Rnd(3) + 76) | 0x8000)
		;

	return res;
}

// @Ok
INLINE void CRhino::PlaySingleAnim(u32 a2, i32 a3, i32 a4)
{
	this->field_388 = 0;
	this->RunAnim(a2, a3, a4);
}

// @NotOk
// globals
CRhino::CRhino(i16* a2, int a3)
{
	i16 *v5 = this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));
	this->InitItem("rhino");

	this->mFlags |= 0x480;
	// @FIXME
	this->mpLight = &M3d_RhinoLight;
	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));

	this->field_21E = 100;
	this->field_1F4 = a3;
	this->mNode = a3;
	this->field_DC = 175;

	this->field_230 = 0;
	this->field_216 = 32;

	this->mPushVal = 64;
	this->field_31C.bothFlags = 0;
	this->field_2A8 |= 1;
	this->field_2A8 |= 0x200;
	this->field_2A8 |= 0x2000000;

	this->mType = 307;
	this->field_E2 = Utils_GetValueFromDifficultyLevel(1400, 1400, 1400, 1400);

	this->field_294.Int = gRhinoStrangeInitData[0];
	this->field_298.Int = gRhinoStrangeInitData[1];

	this->field_344 = gAttackRelated - 240;

	for (i32 i = 0; i < LEN_RHINO_DAZED_DATA; i++)
	{
		gRhinoDazedData[i] = Rnd(4096);
	}

	for (i32 j = 0; j < LEN_RHINO_DATA; j++)
	{
		if (gRhinoData[j].field_8 != j)
			DoAssert(0, "Fire Matt, he fucked up the rhino XA.  Actually, kick him in the nuts first.");
	}

	this->ParseScript(reinterpret_cast<u16*>(v5));
	Panel_CreateHealthBar(this, 307);
}

// @NotOk
// globals
CRhino::CRhino(void)
{
	this->InitItem("rhino");
	this->mFlags |= 0x480;
	// @FIXME
	this->mpLight = &M3d_RhinoLight;
	this->mType = 307;
}

// @Ok
void Rhino_CreateRhino(const u32 *stack, u32 *result)
{
	i16* v2 = reinterpret_cast<i16*>(*stack);
	i32 v3 = static_cast<i32>(stack[1]);

	if (v2)
	{
		*result = reinterpret_cast<u32>(new CRhino(v2, v3));
	}
	else
	{
		*result = reinterpret_cast<u32>(new CRhino());
	}
}


// @Ok
CRhinoNasalSteam::CRhinoNasalSteam(CVector* a2, CVector* a3)
{
	this->mPos = *a2;
	this->mVel = *a3;

	this->SetAnim(1);
	this->SetSemiTransparent();
	this->SetTransparency(64);
	this->SetAnimSpeed(128);
	this->SetScale(128);
	this->field_58 = Rnd(4096);
}

// @Ok
// minor decomp diff
void CRhinoNasalSteam::Move(void)
{

	__int16 mAnimSpeed = this->mAnimSpeed;

	if (mAnimSpeed)
	{
		unsigned __int16 v3 = (this->field_52 << 8) | this->field_53;
		unsigned __int16 v4 = mAnimSpeed + v3;

		this->field_53 = v4;
		v4 >>= 8;
		this->field_52 = v4;

		if ( (char)v4 >= (int)this->field_51)
		{
			this->mAnimSpeed = 0;
			this->field_52 = this->field_51 - 1;
		}

		int index = this->field_52;
		this->field_4C = &this->mPSXAnim[index];
	}

	this->mPos += this->mVel;

	bool v7 = ++this->field_C <= 30;
	this->mVel.vy -= 1024;

	if (!v7 )
	{
		this->Die();
	}
	else
	{
		this->SetTransparency(64 - 2 * (this->field_C & 0xFF));
		this->SetScale(Rnd(4) + 4 * (this->field_C + 32));
	}
}

void validate_CRhino(void){
	VALIDATE_SIZE(CRhino, 0x424);

	VALIDATE(CRhino, field_344, 0x344);

	VALIDATE(CRhino, field_358, 0x358);
	VALIDATE(CRhino, field_388, 0x388);

	VALIDATE(CRhino, field_3E0, 0x3E0);
	VALIDATE(CRhino, field_3E4, 0x3E4);
	VALIDATE(CRhino, field_3F8, 0x3F8);
	VALIDATE(CRhino, field_40C, 0x40C);
}

void validate_CRhinoNasalSteam(void)
{
	VALIDATE_SIZE(CRhinoNasalSteam, 0x68);
}

void validate_SRhinoData(void)
{
	VALIDATE_SIZE(SRhinoData, 0xC);

	VALIDATE(SRhinoData, field_0, 0x0);
	VALIDATE(SRhinoData, field_2, 0x2);

	VALIDATE(SRhinoData, field_8, 0x8);
}
