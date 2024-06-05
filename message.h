#pragma once


#ifndef MESSAGE_H
#define MESSAGE_H

#include "baddy.h"
#include "main.h"

struct SMessageData
{};

class CMessage : public CClass
{
	public:
		unsigned char pad[0x40];

		EXPORT CMessage(CBaddy*, CBaddy*, int a4, SMessageData*)
		{
			*pad = a4;
		}
};

void validate_CMessage(void);

#endif
