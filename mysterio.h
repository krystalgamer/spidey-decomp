#pragma once

#ifndef MYSTERIO_H
#define MYSTERIO_H

#include "export.h"
#include "baddy.h"
#include "camera.h"


class CMystFoot : public CBaddy {};

class CSoftSpot : public CBaddy {
public:
	int field_324;
	int field_328;
	int field_32c;
	int field_330;
	int field_334;
};

class CMysterio : public CBaddy {
	public:

	EXPORT CMysterio(i32*, i32);
	EXPORT CMysterio(void);
	EXPORT u8 MystRedbook_XAPlayPos(i32, i32, CVector*, i32);
	EXPORT i32 CMysterio::PlayAndAttachXAPlease(i32, i32, CBody*, i32);
	EXPORT void ShakePad(void);
	EXPORT i32 CheckforCameraShake(i32);
	EXPORT void EnterP2(void);
	EXPORT i32 GetAttackRotSpeed(void);
	EXPORT void SummonAttack(void);
	EXPORT void LookMenacing(void);

	i32 field_324;
	u8 padAfter324[0x4];

	i32 field_32C;
	u8 padAfter32C[0x34C-0x32c-4];

	i32 field_34C;
	i32 field_350;
	u8 padAfter350[4];

	i32 field_358;
	u8 padAfter358[0x4];


	i32 field_360;
	i32 field_364;
	i32 field_368;
	i32 field_36C;
	u8 padAfter36C[0x4];

	i32 field_374;
	i32 field_378;
	i32 field_37C;
	i32 field_380;
	i32 field_384;
	u8 padAfter384[0x4];

	i32 field_38C;
	u8 padAfter38c[0x8];

	i32 field_398;
	i32 field_39C;
	i32 field_3A0;
	u8 padAfter3A8[4];


	i32 field_3A8;
	u8 mysterioEndPad[0x3d0-0x3a8-4];

};

class CMysterioLaser : public CNonRenderedBit
{
	public:
		EXPORT void SetDamage(int);
		unsigned char fullPad[0x11-4];
		int field_4C;
		unsigned char padBottom[0x64-0x4C-4];
};

class CGoldFish : public CBody
{
	public:
		EXPORT void AngryMode(void);
		EXPORT void NormalMode(void);

		unsigned char pad[0xF8-0xF4];

		int field_F8;

		unsigned char bottomPad[0x110-0xF8-4];

};

class CMysterioHeadCircle : public CQuadBit
{
	public:
		EXPORT void NormalMode(void);
		EXPORT void AngryMode(void);
		unsigned char topPad[4];
		int field_88;
		int field_8C;
};

class CFadePalettes : public CNonRenderedBit
{
	public:
		unsigned char fullPad[0x424];
};

void validate_CMystFoot(void);
void validate_CMysterio(void);
void validate_CSoftSpot(void);
void validate_CMysterioLaser(void);
void validate_CGoldFish(void);
void validate_CMysterioHeadCircle(void);
void validate_CFadePalettes(void);

EXPORT void Mysterio_CreateMysterio(const unsigned int *stack, unsigned int *result);

#endif
