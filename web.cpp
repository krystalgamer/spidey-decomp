#include "web.h"
#include "validate.h"
#include "m3dinit.h"
#include "m3dcolij.h"
#include "m3dzone.h"


SLineInfo gLineInfo;
int gGetGroundRelated;
int gGetGroundDefaultValue;


// @NotOk
// Order assignemnt slightly different and make sure globals are properly set
int Web_GetGroundY(const CVector* a1)
{

	gLineInfo.vec_0.vy = a1->vy;
	gLineInfo.vec_0.vx = a1->vx;
	gLineInfo.vec_0.vz = a1->vz;

	gLineInfo.vec_C.vx = a1->vx;
	gLineInfo.vec_C.vy = a1->vy + 0x1388000;
	gLineInfo.vec_C.vz = a1->vz;

	M3dColij_InitLineInfo(&gLineInfo);
	M3dZone_LineToItem(&gLineInfo, 1);

	if (gGetGroundRelated)
		return gGetGroundDefaultValue;

	return gLineInfo.vec_C.vy;
}

// @TODO
void CTrapWebEffect::Burst(void)
{
}

// @Ok
int CSwinger::IsOneTimeToDie(void)
{
	return this->field_180 >= 4096;
}

// @NotOk
// globals
void CSwinger::SetSpideyAnimFrame(int a2)
{
	globalSuper->field_128 = (a2 * (this->field_180 - 2048)) >> 11;
}


// @Ok
void __inline CDomeShockWave::ResetHitFlags(CBody* body)
{
	for(CBody *cur = body; cur; cur = reinterpret_cast<CBody*>(cur->field_20))
		cur->mCBodyFlags &= 0xFEFF;
}

void validate_CImpactWeb(void){
	VALIDATE_SIZE(CImpactWeb, 0x8C);
}

void validate_CDomePiece(void){
	VALIDATE_SIZE(CDomePiece, 0x100);

	VALIDATE(CDomePiece, field_F8, 0xF8);
	VALIDATE(CDomePiece, field_FC, 0xFC);
}
void validate_CDome(void){
	VALIDATE_SIZE(CDome, 0x11C);
}

void validate_CDomeRing(void){
	VALIDATE_SIZE(CDomeRing, 0x110);

	VALIDATE(CDomeRing, field_F8, 0xF8);
	VALIDATE(CDomeRing, field_FC, 0xFC);
	VALIDATE(CDomeRing, field_100, 0x100);
	VALIDATE(CDomeRing, field_104, 0x104);
	VALIDATE(CDomeRing, field_108, 0x108);
}

void validate_CWeb(void){
	VALIDATE_SIZE(CWeb, 0x13C);


	VALIDATE(CWeb, field_F8, 0xF8);

	VALIDATE(CWeb, field_100, 0x100);
	VALIDATE(CWeb, field_104, 0x104);

	VALIDATE(CWeb, field_108, 0x108);
	VALIDATE(CWeb, field_114, 0x114);

	VALIDATE(CWeb, field_120, 0x120);
	VALIDATE(CWeb, field_124, 0x124);
	VALIDATE(CWeb, field_128, 0x128);

	VALIDATE(CWeb, field_12C, 0x12C);

	VALIDATE(CWeb, field_130, 0x130);


	VALIDATE(CWeb, field_134, 0x134);
	VALIDATE(CWeb, field_138, 0x138);
}

void validate_CSwinger(void){
	VALIDATE_SIZE(CSwinger, 0x190);

	VALIDATE(CSwinger, field_180, 0x180);
}

void validate_CTrapWebEffect(void)
{
	VALIDATE_SIZE(CTrapWebEffect, 0x430);

	VALIDATE(CTrapWebEffect, bitBottomPad, 0x3B);
	VALIDATE(CTrapWebEffect, field_3C, 0x3C);
	VALIDATE(CTrapWebEffect, field_44, 0x44);
	VALIDATE(CTrapWebEffect, field_418, 0x418);
}

void validate_CDomeShockWave(void)
{
	VALIDATE_SIZE(CDomeShockWave, 0x98);
}
