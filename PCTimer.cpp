#include "PCTimer.h"
#include "non_win32.h"

EXPORT UINT uTimerID;

// @FIXME
#ifndef _OLD_WINDOWS
void timeKillEvent(UINT)
{
}
#endif

// @SMALLTODO
void PCTIMER_Init(void)
{
    printf("PCTIMER_Init(void)");
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

// @SMALLTODO
void PCTIMER_Pause(void)
{
    printf("PCTIMER_Pause(void)");
}

// @SMALLTODO
void PCTIMER_Resume(void)
{
    printf("PCTIMER_Resume(void)");
}

// @SMALLTODO
void TimerCallback_Mac(void)
{
    printf("TimerCallback_Mac(void)");
}
