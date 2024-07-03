#pragma once

#ifndef CARNAGE_H
#define CARNAGE_H

#include "export.h"
#include "baddy.h"

class CCarnage : public CBaddy {
public:
	EXPORT CCarnage(int*, int);
	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);

	unsigned char carnageStartPad[0x10];

	int field_334;
	int field_338;
	int field_33C;
	unsigned char padAfter33c[0x18 - 4];

	int field_354;
	int field_358;
	int field_35C;
	unsigned char padAfter35C[0x10-4];

	int field_36C;
	int field_370;
	int field_374;
	int field_378;
};

class CSonicBubble : public CBody
{
	public:
		EXPORT CSonicBubble(void);
		EXPORT ~CSonicBubble(void);
		EXPORT void SetScale(int);

		int field_F4;
};


void validate_CCarnage(void);
void validate_CSonicBubble(void);
EXPORT void CreateSonicBubbleVertexWobbler(void);
EXPORT void Carnage_Create_Carnage(const unsigned int *stack, unsigned int *result);

#endif
