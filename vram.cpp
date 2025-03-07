#include "vram.h"
#include "my_assert.h"
#include "mem.h"

#include "validate.h"

EXPORT tagSVRAMRect *gVramRect;

// @SMALLTODO
void VRAMRectPack(i32,i32,i32,i32 *,i32 *,i32,u8,u32)
{
    printf("VRAMRectPack(i32,i32,i32,i32 *,i32 *,i32,u8,u32)");
}

// @Ok
// @Matching
void VRAMRectUnpack(tagSVRAMRect *pRect)
{
	tagSVRAMRect **v1 = &gVramRect;
	tagSVRAMRect *v2 = 0;

	for (tagSVRAMRect *v3 = *v1; v3; v3 = *v1)
	{
		if (v3 == pRect)
		{
			v2 = *v1;

			*v1 = v2->p_next;
			Pack_Unpack(v2->p_pack);
			Mem_Delete(v2);
			break;
		}

		v1 = &v3->p_next;
	}

	DoAssert(v2 != 0, "No packed texture matching specified coordinates.");
}

void validate_tagSVRAMRect(void)
{
	VALIDATE_SIZE(tagSVRAMRect, 0x14);

	VALIDATE(tagSVRAMRect, p_pack, 0x04);
	VALIDATE(tagSVRAMRect, p_next, 0x10);
}
