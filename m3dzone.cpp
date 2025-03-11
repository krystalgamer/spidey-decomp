#include "m3dzone.h"
#include "m3dcolij.h"
#include "my_assert.h"
#include "spool.h"

#include "validate.h"

#define NUM_ZONES 1
EXPORT SZone Zones[NUM_ZONES];

// @NotOk
// @Note: clean this up, too big and variable names were not okay on ghidra ;(
void M3dZone_LineToItem(
		SLineInfo *pInfo,
		i32 CheckEnviroObs)
{
	i32 v2; // ecx
	i32 vx; // esi
	i32 v4; // edi
	i32 vz; // ebx
	i32 v6; // ebp
	i32 xMin; // eax
	i32 v8; // esi
	i32 v9; // edi
	i32 Width; // eax
	i32 Height; // ecx
	i32 v12; // eax
	i32 v13; // edx
	i32 v14; // eax
	i32 v15; // eax
	i32 v16; // ecx
	i32 v17; // edi
	i32 v18; // ebp
	i32 v19; // ebx
	i32 v20; // esi
	i32 v22; // [esp+10h] [ebp-38h]
	i32 v23; // [esp+10h] [ebp-38h]
	i32 xMax; // [esp+18h] [ebp-30h]

	i32 v25; // [esp+18h] [ebp-30h]
	i32 v26; // [esp+18h] [ebp-30h]
	i32 zMax; // [esp+1Ch] [ebp-2Ch]
	i32 v28; // [esp+1Ch] [ebp-2Ch]
	i32 ZoneWidth; // [esp+24h] [ebp-24h]
	i32 v31; // [esp+28h] [ebp-20h]
	i32 v32; // [esp+2Ch] [ebp-1Ch]
	i32 v33; // [esp+30h] [ebp-18h]
	i32 v34; // [esp+34h] [ebp-14h]
	i32 v35; // [esp+38h] [ebp-10h]
	i32 v36; // [esp+3Ch] [ebp-Ch]
	i32 v37; // [esp+3Ch] [ebp-Ch]
	i32 v38; // [esp+40h] [ebp-8h]
	i32 v1; // [esp+50h] [ebp+8h]
	i32 v5; // [esp+50h] [ebp+8h]
	i32 v3; // [esp+50h] [ebp+8h]

	print_if_false(Zones[0].Flags != 0, "No zone information");

	M3dColij_OneMask = 0;
	M3dColij_ZeroMask = -1;
	if (LineOfSightCheck)
		M3dColij_OneMask = 0x400000;
	if (!BaddyCollisionCheck)
		M3dColij_OneMask ^= 0x200000u;
	if (CameraCollisionCheck)
		M3dColij_ZeroMask = 0xFFEFFFFF;
	if (TriggerCollisionCheck)
		M3dColij_ZeroMask ^= 0x20000u;
	if (CheckEnviroObs)
		M3dColij_LineToItem(&EnvironmentalObjectList[0], pInfo);

	for (i32 i = 0; i <= (NUM_ZONES - 1); i++)
	{
		if (Zones[i].Flags)
		{
			v2 = i;
			vx = pInfo->StartCoords.vx;
			v4 = pInfo->EndCoords.vx;
			vz = pInfo->StartCoords.vz;

			v6 = pInfo->EndCoords.vz;
			xMin = Zones[i].xMin;
			xMax = Zones[i].xMax;
			v1 = Zones[i].zMin;
			zMax = Zones[i].zMax;
			v22 = xMin;
			ZoneWidth = Zones[i].ZoneWidth;
			if ( pInfo->StartCoords.vx >= xMin || v4 >= xMin )
			{
				if (vx > xMax)
				{
					if (v4 > xMax)
						continue;
					v2 = i;
				}

				if (vz < v1)
				{
					if (v6 < v1)
						continue;
					v2 = i;
				}

				if (vz > zMax)
				{
					if ( v6 > zMax )
						continue;
					v2 = i;
				}

				if (vx == v4 && vz == v6)
				{
					v8 = (vx - xMin) / ZoneWidth;
					v9 = (vz - v1) / ZoneWidth;
					Width = Zones[v2].Width;

					if (v8 == Width)
					--v8;
					Height = Zones[v2].Height;
					if (v9 == Height)
						--v9;
					if (v8 < 0 || v8 >= Width || v9 < 0 || v9 >= Height)
						DoAssert(0, "Zone index out of range");
					else
						DoAssert(1u, "Zone index out of range");
					M3dColij_LineToItemZoned(
							reinterpret_cast<CItem**>(Zones[i].Ptr[v8][v9]),
							pInfo);
				}
				else
				{

					if ( vx < xMin )
					{
						if ( vz >= v6 )
							vz = v6 + M3dMaths_MulDiv64(v4 - xMin, vz - v6, v4 - vx);
						else
							vz += M3dMaths_MulDiv64(xMin - vx, v6 - vz, v4 - vx);
						vx = v22;
					}

					if ( v4 < v22 )
					{
						if ( v6 >= vz )
							v6 = vz + M3dMaths_MulDiv64(vx - v22, v6 - vz, vx - v4);
						else
							v6 += M3dMaths_MulDiv64(v22 - v4, vz - v6, vx - v4);
						v4 = v22;
					}

					if ( vx > xMax )
					{
						if ( v6 >= vz )
							vz += M3dMaths_MulDiv64(vx - xMax, v6 - vz, vx - v4);
						else
							vz = v6 + M3dMaths_MulDiv64(xMax - v4, vz - v6, vx - v4);
						vx = xMax;
					}

					if ( v4 > xMax )
					{
						if ( vz >= v6 )
							v6 += M3dMaths_MulDiv64(v4 - xMax, vz - v6, v4 - vx);
						else
							v6 = vz + M3dMaths_MulDiv64(xMax - vx, v6 - vz, v4 - vx);
						v4 = xMax;
					}

					if ( vz < v1 )
					{
						if ( vx >= v4 )
							vx = v4 + M3dMaths_MulDiv64(v6 - v1, vx - v4, v6 - vz);
						else
							vx += M3dMaths_MulDiv64(v1 - vz, v4 - vx, v6 - vz);
						vz = v1;
					}

					if ( v6 < v1 )
					{
						if ( v4 >= vx )
							v4 = vx + M3dMaths_MulDiv64(vz - v1, v4 - vx, vz - v6);
						else
							v4 += M3dMaths_MulDiv64(v1 - v6, vx - v4, vz - v6);
						v6 = v1;
					}

					if ( vz > zMax )
					{
						if ( v4 >= vx )
							vx += M3dMaths_MulDiv64(vz - zMax, v4 - vx, vz - v6);
						else
							vx = v4 + M3dMaths_MulDiv64(zMax - v6, vx - v4, vz - v6);
						vz = zMax;
					}

					if ( v6 > zMax )
					{
						if ( vx >= v4 )
							v4 += M3dMaths_MulDiv64(v6 - zMax, vx - v4, v6 - vz);
						else
							v4 = vx + M3dMaths_MulDiv64(zMax - vz, v4 - vx, v6 - vz);
						v6 = zMax;
					}

					v34 = v4 - vx;

					if ( v4 - vx >= 0 )
					{
						v35 = 1;
					}
					else
					{
						v35 = -1;
						v34 = vx - v4;
					}
					v33 = v6 - vz;

					if ( v6 - vz >= 0 )
					{
						v38 = 1;
					}

					else
					{
						v38 = -1;
						v33 = vz - v6;
					}

					v36 = vx - v22;
					v28 = (vx - v22) / ZoneWidth;
					v31 = (v4 - v22) / ZoneWidth;
					v23 = (vz - v1) / ZoneWidth;
					v32 = (v6 - v1) / ZoneWidth;
					v25 = v36 % ZoneWidth;
					v5 = (vz - v1) % ZoneWidth;
					v12 = Zones[i].Width;
					if ( v28 == v12 )
					{
						--v28;
						v25 += ZoneWidth;
					}
					v13 = Zones[i].Height;

					if ( v23 == v13 )
					{
						--v23;
						v5 += ZoneWidth;
						v13 = Zones[i].Height;
					}

					if ( v31 == v12 )
						--v31;

					if ( v32 == v13 )
						--v32;

					v37 = M3dMaths_MulDiv64(v34, v5, ZoneWidth);
					v14 = M3dMaths_MulDiv64(v33, v25, ZoneWidth);
					v26 = v28;
					v3 = v23;

					if ( vx >= v4 )
						v15 = -v14;
					else
						v15 = v14 - v33;

					if ( vz >= v6 )
						v16 = v37;
					else
						v16 = v34 - v37;

					v17 = v16 + v15;
					v18 = v28;
					v19 = v23;
					v20 = 20 * v28;
					while ( v18 != v31 || v19 != v32 )
					{
						if ( v18 < 0 )
							goto LABEL_112;
						v18 = v26;
						if (v26 >= Zones[i].Width)
							break;
						v19 = v3;
						if ( v3 < 0 || v3 >= Zones[i].Height )
							break;

						M3dColij_LineToItemZoned(
								reinterpret_cast<CItem**>(Zones[i].Ptr[0][v3 + v20]),
								pInfo);
						if ( v17 < 0 )
						{
							v17 += v34;
							v19 = v38 + v3;

							v3 += v38;
						}
						else
						{
							v18 = v35 + v26;
							v17 -= v33;
							v26 += v35;
							v20 += 20 * v35;
						}
					}
					if ( v18 >= 0 && v26 < Zones[i].Width && v3 >= 0 && v3 < Zones[i].Height )
						M3dColij_LineToItemZoned(
								reinterpret_cast<CItem**>(Zones[i].Ptr[v26][v3]),
								pInfo);
				}
			}


		}

LABEL_112:
		;
	}

	M3dColij_GetLineInfo(pInfo);
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
