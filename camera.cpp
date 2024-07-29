#include "camera.h"
#include "validate.h"
#include "ps2funcs.h"

EXPORT CCamera *CameraList;
EXPORT i32 NumCameras;

// @Ok
// @Test
void CCamera::SetFixedPosAnglesMode(
		CVector *a2,
		CQuat *a3,
		u16 a4)
{
	this->mMode = 5;
	this->field_24C = *a2;
	this->field_2D4 = *a3;
	this->field_2AC = 1;
	this->field_2BC = a4;

	if (a4)
	{
		this->field_2C0 = a4;
		this->field_2C4 = this->field_1E4;

		this->field_2B0 = (*a2 - this->mPos) / a4;
	}
}

// @Ok
void CCamera::SetTripodInterpolationMode(i32 a2, i32 a3, i32 a4)
{
	print_if_false(a2 <= 16, "Bad tripod interpolation value");
	print_if_false(a3 <= 16, "Bad tripod interpolation value");
	print_if_false(a4 <= 16, "Bad tripod interpolation value");
	this->field_130 = a2;
	this->field_134 = a3;
	this->field_138 = a4;
}

// @Ok
CCamera::~CCamera(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&CameraList));
	--NumCameras;
}

// @NotOk
// Not matching, not important
void CCamera::SetFixedFocusMode(CVector *a2, unsigned __int16 a3, unsigned __int16 a4){

	this->mMode = 6;
	this->field_2AC = 1;
	this->field_2E8 = *a2;
	this->field_2E4 = (0xFFFF & a3) / 3;
	this->field_2BC = a4;
}

// @Ok
i32 CCamera::SetMode(ECameraMode mode){

	i32 oldMode = this->mMode;
	this->mMode = mode;
	if (mode == ECam_mode_0x10 || mode == ECam_mode_0x11){
		*gCameraRelated = 0;
	}

	return oldMode;
}

// @Ok
void CCamera::SetCollisionRayLR(int a2){
	this->field_264 = a2;
}

// @Ok
void CCamera::SetCollisionRayBack(int a2){
	this->field_268 = a2;
}

// @Ok
void CCamera::SetCollisionAngLR(__int16 a2){
	this->field_26C = a2;
}

void CCamera::SetCollisionAngBack(__int16 a2){
	this->field_26E = a2;
}

// @Ok
void CCamera::SetZoom(int a2, unsigned __int16 a3){

	this->field_174 = a3;
	if (this->field_174)
	{
		this->field_178 = (a2 - this->mZoom) / (0xFFFF & a3);
		this->field_17C = a2;
	}
	else
	{
		this->mZoom = a2;
	}
}

// @Ok
int CCamera::GetZoom(void) const{
	return this->mZoom;
}


// @Ok
void CCamera::PushMode(void){

	int mode = this->mMode;
	this->field_280 = mode;

	if (mode == 4 || mode == 5 || mode == 6){
		this->field_284 = this->mPos;
		this->field_290 = this->field_1E4;
	}
}

// @Ok
void CCamera::PopMode(void){

	int mode = this->field_280;
	if (mode == 4 || mode == 5 || mode == 6){
		this->mPos = this->field_284;
		this->field_1E4 = this->field_290;
	}

	this->mMode = mode;
}


//TODO
void CCamera::CM_Normal(void){
	/* DO ME */
}


// @Ok
void CCamera::SetStartPosition(void){

	if ( this->mMode == 3 )
	{
		this->field_104 = this->field_FC->mPos;
		this->CM_Normal();
		this->mPos = this->field_24C;
		this->field_1E4 = this->field_1F4;
	}

}

// @NotOk
// Revisit
void CCamera::SetFixedPosMode(CVector *a2, u16 a3){

	this->mMode = 4;
	this->field_24C = *a2;
	this->field_2AC = 1;
	this->field_2BC = a3;

	if (a3)
	{
		this->field_2B0 = (*a2 - this->mPos)/a3;
	}
}


// @NotOk
// Revisit
// Not matching but the same, compiler generates codeblock for else statement twice for some reason
void CCamera::CM_FixedPosAngles(void){


	int v2; // r30
	int v3; // r30

	v2 = this->field_2BC;

	if ( v2 && v2 - this->field_80 > 0)
	{
		this->mPos += this->field_2B0 * this->field_80;
	}
	else
	{
		this->mPos = this->field_24C;
	}


	v3 = this->field_2BC;

	if ( v3 && v3 - this->field_80 > 0 )
	{
		Quat_Slerp(
			this->field_2C4,
			this->field_2D4,
			((this->field_2C0 - v3) << 12) / this->field_2C0,
			this->field_1F4);
	}

	else
	{
		this->field_1F4 = this->field_2D4;
	}

	this->field_2BC = v3;

	if ( this->field_2AC )
	{
		this->field_2AC = 0;
		if ( !this->field_2BC )
		{
			this->field_1E4 = this->field_1F4;
			this->field_204 = this->field_1E4;
		}
	}

}

static CVector * const stru_56F260 = (CVector*)0x56F260;

// @NotOk
// Revisit, needs validation
void CCamera::CM_FixedPos(void){

	int v2; // eax
	CVector v6; // eax
	int v10; // eax
	VECTOR v15; // [esp+1Ch] [ebp-50h] BYREF
	VECTOR a1; // [esp+2Ch] [ebp-40h] BYREF
	VECTOR v17; // [esp+3Ch] [ebp-30h] BYREF
	MATRIX v18; // [esp+4Ch] [ebp-20h] BYREF

	v2 = this->field_2BC;
	if ( v2 )
	{
		this->field_2BC = v2 - this->field_80;
		if ( this->field_2BC > 0 )
		{
			this->mPos += this->field_2B0 * this->field_80;
		}
		else
		{
			this->field_2BC = 0;
			this->mPos = this->field_24C;
		}
	}
	else
	{
		this->mPos = this->field_24C;
	}


	this->field_258 = this->field_144;

	v6 = this->mPos * *stru_56F260;

	v15.vx = (this->field_258.vx - v6.vx) >> 12;
	v15.vy = (this->field_258.vy - v6.vy) >> 12;
	v15.vz = (this->field_258.vz - v6.vz) >> 12;

	VectorNormal(&v15, &v15);
	a1.vx = 0;
	a1.vy = 4096;
	a1.vz = 0;
	gte_ldopv1(&a1);
	gte_ldopv2(&v15);
	gte_op12();
	gte_stlvnl(&v17);
	gte_ldopv1(&v15);
	gte_ldopv2(&v17);
	gte_op12();
	gte_stlvnl(&a1);

	v18.m[0][0] = v17.vx;
	v18.m[0][1] = v17.vy;
	v18.m[0][2] = v17.vz;

	v18.m[1][0] = a1.vx;
	v18.m[1][1] = a1.vy;
	v18.m[1][2] = a1.vz;

	v18.m[2][0] = v15.vx;
	v18.m[2][1] = v15.vy;
	v18.m[2][2] = v15.vz;


	MToQ(v18, this->field_1F4);
	if ( this->field_2AC )
	{
		v10 = this->field_2BC;
		this->field_2AC = 0;
		if ( !v10 )
		{
			this->field_1E4 = this->field_1F4;
			this->field_204 = this->field_1F4;
		}
	}

}

// @BIGTODO
void CCamera::SetCamYDistance(__int16, unsigned __int16)
{}

// @BIGTODO
void CCamera::SetCamAngle(__int16, unsigned __int16)
{}

// @NotOk
// Revisit when used (return type seems wrong)
INLINE i16 CalcTheta(i16 a1, i16 a2)
{
	__int16 v2 = (a2 & 0xFFF) - (a1 & 0xFFF);
	if (v2 > 2048)
		return v2 - 4096;
	if (v2 < -2048)
		return v2 + 4096;
	return v2;
}


// @Ok
void CCamera::GetPosition(CVector * dst)
{
	CVector *src = &this->mPos;
	*dst = *src;
}


// @MEDIUMTODO
void CCamera::Shake(CVector*, EShakeType)
{
	printf("void CCamera::Shake(CVector*, EShakeType)");
}

void validate_CCamera(void){
	VALIDATE_SIZE(CCamera, 0x2F4);


	VALIDATE(CCamera, field_F8, 0xF8);
	VALIDATE(CCamera, field_F9, 0xF9);
	VALIDATE(CCamera, field_FC, 0xFC);
	VALIDATE(CCamera, field_100, 0x100);
	VALIDATE(CCamera, field_104, 0x104);

	VALIDATE(CCamera, field_110, 0x110);
	VALIDATE(CCamera, field_114, 0x114);
	VALIDATE(CCamera, field_118, 0x118);
	VALIDATE(CCamera, field_11C, 0x11C);
	VALIDATE(CCamera, field_120, 0x120);
	VALIDATE(CCamera, field_124, 0x124);
	VALIDATE(CCamera, field_128, 0x128);
	VALIDATE(CCamera, field_12C, 0x12C);
	VALIDATE(CCamera, field_130, 0x130);
	VALIDATE(CCamera, field_134, 0x134);
	VALIDATE(CCamera, field_138, 0x138);
	VALIDATE(CCamera, field_13C, 0x13C);
	VALIDATE(CCamera, field_140, 0x140);

	VALIDATE(CCamera, field_144, 0x144);

	VALIDATE(CCamera, field_150, 0x150);
	VALIDATE(CCamera, field_154, 0x154);
	VALIDATE(CCamera, field_158, 0x158);
	VALIDATE(CCamera, field_15C, 0x15C);
	VALIDATE(CCamera, field_160, 0x160);
	VALIDATE(CCamera, field_164, 0x164);
	VALIDATE(CCamera, field_168, 0x168);
	VALIDATE(CCamera, field_16C, 0x16C);
	VALIDATE(CCamera, mZoom, 0x170);

	VALIDATE(CCamera, field_174, 0x174);
	VALIDATE(CCamera, field_178, 0x178);
	VALIDATE(CCamera, field_17C, 0x17C);


	VALIDATE(CCamera, field_1A8, 0x1A8);
	VALIDATE(CCamera, field_1AC, 0x1AC);
	VALIDATE(CCamera, field_1B0, 0x1B0);
	VALIDATE(CCamera, field_1B4, 0x1B4);
	VALIDATE(CCamera, field_1B8, 0x1B8);
	VALIDATE(CCamera, field_1BC, 0x1BC);
	VALIDATE(CCamera, field_1C0, 0x1C0);
	VALIDATE(CCamera, field_1C8, 0x1C8);
	VALIDATE(CCamera, field_1CC, 0x1CC);
	VALIDATE(CCamera, field_1CE, 0x1CE);
	VALIDATE(CCamera, field_1D8, 0x1D8);
	VALIDATE(CCamera, field_1DC, 0x1DC);
	VALIDATE(CCamera, field_1E0, 0x1E0);

	VALIDATE(CCamera, field_1E4, 0x1E4);

	VALIDATE(CCamera, field_1F4, 0x1F4);

	VALIDATE(CCamera, field_204, 0x204);

	VALIDATE(CCamera, field_214, 0x214);
	VALIDATE(CCamera, field_218, 0x218);
	VALIDATE(CCamera, field_21C, 0x21C);
	VALIDATE(CCamera, field_220, 0x220);
	VALIDATE(CCamera, field_224, 0x224);
	VALIDATE(CCamera, field_228, 0x228);
	VALIDATE(CCamera, field_22C, 0x22C);
	VALIDATE(CCamera, field_230, 0x230);
	VALIDATE(CCamera, field_234, 0x234);
	VALIDATE(CCamera, field_238, 0x238);
	VALIDATE(CCamera, field_23C, 0x23C);
	VALIDATE(CCamera, field_240, 0x240);
	VALIDATE(CCamera, field_244, 0x244);
	VALIDATE(CCamera, field_248, 0x248);
	VALIDATE(CCamera, field_24C, 0x24C);

	VALIDATE(CCamera, field_258, 0x258);

	VALIDATE(CCamera, field_264, 0x264);
	VALIDATE(CCamera, field_268, 0x268);
	VALIDATE(CCamera, field_26C, 0x26C);
	VALIDATE(CCamera, field_26E, 0x26E);
	VALIDATE(CCamera, field_274, 0x274);
	VALIDATE(CCamera, field_276, 0x276);
	VALIDATE(CCamera, field_277, 0x277);
	VALIDATE(CCamera, field_278, 0x278);
	VALIDATE(CCamera, field_27A, 0x27A);
	VALIDATE(CCamera, field_27C, 0x27C);
	VALIDATE(CCamera, field_27E, 0x27E);

	VALIDATE(CCamera, field_280, 0x280);
	VALIDATE(CCamera, field_284, 0x284);

	VALIDATE(CCamera, field_290, 0x290);

	VALIDATE(CCamera, mMode, 0x2A0);
	VALIDATE(CCamera, field_2A4, 0x2A4);

	VALIDATE(CCamera, field_2A8, 0x2A8);
	VALIDATE(CCamera, field_2AC, 0x2AC);

	VALIDATE(CCamera, field_2B0, 0x2B0);

	VALIDATE(CCamera, field_2BC, 0x2BC);
	VALIDATE(CCamera, field_2C0, 0x2C0);


	VALIDATE(CCamera, field_2C4, 0x2C4);

	VALIDATE(CCamera, field_2D4, 0x2D4);

	VALIDATE(CCamera, field_2E4, 0x2E4);

	VALIDATE(CCamera, field_2E8, 0x2E8);

}
