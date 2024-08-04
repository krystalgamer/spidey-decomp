#pragma once

#ifndef WEAPONS_H
#define WEAPONS_H

#include "bit.h"
#include "export.h"

// @FIXME
#define SCalcBuffer i32

class CGouraudRibbon : public CSpecialDisplay
{
	public:
		EXPORT CGouraudRibbon(i32, i32);
		EXPORT void Display(void);
		EXPORT void SetRGB(u8,u8,u8);
		EXPORT void SetWidth(u16);
		EXPORT ~CGouraudRibbon(void);

		i32 mTrail;
		i32 NumPoints;
		SRibbonPoint* mpPoints;
};

class CSmokeRing : public CSpecialDisplay
{
	public:
		EXPORT CSmokeRing(i32,u32);
		EXPORT void Display(void);
		EXPORT void SetParams(CVector const *,i32,i32);
		EXPORT void SetRGB(i32,i32,i32);
		EXPORT void SetUV(i32,i32,i32);
		EXPORT ~CSmokeRing(void);
		u8 padBottom[0x30];
};

class CTexturedRibbon : public CSpecialDisplay
{
	public:
		EXPORT CTexturedRibbon(i32,i32);
		EXPORT void SetCoreRGBi(i32,u8,u8,u8);
		EXPORT void SetOuterRGBi(i32,u8,u8,u8);
		EXPORT void SetTexture(Texture *);
		EXPORT ~CTexturedRibbon(void);

		u8 topPad[0x60-0x3C];
		i32* field_60;
};

void validate_CGouraudRibbon(void);
void validate_CSmokeRing(void);
void validate_CTexturedRibbon(void);
EXPORT void CalcScreenNormal(SCalcBuffer *,i32 *,i32 *,i32);
EXPORT void Transform(CVector const *,long *);

#endif
