#include "flash.h"

EXPORT i32 FadeCountdown;
EXPORT i32 FlashCountdown;
EXPORT i32 Fading;
EXPORT u8 CurrentImportance;

// @Ok
i32 Flash_FadeFinished(void)
{
	return FadeCountdown == 0;
}

// @MEDIUMTODO
void Flash_Display(void)
{
    printf("Flash_Display(void)");
}

// @Ok
// @Matching
void Flash_Reset(void)
{
	FlashCountdown = 0;
	FadeCountdown = 0;
	Fading = 0;
	CurrentImportance = 0;
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
