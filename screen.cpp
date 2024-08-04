#include "screen.h"


static bool gScreenTarget;

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

// @SMALLTODO
void Screen_SetTarget(CVector *,u16,i16)
{
    printf("Screen_SetTarget(CVector *,u16,i16)");
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
