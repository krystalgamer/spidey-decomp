#include "Sbinit.h"
#include "pcdcFile.h"
#include "stubs.h"
#include "PCGfx.h"

// @SMALLTODO
INLINE void sbExitSystem(void)
{
	printf("void sbExitSystem(void)");
}

// @SMALLTODO
void sbInitSystem(
		KMDISPLAYMODE a1,
		KMBPPMODE a2,
		i32 a3)
{
	kmInitDevice(0);
	kmSetDisplayMode(a1, a2, 1, 0);
	kmSetWaitVsyncCount(a3);
	/*
	pdInitPeripheral();
	syRtcInit();
	*/

	i32 i;
	for (i = 8; i > 0; i--)
	{
		i32 v9 = gdFsInit();
		if (v9 == -23 || v9 == -33)
		{
			sbExitSystem();
		}
		else if (!v9)
		{
			break;
		}
	}

	if (!i)
	{
		sbExitSystem();
	}
}
