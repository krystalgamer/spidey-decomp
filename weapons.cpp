#include "weapons.h"
#include "validate.h"
#include "mem.h"
#include "ps2funcs.h"
#include "camera.h"
#include "spool.h"

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

// @Ok
// @Test
CSmokeRing::CSmokeRing(i32 NumSectors, u32 a3)
{
	this->field_48.vx = 0;
	this->field_48.vy = 0;
	this->field_48.vz = 0;

	print_if_false(NumSectors != 0, "Zero sectors sent to smoke ring");
	this->mpSectors = static_cast<SSmokeRingRelated *>(DCMem_New(sizeof(SSmokeRingRelated) * NumSectors, 0, 1, 0, 1));
	this->mNumSectors = NumSectors;
	this->field_3C = Spool_FindTextureEntry(a3);
	print_if_false(this->field_3C != 0, "Could not find smoke ring texture");

	for (i32 i = 0; i < this->mNumSectors; i++)
	{
		setPolyGT4();

		this->mpSectors[i].field_3B |= 2;
		this->mpSectors[i].field_42 = this->field_3C->field_2;
		this->mpSectors[i].field_4E = this->field_3C->field_6;

		setPolyGT4();

		this->mpSectors[i].field_7 |= 2;
		this->mpSectors[i].field_E = this->field_3C->field_2;
		this->mpSectors[i].field_1A = this->field_3C->field_6;
	}

	this->SetRGB(128, 128, 128);
	this->SetUV(0, 0, 2);
	this->field_60 = -1;
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

// @Ok
// @Test
void CSmokeRing::SetRGB(i32 a2, i32 a3, i32 a4)
{
	if (a2 < 0)
		a2 = 0;

	if (a3 < 0)
		a3 = 0;

	if (a4 < 0)
		a4 = 0;

	for (i32 i = 0; i < this->mNumSectors; i++)
	{
			this->mpSectors[i].field_4 = 0;
			this->mpSectors[i].field_5 = 0;
			this->mpSectors[i].field_6 = 0;

			this->mpSectors[i].field_10 = 0;
			this->mpSectors[i].field_11 = 0;
			this->mpSectors[i].field_12 = 0;
			this->mpSectors[i].field_1C = a2;
			this->mpSectors[i].field_1D = a3;
			this->mpSectors[i].field_1E = a4;

			this->mpSectors[i].field_28 = a2;
			this->mpSectors[i].field_29 = a3;
			this->mpSectors[i].field_2A = a4;

			this->mpSectors[i].field_38 = a2;
			this->mpSectors[i].field_39 = a3;
			this->mpSectors[i].field_3A = a4;

			this->mpSectors[i].field_44 = a2;
			this->mpSectors[i].field_45 = a3;
			this->mpSectors[i].field_46 = a4;

			this->mpSectors[i].field_50 = 0;
			this->mpSectors[i].field_51 = 0;
			this->mpSectors[i].field_52 = 0;

			this->mpSectors[i].field_5C = 0;
			this->mpSectors[i].field_5D = 0;
			this->mpSectors[i].field_5E = 0;
	}
}

// @SMALLTODO
void CSmokeRing::SetUV(i32,i32,i32)
{
    printf("CSmokeRing::SetUV(i32,i32,i32)");
}

// @Ok
CSmokeRing::~CSmokeRing(void)
{
	Mem_Delete(this->mpSectors);
}

// @Ok
// @Matching
CTexturedRibbon::CTexturedRibbon(i32 NumPoints,i32 LeaveTrail)
{
	print_if_false(NumPoints > 1, "NumPoints must be at least 2");
	print_if_false((u32)NumPoints <= 0x20, "NumPoints too big for buffer.");
	this->mNumPoints = NumPoints;

	this->mpPoints = static_cast<SRibbonPoint *>(DCMem_New(sizeof(SRibbonPoint) * NumPoints, 0, 1, 0, 1));

	for (i32 i = 0; i < this->mNumPoints; i++)
	{
		this->mpPoints[i].WidthB = 0;
		this->mpPoints[i].Width = 0;
	}

	print_if_false(!LeaveTrail || LeaveTrail == 1, "LeaveTrail must be 0 or 1");
	this->mTrail = LeaveTrail;
	this->field_50 = 8;

	this->field_60 = static_cast<int *>(DCMem_New(8 * NumPoints + 4, 0, 1, 0, 1));
	this->field_60[0] = 0;
}

// @Ok
// matching
void CTexturedRibbon::SetCoreRGBi(
		i32 a2,
		u8 a3,
		u8 a4,
		u8 a5)
{
	this->field_60[a2 + 1 + this->mNumPoints] = (((a5 << 8) | a4) << 8) | a3;
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
	Mem_Delete(this->mpPoints);
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

	VALIDATE(CSmokeRing, field_3C, 0x3C);
	VALIDATE(CSmokeRing, mNumSectors, 0x40);
	VALIDATE(CSmokeRing, mpSectors, 0x44);

	VALIDATE(CSmokeRing, field_48, 0x48);

	VALIDATE(CSmokeRing, field_60, 0x60);
}

void validate_CTexturedRibbon(void)
{
	VALIDATE(CTexturedRibbon, mTrail, 0x3C);

	VALIDATE(CTexturedRibbon, field_50, 0x50);

	VALIDATE(CTexturedRibbon, mNumPoints, 0x58);
	VALIDATE(CTexturedRibbon, mpPoints, 0x5C);
	VALIDATE(CTexturedRibbon, field_60, 0x60);
}

void validate_SSmokeRingRelated(void)
{
	VALIDATE_SIZE(SSmokeRingRelated, 0x8C);

	VALIDATE(SSmokeRingRelated, field_4, 0x4);
	VALIDATE(SSmokeRingRelated, field_5, 0x5);
	VALIDATE(SSmokeRingRelated, field_6, 0x6);

	VALIDATE(SSmokeRingRelated, field_7, 0x7);
	VALIDATE(SSmokeRingRelated, field_E, 0xE);
	VALIDATE(SSmokeRingRelated, field_1A, 0x1A);

	VALIDATE(SSmokeRingRelated, field_1C, 0x1C);
	VALIDATE(SSmokeRingRelated, field_1D, 0x1D);
	VALIDATE(SSmokeRingRelated, field_1E, 0x1E);

	VALIDATE(SSmokeRingRelated, field_28, 0x28);
	VALIDATE(SSmokeRingRelated, field_29, 0x29);
	VALIDATE(SSmokeRingRelated, field_2A, 0x2A);

	VALIDATE(SSmokeRingRelated, field_38, 0x38);
	VALIDATE(SSmokeRingRelated, field_39, 0x39);
	VALIDATE(SSmokeRingRelated, field_3A, 0x3A);

	VALIDATE(SSmokeRingRelated, field_3B, 0x3B);

	VALIDATE(SSmokeRingRelated, field_42, 0x42);

	VALIDATE(SSmokeRingRelated, field_44, 0x44);
	VALIDATE(SSmokeRingRelated, field_45, 0x45);
	VALIDATE(SSmokeRingRelated, field_46, 0x46);

	VALIDATE(SSmokeRingRelated, field_4E, 0x4E);

	VALIDATE(SSmokeRingRelated, field_50, 0x50);
	VALIDATE(SSmokeRingRelated, field_51, 0x51);
	VALIDATE(SSmokeRingRelated, field_52, 0x52);

	VALIDATE(SSmokeRingRelated, field_5C, 0x5C);
	VALIDATE(SSmokeRingRelated, field_5D, 0x5D);
	VALIDATE(SSmokeRingRelated, field_5E, 0x5E);
}
