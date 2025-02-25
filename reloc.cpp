#include "reloc.h"
#include "utils.h"

#include "validate.h"

// @BIGTODO
void Reloc_Unload(u32)
{
}

// @Ok
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
	VALIDATE_SIZE(SReloc, 0x30);

	VALIDATE(SReloc, field_0, 0x0);
	VALIDATE(SReloc, mCRC, 0x8);
	VALIDATE(SReloc, field_C, 0xC);
	VALIDATE(SReloc, pNext, 0x2C);

}

void validate_reloc_mod(void)
{
}
