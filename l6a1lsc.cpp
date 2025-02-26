#include "l6a1lsc.h"

#include "spidey.h"


// @MEDIUMTODO
void L6A1LSC_MonitorSpideyinWater(u32 const *,u32 *)
{
    printf("L6A1LSC_MonitorSpideyinWater(u32 const *,u32 *)");
}

// @Ok
// @Matching
void L6A1LSC_RelocatableModuleClear(void)
{
}

// @Ok
// @Matching
void L6A1LSC_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = L6A1LSC_RelocatableModuleClear;
	pMod->field_C[0] = L6A1LSC_MonitorSpideyinWater;
	Spidey_SetUserFunction("l6a1lsc", 1u);
}

// @SMALLTODO
EXPORT void obtainWaterLevelInPoolL6A1(i32)
{
    printf("obtainWaterLevelInPool(i32)");
}
