#include "carnage.h"
#include "validate.h"
#include "trig.h"
#include "panel.h"
#include "spool.h"
#include "effects.h"
#include "camera.h"
#include "ps2funcs.h"
#include "utils.h"
#include "my_assert.h"
#include "ps2redbook.h"

extern const char *gObjFile;
extern CBaddy *BaddyList;
EXPORT u8 gObjFileRegion;

#define NUM_CARNAGE_GOOS 19

// @Ok
// @Matching
EXPORT SSkinGooSource gCarnageSkinGooSource[NUM_CARNAGE_GOOS] =
{
	{ 0x0F0E0A, 0x45F3EC38, 0x45F3EC38 },
	{ 0x1E1D0A, 0x45F3EC38, 0x45F3EC38 },
	{ 0x0A000D, 0x0D291D41B, 0x6CF38ACE },
	{ 0x0B050B, 0x0D291D41B, 0x6CF38ACE },
	{ 0x19160C, 0x0D291D41B, 0x6CF38ACE },
	{ 0x1C190C, 0x0D291D41B, 0x6CF38ACE },
	{ 0x131C0C, 0x0D291D41B, 0x6CF38ACE },
	{ 0x41108, 0x0D291D41B, 0x6CF38ACE },
	{ 0x42208, 0x0D291D41B, 0x6CF38ACE },
	{ 0x1C1D10, 0x0D291D41B, 0x6CF38ACE },
	{ 0x161910, 0x0D291D41B, 0x6CF38ACE },
	{ 0x0B0D0F, 0x0D291D41B, 0x6CF38ACE },
	{ 0x0F1311, 0x0D291D41B, 0x6CF38ACE },
	{ 0x151405, 0x0D291D41B, 0x6CF38ACE },
	{ 0x81405, 0x0D291D41B, 0x6CF38ACE },
	{ 0x40704, 0x0D291D41B, 0x6CF38ACE },
	{ 0x121302, 0x0D291D41B, 0x6CF38ACE },
	{ 0x51202, 0x0D291D41B, 0x6CF38ACE },
	{ 0x40701, 0x0D291D41B, 0x6CF38ACE },
};

// @Ok
INLINE void CCarnage::PlayXA(
		i32 a2,
		i32 a3,
		i32 a4)
{
	if (Rnd(100) <= a4)
		Redbook_XAPlayPos(a2, a3, &this->mPos, 0);
}

// @Ok
// @Matching
void CCarnage::CreateCombatImpactEffect(CVector* pVec, i32)
{
	for (i32 i = 0; i < 16; i++)
	{
		new CCarnageHitSpark(pVec);
	}
}

// @Ok
INLINE void CCarnage::DieCarnage(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->mAccellorVel.vz = 0;
			this->mAccellorVel.vy = 0;
			this->mAccellorVel.vx = 0;
			this->field_218 &= 0xFFFFFFF8;

			this->RunAnim(36, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
			{
				this->PulseL8A5Node();
				this->dumbAssPad++;
			}
			break;
	}
}


// @Ok
INLINE void CCarnage::PulseL8A5Node(void)
{
	CVector v3 = { 0, 0, 0 };
	v3.vx = 0;
	v3.vy = 0;
	v3.vz = 0;

	for (i32 i = 1 ; i < NumNodes; i++)
	{
		if (*gTrigNodes[i] == 1)
		{
			Trig_GetPosition(&v3, i);
			if (!(v3.vz | v3.vx | v3.vy))
			{
				Trig_SendPulseToNode(i);
				return;
			}
		}
	}

	DoAssert(0, "Node not found");
}

// @Ok
// @Matching
void Carnage_RelocatableModuleClear(void)
{
	CItem *pSearch = BaddyList;

	while (pSearch)
	{
		CItem *pNext = pSearch->field_20;

		if (pSearch->field_38 == 314)
			delete pSearch;

		pSearch = pNext;
	}
}

// @Ok
// @Matching
void SetTheCarnageGooSourcesChecksums(void)
{
	for (i32 i = 0; i < NUM_CARNAGE_GOOS; i++)
	{
		if (gCarnageSkinGooSource[i].field_4 == 0x45F3EC38)
		{
			gCarnageSkinGooSource[i].field_4 = Spool_FindTextureChecksum("carnage_bit04_32");
		}
		else if (gCarnageSkinGooSource[i].field_4 == 0xD291D41B)
		{
			gCarnageSkinGooSource[i].field_4 = Spool_FindTextureChecksum("carnage_bit03_32");
		}
		else if (gCarnageSkinGooSource[i].field_4 == 0x6CF38ACE)
		{
			gCarnageSkinGooSource[i].field_4 = Spool_FindTextureChecksum("carnage_bit01_32");
		}

		if (gCarnageSkinGooSource[i].field_8 == 0x45F3EC38)
		{
			gCarnageSkinGooSource[i].field_8 = Spool_FindTextureChecksum("carnage_bit04_32");
		}
		else if (gCarnageSkinGooSource[i].field_8 == 0xD291D41B)
		{
			gCarnageSkinGooSource[i].field_8 = Spool_FindTextureChecksum("carnage_bit03_32");
		}
		else if (gCarnageSkinGooSource[i].field_8 == 0x6CF38ACE)
		{
			gCarnageSkinGooSource[i].field_8 = Spool_FindTextureChecksum("carnage_bit01_32");
		}
	}
}

// @Ok
// @Matching
void Carnage_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Carnage_RelocatableModuleClear;
	pMod->field_C[0] = Carnage_CreateCarnage;

	SetTheCarnageGooSourcesChecksums();
}

// @NotOk
// @Test
CCarnageHitSpark::CCarnageHitSpark(CVector* pVec)
{
	this->mPosC = *pVec;

	CVector v41;
	v41.vx = 0;
	v41.vy = -4096;
	v41.vz = 0;

	CVector v40 = { 0, 0, 0 };

	v40.vx = gMikeCamera[0].Position.vx - (this->mPosC.vx >> 12);
	v40.vy = gMikeCamera[0].Position.vy - (this->mPosC.vy >> 12);
	v40.vz = gMikeCamera[0].Position.vz - (this->mPosC.vz >> 12);

	gte_ldopv1(reinterpret_cast<VECTOR*>(&v41));
	gte_ldopv2(reinterpret_cast<VECTOR*>(&v40));
	gte_op0();

	gte_stlvnl(reinterpret_cast<VECTOR*>(&v40));

	CVector v39;
	v39.vx = v40.vx >> 8;
	v39.vy = v40.vy >> 8;
	v39.vz = v40.vz >> 8;

	gte_ldlvl(reinterpret_cast<VECTOR*>(&v39));
	gte_sqr0();
	gte_stlvnl(reinterpret_cast<VECTOR*>(&v39));

	i32 v8 = M3dMaths_SquareRoot0(v39.vx + v39.vy + v39.vz);
	v40.vx = 16 * (v40.vx / v8);
	v40.vy = 16 * (v40.vy / v8);
	v40.vz = 16 * (v40.vz / v8);


	i32 v9 = Rnd(4096);
	i32 v10 = Rnd(30);
	i32 v11 = (4 * v9) & 0x3FFC;

	i32 v12 = ((v10 + 5) * rcossin_tbl[v11].cos) >> 12;
	i32 v22 = ((v10 + 5) * rcossin_tbl[v11].sin) >> 12;

	this->mVel = (v12 * v41) + (v22 * v40);

	i32 v13 = Rnd(50) + 50;
	i32 v14 = (v13 * rcossin_tbl[v11].cos) >> 12;
	i32 v20 = (v13 * rcossin_tbl[v11].sin) >> 12;

	CVector v33 = (v14 * v41) + (v20 * v40);

	i32 v15 = (4 * (v9 + 1024)) & 0x3FFC;

	i32 v18 = (10 * rcossin_tbl[v15].sin) >> 12;
	i32 v19 = (10 * rcossin_tbl[v15].cos) >> 12;

	CVector v30 = (v19 * v41) + (v18 * v40);

	this->mPos = this->mPosC + v33;

	if (Rnd(2))
	{
		this->mPosD = this->mPosC + v30;
	}
	else
	{
		this->mPosD = this->mPosC - v30;
	}

	this->mPosB = this->mPosD + v33;


	this->SetTexture(0x877E63C8);
	this->SetSemiTransparent();
	this->SetTint(0xFF, 0x80u, 0);
	this->mType = 30;
}

// @Ok
// @Matching
void CCarnageHitSpark::Move(void)
{
	this->mPos.vx += this->mVel.vx;
	this->mPos.vy += this->mVel.vy;
	this->mPos.vz += this->mVel.vz;

	this->mPosB.vx += this->mVel.vx;
	this->mPosB.vy += this->mVel.vy;
	this->mPosB.vz += this->mVel.vz;

	this->mPosC.vx += this->mVel.vx;
	this->mPosC.vy += this->mVel.vy;
	this->mPosC.vz += this->mVel.vz;

	this->mPosD.vx += this->mVel.vx;
	this->mPosD.vy += this->mVel.vy;
	this->mPosD.vz += this->mVel.vz;

	if (++this->field_C > 0)
		Bit_ReduceRGB(&this->mTint, 30);

	if ((this->mTint & 0xFFFFFF) == 0)
		this->Die();
}

// @Ok
CCarnageHitSpark::~CCarnageHitSpark(void)
{
}

// @Ok
CCarnage::~CCarnage(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
	Panel_DestroyHealthBar();

	if (this->field_32C)
		delete reinterpret_cast<CItem*>(this->field_32C);

	if (this->field_344)
		Mem_Delete(this->field_344);
}

// @NotOk
// globals
CCarnage::CCarnage(int* a2, int a3)
{
	this->field_334 = 0;
	this->field_338 = 0;
	this->field_33C = 0;
	this->field_370 = 0;
	this->field_374 = 0;
	this->field_378 = 0;


	this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));
	this->InitItem("carnage");
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->mFlags |= 0x480;
	this->field_3C = 0x548980;
	this->field_194 = 278528;

	this->field_38 = 314;
	this->field_31C.bothFlags = 1;

	this->field_E2 = 3000;
	this->field_DC = 160;
	this->field_21E = 100;
	this->field_35C = 1;
	this->field_354 = 241;

	unsigned __int16 *LinksPointer = reinterpret_cast<unsigned __int16*>(Trig_GetLinksPointer(a3));
	print_if_false(*LinksPointer == 1, "Error");
	this->field_358 = LinksPointer[1];
	Panel_CreateHealthBar(this, 314);
	CreateSonicBubbleVertexWobbler();
}

// @MEDIUMTODO
void CreateSonicBubbleVertexWobbler(void)
{}

// @Ok
void Carnage_CreateCarnage(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CCarnage(v2, v3));
}


// @NotOk
// globals
CSonicBubble::CSonicBubble(void)
{
	this->InitItem(gObjFile);

	this->mModel = Spool_GetModel(0xE9DD4877, gObjFileRegion);
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->mCBodyFlags &= 0xFFFFFFEF;
	this->field_DC = 0;
}

// @Ok
void CSonicBubble::SetScale(int scale)
{
	this->field_28 = 0;
	this->field_2A = 0;
	this->field_2C = 0;
	this->mFlags |= 0x200;
}


extern CBaddy* BaddyList;

// @NotOk
// globals
CSonicBubble::~CSonicBubble(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
}

// @Ok
void CCarnage::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @Ok
INLINE CCarnageElectrified::CCarnageElectrified(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper sent to CVenomWrap");
	print_if_false(pSuper->field_38 == 314, "Non carnage sent to CCarnageElectrified");

	this->field_3C = Mem_MakeHandle(pSuper);
}

// @Ok
// @Matching
CCarnageElectrified::~CCarnageElectrified(void)
{
}

// @BIGTODO
void CCarnage::DoPhysics(void)
{}

void validate_CCarnage(void){
	VALIDATE_SIZE(CCarnage, 0x37C);

	VALIDATE(CCarnage, field_32C, 0x32C);

	VALIDATE(CCarnage, field_334, 0x334);
	VALIDATE(CCarnage, field_338, 0x338);

	VALIDATE(CCarnage, field_33C, 0x33C);

	VALIDATE(CCarnage, field_344, 0x344);

	VALIDATE(CCarnage, field_354, 0x354);
	VALIDATE(CCarnage, field_358, 0x358);
	VALIDATE(CCarnage, field_35C, 0x35C);
	VALIDATE(CCarnage, field_36C, 0x36C);
	VALIDATE(CCarnage, field_370, 0x370);
	VALIDATE(CCarnage, field_374, 0x374);
	VALIDATE(CCarnage, field_378, 0x378);

	VALIDATE_VTABLE(CCarnage, CreateCombatImpactEffect, 6);
}

void validate_CSonicBubble(void)
{
	VALIDATE_SIZE(CSonicBubble, 0xF8);

	VALIDATE(CSonicBubble, field_F4, 0xF4);
}

void validate_CCarnageElectrified(void)
{
	VALIDATE_SIZE(CCarnageElectrified, 0x48);

	VALIDATE(CCarnageElectrified, field_3C, 0x3C);
	VALIDATE(CCarnageElectrified, field_44, 0x44);
}

void validate_CCarnageHitSpark(void)
{
	VALIDATE_SIZE(CCarnageHitSpark, 0x84);
}
