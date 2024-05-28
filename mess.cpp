#include "mess.h"
#include "FontTools.h"

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

static int gRGBBottom;
// @NotOk
// global
void Mess_SetRGBBottom(unsigned char a2, unsigned char a3, unsigned char a4)
{
	gRGBBottom = a2 | (a3 << 8) | (a4 << 16);
}

static Font FontRelated;

// @NotOk
// global
void Mess_UnloadFont(void)
{
	FontManager::UnloadFont(&FontRelated);
}

char* Mess_GetCurrentFont(void)
{
	return FontManager::GetFontName(&FontRelated);
}
