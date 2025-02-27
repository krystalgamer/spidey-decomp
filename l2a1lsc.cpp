#include "l2a1lsc.h"
#include "spidey.h"

#include "l1a3bomb.h"
#include "l5a5lsc.h"

#define LEN_L2_TEXS 5
EXPORT Texture *gL2a1Texs[LEN_L2_TEXS];

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

// @Ok
// @Note: data ordering is all over the place
void L2A1LSC_RelocatableModuleClear(void)
{
	gBombDieRelatedOne = 0;
	gBombDieRelatedTwo = 0;
	gBombDieTimerRelated = gTimerRelated;

	for (i32 i = 0; i < LEN_L2_TEXS; i++)
	{
		gL2a1Texs[i] = 0;
	}
}
