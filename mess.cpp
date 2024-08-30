#include "mess.h"
#include "FontTools.h"
#include "mem.h"
#include "bit.h"

#include <cstring>

#include "validate.h"

EXPORT u8 gTextJustify;

EXPORT SMessage* pMessages;
EXPORT SSimpleMessage* pSimpleMessages;
EXPORT Font gMessFont;
EXPORT u16 gScale;
EXPORT u16 gSort;

EXPORT i32 gMessRelated;
EXPORT i32 gRGBBottom = 0x808080;

EXPORT u8 gShadowRGB = 0x80;

EXPORT char gMessFontName[32];
EXPORT u8 gMessFontLoaded;

EXPORT u32 gSimpleMessageRelated;
EXPORT i32 gSimpleMessageTextWidth;


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
INLINE SSimpleMessage* CreateSimpleMessage(void)
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

// @Ok
// @Matching
void Mess_Display(void)
{
	SSimpleMessage* pMess = pSimpleMessages;
	Mess_SetTextJustify(1);
	Mess_SetRGB(0x60, 0x60, 0x80, 0);

	while (pMess)
	{
		Mess_SetScale(pMess->field_14);
		Mess_DrawText(
				pMess->field_C,
				pMess->field_10,
				pMess->field_0,
				0,
				pMess->field_18);

		pMess = pMess->pNext;
	}
}

// @Ok
i32 Mess_DrawText(
		i32 a1,
		i32 a2,
		const char * a3,
		i32 a4,
		u32 a5)
{
	switch (gTextJustify)
	{
		case 0:
			gMessFont.field_4 = 1;
			break;
		case 1:
			gMessFont.field_4 = 0;
			break;
		case 2:
			gMessFont.field_4 = 2;
			break;
	}

	gMessFont.field_34 = 8 * gScale;

	float v6;
	switch (gSort)
	{
		case 4093:
			v6 = 6.0999999f;
			break;
		case 4094:
			v6 = -4.0f;
			break;
		case 4095:
			v6 = -3.0f;
			break;
		default:
			v6 = 4.0f;
			break;
	}

	gMessFont.draw(a1, a2, a3, 8, v6);
	return 0;
}

// @Ok
i32 Mess_GetScale(void)
{
	return gScale;
}

// @Ok
i32 Mess_GetSort(void)
{
	return gSort;
}

// @Ok
i32 Mess_LoadFont(
		const char* pName,
		i32 a2,
		i32 a3,
		i32 a4)
{
	Font* pFont = FontManager::LoadFont(pName);
	gMessFont = *pFont;

	strcpy(gMessFontName, pName);

	gMessFont.field_C = a2;
	gMessFont.field_10 = a2;

	gMessFont.field_24 = a3;
	gMessFont.field_28 = a3;
	gMessFont.field_8 = 1;

	gMessFontLoaded = 1;

	return 0;
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

// @Ok
void Mess_SetShadowRGB(u8 rgb)
{
	if (rgb < 0x80)
		rgb = 0x80;

	gShadowRGB = rgb;
}

// @Ok
void Mess_SetSort(i32 sort)
{
	gSort = sort;
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

// @Ok
SSimpleMessage* Mess_SimpleMessage(
		const char * a1,
		u32 a2,
		u32 a3,
		u32 a4)
{
	SSimpleMessage* pMessage = CreateSimpleMessage();

	pMessage->field_0 = a1;
	pMessage->field_4 = 0;
	pMessage->field_8 = a4;
	pMessage->field_C = a2;
	pMessage->field_10 = a3;
	pMessage->field_14 = 200;

	gSimpleMessageRelated = a2;

	Mess_SetScale(200);

	gSimpleMessageTextWidth = Mess_TextWidth(a1);

	return pMessage;
}

// @Ok
// @Matching
INLINE i32 Mess_TextWidth(const char* pMessage)
{
	gMessFont.field_34 = 8 * gScale;
	return gMessFont.width(pMessage);
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
INLINE void Mess_SetTextJustify(unsigned char value)
{
	gTextJustify = value;
}

// @NotOk
// Global
INLINE void Mess_SetScale(int value)
{
	gScale = value;
}

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
INLINE void Mess_SetRGB(u8 r, u8 g, u8 b, i32)
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

	VALIDATE(SSimpleMessage, field_0, 0x0);
	VALIDATE(SSimpleMessage, field_4, 0x4);
	VALIDATE(SSimpleMessage, field_8, 0x8);
	VALIDATE(SSimpleMessage, field_C, 0xC);

	VALIDATE(SSimpleMessage, field_10, 0x10);
	VALIDATE(SSimpleMessage, field_14, 0x14);
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
