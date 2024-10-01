#include "PCGfx.h"
#include "PCTex.h"
#include "DXsound.h"
#include "SpideyDX.h"
#include "DXinit.h"
#include "camera.h"
#include "mess.h"
#include "ps2m3d.h"
#include "pshell.h"
#include "spool.h"
#include "ps2pad.h"
#include "PCInput.h"

#include <cmath>
#include <cstring>

EXPORT i8 gPcGfxBrightnessValues[256];

EXPORT u8 gProcessTextureRelated;
EXPORT u16 gChosenBlendingMode;
EXPORT u16 gProcessedTextureFlags;

EXPORT i32 gUseTextureRelated = 0x0FFFFFFFF;
EXPORT DCGfx_BlendingMode gTextureBlendingMode;

EXPORT i32 gPcGfxBlendModeRelated;
EXPORT DXPOLY gDxPolys[15360];

EXPORT float gRenderInitOne[3] = {  10.0f, 8048.0f, 276.0f };
EXPORT float gRenderInitTwo[2] = { 8038.0f, 1.9624f };

EXPORT i32 gPcGfxDrawRelated = 1;
EXPORT i32 gPcGfxSlotNumber =  0x0FFFFFFFF;

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

// @Ok
// @Validate
void PCGfx_DoModelPreview(void)
{
	i32 totalSomething = 0;
	CSuper* SuperItem = 0;
	CSuper* SuperItemNext = 0;
	u8 doModelSwap = 0;
	DWORD modelTickUpdate = 0;

	PShell_Initialise();
	i32 freeIndex = 0;
	for (; freeIndex < MAXPSX; freeIndex++)
	{
		if (!PSXRegion[freeIndex].Filename[0])
			break;
	}


	i32 v24[40];

	for (i32 j = 0; j < freeIndex; j++)
	{
		// @FIXME
		// remove
		break;

		i32 v8 = PSXRegion[j].pPSX[2];
		v24[j] = v8;
		totalSomething += v8;
	}

	//if (totalSomething && freeIndex)
	if (true)
	{
		PCGfx_SetSkyColor(0xFF800080);
		i32 idx = 0;

		i32 v9;
		for (v9 = 0; v9 < freeIndex; v9++)
		{
			//@FIXME
			break;
			if (v24[v9] > 0)
			{
				if (!PSXRegion[v9].IsSuper)
				{
					SuperItem = reinterpret_cast<CSuper*>(PSXRegion[v9].pSuper);
					SuperItemNext = reinterpret_cast<CSuper*>(SuperItem->field_20);
					SuperItem->field_20 = 0;
				}

				SuperItem = createSuperItem(PSXRegion[v9].pSuper);
			}
		}

		//@FIXME
		/*
		gMikeCamera[0].Position.vx = SuperItem->mPos.vx >> 12;
		gMikeCamera[0].Position.vy = SuperItem->mPos.vy >> 12;
		gMikeCamera[0].Position.vz = (SuperItem->mPos.vz >> 12) - 1;
		*/

		gMikeCamera[0].Angles.vx = 0;
		gMikeCamera[0].Angles.vy = 0;
		gMikeCamera[0].Angles.vz = 0;
		gMikeCamera[0].Style = 0;

		i32 stop = 0;
		while (!stop)
		{
			Pad_Update();
			if (gSControl[0].Left.Pressed)
			{
				gMikeCamera[0].Angles.vy -= 16;
				gMikeCamera[0].Angles.vy &= 0xFFF;
			}
			else if (gSControl[0].Right.Pressed)
			{
				gMikeCamera[0].Angles.vy -= 16;
				gMikeCamera[0].Angles.vy &= 0xFFF;
			}

			if (gSControl[0].Up.Pressed)
			{
				if (!PCINPUT_IsKeyPressed(0x42, 0) && !PCINPUT_IsKeyPressed(0x36, 0))
				{
					i32 v14 = gMikeCamera[0].Angles.vy & 0xFFF;
					gMikeCamera[0].Position.vx += (32 * rcossin_tbl[v14].sin) >> 12;
					gMikeCamera[0].Position.vz += (32 * rcossin_tbl[v14].cos) >> 12;
					gMikeCamera[0].Position.vy -= (32 * rcossin_tbl[gMikeCamera[0].Angles.vx & 0xFFF].sin) >> 12;
				}
				else
				{
					gMikeCamera[0].Angles.vx += 16;
					gMikeCamera[0].Angles.vx &= 0xFFF;
				}
			}
			else if (gSControl[0].Down.Pressed)
			{
				if (!PCINPUT_IsKeyPressed(0x2Au, 0) && !PCINPUT_IsKeyPressed(0x36u, 0))
				{
					 gMikeCamera[0].Angles.vx = (gMikeCamera[0].Angles.vx - 16) & 0xFFF;
				}
				else
				{
					i32 v15 = gMikeCamera[0].Angles.vy & 0xFFF;
					gMikeCamera[0].Position.vx -= (32 * rcossin_tbl[v15].sin) >> 12;
					gMikeCamera[0].Position.vy += (32 * rcossin_tbl[gMikeCamera[0].Angles.vx & 0xFFF].sin) >> 12;
					gMikeCamera[0].Position.vz -= (32 * rcossin_tbl[v15].cos) >> 12;
				}
			}

			if (GetTickCount() - modelTickUpdate > 250)
			{
				if (gSControl[0].Square.Pressed)
				{
					u8 IsSuper = PSXRegion[v9].IsSuper;
					if (idx && !IsSuper)
					{
						idx--;
					}
					else
					{
						do
						{
							if (--v9 < 0)
								v9 = freeIndex - 1;
						}
						while(v24[v9] <= 0);

						if (IsSuper)
							idx = 0;
						else
							idx = v24[v9] - 1;
					}

					doModelSwap = 1;
				}
				else if (gSControl[0].Circle.Pressed)
				{
					idx = (idx + 1) % v24[v9];
					if (!idx || PSXRegion[v9].IsSuper)
					{
						do
						{
							v9 = (v9 + 1) % freeIndex;
						}
						while (v24[v9] <= 0);
					}
					doModelSwap = 1;
				}
			}

			
			if (PCINPUT_IsKeyPressed(0x10, 0))
			{
				stop = 1;
			}
			else
			{
				// @FIXME
				/*
				if (doModelSwap)
				{
					if (PSXRegion[SuperItem->mRegion].IsSuper)
					{
						delete SuperItem;
					}
					else
					{
						SuperItem->field_20 = SuperItemNext;
					}

					if (PSXRegion[v9].IsSuper)
					{
						SuperItem = createSuperItem(&PSXRegion[v9].pSuper[idx]);
					}
					else
					{
						SuperItem = reinterpret_cast<CSuper*>(&PSXRegion[v9].pSuper[idx]);
						SuperItemNext = reinterpret_cast<CSuper*>(SuperItem->field_20);
						SuperItem->field_20 = 0;
					}

					gMikeCamera[0].Position.vx = SuperItem->mPos.vx >> 12;
					gMikeCamera[0].Position.vy = SuperItem->mPos.vy >> 12;
					gMikeCamera[0].Position.vz = (SuperItem->mPos.vz >> 12) - 1;

					gMikeCamera[0].Angles.vx = 0;
					gMikeCamera[0].Angles.vy = 0;
					gMikeCamera[0].Angles.vz = 0;

					modelTickUpdate = GetTickCount();
					doModelSwap = 0;
				}
				*/

				PCGfx_RenderModelPreview(SuperItem, PSXRegion[v9].Filename, idx);
			}
		}

		if (PSXRegion[v9].IsSuper)
		{
			delete SuperItem;
		}
		else
		{
			SuperItem->field_20 = SuperItemNext;
		}
	}
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

// @NotOk
// missing low graphics
// might be wrong too
void PCGfx_DrawQuad2D(
		float a1,
		float a2,
		float a3,
		float a4,
		float a5,
		float a6,
		float a7,
		float a8,
		u32 color,
		float a10,
		bool)
{
	gPcGfxDrawRelated &= 0xFFFFFFFB;

	if (a10 <= 6.0f)
		gPcGfxSlotNumber = a10;

	float v13 = a10;
	if (a10 < 0.0f)
		v13 = v13 * a10 + gRenderInitOne[1];
	else
		v13 = v13 * a10 + gRenderInitOne[0];

	float v24 = v13;
	print_if_false(v24 > 0.0f, "invalid zOffset!");

	SDXPolyField *pDxPolyFields[4];
	SDXPolyField dxPolyFields[4];

	dxPolyFields[0].field_18 = a6;
	dxPolyFields[0].field_4 = a2;
	dxPolyFields[1].field_4 = a2;
	dxPolyFields[0].field_10 = color;
	dxPolyFields[1].field_10 = color;
	dxPolyFields[2].field_10 = color;
	dxPolyFields[3].field_10 = color;
	dxPolyFields[0].field_0 = a1;
	dxPolyFields[0].field_14 = a5;
	dxPolyFields[3].field_0 = a1;
	dxPolyFields[3].field_14 = a5;
	pDxPolyFields[2] = &dxPolyFields[2];

	float v27 = (v24 - gRenderInitOne[0]) / gRenderInitTwo[0];
	dxPolyFields[0].field_8 = v27;
	dxPolyFields[1].field_8 = v27;
	dxPolyFields[2].field_8 = v27;
	dxPolyFields[3].field_8 = v27;

	pDxPolyFields[0] = dxPolyFields;
	pDxPolyFields[3] = &dxPolyFields[3];

	float v32 = gRenderInitOne[2] / v24;
	dxPolyFields[0].field_C = v32;
	dxPolyFields[1].field_C = v32;
	dxPolyFields[2].field_C = v32;
	dxPolyFields[3].field_C = v32;

	float v28 = a1 + a3;
	dxPolyFields[1].field_0 = v28;
	dxPolyFields[2].field_0 = v28;
	pDxPolyFields[1] = &dxPolyFields[1];

	float v25 = a5 + a7;
	dxPolyFields[1].field_14 = v25;
	dxPolyFields[1].field_18 = a6;
	dxPolyFields[2].field_14 = v25;

	float v29 = a2 + a4;
	dxPolyFields[2].field_4 = v29;
	dxPolyFields[3].field_4 = v29;

	float v30 = a6 + a8;
	dxPolyFields[2].field_18 = v30;
	dxPolyFields[3].field_18 = v30;

	if (gEndSceneRelatedTwo >= 15360)
	{
		gEndSceneRelatedTwo++;
		return;
	}

	float v26 = 0.0;
	DXPOLY* v16 = &gDxPolys[gEndSceneRelatedTwo++];
	i32 v31 = gPcGfxBlendModeRelated;

	if (gLowGraphics)
	{
		// @FIXME: TODO
	}
	else
	{
		LPDIRECTDRAWSURFACE7 Direct3DTexture;
		if (gUseTextureRelated < 0)
			Direct3DTexture = 0;
		else
			Direct3DTexture = PCTex_GetDirect3DTexture(gUseTextureRelated);
		v16->field_4 = Direct3DTexture;
		v16->mBlendMode = gChosenBlendingMode;
		v16->field_A = gProcessedTextureFlags;
		v16->field_C = 4;
		
		SDXPolyField **v21 = pDxPolyFields;
		SDXPolyField *v22 = v16->field_10;

		for (i32 i = 0; i < 4; i++)
		{
			memcpy(&v22[i], v21[i], sizeof(SDXPolyField));
			
			i32 v23;
			if (gProcessTextureRelated)
				v23 = 128;
			else
				v23 = (v22[i].field_10 >> 24) & 0xFF;

			v22[i].field_10 =
				gPcGfxBrightnessValues[v22[i].field_10 & 0xFF] |
				gPcGfxBrightnessValues[(v22[i].field_10 >> 8) & 0xFF] << 8 |
				gPcGfxBrightnessValues[(v22[i].field_10 >> 16) & 0xFF] << 16 |
				v23 << 24;

			if (v22[i].field_8 < 0.0f)
			{
				v22[i].field_8 = 0.0f;
			}
			else if (v22[i].field_8 > 0.99989998f)
			{
				v22[i].field_8 = 0.99989998f;
				v26 = v22[i].field_8;
			}
			else if (v26 < v22[i].field_8)
			{
				v26 = v22[i].field_8;
			}
		}
		if ( gChosenBlendingMode )
		{
			v31 = 0;
		}
	}

	DXPOLY_DrawPoly(v16, gPcGfxSlotNumber, v31, v26);
	gPcGfxSlotNumber = -1;
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
INLINE void PCGfx_EndScene(i32 a1)
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

// @NotOk
// third parameter of rendesetup seems to be useless but also DB related
void PCGfx_RenderModelPreview(
		void* a1,
		char const* a2,
		i32 a3)
{
	char v3[128];

	M3dMaths_RotMatrixYXZ(&gMikeCamera[0].Angles, &gMikeCamera[0].Transform);
	TransMatrix(&gMikeCamera[0].Transform, &gMikeCamera[0].Position);
	PCGfx_BeginScene(1u, -1);

	// @FIXME: third param seems to be ignored
	M3d_RenderSetup(&gMikeCamera[0], &gViewport, 0);
	M3d_Render(a1);
	M3d_RenderCleanup();
	Mess_SetSort(4095);
	PShell_SmallFont();
	Mess_SetRGB(0xFFu, 0xFFu, 0xFFu, 0);
	Mess_SetRGBBottom(0xFFu, 255, 255);
	Mess_SetShadowRGB(0xFFu);
	Mess_SetTextJustify(1);

	sprintf(v3, "PSX: %s", a2);
	Mess_DrawText(20, 20, v3, 0, 0x1000u);
	sprintf(v3, "IDX: %i", a3);
	Mess_DrawText(220, 20, v3, 0, 0x1000u);
	sprintf(v3, "CAM: %i %i %i", gMikeCamera[0].Position.vx, gMikeCamera[0].Position.vy, gMikeCamera[0].Position.vz);
	Mess_DrawText(20, 45, v3, 0, 0x1000u);

	CItem* pItem = static_cast<CItem*>(a1);
	// @FIXME
	sprintf(
		v3,
		"ITM: shit");
	/*
	sprintf(
		v3,
		"ITM: %i %i %i",
		pItem->mPos.vx >> 12,
		pItem->mPos.vy >> 12,
		pItem->mPos.vz >> 12);
		*/
	Mess_DrawText(220, 45, v3, 0, 0x1000u);

	PCGfx_EndScene(1);
}

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

// @Ok
// @Matching
void PCGfx_UseTexture(i32 a1, DCGfx_BlendingMode a2)
{
	i32 v2 = a1;
	if ( a1 <= 2 )
	{
		v2 = -1;
		gNonRendderSettingE = gIsRenderSettingE;
	}
	if ( gUseTextureRelated != v2 || gTextureBlendingMode != a2 )
	{
		gUseTextureRelated = v2;
		gTextureBlendingMode = a2;
		if (!gSceneRelated)
		{
			PCGfx_BeginScene(3u, -1);
		}
		PCGfx_ProcessTexture(0, v2, a2);
	}
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
CSuper* createSuperItem(CItem *)
{
    printf("createSuperItem(CItem *)");
	return (CSuper*)0x30092024;
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

// @Ok
i32 STDCALL kmSetPALEXTCallback(void*, i32)
{
	return 120;
}

// @Ok
i32 STDCALL kmSetDisplayMode(i32, i32, i32, i32)
{
	return 120;
}

// @Ok
i32 STDCALL kmInitDevice(i32)
{
	return 0;
}

// @Ok
i32 STDCALL kmSetWaitVsyncCount(i32)
{
	return 120;
}

// @Ok
i32 STDCALL kmUnloadDevice(void)
{
	return 120;
}
