#include "front.h"
#include "validate.h"



CMenu::CMenu(int x,int y,unsigned char Justification,int HiScale,int LowScale, int LineSep)
{

}

CMenu::~CMenu()
{
}

void validate_CMenu(void)
{
	VALIDATE_SIZE(CMenu, 0x53C);

	VALIDATE(CMenu, ptr_to, 0x4);
	VALIDATE(CMenu, menu_width, 0x8);
	VALIDATE(CMenu, text_val_b, 0xA);
	VALIDATE(CMenu, text_val_a, 0xC);
	VALIDATE(CMenu, unk_a, 0xE);
	VALIDATE(CMenu, unk_b, 0xF);

	VALIDATE(CMenu, scrollbar_one, 0x10);
	VALIDATE(CMenu, scrollbar_zero, 0x11);
	VALIDATE(CMenu, mJustification, 0x12);
	VALIDATE(CMenu, selected_index, 0x14);

	VALIDATE(CMenu, mCursorLine, 0x15);
	VALIDATE(CMenu, mNumLines,  0x1A);
	VALIDATE(CMenu, field_1E, 0x1E);
	VALIDATE(CMenu, mX, 0x24);
	VALIDATE(CMenu, mY, 0x28);
	VALIDATE(CMenu, mLineSep, 0x2C);
	VALIDATE(CMenu, mEntry, 0x3C);


}

void validate_SEntry(void)
{
	VALIDATE_SIZE(SEntry, 0x20);
}
