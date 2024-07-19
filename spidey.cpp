#include "spidey.h"
#include "validate.h"
#include "mem.h"
#include "camera.h"
#include "screen.h"
#include "ps2funcs.h"
#include <cmath>
#include "ps2lowsfx.h"
#include "ps2redbook.h"
#include "utils.h"
#include "m3dutils.h"
#include "bit.h"
#include "trig.h"
#include "m3dcolij.h"
#include "m3dzone.h"
#include "ps2lowsfx.h"

EXPORT CPlayer* MechList;
EXPORT CVector gGlobalNormal;
extern i32 CurrentSuit;

// @Ok
u8 CPlayer::IncreaseWebbing(i32 amount)
{
	if (this->field_E2 <= 0)
		return 0;

	i32 v3 = 10;
	if (CurrentSuit == 6 || CurrentSuit == 9 || CurrentSuit == 10)
		v3 = 2;

	if ( (this->mWebbing >= 4096 || this->field_5E8) && this->field_5D8 >= v3)
		return 0;

	this->mWebbing += amount;

	if (this->mWebbing > 4096)
	{
		if (this->field_5D8 < v3)
		{
			this->field_5D8++;
			this->mWebbing -= 4096;
			this->field_5DC = *gTimerRelated;
			this->field_5D0++;
			return 1;
		}

		this->mWebbing = 4096;
	}

	this->field_5D0++;
	return 1;
}

// @SMALLTODO
void CPlayer::SetStartOrientation(CSVector* pVector)
{
	SVECTOR a1;
	MATRIX a2;

	a1.vx = 0;
	a1.vy = pVector->vy;
	a1.vz = 0;

	M3dMaths_RotMatrixYXZ(&a1, &a2);
	MulMatrix(&this->field_164, &a2);
	this->OrientToNormal(0, &gGlobalNormal);
}

// @NotOk
// validate later
void CPlayer::CreateFists(unsigned char a2)
{
	if (a2 & 1)
	{
		this->field_194 &= 0xFFFFFFDF;
		this->field_194 |= 0x40;
	}
	else
	{
		this->field_194 &= 0xFFFFFFBF;
		this->field_194 |= 0x20;
	}

	if (a2 & 2)
	{
		this->field_194 &= 0xFFFFFBFF;
		this->field_194 |= 0x800;
	}
	else
	{
		this->field_194 &= 0xFFFFF7FF;
		this->field_194 |= 0x400;
	}
}

// @Ok
void CPlayer::SetIgnoreInputTimer(int a2)
{
	this->field_E18 = a2;
	if (a2)
	{
		this->field_E12 = this->csuperend;
		if (this->field_8EA)
		{
			this->ExitLookaroundMode();
		}
	}
}

// @Ok
void CPlayer::SetCamAngleLock(unsigned __int16 a1)
{
	if (a1)
	{
		this->gCamAngleLock = 0;
	}
	else
	{
		this->gCamAngleLock = 1;
	}
}

static CCamera * const gGlobalThisCamera = (CCamera*)0x69696969;
static int * const dword_660F80 = (int*)0x660F80;
static int * const dword_60F76C = (int*)0x60F76C;

// @NotOk
// globals need to replace
void CPlayer::ExitLookaroundMode(void)
{
	if (this->field_8EA)
	{
		int c90 = this->field_C90;
		this->field_CB4 = 0;
		this->field_CE4 = 0;
		this->field_56C = 0;
		this->field_8EA = 0;

		*dword_660F80 = 0;
		*dword_60F76C = 0;


		if (c90)
		{
			Mem_Delete(reinterpret_cast<void*>(c90));
			this->field_C90 = 0;
		}

		gGlobalThisCamera->PopMode();
		this->PutCameraBehind(0);
		this->field_DE4 = 0;
		Screen_TargetOn(false);

		__int16 *v3 = reinterpret_cast<__int16*>(this->field_188);
		if (v3)
		{
			v3[6] = 0;
			v3[7] = 0;
			v3[18] = 0;
			v3[19] = 0;
		}
	}
}

static int * const dword_6A81FC = (int*)0x6A81FC;
static int * const dword_6A8208 = (int*)0x6A8208;
static int * const dword_6A8260 = (int*)0x6A8260;

// @NotOk
// Remove globals, there's an extra test for some reason
void CPlayer::SetSpideyLookaroundCamValue(unsigned __int16 a1, unsigned __int16 a2, __int16 a3)
{
	unsigned int actualA1 = a1;
	if (actualA1)
	{
		actualA1--;
		if (actualA1)
		{
			actualA1--;
			if (!actualA1)
			{
				if (a2)
				{
					print_if_false(0, "Bad spidey cam param type");
				}
				else
				{
					*dword_6A8208 = a3;
				}
			}
		}
		else
		{
			if (a2)
			{
				print_if_false(0, "Bad spidey cam param type");
			}
			else
			{
				*dword_6A81FC = a3;
			}
		}

	}
	else if (a2)
	{
		print_if_false(0, "Bad spidey cam param type");
	}
	else
	{
		*dword_6A8260 = a3;
	}
}

// @Ok
// slightly different register allocation
void CPlayer::SetTargetTorsoAngleToThisPoint(CVector *a2)
{
	gte_SetRotMatrix(&this->field_89C);


	CVector v8;
	v8.vx = (a2->vx - this->mPos.vx) >> 12;
	v8.vy = (a2->vy - this->mPos.vy) >> 12;
	v8.vz = (a2->vz - this->mPos.vz) >> 12;

	gte_ldlvl(reinterpret_cast<VECTOR*>(&v8));
	gte_rtir();
	gte_stlvnl(reinterpret_cast<VECTOR*>(&v8));

	__int16 v6 = (1024 - ratan2(-v8.vz, -v8.vx)) & 0xFFF;

	__int16 v7;
	if (this->field_8E9)
	{
		v7 = this->GetEffectiveHeading() - v6;
	}
	else
	{
		v7 = this->GetEffectiveHeading() + v6;
	}

	this->SetTargetTorsoAngle(v7 & 0xFFF, 0);
}

// @Ok
__int16 CPlayer::GetEffectiveHeading(void)
{ 
	if (!this->field_8E8)
	{
		return (1024 - ratan2(this->field_C6C.vz, this->field_C6C.vx)) & 0xFFF;
	}

	CVector fourth;
	fourth.vx = 0;
	fourth.vy = -4096;
	fourth.vz = 0;

	CVector second;
	second.vx = 0;
	second.vy = 0;
	second.vz = 0;

	gte_ldopv1(reinterpret_cast<VECTOR*>(&fourth));
	gte_ldopv2(reinterpret_cast<VECTOR*>(&this->field_C84));
	gte_op12();
	gte_stlvnl(reinterpret_cast<VECTOR*>(&second));
	VectorNormal(reinterpret_cast<VECTOR*>(&second), reinterpret_cast<VECTOR*>(&second));

	CVector first;
	first.vx = 0;
	first.vy = 0;
	first.vz = 0;

	gte_ldopv1(reinterpret_cast<VECTOR*>(&second));
	gte_ldopv2(reinterpret_cast<VECTOR*>(&this->field_C84));
	gte_op12();
	gte_stlvnl(reinterpret_cast<VECTOR*>(&first));

	first.vx = -first.vx;
	first.vy = -first.vy;
	first.vz = -first.vz;

	gte_SetRotMatrix(&this->field_89C);
	gte_ldlvl(reinterpret_cast<VECTOR*>(&first));
	gte_rtir();

	CVector third;
	third.vx = 0;
	third.vy = 0;
	third.vz = 0;

	gte_stlvnl(reinterpret_cast<VECTOR*>(&third));

	return (ratan2(third.vz, third.vx) + 1024) & 0xFFF;
}

// @MEDIUMTODO
void CPlayer::SetTargetTorsoAngle(__int16, int)
{
}


static int * const dword_60CFE8 = (int*)0x60CFE8;
static int * const dword_54D474 = (int*)0x54D474;
static char * const byte_682770 = (char*)0x682770;
extern int CurrentSuit;

// @NotOk
// Globals
// The part with >> 12 has a jump in the original rather than it's perfect
char CPlayer::DecreaseWebbing(int a2)
{
	if (!this->field_1AC &&
			!*dword_60CFE8 &&
			CurrentSuit != 3 &&
			CurrentSuit != 4)
	{
		int v3;
		int v4;

		int tmpDword = *dword_54D474;
		if (!tmpDword)
		{
			v3 = a2 << 7;
			v4 = v3 >> 12;
		}
		else if (tmpDword == 1)
		{
			v3 = a2 << 11;
			v4 = v3 >> 12;
		}

		int v5 = this->mWebbing;
		if (v5 > v4)
		{
			this->mWebbing = v5 - v4;
			return 1;
		}

		int v7 = this->field_5D8;
		if (v7)
		{
			this->mWebbing = v5 - v4 + 4096;
			this->field_5D8 = v7 - 1;
			SFX_PlayPos(0x1E, &this->mPos, 0);
			this->field_5E8 = 0;
			return 1;
		}

		if (!this->field_E10)
		{
			if (!*byte_682770)
			{
				Redbook_XAPlay(33, Rnd(3) + 2, 0);
			}

			this->field_5E8 = 0;
			return 0;
		}

		return 1;
	}

	return 1;
}


static CVector * const stru_56F1B4 = (CVector*)0x56F1B4;
static MATRIX * const stru_56F224 = (MATRIX*)0x56F224;

// @NotOk
// Globals
// Can be optimized (remove tmp)
// gte_ldlv0 is dangerous it reads more memory than needed
void CPlayer::RenderLookaroundReticle(void)
{
	if (this->field_DE4)
	{

		CVector tmp = *stru_56F1B4;
		CVector vec  = (this->field_DC0 >> 12) - tmp;
		
		gte_SetRotMatrix(stru_56F224);
		m3d_ZeroTransVector();
		gte_ldlv0(reinterpret_cast<VECTOR*>(&vec));
		gte_rtps();

		int v5;
		gte_stlvnl2(&v5);

		__int16 v6[2];
		gte_stsxy(reinterpret_cast<int*>(v6));

		int v3 = 3072 - v5;
		if (v3 < 768)
		{
			v3 = 768;
		}

		this->DrawRecticle(v6[0], v6[1], v3);
	}
}

// @BIGTODO
void CPlayer::DrawRecticle(unsigned __int16, unsigned __int16, unsigned int)
{}


// @Ok
// instead of sub 0x1000 we do add 0xFFFFF000, dunno why
// also abs is different but wtv
void CPlayer::SetTargetTorsoAngle(__int16 a2, bool a3)
{
	int v4 = (a2 & 0xFFF);
	__int16 EffectiveHeading = this->GetEffectiveHeading();

	if ( (__int16)v4 == EffectiveHeading)
	{
		this->field_DF8 = 0;
		return;
	}

	int v6 = this->field_E1C;
	if (v6 & 6)
		this->field_DF8 = 5 * this->field_DFC;
	else
		this->field_DF8 = 10;


	if (v6 & 0x2000000)
		this->field_DF8 <<= 1;

	this->field_DF0 = v4;

	int v7;
	if (v4 > EffectiveHeading)
	{
		v7 = v4 - EffectiveHeading;
		if ( v7 >= 2048 )
			v7 = (__int16)(v4 - 0x1000) - EffectiveHeading;
	}
	else
	{
		int v8 = EffectiveHeading;
		if ( EffectiveHeading - v4 >= 2048 )
			v8 = (__int16)(EffectiveHeading - 0x1000);
		v7 = v4 - v8;
	}

	int v9 = this->field_DF8;
	int v10 = v7 / v9;
	bool v11 = this->field_AD4 == 0;
	this->field_DF4 = v7 / v9;
	int v12 = 384;
	if ( v11 )
		v12 = 512;
	int v13 = v12 / v9;
	if ( a3 )
		v13 <<= 1;
	if ( v10 > v13 )
	{
		this->field_DF4 = v13;
		this->field_DF8 = abs(v7 / v13);
	}
	if ( this->field_DF4 < -v13 )
	{
		this->field_DF4 = -v13;
		this->field_DF8 = abs(v7 / v13);
	}
}

static __int16 * const word_6A8C66 = (__int16*)0x6A8C66;
static __int16 * const word_610C4A = (__int16*)0x610C4A;
static __int16 * const word_610C48 = (__int16*)0x610C48;

// @NotOk
// globals
void CPlayer::PutCameraBehind(int a2)
{
	if (!this->gCamAngleLock)
	{
		if (!this->field_8E8)
		{
			gGlobalThisCamera->SetCamAngle(this->GetEffectiveHeading(), a2);
		}
		else
		{
			int v5 = (1024 - ratan2(this->field_C84.vz, this->field_C84.vx)) & 0xFFF;
			gGlobalThisCamera->SetCamAngle(v5, a2);

			if (gGlobalThisCamera->mMode == 3)
			{
				if ((this->field_E2E | this->field_E2D) && this->field_E1C == 16)
				{
					int v6 = 2 * (this->field_E2D & 0xFFF);
					gGlobalThisCamera->SetCamYDistance(*word_6A8C66 + ((500 * word_6A8C66[v6]) >> 12), a2);
					gGlobalThisCamera->SetCamAngle(v5 + ((700 * word_610C48[v6]) >> 12), a2);
				}
				else
				{
					gGlobalThisCamera->SetCamYDistance(*word_6A8C66, a2);
				}
			}
		}


	}
}


// @NotOk
// not matching become smoke trai lhas no cosntructor so it's inlined af
void CPlayer::CreateJumpingSmashKickTrail(void)
{
	CVector vec;
	vec.vx = 0;
	vec.vy = 0;
	vec.vz = 0;

	if (!this->field_584)
	{
		M3dUtils_GetHookPosition(reinterpret_cast<VECTOR*>(&vec),
				this,
				5);

		int args = this->field_580;
		CSmokeTrail *smokeTrail = new CSmokeTrail(
				&vec,
				4,
				args,
				*(reinterpret_cast<unsigned char*>(&args) + 2),
				*(reinterpret_cast<unsigned char*>(&args) + 1));

		this->field_584 = smokeTrail;
	}

	if (!this->field_588)
	{
		M3dUtils_GetHookPosition(reinterpret_cast<VECTOR*>(&vec),
				this,
				6);

		int args = this->field_580;
		CSmokeTrail *smokeTrail = new CSmokeTrail(
				&vec,
				4,
				static_cast<unsigned char>(args),
				*(reinterpret_cast<unsigned char*>(&args) + 2),
				*(reinterpret_cast<unsigned char*>(&args) + 1));

		this->field_588 = smokeTrail;
	}
}


// @NotOk
// missing destructor call
void CPlayer::PlaySingleAnim(int a2, int a3, int a4)
{
	// smoehting missing here
	this->RunAnim(a2, a3, a4);
}

// @BIGTODO
void CPlayer::OrientToNormal(bool, CVector*)
{
	printf("CPlayer::OrientToNormal");
}

// @BIGTODO
void CPlayer::PriorToVenomDistanceAttack(CVector)
{}

// @BIGTODO
void CPlayer::SwitchToStandMode(void)
{}

// @NotOk
// Globals
// raw memory accesses
void CPlayer::CutSceneSkipCleanup(void)
{
	Redbook_XAStop();

	if (gGlobalThisCamera->mMode != 3 && Trig_GetLevelId() != 514)
	{
		gGlobalThisCamera->SetMode(static_cast<ECameraMode>(3));
	}

	int v3 = this->field_1A8;
	CVector v14;
	v14.vx = 0;
	v14.vy = 0;
	v14.vz = 0;


	if (v3)
	{
		int* ptr = reinterpret_cast<int*>(Trig_GetLinksPointer(v3));
		if (ptr[0])
		{
			Trig_GetPosition(&v14, ptr[1]);

			v14.vy = 0;
			v14.vx = (this->mPos.vx - v14.vx) >> 12;
			v14.vz = (this->mPos.vz - v14.vz) >> 12;
			VectorNormal(
					reinterpret_cast<VECTOR*>(&v14),
					reinterpret_cast<VECTOR*>(&v14));

			this->field_A8 = 0;
			this->field_AA = -4096;
			this->field_AC = 0;
		}
		else
		{
			v14 = this->field_C6C;
		}

		this->PriorToVenomDistanceAttack(v14);
	}

	this->PlaySingleAnim(0, 0, -1);
	this->SwitchToStandMode();
	gGlobalThisCamera->SetStartPosition();

	char * v13 = reinterpret_cast<char*>(this->field_E0C);
	*(v13  + 256) = 1;
	*(v13  + 48) = 1;

}

// @NotOk
// globals
// variables
void CPlayer::TidyUpZipWebLandingPosition(int a2)
{
	SLineInfo v21;

	int v2 = 0;

	v21.field_18 = 0;
	v21.field_1C = 0;
	v21.field_20 = 0;
	v21.field_24 = 0;
	v21.field_28 = 0;
	v21.field_2C = 0;

	v21.field_6C = 0;
	v21.field_70 = 0;
	v21.field_74 = 0;
	v21.field_78 = 0;
	v21.field_7A = 0;
	v21.field_7C = 0;

	int i = 0;
	do
	{
		int y = this->mPos.vy;
		int v6 = 2 * (i & 0xFFF);

		int v7 = word_610C4A[v6];
		int v8 = word_610C48[v6];

		int v9 = v2 * (((this->field_C78 * v7) >> 12) + ((this->field_C6C.vx * v8) >> 12));
		int v10 = this->field_C7C * v7;
		int v11 = this->field_C80 * v7;

		v21.vec_0.vx = v9 + this->mPos.vx;
		int v12 = (v10 >> 12) + ((this->field_C6C.vy * v8) >> 12);
		v2 = a2;
		int v13 = a2 * v12;
		int v14 = (v11 >> 12) + ((this->field_C6C.vz * v8) >> 12);
		int z = this->mPos.vz;

		int v16 = a2 * v14;
		v21.vec_0.vy = v13 + y;
		v21.vec_0.vz = v16 + z;
		v21.vec_C.vx = this->mPos.vx - v9;

		int v17 = this->mPos.vy;
		v21.vec_C.vy = v17 - v13;
		v21.vec_C.vz = z - v16;
		M3dColij_InitLineInfo(&v21);
		M3dZone_LineToItem(&v21, 1);
		if ( v21.field_68 )
		{
			int v18 = a2 * v21.field_7C;
			int v19 = v17 + a2 * v21.field_7A;
			this->mPos.vx += a2 * v21.field_78;
			this->mPos.vy = v19;
			this->mPos.vz = z + v18;
		}

		i += 512;
	}while(i<4096);
}

static const char* gUserFunctionName;
static unsigned int gUserFunctionSize;

// @NotOk
// global
void Spidey_SetUserFunction(const char *a1, unsigned int a2)
{
	gUserFunctionName = a1;
	gUserFunctionSize = a2;
}

// @Ok
unsigned char CPlayer::CanITalkRightNow(void)
{
	if (this->field_E1C & 0x800080)
		return 0;
	return 1;
}

// @Ok
unsigned char CPlayer::SetFireWebbing(void)
{
	this->field_5E8 = 1;
	this->mWebbing = 4096;
	this->field_5D0++;
	return 1;
}

// @Ok
void __inline CPlayer::GetHookPosition(CVector* a2, unsigned char a3)
{
	M3dUtils_GetHookPosition(reinterpret_cast<VECTOR*>(a2), this, a3);
}

// @NotOk
// revisit without casts
void CPlayer::DestroyJumpingSmashKickTrail(void)
{
	if (this->field_584)
	{
		int *tmp = reinterpret_cast<int*>(this->field_584);
		tmp[21] = 1;
		this->field_584 = NULL;
	}

	if (this->field_588)
	{
		int *tmp = reinterpret_cast<int*>(this->field_588);
		tmp[21] = 1;
		this->field_588 = NULL;
	}
}

// @NotOk
// revisit without casts
void CPlayer::DestroyHandTrails(void)
{
	if (this->field_58C)
	{
		int *tmp = reinterpret_cast<int*>(this->field_58C);
		tmp[21] = 1;
		this->field_58C = NULL;
	}

	if (this->field_590)
	{
		int *tmp = reinterpret_cast<int*>(this->field_590);
		tmp[21] = 1;
		this->field_590 = NULL;
	}
}

// @Ok
void CPlayer::DeleteStuff(void)
{
	Screen_TargetOn(false);
	if (this->field_C90)
	{
		Mem_Delete(reinterpret_cast<void*>(this->field_C90));
		this->field_C90 = 0;
	}
}

// @Ok
void CPlayer::StopAlertMusic(void)
{
	this->field_52C = 0;
	this->field_528 = 0;
	if (this->field_538)
	{
		SFX_Stop(this->field_538);
		this->field_538 = 0;
	}
}

// @BIGTODO
__inline int* CPlayer::KillCommandBlock(int*)
{
	return (int*)0x02062024;
}

// @NotOk
// Revisit
void CPlayer::KillAllCommandBlocks(void)
{
	for (int* cur = reinterpret_cast<int*>(this->field_1BC); cur; cur = this->KillCommandBlock(cur));
	this->field_1BC = 0;
}

// @Ok
void CPlayer::Die(void)
{
	if (!this->IsDead())
	{
		this->mCBodyFlags |= 0x40;
		this->mFlags |= 1;
	}
}

void validate_CPlayer(void)
{
	VALIDATE_SIZE(CPlayer, 0xEFC);

	VALIDATE(CPlayer, field_194, 0x194);

	VALIDATE(CPlayer, field_1A8, 0x1A8);
	VALIDATE(CPlayer, field_1AC, 0x1AC);

	VALIDATE(CPlayer, field_1BC, 0x1BC);

	VALIDATE(CPlayer, field_528, 0x528);
	VALIDATE(CPlayer, field_52C, 0x52C);
	VALIDATE(CPlayer, field_538, 0x538);

	VALIDATE(CPlayer, field_568, 0x568);
	VALIDATE(CPlayer, field_56C, 0x56C);

	VALIDATE(CPlayer, field_580, 0x580);

	VALIDATE(CPlayer, field_584, 0x584);
	VALIDATE(CPlayer, field_588, 0x588);

	VALIDATE(CPlayer, field_58C, 0x58C);
	VALIDATE(CPlayer, field_590, 0x590);

	VALIDATE(CPlayer, field_5D0, 0x5D0);
	VALIDATE(CPlayer, mWebbing, 0x5D4);
	VALIDATE(CPlayer, field_5D8, 0x5D8);
	VALIDATE(CPlayer, field_5DC, 0x5DC);

	VALIDATE(CPlayer, field_5E8, 0x5E8);

	VALIDATE(CPlayer, field_89C, 0x89C);

	VALIDATE(CPlayer, field_8E8, 0x8E8);
	VALIDATE(CPlayer, field_8E9, 0x8E9);
	VALIDATE(CPlayer, field_8EA, 0x8EA);

	VALIDATE(CPlayer, gCamAngleLock, 0x8EC);

	VALIDATE(CPlayer, field_AD4, 0xAD4);

	VALIDATE(CPlayer, field_C78, 0xC78);
	VALIDATE(CPlayer, field_C7C, 0xC7C);
	VALIDATE(CPlayer, field_C80, 0xC80);
	VALIDATE(CPlayer, field_C84, 0xC84);

	VALIDATE(CPlayer, field_C90, 0xC90);
	VALIDATE(CPlayer, field_CB4, 0xCB4);
	VALIDATE(CPlayer, field_CE4, 0xCE4);

	VALIDATE(CPlayer, field_DC0, 0xDC0);
	VALIDATE(CPlayer, field_DE4, 0xDE4);


	VALIDATE(CPlayer, field_DF0, 0xDF0);
	VALIDATE(CPlayer, field_DF4, 0xDF4);
	VALIDATE(CPlayer, field_DF8, 0xDF8);
	VALIDATE(CPlayer, field_DFC, 0xDFC);

	VALIDATE(CPlayer, field_E00, 0xE00);
	VALIDATE(CPlayer, field_E0C, 0xE0C);

	VALIDATE(CPlayer, field_E10, 0xE10);
	VALIDATE(CPlayer, field_E12, 0xE12);
	VALIDATE(CPlayer, field_E18, 0xE18);
	VALIDATE(CPlayer, field_E1C, 0xE1C);

	VALIDATE(CPlayer, field_E2D, 0xE2D);
	VALIDATE(CPlayer, field_E2E, 0xE2E);

}
