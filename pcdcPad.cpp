#include "pcdcPad.h"
#include "PCInput.h"

#include <cstring>
#include "validate.h"



#define NUM_PADS 1
EXPORT SPdPadSmall gPdPeriRelated[NUM_PADS];

EXPORT SPdPadBig gBigPad[NUM_PADS];

// @Ok
// @Matching
void pdInitPeripheral(void)
{
	memset(gPdPeriRelated, 0, sizeof(SPdPadSmall) * NUM_PADS);

	for (i32 i = 0; i < NUM_PADS; i++)
	{
		SPdPadBig *pBig = &gBigPad[i];

		gPdPeriRelated[i].pBig = pBig;
		gPdPeriRelated[i].pBig->field_0 = 1;
	}

	PCINPUT_Initialize();
}

// @Ok
// @Matching
void pdExitPeripheral(void)
{
	PCINPUT_Shutdown();
}

// @Ok
// @Matching
SPdPadSmall* pdGetPeripheral(u32 a1)
{
	return &gPdPeriRelated[a1 / 6];
}

// @Ok
// @Matching
i32 pdVibMxStart(void)
{
	if (PCINPUT_SetupForceFeedbackSineEffect(2000, 5.0f))
		PCINPUT_StartForceFeedbackEffect();
	return 0;
}

// @Ok
// @Matching
i32 pdVibMxStop(i32)
{
	PCINPUT_StopForceFeedbackEffect();
	return 0;
}

// @Ok
// @Matching
i32 pdTmrAlarm(i32, u8*)
{
	return 0;
}

void validate_SPdPadBig(void)
{
	VALIDATE_SIZE(SPdPadBig, 0x78);

	VALIDATE(SPdPadBig, field_0, 0x0);
}

void validate_SPdPadSmall(void)
{
	VALIDATE_SIZE(SPdPadSmall, 0x34);

	VALIDATE(SPdPadSmall, pBig, 0x30);
}
