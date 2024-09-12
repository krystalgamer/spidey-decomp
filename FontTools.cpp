#include "FontTools.h"
#include "validate.h"
#include "pal.h"
#include "mem.h"
#include "ps2pad.h"
#include "utils.h"
#include "PCTex.h"

#include <cstring>

// @Ok
// @Matching
Font::Font(void)
{
	this->field_50 = 0xFFFFFFFF;
}

// @SMALLTODO
Font::Font(
		u8* a2,
		char* a3)
{
	strcpy(this->field_38, a3);
	this->field_8 = 3;
	this->field_10 = 3;
	this->field_4 = 0;
	this->mRed = 128;
	this->mGreen = 128;
	this->mBlue = 128;
	this->field_C = 2;
	this->field_20 = 0;
	this->field_21 = 1;
	this->field_24 = 1;
	this->field_28 = 1;
	this->field_2C = 255;
	this->field_30 = 0;
	this->field_34 = 3800;
	this->field_54 = 0;
	this->field_4C = *reinterpret_cast<i32*>(a2);

	this->SetCharMap(0);

	this->field_48 = static_cast<SFontEntry*>(
			DCMem_New(sizeof(SFontEntry) * (this->field_4C + 1), 0, 1, 0, 1));

	i32 v26 = gClutRelatedOne;
	i32 v6 = gClutRelatedTwo + GetFree16Slot();
	u16* Clut = PCTex_CreateClut(16);

	for (i32 i = 0; i < 16; i++)
	{
		u16* pColor = reinterpret_cast<u16*>(a2);
		u16 color = pColor[8 * this->field_4C + 2 + i];
		Clut[i] = color;
		gSlicedImageRelated[i] = color;
	}

	_LoadImage();

	this->field_50 = GetClut(v26, v6);
	
}

// @Ok
Font::~Font(void)
{
}

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
INLINE void Font::SetCharMap(int a2)
{
	this->field_58 = a2;
	for (int i = 0; i < 256; i++)
	{
		this->field_5F[i] = this->getCharIndex(i);
	}
}

#define CHAR(x) ((char)(x))
// @Ok
// @Test
char Font::getCharIndex(char a2)
{
	i32 v3 = this->field_58;

	if (v3 == 2)
	{
		if ( a2 >= 'a' && a2 <= 'z' )
			return a2 - 48;

		if (a2 == CHAR(0xC0) || a2 == CHAR(0xC1))
			return 75;

		if (a2  == CHAR(0xC7))
			return 76;

		if (a2 == CHAR(0xC8) || a2 == CHAR(0xC9) || a2 == CHAR(0xCA))
			return 77;

		if (a2 == CHAR(0xD4))
			return CHAR(0x4E);

		if (a2 == CHAR(0xD9) || a2 == CHAR(0xDA))
			return CHAR(0x4F);

		if (a2 == CHAR(0x8C))
			return CHAR(0x50);

		if (a2 == CHAR(0xC4))
			return CHAR(0x51);

		if (a2 == CHAR(0xD6))
			return CHAR(0x52);

		if (a2 == CHAR(0xDC))
			return CHAR(0x53);

		if (a2 == CHAR(0xDF))
			return CHAR(0x54);

		if (a2 == CHAR(0xE0) || a2 == CHAR(0xE1))
			return CHAR(0x55);

		if (a2 == CHAR(0xE7))
			return CHAR(0x56);


		if (a2 == CHAR(0xE8) || a2 == CHAR(0xE9) || a2 == CHAR(0xEA))
			return CHAR(0x57);

		if (a2 == CHAR(0xF4))
			return CHAR(0x58);

		if (a2 == CHAR(0xF9) || a2 == CHAR(0xFA))
			return CHAR(0x59);

		if (a2 == CHAR(0x9C))
			return CHAR(0x5A);

		if (a2 == CHAR(0xE4))
			return CHAR(0x5B);

		if (a2 == CHAR(0xF6))
			return CHAR(0x5C);

		if (a2 == CHAR(0xFC))
			return CHAR(0x5D);

		v3 = 0;
	}

	if (!v3)
	{
		if (a2 >= 65 && a2 <= 90)
			return a2 - 65;

		if (a2 >= 97 && a2 <= 122)
			return a2 - 97;

		if (a2 >= 48 && a2 <= 57)
			return a2 - 22;

		if (a2 == CHAR(0x20))
			return CHAR(0xFF);

		if (a2 == CHAR(0x3F) && this->field_4C > 0x25)
			return CHAR(0x25);

		if (a2 == CHAR(0x21) && this->field_4C > 0x26)
			return CHAR(0x26);

		if (a2 == CHAR(0x3A))
			return CHAR(0x27);

		if (a2 == CHAR(0x2E) && this->field_4C > 0x28)
			return CHAR(0x28);

		if (a2 == CHAR(0x2D) && this->field_4C > 0x29)
			return CHAR(0x29);

		if (a2 == CHAR(0x2B) && this->field_4C > 0x2B)
			return CHAR(0x2B);

		if (a2 == CHAR(0x27) && this->field_4C > 0x2A)
			return CHAR(0x2A);

		if (a2 == CHAR(0x5F) && this->field_4C > 0x24)
			return CHAR(0x24);

		if (a2 == CHAR(0xC0) || a2 == CHAR(0xC1) ||
				a2 == CHAR(0xE0) || a2 == CHAR(0xE1))
			return CHAR(0x31);


		if (a2 == CHAR(0xC7) || a2 == CHAR(0xE7))
			return CHAR(0x32);

		if (a2 == CHAR(0xC8) || a2 == CHAR(0xC9) ||
				a2 == CHAR(0xE8) || a2 == CHAR(0xE9) ||
				a2 == CHAR(0xCA) || a2 == CHAR(0xEA))
			return CHAR(0x33);

		if (a2 == CHAR(0xD4) || a2 == CHAR(0xF4))
			return CHAR(0x34);

		if (a2 == CHAR(0xD9) || a2 == CHAR(0xDA) ||
				a2 == CHAR(0xF9) || a2 == CHAR(0xFA))
			return CHAR(0x35);

		if (a2 == CHAR(0x8C) || a2 == CHAR(0x9C))
			return CHAR(0x36);

		if (a2 == CHAR(0xC4) || a2 == CHAR(0xE4))
			return CHAR(0x37);

		if (a2 == CHAR(0xD6) || a2 == CHAR(0xF6))
			return CHAR(0x38);

		if (a2 == CHAR(0xDC) || a2 == CHAR(0xFC))
			return CHAR(0x39);

		if (a2 == CHAR(0xDF))
			return CHAR(0x3A);

		if (a2 == 165)
		{
			if (gSControl.field_14C <= 512)
			{
				if (gSControl.field_14C != 512)
				{
					switch (gSControl.field_14C)
					{
						case 2:
							return 1;
						case 4:
							return 0;
					}
				}
				else
				{
					return 24;
				}
			}
			else if (gSControl.field_14C == 1024)
			{
				return 23;
			}
		}

		if (a2 == 167)
		{
			if (gSControl.field_148 <= 512)
			{
				if (gSControl.field_148 != 512)
				{
					switch (gSControl.field_148)
					{
						case 2:
							return 1;
						case 4:
							return 0;
					}
				}
				else
				{
					return 24;
				}
			}
			else if (gSControl.field_148 == 1024)
			{
				return 23;
			}
		}

		if (a2 == 166)
		{
			if (gSControl.field_144 <= 512)
			{
				if (gSControl.field_144 != 512)
				{
					switch (gSControl.field_144)
					{
						case 2:
							return 1;
						case 4:
							return 0;
					}
				}
				else
				{
					return 24;
				}
			}
			else if (gSControl.field_144 == 1024)
			{
				return 23;
			}
		}

		if (a2 == 164)
		{
			if (!DifficultyLevel)
				return 0;

			if (gSControl.field_140 <= 512)
			{
				if (gSControl.field_140 != 512)
				{
					switch (gSControl.field_140)
					{
						case 2:
							return 1;
						case 4:
							return 0;
					}
				}
				else
				{
					return 24;
				}
			}
			else if (gSControl.field_140 == 1024)
			{
				return 23;
			}
		}
	}
	else if (v3 == 1)
	{
		if ( a2 >= 48 && a2 <= 57 )
			return a2 - 48;
		if ( a2 == 58 )
			return 10;
		if ( a2 == 32 )
			return -1;
	}
	else
	{
		print_if_false(0, "Unrecognized char mapping");
	}

	if (this->isEscapeChar(a2))
		return (char)0xFF;

	return this->field_4C;
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
		delete this->field_48[i].pImage;
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

void validate_SFontEntry(void)
{
	VALIDATE_SIZE(SFontEntry, 0x8);

	VALIDATE(SFontEntry, pImage, 0x0);
	VALIDATE(SFontEntry, field_4, 0x4);
	VALIDATE(SFontEntry, field_5, 0x5);
	VALIDATE(SFontEntry, field_6, 0x6);
	VALIDATE(SFontEntry, field_7, 0x7);
}
