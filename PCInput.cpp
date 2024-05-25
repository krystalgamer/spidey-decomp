#include "PCInput.h"

static unsigned char gMouseStatus;

// @NotOk
// Globals
int PCINPUT_GetMouseStatus(void)
{
	return gMouseStatus;
}

static int gMouseBoundOne;
static int gMouseBoundTwo;
static int gMouseBoundThree;
static int gMouseBoundFour;


// @NotOk
// Globals
void PCINPUT_SetMouseBound(int a1, int a2, int a3, int a4)
{
	gMouseBoundOne = a1;
	gMouseBoundTwo = a2;
	gMouseBoundThree = a3;
	gMouseBoundFour = a4;
}

static int gMouseX;
static int gMouseY;

// @NotOk
// Globals
void PCINPUT_GetMousePosition(int *x, int *y)
{
	*x = gMouseX;
	*y = gMouseY;
}
