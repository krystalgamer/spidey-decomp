#include "ps2m3d.h"
#include "ps2funcs.h"
#include "db.h"
#include "PCGfx.h"
#include "m3dinit.h"
#include "SpideyDX.h"

#include "validate.h"

i32 gWideScreen;


// @Ok
// @Matching
vector4d& vector4d::operator=(const vector4d& other)
{
	this->field_0[0] = other.field_0[0];
	this->field_0[1] = other.field_0[1];
	this->field_0[2] = other.field_0[2];
	this->field_0[3] = other.field_0[3];

	return *this;
}

// @Ok
INLINE vector4d& matrix4x4::operator[](i32 index)
{
	return this->field_0[index];
}

// @Ok
// @Matching
matrix4x4::matrix4x4(
			f32 a1,
			f32 a2,
			f32 a3,
			f32 a4,
			f32 a5,
			f32 a6,
			f32 a7,
			f32 a8,
			f32 a9,
			f32 a10,
			f32 a11,
			f32 a12,
			f32 a13,
			f32 a14,
			f32 a15,
			f32 a16)
{
	this->field_0[0].field_0[0] = a1;
	this->field_0[0].field_0[1] = a2;
	this->field_0[0].field_0[2] = a3;
	this->field_0[0].field_0[3] = a4;
	
	this->field_0[1].field_0[0] = a5;
	this->field_0[1].field_0[1] = a6;
	this->field_0[1].field_0[2] = a7;
	this->field_0[1].field_0[3] = a8;
	
	this->field_0[2].field_0[0] = a9;
	this->field_0[2].field_0[1] = a10;
	this->field_0[2].field_0[2] = a11;
	this->field_0[2].field_0[3] = a12;
	
	this->field_0[3].field_0[0] = a13;
	this->field_0[3].field_0[1] = a14;
	this->field_0[3].field_0[2] = a15;
	this->field_0[3].field_0[3] = a16;
	
}

/*
EXPORT void __ml(matrix4x4 const *,matrix4x4 const *);

EXPORT void matrix4x4::__vc(const(i32);
EXPORT matrix4x4::matrix4x4(f32,f32,f32,f32,f32,f32,f32,f32,f32,f32,f32,f32,f32,f32,f32,f32);

EXPORT void uWibble(STexWibVertInfo *);
EXPORT void vWibble(STexWibVertInfo *);

EXPORT void vector4d::__vc(const(i32);
*/


// @FIXME
char gRenderBuf[4] = { 0, 0, 0, 0 };

// @Ok
// @Matching
void M3d_BuildTransform(CSuper* pSuper)
{
	if ((pSuper->outlineRelated & 1) == 0 )
	{
		M3dMaths_RotMatrixYXZ(
				reinterpret_cast<SVECTOR *>(&pSuper->mAngles),
				&pSuper->mTransform);
	}
	if (pSuper->mFlags & 0x200)
	{
		M3dMaths_ScaleMatrix(pSuper, &pSuper->mTransform);
	}

	pSuper->mTransform.t[0] = pSuper->mPos.vx >> 12;
	pSuper->mTransform.t[1] = pSuper->mPos.vy >> 12;
	pSuper->mTransform.t[2] = pSuper->mPos.vz >> 12;
}

// @BIGTODO
void M3d_Render(void*)
{
	printf("void M3d_Render(void*)");
}

// @MEDIUMTODO
void DCModel_RenderModel(SModel const *,DCModelData *,matrix4x4 const *,void const *)
{
    printf("DCModel_RenderModel(SModel const *,DCModelData *,matrix4x4 const *,void const *)");
}

// @MEDIUMTODO
void DC_PSXModel_RenderModel(SModel const *,matrix4x4 const *,void const *,DCModelData *)
{
    printf("DC_PSXModel_RenderModel(SModel const *,matrix4x4 const *,void const *,DCModelData *)");
}

// @MEDIUMTODO
void M3d_PreprocessPulsingColours(i32)
{
    printf("M3d_PreprocessPulsingColours(i32)");
}

// @MEDIUMTODO
void M3d_PreprocessWibblyTextures(i32)
{
    printf("M3d_PreprocessWibblyTextures(i32)");
}

// @MEDIUMTODO
void M3d_RenderBackground(void *)
{
    printf("M3d_RenderBackground(void *)");
}

// @Ok
// @Test
// can't get it to match but that's fine, looks good tho
void M3d_RenderCleanup(void)
{
	SetDrawArea();
	pPoly += 3;

	stubbed_printf(gRenderBuf);

	if (gWideScreen)
	{
		PCGfx_UseTexture(1, DCGfx_BlendingMode_0);

		f32 v2 = (f32)gGameResolutionY;
		f32 v5 = (f32)(unsigned int)Yres;
		f32 v1 = v2 / v5;
		f32 v6 = (f32)gWideScreen;
		f32 v12 = v1 * v6;
		f32 v7 = (f32)gGameResolutionX;
		f32 v3 = (f32)(unsigned int)Xres;
		f32 v8 = v7 / v3 * 512.0f;
		PCGfx_DrawQuad2D(
				0,
				0,
				v8,
				v12,
				0,
				0,
				1.0,
				1.0,
				0xFF000000,
				0.0,
				false);

		f32 v13 = (f32)gGameResolutionY;
		f32 v9 = (f32)(unsigned int)Yres;
		f32 v4 = v13 / v9;
		f32 v14 = (f32)gWideScreen;
		f32 v18 = v14 * v4;
		f32 v15 = (f32)gGameResolutionX;
		f32 v10 = (f32)(unsigned int)Xres;
		f32 v11 = v15 / v10 * 512.0f;
		f32 v16 = (f32)(240 - gWideScreen);
		f32 v17 = v16 * v4;
		PCGfx_DrawQuad2D(
				0,
				v17,
				v11,
				v18,
				0,
				0,
				1.0,
				1.0,
				0xFF000000,
				0.0,
				false);
	}
}

// @MEDIUMTODO
void M3d_RenderSetup(SCamera *,SViewport *,u32 *)
{
    printf("M3d_RenderSetup(SCamera *,SViewport *,u32 *)");
}

// @MEDIUMTODO
void RenderSuperItem(CItem *,bool)
{
    printf("RenderSuperItem(CItem *,bool)");
}

void validate_matrix4x4(void)
{
	VALIDATE_SIZE(matrix4x4, 64);

	VALIDATE(matrix4x4, field_0, 0x0);
}
