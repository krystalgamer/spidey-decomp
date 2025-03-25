#include "post.h"
#include "bit.h"
#include "PCGfx.h"
#include "m3dinit.h"
#include "SpideyDX.h"
#include "db.h"

EXPORT i32 gWaterEffect;
EXPORT i32 gPostTimerRelated;
EXPORT i32 gPostWaterEffect;
EXPORT u16 gPostWordRelated;

EXPORT u8 gPaletteProcessingPaused;

EXPORT i32 gPostSpideyLogoRelated;
EXPORT u32 gPostPauseRelated;


// @SMALLTODO
void Post_DoPauseDisplayListProcessing(void)
{
    printf("Post_DoPauseDisplayListProcessing(void)");
}

// @Ok
// @Matching
void Post_DoPausePaletteProcessing(void)
{
	gPaletteProcessingPaused = 1;
	gPostSpideyLogoRelated = 0;
	gPostPauseRelated = Db_SkyColor;
}

// @Ok
// @Matching
void Post_PostProcessEffects(void)
{
	if (gWaterEffect)
	{
		gPostTimerRelated = 48 * gTimerRelated;
		Post_WaterEffect();
	}
	if (gPostWordRelated)
	{
		--gPostWordRelated;
	}
}

// @MEDIUMTODO
void Post_SpideyLogo(void)
{
    printf("Post_SpideyLogo(void)");
}

// @Ok
// @Matching
void Post_UndoPausePaletteProcessing(void)
{
	if (gPaletteProcessingPaused)
		gPaletteProcessingPaused = 0;
}

// @Ok
// @Matching
// @Note: getting the v1 and v2 assignment was insane I had wrong code thank god I checked the size
INLINE void Post_WaterEffect(void)
{
	if (!gPostWaterEffect)
	{
		i32 v1 = rcossin_tbl[(gPostTimerRelated / 2) & 0xFFF].sin >> 6;
		i32 v2 = rcossin_tbl[(gPostTimerRelated / 2) & 0xFFF].cos >> 6;

		PCGfx_UseTexture(1, DCGfx_BlendingMode_1);
		f32 v3 = gGameResolutionY;
		f32 a3 = Yres;
		f32 v8 = v3 / a3 * 240.0f;
		f32 a3a = gGameResolutionX;

		f32 v4 = Xres;
		f32 a3b = a3a / v4 * 512.0f;

		PCGfx_DrawQuad2D(
			0.0,
			0.0,
			a3b,
			v8,
			0.0,
			0.0,
			1.0,
			1.0,
			(my_abs(v1) + 64) << 8 | (my_abs(v2) + 64) << 16 | 0x30000032,
			6.0,
			0);
	}
}
