#include "rhino.h"
#include "validate.h"
#include "utils.h"
#include "panel.h"
#include "ps2pad.h"
#include "spidey.h"

static __int16 * const word_682B64 = (__int16*)0x682B64;
EXPORT u32 gRhinoSound;
extern i32 DifficultyLevel;

extern u8 gActuatorRelated;
extern CBody* EnvironmentalObjectList;
extern CPlayer* MechList;

// @NotOk
// understand if that's really PlayerIsVisible call
void CRhino::FuckUpSomeBarrels(void)
{
	i32 barrels = 0;

	for (
			CBody* cur = EnvironmentalObjectList;
			cur && barrels < 2;
			cur = reinterpret_cast<CBody*>(cur->field_20))
	{
		if (cur->field_38 == 401)
		{
			if (Utils_CrapDist(this->mPos, cur->mPos) < 0x2BC && cur != MechList->field_E48)
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
void CRhino::ShakePad(void)
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
CRhino::CRhino(int* a2, int a3)
{

	i16 *v5 = this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));
	this->InitItem("rhino");

	this->mFlags |= 0x480;
	this->field_3C = 0x552080;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E990));

	this->field_21E = 100;
	this->field_1F4 = a3;
	this->field_DE = a3;
	this->field_DC = 175;

	this->field_230 = 0;
	this->field_216 = 32;

	this->field_D8 = 64;
	this->field_31C.bothFlags = 0;
	this->field_2A8 |= 0x2000201;
	this->field_38 = 307;
	this->field_E2 = Utils_GetValueFromDifficultyLevel(1400, 1400, 1400, 1400);

	unsigned char * ptr = reinterpret_cast<unsigned char*>(0x552008);
	this->field_294.Bytes[0] = ptr[0];
	this->field_294.Bytes[1] = ptr[1];
	this->field_294.Bytes[2] = ptr[2];
	this->field_294.Bytes[3] = ptr[3];

	this->field_298.Bytes[0] = ptr[4];
	this->field_298.Bytes[1] = ptr[5];
	this->field_298.Bytes[2] = ptr[6];
	this->field_298.Bytes[3] = ptr[7];

	this->field_344 = *dword_5FCCF4 + 0xFFFFFF10;

	int i = 0;
	while (i < 5)
	{
		word_682B64[i++] = Rnd(4096);
	}

	int v7 = 0;
	int *v8 = (int*)0x552210;

	do
	{
		if (*v8 != v7)
			print_if_false(0, "Fire Matt, he fucked up the rhino XA.  Actually, kick him in the nuts first.");

		v8 += 3;
		v7++;
	}
	while(v7 < 0x17);



	this->ParseScript(reinterpret_cast<unsigned __int16*>(v5));
	Panel_CreateHealthBar(this, 307);
}

// @NotOk
// globals
CRhino::CRhino(void)
{
	this->InitItem("rhino");
	this->mFlags |= 0x480;
	this->field_3C = 0x552080;
	this->field_38 = 307;
}

// @Ok
void Rhino_CreateRhino(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	if (v2)
	{
		*result = reinterpret_cast<unsigned int>(new CRhino(v2, v3));
	}
	else
	{
		*result = reinterpret_cast<unsigned int>(new CRhino());
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
	VALIDATE(CRhino, field_388, 0x388);
}

void validate_CRhinoNasalSteam(void)
{
	VALIDATE_SIZE(CRhinoNasalSteam, 0x68);
}
