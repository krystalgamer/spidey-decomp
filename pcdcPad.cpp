#include "pcdcPad.h"
#include "PCInput.h"
#include "ps2pad.h"
#include "PCShell.h"


#include <cstring>
#include "validate.h"



#define NUM_PADS 1
EXPORT SPdPadSmall gPdPeriRelated[NUM_PADS];
EXPORT SPdPadBig gBigPad[NUM_PADS];

// @Ok
// @Matching
i32 Pad_Update(void)
{
	Pad_IdleTime++;
	u32 v3;
	u32 v4;
	PCINPUT_GetMappedStates(&v3, &v4);

	if (PCSHELL_UpdateMouse())
		Pad_IdleTime = 0;

	for (i32 i = 0; i < NUM_CONTROLLERS; i++)
	{
		gSControl[i].field_16C = 65;
		Pad_Button(&gSControl[i].Triangle, v3 & 0x80);
		Pad_Button(&gSControl[i].Square, v3 & 0x40);
		Pad_Button(&gSControl[i].Circle, v3 & 0x20);
		Pad_Button(&gSControl[i].X, v3 & 0x10);
		Pad_Button(&gSControl[i].LeftOne, v3 & 0x100);
		Pad_Button(&gSControl[i].LeftTwo, 0);
		Pad_Button(&gSControl[i].RightOne, v3 & 0x200);
		Pad_Button(&gSControl[i].RightTwo, v3 & 0x400);
		Pad_Button(&gSControl[i].Left, v3 & 4);
		Pad_Button(&gSControl[i].Right, v3 & 8);
		Pad_Button(&gSControl[i].Up, v3 & 1);
		Pad_Button(&gSControl[i].Down, v3 & 2);
		Pad_Button(&gSControl[i].AnalogueLeft, 0);
		Pad_Button(&gSControl[i].AnalogueRight, 0);
		Pad_Button(&gSControl[i].Start, v3 & 0x1000);
		Pad_Button(&gSControl[i].Select, 0);
		if ( !i )
		{
			Pad_Button(&gSControl[0].Crouch, v3 & 0x10);
			Pad_Button(&gSControl[0].Jump, v3 & 0x80);
			Pad_Button(&gSControl[0].SmartBomb, v3 & 0x40);
			Pad_Button(&gSControl[0].SelectWeapon, v3 & 0x20);
		}
	}

	DCPad_ExpireVibrations();
	return 0;
}

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
i32 pdVibMxIsReady(void)
{
	return 1;
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
