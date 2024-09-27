#pragma once

#ifndef SHELL_H
#define SHELL_H

#include "ob.h"
#include "export.h"

EXPORT extern CBody *MiscList;

struct SSaveGame
{
	u32 mChecksum;
	u8 padAfter4[0x3F-0x0-4];

	// @FIXME: figure proper size
	char field_3F[1];

	u8 padBottom[0xBC-0x3F-1];
};

class CWobblyGlow : public CGlow
{
	public:
		EXPORT CWobblyGlow(CVector*, i32, i32, i32, u8, u8, u8, u8, u8, u8);
		EXPORT virtual void Move(void);

		i32 mInc[8];
		i32 mT[8];

		i32 mAmplitude;
		i32 mInnerRadius;
};

class CShellMysterioHeadGlow : public CWobblyGlow
{
	public:
		EXPORT CShellMysterioHeadGlow(void);
		EXPORT virtual void Move(void);

		unsigned __int16 field_A4;

		unsigned char padBottom[0xA8-0xA4-2];
};

class CRudeWordHitterSpidey : public CSuper
{
public:
	EXPORT CRudeWordHitterSpidey(void);
	EXPORT void AI(void);

	i32 field_1A4;
	i32 field_1A8;

};

class CDummy : public CSuper {
public:
	EXPORT void FadeBack(void);
	EXPORT void FadeAway(void);
	EXPORT void SelectNewTrack(int);
	EXPORT void SelectNewAnim(void);

	u16* field_1A4;
	u16* field_1A8;
	u16* field_1AC;

	u8 padAfter1AC[0x1B8-0x1AC-4];

	u16* field_1B8;
	u16* field_1BC;
	i32 field_1C0;

	u8 padAfter1BC[0x1F8-0x1C0-4];


	i32 field_1F8;
	i32 field_1FC;
	unsigned char padAfter1FC[0x240-0x1FC-4];

	CItem field_240;
	unsigned char padAfter240[0x288 - 0x240 - sizeof(CItem)];
	CItem field_288;
	unsigned char padAfter288[0x2d4 - 0x288 - sizeof(CItem)];


	CVector field_2D4[4];
	CVector field_304[23];
	CVector field_418[128];
};

class Spidey_CIcon : public CSuper
{
	public:
		EXPORT Spidey_CIcon(i32, i32, i32);
		EXPORT Spidey_CIcon(i32);
		EXPORT void AI(void);
		EXPORT void SetIcon(i32);
};

class CShellSymBurn : public CSuper
{
	public:
		EXPORT CShellSymBurn(CVector*);
		EXPORT void AI(void);

		i32 field_1A4;
};

class CShellVenomElectrified : public CNonRenderedBit
{
	public:
		EXPORT CShellVenomElectrified(CSuper*);
		EXPORT virtual void Move(void);

		SHandle field_3C;
		i32 field_44;
};

class CShellCarnageElectrified : public CNonRenderedBit
{
	public:
		EXPORT CShellCarnageElectrified(CSuper*);
		EXPORT virtual void Move(void);

		SHandle field_3C;
		i32 field_44;
};

class CShellSuperDocOckElectrified : public CNonRenderedBit
{
	public:
		EXPORT CShellSuperDocOckElectrified(CSuper*);
		EXPORT virtual void Move(void);

		SHandle field_3C;
		i32 field_44;
};

class CShellRhinoNasalSteam : public CFlatBit
{
	public:
		EXPORT CShellRhinoNasalSteam(CVector*, CVector*);
		EXPORT virtual void Move(void);
};

class CShellEmber : public CFlatBit
{
	public:
		EXPORT CShellEmber(CVector*, i32);
		EXPORT virtual void Move(void);

		i32 field_68;
		i32 field_6C;
		i32 field_70;
		i32 field_74;
		i32 field_78;
		i32 field_7C;
		i32 field_80;
		i32 field_84;
		i32 field_88;
		i32 field_8C;
};

class CShellSimbyMeltSplat : public CQuadBit
{
	public:
		EXPORT CShellSimbyMeltSplat(CVector*);
		EXPORT virtual void Move(void);


		i32 field_84;
		i32 field_88;
		i32 field_8C;
		CVector field_90;
		CVector field_9C;
		CVector field_A8;
};

class CShellSimbyFireDeath : public CNonRenderedBit
{
	public:
		EXPORT CShellSimbyFireDeath(CDummy*);
		u8 fullPad[0x15];
};

class CShellGoldFish : public CBody
{
	public:
		EXPORT CShellGoldFish(CDummy*);
		EXPORT virtual ~CShellGoldFish(void);
		EXPORT virtual void AI(void);

		u8 padTop[4];
		SHandle field_F8;
		i32 field_100;
		i32 field_104;
		i32 field_108;
		i32 field_10C;
		i32 field_110;
		i32 field_114;
};

class CShellMysterioHeadCircle : public CQuadBit
{
	public:
		EXPORT CShellMysterioHeadCircle(CDummy*);
		EXPORT virtual ~CShellMysterioHeadCircle(void);
		EXPORT virtual void Move(void);

		SHandle field_84;
		u8 padAfter84[4];

		i32 field_90;
};

struct SpideyIconRelated
{
	char *Name;
	i32 IconModel;
	i16 field_8;
	u8 padAfter8[2];

	i16 field_C;
	u8 padAfterC[2];

	i32 field_10;
	i32 field_14;
	i32 field_18;

	u8 padBottom[0x28-0x18-4];
};

struct STrainingMission
{
};

enum EShellResult
{
};

class CMenu;

static const i32 INPUT_MAX_SIZE = 9;

EXPORT i32 Shell_DeRudify(char[INPUT_MAX_SIZE]);
EXPORT i32 Shell_ContainsSubString(const char*, const char*);
EXPORT void CallAI(CBody *);
EXPORT i32 CalcIndexOfContinueLevel(void);

EXPORT void Shell_AddGameSlots(CMenu *);
EXPORT u32 Shell_CalculateGameChecksum(SSaveGame *);
EXPORT void Shell_CharacterViewer(void);
EXPORT void Shell_Cheats(void);
EXPORT void Shell_ChooseEnemy(i32,u8,signed char);
EXPORT void Shell_ChooseItemCollection(i32);
EXPORT void Shell_ChooseSpeedTraining(i32);
EXPORT void Shell_ChooseSurvivalArena(i32);
EXPORT void Shell_ChooseTime(i32,i32);
EXPORT void Shell_ChooseTrainingControlType(void);
EXPORT void Shell_ChooseTrainingMission(i32);
EXPORT void Shell_ComicCollection(void);
EXPORT void Shell_CostumeViewer(void);
EXPORT void Shell_Difficulty(i32);
EXPORT void Shell_DisplayGameInfo(i32,i32,SSaveGame *);
EXPORT void Shell_DoShell(u32 const *,u32 *);
EXPORT void Shell_DrawBackground(void);
EXPORT void Shell_DrawTitleBar(i32,i32,const char *,i32,i32,i32,i32,i32);
EXPORT void Shell_Gallery(EShellResult);
EXPORT void Shell_GameCovers(void);
EXPORT i32 Shell_InputName(char *,i32,i32, const char *);
EXPORT void Shell_LegalScreen(void);
EXPORT void Shell_LevelSelect(void);
EXPORT void Shell_LoadGame(void);
EXPORT void Shell_MainMenu(EShellResult);
EXPORT void Shell_MemoryCard(EShellResult);
EXPORT void Shell_MovieViewer(void);
EXPORT void Shell_Options(EShellResult);
EXPORT void Shell_RollCredits(void);
EXPORT void Shell_SFXMusic(void);
EXPORT void Shell_SaveGame(u32 const *,u32 *);
EXPORT void Shell_ScreenAdjust(void);
EXPORT void Shell_ShowRecord(char const *,char const *,STrainingMission *);
EXPORT void Shell_Special(EShellResult);
EXPORT void Shell_StoryBoards(void);
EXPORT void Shell_TitleScreen(void);
EXPORT void Shell_VerySmallFont(void);

void validate_CRudeWordHitterSpidey(void);
void validate_CDummy(void);
void validate_CWobblyGlow(void);
void validate_CShellMysterioHeadGlow(void);
void validate_Spidey_CIcon(void);
void validate_CShellSymBurn(void);
void validate_CShellVenomElectrified(void);
void validate_CShellCarnageElectrified(void);
void validate_CShellSuperDocOckElectrified(void);
void validate_CShellRhinoNasalSteam(void);
void validate_CShellEmber(void);
void validate_CShellSimbyMeltSplat(void);
void validate_CShellSimbyFireDeath(void);
void validate_CShellGoldFish(void);
void validate_CShellMysterioHeadCircle(void);
void validate_SpideyIconRelated(void);
void validate_SSaveGame(void);

#endif
