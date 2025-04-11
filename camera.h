#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "ps2funcs.h"
#include "ob.h"
#include "vector.h"
#include "quat.h"

static int * const gCameraRelated = (int*)0x56F254;

struct SViewport
{
	PADDING(0xC);

	u16 Zoom;
	u16 field_E;
};

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
	EShake_0x1 = 0x1,
};

class CCamera : public CBody {
public:
	EXPORT CCamera(CBody*);
	EXPORT virtual ~CCamera(void);

	EXPORT void SetFixedFocusMode(CVector *, u16, u16);
	EXPORT i32 SetMode(ECameraMode mode);
	EXPORT void SetCollisionRayLR(i32);
	EXPORT void SetCollisionRayBack(i32);
	EXPORT void SetCollisionAngLR(i16);
	EXPORT void SetCollisionAngBack(i16);
	EXPORT void SetZoom(i32, u16);
	EXPORT i32 GetZoom(void) const;
	EXPORT void PushMode(void);
	EXPORT void PopMode(void);
	EXPORT void CM_Normal(void);
	EXPORT void SetStartPosition(void);
	EXPORT void SetFixedPosMode(CVector *a2, u16 a3);
	EXPORT void CM_FixedPosAngles(void);
	EXPORT void CM_FixedPos(void);
	EXPORT void SetCamYDistance(i16, u16);
	EXPORT void SetCamAngle(i16, u16);
	EXPORT void GetPosition(CVector *);
	EXPORT void Shake(CVector*, EShakeType);
	EXPORT void SetTripodInterpolation(i32, i32, i32);
	EXPORT void SetFixedPosAnglesMode(CVector *, CQuat *, u16);
	EXPORT void LoadIntoMikeCamera(void);
	EXPORT void CM_TripodFocus(void);
	EXPORT i16 GetCamXZDistance(void);
	EXPORT void SetCamXZDistance(u16, u16);


	PADDING(4);

	u8 field_F8;
	u8 field_F9;
	CBody* field_FC;
	u8 field_100;

	CVector field_104;

	i32 field_110;
	i32 field_114;
	i32 field_118;
	i32 field_11C;
	i32 field_120;
	i32 field_124;
	i32 field_128;
	i32 field_12C;
	i32 field_130;
	i32 field_134;
	i32 field_138;
	CBody* field_13C;
	u8 field_140;
	CVector field_144;

	i32 field_150;
	i32 field_154;
	i32 field_158;
	i32 field_15C;
	i32 field_160;
	i32 field_164;
	i32 field_168;
	i32 field_16C;
	i32 mZoom;

	i16 field_174;
	PADDING(2);

	i32 field_178;
	i32 field_17C;

	PADDING(0x1A8-0x17C-4);


	i32 field_1A8;
	i32 field_1AC;
	i32 field_1B0;
	i32 field_1B4;
	i32 field_1B8;
	i32 field_1BC;
	i32 field_1C0;

	PADDING(4);


	i32 field_1C8;
	i16 field_1CC;
	i16 field_1CE;

	PADDING(0x8);


	i32 field_1D8;
	i32 field_1DC;
	i32 field_1E0;

	CQuat field_1E4;

	CQuat field_1F4;

	CQuat field_204;

	CQuat field_214;

	

	i32 field_224;
	i32 field_228;
	i32 field_22C;
	i32 field_230;
	i16 field_234;
	i16 field_236;
	i16 field_238;
	i16 field_23A;

	u8 field_23C;
	i32 field_240;
	i32 field_244;
	i32 field_248;
	CVector field_24C;

	CVector field_258;

	i32 field_264;
	i32 field_268;
	i16 field_26C;
	i16 field_26E;

	i16 field_270;
	i16 field_272;

	i16 field_274;
	u8 field_276;
	u8 field_277;
	u8 field_278;
	i16 field_27A;
	i16 field_27C;
	i16 field_27E;

	i32 field_280;

	CVector field_284;

	CQuat field_290;

	i32 mMode;

	i32 field_2A4;
	i32 field_2A8;

	u8 field_2AC;


	CVector field_2B0;

	i32 field_2BC;

	i32 field_2C0;

	CQuat field_2C4;
	CQuat field_2D4;

	i16 field_2E4;

	CVector field_2E8;

};

EXPORT i16 CalcTheta(i16, i16);
EXPORT extern CCamera *CameraList;
EXPORT extern SViewport gViewport;
EXPORT extern SCamera gMikeCamera[2];

void validate_CCamera(void);
void validate_SCamera(void);
void validate_SViewport(void);

#endif
