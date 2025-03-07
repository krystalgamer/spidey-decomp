#include "vram.h"

#include "validate.h"

// @SMALLTODO
void VRAMRectPack(i32,i32,i32,i32 *,i32 *,i32,u8,u32)
{
    printf("VRAMRectPack(i32,i32,i32,i32 *,i32 *,i32,u8,u32)");
}

// @SMALLTODO
void VRAMRectUnpack(tagSVRAMRect *)
{
    printf("VRAMRectUnpack(tagSVRAMRect *)");
}

void validate_tagSVRAMRect(void)
{
	VALIDATE_SIZE(tagSVRAMRect, 0x14);

	VALIDATE(tagSVRAMRect, p_pack, 0x04);
	VALIDATE(tagSVRAMRect, p_next, 0x10);
}
