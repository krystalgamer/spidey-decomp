#pragma once

#ifndef UTILS_H
#define UTILS_H

#include "export.h"
#include "vector.h"
#include "ob.h"

EXPORT extern volatile i32 gVlanksRelated;
EXPORT extern i32 DifficultyLevel;
EXPORT extern volatile u32 Vblanks;

EXPORT u32 Utils_CrapDist(const CVector& a,const CVector& b);
EXPORT u32 Utils_CrapXZDist(const CVector& a,const CVector& b);
EXPORT i32 Utils_CompareStrings(const char* left, const char* right);
EXPORT i32 Utils_ArcCos(i32 val);
EXPORT i32 Utils_CopyString(const char*, char*, i32);
EXPORT CBody* Utils_CheckObjectCollision(CVector*, CVector*, CBody*, CBody*);
EXPORT i32 Utils_GetGroundHeight(CVector*, i32, i32, CBody**);
EXPORT i32 Utils_LineOfSight(CVector*, CVector*, CVector*, i32);
EXPORT i32 Utils_CalcAim(CSVector*, CVector*, CVector*);
EXPORT i32 Utils_GetValueFromDifficultyLevel(i32, i32, i32, i32);
EXPORT void Utils_RotateY(CVector*, CVector*, i32);
EXPORT void Utils_TurnTowards(CSVector, CSVector*, CSVector*, CSVector, i32);

EXPORT i32 Rnd(i32);
EXPORT void Utils_InitialRand(i32);
EXPORT i32 catan(i32);

EXPORT u32 Utils_GenerateCRC(const char*);

EXPORT i32 Utils_LinearFilter(i32, i32, i32);
EXPORT void Utils_GetVecFromMagDir(CVector*, i32, CSVector*);

EXPORT i32 Utils_XZDist(const CVector*, const CVector *);

EXPORT void MyVSync(void);
EXPORT void Pause(i32);
EXPORT void Utils_CalcPerps(CVector *,CVector *,CVector *);
EXPORT void Utils_CalcUnitFacingCamera(CVector const *,CVector const *,CVector *);
EXPORT void Utils_CalcWallPerps(CVector * a1,CVector * a2,CVector * a3);
EXPORT u32 Utils_CalculateSpatialAttenuation(const CVector *,i32,i32);
EXPORT i32 Utils_CanSee(CItem *,CItem *,i32,i32,i32);
EXPORT u32 Utils_Dist(CVector const *,CVector const *);
EXPORT void Utils_InitLoadIcons(void);
EXPORT void Utils_Jumble(i32 *,i32);
EXPORT i32 Utils_KillEverythingInBox(CVector const *,CVector const *);
EXPORT i32 Utils_KillObjectsInBox(CVector const *,CVector const *,CBody *,bool);
EXPORT void Utils_RotateWorldToObject(CBody *,CVector *,CVector *);
EXPORT void Utils_SetBaddyVisibilityInBox(CVector const *,CVector const *,bool,bool,CBody *);
EXPORT void Utils_SetVisibilityByName(char const *,i32,i32,bool);
EXPORT void Utils_SetVisibilityInBox(CVector const *,CVector const *,bool,bool);
EXPORT i32 Utils_ShiftFilter(i32,i32,i32,i32);
EXPORT void Utils_VblankProcessing(void);

#endif
