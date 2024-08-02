#pragma once


#ifndef EFFECTS_H
#define EFFECTS_H

#include "ob.h"
#include "m3dcolij.h"
#include "export.h"

class CBouncingRock : public CFlatBit
{
	public:
		EXPORT CBouncingRock(CVector*, i32, u32);
		EXPORT virtual ~CBouncingRock(void);

		EXPORT virtual void Move(void);

		i32 field_68;
		i32 field_6C;
};

class CChunkSmoke : public CFlatBit
{
	public:
		EXPORT CChunkSmoke(CVector*, CVector*, i32);
		EXPORT virtual ~CChunkSmoke(void);

		EXPORT virtual void Move(void);

		CVector field_68;
		i32 field_74;
		i32 field_78;
		i32 field_7C;
};

class CFootprint : public CQuadBit
{
	public:
		EXPORT CFootprint(CVector*, i32);
		EXPORT virtual ~CFootprint(void);

		EXPORT virtual void Move(void);

		i32 field_84;
};

class CRhinoWallImpact : public CQuadBit
{
	public:
		EXPORT CRhinoWallImpact(SLineInfo*);
		EXPORT virtual ~CRhinoWallImpact(void);

		EXPORT virtual void Move(void);
		u8 padBottom[4];
};

class CElectrify : public CSimpleTexturedRibbon
{
	public:
		unsigned char pad[21];

		EXPORT CElectrify(CSuper*, int);
};

struct SSkinGooSource
{
};

struct SSkinGooSource2
{
};

struct SSkinGooParams
{
};

class CSkinGoo : public CQuadBit
{
	public:
		EXPORT CSkinGoo(CSuper*, SSkinGooSource*, i32, SSkinGooParams*);
		EXPORT CSkinGoo(CSuper*, SSkinGooSource2*, i32, SSkinGooParams*);

		u8 fullPad[0x54];
};

class CElectro : public CSimpleTexturedRibbon
{
	public:
		EXPORT CElectro(void);
		EXPORT virtual ~CElectro(void);

		u8 padTop[4];

		// @FIXME
		void *field_50;
		void *field_54;
};

class CElectroLine : public CElectro
{
	public:
		EXPORT CElectroLine(u16, u16, u16, u8, u8 ,u8, i32, i32, i32, i32, i32, u32*);
		EXPORT virtual ~CElectroLine(void);

		u8 padBottom[0x14];
};

void validate_CElectrify(void);
void validate_CSkinGoo(void);
void validate_SSkinGooSource(void);
void validate_SSkinGooSource2(void);
void validate_SSkinGooParams(void);
void validate_CRhinoWallImpact(void);
void validate_CFootprint(void);
void validate_CChunkSmoke(void);
void validate_CBouncingRock(void);
void validate_CElectro(void);
void validate_CElectroLine(void);

EXPORT void Effects_Electrify(CSuper*);
EXPORT void Effects_UnElectrify(CSuper*);

#endif
