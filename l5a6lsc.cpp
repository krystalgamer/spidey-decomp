#include "l5a6lsc.h"
#include "spidey.h"

// @MEDIUMTODO
void L5A6LSC_MonitorSpideyinWater(const u32 *,u32 *)
{
    printf("L5A6LSC_MonitorSpideyinWater(u32 const *,u32 *)");
}

// @Ok
// @Matching
void L5A6LSC_RelocatableModuleClear(void)
{
}

// @Ok
// @Matching
void L5A6LSC_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = L5A6LSC_RelocatableModuleClear;
	pMod->field_C[0] = L5A6LSC_MonitorSpideyinWater;
	Spidey_SetUserFunction("l5a6lsc", 1u);
}

// @MEDIUMTODO
void obtainWaterLevelInPool(i32)
{
    printf("obtainWaterLevelInPool(i32)");
}
