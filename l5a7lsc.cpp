#include "l5a7lsc.h"

#include "spidey.h"

// @SMALLTODO
void L5A7LSC_MonitorSpideyinWater(const u32 *,u32 *)
{
    printf("L5A7LSC_MonitorSpideyinWater(u32 const *,u32 *)");
}

// @Ok
// @Matching
void L5A7LSC_RelocatableModuleClear(void)
{
}

// @Ok
// @Matching
void L5A7LSC_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = L5A7LSC_RelocatableModuleClear;
	pMod->field_C[0] = L5A7LSC_MonitorSpideyinWater;
	Spidey_SetUserFunction("l5a7lsc", 1u);
}

// @SMALLTODO
EXPORT void obtainWaterLevelInPoolA7(i32)
{
    printf("obtainWaterLevelInPool(i32)");
}
