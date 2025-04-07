#include "training.h"
#include "spidey.h"

#include "l1a3bomb.h"

EXPORT u8 gTrainingSpideyDied;

// @Ok
// @Matching
void Training_SpideyDied(void)
{
	gTrainingSpideyDied = 1;
}

// @Ok
// @AlmostMatching: reloc assignements
void Training_RelocatableModuleClear(void)
{
	gBombDieRelatedTwo = 0;
	gBombDieTimerRelated = gTimerRelated;
	gBombDieRelatedOne = 0;
}

// @SMALLTODO
void Training_RelocatableModuleInit(reloc_mod *pMod)
{
	printf("void Training_RelocatableModuleInit(reloc_mod *)");
}
