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
