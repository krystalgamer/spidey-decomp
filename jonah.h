#pragma once

#ifndef JONAH_H
#define JONAH_H

#include "export.h"
#include "baddy.h"
#include "trig.h"

class CJonah : public CBaddy {
public:
	EXPORT CJonah(void);
	EXPORT CJonah(int*, int);
	EXPORT void GraspWaypoint(SLinkInfo* a2);
	EXPORT int LinkedHidingPlaceStillExists(int);
	EXPORT int StartRunningToNextRoom(void);


	unsigned char padStartJonah[0x330-0x324];
	int field_330;
	unsigned char padAfter330[0x34C-0x330-4];

	int field_34C;
	int field_350;
	int field_354;
	unsigned char padAfter354[0x36C-0x354-4];

	int field_36C;
	int field_370;
	unsigned char padEnd[0x380-0x370-4];
};

void validate_CJonah(void);
EXPORT void Jonah_CreateJonah(const unsigned int *stack, unsigned int *result);

#endif
