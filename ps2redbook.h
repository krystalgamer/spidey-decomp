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
EXPORT void Redbook_XAPause(bool);

EXPORT extern u8 gCarnageXaRelated;
EXPORT extern u32 gCarnageXaRelatedTwo;
EXPORT extern i32 gRedbookXaRelatedOne;
EXPORT extern i32 gRedbookXaRelatedTwo;

// set once the device reports it stopped
//#define G_CARNAGE_XA_RELATED (gCarnageXaRelated)
#define G_CARNAGE_XA_RELATED (*reinterpret_cast<u8*>(0x00550D81))
// vblank delay before the pending XA play starts
//#define G_CARNAGE_XA_RELATED_TWO (gCarnageXaRelatedTwo)
#define G_CARNAGE_XA_RELATED_TWO (*reinterpret_cast<u32*>(0x0068276C))
// track and offset of the XA that plays now
//#define G_REDBOOK_XA_RELATED_ONE (gRedbookXaRelatedOne)
#define G_REDBOOK_XA_RELATED_ONE (*reinterpret_cast<i32*>(0x00681D1C))
//#define G_REDBOOK_XA_RELATED_TWO (gRedbookXaRelatedTwo)
#define G_REDBOOK_XA_RELATED_TWO (*reinterpret_cast<i32*>(0x006612C0))

#endif
