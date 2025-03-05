#include "dcmemcard.h"
#include "pcdcBkup.h"
#include "stubs.h"
#include "utils.h"
#include "pcdcPad.h"

#include <cstring>

EXPORT u8 gAlarmTwo[2] = { 0xC, 0x80 };

EXPORT i32 gAlarmFirst[4] = { 1, 2, 7, 8 };

EXPORT u8 gCardData[8];
EXPORT u8 gCardInit;
EXPORT u8 gCardInitTwo;

EXPORT i32 gDcCardRelated;

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

// @SMALLTODO
void DCCard_CurTime(void)
{
    printf("DCCard_CurTime(void)");
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

// @SMALLTODO
void DCCard_HappyBeep(i32 a1, u32 a2)
{
    printf("DCCard_HappyBeep(i32,u32)");
}

// @Ok
void DCCard_InitCallback(void)
{
	buSetCompleteCallback(DCCard_BupComplete);
}

// @SMALLTODO
void DCCard_SadBeep(i32,u32)
{
    printf("DCCard_SadBeep(i32,u32)");
}

// @NotOk
// @Note: validate when inlined
INLINE void DCCard_StartBeep(i32 a1)
{
	if (gCardInitTwo)
		pdTmrAlarm(gAlarmFirst[a1], gAlarmTwo);
}

// @NotOk
// @Note: validate when inlined
INLINE void DCCard_StopBeep(i32 a1)
{
	u8 v3[4];
	v3[0] = 0;
	v3[1] = 0;
	v3[2] = 0;
	v3[3] = 0;
	pdTmrAlarm(gAlarmFirst[a1], v3);
}

// @SMALLTODO
void DCCard_Wait(i32,i32)
{
    printf("DCCard_Wait(i32,i32)");
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

// @SMALLTODO
void MemCardStop(void)
{
    printf("MemCardStop(void)");
}
