#include "trig.h"
#include "validate.h"


// @TODO
int Trig_GetLevelId(void)
{
	return 0x686868;
}

// @TODO
void Trig_GetPosition(CVector*, int)
{}

// @TODO
void* Trig_GetLinksPointer(int)
{
	return reinterpret_cast<void*>(0x686849);
}

// @TODO
void Trig_SendPulse(unsigned __int16*)
{}

// @TODO
void Trig_SendSignalToLinks(unsigned __int16*)
{}

static int gTrigMenu[40];
static int gRestartPoints;
// @NotOk
// Globals
void Trig_ClearTrigMenu(void)
{
	for (int i = 0; i<40; i++)
	{
		gTrigMenu[i] = 0;
	}

	gRestartPoints = 0;
}

// @Ok
unsigned char* SkipFlags(unsigned char* ptr)
{
	while(*ptr != 0xFF)
		ptr++;

	return ptr+1;
}

void validate_SLinkInfo(void)
{
	VALIDATE_SIZE(SLinkInfo, 0xC);

	VALIDATE(SLinkInfo, field_0, 0x0);
	VALIDATE(SLinkInfo, field_4, 0x4);
	VALIDATE(SLinkInfo, field_8, 0x8);
}

