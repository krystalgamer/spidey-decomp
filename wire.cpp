#include "wire.h"

#include "validate.h"

void validate_CLaserFence(void)
{
	VALIDATE_SIZE(CLaserFence, 0x11C);
}
