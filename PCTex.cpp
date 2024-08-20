#include "PCTex.h"
#include "validate.h"
#include "mem.h"
#include "dcfileio.h"

#include <cstring>
#include <cstdlib>

const i32 GLOBAL_TEXTURE_COUNT = 1024;
EXPORT SPCTexture gGlobalTextures[GLOBAL_TEXTURE_COUNT];

const i32 PC_ICON_COUNT = 5;
EXPORT i32 gPcIcons[PC_ICON_COUNT];
EXPORT const char *gPcIconNames[PC_ICON_COUNT] =
{
	"lti\\butlarrow.bmp",
	"lti\\butrarrow.bmp",
	"lti\\butesc.bmp",
	"lti\\butplus.bmp",
	"lti\\butminus.bmp",
};

EXPORT ClutPC* gClutPcRelated;
EXPORT i32 gClutCount;

// @Ok
u8 CheckValidTexture(u32 index)
{
	if (index < GLOBAL_TEXTURE_COUNT)
	{
		if (gGlobalTextures[index].mD3DTex || gGlobalTextures[index].mSplit)
			return 1;
	}

	return 0;
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

// @Ok
// @Matching
void* PCTex_BufferPVR(const char * a1, char * a2)
{
	char nameBuf[128];

	const char* fileName = a1;
	if (!strchr(a1, '.'))
	{
		strcpy(nameBuf, a1);
		strcat(nameBuf, ".pvr");
		fileName = nameBuf;
	}

	i32* buf = reinterpret_cast<i32*>(a2);
	if (!buf)
	{
		i32 size = FileIO_Open(fileName);
		if (size <= 0)
		{
			print_if_false(0, "Can't find texture file!");
			return 0;
		}

		buf = static_cast<i32*>(DCMem_New(size, 0, 1, 0, 1));
		print_if_false(buf != 0, "out of memory");

		FileIO_Load(buf);
		FileIO_Sync();
	}

	print_if_false(buf[4] == 0x54525650, "corrupted PVR file");
	return buf;
}

// @Ok
// @Matching
i32 PCTex_CountActiveTextures(void)
{
	i32 count = 0;
	for (i32 id = 8;
			id < GLOBAL_TEXTURE_COUNT;
			id++)
	{
		if (gGlobalTextures[id].mD3DTex || gGlobalTextures[id].mSplit)
		{
			count++;
		}
	}

	return count;
}

// @Ok
// @Matching
u16* PCTex_CreateClut(i32 colorCount)
{
	ClutPC* clut = static_cast<ClutPC*>(malloc(sizeof(ClutPC)));

	print_if_false(colorCount == 16 || colorCount == 256, "Weird color count in CreateClut: %i", colorCount);

	if (!clut)
	{
		error("Out of memory allocating ClutPC!");
		return 0;
	}

	clut->mRefs = 0;
	clut->mColorCount = colorCount;
	clut->mClut = static_cast<u16*>(malloc(2 * colorCount));

	if (!clut->mClut)
	{
		error("Out of memory allocating ClutPC colors!");
		free(clut);
		return 0;
	}

	clut->mNext = gClutPcRelated;
	gClutPcRelated = clut;
	gClutCount++;
	
	return clut->mClut;
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

// @Ok
i32 PCTex_CreateTexturePVR(
		i32 a1,
		i32 a2,
		u32 a3,
		void* pData,
		u32 a5,
		const char* a6,
		u32 a7)
{
	 print_if_false(
			 (reinterpret_cast<i32>(pData) & 3) == 0,
			 "texture data pointer must be aligned to 4 byte boundary");
	 
	 i32 unusedId = PCTex_FindUnusedTextureId();
	 i32 res = PCTex_CreateTexturePVRInId(
			 unusedId,
			 a1,
			 a2,
			 a3,
			 pData,
			 a5,
			 a6,
			 a7);
	 if (!res)
		 return -1;

	gGlobalTextures[unusedId].pTextureData = pData;
	gGlobalTextures[unusedId].field_60 = a3;
	gGlobalTextures[unusedId].field_64 = 0x10000;
	 
	 return unusedId;
}

// @MEDIUMTODO
i32 PCTex_CreateTexturePVRInId(i32,i32,i32,u32,const void* ,u32,char const *,u32)
{
    printf("PCTex_CreateTexturePVRInId(i32,i32,i32,u32,void const *,u32,char const *,u32)");
	return 0x20082024;
}

// @Ok
INLINE i32 PCTex_FindUnusedTextureId(void)
{
	i32 id = 8;
	for (;
			id < GLOBAL_TEXTURE_COUNT;
			id++)
	{
		if (!gGlobalTextures[id].mD3DTex && !gGlobalTextures[id].mSplit)
			break;
	}

	if (id >= GLOBAL_TEXTURE_COUNT)
	{
		error("out of texture handles.");
	}

	print_if_false(1u, "id must fit into 10 bits!");
	return id;
}

// @Ok
// @Matching
void PCTex_FreePcIcons(void)
{
	for (i32 i = 0; i < PC_ICON_COUNT; i++)
	{
		if (gPcIcons[i] != -1)
		{
			PCTex_ReleaseSysTexture(gPcIcons[i], true);
			gPcIcons[i] = -1;
		}
	}
}

// @Ok
IDirectDrawSurface7* PCTex_GetDirect3DTexture(i32 index)
{
	return gGlobalTextures[index].mD3DTex;
}

// @Ok
void PCTex_GetInvTextureSize(i32 index, float* pF1 ,float * pF2)
{
	*pF1 = gGlobalTextures[index].field_C;
	*pF2 = gGlobalTextures[index].field_10;
}

// @Ok
void PCTex_GetTextureSize(
		i32 index,
		i32* pOne,
		i32* pTwo)
{
	*pOne = gGlobalTextures[index].mSizeOne;
	*pTwo = gGlobalTextures[index].mSizeTwo;
}

// @Ok
i32 PCTex_GetTextureSplitCount(i32 index)
{
	return gGlobalTextures[index].mSplitCount;
}

// @SMALLTODO
void PCTex_InitSystemTextures(void)
{
    printf("PCTex_InitSystemTextures(void)");
}

// @MEDIUMTODO
i32 PCTex_LoadLtiTexture(const char*,u32,i32,u32)
{
    printf("PCTex_LoadLtiTexture(char const *,u32,i32,u32)");
	return 0x20082024;
}

// @Ok
void PCTex_LoadPcIcons(void)
{
	for (i32 i = 0;
			i < PC_ICON_COUNT;
			i++)
	{
		if (gPcIcons[i] == -1)
		{
			i32 tex = PCTex_LoadLtiTexture(gPcIconNames[i], 0, i+3, 1);
			gPcIcons[i] = tex;
			print_if_false(tex != -1, "Error loading icon tex: %s\r\n", gPcIconNames[i]);
		}
	}
}

// @Ok
void* PCTex_LoadTexturePVR(const char* a1, char* a2)
{
	PVRHeader* pHeader = static_cast<PVRHeader*>(PCTex_BufferPVR(a1, a2));
	i32 texRes = PCTex_CreateTexturePVR(
			pHeader->field_1C,
			pHeader->field_1E,
			pHeader->field_18,
			&pHeader->pTextureData,
			0,
			a1,
			0);

	print_if_false(texRes != -1, "texture cannot be smallvq: %s", a1);
	if (!a2)
		PCTex_UnbufferPVR(pHeader);

	return reinterpret_cast<void*>(texRes);
}

// @Ok
void PCTex_ReleaseAllTextures(void)
{
	for (i32 i = 8;
			i < GLOBAL_TEXTURE_COUNT;
			i++)
	{
		if (gGlobalTextures[i].mD3DTex || gGlobalTextures[i].mSplit)
		{
			PCTex_ReleaseTexture(i, true);
		}
	}

	while (gClutPcRelated)
	{
		releaseClutPc(gClutPcRelated);
	}
}

// @SMALLTODO
void PCTex_ReleaseSysTexture(i32,bool)
{
    printf("PCTex_ReleaseSysTexture(i32,bool)");
}

// @Ok
// @Matching
void PCTex_ReleaseTexture(i32 index, bool a2)
{
	if (index >= 8)
	{
		delete gGlobalTextures[index].mTexture;
		gGlobalTextures[index].mTexture = 0;
		PCTex_ReleaseSysTexture(index, a2);
	}
}

// @MEDIUMTODO
void PCTex_ReloadTextures(void)
{
    printf("PCTex_ReloadTextures(void)");
}

// @Ok
// @Matching
i32 PCTex_TextureHasAlpha(i32 index)
{
	return gGlobalTextures[index].mAlpha & 1;
}

// @Ok
// @Matching
void PCTex_UnbufferPVR(PVRHeader* pPvrHeader)
{
	Mem_Delete(pPvrHeader);
}

// @Ok
// @Matching
void PCTex_UnloadTextures(void)
{
	PCTex_FreePcIcons();

	for (i32 index = 8;
			index < GLOBAL_TEXTURE_COUNT;
			index++)
	{
		if (gGlobalTextures[index].mD3DTex || gGlobalTextures[index].mSplit)
		{
			if (gGlobalTextures[index].mFlags & 0x2000)
			{
				PCTex_ReleaseSysTexture(index, true);
			}
			else
			{
				PCTex_ReleaseSysTexture(index, false);
				gGlobalTextures[index].mFlags |= 0x8000;
			}
		}
	}
}

// @SMALLTODO
void PCTex_UpdateForSoftwareRenderer(void)
{
    printf("PCTex_UpdateForSoftwareRenderer(void)");
}

// @Ok
// @Matching
ClutPC* clutToClutPc(const u16* pClut)
{
	ClutPC* res = gClutPcRelated;
	for (;
			res;
			res = res->mNext)
	{
		if (res->mClut == pClut)
			break;
	}

	return res;
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

// @Ok
INLINE i32 countLeadingZeroBits(u32 num)
{
	if (!num)
		return 0;

	i32 count = 0;
	while (!(num & 1))
	{
		num >>= 1;
		count++;
	}

	return count;
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

// @Ok
// @Matching
void releaseClutPc(ClutPC* pClut)
{
	print_if_false(pClut->mRefs == 0, "Releasing a clut with pending references!");
	print_if_false(gClutCount > 0, "Uh oh, clut count is off!");

	if (pClut->mClut)
		free(pClut->mClut);

	if (pClut == gClutPcRelated)
	{
		gClutPcRelated = gClutPcRelated->mNext;
	}
	else
	{
		for (ClutPC* iter = gClutPcRelated;
				iter;
				iter = iter->mNext)
		{
			if (iter->mNext == pClut)
			{
				iter->mNext = pClut->mNext;
				break;
			}
		}
	}

	free(pClut);
	gClutCount--;
}

// @SMALLTODO
void shouldForceBlend(u16 *,i32,i32,i32)
{
    printf("shouldForceBlend(u16 *,i32,i32,i32)");
}

// @Ok
void PCTex_SetTextureUserData(int index, Bitmap256* texture)
{
	gGlobalTextures[index].mTexture = texture;
}

// @Ok
float PCTex_GetTextureWScale(int index)
{
	return gGlobalTextures[index].wScale;
}

// @Ok
float PCTex_GetTextureHScale(int index)
{
	return gGlobalTextures[index].hScale;
}

// @Ok
int PCTex_GetTextureFlags(int index)
{
	return gGlobalTextures[index].mFlags;
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
// @Matching
int PCTex_GetTextureSplitID(int index, int id)
{
	return gGlobalTextures[index].mSplit[id];
}

void validate_SPCTexture(void)
{
	VALIDATE_SIZE(SPCTexture, 0x68);

	VALIDATE(SPCTexture, mSizeOne, 0x0);
	VALIDATE(SPCTexture, mSizeTwo, 0x2);

	VALIDATE(SPCTexture, wScale, 0x4);
	VALIDATE(SPCTexture, hScale, 0x8);

	VALIDATE(SPCTexture, field_C, 0xC);
	VALIDATE(SPCTexture, field_10, 0x10);

	VALIDATE(SPCTexture, mTexture, 0x14);
	VALIDATE(SPCTexture, mAlpha, 0x18);
	VALIDATE(SPCTexture, mD3DTex, 0x1C);
	VALIDATE(SPCTexture, mFlags, 0x20);
	VALIDATE(SPCTexture, mSplitCount, 0x54);
	VALIDATE(SPCTexture, mSplit, 0x58);

	VALIDATE(SPCTexture, pTextureData, 0x5C);
	VALIDATE(SPCTexture, field_60, 0x60);
	VALIDATE(SPCTexture, field_64, 0x64);
}

void validate_PVRHeader(void)
{
	VALIDATE_SIZE(PVRHeader, 0x24);

	VALIDATE(PVRHeader, field_18, 0x18);
	VALIDATE(PVRHeader, field_1C, 0x1C);
	VALIDATE(PVRHeader, field_1E, 0x1E);
	VALIDATE(PVRHeader, pTextureData, 0x20);
}

void validate_ClutPC(void)
{
	VALIDATE_SIZE(ClutPC, 0xC);

	VALIDATE(ClutPC, mNext, 0x0);
	VALIDATE(ClutPC, mRefs, 0x4);
	VALIDATE(ClutPC, mColorCount, 0x6);
	VALIDATE(ClutPC, mClut, 0x8);
}
