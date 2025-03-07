#include "vram.h"
#include "my_assert.h"
#include "mem.h"

#include "validate.h"

EXPORT tagSVRAMRect *gVramRect;

// @Ok
// @Matching
tagSVRAMRect* VRAMRectPack(
		i32 Type,
		i32 WW,
		i32 H,
		i32 *X,
		i32 *Y,
		i32 BPP,
		u8 a7,
		u32 a8)
{
	tagSVRAMRect *v8 = static_cast<tagSVRAMRect *>(
			DCMem_New(sizeof(tagSVRAMRect), 0, 1, 0, 1));

	v8->p_next = gVramRect;
	gVramRect = v8;

	v8->p_poly = 0;
	v8->update_type = 0;

	v8->flags = a7;
	v8->flags |= (BPP == 4 ? 4 : 0);
	v8->flags |= (BPP == 8 ? 8 : 0);
	v8->flags |= (BPP == 16 ? 16 : 0);
	v8->flags |= (Type >= 0 ? 32 : 0);


	v8->p_pack = Pack_Pack(Type, WW, H, X, Y, BPP, (a7 >> 1) & 1, a8);
	return v8;
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

	VALIDATE(tagSVRAMRect, flags, 0x0);

	VALIDATE(tagSVRAMRect, p_pack, 0x04);
	VALIDATE(tagSVRAMRect, update_type, 0xC);

	VALIDATE(tagSVRAMRect, p_next, 0x10);
}
