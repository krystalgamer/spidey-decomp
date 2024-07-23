#include "ps2lowsfx.h"


// @BIGTODO
i32 SFX_PlayPos(u32, CVector*, i32)
{
	return 0x23072024;
}

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

// @BIGTODO
void SFX_Stop(unsigned int)
{}

// @BIGTODO
void SFX_Play(u32, i16, i32)
{}
