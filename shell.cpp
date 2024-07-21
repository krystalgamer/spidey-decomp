#include "shell.h"
#include "validate.h"
#include "ps2m3d.h"
#include "utils.h"
#include "ps2lowsfx.h"
#include "effects.h"

EXPORT CBody *MiscList;

EXPORT SSkinGooSource gVenomSkinGooSource;
EXPORT SSkinGooParams gVenomSkinGooParams;

EXPORT SSkinGooSource gCarnageSkinGooSource;
EXPORT SSkinGooParams gCarnageSkinGooParams;

EXPORT SSkinGooSource gSuperDocOckSkinGooSource;
EXPORT SSkinGooParams gSuperDocOckSkinGooParams;

EXPORT i32 gShellMysterioRelated;

extern CVector gGlobalNormal;

// @MEDIUMTODO
void CShellMysterioHeadCircle::Move(void)
{
}

// @Ok
CShellMysterioHeadCircle::~CShellMysterioHeadCircle(void)
{
	--gShellMysterioRelated;
}

// @Ok
CShellMysterioHeadCircle::CShellMysterioHeadCircle(CDummy *pDummy)
{
	this->field_84 = Mem_MakeHandle(reinterpret_cast<void*>(pDummy));

	this->SetTexture(0xB968C0FD);
	this->SetSemiTransparent();

	this->field_90 = Rnd(100) + 100 * gShellMysterioRelated + 50;

	if (gShellMysterioRelated & 1)
		this->field_90 *= -1;

	++gShellMysterioRelated;
}

// @MEDIUMTODO
void CShellGoldFish::AI(void)
{
}

// @Ok
CShellGoldFish::~CShellGoldFish(void)
{
	this->DeleteFrom(&MiscList);
}

// @Ok
CShellGoldFish::CShellGoldFish(CDummy *pDummy)
{
	this->field_F8 = Mem_MakeHandle(reinterpret_cast<void*>(pDummy));

	this->InitItem("goldfish");
	this->field_38 = 506;
	this->AttachTo(&MiscList);

	this->mFlags |= 0x200;
	this->csVector1.vy = 50;
	this->field_2C = 10000;
	this->field_2A = 10000;
	this->field_28 = 10000;
}

// @MEDIUMTODO
CShellSimbyFireDeath::CShellSimbyFireDeath(CDummy*)
{
	printf("CShellSimbyFireDeath::CShellSimbyFireDeath(CDummy*)");
}

// @Ok
// @Test
void CShellSimbyMeltSplat::Move(void)
{
	switch (this->field_84)
	{
		case 0:
			this->field_88 += 10;
			if (this->field_88 >= this->field_8C)
				this->field_84 = 1;

			break;
		case 1:
			Bit_ReduceRGB(&this->mTint, 10);
			if (!(0xFFFFFF & this->mTint))
					this->Die();
			break;
	}

	CVector a3 = (this->field_88 * this->field_9C);
	CVector v11 = (this->field_88 * this->field_A8);

	this->mPos = (this->field_90 - a3) - v11;

	this->mPosB = (this->field_90 + a3) - v11;

	this->mPosC = (this->field_90 - a3) + v11;

	this->mPosD = (this->field_90 + a3) + v11;
}

// @Ok
CShellSimbyMeltSplat::CShellSimbyMeltSplat(CVector* pVec)
{
	this->field_90.vx = 0;
	this->field_90.vy = 0;
	this->field_90.vz = 0;

	this->field_9C.vx = 0;
	this->field_9C.vy = 0;
	this->field_9C.vz = 0;

	this->field_A8.vx = 0;
	this->field_A8.vy = 0;
	this->field_A8.vz = 0;

	this->SetTexture(0x3AF6DFF);
	this->SetSemiTransparent();
	this->SetTint(0xFF, 0, 0);

	this->field_8C = Rnd(50) + 70;
	this->field_90 = *pVec;

	SVECTOR v11;
	v11.vx = 0;
	v11.vy = -4096;
	v11.vz = 0;

	this->OrientUsing(&this->field_90, &v11, 1, 1, Rnd(4096));

	this->field_9C = (this->mPosB - this->mPos) >> 1;
	this->field_A8 = (this->mPosC - this->mPos) >> 1;

	this->Move();
	this->mType = 21;
}

// @MEDIUMTODO
void CShellEmber::Move(void)
{
	printf("CShellEmber::Move");
}

// @Ok
// @Test
CShellEmber::CShellEmber(
		CVector* pVec,
		i32 a3)
{
	this->field_68 = 0;
	this->field_6C = 0;
	this->field_70 = 0;

	this->mPos = *pVec;
	this->field_68 = this->mPos.vx;
	this->field_70 = this->mPos.vz;

	this->field_78 = Rnd(10) + 10;
	this->field_7C = Rnd(4096);
	this->field_80 = Rnd(4096);

	this->SetTexture(0x13C0A001);
	this->mScale = Rnd(200) + 350;

	this->field_84 = 255;
	this->field_88 = 128;
	this->field_8C = 0;

	this->SetTint(0xFF, 128, 0);
	this->SetSemiTransparent();

	this->field_74 = (a3 * (Rnd(5) + 5)) > 8;
	this->mVel.vy = (a3 * (Rnd(5) + 6)) << 12 >> 8;
}

// @Ok
CShellMysterioHeadGlow::CShellMysterioHeadGlow(void)
	: CWobblyGlow(&gGlobalNormal, 150, 120, 90, 255, 255, 255, 0x80u, 0, 0xFFu)
{
}

// @Ok
CWobblyGlow::CWobblyGlow(
		CVector* Pos,
		i32 InnerRadius,
		i32 FringeRadius,
		i32 Amp,
		u8 r0,
		u8 g0,
		u8 b0,
		u8 r1,
		u8 g1,
		u8 b1)
	: CGlow(Pos, InnerRadius, FringeRadius, r0, g0, b0, r1, g1, b1)
{
	this->mAmplitude = Amp * InnerRadius / 256;

	this->mInnerRadius = InnerRadius;

	for (i32 i = 0; i < this->field_44; i++)
	{
		this->mInc[i] = Rnd(4096);
		this->mT[i] = Rnd(50) + 200;
	}
}

// @Ok
// @Test
void CShellRhinoNasalSteam::Move(void)
{
	if (this->mAnimSpeed)
	{
		i16 v3 = (this->field_52 << 8) | this->field_53;
		v3 += this->mAnimSpeed;

		this->field_53 = v3;
		v3 >>= 8;

		this->field_52 = v3;

		if (this->field_52 >= this->field_51)
		{
			this->mAnimSpeed = 0;
			this->field_52 = this->field_51 - 1;
		}

		this->field_4C = &this->mPSXAnim[this->field_52];
	}

	this->mPos += this->mVel;

	this->mVel.vy -= 1024;
	if (++this->field_C > 30)
	{
		this->Die();
	}
	else
	{
		this->SetTransparency(64 - 2 * (0xFF & this->field_C));
		this->SetScale(Rnd(4) + 4 *(this->field_C + 32));
	}
}

// @Ok
CShellRhinoNasalSteam::CShellRhinoNasalSteam(
		CVector* a2,
		CVector* a3)
{
	this->mPos = *a2;
	this->mVel = *a3;

	this->SetAnim(1);
	this->SetSemiTransparent();
	this->SetTransparency(0x40);
	this->SetAnimSpeed(128);
	this->SetScale(128);
	this->field_58 = Rnd(4096);
}

// @Ok
// skin goo params are not okay
void CShellSuperDocOckElectrified::Move(void)
{
	CSuper *pSuper = static_cast<CSuper*>(Mem_RecoverPointer(&this->field_3C));

	if (!pSuper)
	{
		this->Die();
		return;
	}

	M3d_BuildTransform(pSuper);

	if (++this->field_44 > 0)
	{
		new CSkinGoo(pSuper, &gSuperDocOckSkinGooSource, 19, &gSuperDocOckSkinGooParams);
		this->field_44 = 0;
	}

}

// @Ok
CShellSuperDocOckElectrified::CShellSuperDocOckElectrified(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pointer");
	print_if_false(pSuper->field_38 == 309, "Non SuperDocOck");

	this->field_3C = Mem_MakeHandle(reinterpret_cast<void*>(pSuper));
}

// @Ok
// skin goo params are not okay
void CShellCarnageElectrified::Move(void)
{
	CSuper *pSuper = static_cast<CSuper*>(Mem_RecoverPointer(&this->field_3C));

	if (!pSuper)
	{
		this->Die();
		return;
	}

	M3d_BuildTransform(pSuper);

	if (++this->field_44 > 0)
	{
		new CSkinGoo(pSuper, &gCarnageSkinGooSource, 19, &gCarnageSkinGooParams);
		this->field_44 = 0;
	}

}

// @Ok
CShellCarnageElectrified::CShellCarnageElectrified(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper sent to CShellCarnageElectrified");
	print_if_false(pSuper->field_38 == 314, "Non carnage sent to CShellCarnageElectrified");

	this->field_3C = Mem_MakeHandle(reinterpret_cast<void*>(pSuper));
}


// @NotOk
// skin goo params are not okay
void CShellVenomElectrified::Move(void)
{
	CSuper *pSuper = static_cast<CSuper*>(Mem_RecoverPointer(&this->field_3C));

	if (!pSuper)
	{
		this->Die();
		return;
	}

	M3d_BuildTransform(pSuper);

	if (++this->field_44 > 0)
	{
		new CSkinGoo(pSuper, &gVenomSkinGooSource, 19, &gVenomSkinGooParams);
		this->field_44 = 0;
	}

}

// @Ok
CShellVenomElectrified::CShellVenomElectrified(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper sent to CVenomWrap");
	print_if_false(pSuper->field_38 == 313, "Non venom sent to CShellVenomElectrified");

	this->field_3C = Mem_MakeHandle(reinterpret_cast<void*>(pSuper));
}

// @Ok
void CDummy::SelectNewAnim(void)
{
	if (this->field_1B8)
	{
		this->field_1B8++;
		if (*this->field_1B8 == 0xFFFF)
		{
			this->SelectNewTrack(0);
		}
		else
		{
			this->RunAnim(*this->field_1B8, 0, -1);
		}
	}
	else
	{
		this->RunAnim(this->field_1C0, 0, -1);
	}
}

// @Ok
void CDummy::SelectNewTrack(int a2)
{
	this->field_1B8 = 0;
	this->field_1BC = 0;

	if (this->field_1A4 || this->field_1A8 || this->field_1AC)
	{
		do
		{
			switch(Rnd(3))
			{
				case 0:
					this->field_1B8 = this->field_1A4;
					break;
				case 1:
					this->field_1B8 = this->field_1A8;
					break;
				case 2:
					this->field_1B8 = this->field_1AC;
					break;
			}
		}
		while(!this->field_1B8);

		print_if_false(*this->field_1B8 != 0xFFFF, "First anim must not be 0xFFFF");

		if (a2)
		{
			u16 *v7 = this->field_1B8;
			i32 i = 0;
			for (i = 0; *v7 != 0xFFFF; i++)
				v7++;

			i32 v9 = 0;
			i32 v10;
			do
			{
				v10 = Rnd(i);
				v9++;
			}
			while (this->field_1B8[v10] == this->field_12A && v9 < 100);

			if (this->field_1B8[v10] != this->field_12A)
				this->field_1B8 = &this->field_1B8[v10];
		}

		this->field_1BC = this->field_1B8;
		this->RunAnim(*this->field_1BC, 0, -1);
	}
	else
	{
		this->RunAnim(this->field_1C0, 0, -1);
	}
}

// @Ok
void __inline CDummy::FadeAway(void)
{
	this->field_1F8 = 1;
	this->field_1FC = 0;

	this->mFlags &= 0xFF7F;
	this->mFlags |= 0x800;

	this->field_24 = 0x202020;

	this->OutlineOn();
	this->SetOutlineSemiTransparent();
	this->SetOutlineRGB(0, 0, 0);
}

// @Ok
void __inline CDummy::FadeBack(void)
{
	this->field_1FC = 1;
	this->field_1F8 = 0;
}

static const __int16 *word_610C48 = (__int16*)0x610C48;

// @NotOk
// Global
void __inline CWobblyGlow::Move(void)
{
	for (unsigned int i = 0; i < this->field_44; i++)
	{
		this->mInc[8+i] += this->mInc[i];
		int v3 = this->mInc[8+i];
		this->field_3C[2*i] = this->mInnerRadius + this->mAmplitude * word_610C48[2 * (v3 & 0xFFF)] / 4096;
	}
}

// @Ok
void CShellMysterioHeadGlow::Move(void)
{
	CWobblyGlow::Move();
	this->field_54 += this->field_A4;
}

// @Ok
void Spidey_CIcon::AI(void)
{
	this->mAngles.vy += 50;
	if (this->mFlags & 2)
	{
		this->UpdateFrame();
		M3d_BuildTransform(this);
	}
}

// @NotOk
// globals
CRudeWordHitterSpidey::CRudeWordHitterSpidey(void)
{
	this->InitItem("spidey");
	this->mFlags |= 0x480;

	this->field_3C = 0x552710; // <- global

	this->field_194 |= 0x420;

	this->RunAnim(0, 0, -1);

	this->field_128 = 18;
	this->mPos.vx = 0xFFF92000;
	this->mPos.vy = 0x104000;
	this->mPos.vz = 0x1F4000;
	this->mAngles.vy = 0xFD76;
}

// @Ok
void CRudeWordHitterSpidey::AI(void)
{
	this->field_1A8++;
	if (this->field_1A8 > 60)
	{
		this->mPos.vy += 0x14000;
	}
	else
	{
		this->mPos.vy -= 0x14000;
		if (this->mPos.vy < 0x91000)
		{
			this->mPos.vy = 0x91000;
		}
	}

	if (this->field_142)
	{
		if (!this->field_12A)
		{
			this->RunAnim(0x64, 0, -1);
		}
		else
		{
			this->RunAnim(0, 0, -1);
		}
	}

	this->UpdateFrame();

	if (this->field_128 == 7 && !this->field_1A4)
	{
		switch (Rnd(4))
		{
			case 0:
				SFX_Play(0xE, 0x2000, 0);
				break;
			case 1:
				SFX_Play(0xF, 0x2000, 0);
				break;
			case 2:
				SFX_Play(0x10, 0x2000, 0);
				break;
			case 3:
				SFX_Play(0x11, 0x2000, 0);
				break;
			default:
				break;
		}

		this->field_1A4 = 1;
	}

	M3d_BuildTransform(this);
}


// @Ok
CShellSymBurn::CShellSymBurn(CVector* pVector)
{
	this->mPos = *pVector;
	this->InitItem("fire");
	this->mFlags |= 0x602;
	this->field_2A = 0;
	this->field_24 = 0xFFFFFF;
	this->AttachTo(&MiscList);
}

SVECTOR gYAnglesRelated;

// @NotOk
// slightly different assembly, not important
void CShellSymBurn::AI(void)
{
	this->mAngles.vy = gYAnglesRelated.vy + 2048;
	this->field_28 = 3000;
	this->field_2C = 3000;

	if (++this->field_1A4 > 60)
	{
		i32 v3 = (this->field_24 & 0xFF) - 4;
		if (v3 < 0)
			v3 = 0;

		this->field_2A -= 75;
		this->field_24 = v3 | ((v3 | (v3 << 8)) << 8);

		if (this->field_2A < 0)
			this->field_2A = 0;

		if (!v3 || !this->field_2A)
		{
			this->Die();
		}
	}
	else
	{
		i32 v5 = (this->field_24 & 0xFF) - 129;
		if (v5 < 128)
			v5 = 128;

		this->field_2A += 800;
		this->field_24 = v5 | ((v5 | (v5 << 8)) << 8);

		if (this->field_2A > 4096)
			this->field_2A = 4096;
	}

	M3d_BuildTransform(this);
}

char *gBadWords[30] =
{
	"sjnkpc",
	"cmpxkpc",
	"bstf",
	"\x62\x74\x74\x00",
	"gvdl",
	"cvhhfs",
	"xbol",
	"\x75\x6A\x75\x00"
	"dvou",
	"tobudi",
	"qvttz",
	"tiju",
	"qjtt",
	"\x64\x76\x6E\x00",
	"\x77\x62\x68\x00",
	"gfmudi",
	"tqvol",
	"\x6B\x6A\x7B\x00",
	"dpdl",
	"gjtujoh",
	"ovutbd",
	"bobm",
	"ejmep",
	"cbtubse",
	"dpdl",
	"cvuu",
	"qfojt",
	"uxbu",
	"cjudi",
};

char *gGoodWords[30] = 
{
	"flower",
	"happy",
	"pretty",
	"puppy",
	"bunny",
	"donut",
	"lolly",
	"love",
	"nice",
	"cake",
	"poppy",
	"fluffy",
	"cloud",
	"rainbow",
	"icecream",
	"sugar",
	"windmill",
	"iowa",
	"toffee",
	"taffy",
	"candy",
	"sodapop",
	"bubble",
	"cinnamon",
	"dinosaur",
	"balloon",
	"lobster",
	"honey",
	"potato",
	"spice",
};

// @Ok
i32 Shell_DeRudify(char inp[INPUT_MAX_SIZE])
{
	char buffer[9];

	for (i32 i = 0; ; i++)
	{
		if (i >= 29)
			return 0;

		Utils_CopyString(gBadWords[i], buffer, 9);
		for (char *j = buffer; *j; j++)
			--*j;

		if (Shell_ContainsSubString(inp, buffer))
			break;
	}

	i32 result = Utils_CopyString(gGoodWords[Rnd(30)], inp, 9);
	for (i32 k = result; k < 8; k++)
		inp[k] = '.';

	return result;

}

// @NotOk
// good candidate for tests
INLINE i32 Shell_ContainsSubString(const char* hay, const char* needle)
{
	for (const char *hayPtr = hay; *hayPtr; hayPtr++)
	{
		const char *needlePtr = needle;
		for (; *needlePtr; needlePtr++)
		{
			char needleChar = *needlePtr;
			char hayChar = hay[needlePtr-needle];

			if (needleChar >= 'A' && needleChar <= 'Z')
				needleChar += ' ';

			if (hayChar >= 'A' && hayChar <= 'Z')
				hayChar += ' ';

			if (hayChar != needleChar)
				break;
		}

		if (!*needlePtr)
			return 1;
	}

	return 0;
}

void validate_CRudeWordHitterSpidey(void){
	VALIDATE_SIZE(CRudeWordHitterSpidey, 0x1AC);

	
	VALIDATE(CRudeWordHitterSpidey, field_194, 0x194);
	VALIDATE(CRudeWordHitterSpidey, field_1A4, 0x1A4);
	VALIDATE(CRudeWordHitterSpidey, field_1A8, 0x1A8);
}

void validate_CDummy(void){
	VALIDATE_SIZE(CDummy, 0xA18);

	VALIDATE(CDummy, field_1A4, 0x1A4);
	VALIDATE(CDummy, field_1A8, 0x1A8);
	VALIDATE(CDummy, field_1AC, 0x1AC);
	VALIDATE(CDummy, field_1B8, 0x1B8);
	VALIDATE(CDummy, field_1BC, 0x1BC);
	VALIDATE(CDummy, field_1C0, 0x1C0);

	VALIDATE(CDummy, field_1F8, 0x1F8);
	VALIDATE(CDummy, field_1FC, 0x1FC);

	VALIDATE(CDummy, field_240, 0x240);
	VALIDATE(CDummy, field_288, 0x288);

	VALIDATE(CDummy, field_2D4, 0x2D4);
	VALIDATE(CDummy, field_304, 0x304);
	VALIDATE(CDummy, field_418, 0x418);
}

void validate_CShellMysterioHeadGlow(void)
{
	VALIDATE_SIZE(CShellMysterioHeadGlow, 0xA8);

	VALIDATE(CShellMysterioHeadGlow, field_A4, 0xA4);
}


void validate_CWobblyGlow(void)
{
	VALIDATE_SIZE(CWobblyGlow, 0xA4);

	VALIDATE(CWobblyGlow, mInc, 0x5C);
	VALIDATE(CWobblyGlow, mT, 0x7C);

	VALIDATE(CWobblyGlow, mAmplitude, 0x9C);
	VALIDATE(CWobblyGlow, mInnerRadius, 0xA0);
}

void validate_Spidey_CIcon(void)
{
	VALIDATE_SIZE(Spidey_CIcon, 0x1A4);
}

void validate_CShellSymBurn(void)
{
	VALIDATE_SIZE(CShellSymBurn, 0x1A8);

	VALIDATE(CShellSymBurn, field_1A4, 0x1A4);
}

void validate_CShellVenomElectrified(void)
{
	VALIDATE_SIZE(CShellVenomElectrified, 0x48);

	VALIDATE(CShellVenomElectrified, field_3C, 0x3C);
	VALIDATE(CShellVenomElectrified, field_44, 0x44);
}

void validate_CShellCarnageElectrified(void)
{
	VALIDATE_SIZE(CShellVenomElectrified, 0x48);

	VALIDATE(CShellVenomElectrified, field_3C, 0x3C);
	VALIDATE(CShellVenomElectrified, field_44, 0x44);
}

void validate_CShellSuperDocOckElectrified(void)
{
	VALIDATE_SIZE(CShellVenomElectrified, 0x48);

	VALIDATE(CShellVenomElectrified, field_3C, 0x3C);
	VALIDATE(CShellVenomElectrified, field_44, 0x44);
}

void validate_CShellRhinoNasalSteam(void)
{
	VALIDATE_SIZE(CShellRhinoNasalSteam, 0x68);
}

void validate_CShellEmber(void)
{
	VALIDATE_SIZE(CShellEmber, 0x90);

	VALIDATE(CShellEmber, field_68, 0x68);
	VALIDATE(CShellEmber, field_6C, 0x6C);
	VALIDATE(CShellEmber, field_70, 0x70);
	VALIDATE(CShellEmber, field_74, 0x74);
	VALIDATE(CShellEmber, field_78, 0x78);
	VALIDATE(CShellEmber, field_7C, 0x7C);
	VALIDATE(CShellEmber, field_80, 0x80);
	VALIDATE(CShellEmber, field_84, 0x84);
	VALIDATE(CShellEmber, field_88, 0x88);
	VALIDATE(CShellEmber, field_8C, 0x8C);
}

void validate_CShellSimbyMeltSplat(void)
{
	VALIDATE_SIZE(CShellSimbyMeltSplat, 0xB4);

	VALIDATE(CShellSimbyMeltSplat, field_84, 0x84);
	VALIDATE(CShellSimbyMeltSplat, field_88, 0x88);
	VALIDATE(CShellSimbyMeltSplat, field_8C, 0x8C);

	VALIDATE(CShellSimbyMeltSplat, field_90, 0x90);
	VALIDATE(CShellSimbyMeltSplat, field_9C, 0x9C);
	VALIDATE(CShellSimbyMeltSplat, field_A8, 0xA8);
}

void validate_CShellSimbyFireDeath(void)
{
	VALIDATE_SIZE(CShellSimbyFireDeath, 0x54);
}

void validate_CShellGoldFish(void)
{
	VALIDATE_SIZE(CShellGoldFish, 0x118);

	VALIDATE(CShellGoldFish, field_F8, 0xF8);
	VALIDATE(CShellGoldFish, field_100, 0x100);
	VALIDATE(CShellGoldFish, field_104, 0x104);
	VALIDATE(CShellGoldFish, field_108, 0x108);
	VALIDATE(CShellGoldFish, field_10C, 0x10C);
	VALIDATE(CShellGoldFish, field_110, 0x110);
	VALIDATE(CShellGoldFish, field_114, 0x114);
}

void validate_CShellMysterioHeadCircle(void)
{
	VALIDATE_SIZE(CShellMysterioHeadCircle, 0x94);

	VALIDATE(CShellMysterioHeadCircle, field_84, 0x84);
	VALIDATE(CShellMysterioHeadCircle, field_90, 0x90);
}
