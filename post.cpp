#include "post.h"
#include "bit.h"

EXPORT i32 gWaterEffect;
EXPORT i32 gPostTimerRelated;
EXPORT u16 gPostWordRelated;

// @SMALLTODO
void Post_DoPauseDisplayListProcessing(void)
{
    printf("Post_DoPauseDisplayListProcessing(void)");
}

// @SMALLTODO
void Post_DoPausePaletteProcessing(void)
{
    printf("Post_DoPausePaletteProcessing(void)");
}

// @Ok
// @Validate: when WaterEffect inlined
void Post_PostProcessEffects(void)
{
	if (gWaterEffect)
	{
		gPostTimerRelated = 48 * gTimerRelated;
		Post_WaterEffect();
	}
	if (gPostWordRelated)
	{
		--gPostWordRelated;
	}
}

// @MEDIUMTODO
void Post_SpideyLogo(void)
{
    printf("Post_SpideyLogo(void)");
}

// @SMALLTODO
void Post_UndoPausePaletteProcessing(void)
{
    printf("Post_UndoPausePaletteProcessing(void)");
}

// @SMALLTODO
void Post_WaterEffect(void)
{
    printf("Post_WaterEffect(void)");
}
