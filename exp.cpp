#include "exp.h"
#include "validate.h"


void Exp_HitEnvItem(CItem* pItem, u32* pFace, i32 Damage)
{
	printf("Exp_HitEnvItem");
}


void validate_CItemFrag(void)
{
	VALIDATE_SIZE(CItemFrag, 0xB8);
}
