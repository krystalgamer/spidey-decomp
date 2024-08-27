#include "PCGfx.h"
#include "PCTex.h"
#include "DXsound.h"
#include "SpideyDX.h"

u8 gSceneRelated;

EXPORT float gZLayerFurthest;
EXPORT float gZLayerNearest;

// @SMALLTODO
void PCGfx_BeginScene(u32,i32)
{
    printf("PCGfx_BeginScene(u32,i32)");
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

	return gZLayerFurthest;
}

// @SMALLTODO
void PCGfx_IncZLayerFurthest(void)
{
    printf("PCGfx_IncZLayerFurthest(void)");
}

// @SMALLTODO
void PCGfx_IncZLayerNearest(void)
{
    printf("PCGfx_IncZLayerNearest(void)");
}

// @SMALLTODO
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

// @SMALLTODO
void PCGfx_SetBrightness(i32)
{
    printf("PCGfx_SetBrightness(i32)");
}

// @SMALLTODO
void PCGfx_SetFogParams(float,float,u32)
{
    printf("PCGfx_SetFogParams(float,float,u32)");
}

// @SMALLTODO
void PCGfx_SetRenderParameter(DCGfx_RenderParameter,DCGfx_RenderSetting)
{
    printf("PCGfx_SetRenderParameter(DCGfx_RenderParameter,DCGfx_RenderSetting)");
}

// @SMALLTODO
void PCGfx_SetSkyColor(u32)
{
    printf("PCGfx_SetSkyColor(u32)");
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
