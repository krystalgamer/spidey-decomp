#pragma once

#ifndef MESS_H
#define MESS_H

#include "export.h"

EXPORT void Mess_SetTextJustify(unsigned char);
EXPORT void Mess_SetScale(int);
EXPORT void Mess_SetRGBBottom(unsigned char, unsigned char, unsigned char);
EXPORT char* Mess_GetCurrentFont(void);
EXPORT void Mess_UnloadFont(void);

#endif

