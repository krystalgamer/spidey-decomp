#pragma once

#ifndef PS2REDBOOK_H
#define PS2REDBOOK_H

#include "export.h"


EXPORT void Redbook_XAStop(void);
EXPORT int Redbook_XAPlay(int, int, int);
EXPORT void Redbook_XAAllow(bool);
EXPORT void Redbook_XAInitAtStart(void);
EXPORT void Redbook_XAReset(void);
EXPORT void Redbook_XAInit(void);

#endif
