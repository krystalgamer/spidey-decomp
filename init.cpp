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

// @SMALLTODO
void DeleteList(CBody *)
{
    printf("DeleteList(CBody *)");
}

// @SMALLTODO
void Init_AtEnd(void)
{
    printf("Init_AtEnd(void)");
}

// @MEDIUMTODO
u8 Init_AtStart(i32)
{
	/*
	Port_InitAtStart();
	dword_628618 = (int *)&unk_628690;
	dword_654F54 = (int)&unk_62A5D0;
	gMemInitRelatedBottom = dword_6150DC;
	dword_60D218 = dword_6150DC + 64;
	dword_60D21C = dword_6150DC + 64;
	dword_60D220 = dword_6150DC + off_54F034;
	Mem_Init();
	if ( !gPrintStubbed )
	stubbed_printf("stubbed out: SetDispMask");
	Db_Init();
	Utils_Init();
	if ( !gPrintStubbed )
	{
	stubbed_printf("stubbed out: ClearImage2");
	if ( !gPrintStubbed )
	{
	stubbed_printf("stubbed out: DrawSync");
	if ( !gPrintStubbed )
	stubbed_printf("stubbed out: SetDispMask");
	}
	}
	*/

	PCGfx_InitAtStart();

	FileIO_Init();
	Card_Init(1);
	Pad_InitAtStart();

	Spool_Init();

	// dword_54A510 = 20;
	SFX_InitAtStart();
	GameFMV_Init();
	M3dInit_InitAtStart();
	Redbook_XAInitAtStart();
	Tweak_Init();

	Pack_Init();
	Pal_Init();

	/*
	Mess_LoadFont("sp_fnt00.fnt", -1, -1, -1);
	Mess_LoadFont("sp_fnt01.fnt", -1, -1, -1);
	Front_Init();
	FontManager::ResetCharMaps();
	SFX_Init("spidey.kat");
	gReStartDeathRelated = 0;
	if ( !gPrintStubbed )
	stubbed_printf("stubbed out: PutDispEnv");
	Bit_Init();
	v5 = Vblanks;
	nullsub_3(v6);
	if ( !gPrintStubbed )
	stubbed_printf("stubbed out: DrawSync");
	PSXRegion[Spool_PSX("webdome2", 0)].Protected = 1;
	v7 = Spool_PSX("webdome3", 0);
	dword_5FB1AC = 0;
	PSXRegion[v7].Protected = 1;
	v8 = Spool_PSX("spidey", 0);
	byte_6B4679 = v8;
	PSXRegion[v8].Protected = 1;
	Spidey_CopyHeadModel(v8);
	PSXRegion[Spool_PSX("bits", 0)].Protected = 1;
	Utils_InitLoadIcons();
	dword_54AE18 = Spool_PSX("spArmor", 0);
	PSXRegion[dword_54AE18].Protected = 1;
	PSXRegion[Spool_PSX("shell_dc", 0)].Protected = 1;
	PSXRegion[Spool_PSX("costarm", 0)].Protected = 1;
	v9 = Spool_PSX("items", 0);
	byte_6B4678 = v9;
	PSXRegion[v9].Protected = 1;
	dword_55AA34 = Spool_PSX("ring", 0);
	v11 = gLowGraphics == 0;
	PSXRegion[dword_55AA34].Protected = 1;
	if ( !v11 )
	{
	v12 = Spool_PSX("sparmour", 0);
	v10 = 17 * v12;
	PSXRegion[v12].Protected = 1;
	}
	Spool_Sync((void *)v10);
	nullsub_3(v13);
	Vblanks = v5 + 300;
	dword_5FB1B0 = 5;
	dword_5FB0D0 = 5;
	Panel_Init();
	Spool_TextureAccess((char *)0xB79DD55B, (int)&gShadowBit);
	print_if_false(gShadowBit != 0, "No shadow bit");
	nullsub_3(v14);
	nullsub_3(v15);
	dword_60CFA4 = 0;
	*/
	return 0;
}

// @SMALLTODO
void Init_Cleanup(i32)
{
    printf("Init_Cleanup(i32)");
}

// @MEDIUMTODO
void Init_KillAll(void)
{
    printf("Init_KillAll(void)");
}
