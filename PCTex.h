#pragma once

#ifndef PCTEX_H
#define PCTEX_H

#include "export.h"
#include "bitmap256.h"
#include "non_win32.h"
#include "my_dx.h"

EXPORT extern u32 gMaxTextureAspectRatio;
EXPORT extern u32 gMaxTextureWidth;
EXPORT extern u32 gTextureHeight;

struct SPCTexContainer
{
	u8 padTop[4];

	i32 field_4;
	i32 field_8;
	i32 field_C;
	i32 field_10;

	i32 field_14;
	i32 field_18;
	i32 field_1C;
	i32 field_20;

	i32 field_24;
	i32 field_28;
	i32 field_2C;
	i32 field_30;
	i32 field_34;
	i32 field_38;
	i32 field_3C;
	i32 field_40;
	i32 field_44;
	i32 field_48;
};

struct SPCTexPixelFormat
{
	DDPIXELFORMAT ddpi;
};

struct ClutPC
{
	ClutPC* mNext;
	i16 mRefs;
	i16 mColorCount;
	u16* mClut;
};

struct PVRHeader
{
	u8 padTop[0x18];
	i32 field_18;
	u16 field_1C;
	u16 field_1E;
	u8 pTextureData;
};

struct SPCTexture
{
	u16 mSizeOne;
	u16 mSizeTwo;
	float mWScale;
	float mHScale;

	float field_C;
	float field_10;

	Bitmap256* mTexture;
	i32 mAlpha;
	IDirectDrawSurface7* mD3DTex;
	i32 mFlags;
	i32 field_24;


	char field_28[0x1F];
	i32 field_48;

	u8 padAfter48[4];

	i32 field_50;

	i32 mSplitCount;
	i32 *mSplit;

	const void* pTextureData;
	i32 field_60;
	i32 field_64;
};

EXPORT void PCTex_SetTextureUserData(int, Bitmap256*);
EXPORT float PCTex_GetTextureWScale(int);
EXPORT float PCTex_GetTextureHScale(int);
EXPORT int PCTex_GetTextureFlags(int);
EXPORT int countBits(unsigned int);
EXPORT int PCTex_GetTextureSplitID(int, int);

EXPORT u8 CheckValidTexture(u32);
EXPORT u8 ConvertPSXPaletteToPC(const u16 *,u16 *,u32,u32);
EXPORT void PCTEX_Init(void);
EXPORT void* PCTex_BufferPVR(const char *,char *);
EXPORT i32 PCTex_CountActiveTextures(void);
EXPORT u16* PCTex_CreateClut(i32);
EXPORT i32 PCTex_CreateTexture16(i32,i32,void const *,u16 const *,char const *,i32,i32,u32);
EXPORT i32 PCTex_CreateTexture256(i32,i32,const void *,const u16 *,u32,const char *,i32,i32);
EXPORT i32 PCTex_CreateTexturePVR(i32,i32,u32,void *,u32,const char *,u32);
EXPORT i32 PCTex_CreateTexturePVRInId(i32,i32,i32,u32, void *,u32, const char*,u32);
EXPORT i32 PCTex_FindUnusedTextureId(void);
EXPORT void PCTex_FreePcIcons(void);
EXPORT IDirectDrawSurface7* PCTex_GetDirect3DTexture(i32);
EXPORT void PCTex_GetInvTextureSize(i32,float *,float *);
EXPORT void PCTex_GetTextureSize(i32,i32 *,i32 *);
EXPORT i32 PCTex_GetTextureSplitCount(i32);
EXPORT void PCTex_InitSystemTextures(void);
EXPORT i32 PCTex_LoadLtiTexture(const char*,u32,i32,u32);
EXPORT void PCTex_LoadPcIcons(void);
EXPORT void* PCTex_LoadTexturePVR(const char*,char *);
EXPORT void PCTex_ReleaseAllTextures(void);
EXPORT void PCTex_ReleaseSysTexture(i32,bool);
EXPORT void PCTex_ReleaseTexture(i32,bool);
EXPORT void PCTex_ReloadTextures(void);
EXPORT u8 PCTex_TextureHasAlpha(i32);
EXPORT void PCTex_UnbufferPVR(PVRHeader *);
EXPORT void PCTex_UnloadTextures(void);
EXPORT void PCTex_UpdateForSoftwareRenderer(void);
EXPORT ClutPC* clutToClutPc(const u16*);
EXPORT void copyBitmap(void const *,i32,void *,i32,i32,i32,i32);
EXPORT void copyConvertBitmap(void const *,i32,i32,void *,i32,i32,i32,i32,bool);
EXPORT i32 countLeadingZeroBits(u32);
EXPORT void downloadTexture(SPCTexture *,u16 *,i32,i32);
EXPORT HRESULT CALLBACK enumPixelFormatsCB(LPDDPIXELFORMAT,void *);
EXPORT void releaseClutPc(ClutPC *);
EXPORT i32 shouldForceBlend(u16 *,i32,i32,i32);

void validate_SPCTexture(void);
void validate_PVRHeader(void);
void validate_ClutPC(void);
void validate_SPCTexPixelFormat(void);
void validate_SPCTexContainer(void);
void validate_DDPIXELFORMAT(void);
void validate_ConvertPSXPaletteToPC(void);

#endif
