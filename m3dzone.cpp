#include "m3dzone.h"

#include "validate.h"

// @SMALLTODO
void M3dZone_LineToItem(SLineInfo *, i32)
{
	printf("void M3dZone_LineToItem(SLineInfo *, int)");
}

// @SMALLTODO
void M3dZone_FreePSX(i32)
{
    printf("M3dZone_FreePSX(i32)");
}

// @Ok
// @Matching
INLINE void M3dZone_Init(void)
{
	M3dZone_FreePSX(0);
}

// @SMALLTODO
void M3dZone_SetZone(i32,u32 *)
{
    printf("M3dZone_SetZone(i32,u32 *)");
}

void validate_SZone(void)
{
	VALIDATE_SIZE(SZone, 0x660);

	VALIDATE(SZone, Flags, 0x0);

	VALIDATE(SZone, xMin, 0x4);
	VALIDATE(SZone, zMin, 0x8);
	VALIDATE(SZone, xMax, 0xC);
	VALIDATE(SZone, zMax, 0x10);

	VALIDATE(SZone, ZoneWidth, 0x14);
	VALIDATE(SZone, ZoneHeight, 0x18);

	VALIDATE(SZone, Width, 0x1C);
	VALIDATE(SZone, Height, 0x1E);

	VALIDATE(SZone, Ptr, 0x20);
}
