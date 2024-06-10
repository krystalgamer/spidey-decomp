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
		unsigned char pad[0x4];

		CMessage* mNext;
		u8 padAfter8[0x10-0x8-4];

		i32 field_10;
		u8 padAfter10[0x18-0x10-4];


		SHandle mHandle;
		u8 padAfter18[0x44-0x18-8];


		EXPORT CMessage(CBaddy*, CBaddy*, int a4, SMessageData*)
		{
			*pad = a4;
		}


};

void validate_CMessage(void);

#endif
