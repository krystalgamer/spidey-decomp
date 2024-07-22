#include "chopper.h"
#include "validate.h"
#include "utils.h"
#include "baddy.h"
#include "trig.h"

extern CBaddy* ControlBaddyList;

// @Ok
void Chopper_CreateSearchlight(u32* a1, u32* a2)
{
	i32 v3 = *a1;

	*a2 = reinterpret_cast<u32>(new CSearchlight(v3));
}

// @MEDIUMTODO
void CSearchlight::SpecialRenderer(void)
{
	printf("CSearchlight::SpecialRenderer(void)");
}

// @Ok
CSearchlight::~CSearchlight(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&ControlBaddyList));
}

// @BIGTODO
void CSearchlight::AI(void)
{
}

// @Ok
CSearchlight::CSearchlight(i32 a2)
{
	this->field_104.vx = 0;
	this->field_104.vy = 0;
	this->field_104.vz = 0;

	this->field_110.vx = 0;
	this->field_110.vy = 0;
	this->field_110.vz = 0;

	this->field_11C.vx = 0;
	this->field_11C.vy = 0;
	this->field_11C.vz = 0;

	for (i32 i = 0; i < 66; i++)
	{
		this->field_138[i].vx = 0;
		this->field_138[i].vy = 0;
		this->field_138[i].vz = 0;
	}

	this->field_38 = 322;
	this->AttachTo(reinterpret_cast<CBody**>(&ControlBaddyList));

	Trig_GetPosition(&this->mPos, a2);
	u16 *LinksPointer = Trig_GetLinksPointer(a2);
	print_if_false(*LinksPointer == 0, "No path for searchlight");

	this->field_F8 = LinksPointer[1];
	Trig_GetPosition(&this->field_104, this->field_F8);

	u16 *OtherLinks = Trig_GetLinksPointer(this->field_F8);
	print_if_false(*OtherLinks == 0, "No path for searchlight");

	this->field_FC = OtherLinks[1];
	Trig_GetPosition(&this->field_110, this->field_FC);

	this->field_11C = (this->field_110 - this->field_104) / 240;
	this->field_100 = 0;
}

// @Ok
INLINE void CChopper::WaitForTrigger(void)
{
	switch (this->dumbAssPad)
	{
		case 0:

			if (this->field_218 & 4)
			{
				this->field_218 &= 0xFB;
				if (this->GetNextWaypoint())
				{
					this->dumbAssPad = 0;
					this->field_31C.bothFlags = 2;
				}
				else
				{
					this->dumbAssPad = 0;
					this->field_31C.bothFlags = 1;
				}
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
	}
}

// @NotOk
// verify later
void CBulletFrag::Move()
{
  this->mPos.vx += this->mVel.vx;
  this->mPos.vy += this->mVel.vy;
  this->mPos.vz += this->mVel.vz;
  this->mVel.vy += 0x7390;

  this->field_58 += this->field_5A;

  if ( ++this->field_C > (int)(unsigned __int16)this->field_E )
	  this->Die();
}

// @Ok
INLINE void CChopper::SetHeightMode(int mode)
{
	this->field_374 = mode;
}

// @Ok
void __inline CSniperTarget::BulletResult(bool result)
{
	this->field_FC++;
	if (result)
		this->field_128 = true;
}

// @Ok
void __inline CChopper::AdjustSineWaveAmplitude(int a2, int a3)
{
	int tmp = this->field_354;
	if (tmp != a2)
	{
		this->field_354 = Utils_LinearFilter(tmp, a2, a3);
	}
}

// @Ok
void CChopper::AngleToTargetAngle(void)
{
	int v1 = (this->field_360 & 0xFFF) - (this->mAngles.vy - 0xFFF);

	if (v1 > 2048)
	{
		v1 -= 4096;
	}
	else if (v1 < -2048)
	{
		v1 += 4096;
	}


	this->csVector1.vy = v1 >> 5;
	this->mAngles.vy += this->csVector1.vy;
}

void validate_CChopper(void){
	VALIDATE_SIZE(CChopper, 0x3D8);

	VALIDATE(CChopper, field_328, 0x328);

	VALIDATE(CChopper, field_330, 0x330);
	VALIDATE(CChopper, field_334, 0x334);
	VALIDATE(CChopper, field_338, 0x338);
	VALIDATE(CChopper, field_33C, 0x33C);
	VALIDATE(CChopper, field_340, 0x340);

	VALIDATE(CChopper, field_344, 0x344);
	VALIDATE(CChopper, field_348, 0x348);

	VALIDATE(CChopper, field_354, 0x354);

	VALIDATE(CChopper, field_358, 0x358);
	VALIDATE(CChopper, field_360, 0x360);
	VALIDATE(CChopper, field_364, 0x364);
	VALIDATE(CChopper, field_368, 0x368);
	VALIDATE(CChopper, field_36C, 0x36C);

	VALIDATE(CChopper, field_374, 0x374);

	VALIDATE(CChopper, field_380, 0x380);
	VALIDATE(CChopper, field_384, 0x384);

	VALIDATE(CChopper, field_388, 0x388);
	VALIDATE(CChopper, field_38C, 0x38C);
	VALIDATE(CChopper, field_390, 0x390);
	VALIDATE(CChopper, field_394, 0x394);
	VALIDATE(CChopper, field_398, 0x398);
	VALIDATE(CChopper, field_39C, 0x39C);
	VALIDATE(CChopper, field_3A8, 0x3A8);
	VALIDATE(CChopper, field_3AC, 0x3AC);
	VALIDATE(CChopper, field_3B0, 0x3B0);
	VALIDATE(CChopper, field_3B4, 0x3B4);
	VALIDATE(CChopper, field_3B8, 0x3B8);
	VALIDATE(CChopper, field_3BC, 0x3BC);
	VALIDATE(CChopper, field_3C0, 0x3C0);
	VALIDATE(CChopper, field_3C8, 0x3C8);
	VALIDATE(CChopper, field_3CC, 0x3CC);
	VALIDATE(CChopper, field_3D0, 0x3D0);
}

void validate_CBulletFrag(void){
	VALIDATE_SIZE(CBulletFrag, 0x68);
}

void validate_CSniperSplat(void){
	VALIDATE_SIZE(CSniperSplat, 0x88);
}

void validate_CSniperTarget(void)
{
	VALIDATE_SIZE(CSniperTarget, 0x15C);

	VALIDATE(CSniperTarget, field_FC, 0xFC);
	VALIDATE(CSniperTarget, field_128, 0x128);
}

void validate_CSearchlight(void)
{
	VALIDATE_SIZE(CSearchlight, 0x450);

	VALIDATE(CSearchlight, field_F8, 0xF8);
	VALIDATE(CSearchlight, field_FC, 0xFC);
	VALIDATE(CSearchlight, field_100, 0x100);
	VALIDATE(CSearchlight, field_104, 0x104);
	VALIDATE(CSearchlight, field_110, 0x110);
	VALIDATE(CSearchlight, field_11C, 0x11C);
	VALIDATE(CSearchlight, field_138, 0x138);

	VALIDATE_VTABLE(CSearchlight, SpecialRenderer, 5);
}
