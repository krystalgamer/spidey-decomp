#include "message.h"
#include "baddy.h"

#include "validate.h"

// @MEDIUMTODO
CMessage::CMessage(CBaddy*, CBaddy*, int a4, SMessageData*)
{
	printf("CMessage::CMessage(CBaddy*, CBaddy*, int a4, SMessageData*)");
}

// @Ok
// @Matching
CMessage::~CMessage(void)
{
	if (this->pPrev)
	{
		this->pPrev->mNext = this->mNext;
	}
	else
	{
		this->pBaddy->pMessage = this->mNext;
	}

	if (this->mNext)
	{
		this->mNext->pPrev = this->pPrev;
	}
}


void validate_CMessage(void)
{
	VALIDATE_SIZE(CMessage, 0x44);

	VALIDATE(CMessage, pPrev, 0x4);
	VALIDATE(CMessage, mNext, 0x8);
	VALIDATE(CMessage, pBaddy, 0xC);

	VALIDATE(CMessage, field_10, 0x10);
	VALIDATE(CMessage, field_14, 0x14);
	VALIDATE(CMessage, mHandle, 0x18);
}
