#include "l2a1lsc.h"
#include "spidey.h"


// @MEDIUMTODO
void L2A1LSC_DisplayProgressBar(u32 const *,u32 *)
{
    printf("L2A1LSC_DisplayProgressBar(u32 const *,u32 *)");
}

// @SMALLTODO
void L2A1LSC_MonitorTimer(u32 const *,u32 *)
{
    printf("L2A1LSC_MonitorTimer(u32 const *,u32 *)");
}

// @Ok
// @Matching
void L2A1LSC_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = L2A1LSC_RelocatableModuleClear;
	pMod->field_C[0] = L2A1LSC_MonitorTimer;
	pMod->field_C[1] = L2A1LSC_DisplayProgressBar;
	Spidey_SetUserFunction("l2a1lsc", 1u);
}

// @SMALLTODO
void L2A1LSC_RelocatableModuleClear(void)
{
    printf("L2A1LSC_RelocatableModuleClear(void)");
}
