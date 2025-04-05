#include "effects.h"
#include "spool.h"
#include "utils.h"
#include "my_assert.h"

#include "validate.h"

extern i32 CurrentSuit;
extern SSinCos rcossin_tbl[];

EXPORT i32 gTextureRelated;

// @SMALLTODO
CElectroLine::CElectroLine(u16, u16, u16, u8, u8 ,u8, i32, i32, i32, i32, i32, u32*)
{
	printf("CElectroLine::CElectroLine(u16, u16, u16, u8, u8 ,u8, i32, i32, i32, i32, i32, u32*)");
}

// @Ok
CElectroLine::~CElectroLine(void)
{
}

// @SMALLTODO
CElectro::CElectro(void)
{
}

// @NotOk
// @FIXME guess type
CElectro::~CElectro(void)
{
	if (this->field_54)
		Mem_Delete(this->field_54);

	if (this->field_50)
		Mem_Delete(this->field_50);
}

// @Ok
void CBouncingRock::Move(void)
{
	this->mPos.vx += this->mVel.vx;
	this->mPos.vy += this->mVel.vy;
	this->mPos.vz += this->mVel.vz;

	if (this->mPos.vy > this->field_68)
	{
		this->mPos.vy = this->field_68;

		this->mVel.vx <<= 7;
		this->mVel.vx >>= 8;

		this->mVel.vy <<= 7;
		this->mVel.vy >>= 8;

		this->mVel.vz <<= 7;
		this->mVel.vz >>= 8;

		this->mVel.vy = -this->mVel.vy;

		this->field_6C++;
	}

	this->mVel.vy += 29584;
	this->mAngle += this->field_5A;

	if (this->field_6C >= 5)
		this->Die();

	if (this->mLifetime > 0x3C)
		this->Die();

}

// @Ok
CBouncingRock::~CBouncingRock(void)
{
}

// @NotOk
// globals
CBouncingRock::CBouncingRock(
		CVector* a2,
		i32 a3,
		u32 a4)
{
	this->mPos = *a2;
	this->field_68 = a3;
	if ( a4 != 0x28001F00 )
	{
		if ( a4 == 0x3288E271 )
		{
			this->SetTexture(*reinterpret_cast<Texture **>(gTextureRelated + 20));
			this->mSemiTransparencyRate = 0;
		}
	}
	else
	{
		this->SetTexture(*reinterpret_cast<Texture **>(gTextureRelated + 44));
	}

	this->mScale = Rnd(200) + 350;
	i32 v6 = Rnd(4096);
	i32 v7 = Rnd(10) + 10;
	i32 v8 = v6 & 0xFFF;
	this->mVel.vx = v7 * rcossin_tbl[v8].sin;
	this->mVel.vz = v7 * rcossin_tbl[v8].cos;

	this->mVel.vy = -81920 - (Rnd(20) << 12);
	this->field_5A = 500;
	if ( Rnd(2) )
		this->field_5A *= -1;
	this->mPostScale = 0xC001000;
}

// @Ok
void CChunkSmoke::Move(void)
{
	this->mAngle += this->field_5A;
	this->field_5A -= this->field_5A >> 3;
	this->mScale += (this->field_7C - this->mScale) >> 1;

	if (++this->mAge > this->field_74)
	{
		this->mPos.vy -= this->mVel.vy;

		Bit_ReduceRGB(&this->mCodeBGR, this->field_78);
		if (!(0xFFFFFF & this->mCodeBGR))
			this->Die();
	}
	else
	{
		this->mPos += (this->field_68 - this->mPos) >> 2;
	}
}

// @Ok
CChunkSmoke::~CChunkSmoke(void)
{
}

// @Ok
// @Test
CChunkSmoke::CChunkSmoke(
		CVector* a2,
		CVector* a3,
		i32 a4)
{
	this->field_68.vx = 0;
	this->field_68.vy = 0;
	this->field_68.vz = 0;

	this->SetSemiTransparent();
	this->mCodeBGR = 0x2E202020;
	this->mScale = 0;

	this->field_7C = Rnd(1000) + 1000;
	this->mAngle = Rnd(4096);
	this->field_5A = 150;

	if ( a4 < 0 )
		this->field_5A = -150;

	this->mPos = *a2;
	this->field_68 = *a3;
	this->field_78 = Rnd(0) + 4;
	this->field_74 = Rnd(40);

	this->SetAnim(0xEu);

	this->mFrame = 0;
	DoAssert(this->mNumFrames != 0, "Woops");

	this->mpPSXFrame = &this->mpPSXAnim[this->mFrame];
	this->mVel.vy = Rnd(5) << 12;
}

// @Ok
void CFootprint::Move(void)
{
	if (this->field_84)
	{
		this->field_84--;
		return;
	}

	u8 low = this->mTint;
	u8 mid = this->mTint >> 8;
	u8 high = this->mTint >> 16;

	if (low < 1)
		low = 0;
	else
		low--;

	if (mid < 1)
		mid = 0;
	else
		mid--;

	if (high < 1)
		high = 0;
	else
		high--;


	this->mTint = (((high << 8) | mid) << 8) | low;
	if (!this->mTint)
		this->Die();
}

// @Ok
CFootprint::~CFootprint(void)
{
}

// @NotOk
// @Test
// diff assembly
CFootprint::CFootprint(CVector* pVector, i32 a3)
{
	this->SetTexture(Spool_FindTextureChecksum("RhinoStomp"));
	this->SetSubtractiveTransparency();
	this->SetTint(0x12u, 0x12u, 0x12u);
	this->field_84 = 2000;

	this->mPos.vy = pVector->vy;
	this->mPosB.vy = pVector->vy;
	this->mPosC.vy = pVector->vy;
	this->mPosD.vy = pVector->vy;

	i32 vxVel = rcossin_tbl[a3 & 0xFFF].sin;
	i32 vzVel = rcossin_tbl[a3 & 0xFFF].cos;

	this->mPos.vx = vxVel - vzVel;
	i32 v12 = vxVel + vzVel;
	i32 v13 = vzVel - vxVel;

	this->mPos.vz = v12;
	this->mPosB.vx = v12;
	this->mPosB.vz = v13;
	this->mPosC.vx = -v12;
	this->mPosC.vz = this->mPos.vx;
	this->mPosD.vx = v13;
	this->mPosD.vz = -v12;
	this->mPos.vx *= 70;
	this->mPos.vz *= 70;
	this->mPosB.vx *= 70;
	this->mPosB.vz *= 70;
	this->mPosC.vx *= 70;
	this->mPosC.vz *= 70;
	this->mPosD.vx *= 70;
	this->mPosD.vz *= 70;
	this->mPos.vx += pVector->vx;
	this->mPos.vz += pVector->vz;
	this->mPosB.vx += pVector->vx;
	this->mPosB.vz += pVector->vz;
	this->mPosC.vx += pVector->vx;
	this->mPosC.vz += pVector->vz;
	this->mPosD.vx += pVector->vx;
	this->mPosD.vz += pVector->vz;

	this->mType = 25;
}

// @Ok
void CRhinoWallImpact::Move(void)
{
	if (++this->mAge >= 200)
	{
		Bit_ReduceRGB(&this->mTint, 1);
		if (!(0xFFFFFF & this->mTint))
			this->Die();
	}
}

// @Ok
CRhinoWallImpact::~CRhinoWallImpact(void)
{
}

// @Ok
CRhinoWallImpact::CRhinoWallImpact(SLineInfo* pLineInfo)
{
	print_if_false(pLineInfo != 0, "NULL pLineInfo");

	this->SetTexture(Spool_FindTextureChecksum("RhinoWallImpact"));
	this->SetTint(0x12u, 0x12u, 0x12u);
	this->SetSubtractiveTransparency();

	this->mCodeBGR &= ~0x200;

	CVector v2;
	v2 = pLineInfo->Position;
	v2.vy -= 204800;

	this->OrientUsing(&v2, reinterpret_cast<SVECTOR*>(&pLineInfo->Normal), 100, 100);
	this->mType = 26;
}

// @MEDIUMTODO
CSkinGoo::CSkinGoo(CSuper*, SSkinGooSource*, i32, SSkinGooParams*)
{
	printf("CSkinGoo::CSkinGoo(CSuper*, SSkinGooSource*, i32, SSkinGooParams*)");
}

// @MEDIUMTODO
CSkinGoo::CSkinGoo(CSuper*, SSkinGooSource2*, i32, SSkinGooParams*)
{
	printf("CSkinGoo::CSkinGoo(CSuper*, SSkinGooSource2*, i32, SSkinGooParams*)");
}

// @MEDIUMTODO
CElectrify::CElectrify(CSuper*, i32)
{
	printf("CElectrify::CElectrify(CSuper*, int)");
}

// @Ok
void INLINE Effects_UnElectrify(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper?");

	CItem *v2 = reinterpret_cast<CItem*>(Mem_RecoverPointer(&pSuper->field_114));
	if (v2)
		delete v2;
}

// @NotOk
// globals
void Effects_Electrify(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper?");
	Effects_UnElectrify(pSuper);

	if (pSuper->mType == 50)
	{
		if (CurrentSuit != 4)
		{
			new CElectrify(pSuper, 10);
		}
	}
	else
	{
		new CElectrify(pSuper, 20);
	}
}

void validate_CElectrify(void)
{
	VALIDATE_SIZE(CElectrify, 0x64);
}

void validate_CSkinGoo(void)
{
	VALIDATE_SIZE(CSkinGoo, 0xD8);
}

void validate_SSkinGooSource(void)
{
	VALIDATE_SIZE(SSkinGooSource, 0xC);

	VALIDATE(SSkinGooSource, field_0, 0x0);
	VALIDATE(SSkinGooSource, field_4, 0x4);
	VALIDATE(SSkinGooSource, field_8, 0x8);
}

void validate_SSkinGooSource2(void)
{
}

void validate_SSkinGooParams(void)
{
}

void validate_CRhinoWallImpact(void)
{
	VALIDATE_SIZE(CRhinoWallImpact, 0x88);
}

void validate_CFootprint(void)
{
	VALIDATE_SIZE(CFootprint, 0x88);

	VALIDATE(CFootprint, field_84, 0x84);
}

void validate_CChunkSmoke(void)
{
	VALIDATE_SIZE(CChunkSmoke, 0x80);

	VALIDATE(CChunkSmoke, field_68, 0x68);
	VALIDATE(CChunkSmoke, field_74, 0x74);
	VALIDATE(CChunkSmoke, field_78, 0x78);
	VALIDATE(CChunkSmoke, field_7C, 0x7C);
}

void validate_CBouncingRock(void)
{
	VALIDATE_SIZE(CBouncingRock, 0x70);

	VALIDATE(CBouncingRock, field_68, 0x68);
	VALIDATE(CBouncingRock, field_6C, 0x6C);
}

void validate_CElectro(void)
{
	VALIDATE_SIZE(CElectro, 0x58);

	VALIDATE(CElectro, field_50, 0x50);
	VALIDATE(CElectro, field_54, 0x54);
}

void validate_CElectroLine(void)
{
	VALIDATE_SIZE(CElectroLine, 0x6C);
}
