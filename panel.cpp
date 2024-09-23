#include "panel.h"
#include "spool.h"
#include "validate.h"

EXPORT SAnimFrame* gAnimSp;
EXPORT SAnimFrame* gAnimCompass;
EXPORT SAnimFrame* gAnimWebcart;

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

// @SMALLTODO
void Panel_CreateCompass(CVector *)
{
    printf("Panel_CreateCompass(CVector *)");
}

// @SMALLTODO
void Panel_DestroyHealthBar(void)
{
    printf("Panel_DestroyHealthBar(void)");
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
{}

static int gHealthBarOne;
static int gHealthBarTwo;
// @NotOk
// globals
void Panel_DestroyHealthbar(void)
{
	gHealthBarOne = 0;
	gHealthBarTwo = 0;
}

static unsigned char gPanelStatus;
// @NotOk
// Global
void Panel_DestroyCompass(void)
{
	gPanelStatus = 0;
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
	VALIDATE_SIZE(Texture, 0x28);

	VALIDATE(Texture, field_0, 0x0);
	VALIDATE(Texture, field_1, 0x1);
	VALIDATE(Texture, field_2, 0x2);

	VALIDATE(Texture, field_4, 0x4);
	VALIDATE(Texture, field_6, 0x6);

	VALIDATE(Texture, field_9, 0x9);

	VALIDATE(Texture, TexWin, 0xC);
	VALIDATE(Texture, Usage, 0x12);

	VALIDATE(Texture, Checksum, 0x14);
	VALIDATE(Texture, pNext, 0x20);
	VALIDATE(Texture, pPrevious, 0x24);
}

void validate_POLY_FT4(void)
{
}

void validate_POLY_GT4(void)
{
}
