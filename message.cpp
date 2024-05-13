#include "message.h"
#include "validate.h"



void validate_CMessage(void)
{
	VALIDATE_SIZE(CMessage, 0x44);
}
