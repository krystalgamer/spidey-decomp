#include "flash.h"

EXPORT i32 gFadeStatus;

// @NotOk
// global
i32 Flash_FadeFinished(void)
{
	return gFadeStatus == 0;
}

// @MEDIUMTODO
void Flash_Display(void)
{
    printf("Flash_Display(void)");
}

// @SMALLTODO
void Flash_Reset(void)
{
    printf("Flash_Reset(void)");
}

// @SMALLTODO
void Flash_Screen(u8,u8,u8,i32,u8,i32)
{
    printf("Flash_Screen(u8,u8,u8,i32,u8,i32)");
}

// @SMALLTODO
void Flash_Update(void)
{
    printf("Flash_Update(void)");
}
