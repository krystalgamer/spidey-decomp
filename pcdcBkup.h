#pragma once

#ifndef PCDCBKUP_H
#define PCDCBKUP_H

#include "export.h"

EXPORT i32 buInit(i32, i32, void*, void (*a4)(void));
EXPORT void buSetCompleteCallback(i32 (*pFunc)(i32, i32, i32, u32));
EXPORT i32 buIsReady(i32);
#endif
