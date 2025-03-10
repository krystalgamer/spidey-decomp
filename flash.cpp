#include "flash.h"

EXPORT i32 FadeCountdown;
EXPORT i32 FlashCountdown;
EXPORT i32 Fading;
EXPORT u8 CurrentImportance;
EXPORT i32 FlashSort;

EXPORT u32 CurrentR;
EXPORT u32 CurrentG;
EXPORT u32 CurrentB;

EXPORT u32 dR;
EXPORT u32 dG;
EXPORT u32 dB;

// @Ok
// @Matching
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

// @Ok
void Flash_Screen(
		u8 StartR,
		u8 StartG,
		u8 StartB,
		i32 Frames,
		u8 Importance,
		i32 Sort)
{
	if (Importance >= CurrentImportance && Frames)
	{
		CurrentR = StartR << 16;
		CurrentG = StartG << 16;
		CurrentB = StartB << 16;
		FlashCountdown = Frames;
		CurrentImportance = Importance;
		dR = (StartR << 16) / Frames;
		dG = (StartG << 16) / Frames;
		dB = (StartB << 16) / Frames;
		FlashSort = Sort;
	}

}

// @Ok
// @Matching
void Flash_Update(void)
{
	if (Fading)
	{
		if (FadeCountdown)
		{
			if (--FadeCountdown == 0)
			{
				CurrentB = 0xFF0000;
				CurrentG = 0xFF0000;
				CurrentR = 0xFF0000;
			}
			else
			{
				CurrentR += dR;
				CurrentG += dR;
				CurrentB += dR;
			}
		}
	}
	else if (FlashCountdown)
	{
		if (--FlashCountdown == 0)
		{
			CurrentImportance = 0;
		}
		else
		{
			CurrentR -= dR;
			CurrentG -= dG;
			CurrentB -= dB;
		}
	}
}
