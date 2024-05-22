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


	unsigned char padStartJonah[0x28];
	int field_34C;
	int field_350;
	int field_354;
	unsigned char padEnd[0x380-0x354-4];
};

void validate_CJonah(void);
EXPORT void Jonah_CreateJonah(const unsigned int *stack, unsigned int *result);

#endif
