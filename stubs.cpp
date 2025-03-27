#include "stubs.h"
#include "PCMusic.h"
#include "validate.h"

#include <cstdlib>

// @Ok
// @Matching
i32 syCfgSetSoundMode(i32)
{
	return 0;
}

// @Ok
// @Matching
i32 syCfgInit(void*)
{
	return 0;
}

// @Ok
// @Matching
void ADXT_SetOutVol(i32, i32 a2)
{
	PCMUSIC_SetVolume(a2);
}

// @Ok
// @Matching
void ADXT_Pause(i32, i32 a2)
{
	PCMUSIC_Pause(a2);
}

// @Ok
// @Matching
i32 ADXT_Create(void)
{
	return 0;
}

// @Ok
// @Matching
void ADXT_Stop(void)
{
	PCMUSIC_Stop();
}

// @Ok
// @Matching
void ADXT_Init(void)
{
	PCMUSIC_Init();
}

// @Ok
// @Matching
i32 ADXT_GetStat(i32)
{
	return PCMUSIC_GetStatus() ? 4 : 0;
}

// @Ok
// @Matching
void ADXT_StartAfs(i32, i32, i32 a3)
{
	PCMUSIC_Play(a3);
}

// @Ok
// @Matching
void ADXT_Finish(void)
{
	PCMUSIC_Finish();
}


// @Ok
// @Matching
i32 syRtcInit(void)
{
	return 0;
}

// @Ok
// @Matching
i32 gsExit(void)
{
	return 1;
}

// @Ok
// @Matching
i32 syCblCheck(void)
{
	return 1;
}

// @Ok
// @Matching
i32 syCblCheckBroadcast(void)
{
	return 0;
}

// @Ok
// @Matching
i32 syRtcGetDate(SDCCardFullTime*)
{
	return 0;
}

void validate_SDCCardTime(void)
{
	VALIDATE_SIZE(SDCCardTime, 0x8);

	VALIDATE(SDCCardTime, field_0, 0x0);

	VALIDATE(SDCCardTime, field_2, 0x2);
	VALIDATE(SDCCardTime, field_3, 0x3);
	VALIDATE(SDCCardTime, field_4, 0x4);
	VALIDATE(SDCCardTime, field_5, 0x5);
	VALIDATE(SDCCardTime, field_6, 0x6);
}

void validate_SDCCardFullTime(void)
{
	VALIDATE_SIZE(SDCCardFullTime, 0xC);

	VALIDATE(SDCCardFullTime, mTime, 0x0);
	VALIDATE(SDCCardFullTime, field_8, 0x8);
}
