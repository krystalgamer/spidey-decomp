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
EXPORT int Rnd(int);
EXPORT CBody* Utils_CheckObjectCollision(CVector*, CVector*, CBody*, CBody*);

#endif
