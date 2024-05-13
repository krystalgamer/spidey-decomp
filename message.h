#pragma once


#ifndef MESSAGE_H
#define MESSAGE_H

#include "baddy.h"

struct SMessageData
{};

class CMessage
{
	public:
		unsigned char pad[0x44];

		EXPORT CMessage(CBaddy*, CBaddy*, int a4, SMessageData*)
		{
			*pad = a4;
		}
};

void validate_CMessage(void);

#endif
