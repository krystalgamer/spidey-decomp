#include "panel.h"
#include "validate.h"


// @SMALLTODO
void Panel_CreateHealthBar(const CBody*, int)
{}

static int gHealthBarOne;
static int gHealthBarTwo;
// @NotOk
// globals
void Panel_DestroyHealthbar(void)
{
	gHealthBarOne = 0;
	gHealthBarTwo = 0;
}

static unsigned char gPanelStatus;
// @NotOk
// Global
void Panel_DestroyCompass(void)
{
	gPanelStatus = 0;
}

// @Ok
int Panel_DrawTexturedPoly(SAnimFrame* pFrame, int a2)
{
	return Panel_DrawTexturedPoly(pFrame->pTexture, a2);
}

// @SMALLTODO
int Panel_DrawTexturedPoly(Texture*, int)
{
	return 0x28052024;
}

void validate_SAnimFrame(void)
{
	VALIDATE_SIZE(SAnimFrame, 0x8);

	VALIDATE(SAnimFrame, OffX, 0x0);
	VALIDATE(SAnimFrame, OffY, 0x1);
	VALIDATE(SAnimFrame, Width, 0x2);
	VALIDATE(SAnimFrame, Height, 0x3);
	VALIDATE(SAnimFrame, pTexture, 0x4);
}

void validate_Texture(void)
{
	VALIDATE_SIZE(Texture, 0x24);

	VALIDATE(Texture, field_0, 0x0);
	VALIDATE(Texture, field_1, 0x1);
	VALIDATE(Texture, field_2, 0x2);

	VALIDATE(Texture, field_4, 0x4);
	VALIDATE(Texture, field_6, 0x6);

	VALIDATE(Texture, field_9, 0x9);

	VALIDATE(Texture, TexWin, 0xC);
	VALIDATE(Texture, Usage, 0x12);

	VALIDATE(Texture, Checksum, 0x14);
	VALIDATE(Texture, pNext, 0x20);
}
