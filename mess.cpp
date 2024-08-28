#include "mess.h"
#include "FontTools.h"

EXPORT u8 gTextJustify;

// @SMALLTODO
void CreateMessage(void)
{
    printf("CreateMessage(void)");
}

// @SMALLTODO
void CreateSimpleMessage(void)
{
    printf("CreateSimpleMessage(void)");
}

// @SMALLTODO
void Mess_ClearSimpleMessages(void)
{
    printf("Mess_ClearSimpleMessages(void)");
}

// @SMALLTODO
void Mess_DeleteAll(void)
{
    printf("Mess_DeleteAll(void)");
}

// @SMALLTODO
void Mess_Display(void)
{
    printf("Mess_Display(void)");
}

// @SMALLTODO
void Mess_DrawText(i32,i32,char const *,i32,u32)
{
    printf("Mess_DrawText(i32,i32,char const *,i32,u32)");
}

// @SMALLTODO
void Mess_GetScale(void)
{
    printf("Mess_GetScale(void)");
}

// @SMALLTODO
void Mess_GetSort(void)
{
    printf("Mess_GetSort(void)");
}

// @SMALLTODO
void Mess_LoadFont(char *,i32,i32,i32)
{
    printf("Mess_LoadFont(char *,i32,i32,i32)");
}

// @SMALLTODO
void Mess_Message(char const *,SMessageProg *)
{
    printf("Mess_Message(char const *,SMessageProg *)");
}

// @SMALLTODO
void Mess_SetShadowRGB(u8)
{
    printf("Mess_SetShadowRGB(u8)");
}

// @SMALLTODO
void Mess_SetSort(i32)
{
    printf("Mess_SetSort(i32)");
}

// @SMALLTODO
void Mess_ShadowsOff(void)
{
    printf("Mess_ShadowsOff(void)");
}

// @SMALLTODO
void Mess_ShadowsOn(void)
{
    printf("Mess_ShadowsOn(void)");
}

// @SMALLTODO
void Mess_SimpleMessage(char const *,u32,u32,u32)
{
    printf("Mess_SimpleMessage(char const *,u32,u32,u32)");
}

// @SMALLTODO
i32 Mess_TextWidth(const char*)
{
    printf("Mess_TextWidth(char const *)");
	return 0x28082024;
}

// @SMALLTODO
void Mess_UnloadAllFonts(void)
{
    printf("Mess_UnloadAllFonts(void)");
}

// @SMALLTODO
void Mess_Update(void)
{
    printf("Mess_Update(void)");
}

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


void validate_SMessageProg(void)
{
}
