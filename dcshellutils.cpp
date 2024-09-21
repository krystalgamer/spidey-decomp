#include "dcshellutils.h"
#include "validate.h"
#include "m3dinit.h"
#include "SpideyDX.h"
#include "PCGfx.h"

i32 gDcSpriteRedAmount[256];
i32 gDcSpriteGreenAmount[256];
i32 gDcSpriteBlueAmount[256];

// @Ok
// @Validate
INLINE void DCSpriteDraw(
		i32 a1,
		i32 a2,
		i32 a3,
		float a4,
		u32 a5,
		u32 a6,
		u32 a7,
		i32 a8,
		u32 a9,
		float a10)
{
	if (a1 != -1)
	{
		if (a5 > 0xFF)
			a5 = 0xFF;

		if (a6 > 0xFF)
			a6 = 0xFF;

		if (a7 > 0xFF)
			a7 = 0xFF;

		gDcSpriteRedAmount[a5]++;
		gDcSpriteGreenAmount[a6]++;
		gDcSpriteBlueAmount[a7]++;
		
		PCGfx_DrawTexture2D(
				a1,
				a2,
				a3,
				a4,
				a7 | (a6 << 8) | (a5 << 16) | (a8 << 24),
				a9,
				a10);
	}
}

// @SMALLTODO
void Sprite2::setData(void*)
{
	printf("Sprite2::setData(void*)");
}

// @SMALLTODO
Sprite2::Sprite2(const char*, i32, i32, i32, u32)
{
	printf("Sprite2::Sprite2(const char*, i32, i32, i32, u32)");
}

// @BIGTODO
void Load8BitBMP2(char *a1, char **a2, int *a3, int *a4, unsigned __int16 *a5, bool a6)
{

	printf("void Load8BitBMP2(char *a1, char **a2, int *a3, int *a4, unsigned __int16 *a5, bool a6)");
}

void validate_Sprite2(void)
{
	VALIDATE_SIZE(Sprite2, 0x24);
}
