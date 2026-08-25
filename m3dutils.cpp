#include "m3dutils.h"
#include "validate.h"

#include "spool.h"

// @SMALLTODO
void M3dUtils_ReadLinksPacket(CSuper* a1, void* a2)
{
	typedef void (*func_ptr)(CSuper*, void*);
	func_ptr func = (func_ptr)0x00453C50;

	func(a1, a2);
}

// @NotOk
// Revisit and fix globals
void M3dUtils_InBetween(CSuper *a1)
{

	typedef void (*func_ptr)(CSuper*);

	func_ptr func = (func_ptr)0x00454200;
	func(a1);
	return;

	u16 v1; // cx
	i32 v2; // ebp
	i32 v3; // edi
	i32 v4; // si

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
				reinterpret_cast<u32*>(v2),
				a1,
				0,
				v4);
	}
}

// @BIGTODO
void M3dUtils_BuildPose(CSuper* pSuper)
{
	typedef void (*func_ptr)(CSuper*);
	func_ptr func = (func_ptr)0x00454450;
	func(pSuper);
}


// @BIGTODO
void M3dUtils_InterpolateVectors(i32, i32, u32*, CItem*, i32, i32)
{
	printf("void M3dUtils_InterpolateVectors(int, int, unsigned int*, CItem*, int, int)");
}

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

// @Ok
// @Matching
void M3dUtils_ReadHooksPacket(CSuper* pSuper, void* pPacket)
{
	G_PSXREGION[pSuper->mRegion].pHooks = reinterpret_cast<SHook*>(reinterpret_cast<i32>(pPacket) + 4);
}

void validate_SHook(void)
{
	VALIDATE_SIZE(SHook, 0x8);

	VALIDATE(SHook, Part, 0x0);
	VALIDATE(SHook, Offset, 0x6);
}


#include "my_patch.h"

// @Bogus
void patch_m3dutils(void)
{
	PATCH_PUSH_RET(0x00453C30, M3dUtils_ReadHooksPacket);
}
