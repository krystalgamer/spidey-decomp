#include "m3dzone.h"
#include "my_assert.h"
#include "spool.h"

#include "validate.h"

#define NUM_ZONES 1
EXPORT SZone Zones[NUM_ZONES];

// @SMALLTODO
void M3dZone_LineToItem(SLineInfo *, i32)
{
	printf("void M3dZone_LineToItem(SLineInfo *, int)");
}

// @Ok
// @Matching
INLINE void M3dZone_FreePSX(i32 EnvIndex)
{
	if (EnvIndex <= (NUM_ZONES-1))
	{
		Zones[EnvIndex].Flags = 0;

		for (i32 i = 0; i < 20; i++)
		{
			for (i32 j = 0; j < 20; j++)
			{
				Zones[EnvIndex].Ptr[i][j] = 0;
			}
		}
	}
}

// @Ok
// @Matching
void M3dZone_Init(void)
{
	M3dZone_FreePSX(0);
}

// @NotOk
// @Validate: slightly different register allocation and code gen
void M3dZone_SetZone(
		i32 EnvIndex,
		u32 *pPack)
{
	DoAssert(EnvIndex == 0, "EnvIndex not zero");

	Zones[EnvIndex].xMin = *pPack;
	Zones[EnvIndex].zMin = pPack[1];
	Zones[EnvIndex].xMax = pPack[2];
	Zones[EnvIndex].zMax = pPack[3];

	Zones[EnvIndex].Width = reinterpret_cast<i16*>(pPack)[8];
	Zones[EnvIndex].Height = reinterpret_cast<i16*>(pPack)[9];

	Zones[EnvIndex].Flags = 1;
	Zones[EnvIndex].ZoneWidth = (Zones[EnvIndex].xMax - Zones[EnvIndex].xMin) / Zones[EnvIndex].Width;

	DoAssert(Zones[EnvIndex].Width <= 20, "ZONE WIDTH TOO LARGE");
	DoAssert(Zones[EnvIndex].Height <= 20, "ZONE HEIGHT\tTOO LARGE");

	u32* v14 = &pPack[5];

	for (i32 i = 0; i < Zones[EnvIndex].Height; i++ )
	{
		for (i32 j = 0; j < Zones[EnvIndex].Width; j++ )
		{
			i32 v17 = v14[2];
			u32 *v18 = &v14[3];

			Zones[EnvIndex].Ptr[j][i] = reinterpret_cast<u32>(v18);

			while (v17-- > 0)
			{
				// @FIXME - wtf is that 64
				u32 *tmp = &reinterpret_cast<u32 *>(PSXRegion[EnvRegions[EnvIndex]].pSuper)[0x10 * *v18];
				*v18 = *tmp;
				++v18;

			}
			v14 = v18 + 1;
		}
	}
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
