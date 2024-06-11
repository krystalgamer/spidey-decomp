#pragma once

#ifndef SCORPION_H
#define SCORPION_H

#include "export.h"
#include "baddy.h"


class CScorpion : public CBaddy {
	public:
		EXPORT void NextRoom(void);
		EXPORT void* GetCurrentTarget(void);
		EXPORT CSuper* FindJonah(void);
		EXPORT i32 SetJonahHandle(SHandle*);
		EXPORT void DoIntroSequence(void);
		EXPORT void Gloat(void);
		EXPORT void DetermineTarget(void);
		EXPORT void TakeHit(void);


		unsigned char padTop[0xBEC-0x324];

		CSuper* field_BEC;

		SHandle hCurrentTarget;

		i32 field_BF8;
		u8 padAfterBF8[0xC18-0xBF8-4];

		i32 field_C18;

		u8 padScorpion[0xC28-0xC18-4];
};

EXPORT void Scorpion_GetCurrentTarget(unsigned int*, unsigned int*);

void validate_CScorpion(void);

#endif
