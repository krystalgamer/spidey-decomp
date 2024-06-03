#pragma once


#ifndef PANEL_H
#define PANEL_H

#include "export.h"
#include "ob.h"
#include "texture.h"


struct SAnimFrame
{
	char OffX;
	char OffY;
	unsigned char Width;
	unsigned char Height;
	Texture *pTexture;
};

EXPORT void Panel_CreateHealthBar(const CBody*, int);
EXPORT void Panel_DestroyCompass(void);
EXPORT void Panel_DestroyHealthbar(void);
EXPORT int Panel_DrawTexturedPoly(SAnimFrame*, int);
EXPORT int Panel_DrawTexturedPoly(Texture*, int);

void validate_SAnimFrame(void);
void validate_Texture(void);

#endif
