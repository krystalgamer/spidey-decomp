#pragma once

#ifndef PCGFX_H
#define PCGFX_H

#include "ob.h"
#include "texture.h"
#include "export.h"

enum DCGfx_RenderParameter
{
	DCGfx_RenderParameter_0  = 0,
	DCGfx_RenderParameter_1  = 1,
	DCGfx_RenderParameter_2  = 2,
	DCGfx_RenderParameter_3  = 3,
	DCGfx_RenderParameter_4  = 4,
};

enum DCGfx_RenderSetting
{
	DCGfx_RenderSetting_0  = 0x0,
	DCGfx_RenderSetting_1  = 0x1,
	DCGfx_RenderSetting_2  = 0x2,
	DCGfx_RenderSetting_3  = 0x3,
	DCGfx_RenderSetting_4  = 0x4,
	DCGfx_RenderSetting_5  = 0x5,
	DCGfx_RenderSetting_6  = 0x6,
	DCGfx_RenderSetting_7  = 0x7,
	DCGfx_RenderSetting_8  = 0x8,
	DCGfx_RenderSetting_9  = 0x9,
	DCGfx_RenderSetting_a  = 0xA,
	DCGfx_RenderSetting_b  = 0xB,
	DCGfx_RenderSetting_c  = 0xC,
	DCGfx_RenderSetting_d  = 0xD,
	DCGfx_RenderSetting_e  = 0xE,
	DCGfx_RenderSetting_MAX  = DCGfx_RenderSetting_e,
};

enum DCGfx_BlendingMode
{
	DCGfx_BlendingMode_0  = 0,
	DCGfx_BlendingMode_1  = 1,
	DCGfx_BlendingMode_2  = 2,
	DCGfx_BlendingMode_3  = 3,
	DCGfx_BlendingMode_4  = 4,
	DCGfx_BlendingMode_MAX  = DCGfx_BlendingMode_4,
};

// @FIXME
#define _DXVERT i32
#define tagKMVERTEX3 i32
#define _tagKMSTRIPHEAD i32

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
EXPORT float PCGfx_GetZLayerFurthest(void);
EXPORT float PCGfx_GetZLayerNearest(void);
EXPORT void PCGfx_IncZLayerFurthest(void);
EXPORT void PCGfx_IncZLayerNearest(void);
EXPORT void PCGfx_InitAtStart(void);
EXPORT u8 PCGfx_IsInScene(void);
EXPORT void PCGfx_ProcessTexture(_tagKMSTRIPHEAD *,i32,DCGfx_BlendingMode);
EXPORT void PCGfx_RenderInit(float,float,float);
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

EXPORT i32 STDCALL kmSetPALEXTCallback(void*, i32);
EXPORT i32 STDCALL kmSetDisplayMode(i32, i32, i32, i32);
EXPORT i32 STDCALL kmInitDevice(i32);

EXPORT extern u8 gSceneRelated;

#endif
