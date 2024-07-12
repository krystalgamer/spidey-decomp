#include "reloc.h"
#include "utils.h"

// @BIGTODO
void Reloc_Unload(unsigned int)
{}

void Reloc_Unload(char* pStr)
{
	Reloc_Unload(Utils_GenerateCRC(pStr));
}
