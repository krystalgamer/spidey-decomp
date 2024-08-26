#pragma once

#ifndef PCGFX_H
#define PCGFX_H

#include "ob.h"
#include "texture.h"
#include "export.h"

// @FIXME
#define _DXVERT i32
#define tagKMVERTEX3 i32
#define DCGfx_RenderParameter i32
#define DCGfx_RenderSetting i32
#define _tagKMSTRIPHEAD i32
#define DCGfx_BlendingMode i32

EXPORT void PCGfx_BeginScene(u32,i32);
EXPORT void PCGfx_ClipSendIndexedVertList(tagKMVERTEX3 const *,i32,u16 const *,i32);
EXPORT void PCGfx_ClipTriToNearPlane(_DXVERT **,_DXVERT *const *);
EXPORT void PCGfx_DoModelPreview(void);
EXPORT void PCGfx_DrawLine(float,float,float,u32,float,float,float,u32,float);
EXPORT void PCGfx_DrawQPoly2D(float,float,float,float,u32,float,float,float,float,u32,float,float,float,float,u32,float
,float,float,float,u32,float);
EXPORT void PCGfx_DrawQPoly3D(float,float,float,float,float,u32,float,float,float,float,float,u32,float,float,float,float,float,u32,float,float,float,float,float,u32);
EXPORT void PCGfx_DrawQuad2D(float,float,float,float,float,float,float,float,u32,float,bool);
EXPORT void PCGfx_DrawTPoly2D(float,float,float,float,u32,float,float,float,float,u32,float,float,float,float,u32,float);
EXPORT void PCGfx_DrawTPoly3D(float,float,float,float,float,u32,float,float,float,float,float,u32,float,float,float,float,float,u32);
EXPORT void PCGfx_DrawTexture2D(i32,i32,i32,float,u32,u32,float);
EXPORT void PCGfx_EndScene(i32);
EXPORT void PCGfx_Exit(void);
EXPORT void PCGfx_GetZLayerFurthest(void);
EXPORT void PCGfx_GetZLayerNearest(void);
EXPORT void PCGfx_IncZLayerFurthest(void);
EXPORT void PCGfx_IncZLayerNearest(void);
EXPORT void PCGfx_InitAtStart(void);
EXPORT u8 PCGfx_IsInScene(void);
EXPORT void PCGfx_ProcessTexture(_tagKMSTRIPHEAD *,i32,DCGfx_BlendingMode);
EXPORT void PCGfx_RenderInit(float,float,float,float,float);
EXPORT void PCGfx_RenderModelPreview(void *,char const *,i32);
EXPORT void PCGfx_SetBrightness(i32);
EXPORT void PCGfx_SetFogParams(float,float,u32);
EXPORT void PCGfx_SetRenderParameter(DCGfx_RenderParameter,DCGfx_RenderSetting);
EXPORT void PCGfx_SetSkyColor(u32);
EXPORT void PCGfx_UseTexture(i32,DCGfx_BlendingMode);
EXPORT void PCPanel_DrawTexturedPoly(float,Texture const *,i32,i32,i32,i32,u8);
EXPORT void ZCLIP_VERT(_DXVERT *,_DXVERT *,_DXVERT *,float);
EXPORT void createSuperItem(CItem *);
EXPORT void setupFog(void);
EXPORT void submitPoly(_DXVERT **,i32);

EXPORT extern u8 gSceneRelated;

#endif
