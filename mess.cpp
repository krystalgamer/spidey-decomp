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

// @Ok
int Mess_TextHeight(char *pStr)
{
	return FontRelated.height(pStr);
}

static SimpleMessage** SimpleMessageList;

// @NotOk
// Revisit  to see if loop is ok
void Mess_ClearSimpleMessageList(void)
{
	while (1)
	{
		SimpleMessage* cur = *SimpleMessageList;
		if (!cur)
			break;

		DeleteSimpleMessage(cur);
	}
}

// @BIGTODO
void DeleteSimpleMessage(SimpleMessage*)
{}


// @SMALLTODO
void Mess_SetRGB(unsigned char, unsigned char, unsigned char, int)
{}

// @MEDIUMTODO
void Mess_SetCurrentFont(char *)
{}

void validate_SimpleMessage(void)
{
}


