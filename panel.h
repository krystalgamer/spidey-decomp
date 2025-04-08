#pragma once


#ifndef PANEL_H
#define PANEL_H

#include "export.h"
#include "ob.h"
#include "texture.h"


struct POLY_FT4
{
	// offset: 0000
	u32 tag;
	// offset: 0004
	u8 r0;
	// offset: 0005
	u8 g0;
	// offset: 0006
	u8 b0;
	// offset: 0007
	u8 code;
	// offset: 0008
	i16 x0;
	// offset: 000A
	i16 y0;
	// offset: 000C
	u8 u0;
	// offset: 000D
	u8 v0;
	// offset: 000E
	u16 clut;
	// offset: 0010
	i16 x1;
	// offset: 0012
	i16 y1;
	// offset: 0014
	u8 u1;
	// offset: 0015
	u8 v1;
	// offset: 0016
	u16 tpage;
	// offset: 0018
	i16 x2;
	// offset: 001A
	i16 y2;
	// offset: 001C
	u8 u2;
	// offset: 001D
	u8 v2;
	// offset: 001E
	u16 pad1;
	// offset: 0020
	i16 x3;
	// offset: 0022
	i16 y3;
	// offset: 0024
	u8 u3;
	// offset: 0025
	u8 v3;
	// offset: 0026
	u16 pad2;
};

struct POLY_GT4
{
};

EXPORT void Panel_CreateHealthBar(CBody*, i32);
EXPORT void Panel_DestroyCompass(void);
EXPORT int Panel_DrawTexturedPoly(SAnimFrame*, int);
EXPORT int Panel_DrawTexturedPoly(Texture*, int);

EXPORT void DCDrawGouraudPoly(f32,POLY_GT4 *,Texture *,i32);
EXPORT void DCDrawGouraudPoly(f32,i32,i32,i32,i32,u32,u32,u32,u32,i32);
EXPORT void DCPanel_DrawFlatShadedPoly(f32,i32,i32,i32,i32,u8,u8,u8,i32,i32);
EXPORT void DCPanel_DrawTexturedPoly(f32,POLY_FT4 *,SAnimFrame const *,i32,i32,i32,i32,i32,u32);
EXPORT void DCPanel_DrawTexturedPoly(f32,POLY_FT4 *,SAnimFrame const *,u32);
EXPORT void DCPanel_DrawTexturedPoly(f32,POLY_FT4 *,Texture const *,u32);

EXPORT void Panel_CreateCompass(CVector *);
EXPORT void Panel_DestroyHealthBar(void);
EXPORT void Panel_Display(void);
EXPORT void Panel_DisplayCompass(void);
EXPORT void Panel_DisplayHealthBar(void);
EXPORT void Panel_DisplayTimer(void);
EXPORT void Panel_DrawFlatShadedPoly(i32,i32,i32,i32,u8,u8,u8,i32,i32);
EXPORT void Panel_Init(void);
EXPORT void Panel_SetStretchedScreenCoords(i32,i32,POLY_FT4 *,SAnimFrame *,i32,i32);
EXPORT void Panel_SetStretchedScreenCoords(i32,i32,POLY_FT4 *,Texture const *,i32,i32);
EXPORT void Panel_UpdateTimer(void);

void validate_SAnimFrame(void);
void validate_Texture(void);
void validate_POLY_FT4(void);
void validate_POLY_GT4(void);

#endif
