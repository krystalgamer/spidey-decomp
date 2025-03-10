#pragma once

#ifndef PS2FUNCS_H
#define PS2FUNCS_H

#include "export.h"
#include "quat.h"

EXPORT extern i32 gClutRelated;
EXPORT extern i32 gPortRelatedOne;
EXPORT extern i32 gSomeSize;
EXPORT extern i32 DoVblankProcessing;

struct SSinCos
{
	i16 sin;
	i16 cos;
};

#define FLATBIT_VELOCITIES_SIZE (4096)
#define FLATBIT_VELOCITIES_MAX_INDEX (FLATBIT_VELOCITIES_SIZE-1)

// @FIXME
// that's not the name
// it's something like rcosin_table
EXPORT extern SSinCos rcossin_tbl[FLATBIT_VELOCITIES_SIZE];

EXPORT extern i32 Pal16X;
EXPORT extern i32 Pal16Y;

EXPORT extern u8 gPrintStubbed;
EXPORT extern u8 gClearImagePrint;

enum GTREGType
{
	GT_ZERO = 0,
	GT_ONE = 1,
};

struct SLineInfo;

struct MATRIX{
	i16 m[3][3];
	i32 t[3];
};

typedef struct {		/* long word type 3D vector */
	long	vx, vy;
	long	vz, pad;
} VECTOR;
	
typedef struct {		/* short word type 3D vector */	
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
	       
typedef struct {		/* color type vector */	
  unsigned char	r, g, b, cd;
} CVECTOR;
	       
typedef struct {		/* 2D short vector */
	short vx, vy;
} DVECTOR;


void validate_MATRIX(void);

EXPORT void Port_InitAtStart(void);
EXPORT void Port_Exit(void);

EXPORT void gte_op0(void);
EXPORT void gte_SetRotMatrix(MATRIX*);
EXPORT void gte_ldv0(const SVECTOR* a1);
EXPORT void gte_rtv0tr(void);
EXPORT void gte_stlvnl(VECTOR *a1);
EXPORT void gte_rtps(void);
EXPORT void gte_rtpt(void);
EXPORT void gte_op12(void);
EXPORT void gte_ldlvl(VECTOR *a1);
EXPORT void gte_sqr0(void);
EXPORT void gte_rtv0(void);
EXPORT void gte_stlvnl0(int *a1);
EXPORT void gte_stlvnl2(int *a1);
EXPORT void gte_gpf0(void);
EXPORT void gte_stlzc(int *a1);
EXPORT void gte_stsv(SVECTOR *a1);
EXPORT void gte_mvmva(int _sf, int mx, int a3, int cv, int lm);
EXPORT void gte_stsxy(int *a1);
EXPORT void gte_lddp(int a1);
EXPORT void gte_ldsvrtrow0(const SVECTOR *a1);
EXPORT void gte_ldopv1(VECTOR *a1);
EXPORT void gte_ldopv2(VECTOR *a1);
EXPORT void gte_ldlv0(const VECTOR *a1);
EXPORT void gte_stsxy3(int *a1, int *a2, int *a3);
EXPORT void gte_rtir(void);
EXPORT void M3dMaths_SetIdentityRotation(MATRIX *a1);
EXPORT void MulMatrix0(MATRIX *a1, MATRIX *a2, MATRIX *a3);
EXPORT void MulMatrix(MATRIX *a1, MATRIX *a2);
EXPORT void m3d_ZeroTransVector(void);
EXPORT void VectorNormal(VECTOR*, VECTOR*);

EXPORT int M3dMaths_SquareRoot0(int i);

EXPORT int M3dMaths_MulDiv64(int, int, int);

EXPORT void M3dMaths_TransposeMatrix1(MATRIX *a1, MATRIX *a2);

class CItem;
EXPORT void M3dMaths_ScaleMatrix(CItem*, MATRIX *a2);

EXPORT void M3dMaths_CopyMat(MATRIX*, MATRIX*);

EXPORT void M3dAsm_ProcessPolys(unsigned int*, SVECTOR*, int);
EXPORT void M3dAsm_SetTransVector(VECTOR*);

EXPORT MATRIX* RotMatrixYXZ(SVECTOR *a1, MATRIX *a2);
EXPORT MATRIX* M3dMaths_RotMatrixYXZ(SVECTOR *a1, MATRIX *a2);

EXPORT int ratan2(int, int);

EXPORT u16 GetClut(i32, i32);

EXPORT void M3dAsm_LineColijPreprocessItems(CItem*, i32, SLineInfo*, u16);

EXPORT void TransMatrix(MATRIX*, VECTOR*);

EXPORT void setPolyGT4(void);
EXPORT void MTC2(i32*, GTREGType);


EXPORT void DCSetFatalError(i32);
EXPORT void DCInitSinCosTable(void);
EXPORT u8 IsForEurope(void);

// @Ok
INLINE static void DrawSync(void)
{
	if (!gPrintStubbed)
	{
		stubbed_printf("stubbed out: DrawSync");
	}
}

// @Ok
INLINE static void ClearImage(void)
{
	if (!gPrintStubbed)
	{
		stubbed_printf("stubbed out: ClearImage");
	}
}

// @Ok
INLINE static void _LoadImage(void)
{
	if (!gPrintStubbed)
	{
		stubbed_printf("stubbed out: LoadImage");
	}
}

// @Ok
INLINE static void setDrawTPage(void)
{
	if (!gPrintStubbed)
	{
		stubbed_printf("stubbed out: setDrawTPage");
	}
}

// @Ok
INLINE static void PutDispEnv(void)
{
	if (!gPrintStubbed)
	{
		stubbed_printf("stubbed out: PutDispEnv");
	}
}

#define STUBBED_FUNC(x)\
	INLINE static void x(void)\
	{\
		if (!gPrintStubbed)\
		{\
			stubbed_printf("stubbed out: " #x);\
		}\
	}

STUBBED_FUNC(SetDispMask)
STUBBED_FUNC(ClearImage2)
STUBBED_FUNC(ClearOTagR)
STUBBED_FUNC(SetDefDrawEnv)
STUBBED_FUNC(SetDefDispEnv)
STUBBED_FUNC(setRGB0)
STUBBED_FUNC(PutDrawEnv)
STUBBED_FUNC(DrawOTag)
STUBBED_FUNC(SetDrawArea)

#endif
