#include "l6a2lsc.h"
#include "spidey.h"

// @Ok
// @Matching
void L6A2LSC_RelocatableModuleClear(void)
{
}

// @SMALLTODO
void L6A2LSC_MonitorSpideyinWater(u32 const *,u32 *)
{
    printf("L6A2LSC_MonitorSpideyinWater(u32 const *,u32 *)");
}

// @Ok
// @Matching
void L6A2LSC_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = L6A2LSC_RelocatableModuleClear;
	pMod->field_C[0] = L6A2LSC_MonitorSpideyinWater;
	Spidey_SetUserFunction("l6a2lsc", 1u);
}
