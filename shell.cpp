#include "shell.h"
#include "ps2m3d.h"
#include "utils.h"
#include "ps2lowsfx.h"
#include "effects.h"
#include "spool.h"
#include "panel.h"
#include "front.h"
#include "PCGfx.h"
#include "mess.h"
#include "ps2pad.h"
#include "dcshellutils.h"
#include "utils.h"
#include "PCShell.h"
#include "powerup.h"
#include "pshell.h"
#include "spidey.h"
#include "ps2m3d.h"
#include "init.h"

#include <cstring>

#include "validate.h"

EXPORT SLight M3d_RudeSpideyLight =
{
  { { -2047, -2896, -2047 }, { 0, 0, 4096 }, { 0, 0, -4096 } },
  0,
  { { 1440, 1920, 1760 }, { 1440, 1920, 1760 }, { 1440, 1920, 1760 } },
  0,
  { 1600, 1600, 1600 }
};

EXPORT SLight M3d_SpideyCIconLight =
{
  { { -2047, -2896, -2047 }, { 0, 0, 4096 }, { 0, 0, -4096 } },

  0,
  { { 2048, 2048, 2048 }, { 2048, 2048, 2048 }, { 2048, 2048, 2048 } },
  0,

  { 2048, 2048, 2048 }
};



// @FIXME
EXPORT SRecords gGlobalRecords;

EXPORT i32 dword_6A7788[16];
EXPORT void* gBiographies;
EXPORT i32 gPshellArmorRealted;

// @FIXME
EXPORT SRecordRelated gChallenges[NUM_CHALLS];

EXPORT u16 OTPushback[3];
EXPORT u8 gPShellCleanup = 1;
EXPORT i32 gShellFromGame;
EXPORT i32 gShellInitialized;


EXPORT u8 gCurrentCostume;

CBody *MiscList;

// @FIXME
EXPORT SSkinGooSource gVenomSkinGooSource;
EXPORT SSkinGooParams gVenomSkinGooParams;

// @FIXME
EXPORT SSkinGooSource gCarnageSkinGooSourceShell;
EXPORT SSkinGooParams gCarnageSkinGooParams;

// @FIXME
EXPORT SSkinGooSource gSuperDocOckSkinGooSource;
EXPORT SSkinGooParams gSuperDocOckSkinGooParams;

EXPORT i32 gShellMysterioRelated;
extern SPSXRegion PSXRegion[];

SAnimFrame* gBackgroundAnimFrame;

const i32 NUM_SAVE_GAME_SLOTS = 8;
EXPORT SSaveGame gSaveGameSlots[NUM_SAVE_GAME_SLOTS];

// @Ok
// @Matching
void Shell_RelocatableModuleClear(void)
{
}

// @Ok
// @Matching
void Shell_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Shell_RelocatableModuleClear;
	pMod->field_C[0] = Shell_DoShell;
	pMod->field_C[1] = Shell_SaveGame;
}

// @Ok
void Shell_AddGameSlots(CMenu* pMenu)
{
	print_if_false(pMenu->mNumLines == 0, "Tried to add slots to non-empty menu");

	for (i32 i = 0; i < NUM_SAVE_GAME_SLOTS; i++)
	{
		i32 v6 = 0;

		if (gSaveGameSlots[i].mChecksum)
		{
			u32 checksum = Shell_CalculateGameChecksum(&gSaveGameSlots[i]);

			if (checksum == gSaveGameSlots[i].mChecksum)
			{
				pMenu->AddEntry(gSaveGameSlots[i].field_3F);
			}
			else
			{
				pMenu->AddEntry("read error");
				v6 = 1;
			}
		}
		else
		{
				pMenu->AddEntry("---- empty ----");
				v6 = 1;
		}

		if (v6)
		{
			pMenu->mEntry[i].unk_c = 80;
			pMenu->mEntry[i].unk_d = 16;
			pMenu->mEntry[i].unk_e = 36;
			pMenu->mEntry[i].field_11 = 40;
			pMenu->mEntry[i].field_12 = 8;

			pMenu->mEntry[i].field_13 = 0x12;
			pMenu->mEntry[i].field_14 = 0x50;

			pMenu->mEntry[i].field_15 = 0x10;
			pMenu->mEntry[i].field_16 = 0x24;

			pMenu->mEntry[i].field_17 = 0x28;
			pMenu->mEntry[i].field_18 = 8;

			pMenu->mEntry[i].field_19 = 0x12;
		}
	}
}

// @Ok
// PowerPC version implies that mSize of SSaveGame is not a field but part of the array
// i don't like it
INLINE u32 Shell_CalculateGameChecksum(SSaveGame* pSave)
{
	u32 checksum = 0;
	print_if_false(1u, "Size of SSaveGame not a multiple of 4");

	u32* fields = &reinterpret_cast<u32*>(pSave)[1];

	for (i32 i = 0; i<0x2E; i++)
	{
		if (checksum & 0x80000000)
		{
			checksum = checksum * 2 + 1;
		}
		else
		{
			checksum <<= 1;
		}

		checksum += fields[i];
	}

	return checksum | 1;
}

// @MEDIUMTODO
void Shell_CharacterViewer(void)
{
	printf("void Shell_CharacterViewer");
}

// @Ok
// @Note: at the end it does add esp 2 times instead of one time but it's the same
void Shell_Cheats(void)
{
	const char *pDesc = 0;
	char v3[12];

	v3[0] = 0;

	while (Shell_InputName(v3, 1, 1, pDesc))
	{
		i32 res = PShell_ActivateCheat(v3);
		if (res != -1)
		{
			SFX_Play(0x1D, 0x2000, 0);
			pDesc = gCheats[res].pDescription;
		}
		else
		{
			SFX_Play(0x1B, 0x2000, 0);
			pDesc = 0;
		}

		v3[0] = 0;
	}

	SFX_Play(0x23, 0x2000, 0);

	if (gCurrentCostume != 5)
	{
		Spidey_BagHead(4096, gCurrentCostume != 9 ? 0 : 2);
	}
	else
	{
		Spidey_BagHead(4096, 1);
	}
}

// @MEDIUMTODO
void Shell_ChooseEnemy(i32,u8,signed char)
{
    printf("Shell_ChooseEnemy(i32,u8,signed char)");
}

// @MEDIUMTODO
void Shell_ChooseItemCollection(i32)
{
    printf("Shell_ChooseItemCollection(i32)");
}

// @MEDIUMTODO
void Shell_ChooseSpeedTraining(i32)
{
    printf("Shell_ChooseSpeedTraining(i32)");
}

// @MEDIUMTODO
void Shell_ChooseSurvivalArena(i32)
{
    printf("Shell_ChooseSurvivalArena(i32)");
}

// @MEDIUMTODO
void Shell_ChooseTime(i32,i32)
{
    printf("Shell_ChooseTime(i32,i32)");
}

// @MEDIUMTODO
void Shell_ChooseTrainingControlType(void)
{
    printf("Shell_ChooseTrainingControlType(void)");
}

// @MEDIUMTODO
void Shell_ChooseTrainingMission(i32)
{
    printf("Shell_ChooseTrainingMission(i32)");
}

// @MEDIUMTODO
void Shell_ComicCollection(void)
{
    printf("Shell_ComicCollection(void)");
}

// @MEDIUMTODO
void Shell_CostumeViewer(void)
{
    printf("Shell_CostumeViewer(void)");
}

// @MEDIUMTODO
void Shell_Difficulty(i32)
{
    printf("Shell_Difficulty(i32)");
}

// @Ok
void Shell_DisplayGameInfo(
		i32 a1,
		i32 a2,
		SSaveGame* pSave)
{
	if (pSave->mChecksum)
	{
		u32 checksum = Shell_CalculateGameChecksum(pSave);

		if (pSave->mChecksum == checksum)
		{
			SLevel* pLevel = Front_FindLevel(pSave->field_4);
			if (pLevel)
			{
				Mess_SetTextJustify(1);
				Mess_DrawText(a1, a2, pLevel->mDisplayName, 0, 0x1000);

				const char* v9 = gRenderBuf;

				switch (pSave->mDifficulty)
				{
					case 0:
						v9 = "kid mode";
						break;
					case 1:
						v9 = "easy";
						break;
					case 2:
						v9 = "normal";
						break;
					case 3:
						v9 = "hard";
						break;
				}

				Mess_DrawText(a1, a2 + 15, "difficulty:", 0, 0x1000);
				Mess_DrawText(a1 + 150, a2 + 15, v9, 0, 0x1000);
			}
		}
	}
}

// @MEDIUMTODO
void Shell_DoShell(const u32 *,u32 *)
{
    printf("Shell_DoShell(u32 const *,u32 *)");
}

// @Ok
// @Matching
void Shell_DrawBackground(void)
{
	if (!gBackgroundAnimFrame)
		Spool_AnimAccess("menubg", &gBackgroundAnimFrame);

	PCPanel_DrawTexturedPoly(-1.0, gBackgroundAnimFrame->pTexture, 0, 0, 512, 240, 128);
}

// @Ok
// @Matching
void Shell_DrawTitleBar(
		i32 a1,
		i32 a2,
		const char * a3,
		i32 a4,
		i32 a5,
		i32 a6,
		i32 a7,
		i32 a8)
{
	Mess_SetTextJustify(0);
	Mess_SetRGB(0x80u, 0x80u, 0x80u, 0);
	Mess_SetRGBBottom(0x45u, 60, 107);
	if (a4)
		PShell_BigFont();
	Mess_SetSort(4094);
	Mess_DrawText(a1, a2, a3, 0, 0x1000u);

	i32 v8;
	if ( a5 < a1 )
		v8 = a6 + a1 + Mess_TextWidth(a3) / 2 - a5;
	else
		v8 = a1 - Mess_TextWidth(a3) / 2 - a5 - a6;
	PShell_DrawHighlight(a5, a7 + a2, v8, a8);
	Mess_SetSort(0);
	if (a4)
		PShell_NormalFont();
}

// @MEDIUMTODO
void Shell_Gallery(EShellResult)
{
    printf("Shell_Gallery(EShellResult)");
}

// @MEDIUMTODO
void Shell_GameCovers(void)
{
    printf("Shell_GameCovers(void)");
}

// @MEDIUMTODO
i32 Shell_InputName(char *,i32,i32, const char *)
{
    printf("Shell_InputName(char *,i32,i32,char *)");
	return 0x27092024;
}

EXPORT u8 gInLegalScreen;

// @Ok
void Shell_LegalScreen(void)
{
	if (!gInLegalScreen)
	{
		gInLegalScreen = 1;
		Front_ClearScreen();

		DrawSync();
		Pad_ClearTriggers(gSControl);
		Pad_Update();
		Pad_ClearTriggers(gSControl);

		Sprite2* v0 = new Sprite2("LegalPC.bmp", 1, 0, 0, 3);
		u32 v3 = Vblanks + 180;
		while ( 1 )
		{
			if (!gSceneRelated)
				PCGfx_BeginScene(1u, -1);

			v0->draw(
				0,
				0,
				8,
				-1.0f);
			if (gSceneRelated)
				PCGfx_EndScene(1);
			++TTime;
			Pad_Update();

			if (Vblanks > v3)
				break;

			PCSHELL_Relax();
		}

		delete v0;
		Mess_DeleteAll();
		Front_ClearScreen();

		DrawSync();
		Pad_ClearTriggers(gSControl);
	}
}

// @MEDIUMTODO
void Shell_LevelSelect(void)
{
    printf("Shell_LevelSelect(void)");
}

// @MEDIUMTODO
void Shell_LoadGame(void)
{
    printf("Shell_LoadGame(void)");
}

// @MEDIUMTODO
void Shell_MainMenu(EShellResult)
{
    printf("Shell_MainMenu(EShellResult)");
}

// @MEDIUMTODO
void Shell_MemoryCard(EShellResult)
{
    printf("Shell_MemoryCard(EShellResult)");
}

// @MEDIUMTODO
void Shell_MovieViewer(void)
{
    printf("Shell_MovieViewer(void)");
}

// @MEDIUMTODO
void Shell_Options(EShellResult)
{
    printf("Shell_Options(EShellResult)");
}

// @MEDIUMTODO
void Shell_RollCredits(void)
{
    printf("Shell_RollCredits(void)");
}

// @MEDIUMTODO
void Shell_SFXMusic(void)
{
    printf("Shell_SFXMusic(void)");
}

// @MEDIUMTODO
void Shell_SaveGame(const u32 *,u32 *)
{
    printf("Shell_SaveGame(u32 const *,u32 *)");
}

// @MEDIUMTODO
void Shell_ScreenAdjust(void)
{
    printf("Shell_ScreenAdjust(void)");
}

// @MEDIUMTODO
void Shell_ShowRecord(char const *,char const *,STrainingMission *)
{
    printf("Shell_ShowRecord(char const *,char const *,STrainingMission *)");
}

// @MEDIUMTODO
void Shell_Special(EShellResult)
{
    printf("Shell_Special(EShellResult)");
}

// @MEDIUMTODO
void Shell_StoryBoards(void)
{
    printf("Shell_StoryBoards(void)");
}

// @MEDIUMTODO
void Shell_TitleScreen(void)
{
    printf("Shell_TitleScreen(void)");
}

// @Ok
INLINE void Shell_VerySmallFont(void)
{
	Mess_SetScale(256);
	Mess_SetCurrentFont("sp_fnt03.fnt");
}


// @BIGTODO
// fill these
EXPORT SpideyIconRelated SpideyIcons[8];


const i32 NUM_LEVELS = 34;
EXPORT u8 LevelIndexes[NUM_LEVELS];

// @Ok
// @Test
i32 CalcIndexOfContinueLevel(void)
{
	i32 bar = 1000000;
	for (i32 i = 0; i < NUM_LEVELS; i++)
	{
		if (LevelIndexes[i] < bar)
			bar = LevelIndexes[i];
	}

	i32 index;
	for (index = 0; index < NUM_LEVELS; index++)
	{
		if (LevelIndexes[index] == bar)
			break;
	}

	return index;
}

// @Ok
void Spidey_CIcon::SetIcon(i32 option)
{
	print_if_false(option >= 0 && (u32)option < 8, "Bad option");

	if (SpideyIcons[option].IconModel < 0)
	{
		this->mFlags |= 1;
		return;
	}

	this->InitItem(SpideyIcons[option].Name);

	i32 iconModel = SpideyIcons[option].IconModel;
	if (iconModel < 0)
	{
		this->mFlags |= 1;
	}
	else
	{
		print_if_false(iconModel < reinterpret_cast<i32>(PSXRegion[this->mRegion].ppModels[-1]),
				"Bad icon model");

		this->mFlags &= 0xFFFE;
		this->mModel = iconModel;
	}


	if (PSXRegion[this->mRegion].Filename[9])
	{
		this->mFlags |= 0x482;
		this->mpLight = &M3d_SpideyCIconLight;
		this->RunAnim(0, 0, -1);
	}
	else
	{
		this->mFlags &= 0xFB7D;
		this->mpLight = 0;
	}

	this->mPos.vy = SpideyIcons[option].field_10 << 12;
	this->mPos.vz = SpideyIcons[option].field_14 << 12;

	this->mAngles.vx = SpideyIcons[option].field_8;
	this->mAngles.vz = SpideyIcons[option].field_C;
}

// @Ok
Spidey_CIcon::Spidey_CIcon(i32 icon)
{
	this->SetIcon(icon);
}

// @Ok
// @Test
Spidey_CIcon::Spidey_CIcon(i32 a2, i32 a3, i32 a4)
{
	this->mPos.vx = a2 << 12;
	this->mPos.vy = a3 << 12;
	this->mPos.vz = a4 << 12;

	this->InitItem("items");

	this->mModel = 5;
	this->mFlags &= 0xFB7D;

	this->mpLight = 0;
	this->mFlags |= 0x200;
	this->mScale.vx = 2048;
	this->mScale.vy = 2048;
	this->mScale.vz = 2048;
}

// @Ok
INLINE void CallAI(CBody *pList)
{
	CBody* pCur = pList;
	if (pCur)
	{
		for (
				CBody *pNext = reinterpret_cast<CBody*>(pCur->mNextItem);
				;
				pNext = reinterpret_cast<CBody*>(pNext->mNextItem))
		{
			if (pCur->mCBodyFlags & 0x40)
			{
				if (pCur->mCBodyFlags & 0x80)
				{
					delete pCur;
				}
			}
			else
			{
				pCur->InterleaveAI();
			}

			pCur = pNext;
			if (!pNext)
				break;
		}
	}
}

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
	this->mType = 506;
	this->AttachTo(&MiscList);

	this->mFlags |= 0x200;
	this->mAngVel.vy = 50;

	this->mScale.vz = 10000;
	this->mScale.vy = 10000;
	this->mScale.vx = 10000;
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
	: CWobblyGlow(&ZeroVector, 150, 120, 90, 255, 255, 255, 0x80u, 0, 0xFFu)
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

	for (u32 i = 0; i < this->mNumSections; i++)
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
		i16 v3 = (this->mFrame << 8) | this->mFrameFrac;
		v3 += this->mAnimSpeed;

		this->mFrameFrac = v3;
		v3 >>= 8;

		this->mFrame = v3;

		if (this->mFrame >= this->mNumFrames)
		{
			this->mAnimSpeed = 0;
			this->mFrame = this->mNumFrames - 1;
		}

		this->mpPSXFrame = &this->mpPSXAnim[this->mFrame];
	}

	this->mPos += this->mVel;

	this->mVel.vy -= 1024;
	if (++this->mAge > 30)
	{
		this->Die();
	}
	else
	{
		this->SetTransparency(64 - 2 * (0xFF & this->mAge));
		this->SetScale(Rnd(4) + 4 *(this->mAge + 32));
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
	this->mAngle = Rnd(4096);
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
	print_if_false(pSuper->mType == 309, "Non SuperDocOck");

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
		new CSkinGoo(pSuper, &gCarnageSkinGooSourceShell, 19, &gCarnageSkinGooParams);
		this->field_44 = 0;
	}

}

// @Ok
CShellCarnageElectrified::CShellCarnageElectrified(CSuper* pSuper)
{
	print_if_false(pSuper != 0, "NULL pSuper sent to CShellCarnageElectrified");
	print_if_false(pSuper->mType == 314, "Non carnage sent to CShellCarnageElectrified");

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
	print_if_false(pSuper->mType == 313, "Non venom sent to CShellVenomElectrified");

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
			while (this->field_1B8[v10] == this->mAnim && v9 < 100);

			if (this->field_1B8[v10] != this->mAnim)
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
void INLINE CDummy::FadeAway(void)
{
	this->field_1F8 = 1;
	this->field_1FC = 0;

	this->mFlags &= 0xFF7F;
	this->mFlags |= 0x800;

	this->mRGB = 0x202020;

	this->OutlineOn();
	this->SetOutlineSemiTransparent();
	this->SetOutlineRGB(0, 0, 0);
}

// @Ok
void INLINE CDummy::FadeBack(void)
{
	this->field_1FC = 1;
	this->field_1F8 = 0;
}

static const i16 *word_610C48 = (i16*)0x610C48;

// @NotOk
// Global
void INLINE CWobblyGlow::Move(void)
{
	for (u32 i = 0; i < this->mNumSections; i++)
	{
		this->mInc[8+i] += this->mInc[i];
		int v3 = this->mInc[8+i];
		this->mpSections[i].Radius = this->mInnerRadius + this->mAmplitude * word_610C48[2 * (v3 & 0xFFF)] / 4096;
	}
}

// @Ok
void CShellMysterioHeadGlow::Move(void)
{
	CWobblyGlow::Move();
	this->mAngle += this->field_A4;
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

	this->mpLight = &M3d_RudeSpideyLight;

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

	if (this->mAnimFinished)
	{
		if (!this->mAnim)
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
	this->mScale.vy = 0;
	this->mRGB = 0xFFFFFF;
	this->AttachTo(&MiscList);
}

SVECTOR gYAnglesRelated;

// @NotOk
// slightly different assembly, not important
void CShellSymBurn::AI(void)
{
	this->mAngles.vy = gYAnglesRelated.vy + 2048;
	this->mScale.vx = 3000;
	this->mScale.vz = 3000;

	if (++this->field_1A4 > 60)
	{
		i32 v3 = (this->mRGB & 0xFF) - 4;
		if (v3 < 0)
			v3 = 0;

		this->mScale.vy -= 75;
		this->mRGB = v3 | ((v3 | (v3 << 8)) << 8);

		if (this->mScale.vy < 0)
			this->mScale.vy = 0;

		if (!v3 || !this->mScale.vy)
		{
			this->Die();
		}
	}
	else
	{
		i32 v5 = (this->mRGB & 0xFF) - 129;
		if (v5 < 128)
			v5 = 128;

		this->mScale.vy += 800;
		this->mRGB = v5 | ((v5 | (v5 << 8)) << 8);

		if (this->mScale.vy > 4096)
			this->mScale.vy = 4096;
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

// @Ok
// @AlmostMatching: no nullsub
void PShell_Cleanup(void)
{
	if ( gShellInitialized )
	{
		if (!gPshellArmorRealted)
		{
			PShell_BigFont();
			Mess_UnloadFont();
		}

		PShell_SmallFont();
		Mess_UnloadFont();

		Shell_VerySmallFont();
		Mess_UnloadFont();

		PShell_NormalFont();

		Spool_ClearPSX("control");
		Spool_ClearPSX("icons");
		Spool_ClearPSX("vmu");
		Spool_ClearPSX("shell");
		SFX_SpoolOutLevelSFX();

		if (gBiographies)
		{
			Mem_Delete(gBiographies);
			gBiographies = 0;
		}

		Pad_ClearAll();
		Front_ClearScreen();

		DrawSync();
		Init_KillAll();
		dword_6A7788[2] = 0;
		dword_6A7788[3] = 0;
		dword_6A7788[4] = 0;

		dword_6A7788[5] = 0;
		dword_6A7788[6] = 0;
		dword_6A7788[7] = 0;
		dword_6A7788[8] = 0;
		dword_6A7788[9] = 0;
		dword_6A7788[10] = 0;
		dword_6A7788[11] = 0;
		dword_6A7788[12] = 0;
		dword_6A7788[13] = 0;
		dword_6A7788[14] = 0;
		dword_6A7788[15] = 0;
		dword_6A7788[1] = 0;
		dword_6A7788[0] = 0;

		//nullsub_3(v0);

		gPShellCleanup = 1;
		OTPushback[0] = 1;

		OTPushback[1] = 1;
		gShellInitialized = 0;
	}
}

// @Ok
// @Matching
void PShell_Initialise(void)
{
	if (gShellFromGame)
		print_if_false(gShellInitialized == 0, "Shell initialised twice, fromgame");
	else
		print_if_false(gShellInitialized == 0, "Shell initialised twice, not fromgame");

	gPShellCleanup = 0;

	Spool_PSX("shell", 0);
	Spool_PSX("icons", 0);
	Spool_PSX("vmu", 0);
	Spool_PSX("control", 0);
	Mess_LoadFont("font_big.fnt", -1, -1, -1);
	Mess_LoadFont("sp_fnt02.fnt", -1, -1, -1);
	Mess_LoadFont("sp_fnt03.fnt", -1, -1, -1);
	SFX_SpoolInLevelSFX("menu");
	PShell_NormalFont();
	Spool_AnimAccess("menubg", &gBackgroundAnimFrame);

	OTPushback[0] = 1;
	OTPushback[1] = -60;

	PShell_MaybeUnlockStuff();
	PCSHELL_Initialize();
	gShellInitialized = 1;
}

// @Ok
// @Matching
INLINE void PShell_LowText(void)
{
	Mess_SetTextJustify(0);
	Mess_SetRGB(0x45u, 0x3Cu, 0x6Bu, 0);
	Mess_SetRGBBottom(0x28u, 35, 62);
}

// @NotOk
// @Note: validate when inlined
INLINE i32 RecordsExist(
		u8 a1,
		i8 a2,
		i8 a3)
{
	i32 v3 = -1;

	for (i32 i = 0; i < NUM_CHALLS; i++)
	{
		if (a1 == gChallenges[i].field_6
				&& a2 == gChallenges[i].field_8
				&& a3 == gChallenges[i].field_9)
		{
			v3 = i;
		}
	}
	print_if_false(v3 != -1, "Mission not found");
	return gGlobalRecords.mScores[5*v3].field_0;
}

// @Ok
INLINE i32 IsBetter(
		i32 a1,
		i32 a2,
		i32 a3)
{
	if (a3)
		return a2 > a1;

	return a1 < a2;
}

// @NotOk
// @Note: validate when inlined
INLINE void Merge(SRecords *a1, const SRecords *a2)
{
	for (i32 i = 0; i < NUM_CHALLS; i++)
	{
		Merge(&a1->mScores[5*i],
				&a2->mScores[5*i],
				gChallenges[i].field_C);
	}
}

// @Ok
// @Test
void Merge(
		SScore *a1,
		const SScore *a2,
		i32 a3)
{

	for (i32 i = 0; i < NUM_RECORDS_PER_CHALL; i++)
	{
		i32 v7 = 1;

		for (i32 j = 0; j < NUM_RECORDS_PER_CHALL; j++)
		{
			if (SameScore(&a1[i], &a2[j]))
			{
				v7 = 0;
			}
		}

		if (!a2[i].field_0)
		{
			v7 = 0;
		}

		if (v7)
		{
			i16 v11 = a2[i].field_3 + (a2[i].field_4 << 8);
			for (i32 v10 = 0; v10 < NUM_RECORDS_PER_CHALL; v10++)
			{
				i16 calc = (a1[v10].field_3 + (a1[v10].field_4 << 8));
				if (!a1[v10].field_0 ||
						IsBetter(v11, calc, a3))
				{
					for (i32 k = 4; k > v10; k--)
					{
						memcpy(&a1[k], &a1[k - 1], sizeof(SScore));
					}

					memcpy(&a1[v10], &a2[i], sizeof(SScore));
					break;
				}
			}
			
		}
	}
}

// @Ok
// @NotMatching: weeeeeeird codegen
INLINE i32 SameScore(
		const SScore *a1,
		const SScore *a2)
{
	if ( !a1->field_0 && !a2->field_0)
		return 1;
	return a1->field_0 == a2->field_0
		&& a1->field_1 == a2->field_1
		&& a1->field_2 == a2->field_2
		&& a1->field_3 == a2->field_3
		&& a1->field_4 == a2->field_4;
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

void validate_SpideyIconRelated(void)
{
	VALIDATE_SIZE(SpideyIconRelated, 0x28);

	VALIDATE(SpideyIconRelated, Name, 0x0);
	VALIDATE(SpideyIconRelated, IconModel, 0x4);
	VALIDATE(SpideyIconRelated, field_8, 0x8);
	VALIDATE(SpideyIconRelated, field_C, 0xC);
	VALIDATE(SpideyIconRelated, field_10, 0x10);
	VALIDATE(SpideyIconRelated, field_14, 0x14);
	VALIDATE(SpideyIconRelated, field_18, 0x18);
}

void validate_SSaveGame(void)
{
	VALIDATE_SIZE(SSaveGame, 0xBC);

	VALIDATE(SSaveGame, mChecksum, 0x0);
	VALIDATE(SSaveGame, field_4, 0x4);

	VALIDATE(SSaveGame, mRestartPointName, 0xD);

	VALIDATE(SSaveGame, field_3F, 0x3F);

	VALIDATE(SSaveGame, mDifficulty, 0x54);

	VALIDATE(SSaveGame, field_7B, 0x7B);

	VALIDATE(SSaveGame, field_88, 0x88);
}

void validate_SScore(void)
{
	VALIDATE_SIZE(SScore, 5);

	VALIDATE(SScore, field_0, 0x0);
	VALIDATE(SScore, field_1, 0x1);
	VALIDATE(SScore, field_2, 0x2);
	VALIDATE(SScore, field_3, 0x3);
	VALIDATE(SScore, field_4, 0x4);
}

void validate_SRecords(void)
{
	VALIDATE_SIZE(SRecords, 0x242);

	VALIDATE(SRecords, mScores, 0x3);
}

void validate_SRecordRelated(void)
{
	VALIDATE_SIZE(SRecordRelated, 0x10);

	VALIDATE(SRecordRelated, pName, 0x0);
	VALIDATE(SRecordRelated, field_6, 0x6);

	VALIDATE(SRecordRelated, field_8, 0x8);
	VALIDATE(SRecordRelated, field_9, 0x9);

	VALIDATE(SRecordRelated, field_C, 0xC);
}
