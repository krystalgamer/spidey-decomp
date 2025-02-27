#include "l5a5lsc.h"

#include "spidey.h"
#include "l1a3bomb.h"

EXPORT u32 gL5A5RelatedTwo;

#define LEN_L5A5_TEXS 4
EXPORT Texture *gL5A5Texs[LEN_L5A5_TEXS];

// @MEDIUMTODO
void L5A5LSC_DisplayProgressBar(u32 const *,u32 *)
{
    printf("L5A5LSC_DisplayProgressBar(u32 const *,u32 *)");
}

// @Ok
// @AlmostMatching: reorder assignements
void L5A5LSC_RelocatableModuleClear(void)
{
	gBombDieRelatedTwo = 0;
	gBombDieTimerRelated = gTimerRelated;

	for (i32 i = 0; i < LEN_L5A5_TEXS; i++)
	{
		gL5A5Texs[i] = 0;
	}
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
	gBombDieTimerRelated = gTimerRelated;
	gL5A5RelatedTwo = 0;
}

// @MEDIUMTODO
void L5A5LSC_WiggleSubwayCars(u32 const *,u32 *)
{
    printf("L5A5LSC_WiggleSubwayCars(u32 const *,u32 *)");
}
