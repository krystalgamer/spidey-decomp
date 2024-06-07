#pragma once

#ifndef MYSTERIO_H
#define MYSTERIO_H

#include "export.h"
#include "baddy.h"


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

	EXPORT CMysterio(int*, int);
	EXPORT CMysterio(void);

	int field_324;
	unsigned char padAfter324[0x4];

	int field_32C;
	unsigned char padAfter32C[0x358-0x32c-4];

	int field_358;
	unsigned char padAfter358[0x4];


	int field_360;
	int field_364;
	int field_368;
	int field_36C;
	unsigned char padAfter36C[0x4];

	int field_374;
	int field_378;
	int field_37C;
	int field_380;
	int field_384;
	unsigned char padAfter384[0x4];

	int field_38C;
	unsigned char padAfter38c[0x8];

	int field_398;
	unsigned char padAfter398[0x3a8-0x398-4];


	int field_3A8;
	unsigned char mysterioEndPad[0x3d0-0x3a8-4];

};

class CMysterioLaser : public CNonRenderedBit
{
	public:
		EXPORT void SetDamage(int);
		unsigned char fullPad[0x11];
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
