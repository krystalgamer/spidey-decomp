#include "reloc.h"
#include "utils.h"

#include "validate.h"
#include <cstring>

// @FIXME - dump entries here

#define LEN_RELOC_TABLE 31
EXPORT SRelocEntry gRelocTable[LEN_RELOC_TABLE];
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
				if (pSearch->field_0)
					pSearch->field_0();

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

// @MEDIUMTODO
void Reloc_CallUserFunction(const char*, u32, const u32*, u32*)
{
	printf("WASSSUP");
}

// @SMALLTODO
void NullFunc(void)
{
    printf("NullFunc(void)");
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
	pReloc->field_0 = NullFunc;

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

// @MEDIUMTODO
void Reloc_UnloadAll(void)
{
    printf("Reloc_UnloadAll(void)");
}

void validate_SReloc(void)
{
	VALIDATE_SIZE(reloc_mod, 0x34);

	VALIDATE(reloc_mod, field_0, 0x0);
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
