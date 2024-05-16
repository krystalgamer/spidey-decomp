#include "jonah.h"
#include "validate.h"

int JoelJewtCheatCode = 0;

// @NotOk
// globals
CJonah::CJonah(void)
{
	this->field_34C = 0;
	this->field_350 = 0;
	this->field_354 = 0;

	if (JoelJewtCheatCode)
	{
		this->InitItem("jjjj");
	}
	else
	{
		this->InitItem("jameson");
	}

	this->mFlags |= 0x480;
	this->field_3C = 0x552010;
	this->field_38 = 316;

}

void validate_CJonah(void){
	VALIDATE_SIZE(CJonah, 0x380);

	VALIDATE(CJonah, field_34C, 0x34C);
	VALIDATE(CJonah, field_350, 0x350);
	VALIDATE(CJonah, field_354, 0x354);
}
