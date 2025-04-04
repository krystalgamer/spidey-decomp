#include "Image.h"
#include "dcshellutils.h"
#include "PCTex.h"
#include "dcfileio.h"
#include "mem.h"

#include "validate.h"


u16 gSlicedImageRelated[256];

// @Ok
void SlicedImage2::pack(void)
{
}

// @Ok
void SlicedImage2::removeFromMemory(void)
{
}

// @Ok
Image::~Image(void)
{
}

// @Ok
SlicedImage2::SlicedImage2(
		void* pData,
		i32 width,
		i32 height,
		i32 slicew,
		i32 sliceh,
		u8 a7,
		u16 a8,
		u32 a9)
{
	print_if_false(width >= 2 && width <= 640, "Unlikely width for SlicedImage2");
	print_if_false(height >= 0 && height <= 480, "Unlikely height for SlicedImage2");

	print_if_false(slicew >= 0 && slicew <= 256, "Unlikely slicew for SlicedImage2");
	print_if_false(sliceh >= 0 && sliceh <= 256, "Unlikely sliceh for SlicedImage2");

	if (a7 == 8)
	{
		width >>= 1;
	}

	u8 v11;
	if (a7 == 4)
	{
		v11 = 2;
	}
	else
	{
		v11 = a7 == 8;
	}

	this->field_1C = v11;
	this->field_10 = a9;

	if ( a7 == 8 )
	{
		this->field_18 = PCTex_CreateTexture256(
				width,
				height,
				pData,
				0,
				a9,
				"SlicedImage2",
				0,
				0);
	}
	else if ( a7 == 4 )
	{
		this->field_18 = PCTex_CreateTexture16(
				width,
				height,
				pData,
				0,
				"SlicedImage2",
				0,
				0,
				1);
	}
	else
	{
		error("Invalid slicedimage color depth.");
	}

	if (a9 & 8)
	{
		Bitmap256* pBitmap = new Bitmap256(
				reinterpret_cast<char*>(pData),
				gSlicedImageRelated,
				width,
				height,
				this->field_18);
		PCTex_SetTextureUserData(this->field_18, pBitmap);
	}

	this->field_16 = height;
	this->field_14 = width >> this->field_1C;
	
}

// @Ok
SlicedImage2::~SlicedImage2(void)
{
	if (this->field_18)
	{
		PCTex_ReleaseTexture(this->field_18, true);
	}
}

// @SMALLTODO
void SlicedImage2::UnknownSlicedImageVirtualFunc(void)
{
	printf("void SlicedImage2::UnknownSlicedImageVirtualFunc(void)");
}

// @Ok
// @Matching
void SlicedImage2::setData(void* pData)
{
	PCTex_ReleaseTexture(this->field_18, 1);

	i32 texture;
	if (this->field_1C == 1)
		texture = PCTex_CreateTexture256(
			2 * this->field_14,
			this->field_16,
			pData,
			0,
			this->field_10,
			"SlicedImage2",
			0,
			0);
	else
		texture = PCTex_CreateTexture16(
			this->field_14 << this->field_1C,
			this->field_16,
			pData,
			0,
			"SlicedImage2",
			0,
			0,
			1);
	this->field_18 = texture;
	if (this->field_10 & 8)
	{
		Bitmap256* pBit = new Bitmap256(
			reinterpret_cast<char*>(pData),
			gSlicedImageRelated,
			this->field_14 << this->field_1C,
			this->field_16,
			this->field_18);

		PCTex_SetTextureUserData(this->field_18, pBit);
	}
}

// @Ok
INLINE i32 GetBMPBitDepth(char* pData)
{
	u16* buf = reinterpret_cast<u16*>(pData);
	i32 depth = buf[14];

	print_if_false(depth == 4 || depth == 8, "Unrecognized color depth %d", depth);
	return depth;
}

// @MEDIUMTODO
void Load4BitBMP_2(char *,char **,i32 *,i32 *,u16 *)
{
    printf("Load4BitBMP_2(char *,char **,i32 *,i32 *,u16 *)");
}

// @Ok
i32 LoadNBitBMP_(
		const char* a1,
		char** a2,
		i32* a3,
		i32* a4,
		u16* a5,
		i32* a6)
{

	i32 fileSize = FileIO_Open(a1);
	if (fileSize <= 0)
	{
		error("\nFile %s not found", a1);
		return 0;
	}

	print_if_false(fileSize > 16, "screwy BMP file size");

	u16* pBmp = static_cast<u16*>(DCMem_New(fileSize, 1, 1, 0, 1));
	if (pBmp)
	{
		FileIO_Load(pBmp);
		FileIO_Sync();

		*a6 = GetBMPBitDepth(reinterpret_cast<char*>(pBmp));

		if (*a6 == 4)
		{
			Load4BitBMP_2(reinterpret_cast<char*>(pBmp), a2, a3, a4, a5);
		}
		else
		{
			Load8BitBMP_2(reinterpret_cast<char*>(pBmp), a2, a3, a4, a5);
		}

		Mem_Delete(pBmp);
		return 1;
	}

	error("\nNot enough memory to load %s", a1);
	return 0;
}

// @Ok
// @Matching
SlicedImage2::SlicedImage2(void)
{
    printf_fancy("stubbed: SlicedImage2::SlicedImage2");
}

// @Ok
INLINE Image::Image(void)
{
	this->field_4 = 0;
	this->Shaded = 0;
	this->field_6 = 0;
	this->field_7 = 0x80;
	this->field_8 = 0x80;
	this->field_9 = 0x80;
	this->field_A = 0;
	this->field_B = 0;
	this->field_C = 4096;
}

// @Ok
int SlicedImage2::screenHeight(void)
{
	return (this->field_C * this->field_16) >> 12;
}

// @Ok
INLINE i32 Load8BitBMP_2(char *a1, char **a2, i32 *a3, i32 *a4, u16 *a5)
{
	Load8BitBMP2(a1, a2, a3, a4, a5, false);
	return 1;
}

// @Ok
// @Validated
i32 Load8BitBMP2(
		char *pData,
		char **data,
		i32 *ww,
		i32 *hh,
		u16 *clut,
		bool a6)
{
	*data = 0;

	BMPHeader *pBmp = reinterpret_cast<BMPHeader*>(pData);
	u16 height_px = pBmp->height_px;
	u16 width_px = pBmp->width_px;
	u16 bits_per_pixel = pBmp->bits_per_pixel;

	if ((bits_per_pixel != 16) & (bits_per_pixel != 8))
	{
		error("\nNot 8 bits per pixel, is %d bits per pixel", bits_per_pixel);
		return 0;
	}

	u16 num_colors = pBmp->num_colors;
	if (!num_colors)
		num_colors = 256;

	
	u16* pClut = PCTex_CreateClut(256);

	u8* pPalette = reinterpret_cast<u8*>(&pBmp[1]);
	char v18;

	for (i32 i = 0; i < num_colors; i++)
	{
		u16 v22[3];

		if (bits_per_pixel == 8)
		{
			v22[0] = pPalette[0];
			v22[1] = pPalette[1];
			v22[2] = pPalette[2];
		}
		else
		{
			char* pCPalette = reinterpret_cast<char*>(pPalette);
			v22[0] = pCPalette[0];
			v22[1] = pCPalette[1];
			v22[2] = pCPalette[2];
		}

		if( v22[0] <= 0xF7 || v22[1] || v22[2] <= 0xF7)
		{
			i8 v25 = 0;
			if (v22[0] < 8u && v22[1] < 8u && v22[2] < 8u && (v22[0] || v22[1] || v22[2]) )
				v25 = 1;

			i16 v26[3];
			if ( v25 )
			{
				v26[0] = 1;
				v26[1] = 1;
				v26[2] = 1;
			}
			else
			{
				v26[0] = v22[0] >> 3;
				v26[1] = v22[1] >> 3;
				v26[2] = v22[2] >> 3;
			}
			if ( v26[0] || v26[1] || v26[2] )
				pClut[i] = v26[0] + 32 * (v26[1] + 32 * (v26[2] + 32));
			else
				pClut[i] = 0x8000;
		}
		else
		{
			pClut[i] = 0;
			v18 = i;
		}

		pPalette += 4;
	}

	for (i32 j = 0; j < 256; j++)
	{
		gSlicedImageRelated[j] = pClut[j];
	}

	i32 v19 = width_px % 4;
	if (v19 > 0)
		v19 = 4 - v19;

	i32 rounded_width = v19 + width_px;
	
	char *dstData = reinterpret_cast<char*>(DCMem_New(rounded_width * height_px, 1, 1, 0, 1));
	//char *dstData = reinterpret_cast<char*>(malloc(rounded_width * height_px));;
	*data = dstData;
	char* pPixel = reinterpret_cast<char*>(&reinterpret_cast<i32*>(&pBmp[1])[num_colors]);

	char* pRow = &dstData[(height_px - 1) * rounded_width];

	for (i32 k = 0; k < height_px; k++)
	{
		for (i32 m = 0; m < rounded_width - v19; m++)
		{
			*pRow++ = *pPixel++;
		}

		for (i32 l = 0; l < v19; l++)
		{
			*pRow++ = v18;
			pPixel++;
		}

		pRow -= 2 * rounded_width;
	}

	
	if (a6)
		Mem_Delete(pData);

	*ww = rounded_width;
	*hh = height_px;
	*clut = -1;
	return 1;
}


void validate_SlicedImage2(void)
{
	VALIDATE_SIZE(SlicedImage2, 0x20);

	VALIDATE(SlicedImage2, field_10, 0x10);

	VALIDATE(SlicedImage2, field_14, 0x14);
	VALIDATE(SlicedImage2, field_16, 0x16);
	VALIDATE(SlicedImage2, field_18, 0x18);
	VALIDATE(SlicedImage2, field_1C, 0x1C);

	VALIDATE(SlicedImage2, field_1E, 0x1E);

	VALIDATE_VTABLE(SlicedImage2, UnknownSlicedImageVirtualFunc, 1);
	VALIDATE_VTABLE(SlicedImage2, setData, 2);
	VALIDATE_VTABLE(SlicedImage2, draw, 3);
}

void validate_Image(void)
{
	VALIDATE(Image, field_4, 0x4);
	VALIDATE(Image, Shaded, 0x5);
	VALIDATE(Image, field_6, 0x6);
	VALIDATE(Image, field_7, 0x7);
	VALIDATE(Image, field_8, 0x8);
	VALIDATE(Image, field_9, 0x9);
	VALIDATE(Image, field_A, 0xA);
	VALIDATE(Image, field_B, 0xB);
	VALIDATE(Image, field_C, 0xC);
}

void validate_BmpHeader(void)
{
	VALIDATE_SIZE(BMPHeader, 0x36);

	VALIDATE(BMPHeader, type, 0x0);
	VALIDATE(BMPHeader, size, 0x2);

	VALIDATE(BMPHeader, width_px, 0x12);
	VALIDATE(BMPHeader, height_px, 0x16);
	VALIDATE(BMPHeader, num_planes, 0x1A);
	VALIDATE(BMPHeader, bits_per_pixel, 0x1C);
	VALIDATE(BMPHeader, image_size_bytes, 0x22);

	VALIDATE(BMPHeader, num_colors, 0x2E);

}

void validate_Load8BitBMP2(void)
{
	return;

	FILE *bmpFp = fopen("LegalPC.bmp", "rb");

	if (!bmpFp)
	{
		puts("Couldnt open LegalPC.bmp");
		return;
	}

	char legalpc[0x1E436];
	if(!fread(legalpc, 0x1E436, 1, bmpFp))
	{
		puts("Couldnt read LegalPC.bmp");
		fclose(bmpFp);
		return;
	}

	fclose(bmpFp);

	char* data = 0;
	i32 width = 0;
	i32 height = 0;
	u16 clut = 0;
	i32 ret = Load8BitBMP2(legalpc, &data, &width, &height, &clut, false);

	VALIDATE_I32(ret, 1);
	VALIDATE_I32(width, 0x200);
	VALIDATE_I32(height, 0xF0);
	VALIDATE_I32(clut, 0xFFFF);

	puts("Finished basics");

	u16 gSlicedExpected[0x100];
	if (read_into("legalbmpgsliced.bin", gSlicedExpected, 0x200))
		return;

	if (compare_buffs("gsliced", gSlicedImageRelated, gSlicedExpected, 0x200))
		return;

	u8 expectedBmpData[0x1E000];

	if (read_into("legalbmpdata.bin", expectedBmpData, sizeof(expectedBmpData)))
		return;

	if (compare_buffs("bmpdata", expectedBmpData, data, sizeof(expectedBmpData)))
	{
		FILE *fp = fopen("mylegal.bin", "wb");

		fwrite(data, sizeof(expectedBmpData), 1, fp);
		fclose(fp);
		return;
	}
}
