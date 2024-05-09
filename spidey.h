#pragma once


#ifndef SPIDEY_H
#define SPIDEY_H

#include "export.h"
#include "ob.h"

class CPlayer : public CSuper 
{
	public:

		unsigned char padTopPlayer[0x8EA-0x194];

		unsigned char field_8EA;
		unsigned char padAFter8Ea;

		unsigned char gCamAngleLock; //8EC
		unsigned char padAfterLock[0xE12-0x8EC-1];


		__int16 field_E12;
		unsigned char padAfterE12[4];

		int field_E18;

		unsigned char padBottomPlayer[0xEFC-0xE18-4];


		EXPORT void SetCamAngleLock(unsigned __int16);
		EXPORT void ExitLookaroundMode(void);
		EXPORT void SetIgnoreInputTimer(int);
};

void validate_CPlayer(void);

#endif
