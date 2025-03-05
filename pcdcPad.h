#pragma once

#ifndef PCDCPAD_H
#define PCDCPAD_H

#include "export.h"

EXPORT void pdInitPeripheral(void);
EXPORT void pdExitPeripheral(void);
EXPORT i32 pdTmrAlarm(i32, u8*);
#endif
