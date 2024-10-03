#include "dcshellutils.h"
#include "validate.h"
#include "m3dinit.h"
#include "SpideyDX.h"
#include "PCGfx.h"
#include "PCTex.h"

i32 gDcSpriteRedAmount[256];
i32 gDcSpriteGreenAmount[256];
i32 gDcSpriteBlueAmount[256];

// @Ok
// @Validate
INLINE void DCSpriteDraw(
		i32 a1,
		i32 a2,
		i32 a3,
		float a4,
		u32 a5,
		u32 a6,
		u32 a7,
		i32 a8,
		u32 a9,
		float a10)
{
	if (a1 != -1)
	{
		if (a5 > 0xFF)
			a5 = 0xFF;

		if (a6 > 0xFF)
			a6 = 0xFF;

		if (a7 > 0xFF)
			a7 = 0xFF;

		gDcSpriteRedAmount[a5]++;
		gDcSpriteGreenAmount[a6]++;
		gDcSpriteBlueAmount[a7]++;
		
		PCGfx_DrawTexture2D(
				a1,
				a2,
				a3,
				a4,
				a7 | (a6 << 8) | (a5 << 16) | (a8 << 24),
				a9,
				a10);
	}
}

// @Ok
// @Matching
void Sprite2::setData(void* a2)
{
	char* v4 = 0;
	i32 v5;
	i32 v6;
	u16 missing;

	Load8BitBMP_2(reinterpret_cast<char*>(a2), &v4, &v5, &v6, &missing);
	print_if_false(
		this->field_14 << this->field_1C == v5,
		"data width %d does not match image width %d",
		v5,
		this->field_14 << this->field_1C);
	print_if_false(
		this->field_16 == v6,
		"data height %d does not match image height %d",
		v6,
		this->field_16);

	this->field_1E = missing;
	SlicedImage2::setData(v4);
	if (this->field_20)
	{
		Mem_Delete(this->field_20);
	}

	this->field_20 = reinterpret_cast<u8*>(v4);
}

// @Ok
Sprite2::Sprite2(
		const char* a2,
		i32 a3,
		i32 a4,
		i32 a5,
		u32 a6)
{
	char* v18 = 0;
	i32 v20;
	i32 v19;
	u16 v17;
	i32 v21;
	
	this->field_18 = -1;
	LoadNBitBMP_(a2, &v18, &v20, &v19, &v17, &v21);
	if ( v21 == 8 )
		this->field_1C = 1;
	else
		this->field_1C = 2;

	this->field_16 = v19;
	this->field_10 = a6;
	this->field_14 = v20 >> this->field_1C;
	this->field_20 = reinterpret_cast<u8*>(v18);

	i32 Texture256;
	if ( v21 == 8 )
		Texture256 = PCTex_CreateTexture256(v20, v19, v18, 0, a6, a2, 0, 0);
	else
		Texture256 = PCTex_CreateTexture16(v20, v19, v18, 0, a2, 0, 0, 1u);
	this->field_18 = Texture256;

	if (a6 & 8)
	{
		Bitmap256* v14 = new Bitmap256(v18, gSlicedImageRelated, v20, v19, this->field_18);
		PCTex_SetTextureUserData(this->field_18, v14);
	}
}

// @Ok
// @Test
// @Validate
void SlicedImage2::draw(
		i32 a2,
		i32 a3,
		i32 a4,
		float a5)
{
	u32 v30, v31, v39;

	if (this->field_4 && this->field_6 == 2)
	{
		v30 = 255 - this->field_7;
		v31 = 255 - this->field_8;
		v39 = 255 - this->field_9;
	}
	else
	{
		v30 = this->field_7;
		v31 = this->field_8;
		v39 = this->field_9;
	}

	i32 v5 = this->field_14;
	i32 v6 = this->field_10;
	i32 v21 = this->field_16;
	i32 v7 = v21;
	float v10;
	if ( (v6 & 4) != 0 )
	{
		float v32 = (float)v5;
		float v24 = (float)Xres;
		float v33 = (float)gGameResolutionX;
		v5 = (v32 * v24 / v33);

		float v34 = (float)v21;
		float v25 = (float)Yres;

		float v35 = (float)gGameResolutionY;
		v10 = v34 * v25 / v35;
	}
	else if (v6 & 0x20)
	{
		float v36 = (float)v5;
		float v26 = (float)Xres;
		v5 = (v36 * v26 / 640.0f);

		float v37 = (float)v21;
		float v27 = (float)Yres;
		v10 = v37 * v27 / 480.0f;
	}
	v7 = v10;

	float v28;
	if (!this->field_A)
	{
		v28 = 0.0f;
	}
	else if (this->field_A == 1)
	{
		v28 = (v5 << this->field_1C) / -2;
	}
	else
	{
		v28 = -(v5 << this->field_1C);
	}

	float v13;
	if (!this->field_B)
	{
		v13 = 0.0f;
	}
	else if (this->field_B == 1)
	{
		v13 = v7 / -2;
	}
	else
	{
		v13 = -v7;
	}

	u32 v15 = (v6 & 0x24) == 0;
	float v38 = this->field_C / 4096.0;
	float v29 = v38 * v28;
	float v23 = v38 * v13;

	if (a4)
		v15 |= a4;

	if (this->field_6 == 1 && this->field_4)
		v15 |= 4;

	DCSpriteDraw(
			this->field_18,
			(float)a2 + v29,
			(float)a3 + v23,
			v38,
			v30,
			v31,
			v39,
			255,
			v15,
			a5);
}

void validate_Sprite2(void)
{
	VALIDATE_SIZE(Sprite2, 0x24);

	VALIDATE(Sprite2, field_20, 0x20);
}
