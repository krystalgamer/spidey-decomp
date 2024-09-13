#include "pack.h"
#include "mem.h"
#include "validate.h"

EXPORT SPack Pack_pFull;

// @SMALLTODO
void Pack_Init(void)
{
    printf("Pack_Init(void)");
}

// @SMALLTODO
void Pack_Pack(i32,i32,i32,i32 *,i32 *,i32,i32,u32)
{
    printf("Pack_Pack(i32,i32,i32,i32 *,i32 *,i32,i32,u32)");
}

// @Ok
// @Matching
void Pack_Unpack(SPack* a1)
{
	SPack* pPrev = &Pack_pFull;
	for (SPack *pCur = pPrev->pNext;
			pCur;
			pCur = pCur->pNext)
	{
		if (a1 == pCur)
		{
			pPrev->pNext = pCur->pNext;
			Mem_Delete(a1);
			return;
		}

		pPrev = pCur;
	}
	
	print_if_false(0, "Couldn't find pack structure.");
	Mem_Delete(a1);
}

void validate_SPack(void)
{
	VALIDATE_SIZE(SPack, 0xC);
	VALIDATE(SPack, pNext, 0x8);
}
