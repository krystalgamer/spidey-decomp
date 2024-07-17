#pragma once

#ifndef TRIG_H
#define TRIG_H

#include "export.h"
#include "vector.h"

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

EXPORT int Trig_GetLevelId(void);
EXPORT u16* Trig_GetPosition(CVector*, int);
EXPORT u16* Trig_GetLinksPointer(int);
EXPORT void Trig_SendPulse(u16*);
EXPORT void Trig_SendPulseToNode(int);
EXPORT void Trig_SendSignalToLinks(u16*);
EXPORT void Trig_ClearTrigMenu(void);
EXPORT unsigned char* SkipFlags(unsigned char*);
EXPORT void Trig_ResetCPCollisionFlags(void);
EXPORT u8 GetFlag(unsigned char, unsigned char *);
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

void validate_SLinkInfo(void);
void validate_SCommandPoint(void);
void validate_PendingListEntry(void);

#endif
