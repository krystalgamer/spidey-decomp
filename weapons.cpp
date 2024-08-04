#include "weapons.h"
#include "validate.h"
#include "mem.h"

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

// @SMALLTODO
void CTexturedRibbon::SetCoreRGBi(i32,u8,u8,u8)
{
    printf("CTexturedRibbon::SetCoreRGBi(i32,u8,u8,u8)");
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

// @SMALLTODO
CTexturedRibbon::~CTexturedRibbon(void)
{
    printf("CTexturedRibbon::~CTexturedRibbon(void)");
}

// @SMALLTODO
void CalcScreenNormal(SCalcBuffer *,i32 *,i32 *,i32)
{
    printf("CalcScreenNormal(SCalcBuffer *,i32 *,i32 *,i32)");
}

// @SMALLTODO
void Transform(CVector const *,long *)
{
    printf("Transform(CVector const *,long *)");
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
	VALIDATE(CTexturedRibbon, field_60, 0x60);
}
