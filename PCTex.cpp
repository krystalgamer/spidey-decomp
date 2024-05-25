#include "PCTex.h"
#include "validate.h"

static WeirdTextureHolder gGlobalTextures[2];

// @NotOk
// globals
void PCTex_SetTextureUserData(int index, Bitmap256* texture)
{
	gGlobalTextures[index].texture = texture;
}

// @NotOk
// globals
float PCTex_GetTextureWScale(int index)
{
	return gGlobalTextures[index].wScale;
}

// @NotOk
// globals
float PCTex_GetTextureHScale(int index)
{
	return gGlobalTextures[index].hScale;
}

// @NotOk
// globals
int PCTex_GetTextureFlags(int index)
{
	return gGlobalTextures[index].flags;
}

// @Ok
int __inline countBits(unsigned int value)
{
	int bits = 0;

	while (value)
	{
		bits += value & 1;
		value >>= 1;
	}
	
	return bits;
}

// @Ok
int __inline countLeadingBits(unsigned int value)
{
	int bits = 0;

	if (!value)
		return 0;

	while(!(value & 1))
	{
		value >>= 1;
		bits++;
	}

	return bits;
}

void validate_WeirdTextureHolder(void)
{
	VALIDATE_SIZE(WeirdTextureHolder, 0x68);

	VALIDATE(WeirdTextureHolder, texture, 0x0);
	VALIDATE(WeirdTextureHolder, wScale, 0x4);
	VALIDATE(WeirdTextureHolder, hScale, 0x8);
	VALIDATE(WeirdTextureHolder, flags, 0xC);
}
