#pragma once

#ifndef POWERUP_H
#define POWERUP_H

#include "ob.h"
#include "export.h"

EXPORT extern i32 TTime;
class CPowerUp : public CBody
{
	public:
		EXPORT virtual ~CPowerUp(void) OVERRIDE;
		EXPORT CPowerUp(u16, CVector*, CVector*, u32, i32, i32);
		EXPORT void SetGravity(i32, i32);
		EXPORT void SetNode(i32);
		EXPORT void CreateBit(void);
		EXPORT void CheckAge(void);
		EXPORT void DoPhysics(void);

		EXPORT virtual void Die(void);
		EXPORT virtual void AI(void);
		EXPORT virtual void DeleteStuff(void);

		PADDING(4);

		CGlow *mpGlow;

		PADDING(4);

		u8 mHasNode;
		u8 mIs3d;
		u8 mDropping;

		PADDING(0x106-0x102-1);

		u16 mNodeIndex;
		u16 field_108;

		PADDING(0x10C-0x108-2);

		i32 field_10C;

		PADDING(0xE);


		u16 field_11E;
		u16 field_120;

		PADDING(0x124-0x120-2);

		u8 field_124;

		PADDING(0x128-0x124-1);

		i32 field_128;
		u16 mLifetime;

		PADDING(2);

		CFlatBit* pPickupBit;

		PADDING(0x138-0x130-4);
};

EXPORT extern CBody* PowerUpList;
void validate_CPowerUp(void);
#endif
