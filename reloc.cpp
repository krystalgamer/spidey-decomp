#include "reloc.h"
#include "utils.h"

#include "validate.h"

EXPORT SReloc *gRelocRoot;

// @Ok
// @Matching
INLINE void Reloc_Unload(u32 crc)
{
	if (gRelocRoot)
	{
		SReloc *pSearch = gRelocRoot;

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

// @SMALLTODO
void Reloc_Load(char *pStr,i32)
{
	u32 crc = Utils_GenerateCRC(pStr);
	for (SReloc *pSearch = gRelocRoot; pSearch; pSearch = pSearch->pNext)
	{
		if (pSearch->mCRC == crc)
			return;
	}


	SReloc *pReloc = static_cast<SReloc*>(DCMem_New(sizeof(SReloc), 0, 1, 0, 1));
	pReloc->pNext = gRelocRoot;
	pReloc->pPrev = 0;

	if (gRelocRoot)
		gRelocRoot->pPrev = pReloc;

	gRelocRoot = pReloc;
	pReloc->mCRC = crc;
	pReloc->field_0 = NullFunc;

}

// @MEDIUMTODO
void Reloc_UnloadAll(void)
{
    printf("Reloc_UnloadAll(void)");
}

void validate_SReloc(void)
{
	VALIDATE_SIZE(SReloc, 0x34);

	VALIDATE(SReloc, field_0, 0x0);
	VALIDATE(SReloc, mCRC, 0x8);
	VALIDATE(SReloc, field_C, 0xC);
	VALIDATE(SReloc, pNext, 0x2C);
	VALIDATE(SReloc, pPrev, 0x30);

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
