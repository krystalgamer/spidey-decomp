#include "panel.h"


// @TODO
void Panel_CreateHealthBar(const CBody*, int)
{}

static unsigned char gPanelStatus;
// @NotOk
// Global
void Panel_DestroyCompass(void)
{
	gPanelStatus = 0;
}
