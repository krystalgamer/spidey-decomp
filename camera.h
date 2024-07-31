#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "ps2funcs.h"
#include "ob.h"
#include "vector.h"
#include "quat.h"

static int * const gCameraRelated = (int*)0x56F254;

struct SCamera
{
	u32 Style;
	VECTOR Position;
	VECTOR Focus;
	i32 Distance;
	i32 Height;
	SVECTOR Angles;
	MATRIX Transform;
};

enum ECameraMode {
	ECam_mode_0x10 = 0x10,
	ECam_mode_0x11 = 0x11,
};

enum EShakeType
{
	EShake_0x0 = 0x0,
};

class CCamera : public CBody {
public:
	EXPORT CCamera(CBody*);
	EXPORT virtual ~CCamera(void);

	EXPORT void SetFixedFocusMode(CVector *a2, unsigned __int16 a3, unsigned __int16 a4);
	EXPORT int SetMode(ECameraMode mode);
	EXPORT void SetCollisionRayLR(int a2);
	EXPORT void SetCollisionRayBack(int a2);
	EXPORT void SetCollisionAngLR(__int16 a2);
	EXPORT void SetCollisionAngBack(__int16 a2);
	EXPORT void SetZoom(int a2, unsigned __int16 a3);
	EXPORT int GetZoom(void) const;
	EXPORT void PushMode(void);
	EXPORT void PopMode(void);
	EXPORT void CM_Normal(void);
	EXPORT void SetStartPosition(void);
	EXPORT void SetFixedPosMode(CVector *a2, unsigned __int16 a3);
	EXPORT void CM_FixedPosAngles(void);
	EXPORT void CM_FixedPos(void);
	EXPORT void SetCamYDistance(__int16, unsigned __int16);
	EXPORT void SetCamAngle(__int16, unsigned __int16);
	EXPORT void GetPosition(CVector *);
	EXPORT void Shake(CVector*, EShakeType);
	EXPORT void SetTripodInterpolation(i32, i32, i32);
	EXPORT void SetFixedPosAnglesMode(CVector *, CQuat *, u16);
	EXPORT void LoadIntoMikeCamera(void);
	EXPORT void CM_TripodFocus(void);


	int padTop;

	unsigned char field_F8;
	unsigned char field_F9;
	CBody* field_FC;
	unsigned char field_100;

	CVector field_104;

	int field_110;
	int field_114;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int field_128;
	int field_12C;
	int field_130;
	int field_134;
	int field_138;
	CBody* field_13C;
	unsigned char field_140;
	CVector field_144;

	int field_150;
	int field_154;
	int field_158;
	int field_15C;
	int field_160;
	int field_164;
	int field_168;
	int field_16C;
	int mZoom;

	__int16 field_174;
	unsigned char padAfter174[2];

	int field_178;
	int field_17C;

	unsigned char padAfter17C[0x1A8-0x17C-4];


	int field_1A8;
	int field_1AC;
	int field_1B0;
	int field_1B4;
	int field_1B8;
	int field_1BC;
	int field_1C0;

	int padAfter1C0;


	int field_1C8;
	__int16 field_1CC;
	__int16 field_1CE;

	unsigned char padAfter1CE[0x8];


	int field_1D8;
	int field_1DC;
	int field_1E0;

	CQuat field_1E4;

	CQuat field_1F4;

	CQuat field_204;

	CQuat field_214;

	

	int field_224;
	int field_228;
	int field_22C;
	int field_230;
	i16 field_234;
	i16 field_236;
	i16 field_238;
	i16 field_23A;

	unsigned char field_23C;
	int field_240;
	int field_244;
	int field_248;
	CVector field_24C;

	CVector field_258;

	int field_264;
	int field_268;
	i16 field_26C;
	i16 field_26E;

	i16 field_270;
	i16 field_272;

	__int16 field_274;
	unsigned char field_276;
	unsigned char field_277;
	unsigned char field_278;
	__int16 field_27A;
	__int16 field_27C;
	__int16 field_27E;

	int field_280;

	CVector field_284;

	CQuat field_290;

	int mMode;

	int field_2A4;
	int field_2A8;

	unsigned char field_2AC;


	CVector field_2B0;

	int field_2BC;

	int field_2C0;

	CQuat field_2C4;
	CQuat field_2D4;

	__int16 field_2E4;

	CVector field_2E8;

};

EXPORT __int16 CalcTheta(__int16, __int16);

void validate_CCamera(void);
void validate_SCamera(void);

#endif
