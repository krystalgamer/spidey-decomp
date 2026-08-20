#include "flash.h"

// @Ok
EXPORT i32 FadeCountdown;
// @Ok
EXPORT i32 FlashCountdown;
// @Ok
EXPORT i32 Fading;
// @Ok
EXPORT u8 CurrentImportance;
// @Ok
EXPORT i32 FlashSort;

// @Ok
EXPORT u32 CurrentR;
// @Ok
EXPORT u32 CurrentG;
// @Ok
EXPORT u32 CurrentB;

// @Ok
EXPORT u32 dR;
// @Ok
EXPORT u32 dG;
// @Ok
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
// @Matching
void Flash_Screen(
		u8 StartR,
		u8 StartG,
		u8 StartB,
		i32 Frames,
		u8 Importance,
		i32 Sort)
{
	if (Importance >= CurrentImportance)
	{
		if (Frames)
		{
			CurrentR = StartR << 16;
			CurrentG = StartG << 16;
			CurrentB = StartB << 16;

			dR = (CurrentR) / Frames;
			dG = (CurrentG) / Frames;
			dB = (CurrentB) / Frames;

			FlashCountdown = Frames;
			CurrentImportance = Importance;
			FlashSort = Sort;
		}
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

#include "my_patch.h"

// @Bogus
void patch_flash(void)
{
	PATCH_PUSH_RET(0x0043D820, Flash_FadeFinished);
	PATCH_PUSH_RET(0x0043D800, Flash_Reset);
	PATCH_PUSH_RET(0x0043D830, Flash_Screen);
}
