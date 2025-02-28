#ifndef MY_BINK_H
#define MY_BINK_H

#pragma once

#include "non_win32.h"
#include "export.h"

EXPORT i32 STDCALL BinkWait(i32);
EXPORT void STDCALL BinkClose(i32);
EXPORT void STDCALL BinkSetVolume(i32, i32);
EXPORT void STDCALL BinkSetPan(i32, i32);


#endif
