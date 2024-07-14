#include "trig.h"
#include "validate.h"

i16 **gTrigNodes;
i32 gNumNodes;

// @SMALLTODO
void* Trig_GetLinkInfoList(i32, SLinkInfo*, i32)
{
	return reinterpret_cast<void*>(0x13072024);
}

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

// @Ok
i16* Trig_GetLinksPointer(int a1)
{
	print_if_false(a1 >= 0 && a1 < gNumNodes, "Bad node sent to Trig_GetLinksPointer");

	i16* trigNodePtr = gTrigNodes[a1];

	if (*trigNodePtr <= 0xD)
	{
		if (*trigNodePtr < 0xC)
		{
			switch (*trigNodePtr)
			{
				case 1:
					return trigNodePtr + 3;
				case 2:
				case 3:
				case 6:
				case 8:
				case 9:
				case 10:
					return trigNodePtr + 1;
				case 5:
					return trigNodePtr + 2;
				default:
					print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
					print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
					return 0;
			}
		}
		else
		{
			return trigNodePtr + 1;
		}
	}
	else if (*trigNodePtr <= 0x3E9)
	{
		if (*trigNodePtr < 0x3E8)
		{
			if (*trigNodePtr != 0x14)
			{
				print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
				print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
				return 0;
			}

			return trigNodePtr + 2;
		}

		return trigNodePtr + 1;
	}
	else if (*trigNodePtr != 0x3EA)
	{
		print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
		print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
		return 0;
	}

	return trigNodePtr + 2;
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
	VALIDATE_SIZE(SLinkInfo, 0x10);

	VALIDATE(SLinkInfo, field_0, 0x0);
	VALIDATE(SLinkInfo, field_4, 0x4);
	VALIDATE(SLinkInfo, field_8, 0x8);
	VALIDATE(SLinkInfo, field_C, 0xC);
}

