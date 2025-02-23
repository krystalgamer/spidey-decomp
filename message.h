#pragma once


#ifndef MESSAGE_H
#define MESSAGE_H

#include "main.h"
#include "mem.h"

class CBaddy;
struct SMessageData
{};

class CMessage : public CClass
{
	public:

		CMessage* pPrev;
		CMessage* mNext;
		
		CBaddy* pBaddy;

		i32 field_10;
		i32 field_14;

		SHandle mHandle;
		u8 padAfter18[0x44-0x18-8];


		EXPORT CMessage(CBaddy*, CBaddy*, int a4, SMessageData*);
		EXPORT ~CMessage(void) OVERRIDE;
};

void validate_CMessage(void);

#endif
