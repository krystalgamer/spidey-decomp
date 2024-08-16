#pragma once

#ifndef SHATTER_H
#define SHATTER_H

#include "export.h"
#include "ob.h"

EXPORT extern i32 gGlassShatterSound;

EXPORT void Shatter_MaybeMakeGlassShatterSound(void);
EXPORT void CalcRGB(i32,u32,i32,u32 *);
EXPORT void Shatter_Face(CItem *,u32 *,i32,i32,i32,i32,i32);
EXPORT void Shatter_Glass(i32,CVector const *,CVector const *,CVector const *,CVector const *,u8,u8,u8);
EXPORT i32 Shatter_Item(CItem *,i32,i32);
EXPORT void Split(CVector const *,CVector const *,CVector const *,i32,i32,i32,i32,i32,i32,u32,i32);
EXPORT void TransformVertex(CVector *,SVECTOR *,u8 *,i32);

#endif
