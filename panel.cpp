#include "panel.h"
#include "spool.h"
#include "l1a3bomb.h"
#include "spidey.h"

#include "validate.h"

EXPORT i32 gHealthBarItemType;
EXPORT i32 gHealthBarRelated;
EXPORT i32 gHealthBarRelatedTwo;
EXPORT Texture* gHealthBarTextures[5];

// @FIXME
EXPORT CVector gCompassPosition;

EXPORT u8 gCompassStatus;

EXPORT SAnimFrame* gAnimSp;
EXPORT SAnimFrame* gAnimCompass;
EXPORT SAnimFrame* gAnimWebcart;

EXPORT CBody* gHealthBarOne;
EXPORT CBody* gHealthBarTwo;


// @MEDIUMTODO
void DCDrawGouraudPoly(f32,POLY_GT4 *,Texture *,i32)
{
    printf("DCDrawGouraudPoly(f32,POLY_GT4 *,Texture *,i32)");
}

// @MEDIUMTODO
void DCDrawGouraudPoly(f32,i32,i32,i32,i32,u32,u32,u32,u32,i32)
{
    printf("DCDrawGouraudPoly(f32,i32,i32,i32,i32,u32,u32,u32,u32,i32)");
}

// @MEDIUMTODO
void DCPanel_DrawFlatShadedPoly(f32,i32,i32,i32,i32,u8,u8,u8,i32,i32)
{
    printf("DCPanel_DrawFlatShadedPoly(f32,i32,i32,i32,i32,u8,u8,u8,i32,i32)");
}

// @MEDIUMTODO
void DCPanel_DrawTexturedPoly(f32,POLY_FT4 *,SAnimFrame const *,i32,i32,i32,i32,i32,u32)
{
    printf("DCPanel_DrawTexturedPoly(f32,POLY_FT4 *,SAnimFrame const *,i32,i32,i32,i32,i32,u32)");
}

// @MEDIUMTODO
void DCPanel_DrawTexturedPoly(f32,POLY_FT4 *,SAnimFrame const *,u32)
{
    printf("DCPanel_DrawTexturedPoly(f32,POLY_FT4 *,SAnimFrame const *,u32)");
}

// @MEDIUMTODO
void DCPanel_DrawTexturedPoly(f32,POLY_FT4 *,Texture const *,u32)
{
    printf("DCPanel_DrawTexturedPoly(f32,POLY_FT4 *,Texture const *,u32)");
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

// @Ok
// @AlmostMatching: same logic but slightly out of order
void Panel_SetStretchedScreenCoords(
		i32 a1,
		i32 a2,
		POLY_FT4 *a3,
		SAnimFrame *a4,
		i32 a5,
		i32 a6)
{
	i32 v6 = a5;
	if (!v6)
	{
		v6 = a4->Width;
	}

	v6 *= 6554;

	if ( (v6 & 0xFFF) >= 0x800)
	{
		v6 += 4096;
	}

	v6 >>= 12;

	if (!a6)
	{
		a6 = a4->Height;
	}

	i32 OffY = a4->OffY;
	i32 OffX = a4->OffX;


	a3->x0 = a1 + ((6554 * OffX) >> 12);
	a3->y0 = a2 + OffY;

	a3->x1 = a3->x0 + v6;
	a3->y1 = a3->y0;
	a3->x2 = a3->x0;

	a3->y2 = a3->y0 + a6;
	a3->x3 = a3->x1;
	a3->y3 = a3->y2;
}

// @Ok
// @Matching
void Panel_SetStretchedScreenCoords(
		i32 a1,
		i32 a2,
		POLY_FT4 *a3,
		const Texture *a4,
		i32 a5,
		i32 a6)
{
	i32 v6 = a5;
	if (!a5)
	{
		v6 = a4->u1 - a4->u0;
	}

	v6 *= 6554;

	if ((v6 & 0xFFF) >= 0x800)
	{
		v6 += 4096;
	}

	v6 >>= 12;

	if (!a6)
	{
		a6 = a4->v2 - a4->v0;
	}

	a3->x0 = a1;
	a3->y0 = a2;
	a3->x1 = a1 + v6;
	a3->y1 = a2;
	a3->x2 = a1;
	a3->y2 = a2 + a6;
	a3->x3 = a3->x1;
	a3->y3 = a3->y2;
}

// @Ok
INLINE void Panel_UpdateTimer(void)
{
	if (gBombDieRelatedTwo)
	{
		u32 v1 = 0;
		if (MechList->field_E18 || MechList->field_1AC)
		{
			v1 = 0;
		}
		else
		{
			v1 = (gBombRelated * (gTimerRelated - gBombDieTimerRelated)) >> 12;
		}

		if (gBombAIRelated > v1)
		{
			gBombAIRelated -= v1;
		}
		else
		{
			gBombAIRelated = 0;
		}

	}

	gBombDieTimerRelated = gTimerRelated;
}

// @Ok
void Panel_CreateHealthBar(CBody* pBody, i32 a2)
{
	if ( a2 != 316 )
	{
		gHealthBarOne = pBody;
		gHealthBarItemType = a2;
		gHealthBarRelated = pBody->mHealth;
	}
	else
	{
		gHealthBarTwo = pBody;
		gHealthBarRelatedTwo = pBody->mHealth;
	}

	switch ( a2 )
	{
		case 310:
			gHealthBarTextures[0] = Spool_FindTextureEntry("scorpion");
			gHealthBarTextures[1] = Spool_FindTextureEntry("boss");
			gHealthBarTextures[2] = Spool_FindTextureEntry("jonah");
			gHealthBarTextures[3] = Spool_FindTextureEntry("scorpion_wounded");
			break;
		case 307:
			gHealthBarTextures[0] = Spool_FindTextureEntry("rhino");
			gHealthBarTextures[1] = Spool_FindTextureEntry("boss");
			gHealthBarTextures[2] = Spool_FindTextureEntry("rhino_wounded");
			break;
		case 311:
			gHealthBarTextures[0] = Spool_FindTextureEntry("mysterio");
			gHealthBarTextures[1] = Spool_FindTextureEntry("boss");
			gHealthBarTextures[2] = Spool_FindTextureEntry("mysterio_wounded");
			break;
		case 313:
			gHealthBarTextures[0] = Spool_FindTextureEntry("venom");
			gHealthBarTextures[1] = Spool_FindTextureEntry("boss");
			gHealthBarTextures[2] = Spool_FindTextureEntry("maryjane_01");
			gHealthBarTextures[3] = Spool_FindTextureEntry("maryJane_bar");
			gHealthBarTextures[4] = Spool_FindTextureEntry("venom_wounded");
			break;
		case 308:
			gHealthBarTextures[0] = Spool_FindTextureEntry("dococ");
			gHealthBarTextures[1] = Spool_FindTextureEntry("boss");
			gHealthBarTextures[2] = Spool_FindTextureEntry("docOc_wounded");
			break;
		case 314:
			gHealthBarTextures[0] = Spool_FindTextureEntry("carnage");
			gHealthBarTextures[1] = Spool_FindTextureEntry("boss");
			gHealthBarTextures[2] = Spool_FindTextureEntry("carnage_wounded");
			break;
		default:
			gHealthBarOne = 0;
			gHealthBarItemType = 0;
			break;
	}
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
	VALIDATE_SIZE(POLY_FT4, 0x28);

	VALIDATE(POLY_FT4, tag, 0x0);

	VALIDATE(POLY_FT4, r0, 0x4);
	VALIDATE(POLY_FT4, g0, 0x5);
	VALIDATE(POLY_FT4, b0, 0x6);

	VALIDATE(POLY_FT4, code, 0x7);

	VALIDATE(POLY_FT4, x0, 0x8);
	VALIDATE(POLY_FT4, y0, 0xA);

	VALIDATE(POLY_FT4, u0, 0xC);
	VALIDATE(POLY_FT4, v0, 0xD);

	VALIDATE(POLY_FT4, clut, 0xE);

	VALIDATE(POLY_FT4, x1, 0x10);
	VALIDATE(POLY_FT4, y1, 0x12);

	VALIDATE(POLY_FT4, u1, 0x14);
	VALIDATE(POLY_FT4, v1, 0x15);

	VALIDATE(POLY_FT4, tpage, 0x16);

	VALIDATE(POLY_FT4, x2, 0x18);
	VALIDATE(POLY_FT4, y2, 0x1A);

	VALIDATE(POLY_FT4, x3, 0x20);
	VALIDATE(POLY_FT4, y3, 0x22);

	VALIDATE(POLY_FT4, u3, 0x24);
	VALIDATE(POLY_FT4, v3, 0x25);
}

void validate_POLY_GT4(void)
{
}
