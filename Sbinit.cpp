#include "Sbinit.h"
#include "pcdcFile.h"
#include "stubs.h"
#include "PCGfx.h"
#include "pcdcPad.h"
#include "pcdcMem.h"

// @Ok
INLINE void sbExitSystem(void)
{
	gdFsFinish();
	pdExitPeripheral();
	kmUnloadDevice();
	syMallocFinish();
}

EXPORT i32 gSbInitRelated;

// @Ok
void sbInitSystem(
		KMDISPLAYMODE a1,
		KMBPPMODE a2,
		i32 a3)
{
	gSbInitRelated |= 0xA0000000;

	// @FIXME: missing some logic with globals here but they're not used so idgaf
	syMallocInit();

	kmInitDevice(0);
	kmSetDisplayMode(a1, a2, 1, 0);
	kmSetWaitVsyncCount(a3);
	pdInitPeripheral();
	syRtcInit();

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
