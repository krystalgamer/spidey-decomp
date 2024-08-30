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
		EXPORT i32 width(const char*);
		EXPORT void unload(void);
		EXPORT i32 heightBelowBaseline(char*);
		EXPORT i32 heightAboveBaseline(char*);

		i32 field_4;
		i32 field_8;
		i32 field_C;
		i32 field_10;

		u32 mRed;
		u32 mGreen;
		u32 mBlue;

		u8 field_20;
		u8 field_21;

		i32 field_24;
		i32 field_28;
		i32 field_2C;
		i32 field_30;
		i32 field_34;

		char field_38[16];

		i32** field_48;
		i32 field_4C;
		i32 field_50;
		i32 field_54;
		i32 field_58;
		u8 field_5C;
		u8 field_5D;
		u8 field_5E;
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
		EXPORT static Font* GetFont(const char*);

		EXPORT static Font* LoadFont(const char*);
};



void validate_Font(void);
#endif
