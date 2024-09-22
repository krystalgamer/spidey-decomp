#include "pal.h"
#include "ps2funcs.h"

const i32 MAXFREE16SLOTS = 192;
EXPORT u8 Free16Slots[MAXFREE16SLOTS];

// @Ok
// @Matching
void Free16Slot(u16 a1)
{
	for (i32 i = 0; i < MAXFREE16SLOTS; i++)
	{
		if (GetClut(Pal16X, Pal16Y + i) == a1)
			break;
	}

	Free16Slots[i] = 1;
}

// @Ok
// @Matching
i32 GetFree16Slot(void)
{
	i32 freeSlot;

	for (freeSlot = 0; freeSlot < MAXFREE16SLOTS; freeSlot++)
	{
		if (Free16Slots[freeSlot])
			break;
	}

	print_if_false(freeSlot < 192, "Run out of 16 colour palettes");
	Free16Slots[freeSlot] = 0;

	return freeSlot;
}

// @SMALLTODO
void GetFree256Slot(void)
{
    printf("GetFree256Slot(void)");
}

// @SMALLTODO
void NewPaletteEntry(u32)
{
    printf("NewPaletteEntry(u32)");
}

// @SMALLTODO
void Pal_FindPaletteEntry(u32)
{
    printf("Pal_FindPaletteEntry(u32)");
}

// @SMALLTODO
void Pal_Init(void)
{
    printf("Pal_Init(void)");
}

// @SMALLTODO
void Pal_LoadPalette(u32,u32 *,u8)
{
    printf("Pal_LoadPalette(u32,u32 *,u8)");
}

// @SMALLTODO
void Pal_ProcessPalette(u16 *,i32)
{
    printf("Pal_ProcessPalette(u16 *,i32)");
}

// @SMALLTODO
void Pal_RemoveUnusedPalettes(void)
{
    printf("Pal_RemoveUnusedPalettes(void)");
}

// @SMALLTODO
void RemovePaletteEntry(tag_S_Pal *)
{
    printf("RemovePaletteEntry(tag_S_Pal *)");
}

void validate_tag_S_Pal(void)
{
}
