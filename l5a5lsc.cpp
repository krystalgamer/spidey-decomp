#include "l5a5lsc.h"

#include "spidey.h"
#include "l1a3bomb.h"

u32 gL5A5Related;
EXPORT u32 gL5A5RelatedTwo;

// @MEDIUMTODO
void L5A5LSC_DisplayProgressBar(u32 const *,u32 *)
{
    printf("L5A5LSC_DisplayProgressBar(u32 const *,u32 *)");
}

// @SMALLTODO
void L5A5LSC_RelocatableModuleClear(void)
{
	printf("void L5A5LSC_RelocatableModuleClear(void)");
}

// @Ok
// @AlmostMatching: assignemtn to dietimerelated is slightly off
void L5A5LSC_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = L5A5LSC_RelocatableModuleClear;
	pMod->field_C[0] = L5A5LSC_WiggleSubwayCars;
	pMod->field_C[1] = L5A5LSC_DisplayProgressBar;
	Spidey_SetUserFunction("l5a5lsc", 1u);

	gBombDieRelatedTwo = 0;
	gBombDieTimerRelated = gL5A5Related;
	gL5A5RelatedTwo = 0;
}

// @MEDIUMTODO
void L5A5LSC_WiggleSubwayCars(u32 const *,u32 *)
{
    printf("L5A5LSC_WiggleSubwayCars(u32 const *,u32 *)");
}
