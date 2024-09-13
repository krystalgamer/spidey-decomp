#include "tweak.h"

i16 gGameState[30];

// @Ok
// @Matching
void Tweak_Init(void)
{
	gGameState[14] = 1;
	gGameState[8] = 0;
	gGameState[9] = 0;
	gGameState[10] = 0;
}
