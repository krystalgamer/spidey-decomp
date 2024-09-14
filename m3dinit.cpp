#include "m3dinit.h"
#include "bit.h"
#include "validate.h"

u32 M3d_FadeColour;

EXPORT i16 WibbleTables[1024];
EXPORT u32 Xres;
EXPORT u32 Yres;

EXPORT i32 PixelAspectX;
EXPORT i32 PixelAspectY;


// @SMALLTODO
void DCClearRegion(i32)
{
    printf("DCClearRegion(i32)");
}

// @Ok
void M3dInit_InitAtStart(void)
{
	M3dInit_SetResolution(0x200, 0xF0);
	M3dInit_SetFoggingParams(0, 6000, 0x800);

	i16 *pWibble = &WibbleTables[0];
	for (i32 i = 0; i < 16; i++)
	{
		for (i32 j = 0; j < 4096; j+=64)
		{
			*pWibble = (i * rcossin_tbl[j].sin) >> 4;
			pWibble++;
		}
	}

	M3d_FadeColour = 0x80000000;
}

// @MEDIUMTODO
void M3dInit_ParsePSX(i32)
{
    printf("M3dInit_ParsePSX(i32)");
}

// @MEDIUMTODO
void M3dInit_SetFoggingParams(long,long,u32)
{
    printf("M3dInit_SetFoggingParams(long,long,u32)");
}

// @Ok
INLINE void M3dInit_SetResolution(u32 X,u32 Y)
{
	if (Y << 2 < X * 3)
	{
		Xres = X;
		Yres = Y;
		PixelAspectX = 0x1000;
		PixelAspectY = (X * 0x3000) / (Y << 2);
		return;
	}

	Xres = X;
	Yres = Y;
	PixelAspectX = (Y << 0xE) / (X * 3);
	PixelAspectX = 0x1000;
}

// @SMALLTODO
void alloc_dc_models(i32,i32)
{
    printf("alloc_dc_models(i32,i32)");
}

// @SMALLTODO
void setup_pulsing_colors(i32)
{
    printf("setup_pulsing_colors(i32)");
}

// @Ok
// Hated this piece of shit, memoery accesses are fucked up on the original for some reason
// there might be a hidden struct or smth, it's not the first time I see something like this
// where pointers to the middle of the struct are used
void M3dInit_FlagZeroWibbles(STexWibItemInfo *pTexWibItemInfo)
{
	print_if_false(pTexWibItemInfo != NULL, "NULL pTexWibItemInfo");

	STexWibItemInfo *v1 = pTexWibItemInfo;
	STexWibItemInfo *v3;
	unsigned int v2;

	while (v1->ItemOffset.Full)
	{
		v2 = 0;

		v1->ZeroUAmplitudes = 1;
		v2 = v1->field_C.Full;
		v1->ZeroVAmplitudes = 1;

		v3 = v1 + 1;


#define AmplitudeCheck(x, arg) {\
	int tmp = 0;\
	tmp = (x);\
	if ( ((int)((tmp) & 0xFFFFFFF0)) > ((int)0x00000050) ) {\
		v1->arg = 0; }\
}

#define UAmplitudeCheck(x) AmplitudeCheck(x, ZeroUAmplitudes)
#define VAmplitudeCheck(x) AmplitudeCheck(x, ZeroVAmplitudes)

		while (v2)
		{
			UAmplitudeCheck(v3->ItemOffset.Byte[2]);
			VAmplitudeCheck(v3->ItemOffset.Byte[3]);

			UAmplitudeCheck(v3->field_6);
			VAmplitudeCheck(v3->field_7);

			UAmplitudeCheck(v3->field_8);
			VAmplitudeCheck(v3->field_9);


			UAmplitudeCheck(v3->ZeroUAmplitudes);
			VAmplitudeCheck(v3->ZeroVAmplitudes);
				
			v3++;
			v2--;
		}

		v1 = v3;

	}
}

void validate_STexWibItemInfo()
{
	VALIDATE_SIZE(STexWibItemInfo, 0x10);

	VALIDATE(STexWibItemInfo, ItemOffset, 0x0);

	VALIDATE(STexWibItemInfo, field_6, 0x6);
	VALIDATE(STexWibItemInfo, field_7, 0x7);
	VALIDATE(STexWibItemInfo, field_8, 0x8);
	VALIDATE(STexWibItemInfo, field_9, 0x9);

	VALIDATE(STexWibItemInfo, field_C, 0xC);

	VALIDATE(STexWibItemInfo, ZeroUAmplitudes, 0xE);
	VALIDATE(STexWibItemInfo, ZeroVAmplitudes, 0xF);
}
