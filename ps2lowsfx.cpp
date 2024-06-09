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

static unsigned char gReverbType;
void __inline SFX_SetReverbType(unsigned char reverb)
{
	gReverbType = reverb != 0;
}

// @Ok
void SFX_ReverbOff(void)
{
	SFX_SetReverbType(0);
}

// @TODO
void SFX_Stop(unsigned int)
{}

// @TODO
void SFX_Play(u32, i16, i32)
{}
