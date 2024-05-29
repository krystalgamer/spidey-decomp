#pragma once

#ifndef SCORPION_H
#define SCORPION_H

#include "export.h"
#include "baddy.h"


class CScorpion : public CBaddy {
	public:
		EXPORT void NextRoom(void);
		EXPORT void* GetCurrentTarget(void);


		unsigned char padTop[0xBF0-0x324];

		SHandle field_BF0;
		unsigned char padAfterBF0[0xBF8-0xBF0 - sizeof(SHandle)];

		int field_BF8;

		unsigned char padScoprtion[0xC28-0xBF8-4];
};

EXPORT void Scorpion_GetCurrentTarget(unsigned int*, unsigned int*);

void validate_CScorpion(void);

#endif
