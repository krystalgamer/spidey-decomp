#include "PCTex.h"
#include "validate.h"
#include "mem.h"
#include "dcfileio.h"
#include "DXinit.h"
#include "SpideyDX.h"

#include <cstring>
#include <cstdlib>
#include <cstdio>

EXPORT i32 gPvrCountRelated;
EXPORT i32 gPvrRelatedWidth;

EXPORT ClutPC* gCreateTextureClut;
EXPORT i32 gCreateTextureArr[39] =
{
  -1283256577,
  172113780,
  1137591542,
  2142391957,
  -1445641424,
  695236112,
  -1129278197,
  1539171391,
  479795307,
  1987673227,
  1785598936,
  1045875925,
  931998923,
  -1221702477,
  1581433793,
  427335541,
  492540533,
  611311190,
  -1097055801,
  1123433078,
  2009228913,
  -1973573692,
  -1103077669,
  1811270644,
  -483570628,
  -1054392008,
  -564620039,
  1889915007,
  -1038898882,
  982550557,
  959634683,
  -1905232968,
  -460927954,
  -1696182241,
  885363113,
  1138070148,
  -522681294,
  -1169312655,
  -465978652
};

EXPORT i32 gPcTexPvrAndSoftRendererRelated;
const i32 NUM_PCTEX_CONTAINERS = 5;

u8 gPcTexContainerData[0x17C] =
{
  0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 
  0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 
  0x05, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0A, 0x00, 
  0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
  0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 
  0x0C, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x04, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 
  0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0B, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 
  0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 
  0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 
  0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x10, 0x00, 
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 
  0x06, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x0F, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 
  0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

SPCTexContainer * const gPcTexContainer = reinterpret_cast<SPCTexContainer*>(&gPcTexContainerData[0]);

EXPORT i32 gNumPixelFormats;

u32 gMaxTextureAspectRatio;
u32 gMaxTextureWidth;
u32 gTextureHeight;

EXPORT bool gSquareOnly;

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
INLINE u8 CheckValidTexture(u32 index)
{
	if (index < GLOBAL_TEXTURE_COUNT)
	{
		if (gGlobalTextures[index].mD3DTex || gGlobalTextures[index].mSplit)
			return 1;
	}

	return 0;
}

// @Ok
// @Matching: by testing
u8 ConvertPSXPaletteToPC(const u16* a1,
		u16* a2,
		u32 a3,
		u32 a4)
{
	if (a4 & 0x10)
	{
		u8 v4 = 0;
		for (u32 i = 0; i < a3; ++i )
		{
			if ( a1[i] && a1[i] == 0x8000 )
			v4 = 1;
		}

		if ( v4 )
		{
			for (u32 j = 0; j < a3; ++j )
			{
				u32 v7 = j;
				u32 v8 = a1[j];
				a2[v7] = ((i32)(u8)(((i32)(v8 & 0x7C00) >> 7) | ((i32)(v8 & 0x7000) >> 12)) >> 3) | (4 * (((i32)(v8 & 0x3E0) >> 2) | ((i32)(v8 & 0x380) >> 7))) & 0x3E0 | (((u8)((-(u8)v8 | (u8)v8) >> 31) << 8) & 0x8000 | (((8 * (u16)v8) & 0xF8 | (v8 >> 2) & 7) << 7) & 0x7C00) & 0xFC1F;
			}

			return 1;
		}
		else
		{
			for (u32 k = 0; k < a3; ++k )
			{
				u32 v11 = k;
				u32 v12 = a1[k];
				a2[v11] = ((i32)(u8)(((i32)(v12 & 0x7C00) >> 7) | ((i32)(v12 & 0x7000) >> 12)) >> 3) | (((8 * (u16)v12) & 0xF8 | ((i32)(v12 & 0x1C) >> 2) & 0xFF07) << 8) & 0xF800 | (8 * ((v12 >> 7) & 7 | ((i32)(v12 & 0x3E0) >> 2) & 0xFFF8)) & 0x7E0;
			}

			return 0;
		}
	}
	else
	{
		u32 v13 = a3;
		u8 v14 = 0;
		u8 v15 = 1;
		while ( (--v13 & 0x80000000) == 0 )
		{
			if ( (a1[v13] & 0x8000) != 0 )
				v14 = 1;
			else
				v15 = 0;
		}
		if ( v14 && !v15 && (a4 & 1) != 0 )
		{
			u32 v19;
			for (u32 l = a3;
			(--l & 0x80000000) == 0;
			a2[l] = ((i32)(u8)(((i32)(v19 & 0x7C00) >> 7) | ((i32)(v19 & 0x7000) >> 12)) >> 3) | (4 * (((i32)(v19 & 0x3E0) >> 2) | ((i32)(v19 & 0x380) >> 7))) & 0x3E0 | (((u8)((i32)(-v19 | v19) >> 31) << 8) & 0x8000 | (((8 * (u16)v19) & 0xF8 | (v19 >> 2) & 7) << 7) & 0x7C00) & 0xFC1F )
			{
				v19 = a1[l];
			}

			return 1;
		}
		else
		{
			u32 v17;
			for (u32 m = a3;
			(--m & 0x80000000) == 0;
			a2[m] = ((i32)(u32)(((i32)(v17 & 0x7C00) >> 7) | ((i32)(v17 & 0x7000) >> 12)) >> 3) | (((8 * (u16)v17) & 0xF8 | ((i32)(v17 & 0x1C) >> 2) & 0xFF07) << 8) & 0xF800 | (8 * ((v17 >> 7) & 7 | ((i32)(v17 & 0x3E0) >> 2) & 0xFFF8)) & 0x7E0 )
			{
				v17 = a1[m];
			}

			return 0;
		}
	}
}

// @Ok
// @AlmostMatching: super close, the ordering of the bit count is slightly off, but generally it's awesome
void PCTEX_Init(void)
{
	for (i32 i = 0; i < NUM_PCTEX_CONTAINERS; i++)
	{
		if (!i)
			gPcTexContainer[i].field_28 = 2;
		else
			gPcTexContainer[i].field_28 = 0;
	}
	gNumPixelFormats = 0;

#ifdef _WIN32
	DDPIXELFORMAT v36[16];
	g_D3DDevice7->EnumTextureFormats(enumPixelFormatsCB, v36);

	//DXERR_printf("Got %d pixel formats\n", gNumPixelFormats);
	for (i32 j = 0; j < gNumPixelFormats; j++)
	{
		if (v36[j].dwFlags & DDPF_RGB)
		{
			i32 rgbBitCount = countBits(v36[j].dwRBitMask);
			i32 rBitCount = countBits(v36[j].dwGBitMask);
			i32 gBitCount = countBits(v36[j].dwBBitMask);
			i32 bBitCount = countBits(v36[j].dwRGBAlphaBitMask);

			i32 rgbLeadingBitCount = countLeadingZeroBits(v36[j].dwRBitMask);
			i32 rLeadingBitCount = countLeadingZeroBits(v36[j].dwGBitMask);
			i32 gLeadingBitCount = countLeadingZeroBits(v36[j].dwBBitMask);
			i32 bLeadingBitCount = countLeadingZeroBits(v36[j].dwRGBAlphaBitMask);

			for (
					i32 containerIndex = 0;
					containerIndex < NUM_PCTEX_CONTAINERS;
					containerIndex++)
			{
				/*
				if (containerIndex == 0)
				{
					DXERR_printf("PCTEX LOOP: %d\n", j);
					DXERR_printf("field_4 == %d, %d", bBitCount == gPcTexContainer[containerIndex].field_4, bBitCount);
					DXERR_printf("field_8 == %d, %d", rgbBitCount == gPcTexContainer[containerIndex].field_8, rgbBitCount);
				}
				*/

				if ( bBitCount == gPcTexContainer[containerIndex].field_8
					&& rgbBitCount == gPcTexContainer[containerIndex].field_C
					&& rBitCount == gPcTexContainer[containerIndex].field_10
					&& gBitCount == gPcTexContainer[containerIndex].field_14
					&& bLeadingBitCount == gPcTexContainer[containerIndex].field_18
					&& rgbLeadingBitCount == gPcTexContainer[containerIndex].field_1C
					&& rLeadingBitCount == gPcTexContainer[containerIndex].field_20
					&& gLeadingBitCount == gPcTexContainer[containerIndex].field_24)
				{
					gPcTexContainer[containerIndex].field_28 |= 4;
					memcpy(
							&gPcTexContainer[containerIndex].field_2C,
							&v36[j],
							sizeof(DDPIXELFORMAT));
				}
			}
		}
	}
#endif

	if (gLowGraphics)
	{
		gPcTexContainer[0].field_28 |= 1;
		if ((gPcTexContainer[0].field_28 & 4) == 0)
		{
			gPcTexContainer[0].field_2C = 32;
			gPcTexContainer[0].field_30 = 65;
			gPcTexContainer[0].field_34 = 0;
			gPcTexContainer[0].field_38 = 16;
			gPcTexContainer[0].field_3C = 31744;
			gPcTexContainer[0].field_40 = 992;
			gPcTexContainer[0].field_44 = 31;
			gPcTexContainer[0].field_48 = 0x8000;
		}
	}
	else
	{
		for (i32 k = 0; k < NUM_PCTEX_CONTAINERS; k++)
		{
			if (gPcTexContainer[k].field_28 & 4)
			{
				gPcTexContainer[k].field_28 |= 1;
			}
			else
			{
				gPcTexContainer[k].field_28 &= ~1;
			}
		}
	}

	if ( (gPcTexContainer[0].field_28 & 1) != 0 )
	{
		gPcTexPvrAndSoftRendererRelated = 0;
	}
	else if ( (gPcTexContainer[4].field_28 & 1) != 0 )
	{
		gPcTexPvrAndSoftRendererRelated = 4;
	}
	else if ( (gPcTexContainer[1].field_28 & 1) != 0 )
	{
		gPcTexPvrAndSoftRendererRelated = 1;
	}
	else
	{
		MessageBeep(0xFFFFFFFF);
		error("D3DTEX: Did not find acceptable 16-bit Alpha format\r\n");

		i32 index;

		for (index = 0; index < NUM_PCTEX_CONTAINERS; index++)
		{
			if (gPcTexContainer[index].field_28 & 1)
				break;
		}

		if (index < 5)
		{
			printf_fancy(
				"  Using alternate format: ARGB %i,%i,%i,%i\r\n",
					gPcTexContainer[index].field_8,
					gPcTexContainer[index].field_C,
					gPcTexContainer[index].field_10,
					gPcTexContainer[index].field_14);

			gPcTexPvrAndSoftRendererRelated = index;
			return;
		}

		error("  NONE OF OUR FORMATS ARE SUPPORTED!  CAN'T RUN THE GAME!\r\n");
		exit(1);
	}
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
i32 PCTex_CreateTexture16(i32,i32,void const *,u16 const *,char const *,i32,i32,u32)
{
    printf("PCTex_CreateTexture16(i32,i32,void const *,u16 const *,char const *,i32,i32,u32)");
	return 0x31082024;
}

// @MEDIUMTODO
i32 PCTex_CreateTexture256(
		i32 a1,
		i32 a2,
		const void* a3,
		const u16* a4,
		u32 a5,
		const char* a6,
		i32 a7,
		i32 a8)
{
	if (a1 <= 0 || a2 <= 0)
		return 0;

	i32 rounded_width;
	if (a1 <= 8)
	{
		rounded_width = 8;
	}
	else if (a1 <= 16)
	{
		rounded_width = 16;
	}
	else if (a1 <= 32)
	{
		rounded_width = 32;
	}
	else if (a1 <= 64)
	{
		rounded_width = 64;
	}
	else if (a1 <= 128)
	{
		rounded_width = 128;
	}
	else if (a1 <= 256)
	{
		rounded_width = 256;
	}
	else if (a1 <= 512)
	{
		rounded_width = 512;
	}
	else
	{
		rounded_width = 1024;
	}

	i32 rounded_height;
	if (a2 <= 8)
	{
		rounded_height = 8;
	}
	else if (a2 <= 16)
	{
		rounded_height = 16;
	}
	else if (a2 <= 32)
	{
		rounded_height = 32;
	}
	else if (a2 <= 64)
	{
		rounded_height = 64;
	}
	else if (a2 <= 128)
	{
		rounded_height = 128;
	}
	else if (a2 <= 256)
	{
		rounded_height = 256;
	}
	else if (a2 <= 512)
	{
		rounded_height = 512;
	}
	else
	{
		rounded_height = 1024;
	}

	if (gSquareOnly)
	{
		if (rounded_width > rounded_height)
		{
			rounded_height = rounded_width;
		}
		else
		{
			rounded_width = rounded_height;
		}
	}

	i32 aspectRatio;
	if (rounded_width > rounded_height)
	{
		aspectRatio = rounded_width / rounded_height;
	}
	else
	{
		aspectRatio = rounded_height / rounded_width;
	}

	if (gMaxTextureAspectRatio && aspectRatio > gMaxTextureAspectRatio)
	{
		if (rounded_width > rounded_height)
		{
			rounded_width = rounded_height * gMaxTextureAspectRatio;
			if (rounded_width < a1)
				rounded_width = a1;
		}
		else
		{
			rounded_height = rounded_width * gMaxTextureAspectRatio;
			if (rounded_height < a2)
				rounded_height = a2;
		}
	}

	u16* pBmpBuf = static_cast<u16*>(DCMem_New(
			2 * rounded_width * rounded_height,
			0,
			1,
			0,
			1));
	print_if_false(pBmpBuf != 0, "Out of system memory.");

	if (a1 != rounded_width || a2 != rounded_height)
		memset(
				pBmpBuf,
				0,
				2 * rounded_width * rounded_height);


	ClutPC* pClut;
	if (!a4)
	{
		pClut = gClutPcRelated;
		print_if_false(pClut != 0, "no palette!");
	}
	else
	{
		pClut = clutToClutPc(a4);
		a4 = pClut->mClut;
	}

	for (i32 i = 0; i < 0x27; i++)
	{
		if (gCreateTextureArr[i] == a8)
		{
			a5 &= 0xFFFFFFFE;
			break;
		}
	}

	u16 v46[256];
	i32 v45 = ConvertPSXPaletteToPC(a4, v46, 0x100, a5);

	for (i32 y = 0; y < a2; y++)
	{
		for (i32 x = 0; x < a1; x++)
		{
			pBmpBuf[x + y * rounded_width] = v46[
				reinterpret_cast<const u8*>(a3)[x + y * a1]];
		}
	}

	i32 textureHandleIndex;
	if (!a7)
	{
		textureHandleIndex = PCTex_CreateTexturePVR(
			rounded_width,
			rounded_height,
			(v45 == 0 ? 1 : 0) | 0x900,
			pBmpBuf,
			1u,
			a6,
			a8);
		print_if_false(textureHandleIndex != -1, "Ouch %s", a6);
	}
	else
	{
		if (CheckValidTexture(a7))
			PCTex_ReleaseSysTexture(a7, 0);

		i32 res = PCTex_CreateTexturePVRInId(
				a7,
				rounded_width,
				rounded_height,
				(v45 == 0 ? 1 : 0) | 0x900,
				pBmpBuf,
				1u,
				a6,
				a8);

		print_if_false(res != 0, "Ouch %s", a6);
		textureHandleIndex = a7;
	}

	SPCTexture* v34 = &gGlobalTextures[textureHandleIndex];
	v34->mSizeOne = a1;
	v34->mSizeTwo = a2;
	v34->field_60 = (int)a4;

	f32 v40 = (f32)(u16)a1;
	f32 v38 = (f32)rounded_width;
	// @FIXME
	v34->pTextureData = const_cast<void*>(a3);
	v34->field_64 = 256;
	v34->mWScale = v40 / v38;
	f32 v41 = (f32)(u16)a2;
	f32 v43 = (f32)rounded_height;

	v34->mHScale = v41 / v43;
	if (pClut)
	{
		print_if_false(pClut->mColorCount == 256, "Clut has wrong color count!");
		++pClut->mRefs;
		gCreateTextureClut = pClut;
	}

	return textureHandleIndex;
}

// @Ok
INLINE i32 PCTex_CreateTexturePVR(
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

	if (res)
	{
		gGlobalTextures[unusedId].pTextureData = pData;
		gGlobalTextures[unusedId].field_60 = a3;
		gGlobalTextures[unusedId].field_64 = 0x10000;

		return unusedId;
	}

	 return -1;
}

// @NotOk
// Missing low graphics and other sliced stuff
i32 PCTex_CreateTexturePVRInId(
		i32 a1,
		i32 a2,
		i32 a3,
		u32 a4,
		void* a5,
		u32 a6,
		const char * a7,
		u32 a8)
{
	void *v83 = a5;
	print_if_false( (a2 & (a2 - 1)) == 0 && a2 &&
			(a3 & (a3 - 1)) == 0 && a3, "texture size must be powers of 2");

	if (a4 & 0x1000)
		return 0;

	print_if_false(!gGlobalTextures[a1].mD3DTex && !gGlobalTextures[a1].mSplit, "texture slot already used");

	gGlobalTextures[a1].mHScale = 1.0f;
	gGlobalTextures[a1].mWScale = 1.0f;
	gGlobalTextures[a1].mSizeOne = a2;
	gGlobalTextures[a1].mSizeTwo = a3;
	gGlobalTextures[a1].mFlags = a6;
	gGlobalTextures[a1].mTexture = 0;
	gGlobalTextures[a1].field_C = 1.0f / (f32)a2;
	gGlobalTextures[a1].field_10 = 1.0f / (f32)a3;

	char v13 = 0;
	if (!a4 || a4 == 2 || a4 == 7)
		v13 = 1;

	gGlobalTextures[a1].mAlpha ^= v13;

	if (!a7)
		strncpy(gGlobalTextures[a1].field_28, a7, 0x1F);
	else
		gGlobalTextures[a1].field_28[0] = 0;

	gGlobalTextures[a1].field_48 = a8;

	i32 v14;
	if (!a4)
	{
		v14 = 0;
	}
	else if (a4 == 2)
	{
		v14 = 1;
	}
	else if (a4 == 1)
	{
		v14 = 2;
	}
	else
	{
		v14 = a4 == 7 ? 3 : -1;
	}

	if (v14 == 3 || gPcTexContainer[v14].field_28 & 1)
	{
		gGlobalTextures[a1].field_24 = gPcTexPvrAndSoftRendererRelated;
	}
	else
	{
		gGlobalTextures[a1].field_24 = v14;
	}

	i32 v84;
	if (a6 & 0x200)
		v84 = 2 * gPvrRelatedWidth;
	else
		v84 = 2 * a2;

	if (a4 == 7)
		v84 *= 2;

	u32 v12 = a4 & 0xFF00;
	if (v12 == 0x100 || v12 == 0x200 || v12 == 0xD00)
	{
		v83 = PVR_ConvertTwiddledToBMP(
				a2,
				a3,
				reinterpret_cast<const u16*>(a5),
				v12 == 512);
	}
	else if (v12 == 0x300 || v12 == 0x400)
	{
		v83 = PVR_ConvertVQToBMP(
				a2,
				a3,
				reinterpret_cast<const u16*>(a5),
				v12 == 1024);
	}

	gGlobalTextures[a1].mD3DTex = 0;

	if (a2 <= gMaxTextureWidth && a3 <= gTextureHeight)
	{
		gPvrCountRelated++;
		i32 v19 = gGlobalTextures[a1].field_24;
		gGlobalTextures[a1].field_50 = gPvrCountRelated;

		i32 v20;
		if (gPcTexContainer[v19].field_4 == 32)
		{
			v20 = 4 * a2;
		}
		else
		{
			v20 = 2 * a2;
		}

		if (gLowGraphics)
		{
			// @FIXME: todo lol
		}
		else
		{
			downloadTexture(
					&gGlobalTextures[a1], 
					reinterpret_cast<u16*>(v83),
					v84,
					v14);
		}

		if (a6 & 0x200)
		{
			gGlobalTextures[a1].mFlags &= ~2;
			gGlobalTextures[a1].mFlags |= 0x2006;

			gGlobalTextures[a1].pTextureData = a5;

			u16* mClut;
			if (gCreateTextureClut)
				mClut = gCreateTextureClut->mClut;
			else
				mClut = reinterpret_cast<u16*>(a4);

			gGlobalTextures[a1].field_60 = reinterpret_cast<i32>(mClut);

			if (gCreateTextureClut)
				gGlobalTextures[a1].field_64 = gCreateTextureClut->mColorCount;
			else
				gGlobalTextures[a1].field_64 = 0x10000;
		}


	}

	if (v12 == 256 || v12 == 512 || v12 == 768 || v12 == 1024 || v12 == 3328)
		free(v83);

	return 1;
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
void PCTex_GetInvTextureSize(i32 index, f32* pF1 ,f32 * pF2)
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

// @Ok
// @Matching
void PCTex_InitSystemTextures(void)
{
	if (gLowGraphics)
	{
		gMaxTextureAspectRatio = 0;
		gMaxTextureWidth = 256;
		gTextureHeight = 256;
		gSquareOnly = 0;
	}
	else
	{
#ifdef _WIN32
		gMaxTextureWidth = gD3DDevCaps.dwMaxTextureWidth;
		gTextureHeight = gD3DDevCaps.dwMaxTextureHeight;
		gMaxTextureAspectRatio = gD3DDevCaps.dwMaxTextureAspectRatio;
		gSquareOnly = (gD3DDevCaps.dpcTriCaps.dwTextureCaps & D3DPTEXTURECAPS_SQUAREONLY) != 0;
#endif
	}

	PCTEX_Init();
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

// @Ok
// @AlmostMatching: sligthly different order on the 9FF and thingy
void PCTex_ReleaseSysTexture(i32 a1, bool a2)
{
	if (gGlobalTextures[a1].mD3DTex)
	{
		if (gGlobalTextures[a1].mFlags & 0x400)
		{
			free(gGlobalTextures[a1].mD3DTex);
		}
		else
		{
#ifdef _WIN32
			HRESULT hr = gGlobalTextures[a1].mD3DTex->Release();
			D3D_ERROR_LOG_AND_QUIT(hr);
#endif
		}

		gGlobalTextures[a1].mD3DTex = 0;
		gGlobalTextures[a1].mFlags &= 0x9FF;

		// @FIXME
		ClutPC *v14 = clutToClutPc(reinterpret_cast<u16*>(gGlobalTextures[a1].field_60));
		if (v14)
		{
			if (--v14->mRefs <= 0 && a2)
			{
				releaseClutPc(v14);
			}
		}
	}

	if (a2)
	{
		if (gGlobalTextures[a1].field_64 == 0xFFFFFF)
		{
			free(gGlobalTextures[a1].pTextureData);
		}
		gGlobalTextures[a1].pTextureData = 0;
		gGlobalTextures[a1].field_60 = 0;
		gGlobalTextures[a1].field_64 = 0;
	}

	if (gGlobalTextures[a1].mSplit)
	{
		free(gGlobalTextures[a1].mSplit);
		gGlobalTextures[a1].mSplit = 0;
	}
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
u8 PCTex_TextureHasAlpha(i32 index)
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
INLINE ClutPC* clutToClutPc(const u16* pClut)
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
void downloadTexture(SPCTexture *,u16 *,i32,i32)
{
    printf("downloadTexture(PCTexture *,u16 *,i32,i32)");
}

// @Ok
// @Matching
HRESULT CALLBACK enumPixelFormatsCB(LPDDPIXELFORMAT lpDDPixFmt, void * lpContext)
{
#ifdef _WIN32
	LPDDPIXELFORMAT pPixelFormat = static_cast<LPDDPIXELFORMAT>(lpContext);
	memcpy(&pPixelFormat[gNumPixelFormats], lpDDPixFmt, sizeof(DDPIXELFORMAT));
#endif
	gNumPixelFormats++;

	return gNumPixelFormats < 16;
}

// @Ok
// @Matching
INLINE void releaseClutPc(ClutPC* pClut)
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

// @Ok
// @Validate
i32 shouldForceBlend(
		u16* a1,
		i32 a2,
		i32 a3,
		i32 a4)
{
	i32 v4 = 20 * a3 * a4 / 100;
	for (i32 i = 0; i < a4; i++)
	{
		for (i32 j = 0; i < a4; i++)
		{
			u16 cur = a1[j];
			cur >>= 0xC;
			if (cur)
			{
				if (cur < 15)
				{
					if (--v4 < 0)
						return 1;
				}
			}
		}

		a1 = &a1[a2];
	}

	return 0;
}

// @Ok
void PCTex_SetTextureUserData(int index, Bitmap256* texture)
{
	gGlobalTextures[index].mTexture = texture;
}

// @Ok
f32 PCTex_GetTextureWScale(int index)
{
	return gGlobalTextures[index].mWScale;
}

// @Ok
f32 PCTex_GetTextureHScale(int index)
{
	return gGlobalTextures[index].mHScale;
}

// @Ok
int PCTex_GetTextureFlags(int index)
{
	return gGlobalTextures[index].mFlags;
}

// @Ok
INLINE i32 countBits(u32 value)
{
	i32 bits = 0;

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

	VALIDATE(SPCTexture, mWScale, 0x4);
	VALIDATE(SPCTexture, mHScale, 0x8);

	VALIDATE(SPCTexture, field_C, 0xC);
	VALIDATE(SPCTexture, field_10, 0x10);

	VALIDATE(SPCTexture, mTexture, 0x14);
	VALIDATE(SPCTexture, mAlpha, 0x18);
	VALIDATE(SPCTexture, mD3DTex, 0x1C);
	VALIDATE(SPCTexture, mFlags, 0x20);

	VALIDATE(SPCTexture, field_24, 0x24);

	VALIDATE(SPCTexture, field_28, 0x28);
	VALIDATE(SPCTexture, field_48, 0x48);

	VALIDATE(SPCTexture, field_50, 0x50);

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

void validate_SPCTexPixelFormat(void)
{
#ifdef _WIN32
	VALIDATE_SIZE(SPCTexPixelFormat, 0x20);
	VALIDATE_SIZE(DDPIXELFORMAT, 0x20);
#endif
}

void validate_SPCTexContainer(void)
{
	VALIDATE_SIZE(SPCTexContainer, 0x4C);

	VALIDATE(SPCTexContainer, field_4, 0x4);
	VALIDATE(SPCTexContainer, field_8, 0x8);
	VALIDATE(SPCTexContainer, field_C, 0xC);
	VALIDATE(SPCTexContainer, field_10, 0x10);

	VALIDATE(SPCTexContainer, field_14, 0x14);
	VALIDATE(SPCTexContainer, field_18, 0x18);
	VALIDATE(SPCTexContainer, field_1C, 0x1C);
	VALIDATE(SPCTexContainer, field_20, 0x20);

	VALIDATE(SPCTexContainer, field_24, 0x24);
	VALIDATE(SPCTexContainer, field_28, 0x28);
	VALIDATE(SPCTexContainer, field_2C, 0x2C);
	VALIDATE(SPCTexContainer, field_30, 0x30);
	VALIDATE(SPCTexContainer, field_34, 0x34);
	VALIDATE(SPCTexContainer, field_38, 0x38);
	VALIDATE(SPCTexContainer, field_3C, 0x3C);
	VALIDATE(SPCTexContainer, field_40, 0x40);
	VALIDATE(SPCTexContainer, field_44, 0x44);
	VALIDATE(SPCTexContainer, field_48, 0x48);

	VALIDATE_I32(gPcTexContainer[0].field_8, 1);
	VALIDATE_I32(gPcTexContainer[0].field_C, 5);
	VALIDATE_I32(gPcTexContainer[0].field_10, 5);
	VALIDATE_I32(gPcTexContainer[0].field_14, 5);
	VALIDATE_I32(gPcTexContainer[0].field_18, 0xF);
	VALIDATE_I32(gPcTexContainer[0].field_1C, 0xA);
	VALIDATE_I32(gPcTexContainer[0].field_20, 5);
	VALIDATE_I32(gPcTexContainer[0].field_24, 0);
}

void validate_DDPIXELFORMAT(void)
{
#ifdef _WIN32
	VALIDATE(DDPIXELFORMAT, dwRBitMask, 0x10);
	VALIDATE(DDPIXELFORMAT, dwGBitMask, 0x14);
	VALIDATE(DDPIXELFORMAT, dwBBitMask, 0x18);
	VALIDATE(DDPIXELFORMAT, dwRGBAlphaBitMask, 0x1C);
#endif
}

void validate_ConvertPSXPaletteToPC(void)
{
	// done its purpsoe
	return;

	u16 a1[0x1000];
	u16 a2[0x1000];
	u16 expected_a2[0x1000];

	for (i32 i = 0; i < 512; i++)
	{
		char fileName[256];
		sprintf(fileName, "palettes/pal_%d.bin", i);
		FILE *fp = fopen(fileName, "rb");

		if (!fp)
		{
			printf("Failed to open %s\n", fileName);
			continue;
		}

		u32 a3;
		u32 a4;

		if (!fread(&a3, 4, 1, fp))
		{
			printf("Error reading a3 for %s\n", fileName);
			fclose(fp);
			continue;
		}

		if (!fread(&a4, 4, 1, fp))
		{
			printf("Error reading a4 for %s\n", fileName);
			fclose(fp);
			continue;
		}

		for(i32 j = 0; j < 0x1000; j++)
		{
			a1[j] = 0;
			a2[j] = 0;
			expected_a2[j] = 0;
		}

		if (!fread(a1, a3 * 2, 1, fp))
		{
			printf("Error reading a1 for %s\n", fileName);
			fclose(fp);
			continue;
		}

		if (!fread(expected_a2, a3 * 2, 1, fp))
		{
			printf("Error reading expected a2 for %s\n", fileName);
			fclose(fp);
			continue;
		}
		fclose(fp);

		ConvertPSXPaletteToPC(a1, a2, a3, a4);

		if (!memcmp(a2, expected_a2, 0x1000))
		{
			printf("MATCH: %s\n", fileName);
		}
		else
		{
			printf("MISMATCH: %s\n", fileName);
		}

	}
}
