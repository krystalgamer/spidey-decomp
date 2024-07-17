#include "trig.h"
#include "validate.h"
#include "mem.h"
#include "utils.h"
#include "spidey.h"

EXPORT void* gTrigFile;
EXPORT u16 **gTrigNodes;
EXPORT i32 NumNodes;

const i32 MAXPENDING = 16;
EXPORT PendingListEntry PendingListArray[MAXPENDING];
EXPORT SCommandPoint* CommandPoints;
EXPORT SCommandPoint* HashTable[256];
static int gTrigMenu[40];
static int gRestartPoints;
EXPORT i32 Restart;
EXPORT i32 RestartNode;
EXPORT i32 gReStartDeathRelated;
EXPORT i32 EndLevelNode;

extern i32 JoelJewCheatCode;

extern CPlayer* MechList;

//@IGNORE
void trigLog(const char*, ...)
{
	printf("trigLog!");
}

// @Ok
void Trig_ExecuteAutoexec(void)
{
	print_if_false(gTrigFile != 0, "No trigger file");
	EndLevelNode = 0xFFFF;

	if (JoelJewCheatCode)
	{
		for (i32 curNode = 0; curNode < NumNodes; curNode++)
		{
			u16 *v5 = gTrigNodes[curNode];
			if (*v5 == 15)
			{
				trigLog("*** Executing AUTOEXEC2 Node %i ***", curNode);
				ExecuteCommandList(v5 + 1, curNode, 1);
				return;
			}
		}
	}

	for (i32 curNode = 0; curNode < NumNodes; curNode++)
	{
		u16 *v5 = gTrigNodes[curNode];
		if (*v5 == 4)
		{
			trigLog("*** Executing AUTOEXEC Node %i ***", curNode);
			ExecuteCommandList(v5 + 1, curNode, 1);
		}
	}
}

// @Ok
void Trig_ExecuteRestart(void)
{
	print_if_false(RestartNode != 0xFFFF, "Tried to execute a restart with no restart node set");
	print_if_false(*gTrigNodes[RestartNode] == 8, "Eh? Restart node isn't a restart node!");
	print_if_false(MechList != 0, "Tried to execute a restart with a NULL MechList");

	CVector v7;
	v7.vx = 0;
	v7.vy = 0;
	v7.vz = 0;

	CSVector *Position = reinterpret_cast<CSVector*>(Trig_GetPosition(&v7, RestartNode));

	MechList->mPos = v7;
	MechList->SetStartOrientation(Position);

	char *v3 = reinterpret_cast<char*>(&Position[1]);
	trigLog("*** Executing Restart Node: %s ***", v3);

	v3 = SkipString(v3);

	Trig_ZeroPendingList();
	ExecuteCommandList(reinterpret_cast<u16*>(v3), RestartNode, 1);
}

// @Ok
void Trig_SetRestart(char *pName)
{
	RestartNode = 0xFFFF;
	for (i32 curNode = 0; curNode < NumNodes; curNode++)
	{
		if (*gTrigNodes[curNode] == 8)
		{
			CVector v3;
			v3.vx = 0;
			v3.vy = 0;
			v3.vz = 0;

			u16* Position = Trig_GetPosition(&v3, curNode);
			
			if (Utils_CompareStrings(reinterpret_cast<char*>(&Position[3]), pName))
			{
				RestartNode = curNode;
				trigLog("Set RestartNode = %i", curNode);
				if (!Utils_CompareStrings(pName, "re_start_death"))
					gReStartDeathRelated = 1;
				return;
			}
		}
	}

	print_if_false(0, "Restart point ");
}

// @Ok
INLINE char *SkipString(char *pText)
{
	while(*pText)
		pText++;

	pText++;

	return &pText[reinterpret_cast<u32>(pText) & 1];
}

// @Ok
void Trig_DeleteTrigFile(void)
{
	if (gTrigFile)
	{
		Mem_Delete(reinterpret_cast<void*>(gTrigFile));
		gTrigFile = 0;
	}

	Restart = 0;
	Trig_ZeroPendingList();
}

// @BIGTODO
void ExecuteCommandList(u16*, i32, i32)
{
	printf("ExecuteCommandList");
}

// @Ok
void Trig_DoPendingCommandLists(void)
{
	for (i32 i = 0; i<MAXPENDING && PendingListArray[i].pCommands; i++)
	{
		ExecuteCommandList(
				PendingListArray[i].pCommands,
				PendingListArray[i].NodeIndex,
				0);
	}

	Trig_ZeroPendingList();
}

// @Ok
INLINE void Trig_AddCommandListToPending(u16 nodeIndex, u16* pCommands)
{
	i32 i;
	for(i = 0; i < MAXPENDING && PendingListArray[i].pCommands; i++);

	print_if_false(i < 16, "Pending command list overflow, increase MAXPENDING in trig.cpp");

	PendingListArray[i].NodeIndex = nodeIndex;
	PendingListArray[i].pCommands = pCommands;
}

// @Ok
SCommandPoint* Trig_TriggerCommandPoint(u32 checksum, bool assert)
{
	for (SCommandPoint *pSearch = HashTable[(checksum)&0xFF]; pSearch; pSearch = pSearch->pNextSimilar)
	{
		if (pSearch->Checksum == checksum)
		{
			pSearch->Collision = 1;
			if (!pSearch->Executed)
			{
				trigLog("\tCommandPoint Triggered: node %i", pSearch->NodeIndex);
				Trig_AddCommandListToPending(pSearch->NodeIndex, pSearch->pCommands);
				pSearch->Executed = 1;
				return pSearch;
			}
		}
	}

	return 0;
}

// @Ok
SCommandPoint* GetCommandPoint(i32 Node)
{
	if (Node != 0xFFF && *gTrigNodes[Node] == 6)
	{
		for (SCommandPoint *cur = CommandPoints; cur; cur = cur->pNext)
		{
			if (cur->NodeIndex == Node)
				return cur;
		}
	}

	return 0;
}

// @Ok
SCommandPoint* CreateCommandPoint(u32 checksum, u16 node, u16* pCommands)
{
	SCommandPoint* result = static_cast<SCommandPoint*>(DCMem_New(sizeof(SCommandPoint), 0, 1, 0, 1));

	result->pNext = CommandPoints;
	CommandPoints = result;

	u32 index = (checksum) & 0xFF;
	result->pNextSimilar = HashTable[index];
	HashTable[index] = result;

	result->Collision = 0;
	result->Executed = 0;
	result->NodeIndex = node;
	result->pCommands = pCommands;
	result->Checksum = checksum;
	result->PulsesReceived = 0;
	result->NumPulsesSet = 0;
	result->NumPulses = 0;

	return result;
}

// @Ok
void Trig_DeleteCommandPoints(void)
{
	for (i32 i = 0; i<256; i++)
		HashTable[i] = 0;

	for (SCommandPoint *cur = CommandPoints; cur; )
	{
		SCommandPoint *next = cur->pNext;
		Mem_Delete(reinterpret_cast<void*>(cur));
		cur = next;
	}

	CommandPoints = 0;
	Trig_ZeroPendingList();
}

// @Ok
INLINE void Trig_ZeroPendingList(void)
{
	for (i32 i = 0; i<MAXPENDING; i++)
	{
		PendingListArray[i].NodeIndex = 0;
		PendingListArray[i].pCommands = 0;
	}
}

// @Ok
void Trig_ResetCPExecutedFlags(void)
{
	for(SCommandPoint *cur = CommandPoints; cur; cur = cur->pNext)
	{
		if (cur->Executed && !cur->Collision)
			cur->Executed = 0;
	}
}

// @Ok
void* Trig_GetLinkInfoList(
		i32 a1,
		SLinkInfo* pLink,
		i32 count)
{
	i32 result = 0;

	u16* linksPtr = reinterpret_cast<u16*>(Trig_GetLinksPointer(a1));

	if (*linksPtr)
	{
		u16 *v8 = linksPtr + 1;
		result = *linksPtr;

		if (result)
		{
			for (i32 i = 0; i<result && i < count; i++, v8++)
			{
				u16 *v11 = gTrigNodes[*v8];

				pLink[i].field_0 = *v8;
				pLink[i].field_4 = *v11;
				if (*v11 == 1002)
					pLink[i].field_8 = v11[1];
				else
					pLink[i].field_8 = 0;
				pLink[i].field_C = 0;
			}
		}
	}


	if (result <= count)
	{
		return reinterpret_cast<void*>(result);
	}

	return reinterpret_cast<void*>(count);

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
u16* Trig_GetLinksPointer(int node)
{
	print_if_false(node >= 0 && node < NumNodes, "Bad node sent to Trig_GetLinksPointer");

	i16* trigNodePtr = reinterpret_cast<i16*>(gTrigNodes[node]);

	if (*trigNodePtr <= 0xD)
	{
		if (*trigNodePtr < 0xC)
		{
			switch (*trigNodePtr)
			{
				case 1:
					return reinterpret_cast<u16*>(trigNodePtr + 3);
				case 2:
				case 3:
				case 6:
				case 8:
				case 9:
				case 10:
					return reinterpret_cast<u16*>(trigNodePtr + 1);
				case 5:
					return reinterpret_cast<u16*>(trigNodePtr + 2);
				default:
					print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
					print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
					return 0;
			}
		}
		else
		{
			return reinterpret_cast<u16*>(trigNodePtr + 1);
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

			return reinterpret_cast<u16*>(trigNodePtr + 2);
		}

		return reinterpret_cast<u16*>(trigNodePtr + 1);
	}
	else if (*trigNodePtr != 0x3EA)
	{
		print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
		print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
		return 0;
	}

	return reinterpret_cast<u16*>(trigNodePtr + 2);
}

// @MEDIUMTODO
void Trig_SendPulse(unsigned __int16*)
{}

// @SMALLTODO
void Trig_SendSignalToLinks(unsigned __int16*)
{}

// @Ok
void Trig_ClearTrigMenu(void)
{
	for (int i = 0; i<40; i++)
	{
		gTrigMenu[i] = 0;
	}

	gRestartPoints = 0;
}

// @Ok
unsigned char* SkipFlags(unsigned char* pFlags)
{
	while(*pFlags != 0xFF)
		pFlags++;

	return pFlags+1;
}


// @Ok
void Trig_ResetCPCollisionFlags(void)
{
	for(SCommandPoint *cur = CommandPoints; cur; cur = cur->pNext)
	{
		cur->Collision = 0;
	}
}

// @NotOk
// check inline later
INLINE u8 GetFlag(unsigned char flag, unsigned char *pFlags)
{
	while (*pFlags != 0xFF)
	{
		if (*pFlags == flag)
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

void validate_SCommandPoint(void)
{
	VALIDATE_SIZE(SCommandPoint, 0x18);


	VALIDATE(SCommandPoint, pCommands, 0x0);

	VALIDATE(SCommandPoint, Collision, 0x4);
	VALIDATE(SCommandPoint, Executed, 0x5);

	VALIDATE(SCommandPoint, NumPulsesSet, 0x6);
	VALIDATE(SCommandPoint, PulsesReceived, 0x7);
	VALIDATE(SCommandPoint, NumPulses, 0x8);
	VALIDATE(SCommandPoint, NodeIndex, 0xA);
	VALIDATE(SCommandPoint, Checksum, 0xC);

	VALIDATE(SCommandPoint, pNextSimilar, 0x10);
	VALIDATE(SCommandPoint, pNext, 0x14);
}

void validate_PendingListEntry(void)
{
	VALIDATE_SIZE(PendingListEntry, 0x8);

	VALIDATE(PendingListEntry, NodeIndex, 0x0);
	VALIDATE(PendingListEntry, field_2, 0x2);
	VALIDATE(PendingListEntry, pCommands, 0x4);
}
