#include "mess.h"
#include "FontTools.h"
#include "mem.h"
#include "bit.h"

#include "validate.h"

EXPORT u8 gTextJustify;

EXPORT SMessage* pMessages;
EXPORT SSimpleMessage* pSimpleMessages;
EXPORT Font gMessFont;
EXPORT u16 gScale;

EXPORT i32 gMessRelated;


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

// @Ok
// For the life of me, can't get it to match the assembly is too obtuse
// I think the developers wrote some macros that when expanded looked weird
void Mess_DeleteAll(void)
{
	SMessage *curMessage = pMessages;
	while (curMessage)
	{
		SMessage* nextMessage = curMessage->pNext;
		Mem_Delete(curMessage);

		curMessage = nextMessage;
	}

	pMessages = 0;

	SSimpleMessage *curSimpleMessage = pSimpleMessages;
	while (curSimpleMessage)
	{
		SSimpleMessage* nextMessage = curSimpleMessage->pNext;
		Mem_Delete(curSimpleMessage);
		curSimpleMessage = nextMessage;
	}

	pSimpleMessages = 0;
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

// @Ok
i32 Mess_GetScale(void)
{
	return gScale;
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

// @Ok
void Mess_ShadowsOff(void)
{
	FontManager::AllShadowOff();
}

// @Ok
void Mess_ShadowsOn(void)
{
	FontManager::AllShadowOn();
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

// @Ok
void Mess_UnloadAllFonts(void)
{
	FontManager::UnloadAllFonts();
}

// @Ok
void Mess_Update(void)
{
	if (!gMessRelated)
		gMessRelated = gTimerRelated - 2;

	i32 v1 = gTimerRelated - gMessRelated;
	SSimpleMessage* pMessage = pSimpleMessages;
	gMessRelated = gTimerRelated;

	while (pMessage)
	{
		pMessage->field_4 += v1;

		if (pMessage->field_4 > pMessage->field_8 + 90)
		{
			SSimpleMessage *next = pMessage->pNext;
			DeleteSimpleMessage(pMessage);
			pMessage = next;
		}
		else
		{
			if (pMessage->field_4 > pMessage->field_8 + 30)
			{
				pMessage->field_18 = 4096 - ((pMessage->field_4 - (pMessage->field_8 + 30)) << 12) / 60;
			}
			else if (pMessage->field_4 > 60)
			{
				pMessage->field_18 = 4096;
			}
			else
			{
				pMessage->field_18 = (pMessage->field_4 << 12) / 60;
			}

			pMessage = pMessage->pNext;
		}
	}
}

// @NotOk
// Global
void Mess_SetTextJustify(unsigned char value)
{
	gTextJustify = value;
}

// @NotOk
// Global
void Mess_SetScale(int value)
{
	gScale = value;
}

static int gRGBBottom;
// @NotOk
// global
void Mess_SetRGBBottom(unsigned char a2, unsigned char a3, unsigned char a4)
{
	gRGBBottom = a2 | (a3 << 8) | (a4 << 16);
}

// @NotOk
// global
void Mess_UnloadFont(void)
{
	FontManager::UnloadFont(&gMessFont);
}

// @Ok
char* Mess_GetCurrentFont(void)
{
	return FontManager::GetFontName(&gMessFont);
}

// @Ok
int Mess_TextHeight(char *pStr)
{
	return gMessFont.height(pStr);
}

// @Ok
// @Matching
void Mess_ClearSimpleMessages(void)
{
	while (pSimpleMessages)
	{
		DeleteSimpleMessage(pSimpleMessages);
	}
}

// @Ok
// @Matching
INLINE void DeleteSimpleMessage(SSimpleMessage* pMessage)
{
	print_if_false(pMessage != 0, "Tried to delete a NULL pMessage");

	if (pMessage->pNext)
		pMessage->pNext->pPrevious = pMessage->pPrevious;

	if (pMessage->pPrevious)
		pMessage->pPrevious->pNext = pMessage->pNext;

	if (pMessage == pSimpleMessages)
		pSimpleMessages = pMessage->pNext;

	Mem_Delete(pMessage);
}


// @Ok
// @Matching
void Mess_SetRGB(u8 r, u8 g, u8 b, i32)
{
	gMessFont.mRed = r;
	gMessFont.mGreen = g;
	gMessFont.mBlue = b;
}

// @Ok
void Mess_SetCurrentFont(char* a1)
{
	Font* pFont = FontManager::GetFont(a1);
	/*
	gMessFont.field_4 = pFont->field_4;
	gMessFont.field_8 = pFont->field_8;
	gMessFont.field_C = pFont->field_C;
	gMessFont.field_10 = pFont->field_10;

	gMessFont.mRed = pFont->mRed;
	gMessFont.mGreen = pFont->mGreen;
	gMessFont.mBlue = pFont->mBlue;

	gMessFont.field_20 = pFont->field_20;
	gMessFont.field_21 = pFont->field_21;
	gMessFont.field_24 = pFont->field_24;
	gMessFont.field_28 = pFont->field_28;
	gMessFont.field_2C = pFont->field_2C;
	gMessFont.field_30 = pFont->field_30;
	gMessFont.field_34 = pFont->field_34;

	gMessFont.field_48 = pFont->field_48;
	gMessFont.field_4C = pFont->field_4C;
	gMessFont.field_50 = pFont->field_50;
	gMessFont.field_54 = pFont->field_54;
	gMessFont.field_58 = pFont->field_58;
	gMessFont.field_5C = pFont->field_5C;
	gMessFont.field_5D = pFont->field_5D;
	gMessFont.field_5E = pFont->field_5E;
	*/

	gMessFont = *pFont;
}

void validate_SimpleMessage(void)
{
	VALIDATE_SIZE(SSimpleMessage, 0x24);

	VALIDATE(SSimpleMessage, field_4, 0x4);
	VALIDATE(SSimpleMessage, field_8, 0x8);

	VALIDATE(SSimpleMessage, field_18, 0x18);
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
