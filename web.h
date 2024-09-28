#pragma once

#ifndef WEB_H
#define WEB_H

#include "bit.h"
#include "export.h"
#include "spidey.h"

EXPORT extern i32 gFireDomes;
EXPORT extern i32 gNumDomes;
EXPORT extern CBody* WebList;

class CImpactWeb : public CFlatBit{
public:
	unsigned char padFull[0x24];
};


class CDomePiece : public CBody {
public:
	EXPORT CDomePiece(CVector*, i32, i32, i32);
	EXPORT virtual ~CDomePiece(void);

	i32 field_F4;
	i32 field_F8;
	i32 field_FC;
};

class CDome : public CBody
{
	public:
		EXPORT CDome(CPlayer*, i32);
		EXPORT virtual ~CDome(void);

		u8 padTop[0x4];

		SHandle hPlayer;

		i32 field_100;
		i32 field_104;

		// @FIXME types
		void *field_108;
		void *field_10C;
		void *field_110;
		void *field_114;
		void *field_118;
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

		SHandle field_3C;
		void *field_44;
		u8 padAfter44[0x418-0x44-4];

		u8 field_418;
		u8 bottomPad[0x430-0x418-1];
};

class CDomeShockWave : public CNonRenderedBit
{
	public:
		EXPORT CDomeShockWave(i32);
		EXPORT virtual ~CDomeShockWave(void);

		EXPORT void ResetHitFlags(CBody*);

		u8 padTop[8];
		CVector field_44;
		i32 field_50[16];
		i32 field_90;
		u8 padBottom[0x4];
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
