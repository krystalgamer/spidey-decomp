#pragma once

#ifndef PCINPUT_H
#define PCINPUT_H

#include "export.h"

EXPORT int PCINPUT_GetMouseStatus(void);
EXPORT void PCINPUT_SetMouseBound(int, int, int, int);
EXPORT void PCINPUT_GetMousePosition(int*, int*);

#endif
