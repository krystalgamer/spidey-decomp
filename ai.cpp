#include "ai.h"
#include "validate.h"


// @NotOk
// validate
int __inline CAIProc::Wait(void)
{
	if (this->field_10 & 3)
		return 1;

	if (this->field_10 & 4)
	{
		this->field_10 |= 1;
		return 2;
	}

	int v3 = this->field_C;

	if (v3 <= 0)
		return 0;

	this->field_C--;
	return v3;
}

void validate_CAIProc(void)
{
	VALIDATE(CAIProc, field_C, 0xC);
	VALIDATE(CAIProc, field_10, 0x10);
}

void validate_CAIProc_LookAt(void)
{
	VALIDATE_SIZE(CAIProc_LookAt, 0x40);
}
