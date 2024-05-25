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

void validate_WeirdTextureHolder(void)
{
	VALIDATE_SIZE(WeirdTextureHolder, 0x68);

	VALIDATE(WeirdTextureHolder, texture, 0x0);
	VALIDATE(WeirdTextureHolder, wScale, 0x4);
}
