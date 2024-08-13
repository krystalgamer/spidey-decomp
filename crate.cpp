#include "crate.h"
#include "shatter.h"
#include "spool.h"
#include "trig.h"
#include "exp.h"
#include "utils.h"
#include "mem.h"

// @FIXME
// is empty according to pc??
EXPORT i32 gCrateRecursion = 0;

// @FIXME find real size and shit
EXPORT u32* gCommandPointRelated[1];

// @SMALLTODO
// @FIXME
// there's a recusive call that trips ghidra and IDA something really weird
void Crate_Destroy(CItem* pItem)
{
	print_if_false(gCrateRecursion++ < 10, "Woops, loads of crate_destroy recursions");

	if (gCrateRecursion >= 10)
	{
		gCrateRecursion--;
		return;
	}

	if (Shatter_Item(pItem, 1, 1))
	{
		i32 EnvIndex = Spool_GetEnvIndex(pItem->mRegion);
		print_if_false(EnvIndex != -1, "Crate not in the environment???");

		Trig_TriggerCommandPoint(gCommandPointRelated[EnvIndex][pItem->mModel], false);

		if (!gMemInitRelatedTop)
		{
			CVector vec = pItem->mPos;

			if (Rnd(5))
			{
				Exp_SmallExplosion(&vec);
			}
			else
			{
				Exp_BigExplosion(&vec);
			}
		}

		for (CItem* i = EnviroList; i; i = i->field_20)
			;
		gCrateRecursion--;
	}

}
