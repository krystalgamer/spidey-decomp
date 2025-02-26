#pragma once

#ifndef L1A3BOMB_H
#define L1A3BOMB_H

#include "export.h"
#include "manipob.h"

class CL1A3Bomb : public CManipOb
{
	public:
		EXPORT CL1A3Bomb(u16*, i32);
		EXPORT void DoPhysics(void);

		EXPORT virtual void Die(void);
		EXPORT virtual void Smash(void);
		EXPORT virtual void AI(void);

		EXPORT virtual ~CL1A3Bomb(void);

		u8 field_128;
		u8 field_129;

		u8 padBottom[0x12C-0x129-1];
};

EXPORT extern u32 gBombRelated;
EXPORT extern u8 gBombDieRelatedOne;
EXPORT extern u8 gBombDieRelatedTwo;
EXPORT extern u32 gBombDieTimerRelated;
EXPORT extern u32 gBombAIRelated;

void validate_CL1A3Bomb(void);
#endif
