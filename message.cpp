#include "message.h"
#include "validate.h"



void validate_CMessage(void)
{
	VALIDATE_SIZE(CMessage, 0x44);

	VALIDATE(CMessage, mNext, 0x8);
	VALIDATE(CMessage, field_10, 0x10);
	VALIDATE(CMessage, field_14, 0x14);
	VALIDATE(CMessage, mHandle, 0x18);
}
