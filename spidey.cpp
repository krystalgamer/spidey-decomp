#include "spidey.h"
#include "validate.h"

void CPlayer::SetIgnoreInputTimer(int a2)
{
	this->field_E18 = a2;
	if (a2)
	{
		this->field_E12 = this->csuperend;
		if (this->field_8EA)
		{
			this->ExitLookaroundMode();
		}
	}
}

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


// @TODO
void CPlayer::ExitLookaroundMode(void)
{}

void validate_CPlayer(void)
{
	VALIDATE_SIZE(CPlayer, 0xEFC);

	VALIDATE(CPlayer, field_8EA, 0x8EA);

	VALIDATE(CPlayer, gCamAngleLock, 0x8EC);

	VALIDATE(CPlayer, field_E12, 0xE12);
	VALIDATE(CPlayer, field_E18, 0xE18);
}
