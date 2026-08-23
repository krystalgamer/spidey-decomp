#include "trig.h"
#include "validate.h"
#include "mem.h"
#include "utils.h"
#include "spidey.h"
#include "baddy.h"
#include "spool.h"
#include "exp.h"
#include "my_assert.h"

#include <cstdarg>

i32 gRunCinemaRelated;
i32 gLevelStatus;

EXPORT u16* TrigFile;
//#define G_TRIGFILE (TrigFile)
#define G_TRIGFILE (*reinterpret_cast<u16**>(0x006B4668))

EXPORT i32 NumCheatRestarts;
//#define G_NUMCHEATRESTARTS (NumCheatRestarts)
#define G_NUMCHEATRESTARTS (*reinterpret_cast<i32*>(0x006B4664))

// @Ok
i16 **OffsetList;


// @Ok
EXPORT i32 NumNodes;
//#define G_NUMNODES (NumNodes)
#define G_NUMNODES (*reinterpret_cast<i32*>(0x006B4670))

// @Ok
const i32 MAXPENDING = 16;

// @Ok
EXPORT PendingListEntry PendingListArray[MAXPENDING];
//#define G_PENDINGLISTARRAY (PendingListArray)
#define G_PENDINGLISTARRAY (reinterpret_cast<PendingListEntry*>(0x006B4688))

// @Ok
EXPORT SCommandPoint* CommandPoints;
//#define G_COMMANDPOINTS (CommandPoints)
#define G_COMMANDPOINTS (*reinterpret_cast<SCommandPoint**>(0x006B4708))

// @Ok
EXPORT SCommandPoint* HashTable[256];
//#define G_HASHTABLE (HashTable)
#define G_HASHTABLE (reinterpret_cast<SCommandPoint**>(0x006B4214))

// @Ok
EXPORT i32 RestartNode = 0xFFFF;
//#define G_RESTARTNODE (RestartNode)
#define G_RESTARTNODE (*reinterpret_cast<i32*>(0x0055804C))

// @Ok
EXPORT i32 IsRestartDeath;

EXPORT i32 EndLevelNode;
extern CSpecialDisplay *SpecialDisplayList;

extern i32 JoelJewCheatCode;

extern CPlayer* MechList;
extern CBody* ControlBaddyList;
extern CBaddy* BaddyList;
extern CBody* EnvironmentalObjectList;
extern CBody* PowerUpList;


EXPORT char *MenuFileNamePointers[40];

//#define G_MENUFILENAMEPOINTERS (MenuFileNamePointers)
#define G_MENUFILENAMEPOINTERS (reinterpret_cast<char**>(0x006B3844))

EXPORT i32 NumTrigMenuEntries;
//#define G_NUMTRIGMENUENTRIES (NumTrigMenuEntries)
#define G_NUMTRIGMENUENTRIES (*reinterpret_cast<i32*>(0x006B467C))

// #define ENABLE_TRIG_LOG

// @Bogus
void trigLog(const char* fmt, ...)
{
#ifdef ENABLE_TRIG_LOG
	static char buffer[512];

	va_list lst;
    va_start(lst, fmt);

#ifdef _WIN32
	_vsnprintf(buffer, sizeof(buffer), fmt, lst);
#else
	vsnprintf(buffer, sizeof(buffer), fmt, lst);
#endif

	va_end(lst);
	printf("trigLog! %s\n", buffer);

#endif
}

// @NotOk
// SpecialDisplayList shitty ass polymorphism
// need to understand what's type 9
void SendKillFromNode(i32 Node, i32 How)
{
	print_if_false(Node >= 0 && Node < NumNodes, "Bad node sent to SendKillFromNode");

	u16 *pLinkInfo = Trig_GetLinksPointer(Node);

	u16 NumLinks = *pLinkInfo;
	u16* nodeIndexPtr = pLinkInfo + 1;

	for (i32 i = 0; i < NumLinks; i++)
	{
		u16 nodeIndex = nodeIndexPtr[i];

		i16 *node = reinterpret_cast<i16*>(G_OFFSETLIST[nodeIndex]);
		switch (*node)
		{
			case 1:
				if (node[1] == 409)
				{
					for (
							CSpecialDisplay *cur = SpecialDisplayList;
							cur;
							cur = reinterpret_cast<CSpecialDisplay*>(cur->mNext))
					{
						if (cur->mType == 9)
						{
							if (*reinterpret_cast<i16*>(reinterpret_cast<u8*>(cur)+0x6A) == nodeIndex)
							{
								cur->Die();
							}
						}
					}
				}
				else
				{
					KillInList(nodeIndex, BaddyList, How);
					KillInList(nodeIndex, ControlBaddyList, How);
					KillInList(nodeIndex, EnvironmentalObjectList, How);
				}
				break;
			case 2:
			case 9:

				u32 v20;
				CItem* EnviroItem;

				v20 = reinterpret_cast<u32>(&node[node[1] + 2]);
				if (v20 & 2)
					v20 += 2;

				EnviroItem = Spool_FindEnviroItem(v20);
				if (EnviroItem)
				{
					if (How == 1)
					{
						Exp_HitEnvItem(EnviroItem, 0, 0xFFFF);
					}
					else
					{
						EnviroItem->mFlags |= 1;
					}
				}
				break;
			case 4:
			case 20:
				KillInList(nodeIndex, PowerUpList, How);
				break;
			default:
				break;
		}
	}


}

// @Ok
void SendSuspendOrActivate(u16* pLinkInfo, i32 signalType)
{
	switch(signalType)
	{
		case 4:
		case 5:
			break;
		default:
			print_if_false(0, "Bad signalType");
			break;
	}

	print_if_false(*pLinkInfo !=0, "Node sending an activate or \n suspen is not lined\n to anything");

	u16 numIters = *pLinkInfo;

	u16* nodeIndexPtr = pLinkInfo + 1;

	for (i32 i = 0; i < numIters; i++)
	{
		u16 *node = reinterpret_cast<u16*>(G_OFFSETLIST[nodeIndexPtr[i]]);

		switch(*node)
		{
			case 1:
			case 7:
				if (signalType == 5)
				{
					SendSuspend(reinterpret_cast<CBody**>(&BaddyList), nodeIndexPtr[i]);
					SendSuspend(reinterpret_cast<CBody**>(&ControlBaddyList), nodeIndexPtr[i]);
					SendSuspend(reinterpret_cast<CBody**>(&EnvironmentalObjectList), nodeIndexPtr[i]);
				}
				else
				{
					SendUnSuspend(BaddyList, nodeIndexPtr[i]);
					SendUnSuspend(ControlBaddyList, nodeIndexPtr[i]);
					SendUnSuspend(EnvironmentalObjectList, nodeIndexPtr[i]);
				}
				break;
		}
	}
}

// @Ok
void SendUnSuspend(CBody* pList, i32 NodeIndex)
{
	for (CBody* cur = pList; cur; cur = reinterpret_cast<CBody*>(cur->mNextItem))
	{
		if (cur->mNode == NodeIndex)
			cur->UnSuspend();
	}
}

// @Ok
// @Matching
void SendSignalToNode(CBody* pBody, i32 NodeIndex)
{
	for (CBody* cur = pBody; cur; cur = reinterpret_cast<CBody*>(cur->mNextItem))
	{
		if (cur->mNode == NodeIndex)
			cur->mInputFlags |= 1;
	}
}

// @Ok
INLINE void SendSuspend(CBody** ppList, i32 NodeIndex)
{
	for (CBody* cur = *ppList; cur; cur = reinterpret_cast<CBody*>(cur->mNextItem))
	{
		if (cur->mNode == NodeIndex)
			cur->Suspend(ppList);
	}
}

// @Ok
void KillInList(i32 Node, CBody* pList, i32 How)
{
	for (CBody *cur = pList; cur; cur = reinterpret_cast<CBody*>(cur->mNextItem))
	{
		if (cur->mNode == Node)
		{
			switch (How)
			{
				case 0:
					cur->Die();
					break;
				case 1:
					SHitInfo hitInfo;
					hitInfo.field_8 = cur->mHealth;
					hitInfo.field_C.vx = 0;
					hitInfo.field_C.vy = 0;
					hitInfo.field_C.vz = 0;
					hitInfo.field_0 = 4;
					cur->Hit(&hitInfo);
					break;
			}
		}
	}

}

// @BIGTODO
CBody* Trig_CreateObject(i32 NodeIndex)
{
	typedef CBody* (*func_ptr)(i32);
	func_ptr func = (func_ptr)0x004DEE70;

	return func(NodeIndex);
}

// @Ok
void Trig_ExecuteAutoexec(void)
{
	print_if_false(G_TRIGFILE != 0, "No trigger file");
	EndLevelNode = 0xFFFF;

	if (JoelJewCheatCode)
	{
		for (i32 curNode = 0; curNode < NumNodes; curNode++)
		{
			u16 *v5 = reinterpret_cast<u16*>(G_OFFSETLIST[curNode]);
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
		u16 *v5 = reinterpret_cast<u16*>(G_OFFSETLIST[curNode]);
		if (*v5 == 4)
		{
			trigLog("*** Executing AUTOEXEC Node %i ***", curNode);
			ExecuteCommandList(v5 + 1, curNode, 1);
		}
	}
}

// @Ok
// @AlmostMatching: different reg alloc
void Trig_ExecuteRestart(void)
{
	ASSERT(G_RESTARTNODE != 0xFFFF, "Tried to execute a restart with no restart node set");
	ASSERT(*G_OFFSETLIST[G_RESTARTNODE] == 8, "Eh? Restart node isn't a restart node!");
	ASSERT(G_MECHLIST != 0, "Tried to execute a restart with a NULL MechList");

	CVector v7;

	CSVector *Position = reinterpret_cast<CSVector*>(Trig_GetPosition(&v7, G_RESTARTNODE));

	CPlayer *pPlayer = (CPlayer*)G_MECHLIST;

	pPlayer->mPos = v7;
	pPlayer->SetStartOrientation(Position);

	char *v3 = reinterpret_cast<char*>(&Position[1]);
	trigLog("*** Executing Restart Node: %s ***", v3);

	u16* v4 = SkipString(v3);

	Trig_ZeroPendingList();
	ExecuteCommandList(v4, G_RESTARTNODE, 1);
}

// @Ok
// @Matching
void Trig_SetRestart(char *pName)
{
	G_RESTARTNODE = 0xFFFF;
	for (i32 curNode = 0; curNode < G_NUMNODES; curNode++)
	{
		if (*G_OFFSETLIST[curNode] == 8)
		{
			CVector v3;

			u16* Position = Trig_GetPosition(&v3, curNode);
			
			if (Utils_CompareStrings(reinterpret_cast<char*>(&Position[3]), pName))
			{
				G_RESTARTNODE = curNode;
				trigLog("Set RestartNode = %i", curNode);
				if (!Utils_CompareStrings(pName, "re_start_death"))
					G_ISRESTARTDEATH = 1;
				return;
			}
		}
	}

	ASSERT(0, "Restart point ");
}

// @Ok
INLINE u16 *SkipString(char *pText)
{
	while(*pText)
		pText++;

	pText++;

	u32 res = reinterpret_cast<u32>(pText);

	return reinterpret_cast<u16*>(res + (res & 1));
}

// @Ok
// @Matching
void Trig_DeleteTrigFile(void)
{
	if (G_TRIGFILE)
	{
		Mem_Delete(reinterpret_cast<void*>(G_TRIGFILE));
		G_TRIGFILE = 0;
	}

	G_NUMCHEATRESTARTS = 0;
	Trig_ZeroPendingList();
}

// @BIGTODO
void ExecuteCommandList(u16* pCommands, i32 Node, i32 WaitForSpooling)
{

	typedef void (*func_ptr)(u16*, i32, i32);

	func_ptr func = (func_ptr)0x004E0210;

	func(pCommands, Node, WaitForSpooling);
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
	for(i = 0; i < MAXPENDING && G_PENDINGLISTARRAY[i].pCommands; i++);

	ASSERT(i < 16, "Pending command list overflow, increase MAXPENDING in trig.cpp");

	G_PENDINGLISTARRAY[i].NodeIndex = nodeIndex;
	G_PENDINGLISTARRAY[i].pCommands = pCommands;
}

// @Ok
// @Matching
SCommandPoint* Trig_TriggerCommandPoint(u32 checksum, bool assert)
{
	for (SCommandPoint *pSearch = G_HASHTABLE[(checksum)&0xFF]; pSearch; pSearch = pSearch->pNextSimilar)
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
INLINE SCommandPoint* GetCommandPoint(i32 Node)
{
	if (Node != 0xFFF && *G_OFFSETLIST[Node] == 6)
	{
		for (SCommandPoint *cur = G_COMMANDPOINTS; cur; cur = cur->pNext)
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
// @Matching
void Trig_DeleteCommandPoints(void)
{
	for (i32 i = 0; i<256; i++)
		G_HASHTABLE[i] = 0;

	for (SCommandPoint *cur = G_COMMANDPOINTS; cur; )
	{
		SCommandPoint *next = cur->pNext;
		Mem_Delete(reinterpret_cast<void*>(cur));
		cur = next;
	}

	G_COMMANDPOINTS = 0;
	Trig_ZeroPendingList();
}

// @Ok
INLINE void Trig_ZeroPendingList(void)
{
	for (i32 i = 0; i<MAXPENDING; i++)
	{
		G_PENDINGLISTARRAY[i].NodeIndex = 0;
		G_PENDINGLISTARRAY[i].pCommands = 0;
	}
}

// @Ok
// @Matching
void Trig_ResetCPExecutedFlags(void)
{
	for(SCommandPoint *pCP = G_COMMANDPOINTS; pCP; pCP = pCP->pNext)
	{
		if (pCP->Executed && !pCP->Collision)
			pCP->Executed = 0;
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
				u16 *v11 = reinterpret_cast<u16*>(G_OFFSETLIST[*v8]);

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
int Trig_GetLevelID(void)
{
	return 0x686868;
}

// @BIGTODO
u16* Trig_GetPosition(CVector* pos, i32 node)
{
	typedef u16* (*func_ptr)(CVector*, i32);
	func_ptr func = (func_ptr)0x004E3940;

	return func(pos, node);
}

// @Ok
INLINE u16* Trig_GetLinksPointer(int node)
{
	print_if_false(node >= 0 && node < NumNodes, "Bad node sent to Trig_GetLinksPointer");

	u16* trigNodePtr = reinterpret_cast<u16*>(G_OFFSETLIST[node]);
	i32 trigNodeValue = *reinterpret_cast<u16*>(trigNodePtr);

	if (trigNodeValue <= 0xD)
	{
		if (trigNodeValue < 0xC)
		{
			switch (trigNodeValue)
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
	else if (trigNodeValue <= 0x3E9)
	{
		if (trigNodeValue < 0x3E8)
		{
			if (trigNodeValue != 0x14)
			{
				print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
				print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
				return 0;
			}

			return reinterpret_cast<u16*>(trigNodePtr + 2);
		}

		return reinterpret_cast<u16*>(trigNodePtr + 1);
	}
	else if (trigNodeValue != 0x3EA)
	{
		print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
		print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
		return 0;
	}

	return reinterpret_cast<u16*>(trigNodePtr + 2);
}

// @Ok
void Trig_SendPulse(u16* pLinkInfo)
{
	u16 NumLinks = pLinkInfo[0];
	u16* pLink = &pLinkInfo[1];

	for (i32 i = 0; i < NumLinks; i++)
	{
		Trig_SendPulseToNode(pLink[i]);
	}
}

// @Ok
void Trig_SendSignalToLinks(u16* pLinkInfo)
{
	print_if_false(*pLinkInfo != 0, "Node sending signal is not linked\n to anything");

	u16 NumLinks = *pLinkInfo;
	u16 *pLink = pLinkInfo+1;

	for (i32 i = 0; i < NumLinks; i++)
	{
		u32 nodeIndex = pLink[i];
		switch (*G_OFFSETLIST[nodeIndex])
		{
			case 1:
			case 7:
				SendSignalToNode(BaddyList, nodeIndex);
				SendSignalToNode(ControlBaddyList, nodeIndex);
				SendSignalToNode(EnvironmentalObjectList, nodeIndex);
				break;
		}
	}
}

// @Ok
// @Matching
void Trig_ClearTrigMenu(void)
{
	for (i32 i = 0; i<40; i++)
	{
		G_MENUFILENAMEPOINTERS[i] = 0;
	}

	G_NUMTRIGMENUENTRIES = 0;
}

// @Ok
unsigned char* SkipFlags(unsigned char* pFlags)
{
	while(*pFlags != 0xFF)
		pFlags++;

	return pFlags+1;
}


// @Ok
// @Matching
void Trig_ResetCPCollisionFlags(void)
{
	for(SCommandPoint *cur = G_COMMANDPOINTS; cur; cur = cur->pNext)
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

// @Ok
void Trig_SendPulseToNode(i32 NodeIndex)
{
	ASSERT(NodeIndex >= 0 && NodeIndex < G_NUMNODES, "Bad node sent to Trig_SendPulseToNode");
	trigLog("\tSending pulse to node %i", NodeIndex);

	SCommandPoint *pCommand;
	switch(*G_OFFSETLIST[NodeIndex])
	{
		case 1:
		case 5:
		case 7:
		case 20:
			Trig_CreateObject(NodeIndex);
			break;
		case 6:
			pCommand = GetCommandPoint(NodeIndex);
			ASSERT(pCommand != 0, "Sent pulse to command point node before command point was created");

			pCommand->PulsesReceived++;
			Trig_AddCommandListToPending(NodeIndex, pCommand->pCommands);

			break;
		default:
			return;
	}
}

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

#include "my_patch.h"

// @Bogus
void patch_trig(void)
{
	PATCH_PUSH_RET(0x004DE750, Trig_ClearTrigMenu);
	PATCH_PUSH_RET(0x004DE890, Trig_ResetCPCollisionFlags);
	PATCH_PUSH_RET(0x004DE8B0, Trig_ResetCPExecutedFlags);
	PATCH_PUSH_RET(0x004DE840, Trig_DeleteCommandPoints);
	PATCH_PUSH_RET(0x004DE8D0, Trig_TriggerCommandPoint);
	PATCH_PUSH_RET(0x004DE970, Trig_SetRestart);

	PATCH_PUSH_RET(0x004DEA20, Trig_ExecuteRestart);

	PATCH_PUSH_RET(0x004DEB10, Trig_DeleteTrigFile);
	PATCH_PUSH_RET(0x004DFC20, Trig_SendPulseToNode);
	PATCH_PUSH_RET(0x004DFD30, Trig_SendPulse);
	PATCH_PUSH_RET(0x004DFFB0, SendSignalToNode);
}
