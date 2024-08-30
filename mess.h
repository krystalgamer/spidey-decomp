#pragma once

#ifndef MESS_H
#define MESS_H

#include "export.h"

struct SSimpleMessage
{
	const char* field_0;

	u32 field_4;
	u32 field_8;
	u32 field_C;
	u32 field_10;
	u32 field_14;

	u32 field_18;
	SSimpleMessage* pNext;
	SSimpleMessage* pPrevious;
};

struct SMessageProg
{
};

struct SMessage
{
	const char* pText;
	u16 T;
	u16 T_total;
	u8 padAfter6[0x10-0x6-2];

	SMessageProg* pProg;
	SMessage* pNext;
	SMessage* pPrevious;
};

EXPORT void Mess_SetTextJustify(unsigned char);
EXPORT void Mess_SetScale(int);
EXPORT void Mess_SetRGB(u8, u8, u8, i32);
EXPORT void Mess_SetRGBBottom(unsigned char, unsigned char, unsigned char);
EXPORT char* Mess_GetCurrentFont(void);
EXPORT void Mess_UnloadFont(void);
EXPORT int Mess_TextHeight(char *);
EXPORT void Mess_SetCurrentFont(char *);

EXPORT void Mess_ClearSimpleMessages(void);
EXPORT void DeleteSimpleMessage(SSimpleMessage*);

EXPORT SMessage* CreateMessage(void);
EXPORT SSimpleMessage* CreateSimpleMessage(void);
EXPORT void Mess_ClearSimpleMessages(void);
EXPORT void Mess_DeleteAll(void);
EXPORT void Mess_Display(void);
EXPORT i32 Mess_DrawText(i32,i32,const char *,i32,u32);
EXPORT i32 Mess_GetScale(void);
EXPORT i32 Mess_GetSort(void);
EXPORT i32 Mess_LoadFont(const char *,i32,i32,i32);
EXPORT SMessage* Mess_Message(const char *,SMessageProg *);
EXPORT void Mess_SetShadowRGB(u8);
EXPORT void Mess_SetSort(i32);
EXPORT void Mess_ShadowsOff(void);
EXPORT void Mess_ShadowsOn(void);
EXPORT SSimpleMessage* Mess_SimpleMessage(const char *,u32,u32,u32);
EXPORT i32 Mess_TextWidth(const char *);
EXPORT void Mess_UnloadAllFonts(void);
EXPORT void Mess_Update(void);

void validate_SimpleMessage(void);
void validate_SMessageProg(void);
void validate_SMessage(void);

#endif

