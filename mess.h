#pragma once

#ifndef MESS_H
#define MESS_H

#include "export.h"

struct SimpleMessage
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

void validate_SimpleMessage(void);

#endif

