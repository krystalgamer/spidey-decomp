#include "screen.h"


static bool gScreenTarget;

// @NotOk
// Globals
void Screen_TargetOn(bool value)
{
	gScreenTarget = value;
}
