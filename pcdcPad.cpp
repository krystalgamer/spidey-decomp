#include "pcdcPad.h"
#include "PCInput.h"

#include <cstring>
#include "validate.h"



EXPORT SPdPadSmall gPdPeriRelated;

#define NUM_BIG_PAD 1
EXPORT SPdPadBig gBigPad[NUM_BIG_PAD];

// @Ok
// @Matching
void pdInitPeripheral(void)
{
	memset(&gPdPeriRelated, 0, sizeof(gPdPeriRelated));

	for (i32 i = 0; i < NUM_BIG_PAD; i++)
	{
		SPdPadBig *pBig = &gBigPad[i];
		gPdPeriRelated.pBig = pBig;

		gPdPeriRelated.pBig->field_0 = 1;
	}

	PCINPUT_Initialize();
}

// @Ok
void pdExitPeripheral(void)
{
	PCINPUT_Shutdown();
}

// @Ok
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
