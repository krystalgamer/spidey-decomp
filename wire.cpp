#include "wire.h"
#include "trig.h"
#include "spidey.h"
#include "utils.h"
#include "ps2lowsfx.h"
#include "m3dcolij.h"
#include "validate.h"

extern CBody* ControlBaddyList;
extern i16 **gTrigNodes;
extern CPlayer* MechList;
extern CSVector gTrajectoryVector;
extern i32 TotalBitUsage;

// @Ok
void CLaserFence::AI(void)
{
	if (MechList)
	{
		if (MechList->mPos.vx > this->mVxMin && MechList->mPos.vx < this->mVxMax)
		{
			if (MechList->mPos.vz > this->mVzMin && MechList->mPos.vz < this->mVzMax)
			{
				CVector v5;
				v5.vx = 0;
				v5.vy = 0;
				v5.vz = 0;

				if (M3dColij_LineToSphere(
							&this->mPos,
							&this->field_F8,
							&v5,
							MechList,
							0,
							4096) == reinterpret_cast<i32>(MechList))
				{
					SHitInfo v6;

					v6.field_C.vx = 0;
					v6.field_C.vy = 0;
					v6.field_C.vz = 0;

					v6.field_0 = 4;
					v6.field_8 = 10;

					MechList->Hit(&v6);

					if (this->field_114)
					{
						// @FIXME remove this shit
						MechList->nullsub_one(reinterpret_cast<i32>(this));
						Bit_SetSparkTrajectory(&gTrajectoryVector);

						CSVector v4;
						v4.vx = 512;
						v4.vy = 4096;
						v4.vz = 0;
						Bit_SetSparkTrajectoryCone(&v4);
						Bit_SetSparkSize(2u);
						Bit_SetSparkRGB(32, 32, 128);
						Bit_SetSparkFadeRGB(1, 1, 4);
						TotalBitUsage = 1;
					}
				}
			}
		}
	}
}

// @Ok
CLaserFence::CLaserFence(i16* a2, i32 a3, bool a4)
{
	this->field_F8.vx = 0;
	this->field_F8.vy = 0;
	this->field_F8.vz = 0;

	print_if_false((reinterpret_cast<i32>(a2) & 3) == 0, "Bad alignment");

	CVector* pPos = reinterpret_cast<CVector*>(a2);

	this->mPos.vx = pPos->vx << 12;
	this->mPos.vy = pPos->vy << 12;
	this->mPos.vz = pPos->vz << 12;
	this->field_DE = a3;

	u16* LinksPointer = Trig_GetLinksPointer(a3);
	print_if_false(*LinksPointer == 1, "LaserFence trigger has bad links");
	LinksPointer++;
	print_if_false(*LinksPointer != a3, "LaserFence trigger linked to itself");

	Trig_GetPosition(&this->field_F8, *LinksPointer);

	this->CommonInitialisation(a4);
}

// @Ok
// matching
void CLaserFence::CommonInitialisation(bool a2)
{
	this->AttachTo(&ControlBaddyList);
	if ( this->mPos.vx < this->field_F8.vx )
	{
		this->mVxMin = this->mPos.vx;
		this->mVxMax = this->field_F8.vx;
	}
	else
	{
		this->mVxMin = this->field_F8.vx;
		this->mVxMax = this->mPos.vx;
	}

	if ( this->mPos.vz < this->field_F8.vz )
	{
		this->mVzMin = this->mPos.vz;
		this->mVzMax = this->field_F8.vz;
	}
	else
	{
		this->mVzMin = this->field_F8.vz;
		this->mVzMax = this->mPos.vz;
	}

	this->mVxMin -= 0x100000;
	this->mVxMax += 0x100000;
	this->mVzMin -= 0x100000;
	this->mVzMax += 0x100000;

	i32 v10 = (this->field_F8 - this->mPos).Length() / 512;
	if ( v10 < 4 )
		v10 = 4;

	u8 v14, v15;
	if ( a2 )
	{
		v15 = 32;
		v14 = 0x80;
	}
	else
	{
		v15 = 0x80;
		v14 = 32;
	}

	this->field_118 = new CWibbly(0x20u, v15, v14, 1, v10, 0, 700, 32, 48, 440, 110, 800, 147);
	print_if_false(this->field_118 != 0, "No wibbly");

	this->field_118->SetEndPoints(&this->mPos, &this->field_F8);

	this->field_118->mProtected = 1;
	this->mType = 404;

	this->SetPushback(a2);
}

// @Ok
CLaserFence::~CLaserFence(void)
{
	this->DeleteFrom(&ControlBaddyList);

	delete this->field_118;
}

// @Ok
// matching
void CTripWire::AI(void)
{
	u8 v2 = 0;
	SLineSeg* mSegs = this->field_110->mSegs;
	if ( MechList && Utils_CheckObjectCollision(&this->mPos, &this->field_104, MechList, 0) )
	{
		v2 = 1;
		if ( !this->field_FB )
		{
			SFX_Play(0x29u, 0x2000, 0);
			Trig_SendPulseToNode(this->field_100);
			this->field_FB = 1;
		}

		mSegs->r = -(this->field_F8 != 0);
		mSegs->g = -(this->field_F9 != 0);
		mSegs->b = -(this->field_FA != 0);
		this->field_FE = 0;
	}

	if (this->field_44 & 1)
	{
		this->field_FB = 1;
		this->field_44 &= ~1;
	}

	if (!v2)
	{
		if (this->field_FB)
		{
			if (++this->field_FE > 0x3C)
			{
				this->Die();
				return;
			}

			if (Rnd(2))
			{
				//v5 = this->field_F8;
				mSegs->r = this->field_F8 - (this->field_F8 >> 2) + Rnd(this->field_F8 >> 1);

				//v6 = this->field_F9;
				mSegs->g = this->field_F9 - (this->field_F9 >> 2) + Rnd(this->field_F9 >> 1);

				//v7 = this->field_FA;
				mSegs->b = this->field_FA - (this->field_FA >> 2) + Rnd(this->field_FA >> 1);
			}
			else
			{
				mSegs->r = this->field_F8 >> 2;
				mSegs->g = this->field_F9 >> 2;
				mSegs->b = this->field_FA >> 2;
				return;
			}
		}
		else
		{
			//v5 = this->field_F8;
			mSegs->r = this->field_F8 - (this->field_F8 >> 2) + Rnd(this->field_F8 >> 1);

			//v6 = this->field_F9;
			mSegs->g = this->field_F9 - (this->field_F9 >> 2) + Rnd(this->field_F9 >> 1);

			//v7 = this->field_FA;
			mSegs->b = this->field_FA - (this->field_FA >> 2) + Rnd(this->field_FA >> 1);
		}

	}

}

// @Ok
// @Test
INLINE void CTripWire::BuildTripWire(void)
{
	this->field_110 = new CPolyLine(1);

	this->field_110->mStart = this->mPos;

	this->field_110->mProtected = 1;

	this->field_110->SetSemiTransparent();

	this->field_110->mSegs->End = this->field_104;
	this->field_110->mSegs->r = this->field_F8;
	this->field_110->mSegs->g = this->field_F9;
	this->field_110->mSegs->b = this->field_FA;
}

// @Ok
CTripWire::CTripWire(i16 *, u16 a3)
{

	this->field_104.vx = 0;
	this->field_104.vy = 0;
	this->field_104.vz = 0;

	this->AttachTo(&ControlBaddyList);
	this->field_FB = 0;

	Trig_GetPosition(&this->mPos, a3);

	u16* LinksPointer = Trig_GetLinksPointer(a3);
	print_if_false(*LinksPointer == 2, "Incorrect number of links for CTripWire node.");

	u16 v5;
	if ( *gTrigNodes[LinksPointer[1]] == 3 )
	{
		u16 v11 = LinksPointer[2];
		print_if_false(*gTrigNodes[v11] != 3, "Incorrect link node for CTripWire node.");
		this->field_100 = v11;
		v5 = LinksPointer[1];
	}
	else
	{
		this->field_100 = LinksPointer[1];
		v5 = LinksPointer[2];
		print_if_false(*gTrigNodes[v5] == 3, "Incorrect link node for CTripWire node.");
	}

	Trig_GetPosition(&this->field_104, v5);

	this->field_F8 = 32;
	this->field_F9 = 0;
	this->field_FA = 0;
	this->field_FE = 0;
	this->field_FC = 1;

	this->BuildTripWire();
}

// @Ok
CTripWire::~CTripWire(void)
{
	this->DeleteFrom(&ControlBaddyList);

	delete this->field_110;
}

// @Ok
INLINE void CLaserFence::SetPushback(bool pushback)
{
	this->field_114 = pushback;
}

void validate_CLaserFence(void)
{
	VALIDATE_SIZE(CLaserFence, 0x11C);

	VALIDATE(CLaserFence, field_F8, 0xF8);

	VALIDATE(CLaserFence, mVxMin, 0x104);
	VALIDATE(CLaserFence, mVxMax, 0x108);
	VALIDATE(CLaserFence, mVzMin, 0x10C);
	VALIDATE(CLaserFence, mVzMax, 0x110);

	VALIDATE(CLaserFence, field_114, 0x114);
	VALIDATE(CLaserFence, field_118, 0x118);
}

void validate_CTripWire(void)
{
	VALIDATE_SIZE(CTripWire, 0x114);

	VALIDATE(CTripWire, field_F8, 0xF8);
	VALIDATE(CTripWire, field_F9, 0xF9);
	VALIDATE(CTripWire, field_FA, 0xFA);
	VALIDATE(CTripWire, field_FB, 0xFB);
	VALIDATE(CTripWire, field_FC, 0xFC);

	VALIDATE(CTripWire, field_FE, 0xFE);
	VALIDATE(CTripWire, field_100, 0x100);

	VALIDATE(CTripWire, field_104, 0x104);
	VALIDATE(CTripWire, field_110, 0x110);
}
