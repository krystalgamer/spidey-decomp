#include "web.h"
#include "m3dinit.h"
#include "m3dcolij.h"
#include "m3dzone.h"
#include "spidey.h"
#include "baddy.h"
#include "utils.h"
#include "camera.h"
#include "spool.h"

#include "validate.h"

i32 gFireDomes;
i32 gNumDomes;
CBody* WebList;

EXPORT SLineInfo gLineInfo;
EXPORT i32 gGetGroundDefaultValue;

extern CBody* MiscList;

// @MEDIUMTODO
i32 Web_CollideWithSuper(CSuper *,CVector const *,CVector const *,SHook *,i32)
{
    printf("Web_CollideWithSuper(CSuper *,CVector const *,CVector const *,SHook *,i32)");
	return 0x23022025;
}

// @Ok
CDomeShockWave::CDomeShockWave(i32 a2)
{
	this->mType = 8;
	this->mPos = MechList->mPos;
	this->mPos.vy += 204800;

	this->field_44.vx = 240;
	this->field_44.vy = 240;
	this->field_44.vz = 240;

	this->field_90 = a2;

	this->ResetHitFlags(BaddyList);
	this->ResetHitFlags(EnvironmentalObjectList);

	for (i32 i = 0; i < 16; i++)
	{
		this->field_50[i] = Rnd(4096);
	}

	CameraList->Shake(&this->mPos, EShake_0x1);
}

// @Ok
CDomeShockWave::~CDomeShockWave(void)
{
}

// @Ok
CDomePiece::CDomePiece(
		CVector* a2,
		i32 a3,
		i32 a4,
		i32 a5)
{
	this->mPos = *a2;
	this->field_F8 = a4;

	if (a5)
		this->InitItem("firedome");
	else
		this->InitItem("webdome3");

	print_if_false(a3 < reinterpret_cast<u32*>(PSXRegion[this->mRegion].ppModels)[-1], "Bad Model sent to CDomePiece");

	this->mModel = a3;
	this->AttachTo(&MiscList);
	this->mFlags |= 0x400;
	this->field_24 = 0;
	this->field_FC = 4;
}

// @Ok
CDomePiece::~CDomePiece(void)
{
	this->DeleteFrom(&MiscList);
}

// @Ok
CDome::CDome(
		CPlayer* pSpidey,
		i32 a3)
{
	print_if_false(pSpidey != 0, "NULL pSpidey");
	this->hPlayer = Mem_MakeHandle(pSpidey);

	this->mPos = pSpidey->mPos;

	this->mPos.vy += pSpidey->field_EA8 << 12;
	this->field_104 = a3;

	if ( a3 )
	{
		this->InitItem("firedome");
		this->mModel = 1;
		gFireDomes++;
		this->mFlags |= 0x200;
		this->field_2A = 0;
	}
	else
	{
		this->InitItem("webdome2");
	}

	this->mFlags |= 1;
	this->AttachTo(&MiscList);
	this->field_100 = 0;
	++gNumDomes;
}

// @NotOk
// @FIXME types
CDome::~CDome(void)
{
	this->DeleteFrom(&MiscList);

	delete reinterpret_cast<CClass*>(this->field_108);
	delete reinterpret_cast<CClass*>(this->field_10C);
	delete reinterpret_cast<CClass*>(this->field_110);
	delete reinterpret_cast<CClass*>(this->field_114);
	delete reinterpret_cast<CClass*>(this->field_118);

	if (this->field_104)
		gFireDomes--;
	gNumDomes--;
}

// @Ok
// @AlmostMatching: vector assignment is different, this one doesn't use esi either
int Web_GetGroundY(const CVector* a1)
{

	gLineInfo.StartCoords = *a1;

	gLineInfo.EndCoords.vx = a1->vx;
	gLineInfo.EndCoords.vy = a1->vy + 0x1388000;
	gLineInfo.EndCoords.vz = a1->vz;

	M3dColij_InitLineInfo(&gLineInfo);
	M3dZone_LineToItem(&gLineInfo, 1);

	if (!gLineInfo.pItem)
		return gLineInfo.EndCoords.vy;

	return gLineInfo.Position.vy;
}

// @BIGTODO
void CTrapWebEffect::Burst(void)
{
	printf("void CTrapWebEffect::Burst(void)");
}

// @Ok
int CSwinger::IsOneTimeToDie(void)
{
	return this->field_180 >= 4096;
}

// @Ok
// @Matching
void CSwinger::SetSpideyAnimFrame(i32 a2)
{
	MechList->field_128 = (a2 * (this->field_180 - 2048)) >> 11;
}


// @Ok
INLINE void CDomeShockWave::ResetHitFlags(CBody* body)
{
	for(CBody *cur = body; cur; cur = reinterpret_cast<CBody*>(cur->field_20))
		cur->mCBodyFlags &= 0xFEFF;
}

void validate_CImpactWeb(void){
	VALIDATE_SIZE(CImpactWeb, 0x8C);
}

void validate_CDomePiece(void){
	VALIDATE_SIZE(CDomePiece, 0x100);

	VALIDATE(CDomePiece, field_F4, 0xF4);
	VALIDATE(CDomePiece, field_F8, 0xF8);
	VALIDATE(CDomePiece, field_FC, 0xFC);
}

void validate_CDome(void){
	VALIDATE_SIZE(CDome, 0x11C);

	VALIDATE(CDome, hPlayer, 0xF8);
	VALIDATE(CDome, field_100, 0x100);

	VALIDATE(CDome, field_104, 0x104);
	VALIDATE(CDome, field_108, 0x108);
	VALIDATE(CDome, field_10C, 0x10C);
	VALIDATE(CDome, field_110, 0x110);
	VALIDATE(CDome, field_114, 0x114);
	VALIDATE(CDome, field_118, 0x118);
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

	VALIDATE(CTrapWebEffect, field_3C, 0x3C);
	VALIDATE(CTrapWebEffect, field_44, 0x44);
	VALIDATE(CTrapWebEffect, field_418, 0x418);
}

void validate_CDomeShockWave(void)
{
	VALIDATE_SIZE(CDomeShockWave, 0x98);

	VALIDATE(CDomeShockWave, field_44, 0x44);
	VALIDATE(CDomeShockWave, field_50, 0x50);
	VALIDATE(CDomeShockWave, field_90, 0x90);
}
