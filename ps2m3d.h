#pragma once

#ifndef PS2M3D_H
#define PS2M3D_H

#include "export.h"
#include "ob.h"
#include "camera.h"
#include "dcmodel.h"

struct matrix4x4;

EXPORT void M3d_BuildTransform(CSuper*);
EXPORT void M3d_Render(void*);
EXPORT void DCModel_RenderModel(SModel const *,DCModelData *,matrix4x4 const *,void const *);
EXPORT void DC_PSXModel_RenderModel(SModel const *,matrix4x4 const *,void const *,DCModelData *);
EXPORT void M3d_PreprocessPulsingColours(i32);
EXPORT void M3d_PreprocessWibblyTextures(i32);
EXPORT void M3d_RenderBackground(void *);
EXPORT void M3d_RenderCleanup(void);
EXPORT void M3d_RenderSetup(SCamera *,SViewport *,u32 *);
EXPORT void RenderSuperItem(CItem *,bool);

#endif
