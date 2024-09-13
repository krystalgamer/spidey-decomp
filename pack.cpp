#include "pack.h"
#include "mem.h"
#include "validate.h"

EXPORT SPack Pack_pFull;
EXPORT u32 gPackRelated;

// @SMALLTODO
void Pack_Init(void)
{
    printf("Pack_Init(void)");
}

// @Ok
SPack* Pack_Pack(
		i32 Type,
		i32 WW,
		i32 H,
		i32 *X,
		i32 *Y,
		i32 BPP,
		i32,
		u32)
{
	i32 v6 = WW;

	print_if_false(Type < 0 || WW <= 512, "width out of range");
	print_if_false(H <= 512, "height out of range");

	if (BPP == 4 || BPP == 8 || BPP == 16)
		print_if_false(1u, "Bad BPP param in pack_pack().");
	else
		print_if_false(0, "Bad BPP param in pack_pack().");

	SPack* pPack = static_cast<SPack*>(
			DCMem_New(sizeof(SPack), 0, 1, 0, 1));

	*X = 0;
	pPack->X = 0;

	gPackRelated += 256;
	*Y = gPackRelated;
	pPack->Y = gPackRelated;
	pPack->pNext = 0;

	if (BPP != 4)
	{
		if (BPP == 8)
		{
			v6 >>= 1;
		}
	}
	else
	{
		v6 >>= 2;
	}

	print_if_false(v6 > 0, "width too small");
	
	pPack->W = v6;
	pPack->H = H;
	pPack->pNext = Pack_pFull.pNext;
	Pack_pFull.pNext = pPack;

	return pPack;
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

	VALIDATE(SPack, X, 0x0);
	VALIDATE(SPack, Y, 0x2);
	VALIDATE(SPack, W, 0x4);
	VALIDATE(SPack, H, 0x6);
	VALIDATE(SPack, pNext, 0x8);
}
