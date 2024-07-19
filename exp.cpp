#include "exp.h"
#include "validate.h"

// @SMALLTODO
void Exp_HitEnvItem(CItem* pItem, u32* pFace, i32 Damage)
{
	printf("Exp_HitEnvItem");
}

// @SMALLTODO
void Exp_GlowFlash(CVector*, i32, u8, u8, u8, i32, i32, i32)
{
	printf("Exp_GlowFlash");
}


void validate_CItemFrag(void)
{
	VALIDATE_SIZE(CItemFrag, 0xB8);
}
