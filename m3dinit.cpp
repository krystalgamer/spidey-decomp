#include "m3dinit.h"
#include "validate.h"

// @SMALLTODO
void DCClearRegion(i32)
{
    printf("DCClearRegion(i32)");
}

// @SMALLTODO
void M3dInit_InitAtStart(void)
{
    printf("M3dInit_InitAtStart(void)");
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

// @SMALLTODO
void M3dInit_SetResolution(u32,u32)
{
    printf("M3dInit_SetResolution(u32,u32)");
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
