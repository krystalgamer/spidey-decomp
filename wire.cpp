#include "wire.h"

#include "validate.h"

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

// @SMALLTODO
void CTripWire::BuildTripWire(void)
{
    printf("CTripWire::BuildTripWire(void)");
}

// @SMALLTODO
CTripWire::CTripWire(i16 *,u16)
{
    printf("CTripWire::CTripWire(short *,ushort)");
}

// @SMALLTODO
CTripWire::~CTripWire(void)
{
    printf("CTripWire::~CTripWire(void)");
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
}
