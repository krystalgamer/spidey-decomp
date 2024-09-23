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
// @Matching
INLINE tag_S_Pal* NewPaletteEntry(u32 checksum)
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

// @Ok
// @Matching
tag_S_Pal* Pal_FindPaletteEntry(u32 checksum)
{
	tag_S_Pal* result;
	for (result = pPaletteList; result; result = result->pNext)
	{
		if (result->Checksum == checksum)
			break;
	}

	return result;
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

// @Ok
// @Matching
tag_S_Pal* Pal_LoadPalette(
		u32 checksum,
		u32* pData,
		u8 flags)
{
	tag_S_Pal* result = NewPaletteEntry(checksum);

	result->flags = flags;
	print_if_false((flags & 3) != 3, "Bad flags");
	print_if_false((flags & 3) != 0, "Bad flags");

	i32 bpp = flags & 1 ? 16 : 256;

	Pal_ProcessPalette(
			reinterpret_cast<u16*>(pData),
			bpp);

	if (bpp == 16)
		result->slot = GetFree16Slot();
	else
		result->slot = GetFree256Slot();

	result->Clut = 0;

	_LoadImage();
	result->InVRAM = 1;
	return result;
}

// @Ok
// @Note: got optimzied somehow?
// @Validate
void Pal_ProcessPalette(
		u16* pData,
		i32 bpp)
{
	u8 firstIf = 0;
	u8 secondIf = 0;
	for (i32 i = 0; i < bpp; i++)
	{
		if ((pData[i] & 0x7FFF) == 0x7C1F)
		{
			firstIf = 1;
			break;
		}

		if (!pData[i])
			secondIf = 1;
	}

	if (firstIf)
	{
		for (i32 j = 0; j < bpp; j++)
		{
			if ((pData[j] & 0x7FFF) == 0x7C1F)
			{
				pData[j] = 0;
			}
			else
			{
				pData[j] |= 0x8000;
			}
		}
	}
	else if (secondIf)
	{
		for (i32 m = 0; m < bpp; m++)
		{
			if (!pData[m])
			{
				pData[m] = 0;
			}
			else
			{
				pData[m] |= 0x8000;
			}
		}
	}
	else
	{
		u32* nPdata = reinterpret_cast<u32*>(pData);
		i32 nBpp = bpp >> 1;
		while (nBpp != 0)
		{
			*nPdata++ = 0x80008000;
			nBpp--;
		}
	}
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

	VALIDATE(tag_S_Pal, Clut, 0x0);
	VALIDATE(tag_S_Pal, slot, 0x2);
	VALIDATE(tag_S_Pal, flags, 0x3);
	VALIDATE(tag_S_Pal, Usage, 0x4);

	VALIDATE(tag_S_Pal, InVRAM, 0x6);
	VALIDATE(tag_S_Pal, Checksum, 0x8);

	VALIDATE(tag_S_Pal, pNext, 0xC);
}
