#pragma once

#ifndef M3DCOLIJ_H
#define M3DCOLIJ_H


#include "export.h"
#include "vector.h"
#include "ps2funcs.h"

class CBody;

// @Note: meant for SLineInfo
// but you know, it's the same as CVector, and would add just confusion
struct Vector
{
	i32 vx;
	i32 vy;
	i32 vz;
};

struct SLineInfo
{
	CVector StartCoords;
	CVector EndCoords;

	CVector MinCoords;
	CVector MaxCoords;

	// offset: 0030
	i32 iLo;
	// offset: 0034
	i32 iHi;
	// offset: 0038
	i32 jLo;
	// offset: 003C
	i32 jHi;

	i32 Distance;
	i32 Length;

	MATRIX WorldCst;
	CItem* pItem;

	CVector Position; // should be Vector?
	CSVector Normal; // should be SVector?

	u32 *pFace;
	i32 Model;

	u8 RecordTriggerZoneHits;
	u8 DropDown;

	u16 Inquiry;
	i32 tNear;

	// offset: 0090
	u32 tNumtrLo;
	// offset: 0094
	i32 tNumtrHi;
	// offset: 0098
	u32 tDenomLo;
	// offset: 009C
	i32 tDenomHi;
	// offset: 00A0
	u32 NormalOffset;
};


void validate_SLineInfo(void);
void validate_Vector(void);

EXPORT void M3dColij_InitLineInfo(SLineInfo *);
EXPORT i32 M3dColij_LineToSphere(CVector*, CVector*, CVector*, CBody*, CBody*, i32);

EXPORT void M3dColij_LineToItem(CItem*, SLineInfo*);
EXPORT void M3dColij_LineToThisItem(CItem*, SLineInfo*);
EXPORT void M3dColij_GetLineInfo(SLineInfo *);
EXPORT void M3dColij_LineInfoFixup(SLineInfo *);
EXPORT void M3dColij_LineToItemZoned(CItem **,SLineInfo *);
EXPORT void NextInquiry(void);

EXPORT extern i32 LineOfSightCheck;
EXPORT extern u32 M3dColij_OneMask;
EXPORT extern u32 M3dColij_ZeroMask;

EXPORT extern i32 BaddyCollisionCheck;
EXPORT extern i32 CameraCollisionCheck;
EXPORT extern i32 TriggerCollisionCheck;
EXPORT extern SLineInfo gLineInfo;
EXPORT extern i16 gUnkPose[1];

#endif
