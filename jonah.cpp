#include "jonah.h"
#include "validate.h"
#include "panel.h"
#include "utils.h"
#include "ai.h"
#include "my_assert.h"

// @Ok
EXPORT i32 JoelJewtCheatCode;

extern CBody* EnvironmentalObjectList;
extern CBaddy* BaddyList;

// @Ok
EXPORT i32 gJonahSetup[2] = { 33686018, 258 };


// @Ok
EXPORT SLight M3d_JonahLight =
{
  { { -2430, -2228, -2430 }, { 2509, -2896, 1447 }, { -648, -3711, -1607 } },
  0,
  { { 3200, 1040, 2048 }, { 2720, 1600, 1920 }, { 2400, 2560, 2048 } },
  0,
  { 1200, 1200, 960 }
};

// @Ok
// @Matching
INLINE u32 CJonah::WhatShouldScorpDo(void)
{
	i32 v = this->field_31C.bothFlags;
	if (v != 5)
	{
		return v != 8;
	}

	return 2;
}

// @Ok
// @Matching
void Jonah_WhatShouldScorpDo(const u32* stack, u32 *res)
{
	CJonah *pJonah = reinterpret_cast<CJonah*>(stack[0]);
	*res = pJonah->WhatShouldScorpDo();
}

// @Ok
// @Matching
INLINE void CJonah::ShouldPlead(void)
{
	this->field_218 |= 0xCu;
}

// @Ok
// @Matching
void Jonah_ShouldPlead(const u32 *stack, u32*)
{
	CJonah *pJonah = reinterpret_cast<CJonah*>(stack[0]);
	pJonah->ShouldPlead();
}

// @Ok
// @Matching
void Jonah_RelocatableModuleClear(void)
{
	CItem *pSearch = BaddyList;

	while (pSearch)
	{
		CItem *pNext = pSearch->mNextItem;

		if (pSearch->mType == 316)
			delete pSearch;

		pSearch = pNext;
	}
}

// @Ok
// @Matching
void Jonah_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Jonah_RelocatableModuleClear;
	pMod->field_C[0] = Jonah_CreateJonah;
	pMod->field_C[1] = Jonah_WhatShouldScorpDo;
	pMod->field_C[2] = Jonah_ShouldPlead;
}

// @Ok
CJonah::CJonah(void)
{
	if (JoelJewtCheatCode)
	{
		this->InitItem("jjjj");
	}
	else
	{
		this->InitItem("jameson");
	}

	this->mFlags |= 0x480;
	this->mpLight = &M3d_JonahLight;
	this->mType = 316;

}

// @Ok
// @AlmostMatching: array assingment after vtable
CJonah::CJonah(i16* a2, i32 a3)
{
	i16 *v5 = this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));


	if (JoelJewtCheatCode)
	{
		this->InitItem("jjjj");
	}
	else
	{
		this->InitItem("jameson");
	}

	this->mFlags |= 0x480;

	this->mpLight = &M3d_JonahLight;
	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));

	this->field_1F4 = a3;
	this->mNode = a3;
	this->mType = 316;
	this->field_21E = 100;
	this->mRMinor = 100;

	this->field_230 = 0;
	this->field_216 = 32;
	this->mPushVal = 64;
	this->field_31C.bothFlags = 0;

	this->field_2A8 |= 0x2002001;
	this->mHealth = 120;

	this->field_294.Int = gJonahSetup[0];
	this->field_298.Int = gJonahSetup[1];

	this->mCBodyFlags &= 0xFFEF;
	this->ParseScript(reinterpret_cast<u16*>(v5));
	Panel_CreateHealthBar(this, 316);
}

// @Ok
void Jonah_CreateJonah(const u32 *stack, u32 *result)
{
	i16* v2 = reinterpret_cast<i16*>(*stack);
	i32 v3 = static_cast<i32>(stack[1]);

	if (v2)
	{
		*result = reinterpret_cast<u32>(new CJonah(v2, v3));
	}
	else
	{
		*result = reinterpret_cast<u32>(new CJonah());
	}
}

// @Ok
// @Matching
INLINE void CJonah::GraspWaypoint(SLinkInfo* a2)
{
	this->field_2F8 = a2->field_8;
	this->field_1F4 = a2->field_0;
}

// @Ok
int CJonah::LinkedHidingPlaceStillExists(i32 a2)
{

	SLinkInfo infos[4];

	i32 v3 = this->field_1F4;
	this->field_364.field_0 = 0;

	if (a2)
	{
		i32 LinksPointer = reinterpret_cast<i32>(Trig_GetLinkInfoList(this->field_1F4, infos, 4));

		if (!LinksPointer)
			return 0;

		for (i32 i = 0; i < LinksPointer; i++)
		{
			if (infos[i].field_8 == 2)
			{
				v3 = infos[i].field_0;
				i = LinksPointer + 1;
			}
		}
	}

	i32 v6 = reinterpret_cast<i32>(Trig_GetLinkInfoList(v3, infos, 4));
	if (!v6 || v6 <= 0)
		return 0;

	for (i32 i = 0; i<v6 ; i++)
	{
		if (infos[i].field_4 == 1 || infos[i].field_4 == 2)
		{
			CBody *BodyByNode = this->FindBodyByNode(infos[i].field_0, EnvironmentalObjectList);

			if (BodyByNode)
			{
				print_if_false(BodyByNode->mType == 401, "Hiding place is not a MANIPOB!");
				this->field_364 = Mem_MakeHandle(BodyByNode);
				return 1;
			}
		}

	}

	return 0;
}

// @Ok
int __inline CJonah::StartRunningToNextRoom(void)
{
	if (this->field_370)
	{
		if ((this->field_218 & 0x200) || (this->field_330 >= 80 && !this->LinkedHidingPlaceStillExists(0)))
		{
			SLinkInfo linkInfo;
			linkInfo.field_8 = 4;
			linkInfo.field_0 = this->field_36C;
			this->GraspWaypoint(&linkInfo);

			this->field_31C.bothFlags = 7;
			this->dumbAssPad = 0;
			this->field_218 |= 0x102;

			return 1;
		}
	}

	return 0;
}

// @NotOk
// missing part findscorp
void CJonah::TakeHit(void)
{

	CBaddy* v3;
	switch (this->dumbAssPad)
	{
		case 0:
			v3 = this->FindScorp();
			if (v3)
			{
			}
			this->dumbAssPad++;
			break;
		case 1:
			if (this->mAnimFinished)
			{
				this->field_318 = 0;
				if (!this->StartRunningToNextRoom())
				{
					this->field_31C.bothFlags = 1;
					this->dumbAssPad = 0;
				}
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
	}
}

// @Ok
CBaddy* CJonah::FindScorp(void)
{
	if (!Mem_RecoverPointer(&this->field_35C))
	{
		for (CBaddy* cur = BaddyList; cur; cur = reinterpret_cast<CBaddy*>(cur->mNextItem))
		{
			if (cur->mType == 310)
			{
				this->field_35C = Mem_MakeHandle(cur);
				return cur;
			}
		}

		return 0;
	}

	CBaddy *ret = reinterpret_cast<CBaddy*>(this->field_35C.field_0);
	print_if_false(ret->mType == 310, "What the fuck? Scorp ptr isn't scorp.");
	return ret;
}

// @Ok
unsigned __int16 CJonah::DistToScorp(void)
{
	CBaddy* pScorp = this->FindScorp();
	if (!pScorp)
		return 0xFFFF;

	return Utils_CrapDist(pScorp->mPos, this->mPos);
}

void validate_CJonah(void){
	VALIDATE_SIZE(CJonah, 0x380);

	VALIDATE(CJonah, dumbAssPad, 0x320);
	VALIDATE(CJonah, field_330, 0x330);

	VALIDATE(CJonah, field_35C, 0x35C);
	VALIDATE(CJonah, field_364, 0x364);

	VALIDATE(CJonah, field_36C, 0x36C);
	VALIDATE(CJonah, field_370, 0x370);
}
