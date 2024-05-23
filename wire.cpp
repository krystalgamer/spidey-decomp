#include "wire.h"

#include "validate.h"

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
