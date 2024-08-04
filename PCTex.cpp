#include "PCTex.h"
#include "validate.h"

EXPORT WeirdTextureHolder gGlobalTextures[2];

// @SMALLTODO
void CheckValidTexture(i32)
{
    printf("CheckValidTexture(i32)");
}

// @MEDIUMTODO
void ConvertPSXPaletteToPC(u16 const *,u16 *,u32,u32)
{
    printf("ConvertPSXPaletteToPC(u16 const *,u16 *,u32,u32)");
}

// @MEDIUMTODO
void PCTEX_Init(void)
{
    printf("PCTEX_Init(void)");
}

// @SMALLTODO
void PCTex_BufferPVR(char const *,char *)
{
    printf("PCTex_BufferPVR(char const *,char *)");
}

// @SMALLTODO
void PCTex_CountActiveTextures(void)
{
    printf("PCTex_CountActiveTextures(void)");
}

// @SMALLTODO
void PCTex_CreateClut(i32)
{
    printf("PCTex_CreateClut(i32)");
}

// @MEDIUMTODO
void PCTex_CreateTexture16(i32,i32,void const *,u16 const *,char const *,i32,i32,u32)
{
    printf("PCTex_CreateTexture16(i32,i32,void const *,u16 const *,char const *,i32,i32,u32)");
}

// @MEDIUMTODO
void PCTex_CreateTexture256(i32,i32,void const *,u16 const *,u32,char const *,i32,i32)
{
    printf("PCTex_CreateTexture256(i32,i32,void const *,u16 const *,u32,char const *,i32,i32)");
}

// @SMALLTODO
void PCTex_CreateTexturePVR(i32,i32,u32,void const *,u32,char const *,u32)
{
    printf("PCTex_CreateTexturePVR(i32,i32,u32,void const *,u32,char const *,u32)");
}

// @MEDIUMTODO
void PCTex_CreateTexturePVRInId(i32,i32,i32,u32,void const *,u32,char const *,u32)
{
    printf("PCTex_CreateTexturePVRInId(i32,i32,i32,u32,void const *,u32,char const *,u32)");
}

// @SMALLTODO
void PCTex_FindUnusedTextureId(void)
{
    printf("PCTex_FindUnusedTextureId(void)");
}

// @SMALLTODO
void PCTex_FreePcIcons(void)
{
    printf("PCTex_FreePcIcons(void)");
}

// @SMALLTODO
void PCTex_GetDirect3DTexture(i32)
{
    printf("PCTex_GetDirect3DTexture(i32)");
}

// @SMALLTODO
void PCTex_GetInvTextureSize(i32,float *,float *)
{
    printf("PCTex_GetInvTextureSize(i32,float *,float *)");
}

// @SMALLTODO
void PCTex_GetTextureSize(i32,i32 *,i32 *)
{
    printf("PCTex_GetTextureSize(i32,i32 *,i32 *)");
}

// @SMALLTODO
void PCTex_GetTextureSplitCount(i32)
{
    printf("PCTex_GetTextureSplitCount(i32)");
}

// @SMALLTODO
void PCTex_InitSystemTextures(void)
{
    printf("PCTex_InitSystemTextures(void)");
}

// @MEDIUMTODO
void PCTex_LoadLtiTexture(char const *,u32,i32,u32)
{
    printf("PCTex_LoadLtiTexture(char const *,u32,i32,u32)");
}

// @SMALLTODO
void PCTex_LoadPcIcons(void)
{
    printf("PCTex_LoadPcIcons(void)");
}

// @SMALLTODO
void PCTex_LoadTexturePVR(char const *,char *)
{
    printf("PCTex_LoadTexturePVR(char const *,char *)");
}

// @SMALLTODO
void PCTex_ReleaseAllTextures(void)
{
    printf("PCTex_ReleaseAllTextures(void)");
}

// @SMALLTODO
void PCTex_ReleaseSysTexture(i32,bool)
{
    printf("PCTex_ReleaseSysTexture(i32,bool)");
}

// @SMALLTODO
void PCTex_ReleaseTexture(i32,bool)
{
    printf("PCTex_ReleaseTexture(i32,bool)");
}

// @MEDIUMTODO
void PCTex_ReloadTextures(void)
{
    printf("PCTex_ReloadTextures(void)");
}

// @SMALLTODO
void PCTex_TextureHasAlpha(i32)
{
    printf("PCTex_TextureHasAlpha(i32)");
}

// @SMALLTODO
void PCTex_UnbufferPVR(PVRHeader *)
{
    printf("PCTex_UnbufferPVR(PVRHeader *)");
}

// @SMALLTODO
void PCTex_UnloadTextures(void)
{
    printf("PCTex_UnloadTextures(void)");
}

// @SMALLTODO
void PCTex_UpdateForSoftwareRenderer(void)
{
    printf("PCTex_UpdateForSoftwareRenderer(void)");
}

// @SMALLTODO
void clutToClutPc(u16 const *)
{
    printf("clutToClutPc(u16 const *)");
}

// @SMALLTODO
void copyBitmap(void const *,i32,void *,i32,i32,i32,i32)
{
    printf("copyBitmap(void const *,i32,void *,i32,i32,i32,i32)");
}

// @MEDIUMTODO
void copyConvertBitmap(void const *,i32,i32,void *,i32,i32,i32,i32,bool)
{
    printf("copyConvertBitmap(void const *,i32,i32,void *,i32,i32,i32,i32,bool)");
}

// @SMALLTODO
void countLeadingZeroBits(u32)
{
    printf("countLeadingZeroBits(u32)");
}

// @MEDIUMTODO
void downloadTexture(PCTexture *,u16 *,i32,i32)
{
    printf("downloadTexture(PCTexture *,u16 *,i32,i32)");
}

// @SMALLTODO
void enumPixelFormatsCB(_DDPIXELFORMAT *,void *)
{
    printf("enumPixelFormatsCB(_DDPIXELFORMAT *,void *)");
}

// @SMALLTODO
void releaseClutPc(_ClutPC *)
{
    printf("releaseClutPc(_ClutPC *)");
}

// @SMALLTODO
void shouldForceBlend(u16 *,i32,i32,i32)
{
    printf("shouldForceBlend(u16 *,i32,i32,i32)");
}

// @NotOk
// globals
void PCTex_SetTextureUserData(int index, Bitmap256* texture)
{
	gGlobalTextures[index].texture = texture;
}

// @NotOk
// globals
float PCTex_GetTextureWScale(int index)
{
	return gGlobalTextures[index].wScale;
}

// @NotOk
// globals
float PCTex_GetTextureHScale(int index)
{
	return gGlobalTextures[index].hScale;
}

// @NotOk
// globals
int PCTex_GetTextureFlags(int index)
{
	return gGlobalTextures[index].flags;
}

// @Ok
int __inline countBits(unsigned int value)
{
	int bits = 0;

	while (value)
	{
		bits += value & 1;
		value >>= 1;
	}
	
	return bits;
}

// @Ok
int __inline countLeadingBits(unsigned int value)
{
	int bits = 0;

	if (!value)
		return 0;

	while(!(value & 1))
	{
		value >>= 1;
		bits++;
	}

	return bits;
}

// @NotOk
// Globals
int PCTex_GetTextureSplitID(int index, int id)
{
	return gGlobalTextures[index].split[id];
}

void validate_WeirdTextureHolder(void)
{
	VALIDATE_SIZE(WeirdTextureHolder, 0x68);

	VALIDATE(WeirdTextureHolder, texture, 0x0);
	VALIDATE(WeirdTextureHolder, wScale, 0x4);
	VALIDATE(WeirdTextureHolder, hScale, 0x8);
	VALIDATE(WeirdTextureHolder, flags, 0xC);
	VALIDATE(WeirdTextureHolder, split, 0x10);
}
