#include "message.h"
#include "validate.h"

// @MEDIUMTODO
CMessage::CMessage(CBaddy*, CBaddy*, int a4, SMessageData*)
{
	printf("CMessage::CMessage(CBaddy*, CBaddy*, int a4, SMessageData*)");
}


void validate_CMessage(void)
{
	VALIDATE_SIZE(CMessage, 0x44);

	VALIDATE(CMessage, mNext, 0x8);
	VALIDATE(CMessage, field_10, 0x10);
	VALIDATE(CMessage, field_14, 0x14);
	VALIDATE(CMessage, mHandle, 0x18);
}
