#include "PCTimer.h"
#include "non_win32.h"

EXPORT UINT uTimerID;
EXPORT UINT uPeriod;
EXPORT i32 gPcTimerPaused;

EXPORT u32 gTimerInitOne;
EXPORT u32 gTimerInitTwo;

#ifndef _OLD_WINDOWS
#define LPTIMECALLBACK void*
#endif
EXPORT LPTIMECALLBACK fptc;

EXPORT double gTimerMsInterval;

// @FIXME
#ifndef _OLD_WINDOWS

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

// @SMALLTODO
void PCTIMER_Init(void)
{
	uTimerID = 0;
	gTimerInitOne = 0;
	ptc.wPeriodMin = 0;
	uPeriod = 0;
	gTimerInitTwo = 0;
	ptc.wPeriodMax = 0;
	fptc = 0;

	if (timeGetDevCaps(&ptc, sizeof(ptc)))
	{
		uTimerID = 0;
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

	uPeriod = wPeriodMax;

	printf(
		"t\tPCTimer - Min: %i, Max: %i, Ideal: %i, Used:%i\r\n",
		ptc.wPeriodMin,
		ptc.wPeriodMax,
		16,
		wPeriodMax);

	u32 uResolution = uPeriod;
    u32 uDelay = 16;

	gTimerInitOne = 16;

	fptc = TimerCallback;
	if (uPeriod > 0x10)
	{
		print_if_false(0, "Timer low resolution error!");
		uResolution = uPeriod;
		uDelay = uPeriod;
		gTimerInitOne = uPeriod;
	}

	uTimerID = timeSetEvent(uDelay, uResolution, fptc, (DWORD)&uTimerID, 1);

	gTimerMsInterval = (double)gTimerInitOne * 60.0 / 1000.0;
	timeBeginPeriod(uPeriod);

	onexit(PCTIMER_Kill);
}

// @SMALLTODO
void PCTIMER_IsActive(void)
{
    printf("PCTIMER_IsActive(void)");
}

// @Ok
// @Matching
i32 PCTIMER_Kill(void)
{
	if (uTimerID)
	{
		timeKillEvent(uTimerID);
		uTimerID = 0;
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

// @SMALLTODO
void CALLBACK TimerCallback(
	UINT uTimerID,
	UINT uMsg,
	unsigned long dwUser,
	unsigned long dw1,
	unsigned long dw2)
{
    printf("TimerCallback_Mac(void)");
}
