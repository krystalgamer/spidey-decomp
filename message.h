#pragma once


#ifndef MESSAGE_H
#define MESSAGE_H

#include "main.h"
#include "mem.h"

class CBaddy;
struct SMessageData
{
	i32 field_0;

	i32 mNumParams;
	i32 mNumVects;

	i32 mParams[2];
	i32 *pVects[2];
};

class CMessage : public CClass
{
	public:

		CMessage* pPrev;
		CMessage* mNext;
		
		CBaddy* pBaddy;

		i32 field_10;
		i32 field_14;

		SHandle mHandle;
		i32 mParams[2];
		i32 mVects[2][3];

		u8 padBottom[4];


		EXPORT CMessage(CBaddy*, CBaddy*, int a4, SMessageData*);
		EXPORT ~CMessage(void) OVERRIDE;
};

void validate_CMessage(void);
void validate_SMessageData(void);

#endif
