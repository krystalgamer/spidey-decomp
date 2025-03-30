#pragma once

#ifndef JONAH_H
#define JONAH_H

#include "export.h"
#include "baddy.h"
#include "trig.h"
#include "reloc.h"

class CJonah : public CBaddy {
public:
	EXPORT CJonah(void);
	EXPORT CJonah(i16*, i32);
	EXPORT void GraspWaypoint(SLinkInfo* a2);
	EXPORT i32 LinkedHidingPlaceStillExists(i32);
	EXPORT i32 StartRunningToNextRoom(void);
	EXPORT void TakeHit(void);
	EXPORT CBaddy* FindScorp(void);
	EXPORT u16 DistToScorp(void);
	EXPORT u32 WhatShouldScorpDo(void);
	EXPORT void ShouldPlead(void);


	PADDING(0x330-0x324);

	i32 field_330;
	PADDING(0x34C-0x330-4);

	CVector field_34C;

	u8 padAfter354[4];

	SHandle field_35C;
	SHandle field_364;

	int field_36C;
	int field_370;
	unsigned char padEnd[0x380-0x370-4];
};

void validate_CJonah(void);
EXPORT void Jonah_CreateJonah(const unsigned int *stack, unsigned int *result);

EXPORT void Jonah_RelocatableModuleInit(reloc_mod*);
EXPORT void Jonah_RelocatableModuleClear(void);

EXPORT void Jonah_WhatShouldScorpDo(const u32*, u32*);
EXPORT void Jonah_ShouldPlead(const u32*, u32*);

#endif
