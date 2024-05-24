#include "flash.h"

static int gFadeStatus;

// @NotOk
// global
int Flash_FadeFinished(void)
{
	return gFadeStatus == 0;
}
