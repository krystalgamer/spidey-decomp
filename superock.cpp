#include "superock.h"
#include "ps2m3d.h"
#include "spidey.h"
#include "trig.h"
#include "ps2lowsfx.h"
#include "utils.h"

#include <cmath>

#include "validate.h"

extern CBaddy* BaddyList;
extern CPlayer* MechList;

void CSuperDocOck::DoPhysics(void)
{
	if (!this->field_338)
	{
		printf("LOOOOL");
	}


	/*
	v7 = this->cbaddy.csuper.cbody.csVector1.vy + this->cbaddy.csuper.cbody.field_8E.vy;
	this->cbaddy.csuper.cbody.csVector1.vx = this->cbaddy.csuper.cbody.csVector1.vx
	+ this->cbaddy.csuper.cbody.field_8E.vx
	- ((__int16)(this->cbaddy.csuper.cbody.csVector1.vx
	+ this->cbaddy.csuper.cbody.field_8E.vx) >> 2);

	this->cbaddy.csuper.cbody.csVector1.vy = v7 - (v7 >> 2);
	CSVector_KillSmall(&this->cbaddy.csuper.cbody.csVector1);
	if ( this->cbaddy.csuper.cbody.field_80 > 0 )
	{
	do
	{
	CVector::operator+=(&this->cbaddy.csuper.cbody.citem.mPos, &this->cbaddy.csuper.cbody.mAccellorVel);
	CSVector::operator+=(&this->cbaddy.csuper.cbody.citem.mAngles, &this->cbaddy.csuper.cbody.csVector1);
	++v2;
	}
	while ( v2 < this->cbaddy.csuper.cbody.field_80 );
	}
	CSVector::Mask(&this->cbaddy.csuper.cbody.citem.mAngles);
	*/

}

// @Ok
void CSuperDocOck::PlaySounds(void)
{
	switch (this->field_12A)
	{
		case 1:
			if (!(this->field_364 & 1) && this->field_128 >= 0)
			{
				SFX_PlayPos((Rnd(3) + 230) | 0x8000, &this->mPos, 0);
				this->field_364 |= 1u;
			}
			else if (!(this->field_364 & 2) && this->field_128 >= 20)
			{
				SFX_PlayPos((Rnd(3) + 230) | 0x8000, &this->mPos, 0);
				this->field_364 |= 2u;
			}
			break;
		case 4:
			if (!(this->field_364 & 1) && this->field_128 >= 0)
			{
				SFX_PlayPos((Rnd(3) + 230) | 0x8000, &this->mPos, 0);
				this->field_364 |= 1u;
			}
			break;
		case 6:
			if (!(this->field_364 & 1) && this->field_128 >= 20)
			{
				SFX_PlayPos((Rnd(3) + 230) | 0x8000, &this->mPos, 0);
				this->field_364 |= 1u;
			}
			break;
	}
}

// @Ok
// @Test
// Not sure what they did in the register array asignment when v2 > v3
// sub i16 but then move i32 and assign i16
void CSuperDocOck::HangAndGetBeaten(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			i16 v5;
			v5 = Rnd(120) + 120;
			print_if_false(1u, "Bad register index");

			this->registerArr[1] = v5;

			this->mCBodyFlags |= 0x10;
			this->field_DC = 100;
			this->dumbAssPad++;

			break;
		case 1:
			print_if_false(1u, "Bad register index");
			i32 v2 = this->registerArr[1];
			i32 v3 = this->field_80;

			if ( v2 > v3 )
			{
				i32 v4;
				v4 = v2 - v3;

				print_if_false(1u, "Bad register index");
				this->registerArr[1] = v4;
			}
			else
			{
				print_if_false(1u, "Bad register index");
				this->registerArr[1] = 0;
				this->mCBodyFlags &= ~0x10u;
				this->field_DC = 0;
				this->field_364 = 0;
				this->RunAnim(0x18u, 0, -1);
				this->dumbAssPad = 0;
				this->field_31C.bothFlags = 2048;
			}
			break;
	}
}

// @Ok
// @Test
void CSuperDocOck::CreateExplosion(i32 a2, i32)
{
	CVector a3;
	a3.vx = 0;
	a3.vy = 0;
	a3.vz = 0;

	Trig_GetPosition(&a3, a2);
	SFX_PlayPos(0x23u, &a3, 0);

	CSVector v7;
	v7.vx = 0;
	v7.vy = 0;
	v7.vz = 0;
	Utils_CalcAim(&v7, &this->mPos, &a3);

	i32 v4 = v7.vy - this->mAngles.vy;
	if (v4 < -2048)
	{
		v4 += 4096;
	}
	else if (v4 > 2048)
	{
		v4 -= 4096;
	}

	if (abs(v4) >= 0x600)
	{
		this->field_218 |= 0x80;
	}
	else if  (v4 < -256)
	{
		this->field_218 |= 0x20;
	}
	else if  (v4 > 256)
	{
		this->field_218 |= 0x40;
	}

	this->mAccellorVel.vz = 0;
	this->mAccellorVel.vy = 0;
	this->mAccellorVel.vx = 0;
	this->field_218 &= ~0x100;
	this->field_31C.bothFlags = 0x2000;
	this->dumbAssPad = 0;
}

// @Ok
void CSuperDocOck::PlayIdleOrGloatAnim(void)
{
	if ( !(this->field_218 & 0x10))
	{
		if ( !this->field_3D8 )
		{
			this->PlaySingleAnim(22, 0, -1);
			return;
		}

		if ( this->field_3E0 > 600 || MechList->field_E2 <= 0 )
		{
			if ( this->field_3D4 == 1 )
				this->PlaySingleAnim(35, 0, -1);
			else
				this->PlaySingleAnim(1, 0, -1);

			this->field_3E0 = 0;
			this->field_31C.bothFlags = 0x8000;
			this->dumbAssPad = 0;
		}
		else
		{
			this->PlaySingleAnim(1, 0, -1);
		}
	}
}

// @Ok
void CSuperDocOck::Gloat(void)
{
	if ( this->field_142 )
	{
		this->csuperend = 0x10000;
		this->PlayIdleOrGloatAnim();
	}
}

// @Ok
INLINE void CSuperDocOck::Initialise(void)
{
	this->field_39C = 455;
	this->field_368 = this->field_DE;
	this->field_31C.bothFlags = 0x10000;
	this->dumbAssPad = 0;
}

// @Ok
INLINE void CSuperDocOck::PlaySingleAnim(u32 a2, i32 a3, i32 a4)
{
	this->field_364 = 0;
	this->RunAnim(a2, a3, a4);
}

// @Ok
CSuperDocOck::~CSuperDocOck(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
	this->KillAllCommandBlocks();

	delete reinterpret_cast<CItem*>(this->field_360);

	for (i32 i = 0; i< 4; i++)
	{
		if (this->field_3B4[i])
			Mem_Delete(this->field_3B4[i]);

		delete reinterpret_cast<CItem*>(this->field_404[i]);
		delete reinterpret_cast<CItem*>(this->field_3F4[i]);
	}
}

// @NotOk
// globals
CSuperDocOck::CSuperDocOck(int *a2, int a3)
{
	this->field_32C = 0;
	this->field_330 = 0;
	this->field_334 = 0;

	this->field_344 = reinterpret_cast<int>(
			this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2))));

	this->InitItem("superock");
	this->mFlags |= 0x480;
	this->mCBodyFlags &= 0xFFEF;
	this->field_3C = 0x557928;

	this->field_E2 = 500;
	this->field_DC = 0;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->field_38 = 309;
	this->field_1F4 = a3;
	this->field_DE = a3;

	this->field_36C = 1024;
	this->field_374 = 0x10000;
	this->field_370 = 0x10000;
	this->field_3D8 = 4;
	this->field_31C.bothFlags = 1;
	this->field_21E = 100;

	*reinterpret_cast<int*>(0x54E8D4) = 4096;
	*reinterpret_cast<int*>(0x60F774) = 0xFFFFFF;
	*reinterpret_cast<unsigned char*>(0x60F772) = 1;
	*reinterpret_cast<int*>(0x60F778) = *gTimerRelated;

	this->field_194 = 0xFFFE0000;
	this->field_198 = 0x1FFF;
}

// @Ok
void SuperDocOck_CreateSuperDocOck(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CSuperDocOck(v2, v3));
}

// @Ok
void CSuperDocOck::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @Ok
void CSuperDocOck::RenderClaws(void)
{
	M3d_Render(this->field_3F4[0]);
}

// @BIGTODO
__inline int* CSuperDocOck::KillCommandBlock(int*)
{
	return (int*)0x02062024;
}

// @NotOk
// Revisit
void CSuperDocOck::KillAllCommandBlocks(void)
{
	for (int* cur = reinterpret_cast<int*>(this->field_348); cur; cur = this->KillCommandBlock(cur));
	this->field_348 = 0;
}

void validate_CSuperDocOck(void){
	VALIDATE_SIZE(CSuperDocOck, 0x414);

	VALIDATE(CSuperDocOck, field_32C, 0x32C);
	VALIDATE(CSuperDocOck, field_330, 0x330);
	VALIDATE(CSuperDocOck, field_334, 0x334);

	VALIDATE(CSuperDocOck, field_338, 0x338);

	VALIDATE(CSuperDocOck, field_344, 0x344);
	VALIDATE(CSuperDocOck, field_348, 0x348);

	VALIDATE(CSuperDocOck, field_360, 0x360);
	VALIDATE(CSuperDocOck, field_364, 0x364);
	VALIDATE(CSuperDocOck, field_368, 0x368);

	VALIDATE(CSuperDocOck, field_36C, 0x36C);
	VALIDATE(CSuperDocOck, field_370, 0x370);
	VALIDATE(CSuperDocOck, field_374, 0x374);

	VALIDATE(CSuperDocOck, field_3B4, 0x3B4);

	VALIDATE(CSuperDocOck, field_3D4, 0x3D4);
	VALIDATE(CSuperDocOck, field_3D8, 0x3D8);

	VALIDATE(CSuperDocOck, field_3E0, 0x3E0);

	VALIDATE(CSuperDocOck, field_3F4, 0x3F4);
	VALIDATE(CSuperDocOck, field_404, 0x404);
}
