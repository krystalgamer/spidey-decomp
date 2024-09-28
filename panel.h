#pragma once


#ifndef PANEL_H
#define PANEL_H

#include "export.h"
#include "ob.h"
#include "texture.h"


struct POLY_FT4
{
};

struct POLY_GT4
{
};

EXPORT void Panel_CreateHealthBar(CBody*, i32);
EXPORT void Panel_DestroyCompass(void);
EXPORT int Panel_DrawTexturedPoly(SAnimFrame*, int);
EXPORT int Panel_DrawTexturedPoly(Texture*, int);

EXPORT void DCDrawGouraudPoly(float,POLY_GT4 *,Texture *,i32);
EXPORT void DCDrawGouraudPoly(float,i32,i32,i32,i32,u32,u32,u32,u32,i32);
EXPORT void DCPanel_DrawFlatShadedPoly(float,i32,i32,i32,i32,u8,u8,u8,i32,i32);
EXPORT void DCPanel_DrawTexturedPoly(float,POLY_FT4 *,SAnimFrame const *,i32,i32,i32,i32,i32,u32);
EXPORT void DCPanel_DrawTexturedPoly(float,POLY_FT4 *,SAnimFrame const *,u32);
EXPORT void DCPanel_DrawTexturedPoly(float,POLY_FT4 *,Texture const *,u32);

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
