#include "ps2m3d.h"
#include "ps2funcs.h"
#include "db.h"
#include "PCGfx.h"
#include "m3dinit.h"
#include "SpideyDX.h"

i32 gWideScreen;
// @FIXME
char gRenderBuf[4] = { 0, 0, 0, 0 };

// @SMALLTODO
void M3d_BuildTransform(CSuper* a)
{
	printf("void M3d_BuildTransform(CSuper* a)");
}

// @BIGTODO
void M3d_Render(void*)
{
	printf("void M3d_Render(void*)");
}

// @MEDIUMTODO
void DCModel_RenderModel(SModel const *,DCModelData *,matrix4x4 const *,void const *)
{
    printf("DCModel_RenderModel(SModel const *,DCModelData *,matrix4x4 const *,void const *)");
}

// @MEDIUMTODO
void DC_PSXModel_RenderModel(SModel const *,matrix4x4 const *,void const *,DCModelData *)
{
    printf("DC_PSXModel_RenderModel(SModel const *,matrix4x4 const *,void const *,DCModelData *)");
}

// @MEDIUMTODO
void M3d_PreprocessPulsingColours(i32)
{
    printf("M3d_PreprocessPulsingColours(i32)");
}

// @MEDIUMTODO
void M3d_PreprocessWibblyTextures(i32)
{
    printf("M3d_PreprocessWibblyTextures(i32)");
}

// @MEDIUMTODO
void M3d_RenderBackground(void *)
{
    printf("M3d_RenderBackground(void *)");
}

// @Ok
// @Test
// can't get it to match but that's fine, looks good tho
void M3d_RenderCleanup(void)
{
	SetDrawArea();
	pPoly += 3;

	stubbed_printf(gRenderBuf);

	if (gWideScreen)
	{
		PCGfx_UseTexture(1, DCGfx_BlendingMode_0);

		float v2 = (float)gGameResolutionY;
		float v5 = (float)(unsigned int)Yres;
		float v1 = v2 / v5;
		float v6 = (float)gWideScreen;
		float v12 = v1 * v6;
		float v7 = (float)gGameResolutionX;
		float v3 = (float)(unsigned int)Xres;
		float v8 = v7 / v3 * 512.0f;
		PCGfx_DrawQuad2D(
				0,
				0,
				v8,
				v12,
				0,
				0,
				1.0,
				1.0,
				0xFF000000,
				0.0,
				false);

		float v13 = (float)gGameResolutionY;
		float v9 = (float)(unsigned int)Yres;
		float v4 = v13 / v9;
		float v14 = (float)gWideScreen;
		float v18 = v14 * v4;
		float v15 = (float)gGameResolutionX;
		float v10 = (float)(unsigned int)Xres;
		float v11 = v15 / v10 * 512.0f;
		float v16 = (float)(240 - gWideScreen);
		float v17 = v16 * v4;
		PCGfx_DrawQuad2D(
				0,
				v17,
				v11,
				v18,
				0,
				0,
				1.0,
				1.0,
				0xFF000000,
				0.0,
				false);
	}
}

// @MEDIUMTODO
void M3d_RenderSetup(SCamera *,SViewport *,u32 *)
{
    printf("M3d_RenderSetup(SCamera *,SViewport *,u32 *)");
}

// @MEDIUMTODO
void RenderSuperItem(CItem *,bool)
{
    printf("RenderSuperItem(CItem *,bool)");
}
