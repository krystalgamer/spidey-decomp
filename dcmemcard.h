#ifndef DCMEMCARD_H
#define DCMEMCARD_H

#pragma once

#include "export.h"
#include "stubs.h"

EXPORT i32 DCCard_BupComplete(i32,i32,i32,u32);
EXPORT SDCCardTime* DCCard_CurTime(void);
EXPORT u8 DCCard_Exists(i32);
EXPORT u32 DCCard_First(void);
EXPORT void DCCard_HappyBeep(i32,u32);
EXPORT void DCCard_InitCallback(void);
EXPORT void DCCard_SadBeep(i32,u32);
EXPORT void DCCard_StartBeep(i32);
EXPORT void DCCard_StopBeep(i32);
EXPORT void DCCard_Wait(i32,i32);
EXPORT void MemCardInit(i32);
EXPORT void MemCardStop(void);


#endif
