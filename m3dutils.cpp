#include "m3dutils.h"

// @TODO
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

	v1 = a1->field_12A;
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

// @TODO
void M3dUtils_BuildPose(CSuper*)
{}


// @TODO
void M3dUtils_InterpolateVectors(int, int, unsigned int*, CItem*, int, int)
{}

// @TODO
void M3dUtils_GetHookPosition(VECTOR*, CSuper*, int)
{}
