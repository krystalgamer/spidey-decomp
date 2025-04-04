#pragma once

#ifndef WEB_H
#define WEB_H

#include "bit.h"
#include "export.h"
#include "spidey.h"
#include "m3dutils.h"

EXPORT extern i32 gFireDomes;
EXPORT extern i32 gNumDomes;
EXPORT extern CBody* WebList;

class CImpactWeb : public CFlatBit
{
	public:
		PADDING(0x24);
};


class CDomePiece : public CBody 
{
	public:
		EXPORT CDomePiece(CVector*, i32, i32, i32);
		EXPORT virtual ~CDomePiece(void) OVERRIDE;

		i32 field_F4;
		i32 field_F8;
		i32 field_FC;
};

class CDome : public CBody
{
	public:
		EXPORT CDome(CPlayer*, i32);
		EXPORT virtual ~CDome(void) OVERRIDE;

		PADDING(4);

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

		PADDING(4);

		i32 field_F8;
		i32 field_FC;
		i32 field_100;
		i32 field_104;
		i32 field_108;

		PADDING(1);
};


class CWeb : public CBody
{
	public:

		PADDING(4);

		i32 field_F8;

		PADDING(4);

		i32 field_100;
		i32 field_104;
		CVector field_108;

		CVector field_114;

		i32 field_120;
		i32 field_124;
		i32 field_128;
		u8 *field_12C;

		i32 field_130;

		i32 field_134;
		i32 field_138;
};

class CSwinger : public CBody 
{
	public:
		EXPORT i32 IsOneTimeToDie(void);
		EXPORT void SetSpideyAnimFrame(i32);

		PADDING(0x180-0xF4);

		i32 field_180;

		PADDING(0x190-0x180-4);
};

class CSplat : public CQuadBit
{
	public:
};

class CTrapWebEffect : public CNonRenderedBit
{
	public:
		EXPORT void Burst(void);

		SHandle field_3C;
		i32 *field_44;

		PADDING(0x418-0x44-4);

		u8 field_418;
		PADDING(0x430-0x418-1);
};

class CDomeShockWave : public CNonRenderedBit
{
	public:
		EXPORT CDomeShockWave(i32);
		EXPORT virtual ~CDomeShockWave(void);

		EXPORT void ResetHitFlags(CBody*);

		PADDING(8);
		CVector field_44;
		i32 field_50[16];
		i32 field_90;

		PADDING(4);
};

EXPORT int Web_GetGroundY(const CVector*);
EXPORT i32 Web_CollideWithSuper(CSuper *,CVector const *,CVector const *,SHook *,i32);


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
