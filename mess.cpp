#include "mess.h"
#include "FontTools.h"
#include "mem.h"

#include "validate.h"

EXPORT u8 gTextJustify;

EXPORT SMessage* pMessages;
EXPORT SSimpleMessage* pSimpleMessages;

// @Ok
// @Matching
INLINE SMessage* CreateMessage(void)
{
	SMessage* newMessage = static_cast<SMessage*>(
			DCMem_New(sizeof(SMessage), 0, 1, 0, 1));

	newMessage->pPrevious = 0;
	newMessage->pNext = pMessages;

	pMessages = newMessage;

	if (newMessage->pNext)
		newMessage->pNext->pPrevious = newMessage;

	return newMessage;
}

// @Ok
SSimpleMessage* CreateSimpleMessage(void)
{
	SSimpleMessage* newMessage = static_cast<SSimpleMessage*>(
			DCMem_New(sizeof(SSimpleMessage), 0, 1, 0, 1));

	newMessage->pPrevious = 0;
	newMessage->pNext = pSimpleMessages;

	pSimpleMessages = newMessage;

	if (newMessage->pNext)
		newMessage->pNext->pPrevious = newMessage;

	return newMessage;
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

// @Ok
// @Matching
SMessage* Mess_Message(const char * pText, SMessageProg* pProg)
{
	SMessage* newMessage = CreateMessage();

	newMessage->pText = pText;
	newMessage->pProg = pProg;

	newMessage->T = 0;
	newMessage->T_total = 0;
	return newMessage;
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

// @NotOk
void Mess_ClearSimpleMessages(void)
{
	while (pSimpleMessages)
	{
		DeleteSimpleMessage(pSimpleMessages);
	}
}

// @BIGTODO
void DeleteSimpleMessage(SSimpleMessage*)
{}


// @SMALLTODO
void Mess_SetRGB(u8, u8, u8, i32)
{
	printf("void Mess_SetRGB(u8, u8, u8, i32)");
}

// @MEDIUMTODO
void Mess_SetCurrentFont(char *)
{}

void validate_SimpleMessage(void)
{
	VALIDATE_SIZE(SSimpleMessage, 0x24);

	VALIDATE(SSimpleMessage, pNext, 0x1C);
	VALIDATE(SSimpleMessage, pPrevious, 0x20);
}

void validate_SMessageProg(void)
{
}

void validate_SMessage(void)
{
	VALIDATE_SIZE(SMessage, 0x1C);

	VALIDATE(SMessage, pText, 0x0);
	VALIDATE(SMessage, T, 0x4);
	VALIDATE(SMessage, T_total, 0x6);

	VALIDATE(SMessage, pProg, 0x10);
	VALIDATE(SMessage, pNext, 0x14);
	VALIDATE(SMessage, pPrevious, 0x18);
}
