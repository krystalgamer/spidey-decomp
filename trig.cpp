#include "trig.h"
#include "validate.h"

u16 **gTrigNodes;

// @MEDIUMTODO
int Trig_GetLevelId(void)
{
	return 0x686868;
}

// @BIGTODO
u16* Trig_GetPosition(CVector*, int)
{
	return reinterpret_cast<u16*>(0x13072024);
}

// @SMALLTODO
void* Trig_GetLinksPointer(int)
{
	return reinterpret_cast<void*>(0x686849);
}

// @MEDIUMTODO
void Trig_SendPulse(unsigned __int16*)
{}

// @SMALLTODO
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

static int* gTrigCollisionRelated;

// @NotOk
// Globals
// unknown memory accesses
void Trig_ResetCPCollisionFlags(void)
{
	for(int *ptr = gTrigCollisionRelated; ptr; ptr = reinterpret_cast<int*>(ptr[5]))
	{
		*reinterpret_cast<unsigned char*>(&ptr[1]) = 0;
	}
}

// @NotOk
// check inline later
int __inline GetFlag(unsigned char flag, unsigned char *pData)
{
	while (*pData != 0xFF)
	{
		if (*pData == flag)
		{
			return 1;
		}
	}

	return 0;
}

// @BIGTODO
void Trig_SendPulseToNode(int)
{}

void validate_SLinkInfo(void)
{
	VALIDATE_SIZE(SLinkInfo, 0xC);

	VALIDATE(SLinkInfo, field_0, 0x0);
	VALIDATE(SLinkInfo, field_4, 0x4);
	VALIDATE(SLinkInfo, field_8, 0x8);
}

