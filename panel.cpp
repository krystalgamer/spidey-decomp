#include "panel.h"


// @TODO
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
