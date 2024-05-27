#include "DXinit.h"

static int gResolutionX;
static int gResolutionY;

// @NotOk
// Globals
void DXINIT_GetCurrentResolution(int *x, int *y)
{
	*x = gResolutionX;
	*y = gResolutionY;
}
