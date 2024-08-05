#include "wire.h"
#include "trig.h"
#include "validate.h"

extern CBody* ControlBaddyList;
extern i16 **gTrigNodes;

// @SMALLTODO
void CLaserFence::AI(void)
{
    printf("CLaserFence::AI(void)");
}

// @SMALLTODO
CLaserFence::CLaserFence(short *,i32,bool)
{
    printf("CLaserFence::CLaserFence(short *,i32,bool)");
}

// @SMALLTODO
void CLaserFence::CommonInitialisation(bool)
{
    printf("CLaserFence::CommonInitialisation(bool)");
}

// @SMALLTODO
CLaserFence::~CLaserFence(void)
{
    printf("CLaserFence::~CLaserFence(void)");
}

// @MEDIUMTODO
void CTripWire::AI(void)
{
    printf("CTripWire::AI(void)");
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
void CLaserFence::SetPushback(bool pushback)
{
	this->field_114 = pushback;
}

void validate_CLaserFence(void)
{
	VALIDATE_SIZE(CLaserFence, 0x11C);

	VALIDATE(CLaserFence, field_114, 0x114);
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
