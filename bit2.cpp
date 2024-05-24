#include "bit2.h"
#include "validate.h"


// @NotOk
// globals
CGLine::CGLine(void)
{
	this->field_44 = 0;
	this->field_48 = 0;
	this->field_4C = 0;
	this->field_50 = 0;
	this->field_54 = 0;
	this->field_58 = 0;

	this->field_3C = 0x50808080;
	this->field_40 = 0x55808080;
	this->AttachTo(reinterpret_cast<CBit**>(0x56E9CC));
}

// @Ok
void CGLine::SetRGB1(unsigned char a2, unsigned char a3, unsigned char a4)
{
	this->field_40 = a2 | (a4 << 16) | (a3 << 8);
}

void validate_CGPolyLine(void){
	VALIDATE_SIZE(CGPolyLine, 0x58);

	VALIDATE(CGPolyLine, field_40, 0x40);
	VALIDATE(CGPolyLine, field_44, 0x44);

	VALIDATE(CGPolyLine, field_50, 0x50);
	VALIDATE(CGPolyLine, field_51, 0x51);
	VALIDATE(CGPolyLine, field_52, 0x52);
	VALIDATE(CGPolyLine, field_53, 0x53);

	VALIDATE(CGPolyLine, field_57, 0x57);
}

void validate_CGLine(void)
{
	VALIDATE_SIZE(CGPolyLine, 0x58);

	VALIDATE(CGLine, field_3C, 0x3C);
	VALIDATE(CGLine, field_40, 0x40);
	VALIDATE(CGLine, field_44, 0x44);
	VALIDATE(CGLine, field_48, 0x48);
	VALIDATE(CGLine, field_4C, 0x4C);
	VALIDATE(CGLine, field_50, 0x50);
	VALIDATE(CGLine, field_54, 0x54);
	VALIDATE(CGLine, field_58, 0x58);
}
