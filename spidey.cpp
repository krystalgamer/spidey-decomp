#include "spidey.h"
#include "validate.h"


// @Ok
void CPlayer::SetCamAngleLock(unsigned __int16 a1)
{
	if (a1)
	{
		this->gCamAngleLock = 0;
	}
	else
	{
		this->gCamAngleLock = 1;
	}
}

void validate_CPlayer(void)
{
	VALIDATE_SIZE(CPlayer, 0xEFC);

	VALIDATE(CPlayer, gCamAngleLock, 0x8EC);
}
