#include "PCTimer.h"
#include "non_win32.h"
#include "utils.h"

#include "validate.h"

EXPORT i32 gPcTimerPaused;

EXPORT u32 gTimerInitOne;
EXPORT u32 gTimerInitTwo;

#ifndef _WIN32
#define LPTIMECALLBACK void*
#endif
EXPORT LPTIMECALLBACK fptc;

EXPORT double gTimerMsInterval;

EXPORT STimerInfo gTimerInfo;
EXPORT double gTimerVblankRelated;

// @FIXME
#ifndef _WIN32

struct TIMECAPS
{
	u32 wPeriodMin;
	u32 wPeriodMax;
};

void onexit(...)
{
}

void timeKillEvent(UINT)
{
}

u32 timeSetEvent(...)
{
	return 69;
}

void timeBeginPeriod(...)
{
}

bool timeGetDevCaps(...)
{
}
#endif

TIMECAPS ptc;

// @Ok
void PCTIMER_Init(void)
{
	gTimerInfo.uTimerID = 0;
	gTimerInfo.field_4 = 0;
	ptc.wPeriodMin = 0;
	gTimerInfo.uPeriod = 0;
	gTimerInfo.field_C = 0;
	ptc.wPeriodMax = 0;
	fptc = 0;

	if (timeGetDevCaps(&ptc, sizeof(ptc)))
	{
		gTimerInfo.uTimerID = 0;
		print_if_false(0, "\t\tD3DTimer init error!");
		return;
	}

	UINT wPeriodMin = ptc.wPeriodMin;
	if (wPeriodMin <= 16)
		wPeriodMin = 16;

	UINT wPeriodMax;
	if (wPeriodMin < ptc.wPeriodMax)
	{
		if (ptc.wPeriodMin > 16)
		{
			wPeriodMax = ptc.wPeriodMin;
		}
		else
		{
			wPeriodMax = 16;
		}
	}
	else
	{
		wPeriodMax = ptc.wPeriodMax;
	}

	gTimerInfo.uPeriod = wPeriodMax;

	printf(
		"t\tPCTimer - Min: %i, Max: %i, Ideal: %i, Used:%i\r\n",
		ptc.wPeriodMin,
		ptc.wPeriodMax,
		16,
		wPeriodMax);

	u32 uResolution = gTimerInfo.uPeriod;
    u32 uDelay = 16;

	gTimerInfo.field_4 = 16;

	// make clang happy :)
#ifdef _WIN32
	fptc = TimerCallback;
#else
	fptc = reinterpret_cast<void*>(TimerCallback);
#endif

	if (gTimerInfo.uPeriod > 0x10)
	{
		print_if_false(0, "Timer low resolution error!");
		uResolution = gTimerInfo.uPeriod;
		uDelay = gTimerInfo.uPeriod;
		gTimerInfo.field_4 = gTimerInfo.uPeriod;
	}

	gTimerInfo.uTimerID = timeSetEvent(uDelay, uResolution, fptc, (DWORD)&gTimerInfo, 1);

	gTimerMsInterval = (double)gTimerInfo.field_4 * 60.0 / 1000.0;
	timeBeginPeriod(gTimerInfo.uPeriod);

	onexit(PCTIMER_Kill);
}

// @Ok
// @Matching
i32 PCTIMER_Kill(void)
{
	if (gTimerInfo.uTimerID)
	{
		timeKillEvent(gTimerInfo.uTimerID);
		gTimerInfo.uTimerID = 0;
	}

	return 0;
}

// @Ok
// @Matching
void PCTIMER_Pause(void)
{
	gPcTimerPaused = 1;
}

// @Ok
// @Matching
void PCTIMER_Resume(void)
{
	gPcTimerPaused = 0;
}

// @Ok
// @Matching
void CALLBACK TimerCallback(
	UINT uTimerID,
	UINT uMsg,
	unsigned long dwUser,
	unsigned long dw1,
	unsigned long dw2)
{
	STimerInfo* pTimeInfo = reinterpret_cast<STimerInfo*>(dwUser);

	if (!gPcTimerPaused)
	{
		gTimerMsInterval = (double)pTimeInfo->field_4 * 60.0 / 1000.0;
		pTimeInfo->field_C += pTimeInfo->field_4;
		gTimerVblankRelated += gTimerMsInterval;

		u32 newTime = gTimerVblankRelated;
		while ( newTime > Vblanks )
			MyVSync();
	}
	
}

void validate_STimerInfo(void)
{
	VALIDATE_SIZE(STimerInfo, 0x10);

	VALIDATE(STimerInfo, uTimerID, 0x0);
	VALIDATE(STimerInfo, field_4, 0x4);
	VALIDATE(STimerInfo, uPeriod, 0x8);
	VALIDATE(STimerInfo, field_C, 0xC);
}
