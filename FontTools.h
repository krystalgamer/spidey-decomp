#pragma once

#ifndef FONTTOOLS_H
#define FONTTOOLS_H

#include "main.h"
#include "export.h"

class Font : public CClass
{
	public:
		EXPORT int GetCharMap(void);
		EXPORT void SetCharMap(int);
		EXPORT int isEscapeChar(char);
		EXPORT char getCharIndex(char);
		EXPORT int height(char*);
		EXPORT void unload(void);
		EXPORT i32 heightBelowBaseline(char*);
		EXPORT i32 heightAboveBaseline(char*);

		unsigned char pad[0x21-4];

		unsigned char field_21;
		unsigned char padAfter21[0x38-0x21-1];

		char field_38[1]; //name don't know how big
		unsigned char padAfter38[0x48-0x38-1];

		i32** field_48;
		i32 field_4C;
		i32 field_50;
		u8 padAfter50[0x4];

		int field_58;
		unsigned char padAfter58[0x5F-0x58-4];

		unsigned char field_5F[256];

		i32 field_160;
};

class FontManager
{
	public:
		EXPORT static void ResetCharMaps(void);
		EXPORT static char* GetFontName(Font*);
		EXPORT static void AllShadowOff(void);
		EXPORT static void AllShadowOn(void);
		EXPORT static void UnloadFont(Font*);
		EXPORT static void UnloadAllFonts(void);
};



void validate_Font(void);
#endif
