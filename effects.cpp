#include "effects.h"
#include "spool.h"
#include "vector.h"
#include "validate.h"

extern i32 CurrentSuit;
extern SFlatBitVelocity FlatBitVelocities[];

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

	i32 vxVel = FlatBitVelocities[a3 & 0xFFF].vxVel;
	i32 vzVel = FlatBitVelocities[a3 & 0xFFF].vzVel;

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
	if (++this->field_C >= 200)
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
	v2.vx = pLineInfo->field_6C;
	v2.vy = pLineInfo->field_70 - 204800;
	v2.vz = pLineInfo->field_74;
	this->OrientUsing(&v2, reinterpret_cast<SVECTOR*>(&pLineInfo->field_78), 100, 100);
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
void __inline Effects_UnElectrify(CSuper* pSuper)
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

	if (pSuper->field_38 == 50)
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
