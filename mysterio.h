#pragma once

#ifndef MYSTERIO_H
#define MYSTERIO_H

#include "export.h"
#include "baddy.h"
#include "camera.h"

#include "reloc.h"


class CMystFoot : public CBaddy {};

class CSoftSpot : public CBaddy 
{
	public:
		i32 field_324;
		i32 field_328;
		i32 field_32c;
		i32 field_330;
		i32 field_334;
};

class CMysterio : public CBaddy {
	public:

	EXPORT CMysterio(i32*, i32);
	EXPORT CMysterio(void);
	EXPORT ~CMysterio(void);
	EXPORT u8 MystRedbook_XAPlayPos(i32, i32, CVector*, i32);
	EXPORT i32 CMysterio::PlayAndAttachXAPlease(i32, i32, CBody*, i32);
	EXPORT void ShakePad(void);
	EXPORT i32 CheckforCameraShake(i32);
	EXPORT void EnterP2(void);
	EXPORT i32 GetAttackRotSpeed(void);
	EXPORT void SummonAttack(void);
	EXPORT void LookMenacing(void);
	EXPORT void RotateToOptimalAttackAngle(i32, i32);
	EXPORT i32 MonitorAttack(i32, VECTOR*, i32);

	CItem* field_324;
	PADDING(4);

	i32 field_32C;
	PADDING(0x34C-0x32c-4);

	i32 field_34C;
	i32 field_350;
	PADDING(4);

	i32 field_358;
	PADDING(4);


	SHandle field_360;
	SHandle field_368;
	PADDING(4);

	i32 field_374;
	i32 field_378;

	CVector field_37C;

	i32 field_388;

	i32 field_38C;

	PADDING(8);

	i32 field_398;
	i32 field_39C;
	i32 field_3A0;

	PADDING(4);


	i32 field_3A8;

	PADDING(0x3B8-0x3A8-4);

	u32 field_3B8;

	PADDING(0x3d0-0x3b8-4);

};

class CMysterioLaser : public CNonRenderedBit
{
	public:
		EXPORT void SetDamage(int);

		PADDING(0x11-4);

		i32 field_4C;

		PADDING(0x64-0x4C-4);
};

class CGoldFish : public CBody
{
	public:
		EXPORT void AngryMode(void);
		EXPORT void NormalMode(void);

		PADDING(0xF8-0xF4);

		i32 field_F8;

		PADDING(0x110-0xF8-4);

};

class CMysterioHeadCircle : public CQuadBit
{
	public:
		EXPORT void NormalMode(void);
		EXPORT void AngryMode(void);

		PADDING(4);

		i32 field_88;
		i32 field_8C;
};

class CFadePalettes : public CNonRenderedBit
{
	public:
		EXPORT CFadePalettes(u8,u8,u8);

		EXPORT void FadeDown(void);
		EXPORT void Move(void);
		EXPORT ~CFadePalettes(void);

		PADDING(0x45B-0x3D+1);

		u8 field_45B;

		PADDING(0x460-0x45B-1);
};

class CAngrySpark : public CQuadBit
{
	public:
		EXPORT CAngrySpark(CVector*);
		EXPORT virtual ~CAngrySpark(void) OVERRIDE;
};

class CDamagedSoftSpotEffect : public CNonRenderedBit
{
	public:
		EXPORT CDamagedSoftSpotEffect(CBody*, i32);
		EXPORT virtual ~CDamagedSoftSpotEffect(void) OVERRIDE;

		PADDING(0xC);

		// @FIXME  type
		void *field_48;
};

void validate_CMystFoot(void);
void validate_CMysterio(void);
void validate_CSoftSpot(void);
void validate_CMysterioLaser(void);
void validate_CGoldFish(void);
void validate_CMysterioHeadCircle(void);
void validate_CFadePalettes(void);
void validate_CAngrySpark(void);
void validate_CDamagedSoftSpotEffect(void);

EXPORT void Mysterio_CreateMysterio(const u32 *stack, u32 *result);
EXPORT void Mysterio_RelocatableModuleInit(reloc_mod *);
EXPORT void Mysterio_RelocatableModuleClear(void);

EXPORT void Mysterio_FadePalettesUp(const u32*, u32*);
EXPORT void Mysterio_FadePalettesDown(const u32*, u32*);
#endif
