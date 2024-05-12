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

// @TODO
__int16 CPlayer::GetEffectiveHeading(void)
{ 
	return 0x32;
}

// @TODO
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

		int v5 = this->field_5D4;
		if (v5 > v4)
		{
			this->field_5D4 = v5 - v4;
			return 1;
		}

		int v7 = this->field_5D8;
		if (v7)
		{
			this->field_5D4 = v5 - v4 + 4096;
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

// @TODO
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
			int v5 = (1024 - ratan2(this->field_C8C, this->field_C84)) & 0xFFF;
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

void validate_CPlayer(void)
{
	VALIDATE_SIZE(CPlayer, 0xEFC);

	VALIDATE(CPlayer, field_1AC, 0x1AC);

	VALIDATE(CPlayer, field_56C, 0x56C);


	VALIDATE(CPlayer, field_5D4, 0x5D4);
	VALIDATE(CPlayer, field_5D8, 0x5D8);

	VALIDATE(CPlayer, field_5E8, 0x5E8);

	VALIDATE(CPlayer, field_89C, 0x89C);

	VALIDATE(CPlayer, field_8E8, 0x8E8);
	VALIDATE(CPlayer, field_8E9, 0x8E9);
	VALIDATE(CPlayer, field_8EA, 0x8EA);

	VALIDATE(CPlayer, gCamAngleLock, 0x8EC);

	VALIDATE(CPlayer, field_AD4, 0xAD4);

	VALIDATE(CPlayer, field_C84, 0xC84);
	VALIDATE(CPlayer, field_C8C, 0xC8C);

	VALIDATE(CPlayer, field_C90, 0xC90);
	VALIDATE(CPlayer, field_CB4, 0xCB4);
	VALIDATE(CPlayer, field_CE4, 0xCE4);

	VALIDATE(CPlayer, field_DC0, 0xDC0);
	VALIDATE(CPlayer, field_DE4, 0xDE4);


	VALIDATE(CPlayer, field_DF0, 0xDF0);
	VALIDATE(CPlayer, field_DF4, 0xDF4);
	VALIDATE(CPlayer, field_DF8, 0xDF8);
	VALIDATE(CPlayer, field_DFC, 0xDFC);

	VALIDATE(CPlayer, field_E10, 0xE10);
	VALIDATE(CPlayer, field_E12, 0xE12);
	VALIDATE(CPlayer, field_E18, 0xE18);
	VALIDATE(CPlayer, field_E1C, 0xE1C);

	VALIDATE(CPlayer, field_E2D, 0xE2D);
	VALIDATE(CPlayer, field_E2E, 0xE2E);

}
