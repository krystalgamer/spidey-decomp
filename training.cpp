#include "training.h"
#include "spidey.h"

#include "l1a3bomb.h"

// @Ok
// @AlmostMatching: reloc assignements
void Training_RelocatableModuleClear(void)
{
	gBombDieRelatedTwo = 0;
	gBombDieTimerRelated = gTimerRelated;
	gBombDieRelatedOne = 0;
}

// @SMALLTODO
void Training_RelocatableModuleInit(reloc_mod *)
{
	printf("void Training_RelocatableModuleInit(reloc_mod *)");
}
