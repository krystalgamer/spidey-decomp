#include "FontTools.h"
#include "validate.h"

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

// @TODO
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

// @TODO
void FontManager::UnloadFont(Font*)
{}

void validate_Font(void)
{
	VALIDATE_SIZE(Font, 0x160);

	VALIDATE(Font, field_21, 0x21);
	VALIDATE(Font, field_38, 0x38);
	VALIDATE(Font, field_58, 0x58);
	VALIDATE(Font, field_5F, 0x5F);
}
