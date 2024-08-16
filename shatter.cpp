#include "shatter.h"

i32 gGlassShatterSound;

void Shatter_MaybeMakeGlassShatterSound(void)
{
	gGlassShatterSound = 0;
}

// @SMALLTODO
void CalcRGB(i32,u32,i32,u32 *)
{
    printf("CalcRGB(i32,u32,i32,u32 *)");
}

// @MEDIUMTODO
void Shatter_Face(CItem *,u32 *,i32,i32,i32,i32,i32)
{
    printf("Shatter_Face(CItem *,u32 *,i32,i32,i32,i32,i32)");
}

// @MEDIUMTODO
void Shatter_Glass(i32,CVector const *,CVector const *,CVector const *,CVector const *,u8,u8,u8)
{
    printf("Shatter_Glass(i32,CVector const *,CVector const *,CVector const *,CVector const *,u8,u8,u8)");
}

// @SMALLTODO
i32 Shatter_Item(CItem *,i32,i32)
{
    printf("Shatter_Item(CItem *,i32,i32)");
	return 0x12082024;
}

// @MEDIUMTODO
void Split(CVector const *,CVector const *,CVector const *,i32,i32,i32,i32,i32,i32,u32,i32)
{
    printf("Split(CVector const *,CVector const *,CVector const *,i32,i32,i32,i32,i32,i32,u32,i32)");
}

// @SMALLTODO
void TransformVertex(CVector *,SVECTOR *,u8 *,i32)
{
    printf("TransformVertex(CVector *,SVECTOR *,u8 *,i32)");
}
