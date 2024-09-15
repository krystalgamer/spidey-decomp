#include "init.h"
#include "mem.h"
#include "PCGfx.h"
#include "dcfileio.h"
#include "dcmemcard.h"
#include "tweak.h"
#include "ps2lowsfx.h"
#include "pack.h"
#include "ps2redbook.h"
#include "m3dinit.h"
#include "spool.h"
#include "ps2pad.h"
#include "ps2gamefmv.h"
#include "pal.h"
#include "ps2card.h"
#include "front.h"
#include "mess.h"
#include "FontTools.h"
#include "trig.h"
#include "bit.h"
#include "utils.h"
#include "panel.h"
#include "spidey.h"
#include "DXinit.h"
#include "db.h"
#include "shell.h"
#include "web.h"
#include "camera.h"
#include "baddy.h"
#include "powerup.h"
#include "backgrnd.h"
#include "bullet.h"
#include "weapons.h"
#include "flash.h"
#include "physics.h"
#include "m3dzone.h"
#include "reloc.h"
#include "SpideyDX.h"

EXPORT Texture* gShadowBit;
EXPORT i32 gPsxSpArmorIndex;
EXPORT i32 gPsxRingIndex;

EXPORT i32 gInitRelatedOne;
EXPORT i32 gInitRelatedTwo;
EXPORT i32 gInitRelatedThree;
EXPORT i32 gSpideyMainRelated;

// @Ok
// can't get too match, because they wrote in an obtuse way
// can get closer with for loop but don't think it's worth it
INLINE void DeleteList(CBody *pLst)
{
	CBody* pCur = pLst;

	while (pCur)
	{
		CBody *pNext = reinterpret_cast<CBody*>(pCur->field_20);

		if (pCur->mCBodyFlags & 0x20)
		{
			delete pCur;
		}

		pCur = pNext;
	}
}

// @SMALLTODO
void Init_AtEnd(void)
{
    printf("Init_AtEnd(void)");
	DXERR_printf("\nStart of Init_AtEnd\n");
	Spool_Sync();
	DXERR_printf("1,");

	DrawSync();

	DXERR_printf("2,");
	Pause(1);

	//dword_5598B8 = 0;
	SFX_Off();
	DXERR_printf("3,");
	//j_MemCardStop(v0);
	Pause(1);
	DXERR_printf("6,");

	SetDispMask();
	DXERR_printf("7,");
	PCGfx_Exit();
	//j__sbExitSystem(v1);
	DXERR_printf("13a,");
	DXERR_printf("14,");
	DXERR_printf("17,");
	DXERR_printf("\nEnd of Init_AtEnd\n");
}

EXPORT i32 dword_60D218;

// @NotOk
// regvisit after memory stuff done
u8 Init_AtStart(i32)
{
	Port_InitAtStart();
	/*
	dword_628618 = (int *)&unk_628690;
	dword_654F54 = (int)&unk_62A5D0;
	*/
	/*
	gMemInitRelatedBottom = gPortRelatedOne;
	dword_60D218 = gPortRelatedOne + 64;
	dword_60D21C = gPortRelatedOne + 64;
	dword_60D220 = gPortRelatedOne + gSomeSize;
	*/

	Mem_Init();

	SetDispMask();

	Db_Init();
	Mem_Init();

	ClearImage2();
	DrawSync();
	SetDispMask();

	PCGfx_InitAtStart();

	FileIO_Init();
	Card_Init(1);
	Pad_InitAtStart();

	Spool_Init();

	gSpideyMainRelated = 20;
	SFX_InitAtStart();
	GameFMV_Init();
	M3dInit_InitAtStart();
	Redbook_XAInitAtStart();
	Tweak_Init();

	Pack_Init();
	Pal_Init();

	Mess_LoadFont("sp_fnt00.fnt", -1, -1, -1);
	Mess_LoadFont("sp_fnt01.fnt", -1, -1, -1);
	Front_Init();
	FontManager::ResetCharMaps();
	SFX_Init("spidey.kat");
	gReStartDeathRelated = 0;

	PutDispEnv();

	Bit_Init();
	i32 v5 = Vblanks;

	DrawSync();
	PSXRegion[Spool_PSX("webdome2", 0)].Protected = 1;
	PSXRegion[Spool_PSX("webdome3", 0)].Protected = 1;
	gInitRelatedThree = 0;

	i32 v8 = Spool_PSX("spidey", 0);
	gSpideyPsxIndex = v8;
	PSXRegion[v8].Protected = 1;
	Spidey_CopyHeadModel(v8);
	PSXRegion[Spool_PSX("bits", 0)].Protected = 1;
	Utils_InitLoadIcons();

	gPsxSpArmorIndex = Spool_PSX("spArmor", 0);
	PSXRegion[gPsxSpArmorIndex].Protected = 1;
	PSXRegion[Spool_PSX("shell_dc", 0)].Protected = 1;
	PSXRegion[Spool_PSX("costarm", 0)].Protected = 1;

	i32 v9 = Spool_PSX("items", 0);
	gPsxItemsIndex = v9;
	PSXRegion[v9].Protected = 1;
	gPsxRingIndex = Spool_PSX("ring", 0);

	PSXRegion[gPsxRingIndex].Protected = 1;
	if (!gLowGraphics)
		PSXRegion[Spool_PSX("sparmour", 0)].Protected = 1;
	Spool_Sync();

	Vblanks = v5 + 300;

	gInitRelatedTwo = 5;
	gInitRelatedOne = 5;

	Panel_Init();
	Spool_TextureAccess(0xB79DD55B, &gShadowBit);
	print_if_false(gShadowBit != 0, "No shadow bit");

	gLevelStatus = 0;
	return 0;
}

EXPORT i32 gMovieIndex = 0xFFFFFFFF;
EXPORT i32 gInitBaddyRelated;

// @Ok
void Init_Cleanup(i32 a1)
{
	Pad_ActuatorOff(0, 0);
	Pad_ActuatorOff(0, 1);

	SFX_LevelStart();

	gViewport.field_E = 256;
	Redbook_XAExit();
	GameFMV_StopFMV();
	Init_KillAll();
	Trig_DeleteCommandPoints();

	delete pYesNoMenu;

	if (a1 == 3)
	{
		for (i32 i = 0; i < MAXPSX; i++)
		{
			PSXRegion[i].Protected = 0;
		}
		Spidey_FreeHeadModel();

		a1 = 0;
	}

	if (a1)
	{
		if (a1 == 1)
		{
			Spool_ClearEnvironmentRegions();
			M3dZone_Init();
		}
	}
	else
	{
		SFX_SpoolOutLevelSFX();
		SFX_ReverbOff();
		Spool_ClearAllPSXs();
		Trig_DeleteTrigFile();

		gRestartPointName[0] = 0;
		Reloc_UnloadAll();
		M3dZone_Init();
	}




	Trig_ClearTrigMenu();
	Flash_Reset();
	Panel_Init();

	CVector v6;
	v6.vx = 0;
	v6.vy = 0x8000;
	v6.vz = 0;
	Physics_SetGravity(&v6);
	gPowerUpRelated = 0;
	Pad_ClearAll();

	gInitBaddyRelated = 0;
	SuspendedDistance = 13000;
	Levels[35].field_C = 0xFFEC;

	if ( gMovieIndex != -1 )
		GameFMV_PlayMovie(gMovieIndex, 1, 1, 1.0);
		gMovieIndex = -1;
	Redbook_XAInit();
}

// @Ok
void Init_KillAll(void)
{
	DeleteList(MechList);
	DeleteList(CameraList);
	DeleteList(BaddyList);
	DeleteList(ControlBaddyList);
	DeleteList(EnvironmentalObjectList);
	DeleteList(BackgroundList);
	DeleteList(PowerUpList);
	DeleteList(BulletList);
	DeleteList(SuspendedList);

	DeleteList(MiscList);
	DeleteList(WebList);

	print_if_false(MechList == 0, "Leftover protected members of MechList");
	print_if_false(CameraList == 0, "Leftover protected members of CameraList");
	print_if_false(BaddyList == 0, "Leftover protected members of BaddyList");
	print_if_false(ControlBaddyList == 0, "Leftover protected members of ControlBaddyList");
	print_if_false(BackgroundList == 0, "Leftover protected members of BackgroundList");
	print_if_false(EnvironmentalObjectList == 0, "Leftover protected members of EnvironmentalObjectList");
	print_if_false(PowerUpList == 0, "Leftover protected members of PowerUpList");
	print_if_false(BulletList == 0, "Leftover protected members of BulletList");
	print_if_false(SuspendedList == 0, "Leftover protected members of SuspendedList");
	print_if_false(MiscList == 0, "Leftover protected members of MiscList");
	print_if_false(WebList == 0, "Leftover protected members of WebList");
	print_if_false(SpideyAdditionalBodyPartsList == 0, "Leftover protected members of SpideyAdditionalBodyPartsList");
	print_if_false(MiscellaneousRenderingList == 0, "Leftover protected members of MiscellaneousRenderingList");
	print_if_false(CWeapons == 0, "Left over CWeapons");

	Bit_DeleteAll();
	Mess_DeleteAll();
}
