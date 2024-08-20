#pragma once

#ifndef PCTEX_H
#define PCTEX_H

#include "export.h"
#include "bitmap256.h"

// @FIXME
#define PCTexture i32
// @FIXME
#define _DDPIXELFORMAT i32

struct ClutPC
{
	ClutPC* mNext;
	u8 padAfter4[4];

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

// @FIXME
typedef void IDirectDrawSurface7;

struct SPCTexture
{
	u16 mSizeOne;
	u16 mSizeTwo;
	float wScale;
	float hScale;
	u8 padAfter8[0x14-0x8-4];

	Bitmap256* mTexture;
	i32 mAlpha;
	IDirectDrawSurface7* mD3DTex;
	i32 mFlags;
	u8 padAfterC[0x54-0x20-4];

	i32 mSplitCount;
	i32 *mSplit;
	unsigned char pad[0x68-0x58-4];
};

EXPORT void PCTex_SetTextureUserData(int, Bitmap256*);
EXPORT float PCTex_GetTextureWScale(int);
EXPORT float PCTex_GetTextureHScale(int);
EXPORT int PCTex_GetTextureFlags(int);
EXPORT int countBits(unsigned int);
EXPORT int countLeadingBits(unsigned int);
EXPORT int PCTex_GetTextureSplitID(int, int);

EXPORT u8 CheckValidTexture(u32);
EXPORT void ConvertPSXPaletteToPC(u16 const *,u16 *,u32,u32);
EXPORT void PCTEX_Init(void);
EXPORT void* PCTex_BufferPVR(const char *,char *);
EXPORT i32 PCTex_CountActiveTextures(void);
EXPORT void PCTex_CreateClut(i32);
EXPORT void PCTex_CreateTexture16(i32,i32,void const *,u16 const *,char const *,i32,i32,u32);
EXPORT void PCTex_CreateTexture256(i32,i32,void const *,u16 const *,u32,char const *,i32,i32);
EXPORT i32 PCTex_CreateTexturePVR(i32,i32,u32,void *,u32,const char *,u32);
EXPORT void PCTex_CreateTexturePVRInId(i32,i32,i32,u32,void const *,u32,char const *,u32);
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
EXPORT i32 PCTex_TextureHasAlpha(i32);
EXPORT void PCTex_UnbufferPVR(PVRHeader *);
EXPORT void PCTex_UnloadTextures(void);
EXPORT void PCTex_UpdateForSoftwareRenderer(void);
EXPORT ClutPC* clutToClutPc(const u16*);
EXPORT void copyBitmap(void const *,i32,void *,i32,i32,i32,i32);
EXPORT void copyConvertBitmap(void const *,i32,i32,void *,i32,i32,i32,i32,bool);
EXPORT void countLeadingZeroBits(u32);
EXPORT void downloadTexture(PCTexture *,u16 *,i32,i32);
EXPORT void enumPixelFormatsCB(_DDPIXELFORMAT *,void *);
EXPORT void releaseClutPc(ClutPC *);
EXPORT void shouldForceBlend(u16 *,i32,i32,i32);

void validate_SPCTexture(void);
void validate_PVRHeader(void);
void validate_ClutPC(void);

#endif
