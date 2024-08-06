#include "weapons.h"
#include "validate.h"
#include "mem.h"
#include "ps2funcs.h"
#include "camera.h"

extern SCamera gMikeCamera[2];

// @MEDIUMTODO
void CGouraudRibbon::Display(void)
{
    printf("CGouraudRibbon::Display(void)");
}

// @SMALLTODO
void CGouraudRibbon::SetRGB(u8,u8,u8)
{
    printf("CGouraudRibbon::SetRGB(u8,u8,u8)");
}

// @SMALLTODO
void CGouraudRibbon::SetWidth(u16)
{
    printf("CGouraudRibbon::SetWidth(u16)");
}

// @SMALLTODO
CGouraudRibbon::~CGouraudRibbon(void)
{
    printf("CGouraudRibbon::~CGouraudRibbon(void)");
}

// @SMALLTODO
CSmokeRing::CSmokeRing(i32,u32)
{
    printf("CSmokeRing::CSmokeRing(i32,u32)");
}

// @MEDIUMTODO
void CSmokeRing::Display(void)
{
    printf("CSmokeRing::Display(void)");
}

// @SMALLTODO
void CSmokeRing::SetParams(CVector const *,i32,i32)
{
    printf("CSmokeRing::SetParams(CVector const *,i32,i32)");
}

// @SMALLTODO
void CSmokeRing::SetRGB(i32,i32,i32)
{
    printf("CSmokeRing::SetRGB(i32,i32,i32)");
}

// @SMALLTODO
void CSmokeRing::SetUV(i32,i32,i32)
{
    printf("CSmokeRing::SetUV(i32,i32,i32)");
}

// @SMALLTODO
CSmokeRing::~CSmokeRing(void)
{
    printf("CSmokeRing::~CSmokeRing(void)");
}

// @SMALLTODO
CTexturedRibbon::CTexturedRibbon(i32,i32)
{
    printf("CTexturedRibbon::CTexturedRibbon(i32,i32)");
}

// @Ok
// matching
void CTexturedRibbon::SetCoreRGBi(
		i32 a2,
		u8 a3,
		u8 a4,
		u8 a5)
{
	this->field_60[a2 + 1 + this->field_58] = (((a5 << 8) | a4) << 8) | a3;
}

// @Ok
void CTexturedRibbon::SetOuterRGBi(i32 index, u8 a3, u8 a4,u8 a5)
{
	this->field_60[index+1] = (a3 | (((a5 << 8) | a4) << 8));
}

// @SMALLTODO
void CTexturedRibbon::SetTexture(Texture *)
{
    printf("CTexturedRibbon::SetTexture(Texture *)");
}

// @Ok
CTexturedRibbon::~CTexturedRibbon(void)
{
	Mem_Delete(this->field_5C);
	Mem_Delete(this->field_60);
}

// @SMALLTODO
void CalcScreenNormal(SCalcBuffer *,i32 *,i32 *,i32)
{
    printf("CalcScreenNormal(SCalcBuffer *,i32 *,i32 *,i32)");
}

// @NotOk
// review when used
INLINE i32 Transform(CVector *a1, i32* a2)
{
	CVector v8;
	v8.vx = 0;
	v8.vy = 0;
	v8.vz = 0;


	v8.vx = (a1->vx >> 12) - gMikeCamera[0].Position.vx;
	v8.vy = (a1->vy >> 12) - gMikeCamera[0].Position.vy;
	v8.vz = (a1->vz >> 12) - gMikeCamera[0].Position.vz;

	gte_ldlv0(reinterpret_cast<VECTOR*>(&v8));

	gte_rtps();
	gte_stsxy(a2);

	i32 v7;
	gte_stlvnl2(&v7);

	return v7;
}

// @Ok
CGouraudRibbon::CGouraudRibbon(i32 NumPoints, i32 LeaveTrail)
{
	print_if_false(NumPoints > 1, "NumPoints must be at least 2");
	print_if_false((u32)NumPoints <= 0x20, "NumPoints too big for buffer.");

	this->NumPoints = NumPoints;

	this->mpPoints = static_cast<SRibbonPoint *>(
			DCMem_New(
				sizeof(SRibbonPoint) * NumPoints,
				0,
				1,
				0,
				1));

	print_if_false(LeaveTrail == 0 || LeaveTrail == 1, "LeaveTrail must be 0 or 1");

	this->mTrail = LeaveTrail;
}

void validate_CGouraudRibbon(void)
{
	VALIDATE_SIZE(CGouraudRibbon, 0x48);

	VALIDATE(CGouraudRibbon, mTrail, 0x3C);
	VALIDATE(CGouraudRibbon, NumPoints, 0x40);
	VALIDATE(CGouraudRibbon, mpPoints, 0x44);
}

void validate_CSmokeRing(void)
{
	VALIDATE_SIZE(CSmokeRing, 0x6C);
}

void validate_CTexturedRibbon(void)
{
	VALIDATE(CTexturedRibbon, field_58, 0x58);
	VALIDATE(CTexturedRibbon, field_5C, 0x5C);
	VALIDATE(CTexturedRibbon, field_60, 0x60);
}
