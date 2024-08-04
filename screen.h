#pragma once

#ifndef SCREEN_H
#define SCREEN_H

#include "export.h"
#include "vector.h"


EXPORT void Screen_TargetOn(bool);
EXPORT void Screen_DrawArrow(void);
EXPORT void Screen_DrawTarget(void);
EXPORT void Screen_SepiaFade(void);
EXPORT void Screen_SetTarget(CVector *,u16,i16);
EXPORT void Screen_StartCircularFadeIn(i32,i32);
EXPORT void Screen_UpdateFades(void);
EXPORT void screen_DrawCircularFade(void);

#endif
