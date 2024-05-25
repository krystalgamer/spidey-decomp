#include "PCTex.h"
#include "validate.h"

static WeirdTextureHolder gGlobalTextures[2];

// @NotOk
// globals
void PCTex_SetTextureUserData(int index, Bitmap256* texture)
{
	gGlobalTextures[index].texture = texture;
}

void validate_WeirdTextureHolder(void)
{
	VALIDATE_SIZE(WeirdTextureHolder, 0x68);

	VALIDATE(WeirdTextureHolder, texture, 0x0);
}
