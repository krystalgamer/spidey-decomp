#include "venom.h"
#include "validate.h"
#include "mem.h"
#include "utils.h"
#include "ps2lowsfx.h"
#include "trig.h"
#include "web.h"
#include "spool.h"


extern CBody* EnvironmentalObjectList;

#define LEN_VENOM_TEXS 10
EXPORT Texture* gVenomTexs[LEN_VENOM_TEXS];

// @BIGTODO
void Venom_DisplayProgressBar(const u32*, u32*)
{
	printf("void Venom_DisplayProgressBar(const u32*, u32*)");
}

// @Ok
// @Matching
void Venom_RelocatableModuleClear(void)
{
	CItem *pSearch = BaddyList;

	while (pSearch)
	{
		CItem *pNext = pSearch->mNextItem;

		if (pSearch->mType == 313)
			delete pSearch;

		pSearch = pNext;
	}

	for (i32 i = 0; i < LEN_VENOM_TEXS; i++)
	{
		gVenomTexs[i] = 0;
	}
}

// @Ok
// @Matching
void Venom_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Venom_RelocatableModuleClear;
	pMod->field_C[0] = Venom_CreateVenom;
	pMod->field_C[1] = Venom_DisplayProgressBar;
}

// @Ok
INLINE i32* CVenom::GetNewCommandBlock(u32 a1)
{
	i32* res = static_cast<i32*>(DCMem_New(4 * a1, 0, 1, 0, 1));
	res[a1 - 1] = 0;

	if (!this->field_35C)
	{
		this->field_35C = res;
	}
	else
	{
		i32* it = this->field_35C;
		while (1)
		{
			if (!it[it[1] - 1])
				break;

			it = reinterpret_cast<i32*>(it[it[1] - 1]);
		}

		it[it[1] - 1] = reinterpret_cast<i32>(res);
	}

	return res;
}

// @MEDIUMTODO
CVenom::CVenom(int*, int)
{
}

// @Ok
void Venom_CreateVenom(const unsigned int *stack, unsigned int *result) {
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CVenom(v2, v3));
}

// @Ok
void CVenom::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @BIGTODO
void CVenom::DoPhysics(void)
{}

// @Ok
void CVenomWrap::Die(void)
{
	CBit::Die();
}

// @Ok
// @Matching
INLINE i32* CVenom::KillCommandBlock(i32* a1)
{
	i32* res = reinterpret_cast<i32*>(a1[a1[1]-1]);

	if (this->field_35C == a1)
	{
		this->field_35C = res;
	}
	else
	{
		i32* it = this->field_35C;

		while (it)
		{
			if (a1 == reinterpret_cast<i32*>(it[it[1]-1]))
			{
				it[it[1]-1] = reinterpret_cast<i32>(res);
				break;
			}

			it = reinterpret_cast<i32*>(it[it[1]-1]);
		}
	}

	Mem_Delete(reinterpret_cast<void*>(a1));
	return res;
}

// @Ok
// @Matching
INLINE void CVenom::KillAllCommandBlocks(void)
{
	for (i32* cur = this->field_35C; cur; cur = this->KillCommandBlock(cur))
		;
	this->field_35C = 0;
}

// @Ok
unsigned char CVenom::TugImpulse(CVector *a2, CVector *a3, CVector *a4)
{
	if (a4)
		Mem_Delete(a4);
	this->field_218 |= 0x200;

	return 0;
}

// @Ok
CVenomElectrified::CVenomElectrified(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper sent to CVenomWrap");
	print_if_false((pSuper->mType == 313), "Non venom sent to CVenomElectrified");

	this->field_3C = Mem_MakeHandle(pSuper);
}

i32 gVenomFootstepRelated;

// @NotOk
// globals
void CVenom::PlayNextFootstepSFX(void)
{
	i32 i;
	for (i = Rnd(4) + 245; i == gVenomFootstepRelated; i = Rnd(4) + 245)
		;

	gVenomFootstepRelated = i;
	SFX_PlayPos(i | 0x8000, &this->mPos, 0);
}

// @Ok
void CVenom::GetTargetPosFromNode(CVector *pVector, i32 a3)
{
	Trig_GetPosition(pVector, a3);

	i32 v5 = Utils_GetGroundHeight(pVector, 0, 0x2000, 0);
	if (v5 != -1)
		pVector->vy = v5 - (this->field_21E << 12);
}

// @Ok
void INLINE CVenom::Lookaround(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->field_218 &= 0xFFFFFFF8;
			this->mVel.vx = 0;
			this->mVel.vy = 0;
			this->mVel.vz = 0;
			this->RunAnim(8, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->mAnimFinished)
			{
				this->field_31C.bothFlags = 32;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate");
			break;
	}
}

// @Ok
void INLINE CVenom::TugWeb(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->field_218 &= 0xFFFFFFF8;
			this->mVel.vz = 0;
			this->mVel.vy = 0;
			this->mVel.vx = 0;
			this->dumbAssPad++;
		case 1:
			if (this->field_218 & 0x200)
			{
				this->field_218 &= 0xFFFFFDFF;
				if (this->field_10C.field_0)
				{
					CTrapWebEffect* pWeb = reinterpret_cast<CTrapWebEffect*>(
							Mem_RecoverPointer(&this->field_10C));

					if (pWeb)
						pWeb->Burst();

					this->field_10C.field_0 = 0;
				}

				this->field_31C.bothFlags = 32;
				this->dumbAssPad = 0;
			}
			break;
		default:
			break;
	}
}

// @Ok
void CVenom::AdjustWaterModel(void)
{
	//SHandle *pHandle = &this->field_340;
	CBody* pBody = reinterpret_cast<CBody*>(
			Mem_RecoverPointer(&this->field_340));

	if (!pBody)
	{
		u32 Model = Spool_GetModel(0x26D2DBB7, gObjFileRegion);

		for (pBody = EnvironmentalObjectList;
				pBody;
				pBody = reinterpret_cast<CBody*>(pBody->mNextItem))
		{
			if (pBody->mRegion == gObjFileRegion && pBody->mModel == Model)
			{
				this->field_340 = Mem_MakeHandle(pBody);
				this->field_348 = pBody->mPos.vy;
				break;
			}
		}
	}

	if (pBody)
	{
		pBody->mPos.vy = this->field_348 - 18 * this->field_338;
	}

}

// @MEDIUMTODO
void CVenom::PulseL6A4Node(bool)
{
}


// @Ok
void CVenom::VenomDie(void)
{
	switch (this->dumbAssPad)
	{

		case 0:
			this->field_330 = 16;
			this->field_218 &= 0xFFFFFFF8;
			this->mVel.vx = 0;
			this->mVel.vy = 0;
			this->mVel.vz = 0;

			this->mCBodyFlags &= 0xFFEF;
			this->mFlags &= 0xFFBE;
			this->field_218 &= 0xFFFFFE7F;
			this->dumbAssPad++;
			break;
		case 1:
			this->field_330 = 16;
			if (this->mAnimFinished)
			{
				this->RunAnim(0x29, 0, -1);
				this->dumbAssPad++;
			}

			break;
		case 2:
			if (this->mAnimFinished)
			{
				if (Trig_GetLevelId() == 1540)
				{
					this->PulseL6A4Node(false);
					this->dumbAssPad++;
				}
				else
				{
					this->Die(0);
				}
			}
			break;
	}
}

void validate_CVenom(void){
	VALIDATE_SIZE(CVenom, 0x468);

	VALIDATE(CVenom, field_330, 0x330);
	VALIDATE(CVenom, field_338, 0x338);

	VALIDATE(CVenom, field_33C, 0x33C);
	VALIDATE(CVenom, field_33D, 0x33D);

	VALIDATE(CVenom, field_340, 0x340);
	VALIDATE(CVenom, field_348, 0x348);

	VALIDATE(CVenom, field_358, 0x358);
	VALIDATE(CVenom, field_35C, 0x35C);

	VALIDATE(CVenom, field_37C, 0x37C);
	VALIDATE(CVenom, field_380, 0x380);
	VALIDATE(CVenom, field_384, 0x384);

	VALIDATE(CVenom, field_39C, 0x39C);

	VALIDATE(CVenom, field_3A0, 0x3A0);
	VALIDATE(CVenom, field_3A4, 0x3A4);
	VALIDATE(CVenom, field_3A8, 0x3A8);

	VALIDATE(CVenom, field_3E8, 0x3E8);
	VALIDATE(CVenom, field_3EC, 0x3EC);
	VALIDATE(CVenom, field_3F0, 0x3F0);
	VALIDATE(CVenom, field_400, 0x400);
	VALIDATE(CVenom, field_404, 0x404);
	VALIDATE(CVenom, field_408, 0x408);
	VALIDATE(CVenom, field_40C, 0x40C);
	VALIDATE(CVenom, field_410, 0x410);
	VALIDATE(CVenom, field_414, 0x414);
	VALIDATE(CVenom, field_418, 0x418);
	VALIDATE(CVenom, field_41C, 0x41C);
	VALIDATE(CVenom, field_420, 0x420);

	VALIDATE(CVenom, field_430, 0x430);
	VALIDATE(CVenom, field_434, 0x434);


	VALIDATE(CVenom, field_454, 0x454);
	VALIDATE(CVenom, field_458, 0x458);
	VALIDATE(CVenom, field_45C, 0x45C);
	VALIDATE(CVenom, field_460, 0x460);
	VALIDATE(CVenom, field_464, 0x464);
}

void validate_CVenomWrap(void)
{
	VALIDATE_SIZE(CVenomWrap, 0x5C);
}

void validate_CVenomElectrified(void)
{
	VALIDATE_SIZE(CVenomElectrified, 0x48);

	VALIDATE(CVenomElectrified, field_3C, 0x3C);
}
