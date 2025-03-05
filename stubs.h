#pragma once

#ifndef STUBS_H
#define STUBS_H

#include "export.h"

struct SDCCardTime
{
	i16 field_0;

	u8 field_2;
	u8 field_3;
	u8 field_4;
	u8 field_5;
	u8 field_6;
	u8 field_7;
};

EXPORT i32 syRtcInit(void);
EXPORT i32 gsExit(void);
EXPORT i32 syCblCheck(void);
EXPORT i32 syCblCheckBroadcast(void);
EXPORT i32 syRtcGetDate(SDCCardTime*);

EXPORT void ADXT_Finish(void);
EXPORT void ADXT_StartAfs(i32, i32, i32);
EXPORT i32 ADXT_GetStat(i32);
EXPORT void ADXT_Init(void);
EXPORT void ADXT_Stop(void);
EXPORT i32 ADXT_Create(void);
EXPORT void ADXT_Pause(i32, i32);
EXPORT void ADXT_SetOutVol(i32, i32);

void validate_SDCCardTime(void);

#endif
