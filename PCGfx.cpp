#include "PCGfx.h"
#include "PCTex.h"
#include "DXsound.h"
#include "SpideyDX.h"
#include "DXinit.h"

#include <cmath>


EXPORT u8 gIsRenderSettingE = 1;
EXPORT u8 gNonRendderSettingE;

u8 gSceneRelated;

EXPORT float gZLayerFurthest;
EXPORT float gZLayerNearest;

EXPORT float gFlFoggingParamOne = 100000.0f;
EXPORT float gFlFoggingParamTwo = 100005.0f;
EXPORT u32 gU32FoggingParamThree;

EXPORT u8 gBFoggingRelated;

EXPORT u32 gPcGfxSkyColor;

EXPORT i32 gEndSceneRelated = -1;
EXPORT i32 gEndSceneRelatedTwo;

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

		PCGfx_ProcessTexture(0, -1, DCGfx_BlendingMode_0);
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

// @Ok
// @Matching
// @Note powerpc has fps counter here and fog level
void PCGfx_EndScene(i32 a1)
{
	if (gSceneRelated)
	{
		DXPOLY_EndScene(a1 != 0);
		PCGfx_ProcessTexture(0, -1, DCGfx_BlendingMode_0);
		gEndSceneRelated = -1;
		gSceneRelated = 0;
		gEndSceneRelatedTwo = 0;
	}
}

// @Ok
// @Matching
void PCGfx_Exit(void)
{
	PCGfx_ProcessTexture(0, -1, DCGfx_BlendingMode_0);
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
	PCGfx_ProcessTexture(0, -1, DCGfx_BlendingMode_0);
	PCGfx_SetBrightness(gBrightnessRelated);
}

// @Ok
// @Matching
u8 PCGfx_IsInScene(void)
{
	return gSceneRelated;
}

EXPORT i32 gBlendingModes[DCGfx_BlendingMode_MAX + 1] =
{
	0, 1, 2, 3, 4
};

EXPORT u8 gProcessTextureRelated;
EXPORT u16 gChosenBlendingMode;
EXPORT u16 gProcessedTextureFlags;

// @NotOk
// missing low graphics stuff
void PCGfx_ProcessTexture(
		_tagKMSTRIPHEAD *,
		i32 a2,
		DCGfx_BlendingMode a3)
{
	i32 TextureFlags = PCTex_GetTextureFlags(a2);
	gProcessTextureRelated = (TextureFlags & 0x1000) != 0 && (a3 == DCGfx_BlendingMode_0 || a3 == DCGfx_BlendingMode_1);

	i32 curBlendingMode;
	if (a3 || a2 < 0 || !PCTex_TextureHasAlpha(a2))
	{
		curBlendingMode = gBlendingModes[a3];
	}
	else
	{
		curBlendingMode = gProcessTextureRelated ? 1 : 5;
	}

	gChosenBlendingMode = curBlendingMode;
	gNonRendderSettingE = (TextureFlags & 0x20) == 0 ? gIsRenderSettingE : 0;

	if (gLowGraphics)
	{
	}
	else if (a2 >= 0)
	{
		IDirectDrawSurface7* Direct3DTexture = PCTex_GetDirect3DTexture(a2);
		DXPOLY_SetTexture(Direct3DTexture);
		gProcessedTextureFlags = 0;

		if (PCTex_TextureHasAlpha(a2))
			gProcessedTextureFlags |= 8;

		i32 v9 = PCTex_GetTextureFlags(a2);
		if ((v9 & 8) != 0)
			gProcessedTextureFlags |= 0x10;

		if ((v9 & 0x20) != 0)
			gProcessedTextureFlags |= 1;

		if ((v9 & 2) == 0)
			gProcessedTextureFlags |= 2;

		if ((v9 & 4) == 0)
			gProcessedTextureFlags |= 4;
	}
	else
	{
		DXPOLY_SetTexture(0);
		gProcessedTextureFlags = 0;
	}
}

EXPORT float gRenderInitOne[3] = {  10.0f, 8048.0f, 276.0f };
EXPORT float gRenderInitTwo[2] = { 8038.0f, 1.9624f };

// @Ok
// @Matching
void PCGfx_RenderInit(float a1, float a2, float a3)
{
	gRenderInitOne[2] = a3;
	gRenderInitOne[0] = a1;
	gRenderInitOne[1] = a2;
	gRenderInitTwo[0] = a2 - a1;
	gRenderInitTwo[1] = gRenderInitTwo[0] / 4096.0f;
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

u32 gDepthCompareValues[DCGfx_RenderSetting_7 + 1] =
{
	0, 2, 3, 4, 5, 6, 7, 8,
};

u32 gFilterModeValues[DCGfx_RenderSetting_d - DCGfx_RenderSetting_a + 1] =
{
	0, 1 ,1 ,1
};

// @Ok
// @Matching
void PCGfx_SetRenderParameter(
		DCGfx_RenderParameter a1,
		DCGfx_RenderSetting a2)
{
	if ( !gLowGraphics )
	{
		switch ( a1 )
		{
			case DCGfx_RenderParameter_0:
				print_if_false(a2 >= DCGfx_RenderSetting_0, "Invalid render setting.");
				print_if_false(a2 <= DCGfx_RenderSetting_7, "Invalid render setting.");
				DXPOLY_SetDepthCompare(gDepthCompareValues[a2]);
				break;
			case DCGfx_RenderParameter_1:
				print_if_false(a2 >= DCGfx_RenderSetting_8, "Invalid render setting.");
				print_if_false(a2 <= DCGfx_RenderSetting_9, "Invalid render setting.");
				DXPOLY_SetDepthWriting(a2 == DCGfx_RenderSetting_8);
				break;
			case DCGfx_RenderParameter_2:
				break;
			case DCGfx_RenderParameter_3:
				print_if_false(a2 >= DCGfx_RenderSetting_a, "Invalid render setting.");
				print_if_false(a2 <= DCGfx_RenderSetting_d, "Invalid render setting.");
				DXPOLY_SetFilterMode(gFilterModeValues[a2-DCGfx_RenderSetting_a]);
				break;
			case DCGfx_RenderParameter_4:
				gIsRenderSettingE = a2 == DCGfx_RenderSetting_e;
				if (!gIsRenderSettingE)
					gNonRendderSettingE = gIsRenderSettingE;
				break;
			default:
				print_if_false(0, "Invalid render parameter.");
				break;
		}
	}
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
