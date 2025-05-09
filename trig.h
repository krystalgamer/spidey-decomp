#pragma once

#ifndef TRIG_H
#define TRIG_H

#include "export.h"
#include "vector.h"

EXPORT extern i32 RestartNode;
EXPORT extern i32 gReStartDeathRelated;
EXPORT extern i32 gLevelStatus;
EXPORT extern i32 gRunCinemaRelated;

EXPORT extern i16 **gTrigNodes;
EXPORT extern i32 NumNodes;

class CBody;

struct SLinkInfo
{
	i32 field_0;
	i32 field_4;
	i32 field_8;
	i32 field_C;
};

struct SCommandPoint
{
	u16* pCommands;
	u8 Collision;
	u8 Executed;

	u8 NumPulsesSet;
	u8 PulsesReceived;

	u16 NumPulses;
	u16 NodeIndex;

	u32 Checksum;

	struct SCommandPoint* pNextSimilar;
	struct SCommandPoint* pNext;
};

struct PendingListEntry
{
	u16 NodeIndex;
	u16 field_2;
	u16* pCommands;
};

EXPORT i32 Trig_GetLevelID(void);
EXPORT u16* Trig_GetPosition(CVector*, i32);
EXPORT u16* Trig_GetLinksPointer(i32);
EXPORT void Trig_SendPulse(u16*);
EXPORT void Trig_SendPulseToNode(int);
EXPORT void Trig_SendSignalToLinks(u16*);
EXPORT void Trig_ClearTrigMenu(void);
EXPORT u8* SkipFlags(u8*);
EXPORT void Trig_ResetCPCollisionFlags(void);
EXPORT u8 GetFlag(u8, u8 *);
EXPORT void* Trig_GetLinkInfoList(i32, SLinkInfo*, i32);
EXPORT void Trig_ResetCPExecutedFlags(void);
EXPORT void Trig_ZeroPendingList(void);
EXPORT void Trig_DeleteCommandPoints(void);
EXPORT SCommandPoint* CreateCommandPoint(u32, u16, u16*);
EXPORT SCommandPoint* GetCommandPoint(i32);

EXPORT SCommandPoint* Trig_TriggerCommandPoint(u32, bool);
EXPORT void Trig_AddCommandListToPending(u16, u16*);
EXPORT void Trig_DoPendingCommandLists(void);
EXPORT void ExecuteCommandList(u16*, i32, i32);
EXPORT void Trig_DeleteTrigFile(void);
EXPORT char *SkipString(char *);
EXPORT void Trig_SetRestart(char *);
EXPORT void Trig_ExecuteRestart(void);
EXPORT void Trig_ExecuteAutoexec(void);
EXPORT void Trig_CreateObject(i32);
EXPORT void KillInList(i32, CBody*, i32);
EXPORT void SendSuspend(CBody**, i32);
EXPORT void SendSignalToNode(CBody*, i32);
EXPORT void SendUnSuspend(CBody*, i32);
EXPORT void SendSuspendOrActivate(u16*, i32);
EXPORT void SendKillFromNode(i32, i32);

void validate_SLinkInfo(void);
void validate_SCommandPoint(void);
void validate_PendingListEntry(void);

#endif
