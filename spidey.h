#pragma once


#ifndef SPIDEY_H
#define SPIDEY_H

#include "export.h"
#include "ob.h"

class CPlayer : public CSuper 
{
	public:

		unsigned char padTopPlayer[0x56C-0x194];

		int field_56C;
		unsigned char padAfter56C[0x8EA-0x56C-4];


		unsigned char field_8EA;
		unsigned char padAFter8Ea;

		unsigned char gCamAngleLock; //8EC
		unsigned char padAfterLock[0xC90-0x8EC-1];

		int field_C90;
		unsigned char padAfterC90[0xCB4-0xC90-4];

		int field_CB4;
		unsigned char padAfterCB4[0xCE4-0xCB4-4];

		int field_CE4;
		unsigned char padAfterCE4[0xDE4-0xCE4-4];

		char field_DE4;
		unsigned char padAfterDE4[0xE12-0xDE4-1];

		__int16 field_E12;
		unsigned char padAfterE12[4];

		int field_E18;

		unsigned char padBottomPlayer[0xEFC-0xE18-4];


		EXPORT void SetCamAngleLock(unsigned __int16);
		EXPORT void ExitLookaroundMode(void);
		EXPORT void SetIgnoreInputTimer(int);
		EXPORT void PutCameraBehind(int);
		EXPORT void SetSpideyLookaroundCamValue(unsigned __int16, unsigned __int16, __int16);
};

void validate_CPlayer(void);

#endif
