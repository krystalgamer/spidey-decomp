#pragma once


#ifndef SPIDEY_H
#define SPIDEY_H

#include "export.h"
#include "ob.h"

class CPlayer : public CSuper 
{
	public:

		unsigned char padTopPlayer[0x8EC-0x194];

		unsigned char gCamAngleLock;

		unsigned char padBottomPlayer[0xEFC-0x8EC-1];


		EXPORT void SetCamAngleLock(unsigned __int16);
};

void validate_CPlayer(void);

#endif
