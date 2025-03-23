#include "m3dutils.h"
#include "validate.h"

// @SMALLTODO
void M3dUtils_ReadLinksPacket(CSuper*, void*)
{}

// @NotOk
// Revisit and fix globals
void M3dUtils_InBetween(CSuper *a1)
{
	unsigned __int16 v1; // cx
	int v2; // ebp
	int v3; // edi
	int v4; // si

	v1 = a1->mAnim;
	v2 = Animations[17 * a1->mRegion];
	v3 = (*(unsigned int *)(v2 + 8 * v1 + 8) >> 16) + 1;
	if (v3 != 1)
	{
		v4 = 0;
		v4 = word_6B2478[34 * a1->mRegion];
		print_if_false(v4 <= 0x1E, "Too many parts for TweenBuffer");
		M3dUtils_InterpolateVectors(
				4 * v4,
				v3,
				reinterpret_cast<unsigned int *>(v2),
				a1,
				0,
				v4);
	}
}

// @BIGTODO
void M3dUtils_BuildPose(CSuper*)
{}


// @BIGTODO
void M3dUtils_InterpolateVectors(int, int, unsigned int*, CItem*, int, int)
{}

// @BIGTODO
void M3dUtils_GetHookPosition(VECTOR*, CSuper*, i32)
{
	printf("void M3dUtils_GetHookPosition(VECTOR*, CSuper*, int)");
}

// @BIGTODO
void M3dUtils_GetDynamicHookPosition(VECTOR*, CSuper*, SHook*)
{
	printf("void M3dUtils_GetDynamicHookPosition(VECTOR*, CSuper*, SHook*)");
}

// @SMALLTODO
void M3dUtils_ReadHooksPacket(CSuper*, void*)
{
	printf("void M3dUtils_ReadHooksPacket(CSuper*, void*)");
}

void validate_SHook(void)
{
	VALIDATE_SIZE(SHook, 0x8);

	VALIDATE(SHook, Part, 0x0);
	VALIDATE(SHook, Offset, 0x6);
}
