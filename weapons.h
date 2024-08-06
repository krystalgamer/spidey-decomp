#pragma once

#ifndef WEAPONS_H
#define WEAPONS_H

#include "bit.h"
#include "export.h"

// @FIXME
#define SCalcBuffer i32

class CSmokeRing : public CSpecialDisplay
{
	public:
		EXPORT CSmokeRing(i32,u32);
		EXPORT void Display(void);
		EXPORT void SetParams(CVector const *,i32,i32);
		EXPORT void SetRGB(i32,i32,i32);
		EXPORT void SetUV(i32,i32,i32);
		EXPORT ~CSmokeRing(void);

		u8 padTop[0x8];
		void* field_44;

		u8 padBottom[0x6C-0x44-4];
};

class CTexturedRibbon : public CSpecialDisplay
{
	public:
		EXPORT CTexturedRibbon(i32,i32);
		EXPORT void SetCoreRGBi(i32,u8,u8,u8);
		EXPORT void SetOuterRGBi(i32,u8,u8,u8);
		EXPORT void SetTexture(Texture *);
		EXPORT ~CTexturedRibbon(void);

		u8 mTrail;
		u8 padAfter3C[0x50-0x3C-1];

		i32 field_50;
		u8 padAfter50[0x58-0x50-4];

		i32 mNumPoints;
		SRibbonPoint* mpPoints;
		i32* field_60;
};

void validate_CGouraudRibbon(void);
void validate_CSmokeRing(void);
void validate_CTexturedRibbon(void);
EXPORT void CalcScreenNormal(SCalcBuffer *,i32 *,i32 *,i32);
EXPORT i32 Transform(CVector *,i32 *);

#endif
