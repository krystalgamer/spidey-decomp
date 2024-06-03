#pragma once

#ifndef UTILS_H
#define UTILS_H

#include "export.h"
#include "vector.h"
#include "ob.h"


EXPORT int Utils_CrapDist(const CVector& a,const CVector& b);
EXPORT int Utils_CrapXZDist(const CVector& a,const CVector& b);
EXPORT int Utils_CompareStrings(const char* left, const char* right);
EXPORT int Utils_ArcCos(int val);
EXPORT int Utils_CopyString(const char*, char*, int);
EXPORT CBody* Utils_CheckObjectCollision(CVector*, CVector*, CBody*, CBody*);
EXPORT int Utils_GetGroundHeight(CVector*, int, int, CBody**);
EXPORT int Utils_LineOfSight(CVector*, CVector*, CVector*, int);
EXPORT int Utils_CalcAim(CSVector*, CVector*, CVector*);
EXPORT int Utils_GetValueFromDifficultyLevel(int, int, int, int);

EXPORT int Rnd(int);
EXPORT void Utils_InitialRand(int);
EXPORT int catan(int);

EXPORT unsigned int Utils_GenerateCRC(const char*);

EXPORT int Utils_LinearFilter(int, int, int);
EXPORT void Utils_GetVecFromMagDir(CVector*, int, CSVector*);

EXPORT int Utils_XZDist(const CVector*, const CVector *);

#endif
