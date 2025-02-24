#pragma once

#ifndef PS2REDBOOK_H
#define PS2REDBOOK_H

#include "export.h"
#include "vector.h"

EXPORT void Redbook_XAStop(void);
EXPORT u8 Redbook_XAPlay(int, int, int);
EXPORT u8 Redbook_XAPlayPos(int, int, CVector*, int);
EXPORT void Redbook_XAAllow(bool);
EXPORT void Redbook_XAInitAtStart(void);
EXPORT void Redbook_XAReset(void);
EXPORT void Redbook_XAInit(void);
EXPORT void RedBook_MwErrFunc(void *,char *);
EXPORT void Redbook_XAExit(void);
EXPORT void Redbook_XAPause(bool);
EXPORT void Redbook_XASetVol(i32);
EXPORT i32 Redbook_XAStat(void);

#endif
