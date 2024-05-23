#pragma once

#ifndef PS2REDBOOK_H
#define PS2REDBOOK_H

#include "export.h"


EXPORT void Redbook_XAStop(void);
EXPORT int Redbook_XAPlay(int, int, int);
EXPORT void Redbook_XAAllow(bool);

#endif
