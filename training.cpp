#include "training.h"
#include "spidey.h"
#include "trig.h"

#include "l1a3bomb.h"

// @Ok
EXPORT u8 gTrainingFlags[3];

// @Ok
EXPORT i32 gTrainingStuff[8];

// @Ok
// @Matching
void Training_SpideyDied(const u32*, u32*)
{
	gTrainingFlags[0] = 1;
}

// @BIGTODO
void Training_MonitorLevel(const u32*, u32*)
{
	printf("void Training_MonitorLevel(const u32*, u32*)");
}

// @Ok
// @AlmostMatching: reloc assignements
void Training_RelocatableModuleClear(void)
{
	gBombDieRelatedTwo = 0;
	gBombDieTimerRelated = gTimerRelated;
	gBombDieRelatedOne = 0;
}

// @Ok
// @Matching
void Training_RelocatableModuleInit(reloc_mod *pMod)
{
	pMod->mClearFunc = Training_RelocatableModuleClear;
	pMod->field_C[0] = Training_MonitorLevel;
	pMod->field_C[1] = Training_SpideyDied;

	Spidey_SetUserFunction("training", 1u);

	gTrainingStuff[0] = Trig_GetLevelId();
	for (i32 i = 1; i < 8; i++)
	{
		gTrainingStuff[i] = 0;
	}

	gBombRelated = 4096;
	gTrainingFlags[2] = 0;
	gTrainingFlags[1] = 0;
	gTrainingFlags[0] = 0;
}
