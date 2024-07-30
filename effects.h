#pragma once


#ifndef EFFECTS_H
#define EFFECTS_H

#include "ob.h"
#include "m3dcolij.h"
#include "export.h"

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

void validate_CElectrify(void);
void validate_CSkinGoo(void);
void validate_SSkinGooSource(void);
void validate_SSkinGooSource2(void);
void validate_SSkinGooParams(void);
void validate_CRhinoWallImpact(void);

EXPORT void Effects_Electrify(CSuper*);
EXPORT void Effects_UnElectrify(CSuper*);

#endif
