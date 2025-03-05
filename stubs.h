#pragma once

#ifndef STUBS_H
#define STUBS_H

#include "export.h"
EXPORT i32 syRtcInit(void);
EXPORT i32 gsExit(void);
EXPORT i32 syCblCheck(void);
EXPORT i32 syCblCheckBroadcast(void);

EXPORT void ADXT_Finish(void);
EXPORT void ADXT_StartAfs(i32, i32, i32);
EXPORT i32 ADXT_GetStat(i32);
EXPORT void ADXT_Init(void);
EXPORT void ADXT_Stop(void);
EXPORT i32 ADXT_Create(void);
EXPORT void ADXT_Pause(i32, i32);
EXPORT void ADXT_SetOutVol(i32, i32);


#endif
