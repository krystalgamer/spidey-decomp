#include "PCInput.h"

static unsigned char gMouseStatus;

// @NotOk
// Globals
int PCINPUT_GetMouseStatus(void)
{
	return gMouseStatus;
}
