#pragma once

#ifndef MESS_H
#define MESS_H

#include "export.h"

struct SimpleMessage
{
};

struct SMessageProg
{
};

EXPORT void Mess_SetTextJustify(unsigned char);
EXPORT void Mess_SetScale(int);
EXPORT void Mess_SetRGB(unsigned char, unsigned char, unsigned char, int);
EXPORT void Mess_SetRGBBottom(unsigned char, unsigned char, unsigned char);
EXPORT char* Mess_GetCurrentFont(void);
EXPORT void Mess_UnloadFont(void);
EXPORT int Mess_TextHeight(char *);
EXPORT void Mess_SetCurrentFont(char *);

EXPORT void Mess_ClearSimpleMessageList(void);
EXPORT void DeleteSimpleMessage(SimpleMessage*);

EXPORT void CreateMessage(void);
EXPORT void CreateSimpleMessage(void);
EXPORT void Mess_ClearSimpleMessages(void);
EXPORT void Mess_DeleteAll(void);
EXPORT void Mess_Display(void);
EXPORT void Mess_DrawText(i32,i32,char const *,i32,u32);
EXPORT void Mess_GetScale(void);
EXPORT void Mess_GetSort(void);
EXPORT void Mess_LoadFont(char *,i32,i32,i32);
EXPORT void Mess_Message(char const *,SMessageProg *);
EXPORT void Mess_SetShadowRGB(u8);
EXPORT void Mess_SetSort(i32);
EXPORT void Mess_ShadowsOff(void);
EXPORT void Mess_ShadowsOn(void);
EXPORT void Mess_SimpleMessage(char const *,u32,u32,u32);
EXPORT i32 Mess_TextWidth(const char *);
EXPORT void Mess_UnloadAllFonts(void);
EXPORT void Mess_Update(void);

void validate_SimpleMessage(void);
void validate_SMessageProg(void);

#endif

