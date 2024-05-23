#pragma once

#ifndef FONTTOOLS_H
#define FONTTOOLS_H

#include "export.h"

class Font
{
	public:
		EXPORT int GetCharMap(void);
		EXPORT void SetCharMap(int);
		EXPORT int isEscapeChar(char);
		EXPORT char getCharIndex(char);

		unsigned char pad[0x38];
		char field_38[1];
		unsigned char padAfter38[0x58-0x38-1];

		int field_58;
		unsigned char padAfter58[0x5F-0x58-4];

		unsigned char field_5F[256];
};

class FontManager
{
	public:
		EXPORT static void ResetCharMaps(void);
		EXPORT static char* GetFontName(Font*);
};

void validate_Font(void);
#endif
