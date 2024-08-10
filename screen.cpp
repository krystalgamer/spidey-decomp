#include "screen.h"


EXPORT bool gScreenTarget;


EXPORT CVector gTargetRelated;
EXPORT u16 gTargetOne;
EXPORT u16 gTargetTwo;

// @SMALLTODO
void Screen_DrawArrow(void)
{
    printf("Screen_DrawArrow(void)");
}

// @MEDIUMTODO
void Screen_DrawTarget(void)
{
    printf("Screen_DrawTarget(void)");
}

// @MEDIUMTODO
void Screen_SepiaFade(void)
{
    printf("Screen_SepiaFade(void)");
}

// @Ok
void Screen_SetTarget(
		CVector *a1,
		u16 a2,
		i16 a3)
{
	gTargetRelated = *a1;
	gTargetOne = a2;
	gTargetTwo = a3;
}

// @SMALLTODO
void Screen_StartCircularFadeIn(i32,i32)
{
    printf("Screen_StartCircularFadeIn(i32,i32)");
}

// @SMALLTODO
void Screen_UpdateFades(void)
{
    printf("Screen_UpdateFades(void)");
}

// @MEDIUMTODO
void screen_DrawCircularFade(void)
{
    printf("screen_DrawCircularFade(void)");
}

// @NotOk
// Globals
void Screen_TargetOn(bool value)
{
	gScreenTarget = value;
}
