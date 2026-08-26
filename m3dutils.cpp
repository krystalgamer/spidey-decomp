#include "m3dutils.h"
#include "validate.h"

#include "spool.h"

#include "my_assert.h"

// @Ok
// @Matching
void M3dUtils_ReadLinksPacket(CSuper* pSuper, void* pPacket)
{
	i32 NumJoints = reinterpret_cast<u16*>(pPacket)[1];
	pSuper->mpLinks = reinterpret_cast<SLink*>(reinterpret_cast<i32>(pPacket) + 4);

	// @Note: it's important to hoist this calculation or else the funciton wouldn't match
	// size would be the same but registers and order of instructions would be slightly off here
	i32 matrixSize = sizeof(SMatrix) * G_PSXREGION[pSuper->mRegion].NumParts;
	pSuper->mpPoseBuffer = static_cast<SMatrix *>(DCMem_New(
		matrixSize,
		0,
		1,
		0,
		1));
	pSuper->mpJoints = static_cast<SJoint *>(
			DCMem_New(sizeof(SJoint) * NumJoints, 0, 1, 0, 1));

	for (i32 i = 0; i < NumJoints; ++i )
	{
		pSuper->mpJoints[i].Displacement.vz = 0;
		pSuper->mpJoints[i].Displacement.vy = 0;
		pSuper->mpJoints[i].Displacement.vx = 0;

		pSuper->mpJoints[i].Angles.vz = 0;
		pSuper->mpJoints[i].Angles.vy = 0;
		pSuper->mpJoints[i].Angles.vx = 0;
	}

	for (i32 j = 0; j < NumJoints; j++)
	{
		i32 k;
		for (k = 0; k < NumJoints; k++)
		{
			if (pSuper->mpLinks[j].ParentPart == pSuper->mpLinks[k].Part)
			{
				pSuper->mpLinks[j].ParentLink = k;
				break;
			}
		}

		if (k == NumJoints)
		{
			pSuper->mpLinks[j].ParentLink = 0xFFFF;
		}
	}
}

// @Ok
// @Matching
void M3dUtils_InBetween(CSuper *pSuper)
{
	u32 *pAnimFile = G_PSXREGION[pSuper->mRegion].pAnimFile;
    i32 Interval =  (pAnimFile[2 * pSuper->mAnim + 2] >> 16) + 1;
    
	if (Interval != 1)
	{
		i32 NumParts = G_PSXREGION[pSuper->mRegion].NumParts;
		ASSERT(NumParts <= 30, "Too many parts for TweenBuffer");

		M3dUtils_InterpolateVectors(
				4 * NumParts,
				Interval,
				pAnimFile,
				pSuper,
				0,
				NumParts);
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
void M3dUtils_InterpolateVectors(i32 NumVectors, i32 Interval, u32* pAnimFile, CItem* pItem, i32 Part, i32 NumParts)
{
	typedef void (*func_ptr)(i32, i32, u32*, CItem*, i32,i32);

	func_ptr func = (func_ptr)0x00454270;
	func(NumVectors, Interval, pAnimFile, pItem, Part, NumParts);
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
	PATCH_PUSH_RET(0x00454200, M3dUtils_InBetween);

	PATCH_PUSH_RET(0x00453C50, M3dUtils_ReadLinksPacket);
}
