#include "panel.h"
#include "spool.h"
#include "validate.h"

EXPORT CVector gCompassPosition = {0, 0, 0};

EXPORT u8 gCompassStatus;

EXPORT SAnimFrame* gAnimSp;
EXPORT SAnimFrame* gAnimCompass;
EXPORT SAnimFrame* gAnimWebcart;

EXPORT i32 gHealthBarOne;
EXPORT i32 gHealthBarTwo;


// @MEDIUMTODO
void DCDrawGouraudPoly(float,POLY_GT4 *,Texture *,i32)
{
    printf("DCDrawGouraudPoly(float,POLY_GT4 *,Texture *,i32)");
}

// @MEDIUMTODO
void DCDrawGouraudPoly(float,i32,i32,i32,i32,u32,u32,u32,u32,i32)
{
    printf("DCDrawGouraudPoly(float,i32,i32,i32,i32,u32,u32,u32,u32,i32)");
}

// @MEDIUMTODO
void DCPanel_DrawFlatShadedPoly(float,i32,i32,i32,i32,u8,u8,u8,i32,i32)
{
    printf("DCPanel_DrawFlatShadedPoly(float,i32,i32,i32,i32,u8,u8,u8,i32,i32)");
}

// @MEDIUMTODO
void DCPanel_DrawTexturedPoly(float,POLY_FT4 *,SAnimFrame const *,i32,i32,i32,i32,i32,u32)
{
    printf("DCPanel_DrawTexturedPoly(float,POLY_FT4 *,SAnimFrame const *,i32,i32,i32,i32,i32,u32)");
}

// @MEDIUMTODO
void DCPanel_DrawTexturedPoly(float,POLY_FT4 *,SAnimFrame const *,u32)
{
    printf("DCPanel_DrawTexturedPoly(float,POLY_FT4 *,SAnimFrame const *,u32)");
}

// @MEDIUMTODO
void DCPanel_DrawTexturedPoly(float,POLY_FT4 *,Texture const *,u32)
{
    printf("DCPanel_DrawTexturedPoly(float,POLY_FT4 *,Texture const *,u32)");
}

// @Ok
void Panel_CreateCompass(CVector * pVec)
{
	gCompassPosition = *pVec >> 12;
	gCompassStatus = 1;
}

// @MEDIUMTODO
void Panel_Display(void)
{
    printf("Panel_Display(void)");
}

// @MEDIUMTODO
void Panel_DisplayCompass(void)
{
    printf("Panel_DisplayCompass(void)");
}

// @MEDIUMTODO
void Panel_DisplayHealthBar(void)
{
    printf("Panel_DisplayHealthBar(void)");
}

// @MEDIUMTODO
void Panel_DisplayTimer(void)
{
    printf("Panel_DisplayTimer(void)");
}

// @SMALLTODO
void Panel_DrawFlatShadedPoly(i32,i32,i32,i32,u8,u8,u8,i32,i32)
{
    printf("Panel_DrawFlatShadedPoly(i32,i32,i32,i32,u8,u8,u8,i32,i32)");
}

// @Ok
// @Matching
void Panel_Init(void)
{
	Spool_AnimAccess("Sp", &gAnimSp);
	Spool_AnimAccess("Compass", &gAnimCompass);
	Spool_AnimAccess("Webcart", &gAnimWebcart);
}

// @SMALLTODO
void Panel_SetStretchedScreenCoords(i32,i32,POLY_FT4 *,SAnimFrame *,i32,i32)
{
    printf("Panel_SetStretchedScreenCoords(i32,i32,POLY_FT4 *,SAnimFrame *,i32,i32)");
}

// @SMALLTODO
void Panel_SetStretchedScreenCoords(i32,i32,POLY_FT4 *,Texture const *,i32,i32)
{
    printf("Panel_SetStretchedScreenCoords(i32,i32,POLY_FT4 *,Texture const *,i32,i32)");
}

// @SMALLTODO
void Panel_UpdateTimer(void)
{
    printf("Panel_UpdateTimer(void)");
}

// @SMALLTODO
void Panel_CreateHealthBar(const CBody*, int)
{
}

// @Ok
void Panel_DestroyHealthBar(void)
{
	gHealthBarOne = 0;
	gHealthBarTwo = 0;
}

// @Ok
void Panel_DestroyCompass(void)
{
	gCompassStatus = 0;
}

// @Ok
int Panel_DrawTexturedPoly(SAnimFrame* pFrame, int a2)
{
	return Panel_DrawTexturedPoly(pFrame->pTexture, a2);
}

// @SMALLTODO
int Panel_DrawTexturedPoly(Texture*, int)
{
	return 0x28052024;
}

void validate_SAnimFrame(void)
{
	VALIDATE_SIZE(SAnimFrame, 0x8);

	VALIDATE(SAnimFrame, OffX, 0x0);
	VALIDATE(SAnimFrame, OffY, 0x1);
	VALIDATE(SAnimFrame, Width, 0x2);
	VALIDATE(SAnimFrame, Height, 0x3);
	VALIDATE(SAnimFrame, pTexture, 0x4);
}

void validate_Texture(void)
{
	VALIDATE_SIZE(Texture, 0x2C);

	VALIDATE(Texture, u0, 0x0);
	VALIDATE(Texture, v0, 0x1);

	VALIDATE(Texture, clut, 0x2);

	VALIDATE(Texture, u1, 0x4);
	VALIDATE(Texture, v1, 0x5);

	VALIDATE(Texture, tpage, 0x6);

	VALIDATE(Texture, u2, 0x8);
	VALIDATE(Texture, v2, 0x9);

	VALIDATE(Texture, u3, 0xA);
	VALIDATE(Texture, v3, 0xB);

	VALIDATE(Texture, TexWin, 0xC);
	VALIDATE(Texture, Usage, 0x10);
	VALIDATE(Texture, field_12, 0x12);
	VALIDATE(Texture, Checksum, 0x14);

	VALIDATE(Texture, pPalette, 0x18);
	VALIDATE(Texture, x, 0x1C);
	VALIDATE(Texture, y, 0x1E);

	VALIDATE(Texture, pNext, 0x20);
	VALIDATE(Texture, pPrevious, 0x24);
	VALIDATE(Texture, mRegion, 0x28);
}

void validate_POLY_FT4(void)
{
}

void validate_POLY_GT4(void)
{
}
