#include "cinema.h"
#include "spidey.h"
#include "ps2lowsfx.h"

extern CPlayer *MechList;

EXPORT i32 gComicBookRun = 1;

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

// @MEDIUMTODO
void Cinema_ComicBookRun(u32)
{
	printf("void Cinema_ComicBookRun(u32)");
}
