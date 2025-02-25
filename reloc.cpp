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
void Reloc_Load(char *,i32)
{
    printf("Reloc_Load(char *,i32)");
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

void validate_reloc_mod(void)
{
}
