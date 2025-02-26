#include "reloc.h"
#include "utils.h"
#include "baddy.h"

#include "validate.h"
#include <cstring>

#include "thug.h"
#include "l2a1lsc.h"
#include "scorpion.h"
#include "jonah.h"
#include "blackcat.h"
#include "hostage.h"
#include "cop.h"
#include "chopper.h"
#include "rhino.h"
#include "venom.h"
#include "lizman.h"
#include "l5a5lsc.h"
#include "l5a6lsc.h"
#include "l5a7lsc.h"

#define LEN_RELOC_TABLE 31


// @FIXME - dump entries here
EXPORT SRelocEntry gRelocTable[LEN_RELOC_TABLE] =
{
	{ "thug", Thug_RelocatableModuleInit },
	{ "l2a1lsc", L2A1LSC_RelocatableModuleInit },
	{ "scorpion", Scorpion_RelocatableModuleInit },
	{ "jonah", Jonah_RelocatableModuleInit },
	{ "blackcat", BlackCat_RelocatableModuleInit },
	{ "hostage", Hostage_RelocatableModuleInit },
	{ "cop", Cop_RelocatableModuleInit },
	{ "chopper", Chopper_RelocatableModuleInit },
	{ "rhino", Rhino_RelocatableModuleInit },
	{ "venom", Venom_RelocatableModuleInit },
	{ "lizman", LizMan_RelocatableModuleInit },
	{ "l5a4lsc", 0 },
	{ "l5a5lsc", L5A5LSC_RelocatableModuleInit },
	{ "l5a6lsc", L5A6LSC_RelocatableModuleInit },
	{ "l5a7lsc", L5A7LSC_RelocatableModuleInit },
};

EXPORT reloc_mod *gRelocRoot;

// @Ok
// @Matching
INLINE void Reloc_Unload(u32 crc)
{
	if (gRelocRoot)
	{
		reloc_mod *pSearch = gRelocRoot;

		while (pSearch)
		{
			if (pSearch->mCRC == crc)
			{
				if (pSearch->mClearFunc)
					pSearch->mClearFunc();

				if (pSearch->pPrev)
					pSearch->pPrev->pNext = pSearch->pNext;

				if (pSearch->pNext)
					pSearch->pNext->pPrev = pSearch->pPrev;

				if (gRelocRoot == pSearch)
					gRelocRoot = pSearch->pNext;

				Mem_Delete(pSearch);
				return;
			}

			pSearch = pSearch->pNext;
		}
	}
}

// @Ok
// @Matching
void Reloc_Unload(char* pStr)
{
	Reloc_Unload(Utils_GenerateCRC(pStr));
}

// @Ok
// @Matching
void Reloc_CallUserFunction(const char* pStr, u32 a2, const u32* a3, u32* a4)
{
	u32 crc = Utils_GenerateCRC(pStr);

	for (reloc_mod *pMod = gRelocRoot; pMod; pMod = pMod->pNext)
	{
		if (crc == pMod->mCRC && pMod->field_C[a2])
		{
			pMod->field_C[a2](a3, a4);
			return;
		}
	}

	print_if_false(0, "Bad user function call");
}

// @Ok
// @Matching
void NullFunc(void)
{
	print_if_false(0, "relocatable function not loaded.");
}

// @Ok
// @AlmostMatching: same code diff reg allocation
void Reloc_Load(char *pStr,i32)
{
	u32 crc = Utils_GenerateCRC(pStr);
	for (reloc_mod *pSearch = gRelocRoot; pSearch; pSearch = pSearch->pNext)
	{
		if (pSearch->mCRC == crc)
			return;
	}


	reloc_mod *pReloc = static_cast<reloc_mod*>(DCMem_New(sizeof(reloc_mod), 0, 1, 0, 1));
	pReloc->pNext = gRelocRoot;
	pReloc->pPrev = 0;

	if (gRelocRoot)
		gRelocRoot->pPrev = pReloc;

	gRelocRoot = pReloc;
	pReloc->mCRC = crc;
	pReloc->mClearFunc = NullFunc;

	i32 used_index = LEN_RELOC_TABLE;

	i32 i = 0;
	while (i < LEN_RELOC_TABLE)
	{
		if (!strcmp(gRelocTable[i].Name, pStr))
		{
			gRelocTable[i].Func(pReloc);
			used_index = -1;
			break;
		}

		i++;
	}

	print_if_false(used_index == -1, "failed to load module %s", pStr);
}

// @Ok
// @Matching
void Reloc_UnloadAll(void)
{

	CBaddy *pSearch = BaddyList;
	while(pSearch)
	{
		CBaddy *pNext = reinterpret_cast<CBaddy*>(pSearch->field_20);
		u16 type = pSearch->field_38;
		if (type == 317 ||
				type == 304 ||
				type == 305 ||
				type == 306 ||
				type == 320 ||
				type == 312 ||
				type == 315)
		{
			delete pSearch;
		}

		pSearch = pNext;
	}

	Reloc_Unload(0xFDBCF4F8);
	Reloc_Unload(0x2736FBF8);
	Reloc_Unload(0xF84F55C0);
	Reloc_Unload(0x1CBA85B9);
	Reloc_Unload(0x2528AEEE);
	Reloc_Unload(0xF4DCD5FD);
	Reloc_Unload(0x1B982E4C);
	Reloc_Unload(0xFF9CB2BA);
	Reloc_Unload(0x1A96491C);
	Reloc_Unload(0x88F1EEF3);
	Reloc_Unload(0x9A44411D);
	Reloc_Unload(0x22F82678);
	Reloc_Unload(0x81070B0A);
	Reloc_Unload(0x93B2A4E4);
	Reloc_Unload(0x2B0EC381);

	Reloc_Unload(Utils_GenerateCRC("blackcat"));
	Reloc_Unload(Utils_GenerateCRC("carnage"));
	Reloc_Unload(Utils_GenerateCRC("chopper"));
	Reloc_Unload(Utils_GenerateCRC("docock"));
	Reloc_Unload(Utils_GenerateCRC("l2a1lsc"));
	Reloc_Unload(Utils_GenerateCRC("lizard"));
	Reloc_Unload(Utils_GenerateCRC("lizman"));
	Reloc_Unload(Utils_GenerateCRC("mj"));
	Reloc_Unload(Utils_GenerateCRC("spclone"));
	Reloc_Unload(Utils_GenerateCRC("submarin"));
	Reloc_Unload(Utils_GenerateCRC("superock"));
	Reloc_Unload(Utils_GenerateCRC("torch"));
	Reloc_Unload(Utils_GenerateCRC("training"));
	Reloc_Unload(Utils_GenerateCRC("turret"));
	Reloc_Unload(Utils_GenerateCRC("venom"));

	print_if_false(gRelocRoot == 0, "Not all code modules cleared!");
}

void validate_SReloc(void)
{
	VALIDATE_SIZE(reloc_mod, 0x34);

	VALIDATE(reloc_mod, mClearFunc, 0x0);
	VALIDATE(reloc_mod, mCRC, 0x8);
	VALIDATE(reloc_mod, field_C, 0xC);
	VALIDATE(reloc_mod, pNext, 0x2C);
	VALIDATE(reloc_mod, pPrev, 0x30);

}

void validate_SRelocEntry(void)
{
	VALIDATE_SIZE(SRelocEntry, 0x14);

	VALIDATE(SRelocEntry, Name, 0x0);
	VALIDATE(SRelocEntry, Func, 0x10);
}

void validate_reloc_mod(void)
{
}
