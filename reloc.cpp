#include "reloc.h"
#include "utils.h"

// @BIGTODO
void Reloc_Unload(unsigned int)
{}

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
