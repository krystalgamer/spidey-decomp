#include "m3dinit.h"
#include "m3dcolij.h"
#include "validate.h"
#include "ob.h"

// @Ok
u16	Inquiry=0xFFFF;

// @Ok
SLineInfo gLineInfo;

i32 LineOfSightCheck;

u32 M3dColij_OneMask;
u32 M3dColij_ZeroMask;

i32 BaddyCollisionCheck;
i32 CameraCollisionCheck;
i32 TriggerCollisionCheck;

// @NotOk
// @FIXME - check ppc version to address this
i16 gUnkPose[1];

// @SMALLTODO
void M3dColij_GetLineInfo(SLineInfo *)
{
    printf("M3dColij_GetLineInfo(SLineInfo *)");
}

// @Ok
// @Matching
void M3dColij_LineInfoFixup(SLineInfo *pInfo)
{
	i32 v2 = M3dMaths_MulDiv64(pInfo->Distance, 0x4000, pInfo->Length);
	i32 v3 = pInfo->EndCoords.vx - pInfo->StartCoords.vx;
	i32 v5 = pInfo->EndCoords.vy - pInfo->StartCoords.vy;
	i32 v4 = pInfo->EndCoords.vz - pInfo->StartCoords.vz;

	i32 v8 = (v3 < 0 ? -1 : 1) * M3dMaths_MulDiv64(my_abs(v3), v2, 0x4000);
	i32 v6 = (v5 < 0 ? -1 : 1) * M3dMaths_MulDiv64(my_abs(v5), v2, 0x4000);
	i32 v7 = (v4 < 0 ? -1 : 1) * M3dMaths_MulDiv64(my_abs(v4), v2, 0x4000);

	pInfo->Position.vx = v8 + pInfo->StartCoords.vx;
	pInfo->Position.vy = v6 + pInfo->StartCoords.vy;
	pInfo->Position.vz = v7 + pInfo->StartCoords.vz;
}

// @Ok
// @Leak
// @Matching
void M3dColij_LineToItemZoned(CItem **ppItem,SLineInfo *pInfo)
{
	if	(!ppItem) return;

	if (pInfo->Length==0)
		return;

	gte_SetRotMatrix(&pInfo->WorldCst);

	M3dAsm_LineColijPreprocessItemsZoned(ppItem,0,pInfo,pInfo->Inquiry);

	for (	; *ppItem; ppItem++)
		if	((*ppItem)->mInquiry != pInfo->Inquiry)
		{
			(*ppItem)->mInquiry =	pInfo->Inquiry;


			M3dColij_LineToThisItem(*ppItem, pInfo);
		}
}

// @Ok
// @Leak
INLINE void NextInquiry(void)
{
	// increment inquiry
	// if it's 0, set to 1 and set all objects' inquiry fields to 0.
	// If this weren't done, a rare bug may occur where the previous collision test with a particular object was
	// performed 65536 tests ago, and the current test would automatically fail.
	if	(!++Inquiry)
	{
		CItem	*pItem;
		Inquiry=1;
		for (pItem=EnviroList; pItem; pItem=pItem->mNextItem)
			pItem->mInquiry=0;
		for (pItem=EnvironmentalObjectList; pItem; pItem=pItem->mNextItem)
			pItem->mInquiry=0;
	}
}


// @MEDIUMTODO
void M3dColij_InitLineInfo(SLineInfo *)
{
	printf("void M3dColij_InitLineInfo(SLineInfo *)");
}

// @BIGTODO
i32 M3dColij_LineToSphere(CVector*, CVector*, CVector*, CBody*, CBody*, i32)
{
	printf("i32 M3dColij_LineToSphere(CVector*, CVector*, CVector*, CBody*, CBody*, i32)");
	return 0x03072024;
}

// @BIGTODO
void M3dColij_LineToThisItem(CItem* pItem, SLineInfo* pInfo)
{
	typedef void (*func_ptr)(CItem*, SLineInfo*);
	func_ptr func = (func_ptr)0x004529C0;

	func(pItem, pInfo);
}

// @Ok
// @Leak
// @Matching
void M3dColij_LineToItem(
		CItem* pItem,
		SLineInfo* pInfo)
{

	if	(!pItem)	return;

	if (pInfo->Length==0)
		return;

	gte_SetRotMatrix(&pInfo->WorldCst);
	M3dAsm_LineColijPreprocessItems(pItem, 0, pInfo, pInfo->Inquiry);

	for (	; pItem;	pItem=pItem->mNextItem)
		if	(pItem->mInquiry != pInfo->Inquiry)
		{
			pItem->mInquiry	= pInfo->Inquiry;
			M3dColij_LineToThisItem(pItem, pInfo);
		}
}

void validate_Vector(void)
{
	VALIDATE_SIZE(Vector, 0xC);

	VALIDATE(Vector, vx, 0x0);
	VALIDATE(Vector, vy, 0x4);
	VALIDATE(Vector, vz, 0x8);
}

void validate_SLineInfo(void)
{
	VALIDATE_SIZE(SLineInfo, 0xA4);

	VALIDATE(SLineInfo, StartCoords, 0x0);
	VALIDATE(SLineInfo, EndCoords, 0xC);


	VALIDATE(SLineInfo, MinCoords, 0x18);

	VALIDATE(SLineInfo, MaxCoords, 0x24);

	VALIDATE(SLineInfo, iLo, 0x30);
	VALIDATE(SLineInfo, iHi, 0x34);
	VALIDATE(SLineInfo, jLo, 0x38);
	VALIDATE(SLineInfo, jHi, 0x3C);

	VALIDATE(SLineInfo, Distance, 0x40);
	VALIDATE(SLineInfo, Length, 0x44);

	VALIDATE(SLineInfo, WorldCst, 0x48);

	VALIDATE(SLineInfo, pItem, 0x68);

	VALIDATE(SLineInfo, Position, 0x6C);

	VALIDATE(SLineInfo, Normal, 0x78);

	VALIDATE(SLineInfo, pFace, 0x80);
	VALIDATE(SLineInfo, Model, 0x84);

	VALIDATE(SLineInfo, RecordTriggerZoneHits, 0x88);
	VALIDATE(SLineInfo, DropDown, 0x89);

	VALIDATE(SLineInfo, Inquiry, 0x8A);
	VALIDATE(SLineInfo, tNear, 0x8C);

	VALIDATE(SLineInfo, tNumtrLo, 0x90);
	VALIDATE(SLineInfo, tNumtrHi, 0x94);
	VALIDATE(SLineInfo, tDenomLo, 0x98);
	VALIDATE(SLineInfo, tDenomHi, 0x9C);
	VALIDATE(SLineInfo, NormalOffset, 0xA0);
}

#include "my_patch.h"

// @Bogus
void patch_m3dcolij(void)
{
	PATCH_PUSH_RET(0x004527C0, M3dColij_LineToItem);
	PATCH_PUSH_RET(0x00452820, M3dColij_LineToItemZoned);
	PATCH_PUSH_RET(0x004528E0, M3dColij_LineInfoFixup);
}
