#include "ps2lowsfx.h"


// @TODO
void SFX_PlayPos(unsigned int, CVector*, int)
{}

static unsigned char gSfxStatus;
// @NotOk
// Global
void SFX_LevelStart(void)
{
	gSfxStatus = 0;
}
