#include "FontTools.h"
#include "validate.h"
#include "pal.h"
#include "mem.h"
#include <cstring>

// @MEDIUMTODO
void Font::draw(i32, i32, const char*, i32, float)
{
	printf("void Font::draw(i32, i32, const char*, i32, float)");
}

// @Ok
int Font::isEscapeChar(char a1)
{
	if (a1 == ']')
		return 254;
	else if (a1 == '[')
		return 253;
	else if (a1 == '}')
		return 254;
	else if (a1 == '{')
		return 252;
	else if (a1 == '>')
		return 254;
	else if (a1 == '<')
		return 251;
	else if (a1 == '|')
		return 249;
	else if (a1 == '~')
		return 248;

	return ((a1 != 0x5E) - 1) & 0x000000FA;
}

// @Ok
int __inline Font::GetCharMap(void)
{
	return this->field_58;
}


// @Ok
void __inline Font::SetCharMap(int a2)
{
	this->field_58 = a2;
	for (int i = 0; i < 256; i++)
	{
		this->field_5F[i] = this->getCharIndex(i);
	}
}

// @BIGTODO
char Font::getCharIndex(char)
{
	return (char)0xFF;
}

static Font* FontList[6];

// NotOk
// globals
// managed to make it match with the this->field_58 = this->field_58, by deref through array
void FontManager::ResetCharMaps(void)
{
	for (int i = 0; i<6; i++)
	{
		if (FontList[i])
		{
			FontList[i]->SetCharMap(FontList[i]->GetCharMap());
		}
	}
}

// @Ok
char* FontManager::GetFontName(Font* pFont)
{
	return pFont->field_38;
}

// @NotOk
// globals
void FontManager::AllShadowOff(void)
{
	for (int i = 0; i<6; i++)
	{
		if (FontList[i])
		{
			FontList[i]->field_21 = 0;
		}
	}
}

// @NotOk
// globals
void FontManager::AllShadowOn(void)
{
	for (int i = 0; i<6; i++)
	{
		if (FontList[i])
		{
			FontList[i]->field_21 = 1;
		}
	}
}


// @Ok
void FontManager::UnloadFont(Font* pFont)
{
	i32 count = 0;
	for (; count < 6; count++)
	{
		if (FontList[count] && !strcmp(FontList[count]->field_38, pFont->field_38))
			break;
	}

	print_if_false(count < 6, "Font %s is not in table", &pFont->field_38);


	FontList[count]->unload();

	if (FontList[count])
		delete FontList[count];

	FontList[count] = 0;
}

// @SMALLTODO
void FontManager::UnloadAllFonts(void)
{
	printf("void FontManager::UnloadAllFonts(void)");
}

// @SMALLTODO
Font* FontManager::GetFont(const char*)
{
	printf("Font* FontManager::GetFont(const char*)");
	return reinterpret_cast<Font*>(0x30082024);
}

// @SMALLTODO
Font* FontManager::LoadFont(const char*)
{
	printf("Font* FontManager::LoadFont(const char*)");
	return reinterpret_cast<Font*>(0x30082024);
}

// @SMALLTODO
i32 Font::heightBelowBaseline(char*)
{
	return 0x14072024;
}

// @SMALLTODO
i32 Font::heightAboveBaseline(char*)
{
	return 0x14072024;
}

// @Ok
int Font::height(char* txt)
{
	return this->heightBelowBaseline(txt) + this->heightAboveBaseline(txt);
}

// @SMALLTODO
i32 Font::width(const char*)
{
	printf("i32 Font::width(const char*)");
	return 0x30082024;
}

// @Ok
INLINE void Font::unload(void)
{
	if (this->field_50 != -1)
		Free16Slot(this->field_50);

	for (i32 i = 0; i < this->field_4C + 1; i++)
	{
		Font *ouch = reinterpret_cast<Font*>(this->field_48[2*i]);
		// @FIXME this should be fixed to the correct type, it just works
		// because it's invoking a virtual destructor
		if (ouch)
			delete ouch;
	}

	Mem_Delete(reinterpret_cast<void*>(this->field_48));

	if (this->field_160)
	{
		Mem_Delete(reinterpret_cast<void*>(this->field_160));
		this->field_160 = 0;
	}
}

void validate_Font(void)
{
	VALIDATE_SIZE(Font, 0x164);

	VALIDATE(Font, field_4, 0x4);
	VALIDATE(Font, field_8, 0x8);
	VALIDATE(Font, field_C, 0xC);
	VALIDATE(Font, field_10, 0x10);

	VALIDATE(Font, mRed, 0x14);
	VALIDATE(Font, mGreen, 0x18);
	VALIDATE(Font, mBlue, 0x1C);

	VALIDATE(Font, field_21, 0x21);

	VALIDATE(Font, field_24, 0x24);
	VALIDATE(Font, field_28, 0x28);
	VALIDATE(Font, field_2C, 0x2C);
	VALIDATE(Font, field_30, 0x30);
	VALIDATE(Font, field_34, 0x34);

	VALIDATE(Font, field_38, 0x38);

	VALIDATE(Font, field_48, 0x48);
	VALIDATE(Font, field_4C, 0x4C);
	VALIDATE(Font, field_50, 0x50);

	VALIDATE(Font, field_58, 0x58);
	VALIDATE(Font, field_5F, 0x5F);

	VALIDATE(Font, field_160, 0x160);
}
