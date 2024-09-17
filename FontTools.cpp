#include "FontTools.h"
#include "validate.h"
#include "pal.h"
#include "mem.h"
#include "ps2pad.h"
#include "utils.h"
#include "PCTex.h"
#include "dcfileio.h"

#include <cstring>

// @Ok
// @Matching
Font::Font(void)
{
	this->Clut = 0xFFFFFFFF;
}

// @Ok
Font::Font(
		u8* a2,
		const char* a3)
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
	this->NumChars = *reinterpret_cast<i32*>(a2);

	this->SetCharMap(0);

	this->pCharTab = static_cast<FontCharacter*>(
			DCMem_New(sizeof(FontCharacter) * (this->NumChars + 1), 0, 1, 0, 1));

	i32 v26 = gClutRelatedOne;
	i32 v6 = gClutRelatedTwo + GetFree16Slot();
	u16* Clut = PCTex_CreateClut(16);

	for (i32 i = 0; i < 16; i++)
	{
		u16* pColor = reinterpret_cast<u16*>(a2);
		u16 color = pColor[8 * this->NumChars + 2 + i];
		Clut[i] = color;
		gSlicedImageRelated[i] = color;
	}

	_LoadImage();

	this->Clut = GetClut(v26, v6);

	SDataGlyph* pGlyph = reinterpret_cast<SDataGlyph*>(&a2[4]);
	void* pData = &a2[16 * this->NumChars + 36];

	for (i32 j = 0; j < this->NumChars; j++)
	{
		this->pCharTab[j].W = pGlyph[j].mWidth;
		this->pCharTab[j].H = pGlyph[j].mHeight;
		this->pCharTab[j].Baseline = pGlyph[j].mBaseline;

		i32 charSliceWidth = pGlyph[j].mSliceWidth;

		this->pCharTab[j].pImage = new SlicedImage2(
				pData,
				4 * charSliceWidth,
				this->pCharTab[j].H,
				0,
				0,
				4,
				this->Clut,
				1);

		this->pCharTab[j].pImage->pack();
		this->pCharTab[j].pImage->removeFromMemory();

		this->pCharTab[j].pImage->field_A = 0;
		this->pCharTab[j].pImage->field_B = 0;
		this->pCharTab[j].pImage->Shaded = 1;

		i32 v17 = 0;
		i32 size = charSliceWidth * this->pCharTab[j].H;
		if (size & 1)
			v17 = 2;

		pData = reinterpret_cast<void*>(static_cast<u8*>(pData) + size * 2 + v17);
	}

	this->pCharTab[this->NumChars].W = pGlyph[0].mWidth;
	this->pCharTab[this->NumChars].H = pGlyph[0].mHeight;
	this->pCharTab[this->NumChars].Baseline = pGlyph[0].mBaseline;

	i32 sliceWidth = pGlyph[0].mSliceWidth;
	i32 v20 = 2 * sliceWidth * this->pCharTab[this->NumChars].H;
	void* v21 = DCMem_New(v20, 0, 1, 0, 1);
	if ( v20 > 0 )
		memset(v21, 0x12u, v20);


	this->pCharTab[this->NumChars].pImage = new SlicedImage2(
			v21,
			4 * sliceWidth,
			this->pCharTab[this->NumChars].H,
			0,
			0,
			4,
			this->Clut,
			1);
	Mem_Delete(v21);


	this->pCharTab[this->NumChars].pImage->pack();
	this->pCharTab[this->NumChars].pImage->removeFromMemory();

	this->pCharTab[this->NumChars].pImage->field_A = 0;
	this->pCharTab[this->NumChars].pImage->field_B = 0;
	this->pCharTab[this->NumChars].pImage->Shaded = 1;
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

		if (a2 == CHAR(0x3F) && this->NumChars > 0x25)
			return CHAR(0x25);

		if (a2 == CHAR(0x21) && this->NumChars > 0x26)
			return CHAR(0x26);

		if (a2 == CHAR(0x3A))
			return CHAR(0x27);

		if (a2 == CHAR(0x2E) && this->NumChars > 0x28)
			return CHAR(0x28);

		if (a2 == CHAR(0x2D) && this->NumChars > 0x29)
			return CHAR(0x29);

		if (a2 == CHAR(0x2B) && this->NumChars > 0x2B)
			return CHAR(0x2B);

		if (a2 == CHAR(0x27) && this->NumChars > 0x2A)
			return CHAR(0x2A);

		if (a2 == CHAR(0x5F) && this->NumChars > 0x24)
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

	return this->NumChars;
}

EXPORT Font* FontList[6];

// @NotOk
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

// @Ok
// @Matching
void FontManager::UnloadAllFonts(void)
{
	for (i32 i = 0; i < 6; i++)
	{
		if (FontList[i])
		{
			FontList[i]->unload();
			delete FontList[i];
			FontList[i] = 0;
		}
	}
}

// @Ok
// @Matching
INLINE u8 FontManager::IsFontLoaded(const char* pName)
{
	for (i32 i = 0; i < 6; i++)
	{
		if (FontList[i] && !strcmp(FontList[i]->field_38, pName))
		{
			return 1;
		}
	}

	return 0;
}

// @Ok
// @Matching
INLINE Font* FontManager::GetFont(const char* pName)
{
	i32 i;
	for (i = 0; i < 6; i++)
	{
		if (FontList[i] && !strcmp(FontList[i]->field_38, pName))
		{
			break;
		}
	}

	print_if_false(i < 6, "Font %s is not loaded", pName);
	return FontList[i];
}

// @Ok
// @Matching
Font* FontManager::LoadFont(u8* pBuf, const char* pName)
{
	i32 i;
	for (i = 0; i < 6; i++)
	{
		if (FontList[i] == 0)
		{
			print_if_false(i < 6, "out of font slots");
			FontList[i] = new Font(pBuf, pName);
			break;
		}

		if (!strcmp(FontList[i]->field_38, pName))
			break;
	}

	return FontList[i];
}

// @Ok
// @Matching
Font* FontManager::LoadFont(const char* pName)
{
	if (FontManager::IsFontLoaded(pName))
		return FontManager::GetFont(pName);

	i32 v2 = FileIO_Open(pName);
	print_if_false(v2 > 40, "unlikely font file size");
	print_if_false(v2 != 0, "File not found");

	u8* v3 = static_cast<u8*>(DCMem_New(v2, 0, 1, 0, 1));
	print_if_false(v3 != 0, "Out of memory");
	FileIO_Load(v3);
	FileIO_Sync();

	Font* pFont = FontManager::LoadFont(v3, pName);
	pFont->field_160 = v3;
	return pFont;
}

// @Ok
// @Note: see comment for heightAboveBaseline
INLINE i32 Font::heightBelowBaseline(char* pStr)
{
	i32 max_h = 0;
	i32 i = 0;
	
	while(pStr[i])
	{
		i32 c = pStr[i];
		if (c != 0x000000FF)
		{
			u32 tmp = this->field_5F[c];

			if ((i32)tmp != 0x000000FF)
			{
				i32 val = this->pCharTab[tmp].H - this->pCharTab[tmp].Baseline;
				if (val > max_h)
					max_h = val;
			}
		}

		i++;
	}

	return (max_h * this->field_34) >> 12;
}

// @Ok
// @Note: fuck this function, can't  get it to match now matter how much i try
// the first if inside the while oculd be removed because it performs sign extension,
// not sure what's up with that to be honest. i think it's a bug somewhere because on the PPC version, it does the same checks but with i8 not i32
INLINE i32 Font::heightAboveBaseline(char* pStr)
{
	i32 max_h = 0;
	i32 i = 0;
	
	while(pStr[i])
	{
		i32 c = pStr[i];
		if (c != 0x000000FF)
		{
			u32 tmp = this->field_5F[c];

			if ((i32)tmp != 0x000000FF)
			{
				i32 val = this->pCharTab[tmp].Baseline;
				if (val > max_h)
					max_h = val;
			}
		}

		i++;
	}

	return (max_h * this->field_34) >> 12;
}

// @Ok
int Font::height(char* txt)
{
	return this->heightAboveBaseline(txt) + this->heightBelowBaseline(txt);
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
	if (this->Clut != -1)
		Free16Slot(this->Clut);

	for (i32 i = 0; i < this->NumChars + 1; i++)
	{
		delete this->pCharTab[i].pImage;
	}

	Mem_Delete(reinterpret_cast<void*>(this->pCharTab));

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

	VALIDATE(Font, pCharTab, 0x48);
	VALIDATE(Font, NumChars, 0x4C);
	VALIDATE(Font, Clut, 0x50);

	VALIDATE(Font, field_58, 0x58);
	VALIDATE(Font, field_5F, 0x5F);

	VALIDATE(Font, field_160, 0x160);
}

void validate_SFontEntry(void)
{
	VALIDATE_SIZE(FontCharacter, 0x8);

	VALIDATE(FontCharacter, pImage, 0x0);
	VALIDATE(FontCharacter, W, 0x4);
	VALIDATE(FontCharacter, H, 0x5);
	VALIDATE(FontCharacter, Baseline, 0x6);
	VALIDATE(FontCharacter, field_7, 0x7);
}

void validate_SDataGlyph(void)
{
	VALIDATE_SIZE(SDataGlyph, 0x10);

	VALIDATE(SDataGlyph, mSliceWidth, 0x0);
	VALIDATE(SDataGlyph, mHeight, 0x4);
	VALIDATE(SDataGlyph, mBaseline, 0x8);
	VALIDATE(SDataGlyph, mWidth, 0xC);
}
