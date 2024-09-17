#pragma once

#ifndef FONTTOOLS_H
#define FONTTOOLS_H

#include "main.h"
#include "export.h"
#include "Image.h"

struct SDataGlyph
{
	i32 mSliceWidth;
	i32 mHeight;
	i32 mBaseline;
	i32 mWidth;
};

struct FontCharacter
{
	SlicedImage2* pImage;
	u8 W;
	u8 H;
	u8 Baseline;
	u8 field_7;
};

class Font : public CClass
{
	public:
		EXPORT Font(void);
		EXPORT Font(u8*, const char*);

		EXPORT ~Font(void);

		EXPORT int GetCharMap(void);
		EXPORT void SetCharMap(int);
		EXPORT int isEscapeChar(char);
		EXPORT char getCharIndex(char);
		EXPORT int height(char*);
		EXPORT i32 width(const char*);
		EXPORT void unload(void);
		EXPORT i32 heightBelowBaseline(char*);
		EXPORT i32 heightAboveBaseline(char*);
		EXPORT void draw(i32, i32, const char*, i32, float);

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

		FontCharacter* pCharTab;

		i32 NumChars;
		i32 Clut;

		i32 field_54;
		i32 field_58;
		u8 field_5C;
		u8 field_5D;
		u8 field_5E;
		u8 field_5F[256];

		u8* field_160;
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
		EXPORT static u8 IsFontLoaded(const char*);

		EXPORT static Font* LoadFont(const char*);
		EXPORT static Font* LoadFont(u8*, const char*);
};



void validate_Font(void);
void validate_SFontEntry(void);
void validate_SDataGlyph(void);

#endif
