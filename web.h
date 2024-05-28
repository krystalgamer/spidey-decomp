#pragma once

#ifndef WEB_H
#define WEB_H

#include "bit.h"
#include "export.h"
#include "ob.h"


class CImpactWeb : public CFlatBit{
public:
	unsigned char padFull[0x24];
};


class CDomePiece : public CBody {
public:
	int padTop;

	int field_F8;
	int field_FC;
};

class CDome : public CBody {
public:
	unsigned char padFull[0x25];
};

class CDomeRing : public CBody {
public:

	int padTop;

	int field_F8;
	int field_FC;
	int field_100;
	int field_104;
	int field_108;

	unsigned char lastCDomeRing;
};


class CWeb : public CBody {
public:

	unsigned char padTop[0xF8-0xF4];

	int field_F8;

	unsigned char padBefore100[0x100-0xF8-4];

	int field_100;
	int field_104;
	CVector field_108;

	CVector field_114;

	int field_120;
	int field_124;
	int field_128;
	unsigned char *field_12C;

	int field_130;

	int field_134;
	int field_138;
};

class CSwinger : public CBody 
{
	public:
		EXPORT int IsOneTimeToDie(void);
		EXPORT void SetSpideyAnimFrame(int);
		unsigned char padTop[0x180-0xF4];

		int field_180;

		unsigned char padBottom[0x190-0x180-4];
};

class CSplat : public CQuadBit {
public:
};

class CTrapWebEffect : public CNonRenderedBit
{
	public:
		EXPORT void Burst(void);
		unsigned char topPad[0x3F4];
};

class CDomeShockWave : public CNonRenderedBit
{
	public:
		EXPORT void ResetHitFlags(CBody*);
		unsigned char fullPad[0x5C];
};

EXPORT int Web_GetGroundY(const CVector*);


void validate_CImpactWeb(void);
void validate_CDomePiece(void);
void validate_CDome(void);
void validate_CDomeRing(void);
void validate_CWeb(void);
void validate_CSwinger(void);
void validate_CSplat(void);
void validate_CTrapWebEffect(void);
void validate_CDomeShockWave(void);

#endif
