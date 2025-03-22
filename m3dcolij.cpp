#include "m3dinit.h"
#include "m3dcolij.h"
#include "validate.h"
#include "ob.h"

i32 LineOfSightCheck;

u32 M3dColij_OneMask;
u32 M3dColij_ZeroMask;

i32 BaddyCollisionCheck;
i32 CameraCollisionCheck;
i32 TriggerCollisionCheck;

// @SMALLTODO
void M3dColij_GetLineInfo(SLineInfo *)
{
    printf("M3dColij_GetLineInfo(SLineInfo *)");
}

// @SMALLTODO
void M3dColij_LineInfoFixup(SLineInfo *)
{
    printf("M3dColij_LineInfoFixup(SLineInfo *)");
}

// @SMALLTODO
void M3dColij_LineToItemZoned(CItem **,SLineInfo *)
{
    printf("M3dColij_LineToItemZoned(CItem **,SLineInfo *)");
}

// @SMALLTODO
void NextInquiry(void)
{
    printf("NextInquiry(void)");
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
void M3dColij_LineToThisItem(CItem*, SLineInfo*)
{
	printf("M3dColij_LineToThisItem");
}

// @NotOk
// was marked as todo but had body, so need to recheck
void M3dColij_LineToItem(
		CItem* pItem,
		SLineInfo* pLine)
{
	if (pItem && pLine->Length)
	{
		gte_SetRotMatrix(&pLine->WorldCst);
		M3dAsm_LineColijPreprocessItems(pItem, 0, pLine, pLine->Inquiry);

		CItem *curItem = pItem;

		while (curItem)
		{
			if (curItem->mInquiry != pLine->Inquiry)
			{
				curItem->mInquiry = pLine->Inquiry;
				M3dColij_LineToThisItem(curItem, pLine);
			}

			curItem = reinterpret_cast<CItem*>(curItem->mNextItem);
		}

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
