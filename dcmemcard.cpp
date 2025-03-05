#include "dcmemcard.h"
#include "pcdcBkup.h"
#include "stubs.h"
#include "utils.h"
#include "pcdcPad.h"

#include "validate.h"

#include <cstring>

EXPORT u8 gAlarmTwo[2] = { 0xC, 0x80 };

EXPORT i32 gAlarmFirst[4] = { 1, 2, 7, 8 };

EXPORT u8 gCardData[8];
EXPORT u8 gCardInit;
EXPORT u8 gCardInitTwo;

EXPORT i32 gDcCardRelated;

EXPORT SDCCardTime gCurTime;

// @Ok
// @Matching
i32 DCCard_BupComplete(
		i32 a1,
		i32 a2,
		i32 a3,
		u32)
{
	switch (a2)
	{
		case 1:
			gDcCardRelated = 0;
			if (!a3)
			{
				gCardData[a1] = 1;
				buIsReady(a1);
			}
			break;
		case 2:
			gDcCardRelated = 0;
			gCardData[a1] = 0;
			break;
	}
	return 0;
}

// @Ok
SDCCardTime* DCCard_CurTime(void)
{
	SDCCardTime v1;
	syRtcGetDate(&v1);

	gCurTime.field_3 = v1.field_3;
	gCurTime.field_0 = v1.field_0;
	gCurTime.field_2 = v1.field_2;
	gCurTime.field_6 = v1.field_6;
	gCurTime.field_4 = v1.field_4;
	gCurTime.field_5 = v1.field_5;

	return &gCurTime;
}

// @Ok
// @Matching
INLINE u8 DCCard_Exists(i32 a1)
{
	u32 v0 = Vblanks;
	i32 i;

	for (i = buIsFormat(a1); i == -1; i = buIsFormat(a1))
	{
		if (Vblanks - v0 > 0x78)
			break;
	}

	// @Note: got it to match! i == 0 would make it generate code with edx for some reason
	if (i)
		return 0;
	return 1;
}

// @Ok
// @Matching
u32 DCCard_First(void)
{
	// @Note: must be like this to match ffs
	if (!DCCard_Exists(0))
		return 0xFFFFFFFF;
	return 0;
}

// @Ok
// @AlmostMatching: diff reg allocation
void DCCard_HappyBeep(i32 a1, u32 a2)
{
	gAlarmTwo[0] = -1;
	gAlarmTwo[1] = 64;
	DCCard_StartBeep(a1);

	u32 v2 = Vblanks;
	u32 v3 = v2 + (a2 >> 1);

	while (Vblanks < v3)
	{
		--gAlarmTwo[1];
		gAlarmTwo[0] = 2 * gAlarmTwo[1];

		DCCard_StartBeep(a1);
	}

	while (Vblanks < v2 + a2)
		;

	DCCard_StopBeep(a1);
}

// @Ok
void DCCard_InitCallback(void)
{
	buSetCompleteCallback(DCCard_BupComplete);
}

// @Ok
// @AlmostMatching: diff reg allocation
void DCCard_SadBeep(i32 a1, u32 a2)
{
	gAlarmTwo[0] = -1;
	gAlarmTwo[1] = 64;
	DCCard_StartBeep(a1);

	u32 v2 = Vblanks;
	u32 v3 = (a2 >> 1) + v2;
	while (Vblanks < v3)
	{
		DCCard_StartBeep(a1);
	}

	while (Vblanks < v2 + a2)
		;

	DCCard_StopBeep(a1);
}

// @Ok
// @Matching
INLINE void DCCard_StartBeep(i32 a1)
{
	if (gCardInitTwo)
		pdTmrAlarm(gAlarmFirst[a1], gAlarmTwo);
}

// @Ok
// @Matching
INLINE void DCCard_StopBeep(i32 a1)
{
	u8 v3[4];
	v3[0] = 0;
	v3[1] = 0;
	v3[2] = 0;
	v3[3] = 0;
	pdTmrAlarm(gAlarmFirst[a1], v3);
}

// @Ok
// @Matching
u8 DCCard_Wait(i32 a1,i32 a2)
{
	if (!gCardData[a1])
		return 0;

	u32 v3 = Vblanks;

	do
	{
	} while(buStat(a1) == -1 && Vblanks - v3 < static_cast<u32>(a2));

	return buGetLastError(a1) == 0;
}

// @Ok
void MemCardInit(i32)
{
	print_if_false(gCardInit == 0, "card already initialized");
	memset(gCardData, 0, sizeof(gCardData));
	print_if_false(buInit(122, 255, NULL, DCCard_InitCallback) == 0, "bu init failed");

	gCardInit = 1;
	gCardInitTwo = 1;
}

// @Ok
// @Matching
void MemCardStop(void)
{
	DebugPrintfX("Shutting down backup subsystem");
	gCardInit = 0;

	do
	{
	}
	while (buExit());
}
