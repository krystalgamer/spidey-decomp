#include "mess.h"

static unsigned char gTextJustify;

// @NotOk
// Global
void Mess_SetTextJustify(unsigned char value)
{
	gTextJustify = value;
}

static unsigned __int16 gTextScale;

// @NotOk
// Global
void Mess_SetScale(int value)
{
	gTextScale = value;
}
