#include "m3dinit.h"
#include "m3dcolij.h"
#include "validate.h"
#include "ob.h"

u32 gLineToItemRelated;

// @MEDIUMTODO
void M3dColij_InitLineInfo(SLineInfo *)
{
}

// @BIGTODO
i32 M3dColij_LineToSphere(CVector*, CVector*, CVector*, CBody*, CBody*, i32)
{
	return 0x03072024;
}

// @BIGTODO
void M3dColij_LineToThisItem(CItem*, SLineInfo*)
{
	printf("M3dColij_LineToThisItem");
}

// @SMALLTODO
void M3dColij_LineToItem(
		CItem* pItem,
		SLineInfo* pLine)
{
	if (pItem && pLine->field_44)
	{
		gte_SetRotMatrix(&pLine->field_48);
		M3dAsm_LineColijPreprocessItems(pItem, 0, pLine, pLine->field_8A);

		CItem *curItem = pItem;

		while (curItem)
		{
			if (curItem->field_6 != pLine->field_8A)
			{
				curItem->field_6 = pLine->field_8A;
				M3dColij_LineToThisItem(curItem, pLine);
			}

			curItem = reinterpret_cast<CItem*>(curItem->field_20);
		}

	}
}

void validate_SLineInfo(void)
{
	VALIDATE_SIZE(SLineInfo, 0x90);

	VALIDATE(SLineInfo, vec_0, 0x0);
	VALIDATE(SLineInfo, vec_C, 0xC);


	VALIDATE(SLineInfo, field_18, 0x18);
	VALIDATE(SLineInfo, field_1C, 0x1C);
	VALIDATE(SLineInfo, field_20, 0x20);
	VALIDATE(SLineInfo, field_24, 0x24);
	VALIDATE(SLineInfo, field_28, 0x28);
	VALIDATE(SLineInfo, field_2C, 0x2C);


	VALIDATE(SLineInfo, field_40, 0x40);
	VALIDATE(SLineInfo, field_44, 0x44);
	VALIDATE(SLineInfo, field_48, 0x48);
	VALIDATE(SLineInfo, field_68, 0x68);

	VALIDATE(SLineInfo, field_6C, 0x6C);
	VALIDATE(SLineInfo, field_70, 0x70);
	VALIDATE(SLineInfo, field_74, 0x74);
	VALIDATE(SLineInfo, field_78, 0x78);
	VALIDATE(SLineInfo, field_7A, 0x7A);
	VALIDATE(SLineInfo, field_7C, 0x7C);

	VALIDATE(SLineInfo, field_80, 0x80);
	VALIDATE(SLineInfo, field_84, 0x84);
	VALIDATE(SLineInfo, field_88, 0x88);
	VALIDATE(SLineInfo, field_89, 0x89);
	VALIDATE(SLineInfo, field_8A, 0x8A);
	VALIDATE(SLineInfo, field_8C, 0x8C);
}
