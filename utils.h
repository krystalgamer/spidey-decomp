#pragma once

#ifndef UTILS_H
#define UTILS_H

#include "export.h"
#include "vector.h"
#include "ob.h"


EXPORT u32 Utils_CrapDist(const CVector& a,const CVector& b);
EXPORT u32 Utils_CrapXZDist(const CVector& a,const CVector& b);
EXPORT int Utils_CompareStrings(const char* left, const char* right);
EXPORT int Utils_ArcCos(int val);
EXPORT int Utils_CopyString(const char*, char*, int);
EXPORT CBody* Utils_CheckObjectCollision(CVector*, CVector*, CBody*, CBody*);
EXPORT int Utils_GetGroundHeight(CVector*, int, int, CBody**);
EXPORT int Utils_LineOfSight(CVector*, CVector*, CVector*, int);
EXPORT int Utils_CalcAim(CSVector*, CVector*, CVector*);
EXPORT int Utils_GetValueFromDifficultyLevel(int, int, int, int);
EXPORT void Utils_RotateY(CVector*, CVector*, int);
EXPORT void Utils_TurnTowards(CSVector, CSVector*, CSVector*, CSVector, i32);

EXPORT int Rnd(int);
EXPORT void Utils_InitialRand(int);
EXPORT int catan(int);

EXPORT unsigned int Utils_GenerateCRC(const char*);

EXPORT int Utils_LinearFilter(int, int, int);
EXPORT void Utils_GetVecFromMagDir(CVector*, int, CSVector*);

EXPORT int Utils_XZDist(const CVector*, const CVector *);

EXPORT void MyVSync(void);
EXPORT void Pause(i32);
EXPORT void Utils_CalcPerps(CVector *,CVector *,CVector *);
EXPORT void Utils_CalcUnitFacingCamera(CVector const *,CVector const *,CVector *);
EXPORT void Utils_CalcWallPerps(CVector * a1,CVector * a2,CVector * a3);
EXPORT void Utils_CalculateSpatialAttenuation(CVector const *,i32,i32);
EXPORT void Utils_CanSee(CItem *,CItem *,i32,i32,i32);
EXPORT void Utils_Dist(CVector const *,CVector const *);
EXPORT void Utils_InitLoadIcons(void);
EXPORT void Utils_Jumble(i32 *,i32);
EXPORT void Utils_KillEverythingInBox(CVector const *,CVector const *);
EXPORT void Utils_KillObjectsInBox(CVector const *,CVector const *,CBody *,bool);
EXPORT void Utils_RotateWorldToObject(CBody *,CVector *,CVector *);
EXPORT void Utils_SetBaddyVisibilityInBox(CVector const *,CVector const *,bool,bool,CBody *);
EXPORT void Utils_SetVisibilityByName(char const *,i32,i32,bool);
EXPORT void Utils_SetVisibilityInBox(CVector const *,CVector const *,bool,bool);
EXPORT void Utils_ShiftFilter(i32,i32,i32,i32);
EXPORT void Utils_VblankProcessing(void);

#endif
