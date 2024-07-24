#include "cinema.h"
#include "spidey.h"
#include "ps2lowsfx.h"
#include "front.h"
#include "ps2gamefmv.h"

extern CPlayer *MechList;

EXPORT i32 gComicBookRun = 1;

// @MEDIUMTODO
u8 Cinema_ComicBookStill(const char *)
{
	printf("u8 Cinema_ComicBookStill(const char *)");
	return 0x24072024;
}

// @Ok
void Cinema_Run(u32 a1)
{
	SFX_StopAll();
	if (MechList)
	{
		if (MechList->field_134)
		{
			Mem_Delete(MechList->field_134);
			MechList->field_134 = 0;
		}
	}

	if (gComicBookRun)
		Cinema_ComicBookRun(a1);
}

// @Ok
void Cinema_ComicBookRun(u32 a1)
{
	Front_GaugeOff();
	switch ( a1 )
	{
		case 0xBu:
			Cinema_ComicBookStill("L1COV.bmp");
			GameFMV_PlayMovie(4u, 1, 1, 1.0);
			break;
		case 0xCu:
			GameFMV_PlayMovie(5u, 1, 1, 1.0);
			break;
		case 0x15u:
			Cinema_ComicBookStill("L2COV.bmp");
			GameFMV_PlayMovie(6u, 1, 1, 1.0);
			break;
		case 0x16u:
			GameFMV_PlayMovie(7u, 1, 1, 1.0);
			break;
		case 0x17u:
			GameFMV_PlayMovie(8u, 1, 1, 1.0);
			break;
		case 0x1Fu:
			GameFMV_PlayMovie(9u, 1, 1, 1.0);
			break;
		case 0x29u:
			Cinema_ComicBookStill("L4COV.bmp");
			GameFMV_PlayMovie(0xAu, 1, 1, 1.0);
			break;
		case 0x2Au:
			GameFMV_PlayMovie(0xBu, 1, 1, 1.0);
			break;
		case 0x33u:
			Cinema_ComicBookStill("L5COV.bmp");
			GameFMV_PlayMovie(0xCu, 1, 1, 1.0);
			break;
		case 0x34u:
			GameFMV_PlayMovie(0xDu, 1, 1, 1.0);
			break;
		case 0x35u:
			GameFMV_PlayMovie(0xEu, 1, 1, 1.0);
			break;
		case 0x36u:
			GameFMV_PlayMovie(0xFu, 1, 1, 1.0);
			break;
		case 0x3Du:
			GameFMV_PlayMovie(0x10u, 1, 1, 1.0);
			break;
		case 0x47u:
			Cinema_ComicBookStill("L7COV.bmp");
			GameFMV_PlayMovie(0x11u, 1, 1, 1.0);
			break;
		case 0x48u:
			GameFMV_PlayMovie(0x12u, 1, 1, 1.0);
			break;
		case 0x49u:
			GameFMV_PlayMovie(0x13u, 1, 1, 1.0);
			break;
		case 0x51u:
			Cinema_ComicBookStill("L8COV.bmp");
			GameFMV_PlayMovie(0x14u, 1, 1, 1.0);
			break;
		case 0x52u:
			GameFMV_PlayMovie(0x15u, 1, 1, 1.0);
			break;
		case 0x53u:
			GameFMV_PlayMovie(0x16u, 1, 1, 1.0);
			break;
		case 0x54u:
			GameFMV_PlayMovie(0x17u, 1, 1, 1.0);
			break;
		case 0x55u:
			GameFMV_PlayMovie(0x18u, 1, 1, 1.0);
			break;
		default:
			break;
	}
}
