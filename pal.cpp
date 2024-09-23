#include "pal.h"
#include "ps2funcs.h"
#include "pack.h"
#include "mem.h"

#include "validate.h"

EXPORT i32 gPalRelated;

const i32 PAL_ARRAY_SIZE = 260;
EXPORT tag_S_Pal gPalArrayData[PAL_ARRAY_SIZE];
EXPORT tag_S_Pal* gPalArray = &gPalArrayData[0];

EXPORT struct tag_S_Pal *pPaletteList;

const i32 MAXFREE16SLOTS = 192;
EXPORT u8 Free16Slots[MAXFREE16SLOTS];

const i32 MAXFREE256SLOTS = 68;
EXPORT u8 Free256Slots[MAXFREE256SLOTS];

// @Ok
// @Matching
INLINE void Free16Slot(u16 a1)
{
	i32 i;
	for (i = 0; i < MAXFREE16SLOTS; i++)
	{
		if (GetClut(Pal16X, Pal16Y + i) == a1)
			break;
	}

	Free16Slots[i] = 1;
}

// @Ok
// @Matching
INLINE i32 GetFree16Slot(void)
{
	i32 freeSlot;

	for (freeSlot = 0; freeSlot < MAXFREE16SLOTS; freeSlot++)
	{
		if (Free16Slots[freeSlot])
			break;
	}

	print_if_false(freeSlot < MAXFREE16SLOTS, "Run out of 16 colour palettes");
	Free16Slots[freeSlot] = 0;

	return freeSlot;
}

// @Ok
// @Matching
INLINE i32 GetFree256Slot(void)
{
	i32 freeSlot;

	for (freeSlot = 0; freeSlot < MAXFREE256SLOTS; freeSlot++)
	{
		if (Free256Slots[freeSlot])
			break;
	}

	print_if_false(freeSlot < MAXFREE256SLOTS, "Run out of 256 colour palettes");
	Free256Slots[freeSlot] = 0;

	return freeSlot;
}

// @Ok
tag_S_Pal* NewPaletteEntry(u32 checksum)
{
	print_if_false(gPalArray != 0, "Run out of palettes");

	tag_S_Pal* result = gPalArray;
	gPalArray = gPalArray->pNext;

	result->pNext = pPaletteList;
	pPaletteList = result;

	result->Checksum = checksum;
	result->InVRAM = 0;
	result->Usage = 0;

	return result;
}

// @SMALLTODO
void Pal_FindPaletteEntry(u32)
{
    printf("Pal_FindPaletteEntry(u32)");
}

// @Ok
// @Matching
void Pal_Init(void)
{
	pPaletteList = 0;
	gPalArray = &gPalArrayData[0];

	for (i32 i = 0; i < PAL_ARRAY_SIZE - 1; i++)
	{
		gPalArrayData[i].pNext = &gPalArrayData[i+1];
	}
	gPalArrayData[PAL_ARRAY_SIZE-1].pNext = 0;

	Mem_Delete(Pack_Pack(-1, 256, 12, &Pal16X, &Pal16Y, 16, 0, 0));
	Mem_Delete(Pack_Pack(-1, 256, 68, &gClutRelated, &gPalRelated, 16, 0, 0));


	for (i32 k = 0; k < MAXFREE16SLOTS; k++)
	{
		Free16Slots[k] = 1;
	}

	Free256Slots[0] = 0;
	for (i32 m = 1; m < MAXFREE256SLOTS; m++)
	{
		Free256Slots[m] = 1;
	}

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

// @Ok
// @Matching
void Pal_RemoveUnusedPalettes(void)
{
	tag_S_Pal* next;
	for (
			tag_S_Pal* pPal = pPaletteList;
			pPal;
			pPal = next)
	{
		next = pPal->pNext;

		if (!pPal->Usage)
		{
			if (pPal->flags & 1)
				Free16Slots[pPal->slot] = 1;

			if (pPal->flags & 2)
				Free256Slots[pPal->slot] = 1;

			RemovePaletteEntry(pPal);
		}
	}
}

// @Ok
// @Matching
INLINE void RemovePaletteEntry(tag_S_Pal* pEntry)
{
	tag_S_Pal* pPrev = 0;
	tag_S_Pal* pIter;

	for (pIter = pPaletteList; pIter; pIter = pIter->pNext)
	{
		if (pIter == pEntry)
			break;

		pPrev = pIter;
	}

	print_if_false(pIter != 0, "pEntry not found for deletion");

	if (pPrev)
		pPrev->pNext = pEntry->pNext;
	else
		pPaletteList = pEntry->pNext;

	pEntry->pNext = gPalArray;
	gPalArray = pEntry;
}

void validate_tag_S_Pal(void)
{
	VALIDATE_SIZE(tag_S_Pal, 0x18);

	VALIDATE(tag_S_Pal, slot, 0x2);
	VALIDATE(tag_S_Pal, flags, 0x3);
	VALIDATE(tag_S_Pal, Usage, 0x4);

	VALIDATE(tag_S_Pal, InVRAM, 0x6);
	VALIDATE(tag_S_Pal, Checksum, 0x8);

	VALIDATE(tag_S_Pal, pNext, 0xC);
}
