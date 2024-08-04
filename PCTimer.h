#pragma once

#ifndef PCTIMER_H
#define PCTIMER_H

#include "export.h"

EXPORT void PCTIMER_Init(void);
EXPORT void PCTIMER_IsActive(void);
EXPORT void PCTIMER_Kill(void);
EXPORT void PCTIMER_Pause(void);
EXPORT void PCTIMER_Resume(void);
EXPORT void TimerCallback_Mac(void);

#endif
