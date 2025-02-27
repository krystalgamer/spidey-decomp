#include "l2a1lsc.h"
#include "spidey.h"

#include "l1a3bomb.h"
#include "l5a5lsc.h"
#include "utils.h"
#include "trig.h"

#define LEN_L2_TEXS 5
EXPORT Texture *gL2a1Texs[LEN_L2_TEXS];

EXPORT u8 gl2a1ArrOne[5];
EXPORT u8 gl2a1ArrTwo[5];

EXPORT i32 gL2A1DifficultyArr[4] = { 0x3F84, 0x3F84, 0x3174, 0x2364 };

// @MEDIUMTODO
void L2A1LSC_DisplayProgressBar(const u32 *,u32 *)
{
    printf("L2A1LSC_DisplayProgressBar(u32 const *,u32 *)");
}

// @Ok
void L2A1LSC_MonitorTimer(const u32 *,u32 *)
{
	gBombRelated = 4096;
	if (!gBombDieRelatedTwo)
	{
		gBombDieRelatedOne = 1;
		gBombDieRelatedTwo = 1;
		gBombAIRelated = gL2A1DifficultyArr[DifficultyLevel];
		gBombDieTimerRelated = gTimerRelated;
		gl2a1ArrOne[0] = 0;
		gl2a1ArrOne[1] = 0;
		gl2a1ArrOne[2] = 0;
		gl2a1ArrOne[3] = 0;
		gl2a1ArrOne[4] = 0;
		gl2a1ArrTwo[0] = 0;
		gl2a1ArrTwo[1] = 0;
		gl2a1ArrTwo[2] = 0;
		gl2a1ArrTwo[3] = 0;
		gl2a1ArrTwo[4] = 0;
	}

	if (!gBombAIRelated && !gl2a1ArrOne[4])
	{
		gl2a1ArrOne[4] = 1;

		for (i32 i = 1; i < NumNodes; i++)
		{
			if (*gTrigNodes[i] == 1)
			{
				CVector v18 = { 0 };
				Trig_GetPosition(&v18, i);

				if (v18.vx >> 12 == -419 &&
						v18.vy >> 12 == -2730 &&
						v18.vz >> 12 == -3826 )
				{
					Trig_SendPulseToNode(i);
					return;
				}
			}
		}
		print_if_false(0, "Pulse node not found");
	}
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
