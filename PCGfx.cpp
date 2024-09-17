#include "PCGfx.h"
#include "PCTex.h"
#include "DXsound.h"
#include "SpideyDX.h"

#include <cmath>

u8 gSceneRelated;

EXPORT float gZLayerFurthest;
EXPORT float gZLayerNearest;

EXPORT float gFlFoggingParamOne = 100000.0f;
EXPORT float gFlFoggingParamTwo = 100005.0f;
EXPORT u32 gU32FoggingParamThree;

EXPORT u8 gBFoggingRelated;

EXPORT u32 gPcGfxSkyColor;

// @NotOk
// missing fog stuff
void PCGfx_BeginScene(u32,i32)
{
	if (!gSceneRelated)
	{
		if (gBFoggingRelated)
		{
			setupFog();
		}

		PCGfx_ProcessTexture(0, -1, 0);
		DXPOLY_BeginScene();
		gSceneRelated = 1;
		gZLayerNearest = 0.0099999998;
		gZLayerFurthest = -0.2;
	}
}

// @MEDIUMTODO
void PCGfx_ClipSendIndexedVertList(tagKMVERTEX3 const *,i32,u16 const *,i32)
{
    printf("PCGfx_ClipSendIndexedVertList(tagKMVERTEX3 const *,i32,u16 const *,i32)");
}

// @SMALLTODO
void PCGfx_ClipTriToNearPlane(_DXVERT **,_DXVERT *const *)
{
    printf("PCGfx_ClipTriToNearPlane(_DXVERT **,_DXVERT *const *)");
}

// @MEDIUMTODO
void PCGfx_DoModelPreview(void)
{
    printf("PCGfx_DoModelPreview(void)");
}

// @MEDIUMTODO
void PCGfx_DrawLine(float,float,float,u32,float,float,float,u32,float)
{
    printf("PCGfx_DrawLine(float,float,float,u32,float,float,float,u32,float)");
}

// @MEDIUMTODO
void PCGfx_DrawQPoly2D(float,float,float,float,u32,float,float,float,float,u32,float,float,float,float,u32,float,float,float,float,u32,float)
{
    printf("PCGfx_DrawQPoly2D(float,float,float,float,u32,float,float,float,float,u32,float,float,float,float,u32,float,float,float,float,u32,float)");
}

// @MEDIUMTODO
void PCGfx_DrawQPoly3D(float,float,float,float,float,u32,float,float,float,float,float,u32,float,float,float,float,float,u32,float,float,float,float,float,u32)
{
    printf("PCGfx_DrawQPoly3D(float,float,float,float,float,u32,float,float,float,float,float,u32,float,float,float,float,float,u32,float,float,float,float,float,u32)");
}

// @MEDIUMTODO
void PCGfx_DrawQuad2D(float,float,float,float,float,float,float,float,u32,float,bool)
{
    printf("PCGfx_DrawQuad2D(float,float,float,float,float,float,float,float,u32,float,bool)");
}

// @MEDIUMTODO
void PCGfx_DrawTPoly2D(float,float,float,float,u32,float,float,float,float,u32,float,float,float,float,u32,float)
{
    printf("PCGfx_DrawTPoly2D(float,float,float,float,u32,float,float,float,float,u32,float,float,float,float,u32,float)");
}

// @MEDIUMTODO
void PCGfx_DrawTPoly3D(float,float,float,float,float,u32,float,float,float,float,float,u32,float,float,float,float,float,u32)
{
    printf("PCGfx_DrawTPoly3D(float,float,float,float,float,u32,float,float,float,float,float,u32,float,float,float,float,float,u32)");
}

// @MEDIUMTODO
void PCGfx_DrawTexture2D(i32,i32,i32,float,u32,u32,float)
{
    printf("PCGfx_DrawTexture2D(i32,i32,i32,float,u32,u32,float)");
}

// @MEDIUMTODO
void PCGfx_EndScene(i32)
{
    printf("PCGfx_EndScene(i32)");
}

// @Ok
// @Matching
void PCGfx_Exit(void)
{
	PCGfx_ProcessTexture(0, -1, 0);
	PCTex_ReleaseAllTextures();
	print_if_false(PCTex_CountActiveTextures() == 0, "some textures still allocated!");
}

// @Ok
float PCGfx_GetZLayerFurthest(void)
{
	if ( !gSceneRelated )
		PCGfx_BeginScene(3, -1);

	return gZLayerFurthest;
}

// @Ok
float PCGfx_GetZLayerNearest(void)
{
	if ( !gSceneRelated )
		PCGfx_BeginScene(3, -1);

	return gZLayerNearest;
}

// @Ok
void PCGfx_IncZLayerFurthest(void)
{
	gZLayerFurthest -= 10.0f;
}

// @Ok
void PCGfx_IncZLayerNearest(void)
{
	gZLayerNearest += 0.001f;
}

// @Ok
void PCGfx_InitAtStart(void)
{
	DXPOLY_SetOutlineColor(0xFF00FF00);
	DXPOLY_SetHUDOffset(7);
	PCGfx_ProcessTexture(0, -1, 0);
	PCGfx_SetBrightness(gBrightnessRelated);
}

// @Ok
// @Matching
u8 PCGfx_IsInScene(void)
{
	return gSceneRelated;
}

// @SMALLTODO
void PCGfx_ProcessTexture(_tagKMSTRIPHEAD *,i32,DCGfx_BlendingMode)
{
    printf("PCGfx_ProcessTexture(_tagKMSTRIPHEAD *,i32,DCGfx_BlendingMode)");
}

// @SMALLTODO
void PCGfx_RenderInit(float,float,float,float,float)
{
    printf("PCGfx_RenderInit(float,float,float,float,float)");
}

// @SMALLTODO
void PCGfx_RenderModelPreview(void *,char const *,i32)
{
    printf("PCGfx_RenderModelPreview(void *,char const *,i32)");
}

EXPORT i8 gPcGfxBrightnessValues[256];
EXPORT float gPcGfxBrightnessPower[8] =
{
	0.80000001f,
	0.85000002f,
	0.89999998f,
	0.94999999f,
	1.0f,
	1.05f,
	1.1f,
	1.15f
};

// @Ok
// @Test
INLINE void PCGfx_SetBrightness(i32 a1)
{
	float v8 = 1.0f / gPcGfxBrightnessPower[a1];
	for (i32 i = 0; i < 256; i++)
	{

		float v9 = i;
		float v6 = v9 / 255.0f;
		float v7 = pow(v6, v8);

		i32 v3 = (v7 * 255.0f + 0.5f);
		if (v3 >= 128)
		{
			v3 = 255;
		}
		else
		{
			v3 *= 2;
		}

		gPcGfxBrightnessValues[i] = v3;
	}
}

// @Ok
// @Matching
void PCGfx_SetFogParams(
		float a1,
		float a2,
		u32 a3)
{
	u32 three = a3;
	if ((a3 & 0xFF000000) == 0x80000000)
	{
		three = 0xFFFFFF & a3;
		a1 = a2 * 0.88999999f;
	}

	gFlFoggingParamOne = a1;
	gFlFoggingParamTwo = a2;
	gU32FoggingParamThree = three;
	gBFoggingRelated = 1;
}

// @SMALLTODO
void PCGfx_SetRenderParameter(DCGfx_RenderParameter,DCGfx_RenderSetting)
{
    printf("PCGfx_SetRenderParameter(DCGfx_RenderParameter,DCGfx_RenderSetting)");
}

// @Ok
INLINE void PCGfx_SetSkyColor(u32 a1)
{
	gPcGfxSkyColor = a1;
	DXPOLY_SetBackgroundColor(a1 | 0xFF000000);
}

// @SMALLTODO
void PCGfx_UseTexture(i32,DCGfx_BlendingMode)
{
    printf("PCGfx_UseTexture(i32,DCGfx_BlendingMode)");
}

// @MEDIUMTODO
void PCPanel_DrawTexturedPoly(float,Texture const *,i32,i32,i32,i32,u8)
{
    printf("PCPanel_DrawTexturedPoly(float,Texture const *,i32,i32,i32,i32,u8)");
}

// @MEDIUMTODO
void ZCLIP_VERT(_DXVERT *,_DXVERT *,_DXVERT *,float)
{
    printf("ZCLIP_VERT(_DXVERT *,_DXVERT *,_DXVERT *,float)");
}

// @SMALLTODO
void createSuperItem(CItem *)
{
    printf("createSuperItem(CItem *)");
}

// @SMALLTODO
void setupFog(void)
{
    printf("setupFog(void)");
}

// @MEDIUMTODO
void submitPoly(_DXVERT **,i32)
{
    printf("submitPoly(_DXVERT **,i32)");
}
