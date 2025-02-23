#include "message.h"
#include "baddy.h"

#include "validate.h"

// @Ok
CMessage::CMessage(
		CBaddy* a2,
		CBaddy* pOwner,
		i32 a4,
		SMessageData* pData)
{
	for (i32 i = 0; i < 2; i++)
	{
		this->mVects[i][0] = 0;
		this->mVects[i][1] = 0;
		this->mVects[i][2] = 0;
	}

	print_if_false(pOwner != 0, "What? No pointer to owner?");
	print_if_false(!pData || pData->mNumParams <= 2, "Too many params passed.");
	print_if_false(!pData || pData->mNumVects <= 2, "Too many vects passed.");

	CMessage *pOwnerMessage = pOwner->pMessage;
	this->mNext = pOwnerMessage;

	if (pOwnerMessage)
		pOwnerMessage->pPrev = this;

	pOwner->pMessage = this;

	this->pBaddy = pOwner;
	this->mHandle = Mem_MakeHandle(a2);

	this->field_14 = a4;


	if (pData)
	{
		for (i32 j = 0; j < pData->mNumParams; j++)
		{
			this->mParams[j] = pData->mParams[j];
		}

		for (i32 k = 0; k < pData->mNumVects; k++)
		{
			i32* pVec = pData->pVects[k];
			this->mVects[k][0] = pVec[0];
			this->mVects[k][1] = pVec[1];
			this->mVects[k][2] = pVec[2];
		}
	}
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

	VALIDATE(CMessage, mParams, 0x20);
	VALIDATE(CMessage, mVects, 0x28);
}

void validate_SMessageData(void)
{
	VALIDATE_SIZE(SMessageData, 0x1C);

	VALIDATE(SMessageData, mNumParams, 0x4);
	VALIDATE(SMessageData, mNumVects, 0x8);

	VALIDATE(SMessageData, mParams, 0xC);
	VALIDATE(SMessageData, pVects, 0x14);
}
