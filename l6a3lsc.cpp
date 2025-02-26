#include "l6a3lsc.h"

#include "spidey.h"

// @SMALLTODO
void L6A3LSC_MonitorSpideyinWater(const u32 *,u32 *)
{
    printf("L6A3LSC_MonitorSpideyinWater(u32 const *,u32 *)");
}

// @Ok
// @Matching
void L6A3LSC_RelocatableModuleClear(void)
{
}

// @Ok
// @Matching
void L6A3LSC_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = L6A3LSC_RelocatableModuleClear;
	pMod->field_C[0] = L6A3LSC_MonitorSpideyinWater;
	Spidey_SetUserFunction("l6a3lsc", 1u);
}
